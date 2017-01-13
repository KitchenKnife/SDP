#pragma once
/*
* MouseCharacter.h
*
*	2017/01/11	Shinya Ueba
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "../EnemyCharacter.h"
#include "Model/Map/Map.h"

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　前方宣言
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
class CMouseKingCharacter;


enum HENCHMAN_POSITION_TYPE :int
{
	NONE	= 0,
	FORWARD = 1,
	DEFENDER = 2,
};


//================================================
// 
// 敵キャラクターの基底クラスとなるクラス
//		
//================================================
class CMouseCharacter :public CEnemyCharacter {
public:
	//コンストラクタ
	CMouseCharacter(CMouseKingCharacter* pMaster, int positionType);

	//デストラクタ
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
	* @desc 攻撃命令フラグを設定
	* @param true...攻撃させる　false...攻撃させない
	*/
	void setAttackOrder(bool flag);


	/**
	* @desc 攻撃命令フラグを取得
	* @param true...攻撃させる　false...攻撃させない
	*/
	bool getAttackOrder(void);

	CMouseKingCharacter* m_pMaster = NULL;
	
	int m_positionType = (int)HENCHMAN_POSITION_TYPE::NONE;
private:
	

	bool m_attackOrder = false;
};