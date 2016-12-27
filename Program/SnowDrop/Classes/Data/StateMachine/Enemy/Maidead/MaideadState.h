#pragma once
//==========================================
//
// File: MaideadState.h
//
// Maidead�@��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../EnemyState.h"


//==========================================
//
// Class: CMaideadIdleState
//
// Maidead  ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadState : public CEnemyState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadState(	CEnemyCharacter* const pOwner,
					CPlayerCharacterBoy* const pPlayer,
					CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadState(void);

	/**
	* @desc �ҋ@��Ԃֈڍs
	*/
	void toIdle(void);

	/**
	* @desc �p�j��Ԃֈڍs
	*/
	void toWandering(void);

	/**
	* @desc �ǐՏ�Ԃֈڍs
	*/
	void toChase(void);

};

//==========================================
//
// Class: CMaideadIdleState
//
// Maidead �ҋ@ ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadIdleState : public CMaideadState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadIdleState(	CEnemyCharacter* const pOwner,
						CPlayerCharacterBoy* const pPlayer,
						CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadIdleState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:
	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;
};

//==========================================
//
// Class: CMaideadWanderingState
//
// Maidead �p�j ��� �N���X
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadWanderingState : public CMaideadState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CMaideadWanderingState(	CEnemyCharacter* const pOwner,
							CPlayerCharacterBoy* const pPlayer,
							CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CMaideadWanderingState(void);

	/**
	* @desc	�J�n����
	*/
	void start(void);

	/**
	* @desc �X�V����
	*/
	void update(void);

	/**
	* @desc ��Ԃ��ς��Ƃ��̏���
	*/
	void onChangeEvent(void);

private:

	//�A�N�V�������s�����ԁi�����_����30�`60�Őݒ肳���j
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//���낤�낷�����
	int m_vec = 1;
};

//EOF