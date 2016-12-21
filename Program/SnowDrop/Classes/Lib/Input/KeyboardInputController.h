#pragma once
//==========================================
//
// File: KeyboardInputController.h
//
// �L�[�{�[�h���̓R���g���[���[ �t�@�C��
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "InputController.h"



//==========================================
//
// Class: CKeyboardInputController
//
// �L�[�{�[�h���̓R���g���[���[�N���X
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CKeyboardInputController : public CInputController
{
public:
	/**
	* @desc �R���X�g���N�^
	* @author Shinya Ueba
	*/
	CKeyboardInputController();


	/**
	* @desc �f�X�g���N�^
	* @author Shinya Ueba
	*/
	virtual ~CKeyboardInputController();

	/*
	* @desc ���ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getLeftMoveFlag()override;

	/*
	* @desc �E�ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getRightMoveFlag()override;

	/*
	* @desc �W�����v���̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getJumpFlag()override;

	/*
	* @desc �U�����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getAttackFlag()override;

	/*
	* @desc �U�����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getCheckFlag()override;

	/*
	* @desc �Z�[�u���̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getSaveFlag()override;
};
//EOF