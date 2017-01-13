#pragma once
/*
* MarionetteCharacter.h
*
*	2017/01/12	Shinya Ueba
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

//================================================
// 
// 敵キャラクターの基底クラスとなるクラス
//		
//================================================
class CMarionetteCharacter :public CEnemyCharacter {
public:

	//コンストラクタ
	CMarionetteCharacter();

	//デストラクタ
	virtual ~CMarionetteCharacter();

	CREATE_FUNC(CMarionetteCharacter);

};

//EOF