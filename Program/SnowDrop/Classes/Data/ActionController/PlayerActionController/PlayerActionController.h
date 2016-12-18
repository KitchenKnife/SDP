#pragma once

/*
* PlayerActionController.h
*
*	2016/11/24	Osumi
*
*/


#include "Data/ActionController/ActionController.h"
//#include "Model/Character/PlayerCharacter.h"

class CPlayerBoy;
class CPlayerGirl;
class CPlayerCharacter;
//class CPlayerCharacter;

class CPlayerAction :public CAction {
public:
	virtual ~CPlayerAction() {}
	//�A�N�V�������J�n���邽�тɌĂяo��
	void start()override {};
	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) override {};
	//�A�N�V�������I�����邽�тɌĂяo��
	virtual void stop() override {};

};


class CPlayerNoneAction:public CPlayerAction {
public:
	virtual ~CPlayerNoneAction() {}
	//�A�N�V�������J�n���邽�тɌĂяo��
	void start()override {};
	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) override {};
	//�A�N�V�������I�����邽�тɌĂяo��
	virtual void stop() override {};

};

//===================================================================
//	�v���C���[�̎����グ�A�N�V����	
//===================================================================
class CPlayerLiftUpAction :public CPlayerAction {
protected:

	//�����̊�_
	float m_girlGoalPoint = 0;

	//�����グ�s�����̊����
	int m_liftVec = 0;

	//�����グ�i�K
	//  0...���N���Ⴊ��
	//�@1...���������グ
	//�@2...���������~�@m_pauseTime�@�Ɉˑ�
	//�@...�}�b�v�`�b�v�̉����悤�ɉ~�^���i�����j�����ɓ����i���N�j
	//  3...�I��
	int m_LiftStep = 0;

	//��~����
	int m_pauseTimeCounter = 0;

	//���Ⴊ�݂ɂ�����R�}��
	int m_crouchFrame = 3;

	//���Ⴊ�ݒ����ǂ����̃t���O	true...���Ⴊ�ݒ�
	//bool m_isCrouching = false;

	//�����グ�J�n�t���O
	//bool m_isLiftUpStart = false;

public:
	//�R���X�g���N�^
	CPlayerLiftUpAction() {}
	CPlayerLiftUpAction(int crouchFrame) :
		 m_crouchFrame(crouchFrame){}

	/*
	* @desc ����
	* @param �����x
	* @tips �W�����v�{�^���������ꂽ�ۂɒl�̐ݒ�Ƌ��ɌĂяo��
	*/
	void start()override;

	/*
	* @desc �X�V�����i�W�����v�ړ��v�Z�j
	* @param �Ώۂ̃L�����N�^�[
	* @tips �֐����Ăяo��
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I��
	* @tips �����グ�I��������Ɋ֐����Ăяo��
	*/
	void stop()override;

};


//===================================================================
//
//	�����̉ɂԂ��A�N�V�����̔h����
//
//===================================================================
class CGirlBaseWasteTimeAction :public CPlayerAction {
protected:

	//�ɂԂ��A�N�V�����̐�
	const int m_actions = 2;

public:
	//�R���X�g���N�^
	CGirlBaseWasteTimeAction() {}

	/*
	* @desc �ɂԂ��J�n����
	* @tips �ɂԂ����Ԃ�������x�o�߂�����ɌĂяo��
	*/
	void start()override;

	/*
	* @desc �X�V�����i�W�����v�ړ��v�Z�j
	* @param �Ώۂ̃L�����N�^�[
	* @tips �֐����Ăяo��
	*/
	void update(CCharacter* pChara);

	//�ɂԂ��s���̎}������
	void branchWasteAction();

	/*
	* @desc�@�I��
	* @tips�@���n�����ۂɂ��̊֐����Ăяo��
	*/
	void stop()override;

};
//===================================================================
//
//	�����̉ɂԂ��A�N�V����_00�@���N���X
//
//===================================================================
class CGirlWasteBaseAction :public CPlayerAction {
protected:

public:
	//�R���X�g���N�^
	CGirlWasteBaseAction();
	//CGirlWasteBaseAction(CPlayerCharacter::STATE state);

	int m_actionTime;

	//�����̃C���X�^���X
	CPlayerGirl* m_pGirl = NULL;

	//���̃A�N�V�����N���X�̃X�e�C�g�^�C�v
	//CPlayerCharacter::STATE m_stateType = CPlayerCharacter::STATE::NONE;

	/*
	* @desc �ɂԂ�����
	*/
	void start()override;

	/*
	* @desc�@�I��
	*/
	void stop()override;

};
//===================================================================
//	�����̉ɂԂ��A�N�V����_01
//  �㉺�ɗh���
//===================================================================
class CGirlWasteAction_01 :public CGirlWasteBaseAction {
protected:

	//���̃A�N�V�����N���X�̃X�e�C�g�^�C�v
	//CPlayerCharacter::STATE m_stateType = CPlayerCharacter::STATE::NONE;

public:
	//�R���X�g���N�^
	CGirlWasteAction_01();

	/*
	* @desc �ɂԂ�����
	*/
	void start()override;

	/*
	* @desc �X�V����
	*/
	void update(CCharacter* pChara);

};

//===================================================================
//	�����̉ɂԂ��A�N�V����_02
//�@���E�ɕ���
//===================================================================
class CGirlWasteAction_02 :public CGirlWasteBaseAction {
protected:

	//���̃A�N�V�����N���X�̃X�e�C�g�^�C�v
	//CPlayerCharacter::STATE m_stateType;

	//const int m_waitTime = 30;
	int m_waitCounter = 0;

	/*
	* 0.�ړ���������̐ݒ�
	* 1.�����ɉ����Ĉړ�
	* 2.�����~�܂�
	* 3.�����ɉ����Ĉړ�
	*/
	int m_actionStep = 0;
	
	int m_vec = 1;

public:
	//�R���X�g���N�^
	CGirlWasteAction_02();

	/*
	* @desc �ɂԂ�����
	*/
	void start()override;

	/*
	* @desc �X�V����
	*/
	void update(CCharacter* pChara);

};
