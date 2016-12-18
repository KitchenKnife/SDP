/*
* EnemyActionDamage.h
*
*	2016/11/22	Yamasaki
*
*/


#pragma once

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"Data/ActionController/ActionController.h"
#include"Model/Character/EnemyCharacter/EnemyCharacter.h"



//===================================================================
// �_���[�W���󂯂����̊��N���X(�ǐ՗D�揇�ʂ͓G�ɍ��킹��)
//===================================================================
class CEnemyActionDamage :public CAction {
protected:

	//�_���[�W�����ǂ����̃t���O	true...�ҋ@��
	bool m_isDamaging = false;

	//�_���[�W�J�n�t���O
	bool m_isDamageStart = false;

public:
	//�R���X�g���N�^
	CEnemyActionDamage() {}

	/*
	* @desc �J�n
	*/
	void start()override {
		this->m_isDamageStart = true;
	}

	/*
	*	@desc�@�_���[�W���󂯂�
	*	@param �_���[�W���󂯂�G�̃A�h���X
	*/
	virtual void Damage(CCharacter* pChara) = 0;


	/*
	* @desc �X�V����
	* @param �_���[�W���󂯂�G�̃A�h���X
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I��
	*/
	void stop()override {
		this->m_isDamaging = false;
	}

	// �t���O�̎擾
	bool getActionFlag() {
		return this->m_isDamaging;
	}
};

//===================================================================
// �_���[�W���󂯂Ē�~����N���X
//===================================================================
class CActionDamageStop : public CEnemyActionDamage {

	/*
	*	@desc�@�_���[�W���󂯂Ē�~����
	*	@param �_���[�W���󂯂�G�̃A�h���X
	*/
	void Damage(CCharacter* pChara);
};


//===================================================================
// �_���[�W���󂯂Čジ����N���X(���ɃY�T�[�I��)
//===================================================================
class CActionDamageBack : public CEnemyActionDamage {

	/*
	*	@desc �_���[�W���󂯂Čジ����
	*	@param �_���[�W���󂯂�G�̃A�h���X
	*/
	void Damage(CCharacter* pChara);
};

//===================================================================
// �_���[�W���A�j���[�V������������N���X�i�ړ�or�U���\�j
//===================================================================
class CActionDamageAnimationOnly : public CEnemyActionDamage {

	/*
	*	@desc�@�_���[�W���A�j���[�V�����̂�
	*	@param �_���[�W���󂯂�G�̃A�h���X
	*/
	void Damage(CCharacter* pChara);
};

//===================================================================
// �_���[�W���ω����Ȃ��N���X�i�ړ�or�U���\�j
//===================================================================
class CActionDamageNone : public CEnemyActionDamage {

	/*
	*	@desc�@�_���[�W���������ڂɕω����Ȃ�
	*	@param �_���[�W���󂯂�G�̃A�h���X
	*/
	void Damage(CCharacter* pChara);
};