/*
 * EnemyCharacter.h
 *
 *	2016/11/11	Yamasaki 
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
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//================================================
class CEnemyCharacter :public CCharacter {
public:
	//�R���X�g���N�^
	CEnemyCharacter();

	//�f�X�g���N�^
	virtual ~CEnemyCharacter();

	//����������
	bool init()override;

	CREATE_FUNC(CEnemyCharacter);

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

	

	//��ȃ^�[�Q�b�g
	TARGET_TYPE m_targetType = TARGET_TYPE::NONE;

	//���݂̗D��U���Ώ�
	CCharacter* m_currentTarget = NULL;

	//�v���C���[�����m�A�ǐՂ���͈�
	float m_chaseRange = 0;

	//�U���͈�
	float m_attackRange = 0;

	//�U���Ԋu
	int m_attackInterval = 0;

};