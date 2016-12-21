#pragma once

/*
* PlayerWeaponFactory.h
*
*	2016/11/27	Osumi
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
/*
//�N���X�̑O���錾

//================================================
// ����p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CPlayerWeaponPartsFactory /*:public CCharacterPartsFactory*{
public:

	virtual ~CPlayerWeaponPartsFactory() {}

	//virtual std::vector<CAnimation* >* getAnimations()override;
	virtual CMove* getMove();//override;
	//virtual std::vector<CAction* >* getActions()override;
	virtual CBody* getBody();//override;
	virtual std::vector<cocos2d::Point*>* getPoints();
	virtual std::map<CPlayerWeapon::ATTACK_ANIME, CAnimation*> getMapAnimations();
	virtual std::map<CPlayerWeapon::ATTACK_ACT, CPlayerWeaponAttack*> getMapActions();
	virtual CStatus* getStatus();
	virtual std::vector<CCollisionArea* >* getCollisionAreas();

};


//================================================
// ����̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerWeaponFactory {
public:

	//�p�[�c�����H��Q
	std::vector<CPlayerWeaponPartsFactory*>partsFactories{
		new CPlayerWeaponPartsFactory(),
		new CPlayerWeaponPartsFactory(),
	};

	~CPlayerWeaponFactory() {
		//�p�[�c�����H��Q�̉��
		for (CPlayerWeaponPartsFactory* pPartsfactory : partsFactories) {
			SAFE_DELETE(pPartsfactory);
		}
	}

	//�v���C���[�̐����Ƒg�ݗ���
	//�h����ɂ���ĈႤ�v���C���[�̐���
	virtual CPlayerWeapon* createWeapon() = 0;

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CPlayerWeapon* pWeapon) = 0;
	//�摜�̐ݒ�
	virtual void settingTexture(CPlayerWeapon* pWeapon) = 0;
	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CPlayerWeapon* pWeapon) = 0;
	//�A�N�V�����̐ݒ�
	virtual void settingActions(CPlayerWeapon* pWeapon) = 0;
	//�Փ˔���f�[�^�̐ݒ�
	virtual void settingBody(CPlayerWeapon* pWeapon) = 0;
	//�Փ˔���̊�_��ݒ�
	virtual void settingPoints(CPlayerWeapon* pWeapon) = 0;
	//�X�e�[�^�X�̐ݒ�
	virtual void settingStatus(CPlayerWeapon* pWeapon) = 0;


	//�����ݒ�������
	virtual void settingInitialize(CPlayerWeapon* pWeapon) = 0;


	//�v���C���[�̐����ƃZ�b�e�B���O
	CPlayerWeapon* create() {

		//�v���C���[�̐����Ƒg�ݗ���
		CPlayerWeapon* pWeapon = this->createWeapon();

		//�����ʒu�̐ݒ�
		this->settingMove(pWeapon);
		//�e�N�X�`���̐ݒ�
		this->settingTexture(pWeapon);
		//�A�j���[�V�����̐ݒ�
		this->settingAnimations(pWeapon);
		//�A�N�V�����̐ݒ�
		this->settingActions(pWeapon);
		//�Փ˔���p�f�[�^�̐ݒ�
		this->settingBody(pWeapon);
		//�Փ˔���̊�_��ݒ�
		this->settingPoints(pWeapon);
		//�X�e�[�^�X�̐ݒ�
		this->settingStatus(pWeapon);

		//�������������
		this->settingInitialize(pWeapon);


		return pWeapon;
	}

};

//================================================
// ����̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerNormalWeaponCreateFactory :public CPlayerWeaponFactory {
public:

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerWeapon* createWeapon()override;

};

//================================================
// ����̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerNormalWeaponFactory :public CPlayerNormalWeaponCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CPlayerWeapon* pWeapon)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerWeapon* pWeapon)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CPlayerWeapon* pWeapon)override;
	//�A�N�V�����̐ݒ�
	void settingActions(CPlayerWeapon* pWeapon)override;
	//�Փ˔���f�[�^�̐ݒ�
	void settingBody(CPlayerWeapon* pWeapon)override;
	//�Փ˔���̊�_��ݒ�
	void settingPoints(CPlayerWeapon* pWeapon)override;
	//�X�e�[�^�X�̐ݒ�
	void settingStatus(CPlayerWeapon* pWeapon)override;

	//�����ݒ�������
	void settingInitialize(CPlayerWeapon* pWeapon)override;

};

/*
//================================================
// ����̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerNormalWeaponCreateFactory :public CPlayerWeaponFactory {
public:

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerWeapon* createWeapon()override;

};

//================================================
// ����̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerNormalWeaponFactory :public CPlayerNormalWeaponCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CPlayerWeapon* pWeapon)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerWeapon* pWeapon)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CPlayerWeapon* pWeapon)override;
	//�A�N�V�����̐ݒ�
	void settingActions(CPlayerWeapon* pWeapon)override;
	//�Փ˔���f�[�^�̐ݒ�
	void settingBody(CPlayerWeapon* pWeapon)override;
	//�Փ˔���̊�_��ݒ�
	void settingPoints(CPlayerWeapon* pWeapon)override;
	//�X�e�[�^�X�̐ݒ�
	void settingStatus(CPlayerWeapon* pWeapon)override;

	//�����ݒ�������
	void settingInitialize(CPlayerWeapon* pWeapon)override;

};
*

//================================================
// �p�[�c�Z�b�e�B���O�N���X�iCBasePlayerFactory�j���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//����̎��
enum WEAPON_TYPE :int {
//	NONE = -1,
	NORMAL = 0,
	LARGE_SWORD = 1,
};

class CPlayerWeaponFactoryManager {
private:
	//�R���X�g���N�^
	CPlayerWeaponFactoryManager() {
		// �v���C���[��{�H��
		m_factories.push_back(new CPlayerNormalWeaponFactory());
		//m_factories.push_back(new CPlayerGirlFactory());
	}

	//���L�̃C���X�^���X
	static CPlayerWeaponFactoryManager* m_pPlayerWeaponFactoryManager;

public:
	//�f�X�g���N�^
	~CPlayerWeaponFactoryManager() {
		SAFE_DELETE(m_pPlayerWeaponFactoryManager);

		for (CPlayerWeaponFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//�C���X�^���X�̎擾
	static CPlayerWeaponFactoryManager* getInstance();

	//�v���C���[�H��Q
	std::vector<CPlayerWeaponFactory*> m_factories;



	//�v���C���[�H���create()���Ăяo��
	CPlayerWeapon* create(int type) {

		//CPlayerCharacter* pPlayer = this->pPlayerFactory->create();
		//return pPlayer;

		return this->m_factories[type]->create();
	}

};

*/
