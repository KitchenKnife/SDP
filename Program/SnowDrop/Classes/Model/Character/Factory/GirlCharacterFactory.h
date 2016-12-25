#pragma once
#include "Model/Character/GirlCharacter/GirlCharacter.h"

//=============================================================
// �����L�����N�^�[�p�[�c�����H��
//	�iAbstractFactory�j
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//============================================================
class CPlayerGirlPartsFactory :public CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CPlayerGirlPartsFactory() {}

	//�A�j���[�V�����Q�f�[�^�̐����Ǝ擾
	virtual std::vector<CAnimation*>* getAnimations()override;
	//�ړ��f�[�^�̐����Ǝ擾
	virtual CMove* getMove()override;
	//�������Z�Q�f�[�^�̐����Ǝ擾
	virtual std::vector<CPhysical*>* getPhysicals()override;
	//���̃f�[�^�̐����Ǝ擾
	virtual CBody* getBody()override;
	//�Փ˔����ԌQ�f�[�^�̐����Ǝ擾
	virtual std::vector<CCollisionArea*>* getCollisionAreas()override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
	*	@return ��ԑJ�ڃf�[�^
	*	@author Shinya Ueba
	*/
	virtual	CStateMachine*	getStateMachine(void)override;

};


//=====================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author Shinya Ueba
//=====================================================
class CPlayerGirlFactory {
public:
	//�f�X�g���N�^
	virtual ~CPlayerGirlFactory() {}

	//�v���C���[�̐����Ƒg�ݗ���
	//�h����ɂ���ĈႤ�v���C���[�̐���
	virtual CPlayerCharacterGirl* createPlayer() = 0;

	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CPlayerCharacterGirl* pChara) = 0;

	//�摜�̐ݒ�
	virtual void settingTexture(CPlayerCharacterGirl* pChara) = 0;

	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CPlayerCharacterGirl* pChara) = 0;

	//�K�p���镨���v�Z�̐ݒ�
	virtual void settingPhysicals(CPlayerCharacterGirl* pChara) = 0;

	//�A�N�V�����̐ݒ�
	virtual void settingActions(CPlayerCharacterGirl* pChara) = 0;

	//���̃f�[�^�̐ݒ�
	virtual void settingBody(CPlayerCharacterGirl* pChara) = 0;

	//�Փ˔�����
	virtual void settingCollisionArea(CPlayerCharacterGirl* pChara) = 0;

	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CPlayerCharacterGirl* pChara) = 0;

	//���̑��F�����ݒ�
	virtual void settingInitialize(CPlayerCharacterGirl* pChara) = 0;


	//�v���C���[�̐����ƃZ�b�e�B���O
	CPlayerCharacterGirl* create();
};


//================================================
// ���̎q�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerGirlCreateFactory :public CPlayerGirlFactory {
public:

	//�f�X�g���N�^
	virtual ~CPlayerGirlCreateFactory() {}

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerCharacterGirl* createPlayer()override;

};

//====================================================
// ���̎q�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author Shinya Ueba
//====================================================
class CBasePlayerGirlFactory :public CPlayerGirlCreateFactory {
public:

	//�e�X�̃p�[�c�̃Z�b�e�B���O
	//�ړ��f�[�^�̐ݒ�
	void settingMove(CPlayerCharacterGirl* pCharacter)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerCharacterGirl* pCharacter)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CPlayerCharacterGirl* pCharacter)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CPlayerCharacterGirl* pCharacter)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CPlayerCharacterGirl* pCharacter)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CPlayerCharacterGirl* pCharacter)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CPlayerCharacterGirl* pCharacter)override;
	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CPlayerCharacterGirl* pChara)override;



	//���̑������ݒ�
	void settingInitialize(CPlayerCharacterGirl* pCharacter)override;
};

//���N�̎��
enum class GIRL_TYPE :int {
	BASE = 0,	//��{
};

//================================================
// �����L�����N�^�[�����H����Ǘ�����N���X
//	�iSingleton�j
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerGirlFactoryManager {
private:
	//�R���X�g���N�^
	CPlayerGirlFactoryManager() {
		//��{���N�L�����N�^�[�̍H��
		this->m_factories.push_back(new CBasePlayerGirlFactory());
	}

	//���L�̃C���X�^���X
	static CPlayerGirlFactoryManager* m_pPlayerGirlFactoryManager;

public:
	//�f�X�g���N�^
	~CPlayerGirlFactoryManager() {
		SAFE_DELETE(m_pPlayerGirlFactoryManager);

		for (CPlayerGirlFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}

	//�C���X�^���X�̔j��
	static void removeInstance();

	//�C���X�^���X�̎擾
	static CPlayerGirlFactoryManager* getInstance();

	//�v���C���[�H��Q
	std::vector<CPlayerGirlFactory*> m_factories;


	//�v���C���[�H���create()���Ăяo��
	CPlayerCharacterGirl* create(int type) {

		return this->m_factories[type]->create();
	}

};
