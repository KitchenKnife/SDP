#pragma once
//==========================================
//
// File: PlayerState.h
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
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
// Class: CPlayerState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerState : public CStateBase
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	virtual ~CPlayerState(void);

	/**
	*	@desc �E�����ҋ@��Ԃֈڍs
	*/
	void toIdleRight(void);

	/**
	*	@desc �������ҋ@��Ԃֈڍs
	*/
	void toIdleLeft(void);

	/**
	*	@desc �E�������s��Ԃֈڍs
	*/
	void toWalkRight(void);

	/**
	*	@desc ���������s��Ԃֈڍs
	*/
	void toWalkLeft(void);

	/**
	 * @desc	�E�����U����ԁi�P���ځj�ֈڍs
	 */
	void toAttackFirstRight(void);

	/**
	 * @desc	�E�����U����ԁi�Q���ځj�ֈڍs
	 */
	void toAttackSecondRight(void);

	/**
	 * @desc	�E�����U����ԁi�R���ځj�ֈڍs
	 */
	void toAttackThirdRight(void);


	/**
	*	@desc �E�������������Ԃֈڍs
	*/
	void toEquipRight(void);

	/**
	*	@desc ���������������Ԃֈڍs
	*/
	void toEquipLeft(void);


	/**
	*	@desc �E�������������������Ԃֈڍs
	*/
	void toUnEquipRight(void);


	/*
	*	@desc ���������������������Ԃֈڍs
	*/
	void toUnEquipLeft(void);


	/*
	*	@desc �E�������͂ޏ�Ԃֈڍs
	*/
	void toGraspRight(void);


	/*
	*	@desc ���������͂ޏ�Ԃֈڍs
	*/
	void toGraspLeft(void);


protected:
	//�Q�Ƃ���v���C���[�L�����N�^�[
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//�Q�Ƃ���K�[���L�����N�^�[
	CGirlCharacter*		m_pGirl = NULL;
};


//==========================================
//
// Class: CPlayerIdleRightState
//
// �v���C���[ �E�����@�ҋ@ ��� �N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerIdleRightState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerIdleRightState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerIdleLeftState
//
// �v���C���[ �������@�ҋ@ ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerIdleLeftState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerIdleLeftState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerWalkRightState
//
// �v���C���[ �E�����@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerWalkRightState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerWalkRightState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerWalkLeftState
//
// �v���C���[ �������@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerWalkLeftState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerWalkLeftState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerAttackRightState
//
// �v���C���[ �E�����@�U�� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerAttackRightState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerAttackRightState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
	//�A���t���O
	bool m_chainAttackFlag;

};

//==========================================
//
// Class: CPlayerEquipRightState
//
// �v���C���[ �E�����@���������� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerEquipRightState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerEquipRightState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerEquipLeftState
//
// �v���C���[ �������@�������� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerEquipLeftState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerEquipLeftState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerUnEquipRightState
//
// �v���C���[ �E�����@�������� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerUnEquipRightState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerUnEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerUnEquipRightState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerUnEquipLeftState
//
// �v���C���[ �E�����@�������� ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerUnEquipLeftState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerUnEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerUnEquipLeftState(void);

	/**
	* @desc �J�n����
	*/
	void start(void)override;
	/**
	* @desc �X�V����
	*/
	void update(void)override;

	// ��Ԃ��ς��Ƃ��̏���
	void onChangeEvent(void)override;

private:
};

//EOF
