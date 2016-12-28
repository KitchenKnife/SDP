//==========================================
//
// File: GirlState.cpp
//
// Girl��ԑJ�� �t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "GirlState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\GirlCharacter\GirlCharacter.h"
#include "Data\Enum\EnumGirl.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"


//==========================================
//
// Class: CGirlState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlState::CGirlState(CPlayerCharacterGirl* pOwner)
:m_pGirl(pOwner){}

/**
* @desc	�f�X�g���N�^
*/
CGirlState::~CGirlState(void) {}

/**
* @desc	�E�����ҋ@��Ԃֈڍs
*/
void CGirlState::toIdleRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::IDLE_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�������ҋ@��Ԃֈڍs
*/
void CGirlState::toIdleLeft(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::IDLE_LEFT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	�E�������s��Ԃֈڍs
*/
void CGirlState::toWalkRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::WALK_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/**
* @desc	���������s��Ԃֈڍs
*/
void CGirlState::toWalkLeft(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::WALK_LEFT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_LEFT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}



/*
* @desc	�E�������͂ޏ�Ԃֈڍs
*/
void CGirlState::toGraspRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::GRASP_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
* @desc	���������͂ޏ�Ԃֈڍs
*/
void CGirlState::toGraspLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::GRASP_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc	�E�������݂͂Ȃ���ҋ@��Ԃֈڍs
*/
void CGirlState::toGraspIdleRight(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_IDLE_RIGHT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_RIGHT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}

/*
*	@desc	���������݂͂Ȃ���ҋ@��Ԃֈڍs
*/
void CGirlState::toGraspIdleLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_IDLE_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;
}


/*
*	@desc	�E�������݂͂Ȃ��������Ԃֈڍs
*/
void CGirlState::toGraspWalkRight(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_WALK_RIGHT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_RIGHT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;

}

/*
*	@desc	���������݂͂Ȃ��������Ԃֈڍs
*/
void CGirlState::toGraspWalkLeft(void)
{
	//���̑����I�ȃv���C���[�̏��
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_WALK_LEFT;
	//���݂̃v���C���[�̃A�j���[�V�������
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_LEFT;
	//���݂̃v���C���[�̃A�N�V�������
	this->m_pGirl->m_actionState = 0;
	//���̑����I�ȃv���C���[�̏�Ԃ����ɍs���X�e�[�g�Ƃ��Ďw��
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//�ҋ@������I��
	this->m_isNext = true;

}

//==========================================
//
// Class: CGirlIdleRightState
//
// �K�[�� �E���� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlIdleRightState::CGirlIdleRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlIdleRightState::~CGirlIdleRightState(void) {}

/**
* @desc	�J�n����
*/
void CGirlIdleRightState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CGirlIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	

	if (this->m_pGirl->getHoldHandsFlag())
	{
		if (pPlayer->m_pMove->m_pos.x <= this->m_pGirl->m_pMove->m_pos.x)
		{
			this->toGraspLeft();
		}
		else
		{
			this->toGraspRight();
		}
	}	
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CGirlIdleLeftState
//
// �K�[�� �������@�ҋ@ ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlIdleLeftState::CGirlIdleLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlIdleLeftState::~CGirlIdleLeftState(void) {}

/**
* @desc	�J�n����
*/
void CGirlIdleLeftState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CGirlIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	if (this->m_pGirl->getHoldHandsFlag())
	{
		if (pPlayer->m_pMove->m_pos.x <= this->m_pGirl->m_pMove->m_pos.x)
		{
			this->toGraspLeft();
		}
		else
		{
			this->toGraspRight();
		}
	}
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGrapsRightState
//
// �K�[�� �E�����@����q�� ��� �N���X
//
// 2016/12/26
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CGirlGraspRightState::CGirlGraspRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner)
{


}

/**
* @desc �f�X�g���N�^
*/
CGirlGraspRightState::~CGirlGraspRightState(void)
{


}

/**
* @desc �J�n����
*/
void CGirlGraspRightState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CGirlGraspRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�����A�j���[�V�������I�������
	if ((*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->isEnd())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toGraspIdleRight();
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CGirlGraspRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGrapsLeftState
//
// �K�[�� �������@����q�� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CGirlGraspLeftState::CGirlGraspLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner)
{


}

/**
* @desc �f�X�g���N�^
*/
CGirlGraspLeftState::~CGirlGraspLeftState(void)
{


}

/**
* @desc �J�n����
*/
void CGirlGraspLeftState::start(void)
{
	//���݂̃A�j���[�V���������Z�b�g
	(*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->reset();
}

/**
* @desc �X�V����
*/
void CGirlGraspLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�����A�j���[�V�������I�������
	if ((*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->isEnd())
	{
		//�������ҋ@��Ԃֈڍs
		this->toGraspIdleLeft();
	}
}

// ��Ԃ��ς��Ƃ��̏���
void CGirlGraspLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlGraspIdleRightState
//
// �K�[�� �E�����@����q�� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspIdleRightState::CGirlGraspIdleRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspIdleRightState::~CGirlGraspIdleRightState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspIdleRightState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CGirlGraspIdleRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�肪�����ꂽ��
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleRight();
		return;
	}


	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_RIGHT)
	{
		this->toGraspWalkRight();
	}
	else if(pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_LEFT)
	{
		this->toGraspWalkLeft();
	}

}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CGirlGraspIdleLeftState
//
//�@�K�[�� �������@����q�� �ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspIdleLeftState::CGirlGraspIdleLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspIdleLeftState::~CGirlGraspIdleLeftState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspIdleLeftState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CGirlGraspIdleLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�肪�����ꂽ��
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//�������ҋ@��Ԃֈڍs
		this->toIdleLeft();
		return;
	}

	//�v���C���[���擾
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_RIGHT)
	{
		this->toGraspWalkRight();
	}
	else if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_LEFT)
	{
		this->toGraspWalkLeft();
	}

}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlGraspWalkRightState
//
// �K�[�� �E���� ����q���@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspWalkRightState::CGirlGraspWalkRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspWalkRightState::~CGirlGraspWalkRightState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspWalkRightState::start(void)
{

}


/**
* @desc	�X�V����
*/
void CGirlGraspWalkRightState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�肪�����ꂽ��
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleRight();
		return;
	}

	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	this->m_pGirl->m_pMove->m_pos.set(pPlayer->m_pMove->m_pos);
}

/**
* @desk	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspWalkRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGraspWalkLeftState
//
// �v���C���[ �������@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	�R���X�g���N�^
*/
CGirlGraspWalkLeftState::CGirlGraspWalkLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	�f�X�g���N�^
*/
CGirlGraspWalkLeftState::~CGirlGraspWalkLeftState(void) {}

/**
* @desc	�J�n����
*/
void CGirlGraspWalkLeftState::start(void)
{

}

/**
* @desc	�X�V����
*/
void CGirlGraspWalkLeftState::update(void)
{
	//�D�揇�ŏ������Ă���

	//�肪�����ꂽ��
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//�E�����ҋ@��Ԃֈڍs
		this->toIdleLeft();
		return;
	}

	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	this->m_pGirl->m_pMove->m_pos.set(pPlayer->m_pMove->m_pos);
}

/**
* @desc	��Ԃ��ς��Ƃ��̏���
*/
void CGirlGraspWalkLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//EOF