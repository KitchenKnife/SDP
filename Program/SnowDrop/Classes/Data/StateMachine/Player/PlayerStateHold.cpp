#include "PlayerStateHold.h"
#include "Data/Enum/EnumPlayer.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Lib/Input/InputManager.h"

/**
 * @desc	�R���X�g���N�^
 */
CPlayerStateHold::CPlayerStateHold(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer), m_pGirl(pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerStateHold::~CPlayerStateHold(void) {}

/**
 * @desc	�E�����ҋ@��Ԃֈڍs
 */
void CPlayerStateHold::toIdleRight(void)
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
void CPlayerStateHold::toIdleLeft(void)
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
void CPlayerStateHold::toWalkRight(void)
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
void CPlayerStateHold::toWalkLeft(void)
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
void CPlayerStateHold::toJumpRight(void)
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
void CPlayerStateHold::toJumpLeft(void)
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
void CPlayerStateHold::toFallRight(void)
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
void CPlayerStateHold::toFallLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::FALL_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FALL_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	���P�l��������Ԃ���ʏ��Ԃֈڍs�i�E�����j
 */
void CPlayerStateHold::toFreeIdleRight(void) {
	//�E�����ҋ@��Ԃֈڍs
	this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

	(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);
}

/**
 * @desc	���P�l��������Ԃ���ʏ��Ԃֈڍs�i�������j
 */
void CPlayerStateHold::toFreeIdleLeft(void) {
	//�������ҋ@��Ԃֈڍs
	this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

	(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);
}

//==========================================
//
// Class: CPlayerHoldIdleRightState
//
// �v���C���[ ���P�l������ �ҋ@ �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldIdleRightState::CPlayerHoldIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldIdleRightState::~CPlayerHoldIdleRightState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldIdleRightState::start(void)
{

}

/**
 * @desc	�X�V����
 */
void CPlayerHoldIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���


	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�肪�����ꂽ��
	if (!pointerInputController->getHugFlag())
	{
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

	//�W�����v
	if (pointerInputController->getJumpFlag()) 
	{
		//�E�����W�����v��Ԃֈڍs
		this->toJumpRight();
		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldIdleLeftState
//
// �v���C���[ ���P�l������ �ҋ@ ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldIdleLeftState::CPlayerHoldIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldIdleLeftState::~CPlayerHoldIdleLeftState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldIdleLeftState::start(void)
{

}

/**
 * @desc	�X�V����
 */
void CPlayerHoldIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�肪�����ꂽ��
	if (!pointerInputController->getHugFlag())
	{
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

	//�W�����v
	if (pointerInputController->getJumpFlag())
	{
		//�������W�����v��Ԃֈڍs
		this->toJumpLeft();
		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldWalkRightState
//
// �v���C���[ ���P�l������ ���s �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldWalkRightState::CPlayerHoldWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldWalkRightState::~CPlayerHoldWalkRightState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldWalkRightState::start(void)
{

}

/**
 * @desc	�X�V����
 */
void CPlayerHoldWalkRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�肪�����ꂽ��
	if (!pointerInputController->getHugFlag())
	{
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

	//�W�����v
	if (pointerInputController->getJumpFlag())
	{
		//�E�����W�����v��Ԃֈڍs
		this->toJumpRight();
		return;
	}


	//�E�����ҋ@��Ԃֈڍs
	this->toIdleRight();
}

/**
 * @desk	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldWalkRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerHoldWalkLeftState
//
// �v���C���[ ���P�l������ ���s ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldWalkLeftState::CPlayerHoldWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldWalkLeftState::~CPlayerHoldWalkLeftState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldWalkLeftState::start(void)
{

}

/**
 * @desc	�X�V����
 */
void CPlayerHoldWalkLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�肪�����ꂽ��
	if (!pointerInputController->getHugFlag())
	{
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

	//�W�����v
	if (pointerInputController->getJumpFlag())
	{
		//�������W�����v��Ԃֈڍs
		this->toJumpLeft();
		return;
	}

	//�������ҋ@��Ԃֈڍs
	this->toIdleLeft();
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerHoldJumpRightState
//
// �v���C���[ ���P�l������ �W�����v �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldJumpRightState::CPlayerHoldJumpRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldJumpRightState::~CPlayerHoldJumpRightState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldJumpRightState::start(void)
{
	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->start();

	//�v���C���[��X���x���L�^����B
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	�X�V����
 */
void CPlayerHoldJumpRightState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�v���C���[��X���x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�v���C���[�����ֈړ����Ă�����
	if (this->m_pPlayer->m_pMove->m_vel.y <= 0.0f) {
		//������Ԃֈڍs����
		this->toFallRight();

		return;
	}

	//�������W�����v
	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
		//�J�n�������ċN������
		this->start();
		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldJumpRightState::onChangeEvent(void)
{
	//�W�����v�I�����Ƀv���C���[�̃W�����v�A�N�V���������Z�b�g����
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldJumpLeftState
//
// �v���C���[ ���P�l������ �W�����v ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldJumpLeftState::CPlayerHoldJumpLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldJumpLeftState::~CPlayerHoldJumpLeftState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldJumpLeftState::start(void)
{
	//�W�����v�A�N�V�����̃X�^�[�g�֐����J�n
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->start();

	//�v���C���[��X���x���L�^����B
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	�X�V����
 */
void CPlayerHoldJumpLeftState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[��X���x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�v���C���[�����ֈړ����Ă�����
	if (this->m_pPlayer->m_pMove->m_vel.y <= 0.0f) {
		//������Ԃֈڍs����
		this->toFallLeft();

		return;
	}
	//�������W�����v
	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
		//�J�n�������ċN������
		this->start();
		return;
	}

}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldJumpLeftState::onChangeEvent(void)
{
	//�W�����v�I�����Ƀv���C���[�̃W�����v�A�N�V���������Z�b�g����
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->restart(this->m_pPlayer);

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldFallRightState
//
// �v���C���[ ���P�l������ ���� �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldFallRightState::CPlayerHoldFallRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldFallRightState::~CPlayerHoldFallRightState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldFallRightState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	�X�V����
 */
void CPlayerHoldFallRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[�̑��x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�v���C���[�����ֈړ����Ă�����
	if (this->m_pPlayer->m_pMove->m_vel.y == 0.0f) {
		//������Ԃֈڍs����
		this->toIdleRight();

		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldFallRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;

	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldFallLeftState
//
// �v���C���[ ���P�l������ ���� ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerHoldFallLeftState::CPlayerHoldFallLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerHoldFallLeftState::~CPlayerHoldFallLeftState(void) {}

/**
 * @desc	�J�n����
 */
void CPlayerHoldFallLeftState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	�X�V����
 */
void CPlayerHoldFallLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�v���C���[�̑��x���ێ�������
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//�v���C���[�����ֈړ����Ă�����
	if (this->m_pPlayer->m_pMove->m_vel.y == 0.0f) {
		//������Ԃֈڍs����
		this->toIdleLeft();

		return;
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerHoldFallLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;

	this->m_isNext = false;
}
