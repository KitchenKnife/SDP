#pragma once
//==========================================
//
// File: GirlState.h
//
// Girl��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../StateMachine.h"


//==========================================
//
// Class: CGirlStandState
//
// Girl ���� ��� �N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CGirlStandState :public CStateBase
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CGirlStandState(int nextRegisterKey);

	/**
	* @desc �f�X�g���N�^
	*/
	~CGirlStandState();

	/**
	* @desc �J�n����
	*/
	void start()override;
	/**
	* @desc �X�V����
	*/
	void update()override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent()override;

private:


};

//EOF