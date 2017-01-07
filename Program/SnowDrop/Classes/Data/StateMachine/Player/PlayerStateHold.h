#pragma once
//==========================================
//
// File: PlayerStateGraps.h
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
//		�����Ǝ���q�������
//
// 2017/ 1/ 5
//						Author Harada
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../StateMachine.h"

//==========================================
// �O���錾
//==========================================
class CPlayerCharacterBoy;
class CGirlCharacter;

//==========================================
//
// Class: CPlayerStateHold
//
// �v���C���[ ���P�l�������@��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateHold : public CStateBase {
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerStateHold(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	virtual ~CPlayerStateHold(void);

	/**
	 * @desc	�E�����ҋ@��Ԃֈڍs
	 */
	void toIdleRight(void);

	/**
	 * @desc	�������ҋ@��Ԃֈڍs
	 */
	void toIdleLeft(void);

	/**
	 * @desc	�E�������s��Ԃֈڍs
	 */
	void toWalkRight(void);

	/**
	 * @desc	���������s��Ԃֈڍs
	 */
	void toWalkLeft(void);

	/**
	 * @desc	�E�����W�����v��Ԃֈڍs
	 */
	void toJumpRight(void);

	/**
	 * @desc	�������W�����v��Ԃֈڍs
	 */
	void toJumpLeft(void);

	/**
	 * @desc	�E����������Ԃֈڍs
	 */
	void toFallRight(void);

	/**
	 * @desc	������������Ԃֈڍs
	 */
	void toFallLeft(void);

	/**
	 * @desc	���P�l��������Ԃ���ʏ��Ԃֈڍs�i�E�����j
	 */
	void toFreeIdleRight(void);

	/**
	 * @desc	���P�l��������Ԃ���ʏ��Ԃֈڍs�i�������j
	 */
	void toFreeIdleLeft(void);

protected:
	//�Q�Ƃ���v���C���[�L�����N�^�[
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//�Q�Ƃ���K�[���L�����N�^�[
	CGirlCharacter*		m_pGirl = NULL;
};



//==========================================
//
// Class: CPlayerHoldIdleRightState
//
// �v���C���[ ���P�l������ �ҋ@ �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldIdleRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldIdleRightState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldIdleLeftState
//
// �v���C���[ ���P�l������ �ҋ@ ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldIdleLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldIdleLeftState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldWalkRightState
//
// �v���C���[ ���P�l������ ���s �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldWalkRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
 	 */
	~CPlayerHoldWalkRightState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldWalkLeftState
//
// �v���C���[ ���P�l������ ���s ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldWalkLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldWalkLeftState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldJumpRightState
//
// �v���C���[ ���P�l������ �W�����v �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldJumpRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldJumpRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldJumpRightState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:

	//�W�����v����X�����x
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldJumpLeftState
//
// �v���C���[ ���P�l������ �W�����v ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldJumpLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldJumpLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldJumpLeftState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:
	//�W�����v����X�����x
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldFallRightState
//
// �v���C���[ ���P�l������ ���� �E���� ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldFallRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldFallRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldFallRightState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:
	//�W�����v����X�����x
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldFallLeftState
//
// �v���C���[ ���P�l������ ���� ������ ��ԃN���X
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldFallLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerHoldFallLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerHoldFallLeftState(void);

	/**
	 * @desc	�J�n����
	 */
	void start(void)override;

	/**
	 * @desc	�X�V����
	 */
	void update(void)override;

	/**
	 * @desc	��Ԃ��ς��Ƃ��̏���
	 */
	void onChangeEvent(void)override;

private:
	//�W�����v����X�����x
	float m_velX;
};