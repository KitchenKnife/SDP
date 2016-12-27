#include "Math.h"
#include "Model/Character/Character.h"
#include "Model/Character/Enemycharacter/EnemyCharacter.h"

//�R���X�g���N�^
CCustomMath::CCustomMath(){}

//���L�C���X�^���X
CCustomMath* CCustomMath::m_pSharedCustomMath = NULL;

//�f�X�g���N�^
CCustomMath::~CCustomMath(){}

//�C���X�^���X�̎擾
CCustomMath* CCustomMath::getInstance() {

	if (CCustomMath::m_pSharedCustomMath == NULL) {
		CCustomMath::m_pSharedCustomMath = new CCustomMath();
	}

	return CCustomMath::m_pSharedCustomMath;
}

//�C���X�^���X�̔j��
void CCustomMath::removeInstance() {
	SAFE_DELETE(CCustomMath::m_pSharedCustomMath);
}

/*
* @desc 2�_�Ԃ̋��������߂鎮
* @param �_1
* @param �_2
* @return �_1�Ɠ_2�̋���
*/
float CCustomMath::length(cocos2d::Point pt1, cocos2d::Point pt2) {

	float length;
	length = sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2));

	return length;
}

/*
* @desc 2�̂̃L�����̋��������߂鎮
* @param�@�L����1
* @param�@�L����2
* @return �L����1�ƃL����2�̋���
*/
float CCustomMath::lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2) {

	float length = this->length(pChara1->m_pMove->m_pos, pChara2->m_pMove->m_pos);

	return length;
}

/*
* @desc �^�[�Q�b�g�̑I��
* @return �^�[�Q�b�g�����܂������ǂ����@true...���܂���
* @tips �����ƋR�m�œG�ɋ߂����̋����𓱂�
*�@�@�@ �߂������ǐՔ͈͂ɂȂ�^�[�Q�b�g�ɐݒ�
*/
bool CCustomMath::seachAndSelectTarget(CCharacter* pChara) {
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//�G�Ə��N�̋���
	float lemgthFromBoy = this->lengthBitweenChara(pChara, pBoy);
	//�G�Ə����̋���
	float lemgthFromGirl = this->lengthBitweenChara(pChara, pGirl);

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//�߂������G�̒ǐՔ͈͓��Ȃ�A�߂�����G�̃^�[�Q�b�g�ɐݒ�
	/*
	if ((lemgthFromBoy < lemgthFromGirl) && lemgthFromBoy <= pEne->m_chaseRange) {
		pEne->setTarget(pBoy);
		return true;
	}
	else if ((lemgthFromBoy >= lemgthFromGirl) && lemgthFromGirl <= pEne->m_chaseRange) {
		pEne->setTarget(pGirl);
		return true;
	}
	*/

	return false;
}

/*
* @desc �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
* @param �A�N�V�������s���L�����N�^�[
* @param �^�[�Q�b�g�̃^�C�v
*/
void CCustomMath::checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type) {

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//�D��^�[�Q�b�g�������łȂ����
	if (type != TARGET_TYPE::BOTH) {
		/*
		//�^�[�Q�b�g�Ƃ̋������ǐՔ͈͓��Ȃ�
		if (pEne->m_chaseRange >= this->lengthBitweenChara(pEne, pEne->m_currentTarget)) {
			//������~
			this->stop();
			//�G��ǐՏ�ԂɈڍs
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
		*/
	}
	//�����Ȃ�
	else {
		/*
		//�^�[�Q�b�g�̌����Ɛݒ�
		if (seachAndSelectTarget(pEne) == true) {
			//������~
			this->stop();
			//�G��ǐՏ�ԂɈڍs
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
		*/
	}
}

/*
* @desc �L��������^�[�Q�b�g�ւ�X�����̐��K���x�N�g�������߂Đ����ړ����x��ݒ�
* @param �A�N�V�������s���L�����N�^�[
* @param �ڕW�n�_�̍��W
*/
void CCustomMath::normalizeVel_X(CCharacter* pChara, cocos2d::Point pt) {

	float nomalizevelX = (pt.x - pChara->m_pMove->m_pos.x) / abs(pt.x - pChara->m_pMove->m_pos.x);

	pChara->m_pMove->m_vel.x = pChara->m_status.getSpeed()*nomalizevelX;
}

/*
* @desc �ڕW�n�_�܂ł̐��K���x�N�g���ɃL�����̃X�s�[�h�������l��ݒ肷��
* @param �A�N�V�������s���L�����N�^�[
* @param �ڕW�n�_�̍��W
*/
void CCustomMath::normalizeVel(CCharacter* pChara, cocos2d::Point pt) {

	//�^�[�Q�b�g�܂ł̋��������߂�
	float length = this->length(pChara->m_pMove->m_pos, pt);
	float lengthX = pt.x - pChara->m_pMove->m_pos.x;
	float lengthY = pt.y - pChara->m_pMove->m_pos.y;

	//�L�����N�^�[�̃X�s�[�h�Ɋe�����̐��K���x�N�g����������
	float velX = (pChara->m_status.getSpeed()*lengthX) / length;
	float velY = (pChara->m_status.getSpeed()*lengthY) / length;

	pChara->m_pMove->m_vel.set(velX, velY);
}



