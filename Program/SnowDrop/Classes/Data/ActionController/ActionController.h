/*
 * ActionController.h
 *
 *	2016/11/09	Osumi
 *
 */
#pragma once

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"cocos2d.h"
#include"Constants.h"

//================================================
// �O���錾�Ɋւ���R�[�h�͂������珑��
//================================================
class CCharacter;

//================================================
// �A�N�V�����N���X
//================================================
class CAction {
public:
	//�f�X�g���N�^
	virtual ~CAction(){}

	//�A�N�V�������J�n���邽�тɌĂяo��
	virtual void start() = 0;

	//�A�N�V�����̍X�V����
	virtual void update(CCharacter* pChara) = 0;

	//�A�N�V�������I�����邽�тɌĂяo��
	virtual void stop() = 0;


	/**
	 * @desc	�A�N�V�����̍ċN��
	 * @param	�ċN������L�����N�^�[
	 * @tips	�W���I�ȃA�N�V�����̍ċN��
	 *�@		�����ł̓L�����N�^�[�͎g�p���Ȃ�
	 */
	virtual void restart(CCharacter* pChara) {
		//�A�N�V�����̒�~
		this->stop();

		//�A�N�V�����̊J�n
		this->start();
	}

};

//===================================================================
// �W�����v
//		�W�����v�Ɋւ��鏈�����s�����������Ƃ��Ĉړ��f�[�^�ɑ΂��ĕύX��������
//		 tips:
//			cocos2dx��Action�N���X�ɂ��W�����v�͑��݂��邪
//			Action�N���X�Ɉˑ����Ă���̂ŏd�͂▀�C��}�b�v�`�b�v�Ȃǂ̉e�����l�����
//			���߂̂����͕������čl���������������₷��
//===================================================================
class CActionJump :public CAction {
protected:

	//�W�����v�̉����x
	float m_accele = 0.0f;
	//�W�����v�u�[�X�g
	int m_boost = 0;

	//���݂̃W�����v�u�[�X�g
	int m_currentBoost = 0;

	//�W�����v�����ǂ����̃t���O	true...�W�����v��
	bool m_isJumping = false;

	//�W�����v�J�n�t���O
	bool m_isJumpStart = false;

public:
	//�f�t�H���g�R���X�g���N�^
	CActionJump(){}
	//�R���X�g���N�^�i�e��ݒ�j
	CActionJump(float accele, int boost)
		:m_accele(accele),m_boost(boost){}

	/*
	 * @desc	�����x�ƃu�[�X�g�̐ݒ�
	 * @param	�����x
	 * @param	�W�����v�u�[�X�g
	 */
	void set(float accele, int boost)  {
		m_accele = accele;
		m_boost = boost;
	}

	/*
	 * @desc	�W�����v�J�n
	 * @tips	�W�����v�{�^���������ꂽ�ۂɌĂяo��
	 */
	void start()override {
		//�W�����v�J�n�t���O���グ��
		this->m_isJumpStart = true;
	}


	/*
	 * @desc	�X�V�����i�W�����v�ړ��v�Z�j
	 * @param	�W�����v����Ώۂ̃L�����N�^�[
	 * @tips	��L�[�������ꂽ�炱�̊֐����Ăяo��
	 */
	void update(CCharacter* pChara); 

	/*
	 * @desc	�W�����v�I��
	 * @tips	���n�����ۂɌĂяo��
	 */
	void stop()override {
		//�W�����v���t���O������
		this->m_isJumping = false;
	}

	/**
	* @desc	�A�N�V�����̍ċN��
	* @param �ċN������L�����N�^�[
	* @tips �L�����N�^�[��Y�����̃��Z�b�g
	*/
	void restart(CCharacter* pChara)override;
};
