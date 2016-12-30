#pragma once
/*
* ActionController.h
*
*	2016/11/09	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"cocos2d.h"
#include"Constants.h"
#include "Lib/Math/Math.h"

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
	virtual ~CAction() {}

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
//�@���낤�듮��
//===================================================================
class CActionWondering :public CAction {
private:
	

	//���낤�낷�����
	int m_vec = 1;

	//�A�N�V���������ǂ��� true...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�������J�n��Ԃ��ǂ����@true...�J�n���
	bool m_isStart = false;

	//�������ׂ��^�[�Q�b�g
	//TARGET_TYPE m_defaultTarget = TARGET_TYPE::NONE;

public:
	/*
	* @desc �R���X�g���N�^
	* @param �ǐՂ��ׂ��v���C���[�^�C�v
	*/
	CActionWondering(/*TARGET_TYPE type*/);

	/*
	* @desc �J�n����
	*/
	void start()override;

	/*
	* @desc �X�V����
	* @param �A�N�V�������s���L�����N�^�[
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I����������
	*/
	void stop() override;
};

//===================================================================
//�@�ǐՃA�N�V����
//===================================================================
class CActionChase :public CAction {

private:

	//�ړ��������
	int m_vec = 1;

	//�A�N�V���������ǂ��� true...�A�N�V������
	bool m_inAction = false;

	//�A�N�V�������J�n��Ԃ��ǂ����@true...�J�n���
	bool m_isStart = false;

	//�ǐՓ�����s���G����s���邩�ǂ���
	bool m_isFlying = false;

public:
	/*
	* @desc �R���X�g���N�^
	* @param �L�����N�^�[����Ԃ��ǂ����@false...��΂Ȃ�
	*/
	CActionChase(bool isFlying);

	/*
	* @desc �J�n����
	*/
	void start()override;

	/*
	* @desc �X�V����
	* @param �A�N�V�������s���L�����N�^�[
	*/
	void update(CCharacter* pChara);

	/*
	* @desc �I����������
	*/
	void stop() override;
};

//EOF