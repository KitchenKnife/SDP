//==========================================
//
// File: PlayerState.cpp
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "PlayerState.h"
#include "Model\Character\PlayerCharacter\PlayerCharacter.h"

//==========================================
//
// Class: CPlayerState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerState::CPlayerState(int nextRegisterKey, CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CStateBase::CStateBase(nextRegisterKey),m_pPlayer(pPlayer),m_pGirl(pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CPlayerState::~CPlayerState(void)
{

}

//==========================================
//
// Class: CPlayerStandState
//
// �v���C���[ ���� ��� �N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerStandState::CPlayerStandState(int nextRegisterKey,CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(nextRegisterKey,pPlayer,pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerStandState::~CPlayerStandState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerStandState::start(void)
{

}

/**
* @desc �X�V����
*/
void CPlayerStandState::update(void)
{
	//�D�揇�ŏ������Ă���
	
	//�E�Ɉړ����Ă��邩
	if (this->m_pPlayer->m_pMove->m_vel.x > 0)
	{
		this->m_pPlayer->m_state = (int)CPlayerCharacterBoy::PLAYER_STATE::WALK_RIGHT;
		
		//�����Ŏ��̃L�[���w��

		this->m_isNext = true;
		return;
	}

	//���Ɉړ����Ă��邩
	if (this->m_pPlayer->m_pMove->m_vel.x < 0)
	{
		this->m_pPlayer->m_state = (int)CPlayerCharacterBoy::PLAYER_STATE::WALK_RIGHT;

		//�����Ŏ��̃L�[���w��

		this->m_isNext = true;
		return;
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerStandState::onChangeEvent(void)
{
	this->m_nextRegisterKey = this->m_defaultNextRegisterKey;
	this->m_isNext = false;
}
//EOF