#pragma once
/*
* MouseCharacter.h
*
*	2017/01/11	Shinya Ueba
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "../EnemyCharacter.h"
#include "Model/Map/Map.h"

//������������������������������������������������
//�@�O���錾
//������������������������������������������������
class CMouseKingCharacter;

//================================================
// 
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//================================================
class CMouseCharacter :public CEnemyCharacter {
public:
	//�R���X�g���N�^
	CMouseCharacter(CMouseKingCharacter* pMaster);

	//�f�X�g���N�^
	virtual ~CMouseCharacter();

	static CMouseCharacter* create(CMouseKingCharacter* pMaster) \
	{ \
		CMouseCharacter *pRet = new(std::nothrow) CMouseCharacter(pMaster); \
		if (pRet && pRet->init()) \
		{ \
			pRet->autorelease(); \
			return pRet; \
		} \
		else \
		{ \
			delete pRet; \
			pRet = nullptr; \
			return nullptr; \
		} \
	}

private:
	CMouseKingCharacter* m_pMaster = NULL;
};