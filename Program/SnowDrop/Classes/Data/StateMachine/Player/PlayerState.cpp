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
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

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
 * @desc	�R���X�g���N�^
 */
CPlayerState::CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer),m_pGirl(pGirl){}

/**
 * @desc	�f�X�g���N�^ 
 */
CPlayerState::~CPlayerState(void){}

/**
 * @desc	�E�����ҋ@��Ԃֈڍs
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
 * @desc	�������ҋ@��Ԃֈڍs
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
 * @desc	�E�������s��Ԃֈڍs
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
 * @desc	���������s��Ԃֈڍs
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
 * @desc	�E�����U����ԁi�P���ځj�ֈڍs
 */
void CPlayerState::toAttackFirstRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�E�����U����ԁi�Q���ځj�ֈڍs
 */
void CPlayerState::toAttackSecondRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�E�����U����ԁi�R���ځj�ֈڍs
 */
void CPlayerState::toAttackThirdRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�������U����ԁi�P���ځj�ֈڍs
 */
void CPlayerState::toAttackFirstLeft(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�������U����ԁi�Q���ځj�ֈڍs
 */
void CPlayerState::toAttackSecondLeftt(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�������U����ԁi�R���ځj�ֈڍs
 */
void CPlayerState::toAttackThirdLeft(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
 * @desc	�E�����@���������Ԃֈڍs
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
 * @desc	�������@���������Ԃֈڍs
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
 * @desc	�E�����@����������Ԃֈڍs
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
 * @desc	�������@����������Ԃֈڍs
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
 * @desc	�E�������͂ޏ�Ԃֈڍs
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
 * @desc	���������͂ޏ�Ԃֈڍs
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

/*
*	@desc	�E�������݂͂Ȃ���ҋ@��Ԃֈڍs
*/
void CPlayerState::toGraspIdleRight(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_IDLE_RIGHT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pPlayer->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc	���������݂͂Ȃ���ҋ@��Ԃֈڍs
*/
void CPlayerState::toGraspIdleLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_IDLE_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pPlayer->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/*
*	@desc	�E�������݂͂Ȃ��������Ԃֈڍs
*/
void CPlayerState::toGraspWalkRight(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_WALK_RIGHT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_RIGHT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pPlayer->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//�ҋ@������I��
	this->m_isNext = true;

}

/*
*	@desc	���������݂͂Ȃ��������Ԃֈڍs
*/
void CPlayerState::toGraspWalkLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_WALK_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
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
// �v���C���[ �E���� �ҋ@ ��� �N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerIdleRightState::CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer,pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerIdleRightState::~CPlayerIdleRightState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerIdleRightState::start(void)
{
	
}

/**
 * @desc	�X�V����
 */
void CPlayerIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	//�K�[�����擾
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();


	float distanceToGirl = customMath->lengthBitweenChara(pPlayer, pGirl);
	if (distanceToGirl <= 100.0f)
	{

		if (!pPlayer->getGrapsMark())
		{
			cocos2d::CCParticleSystemQuad* pGrapsMark = cocos2d::CCParticleSystemQuad::create(PARTICLE_GRAPS_MARK);
			pGrapsMark->resetSystem();
			pPlayer->setGrapsMark(pGrapsMark);
			pPlayer->getParent()->addChild(pGrapsMark);
			if (pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				pGrapsMark->setPosition(pPlayer->m_pMove->m_pos.x + distanceToGirl*0.5f, pPlayer->m_pMove->m_pos.y - 10.0f);
			}
			else
			{
				pGrapsMark->setPosition(pPlayer->m_pMove->m_pos.x - distanceToGirl*0.5f, pPlayer->m_pMove->m_pos.y - 10.0f);
			}
		}

		if (pointerInputController->getHolodHandsFlag())
		{

			//����q��
			pGirl->setHoldHandsFlag(true);


			if (pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//����q���E��Ԃֈڍs
				this->toGraspRight();
			}
			else
			{
				//����q������Ԃֈڍs
				this->toGraspLeft();
			}
			return;
		}

	}



	//����𑕔�
	if (pointerInputController->getEquipFlag())
	{
		//�E����������Ԃֈڍs
	//	this->toEquipRight();
		return;
	}

	//�E�U��
	if (pointerInputController->getAttackFlag()) {
		//�E�U����Ԃֈڍs(�P����)
		this->toAttackFirstRight();
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

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
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
 * @desc	�R���X�g���N�^
 */
CPlayerIdleLeftState::CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerIdleLeftState::~CPlayerIdleLeftState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerIdleLeftState::start(void)
{

}

/**
 * @desc	�X�V����
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
	
	//���U��
	if (pointerInputController->getAttackFlag()) {
		//���U����Ԃֈڍs(�P����)
		this->toAttackFirstLeft();
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

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerWalkRightState
//
// �v���C���[ �E�����@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerWalkRightState::CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerWalkRightState::~CPlayerWalkRightState(void){}

/**
 * @desc	 �J�n����
 */
void CPlayerWalkRightState::start(void)
{

}

/**
 * @desc	�X�V����
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
	
	//�E�U��
	if (pointerInputController->getAttackFlag()) {
		//�E�U����Ԃֈڍs(�P����)
		this->toAttackFirstRight();
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
 * @desc	�R���X�g���N�^
 */
CPlayerWalkLeftState::CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerWalkLeftState::~CPlayerWalkLeftState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerWalkLeftState::start(void)
{

}

/**
 * @desc	�X�V����
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

	//���U��
	if (pointerInputController->getAttackFlag()) {
		//���U����Ԃֈڍs(�P����)
		this->toAttackFirstLeft();
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

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;


	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerAttackRightState
//
// �v���C���[ �E�����@�U�� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerAttackRightState::CPlayerAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerAttackRightState::~CPlayerAttackRightState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerAttackRightState::start(void)
{
	this->m_pPlayer->setScaleX(-2.0f);

	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

	//�A���t���O��false�Ŏn�߂�
	this->m_chainAttackFlag = false;

	//�_���[�W�L�����N�^�[�����f�[�^���쐬
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
															cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_right, this->m_pPlayer->m_pMove->m_pos.y),
															30);
	//�_���[�W�L�����N�^�[�����g���K�[���쐬
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
}

/**
 * @desc	�X�V����
 */
void CPlayerAttackRightState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�U���{�^���������ꂽ��
	if (pointerInputController->getAttackFlag())
	{
		//�U���A���t���O��true �ɂ���
		this->m_chainAttackFlag = true;
	}

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�U���A���t���O�� false �Ȃ�
		if (this->m_chainAttackFlag == false) {
			//�E�����ҋ@��Ԃ֖߂�
			this->toIdleRight();
			return;
		}

		(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

		//�I�����Ă�����
		//���݂̃v���C���[�̃A�j���[�V������Ԃ��P���ڂȂ�
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT) {
			//�Q���ڂɈڍs����B
			this->toAttackSecondRight();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_RIGHT) {
			//�R���ڂɈڍs����
			this->toAttackThirdRight();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_RIGHT) {
			//�E�����ҋ@��Ԃ֖߂�
			this->toIdleRight();
			return;
		}
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerAttackRightState::onChangeEvent(void)
{
	this->m_pPlayer->setScaleX(2.0f);

	//�A���t���O��false�ɖ߂�
	//start��false�ɂ��Ă��邪�O�̂��߂����ɂ��L�q���Ă���
	this->m_chainAttackFlag = false;

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
CPlayerAttackLeftState::CPlayerAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerAttackLeftState::~CPlayerAttackLeftState(){}

/**
 * @desc	�J�n����
 */
void CPlayerAttackLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

	//�A���t���O��false�Ŏn�߂�
	this->m_chainAttackFlag = false;

	//�_���[�W�L�����N�^�[�����f�[�^���쐬
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
															cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_left, this->m_pPlayer->m_pMove->m_pos.y),
															30);
	//�_���[�W�L�����N�^�[�����g���K�[���쐬
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
}

/**
 * @desc	�X�V����
 */
void CPlayerAttackLeftState::update(void)
{
	//�D�揇�ŏ������Ă���
	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//�U���{�^���������ꂽ��
	if (pointerInputController->getAttackFlag())
	{
		//�U���A���t���O��true �ɂ���
		this->m_chainAttackFlag = true;
	}

	//�A�j���[�V�������I���������ǂ����̃t���O
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�U���A���t���O�� false �Ȃ�
		if (this->m_chainAttackFlag == false) {
			//�����������ҋ@��Ԃ֖߂�
			this->toIdleLeft();
			return;
		}

		(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

		//�I�����Ă�����
		//���݂̃v���C���[�̃A�j���[�V������Ԃ��P���ڂȂ�
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT) {
			//�Q���ڂɈڍs����B
			this->toAttackSecondLeftt();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_LEFT) {
			//�R���ڂɈڍs����
			this->toAttackThirdLeft();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_LEFT) {
			//�E�����ҋ@��Ԃ֖߂�
			this->toIdleLeft();
			return;
		}
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerAttackLeftState::onChangeEvent(void)
{
	//�A���t���O��false�ɖ߂�
	//start��false�ɂ��Ă��邪�O�̂��߂����ɂ��L�q���Ă���
	this->m_chainAttackFlag = false;

	//���̃X�e�[�g�ֈڍs���邱�Ƃ��m�肵�Ă���̂Ō��ɖ߂��Ă���
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
 * @desc	�R���X�g���N�^
 */
CPlayerEquipRightState::CPlayerEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerEquipRightState::~CPlayerEquipRightState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerEquipRightState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc	�X�V����
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

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
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
 * @desc	�R���X�g���N�^
 */
CPlayerEquipLeftState::CPlayerEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerEquipLeftState::~CPlayerEquipLeftState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerEquipLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc	�X�V����
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


/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
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
 * @desc	�R���X�g���N�^
 */
CPlayerUnEquipRightState::CPlayerUnEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc �f�X�g���N�^
 */
CPlayerUnEquipRightState::~CPlayerUnEquipRightState(void){}

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


/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
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
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc �f�X�g���N�^
 */
CPlayerUnEquipLeftState::~CPlayerUnEquipLeftState(void){}

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


/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerUnEquipLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}




//==========================================
//
// Class: CPlayerGrapsRightState
//
// �v���C���[ �E�����@����q�� ��� �N���X
//
// 2016/12/26
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerGraspRightState::CPlayerGraspRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerGraspRightState::~CPlayerGraspRightState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerGraspRightState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc	�X�V����
 */
void CPlayerGraspRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�����A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toGraspIdleRight();
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerGraspRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerGrapsLeftState
//
// �v���C���[ �������@����q�� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	�R���X�g���N�^
 */
CPlayerGraspLeftState::CPlayerGraspLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	�f�X�g���N�^
 */
CPlayerGraspLeftState::~CPlayerGraspLeftState(void){}

/**
 * @desc	�J�n����
 */
void CPlayerGraspLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

 /**
 * @desc	�X�V����
 */
void CPlayerGraspLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//���̓R���g���[���[�̎擾
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//�����A�j���[�V�������I�������
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//�������ҋ@��Ԃֈڍs
		this->toGraspIdleLeft();
	}
}

/**
 * @desc	��Ԃ��ς��Ƃ��̏���
 */
void CPlayerGraspLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
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
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

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

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleRight();
		return;
	}


	//���U��
	if (pointerInputController->getAttackFlag()) {
		//���U����Ԃֈڍs(�P����)
	//	this->toAttackFirstLeft();
		return;
	}


	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toGraspWalkRight();
	}

	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���������s��Ԃֈڍs
		this->toGraspWalkLeft();
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
// �v���C���[ �������@����q�� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CPlayerGraspIdleLeftState::CPlayerGraspIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

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

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleLeft();
		return;
	}


	//���U��
	if (pointerInputController->getAttackFlag()) {
		//���U����Ԃֈڍs(�P����)
	//	this->toAttackFirstLeft();
		return;
	}


	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toGraspWalkRight();

		//this->m_pMove->m_accele.x = 0.5f;
	}

	//���ֈړ��i���s�j
	if (pointerInputController->getLeftMoveFlag())
	{
		//���������s��Ԃֈڍs
		this->toGraspWalkLeft();


		//this->m_pMove->m_accele.x = -0.5f;
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
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	�f�X�g���N�^
*/
CPlayerGraspWalkRightState::~CPlayerGraspWalkRightState(void) {}

/**
* @desc	 �J�n����
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


	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleRight();
		return;
	}

	//�E�U��
	if (pointerInputController->getAttackFlag()) {
		//�E  ����q���U����Ԃֈڍs
		//this->toAttackFirstRight();
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
		this->toGraspWalkLeft();
		return;
	}

	//�E�����ҋ@��Ԃֈڍs
	this->toGraspIdleRight();
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
// Class: CPlayerWalkLeftState
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
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

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

	//�肪�����ꂽ��
	if (!pointerInputController->getHolodHandsFlag())
	{
		//�������ҋ@��Ԃֈڍs
		this->toIdleLeft();
		return;
	}

	//���U��
	if (pointerInputController->getAttackFlag()) {
		//���U����Ԃֈڍs(�P����)
		//this->toAttackFirstLeft();
		return;
	}

	//�E�ֈړ��i���s�j
	if (pointerInputController->getRightMoveFlag())
	{
		//�E�������s��Ԃֈڍs
		this->toGraspWalkRight();
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
	this->toGraspIdleLeft();
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CPlayerGraspWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;


	this->m_isNext = false;
}



//EOF