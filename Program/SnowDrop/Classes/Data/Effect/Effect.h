#pragma once
/*
 * Effect.h
 *
 *	2016/11/25	Osumi
 *
 */

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//================================================
// �G�t�F�N�g�̊��N���X
//
//	2016/12/22
//									Author Harada
//================================================
class CEffect :public CCharacter {
public:
	//================================================
	// �K�{�֐��̗�
	//================================================
	//�R���X�g���N�^
	CEffect();

	//�f�X�g���N�^
	virtual ~CEffect();

	//����������
	virtual bool init()override;

	CREATE_FUNC(CEffect);

	//================================================ 
	// �L�����N�^�[�N���X�̃I�[�o�[���C�h������֐��Q
	//================================================
	//�ړ�����
	virtual void moveFunc()override;

	//�A�j���[�V��������
	virtual void animationFunc()override;

	//�Փ˔��菈��
	virtual void collisionAll()override;

	//��ԃ`�F�b�N
	virtual void checkState()override;

	//���f����
	virtual void applyFunc()override;

	/**
	 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	 * @param	�L�����N�^�[�̃A�h���X
	 * @return	true...�Փ˂���
	 */
	virtual bool collision(CCharacter* pChara)override;

	/**
	 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
	 * @param	�L�����N�^�[�̃A�h���X
	 */
	virtual void hits(CCharacter* pChara)override;

};