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


//EOF