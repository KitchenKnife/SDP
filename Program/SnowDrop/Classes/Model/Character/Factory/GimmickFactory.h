#pragma once

//#pragmaonce//////////*+-----------------------------------------------------------------------------------------------------------------------------------------**++++++++++++++++++++-++++++++++++++++++++++++++++++++++++++++++++++++
#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//�v���C���[�N���X�̑O���錾
class CGimmickCharacter;

//================================================
// �M�~�b�N�p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CGimmickPartsFactory /*:public CCharacterPartsFactory*/ {
public:

	virtual ~CGimmickPartsFactory() {}

	std::vector<CAnimation* >* getAnimations();
	CMove* getMove();
	std::vector<CPhysical* >* getPhysicals();
	CBody* getBody();
	std::vector<CCollisionArea* >* getCollisionAreas();

};


//================================================
// �M�~�b�N�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CGimmickFactory {
public:

	virtual ~CGimmickFactory() {}

	//�M�~�b�N�̐����Ƒg�ݗ���
	//�h����ɂ���ĈႤ�M�~�b�N�̐���
	virtual CGimmickCharacter* createGimmick() = 0;

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CGimmickCharacter* pCharacter, cocos2d::Point pt) = 0;
	//�摜�̐ݒ�
	virtual void settingTexture(CGimmickCharacter* pCharacter) = 0;
	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CGimmickCharacter* pCharacter) = 0;
	//�K�p���镨���v�Z�̐ݒ�
	virtual void settingPhysicals(CGimmickCharacter* pCharacter) = 0;
	//�A�N�V�����̐ݒ�
	virtual void settingActions(CGimmickCharacter* pCharacter) = 0;
	//�Փ˔���f�[�^�̐ݒ�
	virtual void settingBody(CGimmickCharacter* pCharacter) = 0;
	//�Փ˔����Ԃ̐ݒ�
	virtual void settingColllisionArea(CGimmickCharacter* pCharacter) = 0;
	//�����ݒ�������
	virtual void settingInitialize(CGimmickCharacter* pCharacter) = 0;


	//�M�~�b�N�̐����ƃZ�b�e�B���O
	CGimmickCharacter* create(cocos2d::Point pt) {

		//�M�~�b�N�̐����Ƒg�ݗ���
		CGimmickCharacter* pCharacter = this->createGimmick();

		//�����ʒu�̐ݒ�
		this->settingMove(pCharacter, pt);
		//�e�N�X�`���̐ݒ�
		this->settingTexture(pCharacter);
		//�A�j���[�V�����̐ݒ�
		this->settingAnimations(pCharacter);
		//�K�p���镨���v�Z�̐ݒ�
		this->settingPhysicals(pCharacter);
		//�A�N�V�����̐ݒ�
		this->settingActions(pCharacter);
		//�Փ˔���p�f�[�^�̐ݒ�
		this->settingBody(pCharacter);
		//�Փ˔����Ԃ̐ݒ�
		this->settingColllisionArea(pCharacter);
		//�������������
		this->settingInitialize(pCharacter);//(pCharacter, vec)

		return pCharacter;
	}

};

//================================================
// �M�~�b�N�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CGimmickCreateFactory :public CGimmickFactory {
public:

	//�f�X�g���N�^
	virtual ~CGimmickCreateFactory() {}

	//�M�~�b�N�̐����Ƒg�ݗ���
	CGimmickCharacter* createGimmick()override;

};

//================================================
// �_���[�W�u���b�N�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CDamageBlockFactory :public CGimmickCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CGimmickCharacter* pCharacter, cocos2d::Point pt)override;
	//�摜�̐ݒ�
	void settingTexture(CGimmickCharacter* pCharacter)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CGimmickCharacter* pCharacter)override;
	//�K�p���镨���v�Z�̐ݒ�
	void settingPhysicals(CGimmickCharacter* pCharacter)override;
	//�A�N�V�����̐ݒ�
	void settingActions(CGimmickCharacter* pCharacter)override;
	//�Փ˔���f�[�^�̐ݒ�
	void settingBody(CGimmickCharacter* pCharacter)override;
	//�Փ˔����Ԃ̐ݒ�
	void settingColllisionArea(CGimmickCharacter* pCharacter)override;

	//�����ݒ�������
	void settingInitialize(CGimmickCharacter* pCharacter)override;

};


//================================================
// �p�[�c�Z�b�e�B���O�N���X�iCBasePlayerFactory�j���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
class CGimmickFactoryManager {
private:
	//�R���X�g���N�^
	CGimmickFactoryManager() {
		// �M�~�b�N�H��
		m_factories.push_back(new CDamageBlockFactory());

	}

	//���L�̃C���X�^���X
	static CGimmickFactoryManager* m_pGimmickFactoryManager;

public:
	//�f�X�g���N�^
	~CGimmickFactoryManager() {
		SAFE_DELETE(m_pGimmickFactoryManager);

		for (CGimmickFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}

	//�C���X�^���X�̎擾
	static CGimmickFactoryManager* getInstance();


	std::vector<CGimmickFactory*> m_factories;

	/**
	* @desc �M�~�b�N�H���create()���Ăяo��
	* @param �e�̃^�C�v
	* @param �e�̔��ˈʒu
	*/
	CGimmickCharacter* create(int type, cocos2d::Point Pt) {

		return this->m_factories[type]->create(Pt);
	}

};


