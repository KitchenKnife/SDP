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

	//�����Ƒg�ݗ���
	virtual CDamageCharacter* createDamage() = 0;

	//�ړ��f�[�^�̐ݒ�
	virtual void settingMove(CDamageCharacter* pChara, CCharacter* pAttackChara) = 0;
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
	virtual void settingInitialize(CDamageCharacter* pChara,int activeFrame) = 0;

public:
	//�f�X�g���N�^
	virtual ~CDamageFactory() {};

	//�G�̐����ƃZ�b�e�B���O
	CDamageCharacter* create(CCharacter* pAttackChara,int activeFrame) {

		//�G�̐����Ƒg�ݗ���
		CDamageCharacter* pChara = this->createDamage();

		//�ړ��f�[�^�ݒ�
		this->settingMove(pChara, pAttackChara);
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
		this->settingInitialize(pChara,activeFrame);

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
	void settingMove(CDamageCharacter* pChara, CCharacter* pAttackChara)override;
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
	void settingInitialize(CDamageCharacter* pChara,int activeFrame)override;

};

//================================================
// �_���[�W�H��Q���Ǘ�����N���X
//	�iSingleton�j
//================================================
class CDamageFactoryManager {
private:
	//�R���X�g���N�^
	CDamageFactoryManager() {

		this->m_factories = new CNearDamageFactory();
	}

	//���L�̃C���X�^���X
	static CDamageFactoryManager* m_pDamageFactoryManager;

public:
	//�f�X�g���N�^
	~CDamageFactoryManager() {
			SAFE_DELETE(this->m_factories);
	}

	static void removeInstance() {
		SAFE_DELETE(m_pDamageFactoryManager);
	}


	//�C���X�^���X�̎擾
	static CDamageFactoryManager* getInstance();

	//�_���[�W�H��i1��ނ̂݁j
	CDamageFactory* m_factories;

	/**
	* @desc	�L�����N�^�[�𐶐�
	* @param	�v���C���[��m_pMove
	* @param	���݂����Ă����t���[����
	* @param	�o������
	* @return	���������_���[�W�L�����N�^�[
	*/
	CDamageCharacter* create(CCharacter* pAttackChara,int activeFrame) {

		return this->m_factories->create(pAttackChara,activeFrame);
	}

};

//EOF