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


enum HENCHMAN_POSITION_TYPE :int
{
	NONE	= 0,
	FORWARD = 1,
	DEFENDER = 2,
};


//================================================
// 
// �G�L�����N�^�[�̊��N���X�ƂȂ�N���X
//		
//================================================
class CMouseCharacter :public CEnemyCharacter {
public:
	//�R���X�g���N�^
	CMouseCharacter(CMouseKingCharacter* pMaster, int positionType);

	//�f�X�g���N�^
	virtual ~CMouseCharacter();

	static CMouseCharacter* create(CMouseKingCharacter* pMaster, int positionType) \
	{ \
		CMouseCharacter *pRet = new(std::nothrow) CMouseCharacter(pMaster,positionType); \
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

	/**
	* @desc �U�����߃t���O��ݒ�
	* @param true...�U��������@false...�U�������Ȃ�
	*/
	void setAttackOrder(bool flag);


	/**
	* @desc �U�����߃t���O���擾
	* @param true...�U��������@false...�U�������Ȃ�
	*/
	bool getAttackOrder(void);

	CMouseKingCharacter* m_pMaster = NULL;
	
	int m_positionType = (int)HENCHMAN_POSITION_TYPE::NONE;
private:
	

	bool m_attackOrder = false;
};