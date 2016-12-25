#pragma once
//==========================================
//
// File: KeyboardInputType.h
//
// �L�[�{�[�h���̓^�C�v �t�@�C��
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"InputFlag.h"


/*
*	���̓^�C�v
*/
enum class kInputType : int {
	NONE = -1,
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
	ESC = 4,
	SPACE = 5,
	Z = 6,
	X = 7,
	C = 8,
	A = 9,
	S = 10,
	D = 11,
	MAX_KEY_TYPE,
};

/*
*	�L�[�{�[�h�p���̓t���O
*/
class CKeyboardInputFlag :public CInputFlag{
public:

	//�v���X���
	bool m_up = false;		// ��L�[
	bool m_down = false;	// ���L�[
	bool m_left = false;	// ���L�[
	bool m_right = false;	// �E�L�[
	bool m_esc = false;	// ESC �L�[
	bool m_space = false;	// �X�y�[�X�L�[

	bool m_z = false;		// z �L�[
	bool m_x = false;		// x �L�[
	bool m_c = false;		// c �L�[

	bool m_a = false;		// a �L�[
	bool m_s = false;		// s �L�[
	bool m_d = false;		// d �L�[

	//�g���K�[���
	bool m_upTrigger	= false;		// ��L�[
	bool m_downTrigger	= false;		// ���L�[
	bool m_leftTrigger	= false;		// ���L�[
	bool m_rightTrigger = false;		// �E�L�[
	bool m_escTrigger	= false;		// ESC �L�[
	bool m_spaceTrigger = false;		// �X�y�[�X�L�[
	bool m_zTrigger		= false;		// z �L�[
	bool m_xTrigger		= false;		// x �L�[
	bool m_cTrigger		= false;		// c �L�[
	bool m_aTrigger		= false;		// a �L�[
	bool m_sTrigger		= false;		// s �L�[
	bool m_dTrigger		= false;		// d �L�[

private:

	bool m_arrayTriggerLastSate[(int)kInputType::MAX_KEY_TYPE];

public:
	/**
	*	@desc �R���X�g���N�^
	*/
	CKeyboardInputFlag();


	/**
	*	@desc	�l�̃N���A
	*/
	virtual void clear(void)override;

	/**
	*	@desc	�L�[�̃t���O���グ�� ( �t���O�A�b�v )
	*	@param	�L�[�R�[�h
	*/
	virtual void up(int keyType_)override;
	/**
	*	@desc	�L�[�̃t���O�������� ( �t���O�_�E�� )
	*	@praram	�L�[�R�[�h
	*/
	virtual void down(int keyType_)override;

	/**
	*	@desc	�w�肵���L�[��������Ă��邩�ǂ������擾
	*	@param	�L�[�^�C�v
	*	@return	true...������Ă���
	*	@tips	���͂̃^�C�v�ɂ���ĕω�
	*/
	virtual bool isKeyPressed(int keyType_)override;

	/**
	*	@desc	�w�肵���L�[���g���K�[���͏�Ԃ��擾
	*	@param	�L�[�^�C�v
	*	@return	true...������Ă���
	*	@tips	���͂̃^�C�v�ɂ���ĕω�
	*/
	virtual bool isKeyTrigger(int keyType_)override;
};
//EOF