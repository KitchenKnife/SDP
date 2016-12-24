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
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"

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
CPlayerState::CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer),m_pGirl(pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CPlayerState::~CPlayerState(void)
{

}

/**
*	@desc �E�����ҋ@��Ԃֈڍs
*/
void CPlayerState::toIdleRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
*	@desc �������ҋ@��Ԃֈڍs
*/
void CPlayerState::toIdleLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::IDLE_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::IDLE_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
*	@desc �E�������s��Ԃֈڍs
*/
void CPlayerState::toWalkRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::WALK_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::WALK_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
*	@desc ���������s��Ԃֈڍs
*/
void CPlayerState::toWalkLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::WALK_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
*	@desc ���������Ԃֈڍs
*/
void CPlayerState::toEquip(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::EQUIP;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::EQUIP;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc ����������Ԃֈڍs
*/
void CPlayerState::toUnEquip(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UN_EQUIP;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::UN_EQUIP;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc �E�������͂ޏ�Ԃֈڍs
*/
void CPlayerState::toGraspRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc ���������͂ޏ�Ԃֈڍs
*/
void CPlayerState::toGraspLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRASP_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


//==========================================
//
// Class: CPlayerIdleRightState
//
// �v���C���[ ���� ��� �N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerIdleRightState::CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer,pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerIdleRightState::~CPlayerIdleRightState(void)
{
	

}

/**
* @desc �J�n����
*/
void CPlayerIdleRightState::start(void)
{

}

/**
* @desc �X�V����
*/
void CPlayerIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toWalkRight();
		return;
		//this->m_pMove->m_accele.x = 0.5f;
	}


	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���������s��Ԃֈڍs
		this->toWalkLeft();
		return;
		
		//this->m_pMove->m_accele.x = -0.5f;
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerIdleLeftState
//
// �v���C���[ �������@�ҋ@ ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerIdleLeftState::CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerIdleLeftState::~CPlayerIdleLeftState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerIdleLeftState::start(void)
{

}

/**
* @desc �X�V����
*/
void CPlayerIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();



	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toWalkRight();

		//this->m_pMove->m_accele.x = 0.5f;
	}

	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���������s��Ԃֈڍs
		this->toWalkLeft();

		
		//this->m_pMove->m_accele.x = -0.5f;
	}


}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerWalkRightState
//
// �v���C���[ �������@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerWalkRightState::CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerWalkRightState::~CPlayerWalkRightState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerWalkRightState::start(void)
{

}

/**
* @desc �X�V����
*/
void CPlayerWalkRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�����ɕ��s����
		this->m_pPlayer->m_pMove->m_accele.x = 0.5f;
		return;
	}

	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���������s��Ԃֈڍs
		this->toWalkLeft();
		return;
	}

	//�E�����ҋ@��Ԃֈڍs
	this->toIdleRight();
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerWalkRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerWalkLeftState
//
// �v���C���[ �������@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerWalkLeftState::CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerWalkLeftState::~CPlayerWalkLeftState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerWalkLeftState::start(void)
{

}

/**
* @desc �X�V����
*/
void CPlayerWalkLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	
	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toWalkRight();
		return;
	}

	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//�������ɕ��s����
		this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
		return;
	}

	//�������ҋ@��Ԃֈڍs
	this->toIdleLeft();
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;


	this->m_isNext = false;
}
//EOF