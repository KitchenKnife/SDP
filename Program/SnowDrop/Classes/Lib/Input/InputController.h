#pragma once
//==========================================
//
// File: InputController.h
//
// ���̓R���g���[���[���N���X
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
#include "InputFlag.h"


//==========================================
//
// Class: CInputController
//
// ���̓R���g���[���[���N���X
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CInputController
{
public:
	/**
	* @desc �R���X�g���N�^
	* @author Shinya Ueba
	*/
	CInputController(void);


	/**
	* @desc �f�X�g���N�^
	* @author Shinya Ueba
	*/
	virtual ~CInputController(void);
	
	/*
	* @desc ���ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getLeftMoveFlag(void) = 0;

	/*
	* @desc �E�ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getRightMoveFlag(void) = 0;
	
	/*
	* @desc �W�����v���̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getJumpFlag(void) = 0;

	/*
	* @desc �U�����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getAttackFlag(void) = 0;

	/*
	* @desc ����Ȃ��t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getHolodHandsFlag(void) = 0;

	/*
	* @desc ���P�l�������t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getHugFlag(void) = 0;


	/*
	* @desc	�Q�[���I���t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getGameExitFlag(void) = 0;

	/**
	*	@desc �f�o�b�O���[�h�t���O�擾
	*	@return true...���͂���@false...���͂Ȃ�
	*/
	virtual bool getDebugModeFlag(void) = 0;

	/**
	* @desc ���̓t���O�C���X�^���X�̎擾
	* @return�@ ���̓t���O�C���X�^���X
	*/
	virtual CInputFlag* getInputFlagInstance(void) = 0;


};
//EOF