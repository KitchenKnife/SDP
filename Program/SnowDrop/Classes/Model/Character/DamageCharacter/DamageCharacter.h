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

	//================================================
	//	�萔�Ɋւ���R�[�h�̒ǉ��͂�������
	//================================================
	//�G�̏��(�A�j���[�V����)
	enum class STATE :int {
		NONE = -1,
		STAND = 0,
		JUMPING = 0,
		WALK = 1,
		FALING = 2,
		ATTACK = 3,
		CHASE = 4,
		STAY = 5,
		WANDERING = 6,	//�R�E�����͏o���ʒu�Ɍ������A����ȊO�͂��܂悢�s��
		DAMAGE = 7,
		DIE = 8,
	};

	//�A�j���[�V�����̏��
	//int m_state = (int)STATE::NONE;

	//�G���s����A�N�V����
	enum class ACTION :int {
		ATTACK = 0,	//�U��
		PURSUIT = 1,	//
		IDLE = 2,	//
		DAMAGE = 3,	//
	};
};