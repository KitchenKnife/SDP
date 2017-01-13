/*
* DamageCharacter.h
*
*	2016/12/26	Yamasaki
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//=========================================================================
//	�_���[�W�̎��
//		�u���b�N�ԍ��Ɉˑ�
//=========================================================================
enum class DAMAGE_TYPE :int {
	NONE = 0,	//�����Ȃ�
	SMOKE = 1,	//��
	FALL_KNIFE = 2,	//
};


//================================================
// 
// �_���[�W�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//================================================
class CDamageCharacter :public CCharacter {
public:
	//�R���X�g���N�^
	CDamageCharacter();

	//�f�X�g���N�^
	virtual ~CDamageCharacter();

	//����������
	bool init()override;

	CREATE_FUNC(CDamageCharacter);

	//================================================
	//	�L�����N�^�[�N���X�̃I�[�o�[���C�h����֐��Q
	//================================================
	//�ړ�����
	void moveFunc() override;

	//�A�j���[�V��������
	void animationFunc()override;

	//�Փ˔��菈��
	void collisionAll()override;

	//��ԃ`�F�b�N
	void checkState() override;

	//���f����
	void applyFunc() override;

	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override;

	/**
	* @desc	���N���X����Փ˔�����󂯂��ۂ̏���
	* @param	�L�����N�^�[�̃A�h���X
	*/
	void hits(CCharacter* pChara)override;

	//�_���[�W�L�����N�^�[���o�����L�����N�^�[�N���X
	CCharacter* m_pChara = NULL;

	// �L���t���[����(���t���[�����݂��Ă�����)
	int m_activeFrame;
};