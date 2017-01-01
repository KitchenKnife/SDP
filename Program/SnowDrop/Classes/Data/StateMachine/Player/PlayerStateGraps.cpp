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
#include "PlayerStateGraps.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"


//==========================================
//
// Class: CPlayerStateGraps
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerStateGraps::CPlayerStateGraps(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer), m_pGirl(pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerStateGraps::~CPlayerStateGraps(void) {}


/**
* @desc	�E�����ҋ@��Ԃֈڍs
*/
void CPlayerStateGraps::toIdleRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�������ҋ@��Ԃֈڍs
*/
void CPlayerStateGraps::toIdleLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�E�������s��Ԃֈڍs
*/
void CPlayerStateGraps::toWalkRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	���������s��Ԃֈڍs
*/
void CPlayerStateGraps::toWalkLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc	�E�����W�����v��Ԃֈڍs
*/
void CPlayerStateGraps::toJumpRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::JUMP_RIGHT;
	this->m_pPlayer->m_actionState = (int)PLAYER_ACTION_STATE::JUMP;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�������W�����v��Ԃֈڍs
*/
void CPlayerStateGraps::toJumpLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::JUMP_LEFT;
	this->m_pPlayer->m_actionState = (int)PLAYER_ACTION_STATE::JUMP;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/**
* @desc	�E����������Ԃֈڍs
*/
void CPlayerStateGraps::toFallRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::FALL_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FALL_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	������������Ԃֈڍs
*/
void CPlayerStateGraps::toFallLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::FALL_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FALL_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�E�����U����Ԃֈڍs
*/
void CPlayerStateGraps::toAttackRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�������U����Ԃֈڍs
*/
void CPlayerStateGraps::toAttackLeft(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�E�����@���������Ԃֈڍs
*/
void CPlayerStateGraps::toEquipRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�������@���������Ԃֈڍs
*/
void CPlayerStateGraps::toEquipLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/*
* @desc	�E�����@����������Ԃֈڍs
*/
void CPlayerStateGraps::toUnEquipRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
* @desc	�������@����������Ԃֈڍs
*/
void CPlayerStateGraps::toUnEquipLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UN_EQUIP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::UN_EQUIP_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/*
* @desc	�E�������͂ޏ�Ԃֈڍs
*/
void CPlayerStateGraps::toGraspRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
* @desc	���������͂ޏ�Ԃֈڍs
*/
void CPlayerStateGraps::toGraspLeft(void)
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
// Class: CPlayerGraspIdleRightState
//
// �v���C���[ �E�����@����q�� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspIdleRightState::CPlayerGraspIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspIdleRightState::~CPlayerGraspIdleRightState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspIdleRightState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerGraspIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���


	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���擾
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		pGirl->setHoldHandsFlag(false);

		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

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
		//���������s��Ԃֈڍs
		this->toWalkLeft();
		return;
	}


}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerGraspIdleLeftState
//
//	�v���C���[ �������@����q�� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspIdleLeftState::CPlayerGraspIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspIdleLeftState::~CPlayerGraspIdleLeftState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspIdleLeftState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerGraspIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���擾
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		pGirl->setHoldHandsFlag(false);

		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

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
		//���������s��Ԃֈڍs
		this->toWalkLeft();
		return;
	}



}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspWalkRightState
//
// �v���C���[ �E���� ����q���@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspWalkRightState::CPlayerGraspWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspWalkRightState::~CPlayerGraspWalkRightState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspWalkRightState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerGraspWalkRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���擾
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		pGirl->setHoldHandsFlag(false);


		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

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

/**
* @desk	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspWalkRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerGraspWalkLeftState
//
// �v���C���[ �������@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspWalkLeftState::CPlayerGraspWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspWalkLeftState::~CPlayerGraspWalkLeftState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGraspWalkLeftState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CPlayerGraspWalkLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[���擾
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		pGirl->setHoldHandsFlag(false);

		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

		return;
	}

	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�����ɕ��s��Ԃֈڍs
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

	//�E�����ҋ@��Ԃֈڍs
	this->toIdleLeft();
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}