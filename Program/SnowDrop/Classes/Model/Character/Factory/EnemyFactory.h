/*
 * EnemyFactory.h
 *
 *	2016/12/21	Yamasaki And Harada
 *	
 */

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"
#include <map>

//================================================
// �L�����N�^�[�p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CEnemeyPartsFactory :public CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CEnemeyPartsFactory();

	//�A�j���[�V�����Q�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CAnimation* >* getAnimations()override;
	//�ړ��f�[�^�̎��̂𐶐����擾
	virtual CMove* getMove()override;
	//�������Z�Q�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CPhysical* >* getPhysicals()override;
	//�A�N�V�����Q�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CAction* >* getActions()override;
	//���̃f�[�^�̎��̂𐶐����擾
	virtual CBody* getBody()override;
	//�Փ˔����ԌQ�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CCollisionArea* >* getCollisionAreas()override;

};


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CEnemyFactory {
protected:

	//�G�̐����Ƒg�ݗ���
	virtual CEnemyCharacter* createEnemy() = 0;

	//�ړ��f�[�^�̐ݒ�
	virtual void settingMove(CEnemyCharacter* pChara ,float x,float y) = 0;
	//�摜�̐ݒ�
	virtual void settingTexture(CEnemyCharacter* pChara) = 0;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	virtual void settingAnimations(CEnemyCharacter* pChara) = 0;
	//�������Z�Q�f�[�^�̐ݒ�
	virtual void settingPhysicals(CEnemyCharacter* pChara) = 0;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	virtual void settingActions(CEnemyCharacter* pChara) = 0;
	//���̃f�[�^�̐ݒ�
	virtual void settingBody(CEnemyCharacter* pChara) = 0;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	virtual void settingCollisionArea(CEnemyCharacter* pChara) = 0;

	//���̑��@�����ݒ�
	virtual void settingInitialize(CEnemyCharacter* pChara) = 0;

public:
	//�f�X�g���N�^
	virtual ~CEnemyFactory() {};

	//�G�̐����ƃZ�b�e�B���O
	CEnemyCharacter* create(float posX,float posY) {

		//�G�̐����Ƒg�ݗ���
		CEnemyCharacter* pChara = this->createEnemy();

		//�ړ��f�[�^�ݒ�
		this->settingMove(pChara,posX,posY);
		//�摜�̐ݒ�
		this->settingTexture(pChara);
		//�A�j���[�V�����Q�f�[�^�̐ݒ�
		this->settingAnimations(pChara);
		//�������Z�Q�f�[�^�̐ݒ�
		this->settingPhysicals(pChara);
		//�A�N�V�����Q�f�[�^�̐ݒ�
		this->settingActions(pChara);
		//���̃f�[�^�̐ݒ�
		this->settingBody(pChara);
		//�Փ˔����ԌQ�f�[�^�̐ݒ�
		this->settingCollisionArea(pChara);
		//���̑�������
		this->settingInitialize(pChara);

		return pChara;
	}
};

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CEnemyCreateFactory :public CEnemyFactory {
public:
	//�f�X�g���N�^
	virtual ~CEnemyCreateFactory() {}

protected:
	//�G�̐����Ƒg�ݗ���
	virtual CEnemyCharacter* createEnemy()override {

		// �G����
		CEnemyCharacter* pEnemy = CEnemyCharacter::create();
		// �G�p�[�c�H�ꐶ��
		CEnemeyPartsFactory pEnemyPartsFactory;

		// �p�[�c�̐ݒ�
		pEnemy->m_pMove = pEnemyPartsFactory.getMove();
		pEnemy->m_pAnimations = pEnemyPartsFactory.getAnimations();
		
		pEnemy->m_pPhysicals = pEnemyPartsFactory.getPhysicals();
		pEnemy->m_pActions = pEnemyPartsFactory.getActions();
		pEnemy->m_pBody = pEnemyPartsFactory.getBody();
		pEnemy->m_pCollisionAreas = pEnemyPartsFactory.getCollisionAreas();

		//�@�G�Ԃ�
		return pEnemy;
	}
};

//================================================
// ���C�f�b�h�H��
//================================================
class CMaideadFactory :public CEnemyCreateFactory {
public:
	//�f�X�g���N�^
	virtual ~CMaideadFactory(){}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pChara)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};


//================================================
//�@�R�E�����H��
//================================================
class CBatFactory :public CEnemyCreateFactory {
public:
	//�f�X�g���N�^
	~CBatFactory(){}
	
	//�ړ��f�[�^�̐ݒ�
	void settingMove(CEnemyCharacter* pChara, float posX, float posY)override;
	//�摜�̐ݒ�
	void settingTexture(CEnemyCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CEnemyCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CEnemyCharacter* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CEnemyCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CEnemyCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CEnemyCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CEnemyCharacter* pChara)override;

};

//================================================
// �G�H��Q���Ǘ�����N���X
//	�iSingleton�j
//================================================
class CEnemyFactoryManager {
private:
	//�R���X�g���N�^
	CEnemyFactoryManager() {
		//���C�h�����H��𐶐��� [key : MAIDEAD] �Ɏ��t����
		m_factories[ENEMY_TYPE::MAIDEAD] = new CMaideadFactory();

		//�R�E���������H��𐶐��� [key : BAT] �Ɏ��t����
		m_factories[ENEMY_TYPE::BAT] = new CBatFactory();
	}

	//���L�̃C���X�^���X
	static CEnemyFactoryManager* m_pEnemyFactoryManager;

public:
	//�f�X�g���N�^
	~CEnemyFactoryManager() {
		//���L�C���X�^���X�̍폜
		SAFE_DELETE(m_pEnemyFactoryManager);

		//���t�����H��Q���폜
		std::map<ENEMY_TYPE, CEnemyFactory*>::iterator itr = m_factories.begin();
		while (itr != m_factories.end()) {
			//�N���X�̃C���X�^���X���폜
			SAFE_DELETE(itr->second);
			//�C�e���[�^�[���X�V
			itr++;
		}
	}


	//�C���X�^���X�̎擾
	static CEnemyFactoryManager* getInstance();

	//�G�H��Q
	std::map<ENEMY_TYPE, CEnemyFactory*> m_factories;

	/**
	 * @desc	�G�L�����N�^�[�𐶐�
	 * @param	�o��������ʒu
	 * @param	�G�̃^�C�v
	 * @return	���������G�L�����N�^�[
	 */
	CEnemyCharacter* create(Point pos, ENEMY_TYPE type) {
		//�G�̃^�C�v�� key �Ƃ��ēG�𐶐����ĕԂ�
		return this->m_factories[type]->create(pos.x, pos.y);
	}

};

