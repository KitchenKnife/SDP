#pragma once
/*
* MouseKingCharacter.h
*
*	2017/01/09	Shinya Ueba
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "../EnemyCharacter.h"
#include "Model/Map/Map.h"

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　前方宣言
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
class CMouseCharacter;

//================================================
// 
// 敵キャラクターの基底クラスとなるクラス
//		
//================================================
class CMouseKingCharacter :public CEnemyCharacter {
public:
	static const int MAX_HENCHMANS = 2;

	//コンストラクタ
	CMouseKingCharacter();

	//デストラクタ
	virtual ~CMouseKingCharacter();

	CREATE_FUNC(CMouseKingCharacter);


	CMouseCharacter* m_pHenchmans[MAX_HENCHMANS];
};