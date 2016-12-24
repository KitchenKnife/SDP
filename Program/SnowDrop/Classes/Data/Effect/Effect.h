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
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//================================================
// エフェクトの基底クラス
//
//	2016/12/22
//									Author Harada
//================================================
class CEffect :public CCharacter {
public:
	//================================================
	// 必須関数の列挙
	//================================================
	//コンストラクタ
	CEffect();

	//デストラクタ
	virtual ~CEffect();

	//初期化処理
	virtual bool init()override;

	CREATE_FUNC(CEffect);

	//================================================ 
	// キャラクタークラスのオーバーライドさせる関数群
	//================================================
	//移動処理
	virtual void moveFunc()override;

	//アニメーション処理
	virtual void animationFunc()override;

	//衝突判定処理
	virtual void collisionAll()override;

	//状態チェック
	virtual void checkState()override;

	//反映処理
	virtual void applyFunc()override;

	/**
	 * @desc	キャラクター1体との衝突判定処理
	 * @param	キャラクターのアドレス
	 * @return	true...衝突した
	 */
	virtual bool collision(CCharacter* pChara)override;

	/**
	 * @desc	他クラスから衝突判定を受けた際の処理
	 * @param	キャラクターのアドレス
	 */
	virtual void hits(CCharacter* pChara)override;

};