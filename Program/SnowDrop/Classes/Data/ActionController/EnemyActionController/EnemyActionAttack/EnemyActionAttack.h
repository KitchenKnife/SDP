/*
* EnemyActionAttack.h
*
*	2016/11/07	Yamasaki
*
*/


#pragma once

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"Data/ActionController/ActionController.h"
#include "Model/Character/Factory/EnemyFactory.h"

//===================================================================
// �R�E�����p�@�A�N�V�����Ǘ��N���X
//===================================================================
class CBatActionManager : public CAction {
private:
	// �J�n
	bool m_isStart = false;

	bool m_inAction = false;


	virtual ~CBatActionManager() {}
	/*
	*	@desc �A�N�V�������J�n���邽�тɌĂяo��
	*	@param	�ύX�������X�e�[�^�X������ꍇ�Ɏg��
	*/
	virtual void start() {
		this->m_isStart = true;
	}

	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) {



	}
	//�A�N�V�������I�����邽�тɌĂяo��
	virtual void stop() {

	}

	// �A�N�V�����t���O�̎擾
	virtual bool getActionFlag() {

	}
};


//===================================================================
// �U��
//		�U���Ɋւ��鏈�����s��
//===================================================================
class CEnemyActionAttack :public CAction {
protected:

	//�U�����Đ�����K��t���[����
	int m_frame = 180;

	//���݂̃t���[��
	int m_currentFrame = 0;


	//�U�������ǂ����̃t���O	true...�U����
	bool m_isAttacking = false;

	//�U���J�n�t���O
	bool m_isAttackStart = false;

public:
	//�R���X�g���N�^
	CEnemyActionAttack() {}
	// �f�X�g���N�^
	~CEnemyActionAttack(){}

	// �t���[���ݒ�
	void setFrame(int frame) { this->m_frame = frame; }


	/*
	* @desc �J�n
	* @param	�U�������L�����N�^�[�̃X�e�[�^�X
	*/
	void start()override {

		//�J�n
		this->m_isAttackStart = true;

	}

	/*
	*	@desc �U�����@
	*	@param �U������L�����N�^�[
	*/
	virtual void attack(CCharacter* pChara) = 0;


	/*
	* @desc �X�V����
	* @param �U�����s���L�����N�^�[�̃A�h���X
	*/
	void update(CCharacter* pChara);



	/*
	* @desc �I��
	*/
	void stop()override {

		//�W�����v���t���O������
		this->m_isAttacking = false;
	}



	// �t���O�̎擾
	bool getActionFlag() {
		return this->m_isAttacking;
	}
};

//======================================
// �Ō�
//======================================
class CEnemyBrowAttack : public CEnemyActionAttack {

public:

	~CEnemyBrowAttack(){}


	void attack(CCharacter* pChara) {

		pChara->m_pStatus->decreaseHP(1);
	}
};

//======================================
// ������
//======================================
class CEnemyAttack : public CEnemyActionAttack {

public:
	~CEnemyAttack(){}


	void attack(CCharacter* pChara) {}
};

//======================================
// BOSS1 �r��
//======================================
class CEnemyBOSS1Attack : public CEnemyActionAttack {

public:

	~CEnemyBOSS1Attack(){}

	void attack(CCharacter* pChara);
};


//======================================
// BOSS1 �N�G�C�N
//======================================
class CEnemyBOSS1AttackQuake : public CEnemyActionAttack {

public:

	~CEnemyBOSS1AttackQuake(){}
	void attack(CCharacter* pChara);
};