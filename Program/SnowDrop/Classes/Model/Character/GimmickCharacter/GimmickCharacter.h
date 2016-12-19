#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "../Character.h"


//================================================
// 
// �M�~�b�N�N���X
//			
//================================================
class CGimmickCharacter :public CCharacter {
public:

	//�R���X�g���N�^
	CGimmickCharacter();

	//�f�X�g���N�^
	virtual ~CGimmickCharacter();

	//����������
	bool init()override;

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

	static CGimmickCharacter* create() {
		CGimmickCharacter* pRet = new(std::nothrow) CGimmickCharacter();

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


	//================================================
	// 
	// �����o�[�Ɋւ���R�[�h�̒ǉ��͂�������
	//		
	//		
	//================================================

	//�ړ�����
	void moveFunc() override;

	//�A�j���[�V��������
	void animationFunc()override;

	//��ԂƂ̏Փ˔��菈��
	void collisionAll()override;


	//��ԃ`�F�b�N
	void checkState() override;

	//���f����
	void applyFunc() override;

	void hits(CCharacter* pChara)override{}

	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	bool collision(CCharacter* pChara)override;

	/**
	* @desc ���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	* @param �}�b�v�`�b�vID
	*		�@��ʉ��̍ۂ�0
	*/
	void collisionBottomCallback(int event)override {};

	/**
	* @desc �Փ˂����ۂ̃C�x���g�R�[���o�b�N
	*/
	void collisionTopCallback(int event)override {};

	/**
	* @desc �Փ˂����ۂ̃C�x���g�R�[���o�b�N
	*/
	void collisionRightCallback(int event)override {};

	/**
	* @desc ��ʒ[�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N
	*/
	void collisionLeftCallback(int event)override {};

	/**
	* @desc �Փ˂��Ă�����̏���
	* @param �Փ˂��Ă����L�����N�^�[
	*/
	//void hits(CCharacter* pChara)override;

	//�v���C���[�Ƃ̏Փ˔����̏���
	void hitsPlayerCharacter(CCharacter* pChara);

	//�v���C���[�ȊO�Ƃ̏Փ˔����̏���
	void hitsNotPlayerCharacter(CCharacter* pChara);

};


