
/*
* PlayerCharacter.h
*
*	2016/11/24	Osumi
*
*/

#pragma once
//================================================
//�@�ǉ��̃C���N���[�h�͂�������
//================================================
#include "../Character.h"
//#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
#include <map>


//================================================
//�@�N���X�̑O���錾�͂�������
//================================================
class CPlayerFactoryManager;
class CPlayerEffect;
class CPlayerWeapon;

//================================================
// �v���C���[�L�����N�^�[�N���X
//		����͍X�V�����������ōs����̂�
//		���͏����������ōs��
//		���͂ɂ��ړ������Ƃ����J�e�S���ň�����
//================================================
class CPlayerCharacter :public CCharacter {

public:

	//�R���X�g���N�^
	CPlayerCharacter();

	//�f�X�g���N�^
	~CPlayerCharacter();

	//����������
	bool init()override;

	//CREATE_FUNC(CPlayerCharacter);

	//================================================
	// 
	//	�萔�Ɋւ���R�[�h�̒ǉ��͂�������
	//			
	//================================================
	
	
	//�v���C���[�̏��
	enum class STATE :int {
		NONE = -1,
		STAND = 0,
		JUMPING =0,
		WALK =1,
		HIT = 2,
		FALING = 3,
		//RETURN_WEAPON ,	//�[��
		DRAWN_STAND,		//��������
		DRAWN_WALK,			//��������
		SLASH_ATTACK_01_1,	//�a��1_1
		SLASH_ATTACK_01_2,	//�a��1_2
		SLASH_ATTACK_01_3,	//�a��1_3

		LIFT_UPING,

		WASTE,		//�ɂԂ�
		WASTE_ANIME_01,
		WASTE_ANIME_02,
		WASTE_ANIME_03,

	};
	
	//�v���C���[���s����A�N�V����
	enum class ACTION :int {
		NONE = -1,
		JUMP = 0,
		ATTACK = 1 ,

		LIFT_UP,

		WASTE,		//�ɂԂ�
		WASTE_ACT_01,
		WASTE_ACT_02,
		WASTE_ACT_03,

	};

	//�G�t�F�N�g�^�C�v
	enum class EFFECT {
		NONE = -1,
		DISAPPEAR,
		DAMAGE,
	};

	//================================================
	// 
	//	�����o�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//�v���C���[�̏��
	STATE m_playerState = STATE::FALING;
	//�v���C���[�̃A�N�V�������
	ACTION m_playerAct = ACTION::NONE;

	//�A�j���[�V�����Q�imap�j
	std::map<STATE, CAnimation*> m_mapAnimations;
	//�A�N�V�����Q�imap�j
	std::map<ACTION, CAction*> m_mapActions;
	//�G�t�F�N�g�Q�imap�j
	std::vector<CPlayerEffect*>* m_pEffects = NULL;

	//����
	CPlayerWeapon* m_pWeapon = NULL;

	//��Ȃ��t���O
	//true...����Ȃ��ł�
	bool m_isShakeHands = false;

	//�X�V����
	virtual void update(float deltaTime)override;

	//�G�t�F�N�g�̃v���C���[�ւ̎��t��
	virtual void jointEffect(CPlayerCharacter::EFFECT effectType) = 0;

	//����̑���
	virtual void equipWeapon() = 0;

	/**
	* @desc ����Ȃ����Ԃ��`�F�b�N
	* @param �����i�����j�̍��W
	* @tips ����Ȃ����ԂȂ�"��Ȃ��t���O"���グ��
	*/
	void checkSakeHands(CPlayerCharacter* pCharacter);

	//�ړ�����
	virtual void moveFunc()override {};

	//�A�j���[�V��������
	virtual void animationFunc()override;

	//��ʔ͈͊O���菈��
	//virtual void endOfScreen()override;

	//��ԃ`�F�b�N
	virtual void checkState() override {};

	//���f����
	virtual void applyFunc() override;

	//�G�t�F�N�g�̍X�V����
	virtual void effectUpdate();
	
	//�L���t���O�̊m�F�Ƃ��̌�̏���
	virtual void checkActiveFlagAndFunc();

	//�G�t�F�N�g�̎��O��
	void removeEffect(CPlayerEffect* pEffect);

	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override;

	/**
	* @desc �Փ˔��菈��
	*/
	void collisionAll()override;
	
};


//================================================
// ���N�N���X
//================================================
class CPlayerBoy :public CPlayerCharacter {

private:
	//�R���X�g���N�^
	CPlayerBoy();

	//���L�C���X�^���X
	static CPlayerBoy* m_pBoy;

	//CREATE_FUNC(CPlayerBoy);

	//�����t���O true...�����n����
	//bool m_disappearFlag = false;

public:
	static CPlayerBoy* create() {
		CPlayerBoy* pRet = new(std::nothrow) CPlayerBoy();

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

	//�C���X�^���X�̎擾
	static CPlayerBoy* getInstance();

	//�C���X�^���X�̔j��
	static void removeInstnace() {
		//SAFE_DELETE(CPlayerBoy::m_pBoy);
	}

	//�f�X�g���N�^
	~CPlayerBoy();

	//����������
	bool init()override;

	//================================================
	// 
	//	�萔�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//���ˊԊu
	const static int m_disappearInterval = 60;
	//���˃J�E���^�[
	int m_disappearCounter = 0;

	

	//================================================
	// 
	//	�����o�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================
	//�G�t�F�N�g�̃v���C���[�ւ̎��t��
	virtual void jointEffect(CPlayerCharacter::EFFECT effectType)override;

	//����̑���
	virtual void equipWeapon()override;

	//�����Ƃ̋���
	float lengthFromGirl();

	//������Ԃ̃`�F�b�N�i�J�E���^�[�̃f�N�������g���S���j
	void checkDisappear();

	//�ړ�����
	void moveFunc()override;

	//��ԃ`�F�b�N
	virtual void checkState() override;

	//�X�V����
	void update(float deltaTime)override;

	void hits(CCharacter* pChara)override{}

	/**
	* @desc ���͏���
	* @tips �ړ������ŌĂяo��
	*/
	void inputFunc();

	//���͎�t���ۃt���O true...���͏������󂯕t���Ȃ�
	bool m_nonInputFlag = false;

	//��d�����h�~�t���O
	bool m_spaceKeyDown = false;
	bool m_zKeyDown = false;

	/**
	* @desc ����Ȃ����Ԃ��`�F�b�N
	* @param �����i�����j�̍��W
	* @tips ����Ȃ����ԂȂ�"��Ȃ��t���O"���グ��
	*/
	void checkSakeHands(CPlayerCharacter* pCharacter);
	
	/**
	* @desc ���݂��̎�����
	*/
	void removeHands();

	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	*		�@��ʉ��̍ۂ�0
	*/
	virtual void collisionBottomCallback(int event) {
		this->m_mapActions[ACTION::JUMP]->stop();
	}

};


//================================================
// �����N���X
//================================================
class CPlayerGirl :public CPlayerCharacter {


private:
	//�R���X�g���N�^
	CPlayerGirl();

	//���L�C���X�^���X
	static CPlayerGirl* m_pGirl;

	//CREATE_FUNC(CPlayerGirl);
	

public:
	static CPlayerGirl* create() {
		CPlayerGirl* pRet = new(std::nothrow) CPlayerGirl();

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

	//�C���X�^���X�̎擾
	static CPlayerGirl* getInstance();

	//�C���X�^���X�̔j��
	static void removeInstnace() {
		//SAFE_DELETE(CPlayerGirl::m_pGirl);
	}

	//�f�X�g���N�^
	~CPlayerGirl();

	//����������
	bool init()override;



	//================================================
	// 
	//	�萔�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//�ɂԂ��s���̎���
	const int m_wasteTime = 120;
	//�ɂԂ��A�N�V�������ɃC���N�������g
	int m_wasteActCounter = 0;

	//�ɂԂ����Ă邩�ǂ��� (true...�ɂԂ����Ă�)
	bool m_wasteActFlag = false;

	//================================================
	// 
	//	�����o�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//�ړ�����
	virtual void moveFunc()override;

	//��ԃ`�F�b�N
	virtual void checkState() override;

	//�X�V����
	void update(float deltaTime)override;

	//�G�t�F�N�g�̃v���C���[�ւ̎��t��
	virtual void jointEffect(CPlayerCharacter::EFFECT effectType){}

	//����̑���
	virtual void equipWeapon(){}

	/**
	* @desc ���N�Ɍ������Ă��߂Â�����
	* @param	���N�̈ʒu
	*/
	void closeWithBoyFunc(Point* pPos);

	/**
	* @desc ���N�ɂ��Ă�������
	* @param	���N�̈ʒu
	*/
	void goWithBoyFunc(Point* pPos);


	void hits(CCharacter* pChara)override{}
};

