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

//================================================
// 
// 敵キャラクターの基底クラスとなるクラス
//		
//================================================
class CMouseCharacter :public CEnemyCharacter {
public:
	//コンストラクタ
	CMouseCharacter(CMouseKingCharacter* pMaster);

	//デストラクタ
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