/*
* EnemyActionController.h
*
*	2016/11/07	Yamasaki
*
*/


#pragma once

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"Data/ActionController/ActionController.h"

//class CCharacter;

//===================================================================
// �Ō��U��
//		�Ō��U���Ɋւ��鏈�����s�����������Ƃ��Ăg�o�f�[�^�ɑ΂��ĕύX��������
//===================================================================
class CEnemyAction :public CAction {


public:
	//�R���X�g���N�^
	CEnemyAction() {}

	/*
	* @desc �J�n
	*/
	virtual void start()override {
		CCLOG("this function is brank!!!!");
	};

	/*
	* @desc �J�n
	* @param	�U�������L�����N�^�[�̃X�e�[�^�X
	*/
	virtual void start(CStatus* pStatus , CCharacter* pChara =NULL ) = 0;

	/*
	* @desc �I��
	*/
	//void stop()override;



	// �t���O�̎擾
	//virtual bool getActionFlag() = 0;
};

//===================================================================
// �Ō��U��
//		�Ō��U���Ɋւ��鏈�����s�����������Ƃ��Ăg�o�f�[�^�ɑ΂��ĕύX��������
//===================================================================
class CActionBlowAttack :public CEnemyAction {
protected:

	//�U�����Đ�����K��t���[����
	int m_frame = 180;

	//���݂̃t���[��
	int m_currentFrame = 0;

	//�Ō��U�������ǂ����̃t���O	true...�Ō��U����
	bool m_isBlowAttacking = false;

	//�Ō��U���J�n�t���O
	bool m_isBlowAttackStart = false;

	// �U�������L�����N�^�[�̃X�e�[�^�X��ۊǂ���
	CStatus* m_pStatus;

	// �U������L�����N�^�[�̃A�h���X
	CCharacter* m_pChara;

public:

	

	//�R���X�g���N�^
	CActionBlowAttack() {}

	/*
	* @desc �Ō��U��
	* @param �U����
	* @param �U�������L�����̃X�e�[�^�X
	*/
	void blowHit(int attackPt, CStatus* pStatus) {

		// HP��������
		pStatus->decreaseHP(attackPt);

	}

	//void start()override{};
	/*
	* @desc �J�n
	* @param	�U�������L�����N�^�[�̃X�e�[�^�X
	*/
	void start(CStatus* pStatus, CCharacter* pChara = NULL)override{

		//�W�����v�J�n
		this->m_isBlowAttackStart = true;

		// �X�e�[�^�X�ۊ�
		this->m_pStatus = pStatus;

		// �U���͂�ۊ�
		this->m_pChara = pChara;

	}
	

	/*
	* @desc �X�V����
	* @param �U�����s���L�����N�^�[�̃A�h���X
	* @param �U�������L�����N�^�[�̃X�e�[�^�X
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I��
	*/
	void stop()override {

		//�W�����v���t���O������
		this->m_isBlowAttacking = false;
	}



	// �t���O�̎擾
	bool getActionFlag() override{
		return this->m_isBlowAttacking;
	}
};
