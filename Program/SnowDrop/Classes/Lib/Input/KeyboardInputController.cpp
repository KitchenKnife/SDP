//==========================================
//
// File: KeyboardInputController.h
//
// ���̓R���g���[���[���N���X
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "KeyboardInputController.h"



/**
* @desc �R���X�g���N�^
* @author Shinya Ueba
*/
CKeyboardInputController::CKeyboardInputController(void)
{

}

/**
* @desc �f�X�g���N�^
* @author Shinya Ueba
*/
CKeyboardInputController::~CKeyboardInputController(void)
{

}

/*
* @desc ���ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getLeftMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::LEFT);
}

/*
* @desc �E�ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getRightMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::RIGHT);
}

/*
* @desc �W�����v���̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getJumpFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::UP);
}

/*
* @desc �U�����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getAttackFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::Z);
}

/*
* @desc ����Ȃ��t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHolodHandsFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::X);
}

/*
* @desc ���P�l�������t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHugFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::C);
}

/*
* @desc	�Q�[���I���t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getGameExitFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::ESC);
}


/**
*	@desc �f�o�b�O���[�h�t���O�擾
*	@return true...���͂���@false...���͂Ȃ�
*/
bool CKeyboardInputController::getDebugModeFlag(void)
{
	//�f�o�b�O�p
#ifdef _DEBUG
	return this->m_inputFlag.isKeyPressed((int)kInputType::D);
#endif // DEBUG

	return false;
}



/**
* @desc ���̓t���O�C���X�^���X�̎擾
* @return�@ ���̓t���O�C���X�^���X
*/
CInputFlag* CKeyboardInputController::getInputFlagInstance(void)
{
	return &this->m_inputFlag;
}
//EOF