/*
* EnemyActionController.cpp
*
*	2016/12/20	Osumi
*
*/
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"

//===================================================================
//�@�G�̓���̔h����
//===================================================================
/*
* @desc 2�_�Ԃ̋��������߂鎮
* @param �_1
* @param �_2
* @return �_1�Ɠ_2�̋���
*/
float CEnemyAction::length(cocos2d::Point pt1, cocos2d::Point pt2) {

	float length;
	length = sqrt(pow(pt1.x-pt2.x, 2)+ pow(pt1.y - pt2.y, 2));

	return length;
}

/*
* @desc 2�̂̃L�����̋��������߂鎮
* @param�@�L����1
* @param�@�L����2
* @return �L����1�ƃL����2�̋���
*/
float CEnemyAction::lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2) {
	
	float length  = this->length(pChara1->m_pMove->m_pos, pChara2->m_pMove->m_pos);

	return length;
}

/*
* @desc �^�[�Q�b�g�̑I��
* @return �^�[�Q�b�g�����܂������ǂ����@true...���܂���
* @tips �����ƋR�m�œG�ɋ߂����̋����𓱂�
*�@�@�@ �߂������ǐՔ͈͂ɂȂ�^�[�Q�b�g�ɐݒ�
*/
bool CEnemyAction::seachAndSelectTarget(CCharacter* pChara) {
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//�G�Ə��N�̋���
	float lemgthFromBoy = this->lengthBitweenChara(pChara,pBoy);
	//�G�Ə����̋���
	float lemgthFromGirl = this->lengthBitweenChara(pChara, pGirl);

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//�߂������G�̒ǐՔ͈͓��Ȃ�A�߂�����G�̃^�[�Q�b�g�ɐݒ�
	if ((lemgthFromBoy < lemgthFromGirl)  && lemgthFromBoy <= pEne->m_chaseRange) {
		pEne->setTarget(pBoy);
		return true;
	}
	else if ((lemgthFromBoy >= lemgthFromGirl) && lemgthFromGirl <= pEne->m_chaseRange) {
		pEne->setTarget(pGirl); 
		return true;
	}

	return false;
}

/*
* @desc �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
* @param �A�N�V�������s���L�����N�^�[
* @param �^�[�Q�b�g�̃^�C�v
*/
void CEnemyAction::checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type) {

	CEnemyCharacter* pEne = (CEnemyCharacter*) pChara;

	//�D��^�[�Q�b�g�������łȂ����
	if (type != TARGET_TYPE::BOTH) {
		//�^�[�Q�b�g�Ƃ̋������ǐՔ͈͓��Ȃ�
		if (pEne->m_chaseRange >= this->lengthBitweenChara(pEne, pEne->m_currentTarget)) {
			//������~
			this->stop();
			//�G��ǐՏ�ԂɈڍs
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
	}
	//�����Ȃ�
	else {
		//�^�[�Q�b�g�̌����Ɛݒ�
		if (seachAndSelectTarget(pEne) == true) {
			//������~
			this->stop();
			//�G��ǐՏ�ԂɈڍs
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
	}
}

/*
* @desc �L��������^�[�Q�b�g�ւ�X�����̐��K���x�N�g�������߂Đ����ړ����x��ݒ�
* @param �A�N�V�������s���L�����N�^�[
* @param �ڕW�n�_�̍��W
*/
void CEnemyAction::normalizeVel_X(CCharacter* pChara, cocos2d::Point pt) {

	float nomalizevelX = (pt.x - pChara->m_pMove->m_pos.x) / abs(pt.x - pChara->m_pMove->m_pos.x);

	pChara->m_pMove->m_vel.x = pChara->m_pStatus->getSpeed()*nomalizevelX;
}

/*
* @desc �ڕW�n�_�܂ł̐��K���x�N�g���ɃL�����̃X�s�[�h�������l��ݒ肷��
* @param �A�N�V�������s���L�����N�^�[
* @param �ڕW�n�_�̍��W
*/
void CEnemyAction::normalizeVel(CCharacter* pChara, cocos2d::Point pt){

	//�^�[�Q�b�g�܂ł̋��������߂�
	float length = this->length(pChara->m_pMove->m_pos, pt);
	float lengthX = pt.x - pChara->m_pMove->m_pos.x;
	float lengthY = pt.y - pChara->m_pMove->m_pos.y;

	//�L�����N�^�[�̃X�s�[�h�Ɋe�����̐��K���x�N�g����������
	float velX = (pChara->m_pStatus->getSpeed()*lengthX) / length;
	float velY = (pChara->m_pStatus->getSpeed()*lengthY) / length;

	pChara->m_pMove->m_vel.set(velX, velY);
}

//===================================================================
//�@�G�̑ҋ@���� CEnemyActionStay
//===================================================================
//�R���X�g���N�^
CEnemyActionStay::CEnemyActionStay(TARGET_TYPE type) {
	//�R���X�g���N�^�ŃA�N�V��������Ԃɐݒ�
	this->m_inAction = true;

	//�^�C�v��ݒ�
	this->m_defaultTarget = type;
}

/*
* @desc �J�n����
*/
void CEnemyActionStay::start() {
	//�A�N�V��������Ԃɐݒ�
	this->m_inAction = true;
}

/*
* @desc �X�V����
*/
void CEnemyActionStay::update(CCharacter* pChara) {

	//�A�N�V�������Ȃ�
	if (this->m_inAction == true) {

		// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
		this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

/*
* @desc �I����������
*/
void CEnemyActionStay::stop() {

	//�t���O��S�ĉ�����
	this->m_isStart = false;
	this->m_inAction = false;

}
//===================================================================
//�@�G�̎��Ԍo�߂ɂ��ҋ@����
//===================================================================
//�R���X�g���N�^
CEnemyActionStayAtTime::CEnemyActionStayAtTime(TARGET_TYPE type): CEnemyActionStay(type){
	//�R���X�g���N�^�ŃA�N�V�����J�n��Ԃɐݒ�
	this->m_isStart = true;
}

/*
* @desc �J�n����
*/
void CEnemyActionStayAtTime::start() {
	//�A�N�V�����J�n��Ԃɐݒ�
	this->m_isStart = true;
}

/*
* @desc �X�V����
*/
void CEnemyActionStayAtTime::update(CCharacter* pChara) {

	//�J�n��ԂȂ�
	if (this->m_isStart == true) {
		//�����_���ŃA�N�V�������Ԃ�ݒ�(30~60)
		this->m_actionInterval = rand() % 30 + 31;

		//�J�n��Ԃ𗣒E
		this->m_isStart = false;
		//�A�N�V��������ԂɈڍs
		this->m_inAction = true;
	}

	//�A�N�V�������Ȃ�
	if (this->m_inAction == true) {
		//�J�E���^�[���C���N�������g
		this->m_actionCounter++;

		//�J�E���^�[���C���^�[�o���ȏ�Ȃ�
		if (this->m_actionCounter >= this->m_actionInterval) {
			//�J�E���^�[�����Z�b�g
			this->m_actionCounter = 0;
			//�ҋ@������I��
			this->stop();
			//���܂悢�s���Ɉڍs
			CEnemyCharacter* pEne = (CEnemyCharacter*) pChara;
			pEne->m_state = CEnemyCharacter::STATE::WANDERING;
			pEne->m_pActions[pEne->m_state]->start();
		}
		// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
		this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

//===================================================================
//�@�G�̂��낤�듮��
//===================================================================
//�R���X�g���N�^
CEnemyActionWondering::CEnemyActionWondering(TARGET_TYPE type) {
	//�R���X�g���N�^�ŃA�N�V�����J�n��Ԃɐݒ�
	this->m_isStart = true;

	//�^�C�v��ݒ�
	this->m_defaultTarget = type;
}

/*
* @desc �J�n����
*/
void CEnemyActionWondering::start() {
	//�A�N�V�����J�n��Ԃɐݒ�
	this->m_isStart = true;
}

/*
* @desc �X�V����
*/
void CEnemyActionWondering::update(CCharacter* pChara) {
	
	//�J�n��ԂȂ�
	if (this->m_isStart == true) {
		//�����_���ŕ���������ݒ�
		this->m_vec = (rand() % 3) -1;
		if (this->m_vec == 0) {
			//������~
			this->stop();
			//�ҋ@��ԂɈڍs
			CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;
			pEne->m_state = CEnemyCharacter::STATE::STAY;
			pEne->m_pActions[pEne->m_state]->start();
		}
		//������ݒ�
		pChara->m_pMove->m_vel.set(
			pChara->m_pStatus->getSpeed()*this->m_vec,
			0.0f
		);

		//�����_���ŃA�N�V�������Ԃ�ݒ�(30~60)
		this->m_actionInterval = rand() % 30 + 31;

		//�J�n��Ԃ𗣒E
		this->m_isStart = false;
		//�A�N�V��������ԂɈڍs
		this->m_inAction = true;
	}

	//�A�N�V�������Ȃ�
	if (this->m_inAction == true ) {
		//�J�E���^�[���C���N�������g
		this->m_actionCounter++;
		//�J�E���^�[���C���^�[�o���ȏ�Ȃ�
		if(this->m_actionCounter >= this->m_actionInterval) {
			//�J�E���^�[�����Z�b�g
			this->m_actionCounter = 0;
			//�J�n��ԂɈڍs
			this->m_isStart = true;
			//�A�N�V��������Ԃ��痣�E
			this->m_inAction = false;
		}

		// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
		this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

/*
* @desc �I����������
*/
void CEnemyActionWondering::stop() {

	//�t���O��S�ĉ�����
	this->m_isStart = false;
	this->m_inAction = false;

}

//===================================================================
//�@�G�̒ǐՓ���
//===================================================================
/*
* @desc �R���X�g���N�^
* @param �L�����N�^�[����Ԃ��ǂ����i�f�t�H���g��false�j
*/
CEnemyActionChase::CEnemyActionChase(bool isFlying)
:m_isFlying(isFlying){}

/*
* @desc �J�n����
*/
void CEnemyActionChase::start() {
	this->m_inAction = true;
}

/*
* @desc �X�V����
* @param �A�N�V�������s���L�����N�^�[
*/
void CEnemyActionChase::update(CCharacter* pChara) {

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	if (this->m_inAction == true) {
		//�A�N�V�������s���L����������΂Ȃ����
		if (this->m_isFlying == false) {
			//�L��������^�[�Q�b�g�ւ�X�����̐��K���x�N�g�������߂Đ����ړ����x��ݒ�
			this->normalizeVel_X(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
		else {
			// �ڕW�n�_�܂ł̐��K���x�N�g���ɃL�����̃X�s�[�h�������l��ݒ肷��
			this->normalizeVel(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
	}

	//�G��������x���ꂽ�烏���_�����O��ԂɈڍs����
	if (pEne->m_chaseRange < this->lengthBitweenChara(pEne,pEne->m_currentTarget)) {
		this->stop();
		pEne->m_state = CEnemyCharacter::STATE::WANDERING;
		pEne->m_pActions[CEnemyCharacter::STATE::WANDERING]->start();
	}
}

/*
* @desc �I����������
*/
void CEnemyActionChase::stop() {
	this->m_inAction = false;
}

//===================================================================
//�@�G�̏o���n�_�ɖ߂铮�� CEnemyActionReturnLanchPos
//===================================================================
/*
* @desc �R���X�g���N�^
* @param �ǐՂ��ׂ��v���C���[�^�C�v
* @param �o�������L�����N�^�[
*/
CEnemyActionReturnLanchPos::CEnemyActionReturnLanchPos(TARGET_TYPE type, CCharacter* pChara)
	:CEnemyActionStay(type), m_launchPos(pChara->m_pMove->m_pos){
	//�R���X�g���N�^�ŃA�N�V��������Ԃɐݒ�
	this->m_inAction = true;
}

/*
* @desc �J�n����
*/
void CEnemyActionReturnLanchPos::start() {
	this->m_isStart = true;
}

/*
* @desc �X�V����
* @param �A�N�V�������s���L�����N�^�[
*/
void CEnemyActionReturnLanchPos::update(CCharacter* pChara) {

	if (this->m_isStart == true) {
		// �ڕW�n�_�܂ł̐��K���x�N�g���ɃL�����̃X�s�[�h�������l��ݒ肷��
		this->normalizeVel(pChara, this->m_launchPos);

		//�J�n��Ԃ𗣒E
		this->m_isStart = false;
		//�A�N�V��������ԂɈڍs
		this->m_inAction = true;
	}

	if (this->m_inAction == true) {

		//�o���ʒu�܂ł̋��������߂�
		float length = this->length(this->m_launchPos, pChara->m_pMove->m_pos);
		//������������x�߂����
		if (length <= 5) {
			//�o���ʒu�ɃL�����N�^�[�̈ʒu��ݒ�
			pChara->m_pMove->m_pos.set(this->m_launchPos.x, this->m_launchPos.y);
			//���x��0�ɐݒ�
			pChara->m_pMove->m_vel.set(0.0f, 0.0f);
			//���݂̓���̒�~
			this->stop();
			//�ҋ@��ԂɈڍs
			CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;
			pEne->m_state = CEnemyCharacter::STATE::STAY;
			pEne->m_pActions[pEne->m_state]->start();
		}

		//�^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
		checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

/*
* @desc �I����������
*/
void CEnemyActionReturnLanchPos::stop() {
	this->m_isStart = false;
	this->m_inAction = false;
}
