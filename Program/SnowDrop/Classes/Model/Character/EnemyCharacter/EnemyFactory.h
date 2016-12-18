
/*
* EnemyFactory.h
*
*	2016/11/07	Yamasaki
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//�v���C���[�N���X�̑O���錾
class CEnemyCharacter;

//================================================
// �L�����N�^�[�p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CEnemeyPartsFactory :public CCharacterPartsFactory {
public:

	virtual ~CEnemeyPartsFactory() {}

	virtual std::vector<CAnimation* >* getAnimations()override;
	virtual CMove* getMove()override;
	virtual std::vector<CPhysical* >* getPhysicals()override;
	virtual std::vector<CAction* >* getActions()override;
	virtual CBody* getBody()override;
	virtual std::vector<CCollisionArea* >* getCollisionAreas()override;

	virtual CStatus* getStatus()override;

};


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CEnemyFactory {
public:

	//�p�[�c�����H��Q
	std::vector<CCharacterPartsFactory*>partsFactories{
		new CEnemeyPartsFactory(),
		new CEnemeyPartsFactory()
	};

	~CEnemyFactory() {
		//�p�[�c�����H��Q�̉��
		for (CCharacterPartsFactory* pPartsfactory : partsFactories) {
			SAFE_DELETE(pPartsfactory);
		}
	}

	//�G�̐����Ƒg�ݗ���
	//�h����ɂ���ĈႤ�v���C���[�̐���
	virtual CEnemyCharacter* createEnemy() = 0;

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CEnemyCharacter* pCharacter ,float x,float y) = 0;
	//�摜�̐ݒ�
	virtual void settingTexture(CEnemyCharacter* pCharacter) = 0;
	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CEnemyCharacter* pCharacter) = 0;
	//�K�p���镨���v�Z�̐ݒ�
	virtual void settingPhysicals(CEnemyCharacter* pCharacter) = 0;
	//�A�N�V�����̐ݒ�
	virtual void settingActions(CEnemyCharacter* pCharacter) = 0;
	//�Փ˔���f�[�^�̐ݒ�
	virtual void settingBody(CEnemyCharacter* pCharacter) = 0;
	//�Փ˔�����
	virtual void settingCollisionArea(CEnemyCharacter* pCharacter) = 0;
	//�X�e�[�^�X�̐ݒ�
	virtual void settingStatus(CEnemyCharacter* pCharacter) = 0;
	

	//�����ݒ�������
	virtual void settingInitialize(CEnemyCharacter* pCharacter) = 0;


	//�G�̐����ƃZ�b�e�B���O
	CEnemyCharacter* create(float posX,float posY) {

		//�G�̐����Ƒg�ݗ���
		CEnemyCharacter* pCharacter = this->createEnemy();

		//�����ʒu�̐ݒ�
		this->settingMove(pCharacter,posX,posY);
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
		//�X�e�[�^�X�̐ݒ�
		this->settingStatus(pCharacter);
		//�������������
		this->settingInitialize(pCharacter);

		return pCharacter;
	}

};

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CMaideadCreateFactory :public CEnemyFactory {
public:

	//�v���C���[�̐����Ƒg�ݗ���
	CEnemyCharacter* createEnemy()override;

};

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CBaseEnemyFactory :public CMaideadCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pCharacter , float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pCharacter)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	//�K�p���镨���v�Z�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����̐ݒ�
	void settingActions(CEnemyCharacter* pCharacter)override;
	//�Փ˔���f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pCharacter)override;
	//�Փ˔�����
	void settingCollisionArea(CEnemyCharacter* pCharacter)override;
	//�X�e�[�^�X�̐ݒ�
	void settingStatus(CEnemyCharacter* pCharacter)override;


	//�����ݒ�������
	void settingInitialize(CEnemyCharacter* pCharacter)override;

};
//================================================
// �p�^�p�^�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CFlyCreateFactory :public CEnemyFactory {
public:

	//�v���C���[�̐����Ƒg�ݗ���
	CEnemyCharacter* createEnemy()override;

};

//================================================
// �p�^�p�^�p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
class CFlyFactory :public CFlyCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��p�f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pCharacter , float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pCharacter)override;
	//�A�j���[�V�����̐ݒ�
	void settingAnimations(CEnemyCharacter* pCharacter)override;
	//�K�p���镨���v�Z�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����̐ݒ�
	void settingActions(CEnemyCharacter* pCharacter)override;
	//�Փ˔���f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pCharacter)override;
	//�Փ˔�����
	void settingCollisionArea(CEnemyCharacter* pCharacter)override;
	//�X�e�[�^�X�̐ݒ�
	void settingStatus(CEnemyCharacter* pCharacter)override;


	//�����ݒ�������
	void settingInitialize(CEnemyCharacter* pCharacter)override;

};

//================================================
// �p�[�c�Z�b�e�B���O�N���X�iCBaseEnemyFactory�j���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//�G�̎푰�^�C�v
enum ENEMY_RACE_TYPE :int{
	MAIDEAD = 0,			// ���C�h
	BAT		= 1,			// �R�E����
	MALICE	= 2,			// �}���X
};

class CEnemyFactoryManager {
private:
	//�R���X�g���N�^
	CEnemyFactoryManager() {
		// �v���C���[��{�H��
		//m_factories.push_back(new CBaseEnemyFactory());
		// �v���C���[��{�H��
		//m_factories.push_back(new CFlyFactory());

		m_factories[ENEMY_TYPE::KURIBO] = new CBaseEnemyFactory();
		m_factories[ENEMY_TYPE::MAIDEAD] = new CBaseEnemyFactory();
		m_factories[ENEMY_TYPE::BAT] = new CFlyFactory();
	}

	//���L�̃C���X�^���X
	static CEnemyFactoryManager* m_pEnemyFactoryManager;

public:
	//�f�X�g���N�^
	~CEnemyFactoryManager() {
		SAFE_DELETE(m_pEnemyFactoryManager);

		std::map<ENEMY_TYPE, CEnemyFactory*>::iterator itr = this->m_factories.begin();

		while (itr != this->m_factories.end()) {
			SAFE_DELETE(itr->second);
			itr++;
		}

		this->m_factories.clear();
	}


	//�C���X�^���X�̎擾
	static CEnemyFactoryManager* getInstance();

	//�v���C���[�H��Q
	std::map<ENEMY_TYPE, CEnemyFactory*> m_factories;


	//�v���C���[�H���create()���Ăяo��
	CEnemyCharacter* create(Point pos, int type) {

		//CEnemyCharacter* pEnemy = this->pEnemyFactory->create();
		//return pEnemy;


			return this->m_factories[(ENEMY_TYPE)type]->create(pos.x, pos.y);
	}

};

