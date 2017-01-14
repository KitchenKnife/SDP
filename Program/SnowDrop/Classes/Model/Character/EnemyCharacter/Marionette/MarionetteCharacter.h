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
	enum IDLE_POSITION :int
	{
		RIGHT		= 0,
		CENTER		= 1,
		LEFT		= 2,
		MAX_IDLE_POSITION
	};


	//コンストラクタ
	CMarionetteCharacter();

	//デストラクタ
	virtual ~CMarionetteCharacter();

	CREATE_FUNC(CMarionetteCharacter);

	//待機する位置番号
	int m_numIdlePosition = 0;
};

//EOF