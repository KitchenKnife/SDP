
/*
* PlayerCharacter.h
*
*	2016/11/24	Osumi
*
*/

#pragma once
//================================================
//�@�ǉ��̃C���N���[�h�͂�������
//================================================
#include "Model/Character/Character.h"


//================================================
//�@�O���錾
//================================================
class CPlayerCharacterGirl;

//================================================
// ���N�N���X
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerCharacterBoy :public CCharacter {
public:
	//================================================ 
	// �K�{�֐��̗�	
	//================================================
	//�R���X�g���N�^
	CPlayerCharacterBoy();

	//�f�X�g���N�^
	~CPlayerCharacterBoy();

	CREATE_FUNC(CPlayerCharacterBoy);

	//����������
	bool init()override;

	//================================================ 
	// �L�����N�^�[�N���X�̃I�[�o�[���C�h������֐��Q
	//================================================

	//�ړ�����
	virtual void moveFunc();

	//�A�j���[�V��������
	virtual void animationFunc();

	//�Փ˔��菈��
	virtual void collisionAll();

	//��ԃ`�F�b�N
	virtual void checkState();

	//���f����
	virtual void applyFunc();

	/**
	 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	 * @param	�L�����N�^�[�̃A�h���X
	 * @return	true...�Փ˂���
	 */
	virtual bool collision(CCharacter* pChara);

	/**
	 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
	 * @param	�L�����N�^�[�̃A�h���X
	 */
	virtual void hits(CCharacter* pChara);

	//================================================ 
	// CPlayerCharacterBoy�N���X��p�����o
	//================================================

	//�v���C���[��p�̃X�e�[�g�}�V�[���f�[�^�Q
	std::map<int, CStateMachine*>* m_pStateMachines = NULL;

	//�v���C���[�Ə����̏��
	int m_playerAndGirlState = 0;


private:
};