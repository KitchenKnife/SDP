//==========================================
//
// File: GamepadInputController.cpp
//
// �Q�[���p�b�h���̓R���g���[���[ �t�@�C��
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "GamepadInputController.h"
#include "cocos2d.h"


/**
* @desc �R���X�g���N�^
* @author Shinya Ueba
*/
CGamepadInputController::CGamepadInputController()
{

}

/**
* @desc �f�X�g���N�^
* @author Shinya Ueba
*/
CGamepadInputController::~CGamepadInputController()
{

}


/*
* @desc ���ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getLeftMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::DPAD_LEFT);
}

/*
* @desc �E�ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getRightMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::DPAD_RIGHT);
}

/*
* @desc �W�����v���̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getJumpFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::A);
}

/*
* @desc �U�����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getAttackFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::X);
}
/*
* @desc ����Ȃ��t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getHolodHandsFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::B);
}

/*
* @desc ���P�l�������t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getHugFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::Y);
}

/*
* @desc	�Q�[���I���t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getGameExitFlag(void) 
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::BACK);
}


/**
* @desc ���̓t���O�C���X�^���X�̎擾
* @return�@ ���̓t���O�C���X�^���X
*/
CInputFlag* CGamepadInputController::getInputFlagInstance(void)
{
return &this->m_inputFlag;
}

//EOF