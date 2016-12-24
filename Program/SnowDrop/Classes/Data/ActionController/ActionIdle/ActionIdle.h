#pragma once
//==========================================
//
// File: ActionIdle.h
//
// �A�N�V�����@�ҋ@ �w�b�_�[�t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../Action.h"


//==========================================
//
// Class: ActionIdle
//
// �A�N�V�����@�ҋ@		�N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CActionIdle : public CAction
{
private:
	//�A�N�V���������ǂ����̃t���O true...�A�N�V������
	bool m_inAction = false;

public:

	/**
	* @desc �R���X�g���N�^
	*/
	CActionIdle();

	/**
	* @desc �A�N�V�����J�n
	*/
	void start(void)override;

	/**
	* @desc �X�V����
	* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc �A�N�V�����I��
	*/
	void stop(void)override;
};
//EOF
