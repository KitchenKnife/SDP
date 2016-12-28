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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	virtual ~CPlayerState(void);

	/**
	 *	@desc	�E�����ҋ@��Ԃֈڍs
	 */
	void toIdleRight(void);

	/**
	 *	@desc	�������ҋ@��Ԃֈڍs
	 */
	void toIdleLeft(void);

	/**
	 *	@desc	�E�������s��Ԃֈڍs
	 */
	void toWalkRight(void);

	/**
	 *	@desc	���������s��Ԃֈڍs
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
	 * @desc	�������U����ԁi�P���ځj�ֈڍs
	 */
	void toAttackFirstLeft(void);

	/**
	 * @desc	�������U����ԁi�Q���ځj�ֈڍs
	 */
	void toAttackSecondLeftt(void);

	/**
	 * @desc	�������U����ԁi�R���ځj�ֈڍs
	 */
	void toAttackThirdLeft(void);

	/**
	 * @desc	�E�������������Ԃֈڍs
	 */
	void toEquipRight(void);

	/**
	 *	@desc	���������������Ԃֈڍs
	 */
	void toEquipLeft(void);

	/**
	 *	@desc	�E�������������������Ԃֈڍs
	 */
	void toUnEquipRight(void);

	/*
	 *	@desc	���������������������Ԃֈڍs
	 */
	void toUnEquipLeft(void);

	/*
	 *	@desc	�E�������͂ޏ�Ԃֈڍs
	 */
	void toGraspRight(void);

	/*
	 *	@desc	���������͂ޏ�Ԃֈڍs
	 */
	void toGraspLeft(void);

	/*
	*	@desc	�E�������݂͂Ȃ���ҋ@��Ԃֈڍs
	*/
	void toGraspIdleRight(void);

	/*
	*	@desc	���������݂͂Ȃ���ҋ@��Ԃֈڍs
	*/
	void toGraspIdleLeft(void);

	/*
	*	@desc	�E�������݂͂Ȃ��������Ԃֈڍs
	*/
	void toGraspWalkRight(void);

	/*
	*	@desc	���������݂͂Ȃ��������Ԃֈڍs
	*/
	void toGraspWalkLeft(void);

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerIdleRightState(void);

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerIdleLeftState(void);

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerWalkRightState(void);

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerWalkLeftState(void);

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
// Class: CPlayerAttackRightState
//
// �v���C���[ �E�����@�U�� ��� �N���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerAttackRightState :public CPlayerState
{
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerAttackRightState(void);

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
	//�A���t���O
	bool m_chainAttackFlag = false;

};

//==========================================
//
// Class: CPlayerAttackLeftState
//
// �v���C���[ �������@�U�� ��� �N���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerAttackLeftState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerAttackLeftState(void);

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
	//�A���t���O
	bool m_chainAttackFlag = false;

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerEquipRightState(void);

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerEquipLeftState(void);

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerUnEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerUnEquipRightState(void);

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
	 * @desc	�R���X�g���N�^
	 */
	CPlayerUnEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	~CPlayerUnEquipLeftState(void);

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
// Class: CPlayerGraspRightState
//
// �v���C���[ �E�����@����Ȃ� �N���X
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CPlayerGraspRightState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerGraspRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerGraspRightState(void);

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
// Class: CPlayerGraspLeftState
//
// �v���C���[ �������@����Ȃ� ��� �N���X
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CPlayerGraspLeftState :public CPlayerState
{
public:
	/**
	* @desc �R���X�g���N�^
	*/
	CPlayerGraspLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc �f�X�g���N�^
	*/
	~CPlayerGraspLeftState(void);

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
// Class: CPlayerGraspIdleRightState
//
// �v���C���[ �E�����@����q���ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CPlayerGraspIdleRightState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspIdleRightState(void);

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
// Class: CPlayerGraspWalkLeftState
//
// �v���C���[ �������@����q���ҋ@ ��� �N���X
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CPlayerGraspIdleLeftState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspIdleLeftState(void);

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
// Class: CPlayerGraspWalkRightState
//
// �v���C���[ �E�����@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerGraspWalkRightState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspWalkRightState(void);

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
// Class: CPlayerGraspWalkLeftState
//
// �v���C���[ �������@���s ��� �N���X
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerGraspWalkLeftState :public CPlayerState
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGraspWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGraspWalkLeftState(void);

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
//EOF