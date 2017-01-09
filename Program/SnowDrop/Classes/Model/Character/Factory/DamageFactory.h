/*
* DamageFactory.h
*
*	2016/12/21	Yamasaki And Harada
*	2017/01/09	Shinya Ueba	
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/DamageCharacter/DamageCharacter.h"
#include "Model\Character\Factory\CharacterFactory.h"
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

	//�����Ƒg�ݗ���
	virtual CDamageCharacter* createDamage() = 0;

	//�ړ��f�[�^�̐ݒ�
	virtual void settingMove(CDamageCharacter* pChara, cocos2d::Point pos) = 0;
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
	virtual void settingInitialize(CDamageCharacter* pChara,CCharacter* pAttackChara,int activeFrame) = 0;

public:
	//�f�X�g���N�^
	virtual ~CDamageFactory() {};

	//�G�̐����ƃZ�b�e�B���O
	CDamageCharacter* create(CCharacter* pAttackChara, cocos2d::Point pos,int activeFrame) {

		//�G�̐����Ƒg�ݗ���
		CDamageCharacter* pChara = this->createDamage();

		//�ړ��f�[�^�ݒ�
		this->settingMove(pChara, pos);
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
		this->settingInitialize(pChara, pAttackChara,activeFrame);

		return pChara;
	}
};


//================================================
// �����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
class CDamageCreateFactory :public CDamageFactory {
public:

	//�f�X�g���N�^
	virtual ~CDamageCreateFactory() {}

	//�����Ƒg�ݗ���
	CDamageCharacter* createDamage()override;

};

//================================================
// �ߐڃ_���[�W�H��
//================================================
class CNearDamageFactory :public CDamageCreateFactory {
public:
	//�f�X�g���N�^
	virtual ~CNearDamageFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CDamageCharacter* pChara, cocos2d::Point pos)override;
	//�摜�̐ݒ�
	void settingTexture(CDamageCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CDamageCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CDamageCharacter* pChara)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CDamageCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CDamageCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CDamageCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CDamageCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CDamageCharacter* pChara, CCharacter* pAttackChara, int activeFrame)override;

};

//================================================
// ���_���[�W�H��
//================================================
class CSmokeDamageFactory :public CDamageCreateFactory {
public:
	//�f�X�g���N�^
	virtual ~CSmokeDamageFactory() {}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CDamageCharacter* pChara, cocos2d::Point pos)override;
	//�摜�̐ݒ�
	void settingTexture(CDamageCharacter* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CDamageCharacter* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CDamageCharacter* pChara)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CDamageCharacter* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CDamageCharacter* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CDamageCharacter* pChara)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	void settingStateMachine(CDamageCharacter* pChara)override;
	//���̑������ݒ�
	void settingInitialize(CDamageCharacter* pChara, CCharacter* pAttackChara, int activeFrame)override;

};


//================================================
// �_���[�W�H��Q���Ǘ�����N���X
//	�iSingleton�j
//================================================
class CDamageFactoryManager {
private:
	//�R���X�g���N�^
	CDamageFactoryManager() {

		//�ߐڍU�������H��𐶐��� [key : NONE] �Ɏ��t����
		this->m_factories[DAMAGE_TYPE::NONE] = new CNearDamageFactory();

		//���U�������H��𐶐��� [key : SMOKE] �Ɏ��t����
		this->m_factories[DAMAGE_TYPE::SMOKE] = new CSmokeDamageFactory();
	}

	//���L�̃C���X�^���X
	static CDamageFactoryManager* m_pDamageFactoryManager;

public:
	//�f�X�g���N�^
	~CDamageFactoryManager() {
		//���t�����H��Q���폜
		std::map<DAMAGE_TYPE, CDamageFactory*>::iterator itr = m_factories.begin();
		while (itr != m_factories.end()) {
			//�N���X�̃C���X�^���X���폜
			SAFE_DELETE(itr->second);
			//�C�e���[�^�[���X�V
			itr++;
		}
	}

	static void removeInstance() {
		SAFE_DELETE(m_pDamageFactoryManager);
	}


	//�C���X�^���X�̎擾
	static CDamageFactoryManager* getInstance();

	//�_���[�W�H��Q
	std::map<DAMAGE_TYPE, CDamageFactory*> m_factories;


	/**
	* @desc	�_���[�b�W�L�����N�^�[�𐶐�
	* @param	�o��������ʒu
	* @param	���݂����Ă����t���[����
	* @return	���������_���[�W�L�����N�^�[
	*/
	CDamageCharacter* create(CCharacter* pAttackChara, cocos2d::Point pos,int activeFrame, DAMAGE_TYPE type = DAMAGE_TYPE::NONE) {

		//�G�̃^�C�v�� key �Ƃ��ēG�𐶐����ĕԂ�
		return this->m_factories[type]->create(pAttackChara, pos, activeFrame);
	}

};

//EOF