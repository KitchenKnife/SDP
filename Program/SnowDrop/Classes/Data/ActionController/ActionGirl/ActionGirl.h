#pragma once
//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "../Action.h"


//===================================================================
// �����̎�Ȃ��A�N�V����
//===================================================================
class CGirlActionGraspHand :public CAction {
protected:

	//�v���C���[�̃A�h���X
	CCharacter* m_pPlayerChara;
public:

	//�f�t�H���g�R���X�g���N�^
	CGirlActionGraspHand() {}
	//�R���X�g���N�^�i�e��ݒ�j
	CGirlActionGraspHand(CCharacter* pChara)
		:m_pPlayerChara(pChara) {}

	/*
	 * @desc	�A�N�V�����J�n
	 */
	void start()override {

	}


	/*
	 * @desc	�X�V����
	 * @param	�A�N�V��������Ώۂ̃L�����N�^�[�i�����j
	 */
	void update(CCharacter* pChara);

	/*
	 * @desc	�A�N�V�����I��
	 */
	void stop()override {

	}
};

//===================================================================
// �����̂��P�l�������A�N�V����
//===================================================================
class CGirlActionHoldThePrincess :public CAction {
protected:

	//�v���C���[�̃A�h���X
	CCharacter* m_pPlayerChara;
public:

	//�f�t�H���g�R���X�g���N�^
	CGirlActionHoldThePrincess() {}
	//�R���X�g���N�^�i�e��ݒ�j
	CGirlActionHoldThePrincess(CCharacter* pChara)
		:m_pPlayerChara(pChara) {}

	/*
	* @desc	�A�N�V�����J�n
	*/
	void start()override {

	}


	/*
	* @desc	�X�V����
	* @param	�A�N�V��������Ώۂ̃L�����N�^�[�i�����j
	*/
	void update(CCharacter* pChara);

	/*
	* @desc	�A�N�V�����I��
	*/
	void stop()override {

	}
};