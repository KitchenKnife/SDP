/*
 * EnemyCharacter.h
 *
 *	2016/11/11	Yamasaki 
 *
 */

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//================================================
// 
// 敵キャラクターの基底クラスとなるクラス
//		
//================================================
class CEnemyCharacter :public CCharacter {
public:
	//コンストラクタ
	CEnemyCharacter();

	//デストラクタ
	virtual ~CEnemyCharacter();

	//初期化処理
	bool init()override;

	CREATE_FUNC(CEnemyCharacter);

	//================================================
	//	キャラクタークラスのオーバーライドする関数群
	//================================================
	//移動処理
	void moveFunc() override;

	//アニメーション処理
	void animationFunc()override;

	//衝突判定処理
	void collisionAll()override;

	//状態チェック
	void checkState() override;

	//反映処理
	void applyFunc() override;

	/**
	 * @desc キャラクター1体との衝突判定処理
	 * @param キャラクターのアドレス
	 * @return true...衝突した
	 */
	bool collision(CCharacter* pChara)override;

	/**
	 * @desc	他クラスから衝突判定を受けた際の処理
	 * @param	キャラクターのアドレス
	 */
	void hits(CCharacter* pChara)override;

	//================================================
	//	定数に関するコードの追加はここから
	//================================================
	
};