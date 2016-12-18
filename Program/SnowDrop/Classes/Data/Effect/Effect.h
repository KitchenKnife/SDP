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
#include "Data/Animation/Animation.h"
#include "Data/Move/Move.h"

#include <stdio.h>

using namespace cocos2d;
//using namespace std;

//================================================
// 
// �G�t�F�N�g�̊��N���X
//
//================================================
class CEffect :public Sprite {
public:

	//�R���X�g���N�^
	CEffect(){}

	//�f�X�g���N�^
	virtual ~CEffect(){}

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update();

	//�A�j���[�V�����f�[�^
    CAnimation* m_pAnimationDatas = NULL;

	//�ړ��f�[�^
	CMove* m_pMove = NULL;

	//�L���t���O
	bool m_activeFlag = true;

	//���f����
	virtual void applyFunc();

protected:

	//�ړ�����
	virtual void moveFunc() = 0;

	//�A�j���[�V��������
	virtual void animationFunc();

	


	//================================================
	// 
	//�@�����܂łɃ����o�Ɋւ���R�[�h��ǉ�
	//		
	//================================================
};
