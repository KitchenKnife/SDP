/*
* DamageFactory.h
*
*	2016/12/21	Yamasaki And Harada
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/DamageCharacter/DamageCharacter.h"
#include <map>

//================================================
// �L�����N�^�[�p�[�c�����H��
//	�iAbstractFactory�j
//================================================
class CDamagePartsFactory :public CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CDamagePartsFactory();

	//�A�j���[�V�����Q�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CAnimation* >* getAnimations()override;
	//�ړ��f�[�^�̎��̂𐶐����擾
	virtual CMove* getMove()override;
	//�������Z�Q�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CPhysical* >* getPhysicals()override;
	//���̃f�[�^�̎��̂𐶐����擾
	virtual CBody* getBody()override;
	//�Փ˔����ԌQ�f�[�^�̎��̂𐶐����擾
	virtual std::vector<CCollisionArea* >* getCollisionAreas()override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
	*	@return ��ԑJ�ڃf�[�^
	*	@author Shinya Ueba
	*/
	virtual	CStateMachine*	getStateMachine(void)override;


};


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
class CDamageFactory {
protected:

	//�G�̐����Ƒg�ݗ���
	virtual CDamageCharacter* createDamage() = 0;

	//�ړ��f�[�^�̐ݒ�
	virtual void settingMove(CDamageCharacter* pChara, float x, float y) = 0;
	//�摜�̐ݒ�
	virtual void settingTexture(CDamageCharacter* pChara) = 0;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	virtual void settingAnimations(CDamageCharacter* pChara) = 0;
	//�������Z�Q�f�[�^�̐ݒ�
	virtual void settingPhysicals(CDamageCharacter* pChara) = 0;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	virtual void settingActions(CDamageCharacter* pChara) = 0;
	//���̃f�[�^�̐ݒ�
	virtual void settingBody(CDamageCharacter* pChara) = 0;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	virtual void settingCollisionArea(CDamageCharacter* pChara) = 0;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CDamageCharacter* pChara) = 0;
	//���̑��@�����ݒ�
	virtual void settingInitialize(CDamageCharacter* pChara) = 0;

public:
	//�f�X�g���N�^
	virtual ~CDamageFactory() {};

	//�G�̐����ƃZ�b�e�B���O
	CDamageCharacter* create(float posX, float posY) {

		//�G�̐����Ƒg�ݗ���
		CDamageCharacter* pChara = this->createDamage();

		//�ړ��f�[�^�ݒ�
		this->settingMove(pChara, posX, posY);
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
		//��ԑJ�ڃ}�V���̐ݒ�
		this->settingStateMachine(pChara);
		//���̑�������
		this->settingInitialize(pChara);

		return pChara;
	}
};

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
template <class Ty>
class CDamageCreateFactory :public CDamageFactory {
public:
	//�f�X�g���N�^
	virtual ~CDamageCreateFactory() {}

protected:
	//�G�̐����Ƒg�ݗ���
	virtual CDamageCharacter* createDamage()override {

		// �G����
		CDamageCharacter* pDamage = Ty::create();
		// �G�p�[�c�H�ꐶ��
		CDamagePartsFactory pDamagePartsFactory;

		// �p�[�c�̐ݒ�
		pDamage->m_pMove = pDamagePartsFactory.getMove();
		pDamage->m_pAnimations = pDamagePartsFactory.getAnimations();

		pDamage->m_pPhysicals = pDamagePartsFactory.getPhysicals();
		pDamage->m_pBody = pDamagePartsFactory.getBody();
		pDamage->m_pCollisionAreas = pDamagePartsFactory.getCollisionAreas();

		//��ԃf�[�^�̐����Ǝ擾
		pDamage->m_pStateMachine = pDamagePartsFactory.getStateMachine();

		//�@�G�Ԃ�
		return pDamage;
	}
};

//================================================
// �G�H��Q���Ǘ�����N���X
//	�iSingleton�j
//================================================
class CDamageFactoryManager {
private:
	//�R���X�g���N�^
	CDamageFactoryManager() {
	}

	//���L�̃C���X�^���X
	static CDamageFactoryManager* m_pDamageFactoryManager;

public:
	//�f�X�g���N�^
	~CDamageFactoryManager() {
		//���L�C���X�^���X�̍폜
		SAFE_DELETE(m_pDamageFactoryManager);

		//���t�����H��Q���폜
		std::map<ENEMY_TYPE, CDamageFactory*>::iterator itr = m_factories.begin();
		while (itr != m_factories.end()) {
			//�N���X�̃C���X�^���X���폜
			SAFE_DELETE(itr->second);
			//�C�e���[�^�[���X�V
			itr++;
		}
	}


	//�C���X�^���X�̎擾
	static CDamageFactoryManager* getInstance();

	//�G�H��Q
	std::map<ENEMY_TYPE, CDamageFactory*> m_factories;

	/**
	* @desc	�G�L�����N�^�[�𐶐�
	* @param	�o��������ʒu
	* @param	�G�̃^�C�v
	* @return	���������G�L�����N�^�[
	*/
	CDamageCharacter* create(Point pos, ENEMY_TYPE type) {
		//�G�̃^�C�v�� key �Ƃ��ēG�𐶐����ĕԂ�
		return this->m_factories[type]->create(pos.x, pos.y);
	}

};

//EOF