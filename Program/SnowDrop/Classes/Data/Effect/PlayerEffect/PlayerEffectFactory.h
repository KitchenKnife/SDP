#pragma once
/*
* PlayerEffectFactory.h
*
*	2016/11/25	Osumi
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Data/Effect/PlayerEffect/PlayerEffect.h"

//�N���X�̑O���錾

//================================================
// �G�b�t�F�N�g�p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CPlayerEffactPartsFactory /*:public CCharacterPartsFactory*/ {
public:

	virtual ~CPlayerEffactPartsFactory() {}
	virtual CMove* getMove();//override;
	//std::vector<CAnimation*> getMapAnimations();
	//CAnimation* getAnimation();
};


//================================================
// �G�t�F�N�g�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerEffectFactory {
public:

	//�p�[�c�����H��Q
	std::vector<CPlayerEffactPartsFactory*>partsFactories{
		new CPlayerEffactPartsFactory(),
		new CPlayerEffactPartsFactory(),
	};

	~CPlayerEffectFactory() {
		//�p�[�c�����H��Q�̉��
		for (CPlayerEffactPartsFactory* pPartsfactory : partsFactories) {
			SAFE_DELETE(pPartsfactory);
		}
	}

	//�v���C���[�̐����Ƒg�ݗ���
	//�h����ɂ���ĈႤ�v���C���[�̐���
	virtual CPlayerEffect* createEffect() = 0;

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CPlayerEffect* pEffct, cocos2d::Point pt) = 0;
	//�摜�̐ݒ�
	virtual void settingTexture(CPlayerEffect* pEffct) = 0;
	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CPlayerEffect* pEffct) = 0;

	//�����ݒ�������
	virtual void settingInitialize(CPlayerEffect* pEffct) = 0;


	//�v���C���[�̐����ƃZ�b�e�B���O
	CPlayerEffect* create(cocos2d::Point pt) {

		//�v���C���[�̐����Ƒg�ݗ���
		CPlayerEffect* pCharacter = this->createEffect();

		//�����ʒu�̐ݒ�
		this->settingMove(pCharacter,pt);
		//�e�N�X�`���̐ݒ�
		this->settingTexture(pCharacter);
		//�A�j���[�V�����̐ݒ�
		this->settingAnimations(pCharacter);

		//�������������
		this->settingInitialize(pCharacter);


		return pCharacter;
	}

};

//================================================
// �G�t�F�N�g�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CDisappearEffectCreateFactory :public CPlayerEffectFactory {
public:

	//�G�t�F�N�g�̐����Ƒg�ݗ���
	virtual CPlayerEffect* createEffect()override;

};

//================================================
// �G�t�F�N�g�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CDisappearEffectFactory :public CDisappearEffectCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CPlayerEffect* pEffct, cocos2d::Point pt)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerEffect* pEffct)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CPlayerEffect* pEffct)override;

	//�����ݒ�������
	void settingInitialize(CPlayerEffect* pEffct)override;

};

/*
//================================================
// �G�t�F�N�g�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CDisappearEffectCreateFactory :public CPlayerEffectFactory {
public:

	//�G�t�F�N�g�̐����Ƒg�ݗ���
	virtual CPlayerEffect* createEffect()override;

};

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CDisappearEffectFactory :public CDisappearEffectCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CPlayerEffect* pEffct)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerEffect* pEffct)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CPlayerEffect* pEffct)override;

	//�����ݒ�������
	void settingInitialize(CPlayerEffect* pEffct)override;

};
*/

//================================================
// �p�[�c�Z�b�e�B���O�N���X�iCBasePlayerFactory�j���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================

class CPlayerEffectFactoryManager {
private:
	//�R���X�g���N�^
	CPlayerEffectFactoryManager() {
		// �v���C���[��{�H��
		m_factories.push_back(new CDisappearEffectFactory());
		m_factories.push_back(new CDisappearEffectFactory());
	}

	//���L�̃C���X�^���X
	static CPlayerEffectFactoryManager* m_pPlayerEffectFactoryManager;

public:
	//�f�X�g���N�^
	~CPlayerEffectFactoryManager() {
		SAFE_DELETE(m_pPlayerEffectFactoryManager);

		for (CPlayerEffectFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}

	//�C���X�^���X�̎擾
	static CPlayerEffectFactoryManager* getInstance();

	//�G�t�F�N�g�H��Q
	std::vector<CPlayerEffectFactory*> m_factories;

	//�G�t�F�N�g�H���create()���Ăяo��
	CPlayerEffect* create(int type,cocos2d::Point pt) {

		//CPlayerCharacter* pPlayer = this->pPlayerFactory->create();
		//return pPlayer;

		return this->m_factories[type]->create(pt);
	}

};

