#include "Action.h"
#include "Model/Character/Character.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"


//===================================================================
//�@�G�̂��낤�듮��
//===================================================================
//�R���X�g���N�^
CActionWondering::CActionWondering() {
	//�R���X�g���N�^�ŃA�N�V�����J�n��Ԃɐݒ�
	this->m_isStart = true;

}

/*
* @desc �J�n����
*/
void CActionWondering::start() {
	//�A�N�V�����J�n��Ԃɐݒ�
	this->m_isStart = true;
}

/*
* @desc �X�V����
*/
void CActionWondering::update(CCharacter* pChara) {

	/*
	//�J�n��ԂȂ�
	if (this->m_isStart == true) {
		
		//�����_���ŕ���������ݒ�
		this->m_vec = (rand() % 3) - 1;
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
			pChara->m_status.getSpeed()*this->m_vec,
			0.0f
		);

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
			//�J�n��ԂɈڍs
			this->m_isStart = true;
			//�A�N�V��������Ԃ��痣�E
			this->m_inAction = false;
		}
		
		// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
		//customMath->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
		
	}
	*/
}

/*
* @desc �I����������
*/
void CActionWondering::stop() {

	//�t���O��S�ĉ�����
	this->m_isStart = false;
	this->m_inAction = false;

}

//===================================================================
//�@�G�̒ǐՓ���
//===================================================================
/*
* @desc �R���X�g���N�^
* @param �L�����N�^�[����Ԃ��ǂ���
*/
CActionChase::CActionChase(bool isFlying)
	:m_isFlying(isFlying) {}

/*
* @desc �J�n����
*/
void CActionChase::start() {
	this->m_inAction = true;
}

/*
* @desc �X�V����
* @param �A�N�V�������s���L�����N�^�[
*/
void CActionChase::update(CCharacter* pChara) {

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	if (this->m_inAction == true) {
		//�A�N�V�������s���L����������΂Ȃ����
		if (this->m_isFlying == false) {
			//�L��������^�[�Q�b�g�ւ�X�����̐��K���x�N�g�������߂Đ����ړ����x��ݒ�
			customMath->normalizeVel_X(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
		else {
			// �ڕW�n�_�܂ł̐��K���x�N�g���ɃL�����̃X�s�[�h�������l��ݒ肷��
			customMath->normalizeVel(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
	}
}

/*
* @desc �I����������
*/
void CActionChase::stop() {
	this->m_inAction = false;
}