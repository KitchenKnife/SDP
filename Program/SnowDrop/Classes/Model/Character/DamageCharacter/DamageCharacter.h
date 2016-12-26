/*
* DamageCharacter.h
*
*	2016/12/26	Yamasaki
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
// ダメージキャラクターの基底クラスとなるクラス
//		
//================================================
class CDamageCharacter :public CCharacter {
public:
	//コンストラクタ
	CDamageCharacter();

	//デストラクタ
	virtual ~CDamageCharacter();

	//初期化処理
	bool init()override;

	CREATE_FUNC(CDamageCharacter);

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


	// 有効フレーム数(何フレーム存在しておくか)
	int m_activeFrame;
};