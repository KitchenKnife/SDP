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
	return this->m_inputFlag.isKeyPressed(kInputType::LEFT);
}

/*
* @desc �E�ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getRightMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::RIGHT);
}

/*
* @desc �W�����v���̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getJumpFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::UP);
}

/*
* @desc �U�����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getAttackFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::Z);
}

/*
* @desc ����Ȃ��t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHolodHandsFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::X);
}

/*
* @desc ���P�l�������t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHugFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::C);
}
//EOF