#pragma once
#include <math.h>
#include <stdio.h>
#include "cocos2d.h"
#include "Constants.h"

//=================================
//�@�O���錾
//=================================
class CCharacter;
class CEnemyCharacter;

//-------------------------------------------------------
//  math.h  ���Z�N���X�t�@�C��
//  12/27
//		Author	Keita Osumi
//------------------------------------------------------
//���Z�N���X
class CCustomMath {
private:
	//�R���X�g���N�^
	CCustomMath();

	//���L�C���X�^���X
	static CCustomMath* m_pSharedCustomMath;

public:
	//�f�X�g���N�^
	~CCustomMath();

	//�^�[�Q�b�g�̎��
	enum class TARGET_TYPE :int {
		NONE,
		BOY,
		GIRL,
		BOTH
	};

	//�C���X�^���X�̎擾
	static CCustomMath* getInstance();

	//�C���X�^���X�̔j��
	static void removeInstance();

	/*
	* @desc 2�_�Ԃ̋��������߂鎮
	* @param �_1
	* @param �_2
	* @return �_1�Ɠ_2�̋���
	*/
	virtual float length(cocos2d::Point pt1, cocos2d::Point pt2);

	/*
	* @desc 2�̂̃L�����̋��������߂鎮
	* @param�@�L����1
	* @param�@�L����2
	* @return �L����1�ƃL����2�̋���
	*/
	virtual float lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2);

	/*
	* @desc �^�[�Q�b�g�̒T���ƑI��
	* @param �A�N�V�������s���L�����N�^�[
	* @return �^�[�Q�b�g�����܂������ǂ����@true...���܂���
	* @tips �����ƋR�m�œG�ɋ߂����̋����𓱂�
	*�@�@�@ �߂������ǐՔ͈͂ɂȂ�^�[�Q�b�g�ɐݒ�
	*/
	virtual bool seachAndSelectTarget(CCharacter* pChara);

	/*
	* @desc �^�[�Q�b�g���ԍ����ɂ��邩�ǂ����̂��m�F�ƒǐՏ�Ԃւ̈ڍs
	* @param �A�N�V�������s���L�����N�^�[
	* @param �^�[�Q�b�g�̃^�C�v
	*/
	virtual void checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type);

	/*
	* @desc �L��������^�[�Q�b�g�ւ�X�����̐��K���x�N�g�������߂Đ����ړ����x��ݒ�
	* @param �A�N�V�������s���L�����N�^�[
	* @param �ڕW�n�_�̍��W
	*/
	virtual void normalizeVel_X(CCharacter* pChara, cocos2d::Point pt);

	/*
	* @desc �ڕW�n�_�܂ł̐��K���x�N�g���ɃL�����̃X�s�[�h�������l��ݒ肷��
	* @param �A�N�V�������s���L�����N�^�[
	* @param �ڕW�n�_�̍��W
	*/
	virtual void normalizeVel(CCharacter* pChara, cocos2d::Point pt);

};

//�C���X�^���X�̎擾�̃}�N��
#define customMath (CCustomMath::getInstance())

