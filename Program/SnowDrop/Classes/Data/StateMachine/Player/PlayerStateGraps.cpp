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
* @desc	�E�����U����Ԃֈڍs
*/
void CPlayerStateGraps::toAttackRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_RIGHT;
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
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_LEFT;
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

		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

		return;
	}

	//�E�����U����Ԃֈڍs
	if (pointerInputController->getAttackFlag()) {
		//�E�����U����Ԃֈڍs
		this->toAttackRight();
		return;
	}

	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toWalkRight();
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
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

		return;
	}

	//�������U����Ԃֈڍs
	if (pointerInputController->getAttackFlag()) {
		//�������U����Ԃֈڍs
		this->toAttackLeft();
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
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

		return;
	}

	//�E�����U����Ԃֈڍs
	if (pointerInputController->getAttackFlag()) {
		//�E�����U����Ԃֈڍs
		this->toAttackRight();
		return;
	}

	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�����ɕ��s����
		this->m_pPlayer->m_pMove->m_accele.x = 0.5f;
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
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

		return;
	}

	//�������U����Ԃֈڍs
	if (pointerInputController->getAttackFlag()) {
		//�������U����Ԃֈڍs
		this->toAttackLeft();
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


//==========================================
//
// Class: CPlayerGrapsAttackRightState
//
// �v���C���[ �E�����@�U�� ��� �N���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGrapsAttackRightState::CPlayerGrapsAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGrapsAttackRightState::~CPlayerGrapsAttackRightState(void) {}

/**
* @desc	�J�n����
*/
void CPlayerGrapsAttackRightState::start(void)
{
	this->m_pPlayer->setScaleX(-2.0f);

	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

	//�_���[�W�L�����N�^�[�����f�[�^���쐬
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
		cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_right, this->m_pPlayer->m_pMove->m_pos.y),
		1);
	//�_���[�W�L�����N�^�[�����g���K�[���쐬
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
}

/**
* @desc	�X�V����
*/
void CPlayerGrapsAttackRightState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�E�����ҋ@��Ԃ֖߂�
		this->toIdleRight();
		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGrapsAttackRightState::onChangeEvent(void)
{
	this->m_pPlayer->setScaleX(2.0f);


	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerAttackLeftState
//
// �v���C���[ �������@�U�� ��� �N���X
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGrapsAttackLeftState::CPlayerGrapsAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGrapsAttackLeftState::~CPlayerGrapsAttackLeftState() {}

/**
* @desc	�J�n����
*/
void CPlayerGrapsAttackLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

	//�_���[�W�L�����N�^�[�����f�[�^���쐬
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
		cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_left, this->m_pPlayer->m_pMove->m_pos.y),
		1);
	//�_���[�W�L�����N�^�[�����g���K�[���쐬
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
}

/**
* @desc	�X�V����
*/
void CPlayerGrapsAttackLeftState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�E�����ҋ@��Ԃ֖߂�
		this->toIdleLeft();
		return;
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGrapsAttackLeftState::onChangeEvent(void)
{
	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
	this->m_isNext = false;
}

