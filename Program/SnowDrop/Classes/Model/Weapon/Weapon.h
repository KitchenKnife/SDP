
/*
* weapon.h
*
*	2016/11/26	Osumi
*
*/
#pragma once

#include "Model/Character/PlayerCharacter.h"
#include "cocos2d.h"

//================================================
//
//�@����̒��ۃN���X
//
//================================================
class CWeapon :public CCharacter {
public:

	//�R���X�g���N�^
	CWeapon();

	//�f�X�g���N�^
	virtual ~CWeapon();

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update();

	//�A�j���[�V�����f�[�^�Q
	//std::vector<CAnimation* >* m_pAnimations = NULL;

	//�s����A�N�V�����Q
	//std::vector<CAction* >* m_pActions = NULL;

	//�ړ��f�[�^
	//CMove* m_pMove = NULL;

	//���̂̊�_
	std::vector<cocos2d::Point*>* m_pBasePoints = NULL ;

	//���̃f�[�^�Q
	//std::vector<CBody* >* m_pBodies = NULL;
	//CBody* m_pBody = NULL;

	// �X�e�[�^�X
	//CStatus* m_pStatus = NULL;

	//�L���t���O
	//bool m_activeFlag = false;

protected:

	//�ړ�����
	//virtual void moveFunc() = 0;

	//�A�j���[�V��������
	//virtual void animationFunc() = 0;

	//��ԃ`�F�b�N
	//virtual void checkState() = 0;

	//���f����
	//virtual void applyFunc() = 0;

public:
	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	//virtual bool collision(CCharacter* pChara) = 0;

};