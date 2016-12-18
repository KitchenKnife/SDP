#pragma once
/*
* Effect.h
*
*	2016/11/25	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Data/Animation/Animation.h"
#include "Data/Move/Move.h"

#include <stdio.h>

using namespace cocos2d;
//using namespace std;

//================================================
// 
// エフェクトの基底クラス
//
//================================================
class CEffect :public Sprite {
public:

	//コンストラクタ
	CEffect(){}

	//デストラクタ
	virtual ~CEffect(){}

	//初期化処理
	virtual bool init()override;

	//更新処理
	virtual void update();

	//アニメーションデータ
    CAnimation* m_pAnimationDatas = NULL;

	//移動データ
	CMove* m_pMove = NULL;

	//有効フラグ
	bool m_activeFlag = true;

	//反映処理
	virtual void applyFunc();

protected:

	//移動処理
	virtual void moveFunc() = 0;

	//アニメーション処理
	virtual void animationFunc();

	


	//================================================
	// 
	//　ここまでにメンバに関するコードを追加
	//		
	//================================================
};
