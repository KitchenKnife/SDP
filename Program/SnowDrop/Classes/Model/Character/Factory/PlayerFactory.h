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
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"

//================================================
// ���N�L�����N�^�[�p�[�c�����H��
//	�iAbstractFactory�j
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerBoyPartsFactory :public CCharacterPartsFactory {
public:
	//�f�X�g���N�^
	virtual ~CPlayerBoyPartsFactory() {}

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


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerBoyFactory {
public:
	//�f�X�g���N�^
	virtual ~CPlayerBoyFactory() {}

	//�v���C���[�̐����Ƒg�ݗ���
	virtual CPlayerCharacterBoy* createPlayer() = 0;

	//�ړ��p�f�[�^�̐ݒ�
	virtual void settingMove(CPlayerCharacterBoy* pChara) = 0;

	//�摜�̐ݒ�
	virtual void settingTexture(CPlayerCharacterBoy* pChara) = 0;

	//�A�j���[�V�����̐ݒ�
	virtual void settingAnimations(CPlayerCharacterBoy* pChara) = 0;

	//�K�p���镨���v�Z�̐ݒ�
	virtual void settingPhysicals(CPlayerCharacterBoy* pChara) = 0;

	//�A�N�V�����̐ݒ�
	virtual void settingActions(CPlayerCharacterBoy* pChara) = 0;

	//���̃f�[�^�̐ݒ�
	virtual void settingBody(CPlayerCharacterBoy* pChara) = 0;

	//�Փ˔�����
	virtual void settingCollisionArea(CPlayerCharacterBoy* pChara) = 0;

	/**
	*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
	*	@param �ݒ肷��L�����N�^�[
	*	@author Shinya Ueba
	*/
	virtual	void settingStateMachine(CPlayerCharacterBoy* pChara) = 0;

	//���̑��F�����ݒ�
	virtual void settingInitialize(CPlayerCharacterBoy* pChara) = 0;

	
	//�v���C���[�̐����ƃZ�b�e�B���O
	CPlayerCharacterBoy* create();
};

//================================================
// ���N�L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerBoyCreateFactory :public CPlayerBoyFactory {
public:
	//�f�X�g���N�^
	virtual ~CPlayerBoyCreateFactory(){}

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerCharacterBoy* createPlayer()override;

};

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//================================================
class CBasePlayerBoyFactory :public CPlayerBoyCreateFactory {
public:
	//�f�X�g���N�^
	~CBasePlayerBoyFactory(){}

	//�ړ��f�[�^�̐ݒ�
	void settingMove(CPlayerCharacterBoy* pChara)override;
	//�摜�̐ݒ�
	void settingTexture(CPlayerCharacterBoy* pChara)override;
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	void settingAnimations(CPlayerCharacterBoy* pChara)override;
	//�������Z�Q�f�[�^�̐ݒ�
	void settingPhysicals(CPlayerCharacterBoy* pChara)override;
	//�A�N�V�����Q�f�[�^�̐ݒ�
	void settingActions(CPlayerCharacterBoy* pChara)override;
	//���̃f�[�^�̐ݒ�
	void settingBody(CPlayerCharacterBoy* pChara)override;
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	void settingCollisionArea(CPlayerCharacterBoy* pChara)override;
	//��ԑJ�ڃ}�V���̐ݒ�
	void settingStateMachine(CPlayerCharacterBoy* pChara)override;

	//���̑������ݒ�
	void settingInitialize(CPlayerCharacterBoy* pCharacter)override;

};


//���N�̎��
enum class PLAYER_TYPE :int {
	BASE	= 0,	//��{
};

//================================================
// ���N�L�����N�^�[�����H����Ǘ�����N���X
//	�iSingleton�j
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerBoyFactoryManager {
private:
	//�R���X�g���N�^
	CPlayerBoyFactoryManager(){
		//��{���N�L�����N�^�[�̍H��
		m_factories.push_back(new CBasePlayerBoyFactory());
	}

	//���L�̃C���X�^���X
	static CPlayerBoyFactoryManager* m_pPlayerBoyFactoryManager;
	
public:
	//�f�X�g���N�^
	~CPlayerBoyFactoryManager() {
		SAFE_DELETE(m_pPlayerBoyFactoryManager);

		for (CPlayerBoyFactory* pFactory : this->m_factories) {
			SAFE_DELETE(pFactory);
		}
	}


	//�C���X�^���X�̎擾
	static CPlayerBoyFactoryManager* getInstance();

	//�v���C���[�H��Q
	std::vector<CPlayerBoyFactory*> m_factories;
	

	//�v���C���[�H���create()���Ăяo��
	CPlayerCharacterBoy* create( int type ) {

		return this->m_factories[type]->create();
	}

};

