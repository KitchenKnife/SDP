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
#include "KeyboardInputType.h"



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
private:
	//�L�[�{�[�h���̓t���O
	CKeyboardInputFlag m_inputFlag;

public:
	/**
	* @desc �R���X�g���N�^
	* @author Shinya Ueba
	*/
	CKeyboardInputController(void);


	/**
	* @desc �f�X�g���N�^
	* @author Shinya Ueba
	*/
	virtual ~CKeyboardInputController(void);

	/*
	* @desc ���ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getLeftMoveFlag(void)override;

	/*
	* @desc �E�ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getRightMoveFlag(void)override;

	/*
	* @desc �W�����v���̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getJumpFlag(void)override;

	/*
	* @desc �U�����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getAttackFlag(void)override;

	/*
	* @desc ����Ȃ��t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getHolodHandsFlag(void)override;

	/*
	* @desc ���P�l�������t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	bool getHugFlag(void)override;
};
//EOF