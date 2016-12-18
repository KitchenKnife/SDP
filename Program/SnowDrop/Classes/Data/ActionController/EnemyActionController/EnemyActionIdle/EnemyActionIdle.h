/*
* EnemyActionIdle.h
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
// �ҋ@�̊��N���X(�ǐ՗D�揇�ʂ͓G�ɍ��킹��)
//===================================================================
class CEnemyActionIdle :public CAction {
protected:
	//�Đ�����K��t���[����
	//(���[�v����̃A�j���[�V�����݂����Ƀt���[�����J��Ԃ�)
	int m_frame = 0;

	//���݂̃t���[��
	int m_currentFrame = 0;

	//�ҋ@�����ǂ����̃t���O	true...�ҋ@��
	bool m_isIdlering = false;

	//�ҋ@�J�n�t���O
	bool m_isIdleStart = false;

public:
	//�R���X�g���N�^
	CEnemyActionIdle() {}

	// �Đ��t���[���̐ݒ�
	void setFrame(int frame) { this->m_frame = frame; }

	/*
	* @desc �J�n
	*/
	void start()override {
		this->m_isIdleStart = true;
	}

	/*
	*	@desc�@�ҋ@
	*	@param �ҋ@����G�̃A�h���X
	*/
	virtual void Idle(CCharacter* pChara) = 0;


	/*
	* @desc �X�V����
	* @param �ҋ@���s���L�����N�^�[�̃A�h���X
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I��
	*/
	void stop()override {
		this->m_isIdlering = false;
	}

	// �t���O�̎擾
	bool getActionFlag() {
		return this->m_isIdlering;
	}
};


//===================================================================
// �ҋ@���A�j�����ړ����Ȃ��N���X
//===================================================================
class CActionIdleStop : public CEnemyActionIdle {

	/*
	*	@desc �A�j�����ړ����Ȃ��̑ҋ@
	*	@param �ҋ@����G�̃A�h���X
	*/
	void Idle(CCharacter* pChara) {

		// ���x��0�łȂ���Ώ���������
		if (pChara->m_pMove->m_vel.x != 0.0f) {

			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_vel.y = 0.0f;
		}
	}
};

//===================================================================
// �ҋ@�����낤�낷��N���X
//===================================================================
class CActionIdleMove : public CEnemyActionIdle {

	/*
	*	@desc�@�ړ� + �A�j��������ҋ@
	�@	*	@param �ҋ@����G�̃A�h���X
		*/
	void Idle(CCharacter* pChara);
};




//===================================================================
// �ҋ@���A�j���[�V������������N���X
//===================================================================
class CActionIdleAnimationOnly : public CEnemyActionIdle {

	/*
	*	@desc�@�A�j���[�V�����݂̂̑ҋ@
	*	@param �ҋ@����G�̃A�h���X
	*/
	void Idle(CCharacter* pChara);
};