
/*
* PlayerWeapon.h
*
*	2016/11/26	Osumi
*
*/
#pragma once

#include "Model/Weapon/Weapon.h"
#include "cocos2d.h"
#include "Lib/Input/InputManager.h"

class CPlayerWeaponAttack;

//����̏��
enum class PLAYER_WEAPON_STATE :int {

	NONE = -1,  //����
	RETURN,    //�[��
	DRAWN,	   //����
	ATTACK,    //�U��

};

//================================================
//
//�@�v���C���[�̕�����N���X
//
//================================================
class CPlayerWeapon :public CWeapon {
	
	

	//================================================
	//�@�ϐ�
	//================================================
public:

	//��d�����h�~�t���O
	bool m_zKeyDown = true;

	//����̑����ʒu
	cocos2d::Point m_offset;


	//�U���A�j��
	enum class ATTACK_ANIME :int {

		NONE = -1,		//����
		RETURN,			//�[��
		DRAWN,			//����
		SLASH_01_1,     //�a��01_1
		SLASH_01_2,     //�a��01_2
		SLASH_01_3,     //�a��01_3

	};

	//�U���A�N�V����
	enum class ATTACK_ACT :int {

		NONE = -1,		//����
		DRAWN,			//����
		SLASH_01,       //�a��01

	};

	//�U���A�j��
	ATTACK_ANIME m_attackAnime = ATTACK_ANIME::RETURN;
	//�U���A�N�V����
	ATTACK_ACT m_attackAct = ATTACK_ACT::NONE;

	//================================================
	//�@�֐�
	//================================================
public:

	//�R���X�g���N�^
	CPlayerWeapon();

	//�f�X�g���N�^
	virtual ~CPlayerWeapon();

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update()override;

	//��Ԃ̃`�F�b�N
	virtual void checkState();

	//����̔[��
	virtual void returnSword();

	//����̎��t��
	virtual void addChildPlayer(CPlayerCharacter* pChara) = 0;
	
	//���C���[����̎��O��
	void removeFromeLayer();

	//����̏��
	//PLAYER_WEAPON_STATE m_state = PLAYER_WEAPON_STATE::RETURN;

	//�A�j���[�V�����f�[�^�Q(map)
	std::map<ATTACK_ANIME, CAnimation* > m_mapAnimations;
	//�s����A�N�V�����Q(map)
	std::map<ATTACK_ACT, CPlayerWeaponAttack* > m_mapActions;

protected:

	//�ړ�����
	virtual void moveFunc()override;

	//�A�j���[�V��������
	virtual void animationFunc()override;

	//�A�N�V��������
	virtual void actionFunc();

	//���͏���
	virtual void inputFunc();

public:

	//���f����
	virtual void applyFunc()override;

	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	//virtual bool collision(CCharacter* pChara) = 0;

};

//================================================
//
//�@�v���C���[�̒ʏ핐��N���X
//
//================================================
class CPlayerNormalWeapon :public CPlayerWeapon {

private:

	//�R���X�g���N�^
	CPlayerNormalWeapon();

	//���L�C���X�^���X
	static CPlayerNormalWeapon* m_pPlayerWeapon;

public:

	//�C���X�^���X�̎擾
	static CPlayerNormalWeapon* getInstance();

	//�C���X�^���X�̉��
	static void removeInstance();

	//����̃��C���[�ւ̎��t��
	void addChildPlayer(CPlayerCharacter* pChara)override;

	//�f�X�g���N�^
	virtual ~CPlayerNormalWeapon();

	//����������
	virtual bool init()override;

	//�X�V����
	virtual void update()override;

	

	//CREATE_FUNC(CPlayerNormalWeapon);

	static CPlayerNormalWeapon* create() {
		CPlayerNormalWeapon* pRet = new(std::nothrow) CPlayerNormalWeapon();

		if (pRet && pRet->init()) {
			pRet->autorelease();
			return pRet;
		}
		else {
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

protected:

	//�ړ�����
	//virtual void moveFunc()override;

	//�A�j���[�V��������
	virtual void animationFunc()override;

	//��ԃ`�F�b�N
	//virtual void checkState()override {};

	/**
	* @desc �Փ˔��菈��
	*/
	void collisionAll()override {};

public:
	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override {
		return true;
	};

	void hits(CCharacter* pChara)override{}

};