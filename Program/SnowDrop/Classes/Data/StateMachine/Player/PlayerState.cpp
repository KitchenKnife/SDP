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
*	@desc �E�����@���������Ԃֈڍs
*/
void CPlayerState::toEquipRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
*	@desc �������@���������Ԃֈڍs
*/
void CPlayerState::toEquipLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/*
*	@desc �E�����@����������Ԃֈڍs
*/
void CPlayerState::toUnEquipRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc �������@����������Ԃֈڍs
*/
void CPlayerState::toUnEquipLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UN_EQUIP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::UN_EQUIP_LEFT;
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
	//���̑����I�ȃv���C���[�̏��
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRASP_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pPlayer->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
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


	//����𑕔�
	if (pointerInputController->getEquipFlag())
	{
		//�E����������Ԃֈڍs
		this->toEquipRight();
		return;
	}


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

	//����𑕔�
	if (pointerInputController->getEquipFlag())
	{
		//������������Ԃֈڍs
		this->toEquipLeft();
		return;
	}

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

	//����𑕔�
	if (pointerInputController->getEquipFlag())
	{
		//�E����������Ԃֈڍs
		this->toEquipRight();
		return;
	}

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

	//����𑕔�
	if (pointerInputController->getEquipFlag())
	{
		//������������Ԃֈڍs
		this->toEquipLeft();
		return;
	}

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

//==========================================
//
// Class: CPlayerEquipRightState
//
// �v���C���[ �E�����@�������� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerEquipRightState::CPlayerEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerEquipRightState::~CPlayerEquipRightState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerEquipRightState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CPlayerEquipRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�����A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{

		//��������
		if (pointerInputController->getUnEquipFlag())
		{
			//�E��������������Ԃֈڍs
			this->toUnEquipRight();
			return;
		}

		//�E�ֈړ��i������� ���s�j
		if (pointerInputController->getRightMoveFlag())
		{
			//�E����������ԁ@���s��Ԃֈڍs
			//	this->toWalkRight();
			return;
		}

		//���ֈړ��i������� ���s�j
		if (pointerInputController->getLeftMoveFlag())
		{
			//�������ɑ�����ԁ@���s�ֈڍs
			//this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
			return;
		}
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerEquipRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerEquipLeftState
//
// �v���C���[ �������@�������� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerEquipLeftState::CPlayerEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerEquipLeftState::~CPlayerEquipLeftState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerEquipLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CPlayerEquipLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�����A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{

		//��������
		if (pointerInputController->getUnEquipFlag())
		{
			//����������������Ԃֈڍs
			this->toUnEquipLeft();
			return;
		}

		//�E�ֈړ��i������� ���s�j
		if (pointerInputController->getRightMoveFlag())
		{
			//�E����������ԁ@���s��Ԃֈڍs
		//	this->toWalkRight();
			return;
		}

		//���ֈړ��i������� ���s�j
		if (pointerInputController->getLeftMoveFlag())
		{
			//�������ɑ�����ԁ@���s�ֈڍs
			//this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
			return;
		}
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerEquipLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerUnEquipRightState
//
// �v���C���[ �E�����@������������ ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerUnEquipRightState::CPlayerUnEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerUnEquipRightState::~CPlayerUnEquipRightState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerUnEquipRightState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CPlayerUnEquipRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�����A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleRight();
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerUnEquipRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerUnEquipLeftState
//
// �v���C���[ �������@������������ ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CPlayerUnEquipLeftState::CPlayerUnEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc �f�X�g���N�^
*/
CPlayerUnEquipLeftState::~CPlayerUnEquipLeftState(void)
{


}

/**
* @desc �J�n����
*/
void CPlayerUnEquipLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CPlayerUnEquipLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�����A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�������ҋ@��Ԃֈڍs
		this->toIdleLeft();
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CPlayerUnEquipLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}
//EOF