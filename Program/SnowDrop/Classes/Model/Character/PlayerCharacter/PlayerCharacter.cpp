
/*
* PlayerCharacter.cpp
*
*	2016/12/1	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "PlayerCharacter.h"
#include "Lib/Input/InputManager.h"

//================================================	
//	���N�N���X�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//
//	2016/12/22
//									Author Harada
//================================================
//�R���X�g���N�^
CPlayerCharacterBoy::CPlayerCharacterBoy() {}

//�f�X�g���N�^
CPlayerCharacterBoy::~CPlayerCharacterBoy() {}

//����������
bool CPlayerCharacterBoy::init() {

	if (CCharacter::init() == false) {
		CCLOG("�v���C���[�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	return true;
}



//�ړ�����
void CPlayerCharacterBoy::moveFunc() {

	//����ł����΂�
	if (this->m_activeFlag == false)
		return;

	//���͏���
	this->inputFunc();

	//�A�N�V�����̍X�V����
	for (CAction* pAction : (*this->m_pActions)) {
		pAction->update(this);
	}
	
	//�����v�Z
	for (CPhysical* pPhysical : (*this->m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}


//�A�j���[�V��������
void CPlayerCharacterBoy::animationFunc() {

	//�v���C���[�A�j���[�V����
	(*this->m_pAnimations)[m_playerState]->update();

}


//�Փ˔��菈��
void CPlayerCharacterBoy::collisionAll() {
	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}

	//�S�ẴL�����N�^�[�Ƃ̏Փ˔���
	std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();
	for (CCharacter* pChara : (*pCharacters)) {
		//��̂̃L�����Ƃ̏Փ˔���
		this->collision(pChara);
	}
}

//��ԃ`�F�b�N
void CPlayerCharacterBoy::checkState() {

	//��Ԃ̔���
	if (this->m_pMove->m_vel.x > 0) {
		//�E���s���
		m_playerState = (int)PLAYER_STATE::WALK_RIGHT;
	}
	else if (this->m_pMove->m_vel.x < 0) {
		//�����s���
		m_playerState = (int)PLAYER_STATE::WALK_LEFT;
	}
	else if (this->m_pMove->m_vel.y > 0.0f) {
		//�W�����v���
		m_playerState = (int)PLAYER_STATE::JUMP;
	}
	else if (this->m_pMove->m_vel.y < 0.0f) {
		//�������
		m_playerState = (int)PLAYER_STATE::FALLING;
	}
	else {
		//�ҋ@���
		m_playerState = (int)PLAYER_STATE::STAND;
	}
}


//���f����
void  CPlayerCharacterBoy::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[m_playerState]->getCurrentChip());
}


/**
 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
 * @param	�L�����N�^�[�̃A�h���X
 * @return	true...�Փ˂���
 */
bool  CPlayerCharacterBoy::collision(CCharacter* pChara) {

	return true;
}

/**
 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
 * @param	�L�����N�^�[�̃A�h���X
 */
void CPlayerCharacterBoy::hits(CCharacter* pChara) {

}

/**
 * @desc ���͏���
 * @tips �ړ������ŌĂяo��
 */
void  CPlayerCharacterBoy::inputFunc() {

	CInputController* pointerInputController = CInputManager::getInstance()->getInputController(CONTROLLER_TYPE::KEYBORD);


	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		this->m_pMove->m_accele.x = -0.5f;
	}

	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		this->m_pMove->m_accele.x = 0.5f;
	}

	if (!pointerInputController->getRightMoveFlag() && 
		!pointerInputController->getLeftMoveFlag())
	{
		this->m_pMove->m_accele.x = 0.0f;
	}
		
	if (pointerInputController->getJumpFlag() == true) 
	{
		//�W�����v���J�n������
		(*this->m_pActions)[(int)PLAYER_ACTION::JUMP]->start();
	}
}