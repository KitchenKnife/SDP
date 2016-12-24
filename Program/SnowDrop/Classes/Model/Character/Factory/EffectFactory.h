#pragma once
#include "Data/Effect/Effect.h"

//================================================
// �G�t�F�N�g�p�[�c�����H��
//	�iAbstractFactory�j
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectPaartsFactory :public CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CEffectPaartsFactory() {}

	//�A�j���[�V�����Q�f�[�^�̐����Ǝ擾
	virtual std::vector<CAnimation*>* getAnimations()override;
	//�ړ��f�[�^�̐����Ǝ擾
	virtual CMove* getMove()override;
	//�������Z�Q�f�[�^�̐����Ǝ擾
	virtual std::vector<CPhysical*>* getPhysicals()override;
	//�A�N�V�����Q�f�[�^�̐����Ǝ擾
	virtual std::vector<CAction*>* getActions()override;
	//���̃f�[�^�̐����Ǝ擾
	virtual CBody* getBody()override;
	//�Փ˔����ԌQ�f�[�^�̐����Ǝ擾
	virtual std::vector<CCollisionArea*>* getCollisionAreas()override;
};


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectFactory {
public:
	//�f�X�g���N�^
	virtual ~CEffectFactory() {}

	//�G�t�F�N�g�̐����Ƒg�ݗ���
	virtual CEffect* createPlayer() = 0;

	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CEffect* pChara, cocos2d::Point pos) = 0;

	//�摜�̐ݒ�
	virtual void settingTexture(CEffect* pChara) = 0;

	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CEffect* pChara) = 0;

	//�K�p���镨���v�Z�̐ݒ�
	virtual void settingPhysicals(CEffect* pChara) = 0;

	//�A�N�V�����̐ݒ�
	virtual void settingActions(CEffect* pChara) = 0;

	//���̃f�[�^�̐ݒ�
	virtual void settingBody(CEffect* pChara) = 0;

	//�Փ˔�����
	virtual void settingCollisionArea(CEffect* pChara) = 0;

	//���̑��F�����ݒ�
	virtual void settingInitialize(CEffect* pChara) = 0;


	//�G�t�F�N�g�̐����Ɛݒ�
	CEffect* create(cocos2d::Point pos);
};

//================================================
// ���N�L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectCreateFactory :public CEffectFactory {
public:
	//�f�X�g���N�^
	virtual ~CEffectCreateFactory() {}

	//�G�t�F�N�g�̐����Ƒg�ݗ���
	CEffect* createPlayer()override;

};

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//
//	2016/12/23
//									Author Harada
//================================================
class CBaseEffectFactory :public CEffectCreateFactory {
public:
	//�f�X�g���N�^
	~CBaseEffectFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEffect* pChara, cocos2d::Point pos)override;
	//�摜�̐ݒ�
	void settingTexture(CEffect* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEffect* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEffect* pChara)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEffect* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEffect* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEffect* pChara)override;

	//���̑������ݒ�
	void settingInitialize(CEffect* pCharacter)override;

};

//================================================
// ���N�L�����N�^�[�����H����Ǘ�����N���X
//	�iSingleton�j
//
//	2016/12/23
//									Author Harada
//================================================
class CEffectFactoryManager {
private:
	//�R���X�g���N�^
	CEffectFactoryManager() {
		//��{�G�t�F�N�g�̐����H��𐶐����Ď��t����
		m_factories.push_back(new CBaseEffectFactory());
	}

	//���L�C���X�^���X
	static CEffectFactoryManager* m_pEffectFactoryManager;

public:
	//�f�X�g���N�^
	~CEffectFactoryManager() {
		//���L�C���X�^���X�̍폜
		SAFE_DELETE(m_pEffectFactoryManager);

		//�G�t�F�N�g�H��Q�̍폜
		for (CEffectFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//���L�C���X�^���X�̎擾
	static CEffectFactoryManager* getInstance();

	//�G�t�F�N�g�H��Q
	std::vector<CEffectFactory*> m_factories;


	/**
	 * @desc	�G�t�F�N�g�̐���
	 * @param	�o��������ʒu
	 * @param	�G�t�F�N�g�^�C�v
	 * @return	���������G�t�F�N�g�i�L�����N�^�[�j
	 */
	CEffect* create(cocos2d::Point pos, EFFECT_TYPE type) {
		//�G�t�F�N�g�^�C�v�� int �^�ɃL���X�g���đΉ�����H���create���Ăяo���A�G�t�F�N�g�𐶐�����B
		return this->m_factories[(int)type]->create(pos);
	}

};

