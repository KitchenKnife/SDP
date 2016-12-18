
/*
* EnemyCharacter.h
*
*	2016/11/11	Yamasaki
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"
#include "Data/Status/Status.h"

//================================================
// 
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//		
//================================================
class CEnemyCharacter :public CCharacter {
public:

	//�R���X�g���N�^
	CEnemyCharacter();

	//�f�X�g���N�^
	~CEnemyCharacter();

	//����������
	bool init()override;

	
	//�s����A�N�V�����Q
	//std::vector<CAction* >* m_pActions = NULL;

	//�s����A�N�V�����Q
	//std::vector<CEnemyAction* >* m_pActions = NULL;

	/*
	* @desc	����������
	* @param�@�������ʒuX 
	* @param�@�������ʒuY
	* @tips�@create()�����o�֐��̒���init()�����o�֐����Ăяo���Ă邪
	*		�@����A����create()�����o�֐����I�[�o�[���[�h����
	*		�@�������󂯎���Ă���̂ŁAinit()�����o�֐���
	*		�@�I�[�o�[���[�h����K�v������B
	*/
	bool init(float posX, float posY);

	/**
	* @desc CREATE_FUNC�}�N���̒��g�����̂܂܂����Ă�������
	* @tips		�O��͓G�o���f�[�^�Ƃ����G��p�̃N���X�����݂��Ă����̂�
	*			���̃N���X�ɒ��������Ă����Ȃ�������
	*�@�@�@�@�@ ����̓}�b�v�̏��ɂ��o���ʒu�̌���Ƃ������ڂ��K�v�ɂȂ�B
	*�@�@�@�@�@ �}�b�v���V���O���g���������̂Œ��������Ă����Ȃ��悤�Ɏv���邪
	*�@�@�@�@�@ ���̃^�C�~���O�ł��̏ꏊ�̃}�b�v�̃^�C���̈ʒu��񂪕K�v�ɂȂ�B
	*�@�@�@�@�@�ŏI�I�ɕK�v�ɂȂ�͈̂ʒu�������B
	*�@�@�@�@�@�Ȃ̂Ő����Ɠ����Ɉʒu���擾�������B
	*�@�@�@�@�@�����������Acocos2d���̋@�\�ł��鎩����delete�̋@�\���g������
	*�@�@�@�@�@�Ȃ̂ŁAcreate�ÓI�����o�֐����J�X�^�}�C�Y����B
	*/
	//CREATE_FUNC(CEnemyCharacter);
	
	static CEnemyCharacter* create() {
		CEnemyCharacter* pRet = new(std::nothrow) CEnemyCharacter();
	
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
	

	/**
	* @desc CREATE_FUNC���I�[�o�[���[�h
	* @param �����ʒu
	* @param
	* @tips		�O��͓G�o���f�[�^�Ƃ����G��p�̃N���X�����݂��Ă����̂�
	*			���̃N���X�ɒ��������Ă����Ȃ�������
	*�@�@�@�@�@ ����̓}�b�v�̏��ɂ��o���ʒu�̌���Ƃ������ڂ��K�v�ɂȂ�B
	*�@�@�@�@�@ �}�b�v���V���O���g���������̂Œ��������Ă����Ȃ��悤�Ɏv���邪
	*�@�@�@�@�@ ���̃^�C�~���O�ł��̏ꏊ�̃}�b�v�̃^�C���̈ʒu��񂪕K�v�ɂȂ�B
	*�@�@�@�@�@�ŏI�I�ɕK�v�ɂȂ�͈̂ʒu�������B
	*�@�@�@�@�@�Ȃ̂Ő����Ɠ����Ɉʒu���擾�������B
	*�@�@�@�@�@�����������Acocos2d���̋@�\�ł��鎩����delete�̋@�\���g������
	*�@�@�@�@�@�Ȃ̂ŁAcreate�ÓI�����o�֐����J�X�^�}�C�Y����B
	*/
	static CEnemyCharacter* create(float posX, float posY) {
		CEnemyCharacter* pRet = new(std::nothrow) CEnemyCharacter();

		if (pRet && pRet->init(posX, posY)) {
			pRet->autorelease();
			return pRet;
		}
		else {
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}



	//================================================
	// 
	//	�萔�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//�G�̏��(�A�j���[�V�����Ǘ�)
	enum class STATE :int {
		STAND = 0,
		JUMPING = 0,
		WALK = 1,
		HIT = 2,
		FALING = 3,
		ATTACK = 4,
		PURSUIT = 5,
		IDLE = 6,
		DAMAGE = 7,

	};

	//�G���s����A�N�V����
	enum class ACTION :int {
		JUMP = 0,
		ATTACK = 1,
		PURSUIT = 2,
		IDLE = 3,
		DAMAGE = 4,
	};

	//================================================
	// 
	// �����o�[�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	// �A�N�V��������
	void actionFunc(CCharacter* pChara);

	//�ړ�����
	void moveFunc() override;

	//�A�j���[�V��������
	void animationFunc()override;

	//��ʔ͈͊O���菈��
	//void endOfScreen()override;

	//��ԃ`�F�b�N
	void checkState() override;

	//���f����
	void applyFunc() override;

	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override;

	/**
	* @desc �}�b�v�Ƃ̏Փ˔���
	* @return true...�Փ˂���
	*/
	//bool collisionMap()override;

	/**
	* @desc �Փ˔��菈��
	*/
	void collisionAll()override;
};

