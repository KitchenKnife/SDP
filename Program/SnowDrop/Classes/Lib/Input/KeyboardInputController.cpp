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
CKeyboardInputController::CKeyboardInputController()
{

}

/**
* @desc �f�X�g���N�^
* @author Shinya Ueba
*/
CKeyboardInputController::~CKeyboardInputController()
{

}

/*
* @desc ���ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getLeftMoveFlag()
{
	return false;
}

/*
* @desc �E�ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getRightMoveFlag()
{
	return false;
}

/*
* @desc �W�����v���̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getJumpFlag()
{
	return false;
}

/*
* @desc �U�����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getAttackFlag()
{
	return false;
}

/*
* @desc �U�����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getCheckFlag()
{
	return false;
}

/*
* @desc �Z�[�u���̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CKeyboardInputController::getSaveFlag()
{
	return false;
}
//EOF