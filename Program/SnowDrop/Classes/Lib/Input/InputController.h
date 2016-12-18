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


//�S�R���g���[���[���ۃN���X
class CController
{
public:
	/**
	* @desc �R���X�g���N�^
	* @author Shinya Ueba
	*/
	CController();


	/**
	* @desc �f�X�g���N�^
	* @author Shinya Ueba
	*/
	virtual ~CController();
	
	/*
	* @desc ���ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getLeftMoveFlag() = 0;

	/*
	* @desc �E�ړ����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getRightMoveFlag() = 0;
	
	/*
	* @desc �W�����v���̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getJumpFlag() = 0;

	/*
	* @desc �U�����̓t���O�擾
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getAttackFlag() = 0;

	/*
	* @desc �Z�[�u���̓t���O�擾 
	* @return true...���͂���@false...���͂Ȃ�
	* @author Shinya Ueba
	*/
	virtual bool getSaveFlag() = 0;
};
//EOF