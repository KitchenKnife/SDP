#pragma once

/*
* PlayerWeaponActionController.h
*
*	2016/11/27	Osumi
*
*/

#include "Data/ActionController/ActionController.h"
/*
class CPlayerWeapon;
class CPlayerBoy;
//class CPlayerCharacter;

//===================================================================
//
//	����U���̒��ۃN���X
//�@�@�v���C���[�̓������S��
//
//===================================================================

class CPlayerWeaponAttack :public CAction {
public:

	//�R���X�g���N�^
	CPlayerWeaponAttack();

	//���N�̃C���X�^���X
	CPlayerBoy* m_pBoy = NULL;// = NULL;

	//����̃C���X�^���X
	CPlayerWeapon* m_pWeapon = NULL;// = NULL;

	//���͎�t����
	//int m_delayTime = 50;

	//���͎�t�J�E���^�[
	int m_delayCounter = 0;

	//���̃A�N�V�����Ɉڍs���邩�ǂ����̃t���O
	bool m_nextActionFlag = false;

	//�P�̃A�N�V�������I��������ǂ��� true...�I����Ă�
	//bool m_isAttackEnd = false;

	virtual ~CPlayerWeaponAttack() {}
	//�A�N�V�������J�n���邽�тɌĂяo��
	void start()override {};
	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) {};
	//�A�N�V�������I�����邽�тɌĂяo��
	virtual void stop() override {};

};


class CPlayerNoneWeaponAction :public CPlayerWeaponAttack {
public:

	virtual ~CPlayerNoneWeaponAction() {}
	//�A�N�V�������J�n���邽�тɌĂяo��
	void start()override {};
	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) override {};
	//�A�N�V�������I�����邽�тɌĂяo��
	virtual void stop() override {};

};

//===================================================================
//	�a���A�N�V�����Q01	
//===================================================================
class CNormalSlashAttack_01 :public CPlayerWeaponAttack {
protected:

	//�����
	int m_attackVec = 0;

	//�����グ�i�K
	//  0...�a���@1-1
	//�@1...�a���@1-2
	//�@2...�a���@1-3

	int m_attackStep = 0;

	//���͎�t����
	const int m_delayTime = 20;

public:
	

	//�R���X�g���N�^
	CNormalSlashAttack_01() {}

	/*
	* @desc �J�n����
	*
	void start()override;

	/*
	* @desc �X�V�����i�W�����v�ړ��v�Z�j
	* @param �Ώۂ̃L�����N�^�[
	*
	void update(CCharacter* pChara)override;

	/*
	* @desc �I������
	*
	void stop()override;

};




*/