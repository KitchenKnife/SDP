#pragma once
//==========================================
//
// File: InputFlag.h
//
// ���̓t���O���N���X �w�b�_�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================


//==========================================
//
// File: InputFlag.h
//
// ���̓t���O���N���X �w�b�_�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CInputFlag
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CInputFlag(void);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CInputFlag(void);

	/**
	*	@desc	�l�̃N���A
	*/
	virtual void clear()=0;

	/**
	*	@desc	���͂̃t���O���グ�� ( �t���O�A�b�v )
	*	@param	�R�[�h
	*/
	virtual void up(int Type_) = 0;
	/**
	*	@desc	���͂̃t���O�������� ( �t���O�_�E�� )
	*	@praram	�L�[�R�[�h
	*/
	virtual void down(int Type_) = 0;

	/**
	*	@desc	�w�肵���L�[��������Ă��邩�ǂ������擾
	*	@param	�L�[�^�C�v
	*	@return	true...������Ă���
	*	@tips	���͂̃^�C�v�ɂ���ĕω�
	*			�L�[�{�[�h�^�C�v�ł͎g�p����K�v�͂Ȃ�
	*/
	virtual bool isKeyPressed(int Type_) = 0;

	/**
	*	@desc	�w�肵���L�[���g���K�[���͏�Ԃ��擾
	*	@param	�L�[�^�C�v
	*	@return	true...������Ă���
	*	@tips	���͂̃^�C�v�ɂ���ĕω�
	*/
	virtual bool isKeyTrigger(int keyType_)=0;
};