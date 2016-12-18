#pragma once

#include "Data/Effect/Effect.h"

class CPlayerCharacter;

//==========================================
//
//  �v���C���[�̃G�t�F�N�g�̊��N���X
//
//==========================================

class CPlayerEffect :public CEffect {

public:

	//�R���X�g���N�^
	CPlayerEffect() {}

	//�f�X�g���N�^
	virtual ~CPlayerEffect() {}

	//����������
	virtual bool init()override;

	//�G�t�F�N�g�̃��C���[�ւ̎��t��
	virtual void jointToLayer(cocos2d::Layer* pLayer) {
		pLayer->addChild(this);
	}

protected:

	//�ړ�����
	virtual void moveFunc()override {}

	//================================================
	// 
	//�@�����܂łɃ����o�Ɋւ���R�[�h��ǉ�
	//		
	//================================================
};

//==========================================
//
//  �����G�t�F�N�g�N���X
//
//==========================================
class CBoyDisappearEffect :public CPlayerEffect {
public:

	CREATE_FUNC(CBoyDisappearEffect);

	//�R���X�g���N�^
	CBoyDisappearEffect() {}

	//�f�X�g���N�^
	virtual ~CBoyDisappearEffect() {}

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update()override {

		//�A�j���[�V�������I����Ă���A�L���t���O��������
		if (this->m_pAnimationDatas->isEnd() == true) {
			this->m_activeFlag = false;
		}

		CEffect::update();
	}

protected:

	//�ړ�����
	virtual void moveFunc()override {
		//�ړ��v�Z
		this->m_pMove->moveBy();
	};

	//================================================
	// 
	//�@�����܂łɃ����o�Ɋւ���R�[�h��ǉ�
	//		
	//================================================
};

//==========================================
//
//  ���N�̃_���[�W�G�t�F�N�g�N���X
//
//==========================================
class CBoyDamageEffect :public CPlayerEffect {
public:

	CREATE_FUNC(CBoyDamageEffect);

	//�R���X�g���N�^
	CBoyDamageEffect() {}

	//�f�X�g���N�^
	virtual ~CBoyDamageEffect() {}

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update()override {

		CEffect::update();
	}

	//�A�j���[�V�����f�[�^
	//CAnimation* m_pAnimationDatas = NULL;
	//�ړ��f�[�^
	//CMove* m_pMove = NULL;
	//�L���t���O
	//bool m_activeFlag = false;

	//�G�t�F�N�g�̃��C���[�ւ̎��t��
	//void jointToLayer(cocos2d::Layer* pLayer);

protected:

	//�ړ�����
	virtual void moveFunc()override {
		//�ړ��v�Z
		this->m_pMove->moveBy();
	};

	//�A�j���[�V��������
	//virtual void animationFunc()override {}
	//���f����
	//virtual void applyFunc()override {}

	//================================================
	// 
	//�@�����܂łɃ����o�Ɋւ���R�[�h��ǉ�
	//		
	//================================================
};