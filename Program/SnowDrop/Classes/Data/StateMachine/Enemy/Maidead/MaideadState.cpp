//==========================================
//
// File: MaideadState.cpp
//
// Maidead ��ԑJ�� �t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "MaideadState.h"
#include "Model\Character\EnemyCharacter\EnemyCharacter.h"
#include "Data\Enum\EnumEnemy.h"

//==========================================
//
// Class: CMaideadState
//
// Maidead ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadState::CMaideadState(	CEnemyCharacter* const pOwner,
								CPlayerCharacterBoy* const pPlayer,
								CGirlCharacter* const pGirl)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadState::~CMaideadState(void)
{

}

/**
* @desc �ҋ@��Ԃֈڍs
*/
void CMaideadState::toIdle(void)
{
	this->m_pOwner->m_state				=	(int)ENEMY_MAIDEAD_STATE::IDLE;
	this->m_pOwner->m_animationState	=	(int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState		=	(int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey				=	this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �p�j��Ԃֈڍs
*/
void CMaideadState::toWandering(void)
{
	this->m_pOwner->m_state				= (int)ENEMY_MAIDEAD_STATE::WANDERING;
	this->m_pOwner->m_animationState	= (int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState		= (int)ENEMY_MAIDEAD_ACTION_STATE::WANDERING;
	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc �ǐՏ�Ԃֈڍs
*/
void CMaideadState::toChase(void)
{
	this->m_pOwner->m_state				= (int)ENEMY_MAIDEAD_STATE::IDLE;
	this->m_pOwner->m_animationState	= (int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState		= (int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


//==========================================
//
// Class: CMaideadIdleState
//
// Maidead �ҋ@ ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadIdleState::CMaideadIdleState(	CEnemyCharacter* const pOwner,
										CPlayerCharacterBoy* const pPlayer,
										CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner,pPlayer,pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadIdleState::~CMaideadIdleState()
{

}

/**
* @desc	�J�n����
*/
void CMaideadIdleState::start(void)
{
	//�����_���ŃA�N�V�������Ԃ�ݒ�(30~60)
	this->m_actionInterval = rand() % 30 + 31;
}

/**
* @desc �X�V����
*/
void CMaideadIdleState::update(void)
{
	// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
	//this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);

	//�J�E���^�[���C���N�������g
	this->m_actionCounter++;

	


	//�J�E���^�[���C���^�[�o���ȏ�Ȃ�
	if (this->m_actionCounter >= this->m_actionInterval) {
		//�J�E���^�[�����Z�b�g
		this->m_actionCounter = 0;
		
		//���܂悢�s���Ɉڍs
		this->toWandering();
	}
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMaideadIdleState::onChangeEvent(void)
{
	int m_actionInterval = 45;

	this->m_actionCounter = 0;

	//�ҋ@������I��
	this->m_isNext = false;
}


//==========================================
//
// Class: CMaideadWanderingState
//
// Maidead �p�j ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CMaideadWanderingState::CMaideadWanderingState(	CEnemyCharacter* const pOwner,
												CPlayerCharacterBoy* const pPlayer,
												CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc �f�X�g���N�^
*/
CMaideadWanderingState::~CMaideadWanderingState()
{

}

/**
* @desc	�J�n����
*/
void CMaideadWanderingState::start(void)
{
	//�����_���ŕ���������ݒ�
	this->m_vec = (rand() % 3) - 1;

	if (this->m_vec == 0)
	{
		//������~
		for(CAction* pAction : (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState]))
		{
			pAction->stop();
		}
		//�ҋ@��ԂɈڍs
		this->toIdle();
	}

	//������ݒ�
	this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec,0.0f);

	//�����_���ŃA�N�V�������Ԃ�ݒ�(30~60)
	this->m_actionInterval = rand() % 30 + 31;

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(-1.0);
	}
	
	
}

/**
* @desc �X�V����
*/
void CMaideadWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}
		
	//�J�E���^�[���C���N�������g
	this->m_actionCounter++;
	//�J�E���^�[���C���^�[�o���ȏ�Ȃ�
	if (this->m_actionCounter >= this->m_actionInterval) {
		//�J�E���^�[�����Z�b�g
		this->m_actionCounter = 0;
		//�J�n��ԂɈڍs
		this->start();
	}

	// �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
	//this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
}

/**
* @desc ��Ԃ��ς��Ƃ��̏���
*/
void CMaideadWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//�ҋ@������I��
	this->m_isNext = false;
}


//EOF