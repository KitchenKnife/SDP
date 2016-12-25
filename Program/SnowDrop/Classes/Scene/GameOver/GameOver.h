#pragma once
//==========================================
//
// File: GameOver.h
//
//	�Q�[���I�[�o�[�V�[���t�@�C��
//
// 2016/12/21
//						Author Koyuki Yamasaki
//
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"cocos2d.h"

//==========================================
//
// Class: CGameOver
//
// �L�[�{�[�h���̓R���g���[���[�N���X
//
// 2016/12/18
//						Author Koyuki Yamasaki
//==========================================
class CGameOver : public cocos2d::Layer
{
public:
	/*
	* @desc �R���X�g���N�^
	*/
	CGameOver();

	/*
	* @desc �f�X�g���N�^
	*/
	~CGameOver();

	/**
	* @desc		�V�[���̐���
	* @return	CTitle���C���[�������V�[���N���X�C���X�^���X
	* @tips		�ÓI�����o�֐�
	*/
	static cocos2d::Scene* createScene();

	//create()�ÓI�����o�֐��̍쐬
	CREATE_FUNC(CGameOver);

	/**
	* @desc ������
	* @return true...���� false...���s
	*/
	bool init() override;

	/**
	* @desc  �X�V����
	* @param �o�ߎ���
	*/
	void update(float deltaTime) override;

	/**
	* @desc		�^�C�g���ɑJ��
	* @param	�^�C�g�����C���[�̃C���X�^���X
	* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
	*/
	void callbackChangeTitle(cocos2d::Ref* pSender);

};






//EOF