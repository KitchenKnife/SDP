/*
* PlayerFactory.h
*
*	2016/11/24	Osumi
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
//#include "Character.h"
#include "PlayerCharacter.h"

class CPlayerWeapon;
class CCollisionArea;
//�N���X�̑O���錾

//================================================
// �L�����N�^�[�p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CPlayerPartsFactory /*:public CCharacterPartsFactory*/ {
public:

	virtual ~CPlayerPartsFactory() {}

	//virtual std::vector<CAnimation* >* getAnimations()override;
	virtual CMove* getMove();//override;
	virtual std::vector<CPhysical* >* getPhysicals();//override;
	//virtual std::vector<CAction* >* getActions()override;
	virtual CBody* getBody();//override;
	std::vector<CCollisionArea* >* getCollisionAreas();

	virtual std::map<CPlayerCharacter::STATE, CAnimation*> getMapAnimations();
	virtual std::map<CPlayerCharacter::ACTION, CAction*> getMapActions();
	virtual std::vector<CPlayerEffect*>* getEffects();
	virtual CPlayerWeapon* getWeapon();

	virtual CStatus* getStatus();
	
};


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerFactory  {
public:

	//�p�[�c�����H��Q
	std::vector<CPlayerPartsFactory*>partsFactories{
		new CPlayerPartsFactory(),
		new CPlayerPartsFactory(),
	};

	~CPlayerFactory() {
		//�p�[�c�����H��Q�̉��
		for (CPlayerPartsFactory* pPartsfactory: partsFactories) {
			SAFE_DELETE(pPartsfactory);
		}
	}

	//�v���C���[�̐����Ƒg�ݗ���
	//�h����ɂ���ĈႤ�v���C���[�̐���
	virtual CPlayerCharacter* createPlayer() = 0;

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CPlayerCharacter* pCharacter) = 0;

	//�摜�̐ݒ�
	virtual void settingTexture(CPlayerCharacter* pCharacter) = 0;

	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CPlayerCharacter* pCharacter) = 0;

	//�K�p���镨���v�Z�̐ݒ�
	virtual void settingPhysicals(CPlayerCharacter* pCharacter) = 0;

	//�A�N�V�����̐ݒ�
	virtual void settingActions(CPlayerCharacter* pCharacter) = 0;

	//�Փ˔���f�[�^�̐ݒ�
	virtual void settingBody(CPlayerCharacter* pCharacter) = 0;
	//�Փ˔�����
	virtual void settingCollisionArea(CPlayerCharacter* pCharacter) = 0;

	//�X�e�[�^�X�̐ݒ�
	virtual void settingStatus(CPlayerCharacter* pCharacter) = 0;

	//�G�t�F�N�g�̐ݒ�
	virtual void settingEffects(CPlayerCharacter* pCharacter) = 0;

	//����̐ݒ�
	virtual void settingWeapon(CPlayerCharacter* pCharacter) = 0;


	//�����ݒ�������
	virtual void settingInitialize(CPlayerCharacter* pCharacter) = 0;

	
	//�v���C���[�̐����ƃZ�b�e�B���O
	CPlayerCharacter* create() {

		//�v���C���[�̐����Ƒg�ݗ���
		CPlayerCharacter* pCharacter = this->createPlayer();

		//�����ʒu�̐ݒ�
		this->settingMove(pCharacter);
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
		//�Փ˔�����
		this->settingCollisionArea(pCharacter);
		//�G�t�F�N�g�̐ݒ�
		this->settingEffects(pCharacter);
		//�X�e�[�^�X�̐ݒ�
		this->settingStatus(pCharacter);
		//����̐ݒ�
		this->settingWeapon(pCharacter);

		//�������������
		this->settingInitialize(pCharacter);
		

		return pCharacter;
	}

};

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerBoyCreateFactory :public CPlayerFactory {
public:

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerCharacter* createPlayer()override;

};

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerBoyFactory :public CPlayerBoyCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CPlayerCharacter* pCharacter)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerCharacter* pCharacter)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CPlayerCharacter* pCharacter)override;
	//�K�p���镨���v�Z�̐ݒ�
	void settingPhysicals(CPlayerCharacter* pCharacter)override;
	//�A�N�V�����̐ݒ�
	void settingActions(CPlayerCharacter* pCharacter)override;
	//�Փ˔���f�[�^�̐ݒ�
	void settingBody(CPlayerCharacter* pCharacter)override;
	//�Փ˔�����
	void settingCollisionArea(CPlayerCharacter* pCharacter)override;
	//�X�e�[�^�X�̐ݒ�
	void settingStatus(CPlayerCharacter* pCharacter)override;
	//�G�t�F�N�g�̐ݒ�
	void settingEffects(CPlayerCharacter* pCharacter)override;
	//����̐ݒ�
	void settingWeapon(CPlayerCharacter* pCharacter)override;

	//�����ݒ�������
	void settingInitialize(CPlayerCharacter* pCharacter)override;

};

//================================================
// ���̎q�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerGirlCreateFactory :public CPlayerFactory {
public:

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerCharacter* createPlayer()override;

};

//================================================
// ���̎q�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CPlayerGirlFactory :public CPlayerGirlCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CPlayerCharacter* pCharacter)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerCharacter* pCharacter)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CPlayerCharacter* pCharacter)override;
	//�K�p���镨���v�Z�̐ݒ�
	void settingPhysicals(CPlayerCharacter* pCharacter)override;
	//�A�N�V�����̐ݒ�
	void settingActions(CPlayerCharacter* pCharacter)override;
	//�Փ˔���f�[�^�̐ݒ�
	void settingBody(CPlayerCharacter* pCharacter)override;
	//�Փ˔�����
	void settingCollisionArea(CPlayerCharacter* pCharacter)override;
	//�X�e�[�^�X�̐ݒ�
	void settingStatus(CPlayerCharacter* pCharacter)override;
	//�G�t�F�N�g�̐ݒ�
	void settingEffects(CPlayerCharacter* pCharacter)override;
	//����̐ݒ�
	void settingWeapon(CPlayerCharacter* pCharacter)override;

	//�����ݒ�������
	void settingInitialize(CPlayerCharacter* pCharacter)override;

};

//================================================
// �p�[�c�Z�b�e�B���O�N���X�iCBasePlayerFactory�j���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//�v���C���[�̎��
enum PLAYER_TYPE :int {
	NONE = -1,
	BOY = 0,
	GIRL = 1,
};

class CPlayerFactoryManager {
private:
	//�R���X�g���N�^
	CPlayerFactoryManager(){
		// �v���C���[��{�H��
		m_factories.push_back(new CPlayerBoyFactory() );
		m_factories.push_back(new CPlayerGirlFactory());
	}

	//���L�̃C���X�^���X
	static CPlayerFactoryManager* m_pPlayerFactoryManager;
	
public:
	//�f�X�g���N�^
	~CPlayerFactoryManager() {
		SAFE_DELETE(m_pPlayerFactoryManager);

		for (CPlayerFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//�C���X�^���X�̎擾
	static CPlayerFactoryManager* getInstance();

	//�v���C���[�H��Q
	std::vector<CPlayerFactory*> m_factories;
	

	//�v���C���[�H���create()���Ăяo��
	CPlayerCharacter* create( int type ) {

		//CPlayerCharacter* pPlayer = this->pPlayerFactory->create();
		//return pPlayer;

		return this->m_factories[type]->create();
	}

};

