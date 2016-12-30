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

	float length = (CCustomMath::m_pSharedCustomMath)->length(pChara1->m_pMove->m_pos, pChara2->m_pMove->m_pos);

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
	float lemgthFromBoy = (CCustomMath::m_pSharedCustomMath)->lengthBitweenChara(pChara, pBoy);
	//�G�Ə����̋���
	float lemgthFromGirl = (CCustomMath::m_pSharedCustomMath)->lengthBitweenChara(pChara, pGirl);

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//�߂������G�̒ǐՔ͈͓��Ȃ�A�߂�����G�̃^�[�Q�b�g�ɐݒ�
	if ((lemgthFromBoy < lemgthFromGirl) && lemgthFromBoy <= pEne->m_chaseRange) {
		pEne->m_currentTarget = (pBoy);
		return true;
	}
	else if ((lemgthFromBoy >= lemgthFromGirl) && lemgthFromGirl <= pEne->m_chaseRange) {
		pEne->m_currentTarget = (pGirl);
		return true;
	}
	
	return false;
}

/*
* @desc �^�[�Q�b�g�Ƃ̊ԍ����̊m�F
* @param �A�N�V�������s���L�����N�^�[
* @param �^�[�Q�b�g�̃^�C�v
* @return �^�[�Q�b�g�Ƃ̊ԍ���
*/
float CCustomMath::checkTargetRange(CCharacter* pChara, TARGET_TYPE type) {

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//�D��^�[�Q�b�g�����肵�Ă����
	if (type != TARGET_TYPE::BOTH) {

		return (CCustomMath::m_pSharedCustomMath)->lengthBitweenChara(pEne, pEne->m_currentTarget);
		
	}
	//�����Ȃ�
	else {
		
		CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
		CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

		//�G�Ə��N�̋���
		float lemgthFromBoy = (CCustomMath::m_pSharedCustomMath)->lengthBitweenChara(pChara, pBoy);
		//�G�Ə����̋���
		float lemgthFromGirl = (CCustomMath::m_pSharedCustomMath)->lengthBitweenChara(pChara, pGirl);

		//�߂������G�̒ǐՔ͈͓��Ȃ�A�߂�����G�̃^�[�Q�b�g�ɐݒ�
		if ((lemgthFromBoy < lemgthFromGirl)) {
			pEne->m_currentTarget = (pBoy);
			return lemgthFromBoy;
		}
		else if ((lemgthFromBoy >= lemgthFromGirl)) {
			pEne->m_currentTarget = (pGirl);
			return lemgthFromGirl;
		}
		
	}

	return 0;
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
	float length = (CCustomMath::m_pSharedCustomMath)->length(pChara->m_pMove->m_pos, pt);
	float lengthX = pt.x - pChara->m_pMove->m_pos.x;
	float lengthY = pt.y - pChara->m_pMove->m_pos.y;

	//�L�����N�^�[�̃X�s�[�h�Ɋe�����̐��K���x�N�g����������
	float velX = (pChara->m_status.getSpeed()*lengthX) / length;
	float velY = (pChara->m_status.getSpeed()*lengthY) / length;

	pChara->m_pMove->m_vel.set(velX, velY);
}



