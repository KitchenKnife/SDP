#pragma once
//==========================================
//
// File: PlayerStateGraps.h
//
// �v���C���[��ԑJ�� �w�b�_�[�t�@�C��
//		�����Ǝ���q�������
//
// 2017/ 1/ 1
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
// Class: CPlayerState
//
// �v���C���[ ��� ���N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateGraps : public CStateBase {
public:
	/**
	 * @desc	�R���X�g���N�^
	 */
	CPlayerStateGraps(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	�f�X�g���N�^
	 */
	virtual ~CPlayerStateGraps(void);

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
	void toAttackRight(void);

	/**
	 * @desc	�������U����ԁi�P���ځj�ֈڍs
	 */
	void toAttackLeft(void);

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

protected:
	//�Q�Ƃ���v���C���[�L�����N�^�[
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//�Q�Ƃ���K�[���L�����N�^�[
	CGirlCharacter*		m_pGirl = NULL;
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
class CPlayerGraspIdleRightState :public CPlayerStateGraps
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
class CPlayerGraspIdleLeftState :public CPlayerStateGraps
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
class CPlayerGraspWalkRightState :public CPlayerStateGraps
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
class CPlayerGraspWalkLeftState :public CPlayerStateGraps
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


//==========================================
//
// Class: CPlayerAttackRightState
//
// �v���C���[ �E�����@�U�� ��� �N���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerGrapsAttackRightState :public CPlayerStateGraps
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGrapsAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGrapsAttackRightState(void);

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
// Class: CPlayerAttackLeftState
//
// �v���C���[ �������@�U�� ��� �N���X
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerGrapsAttackLeftState :public CPlayerStateGraps
{
public:
	/**
	* @desc	�R���X�g���N�^
	*/
	CPlayerGrapsAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	�f�X�g���N�^
	*/
	~CPlayerGrapsAttackLeftState(void);

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
