/*
* EnemyLaunchData.h
*
*	2016/11/07	Osumi
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Map/Map.h"
#include "Model\Character\DamageCharacter\DamageCharacter.h"

using namespace cocos2d;

// �O���錾
class CCharacter;
//=========================================================================
//�@�G�o���f�[�^
//=========================================================================
class CEnemyLaunchData {
public:
	//�G�̃^�C�v
	ENEMY_TYPE m_type;
	//�o���ʒu
	Point m_pos;

	//�R���X�g���N�^
	CEnemyLaunchData(ENEMY_TYPE type, Point pos)
		:m_type(type),m_pos(pos){}

};

//=========================================================================
//�@�M�~�b�N�o���f�[�^
//=========================================================================
class CGimmickLaunchData {
public:
	//�e�̃^�C�v
	GIMMICK_TYPE m_type;
	//���ˈʒu
	cocos2d::Point m_pos;

	//�R���X�g���N�^
	CGimmickLaunchData(GIMMICK_TYPE type, cocos2d::Point pos) {

		this->m_type = type;
		this->m_pos = pos;
		
	}

};


//=========================================================================
//�@�G�t�F�N�g�o���f�[�^
//=========================================================================
class CEffectLaunchData {
public:
	//�G�t�F�N�g�̃^�C�v
	EFFECT_TYPE m_type;
	//�o���ʒu
	cocos2d::Point m_pos;

	//�R���X�g���N�^
	CEffectLaunchData(EFFECT_TYPE type, cocos2d::Point pos) {

		this->m_type = type;
		this->m_pos = pos;

	}

};

//=========================================================================
//�@�_���[�W�o���f�[�^
//=========================================================================
class CDamageLaunchData {
public:
	//�U�����s���L�����N�^�[�i�_���[�W���o��������L�����j
	CCharacter* m_pChara;

	//�o��������ʒu
	cocos2d::Point m_pos;

	// ���t���[�����݂����邩
	int m_activeFrame;

	//�_���[�W�^�C�v
	DAMAGE_TYPE m_type;

	//�R���X�g���N�^
	CDamageLaunchData(CCharacter* pChara,cocos2d::Point pos,int activeFrame, DAMAGE_TYPE type = DAMAGE_TYPE::NONE)
		:m_pChara(pChara) ,m_pos(pos) ,m_activeFrame(activeFrame),m_type(type){}

};