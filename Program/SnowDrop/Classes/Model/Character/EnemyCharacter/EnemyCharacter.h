
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
#include "Data/Status/Status.h"

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
	// 
	//	定数に関するコードの追加はここから
	//		
	//		
	//================================================

	//敵の状態(アニメーション管理)
	enum class STATE :int {
		STAND = 0,
		JUMPING = 0,
		WALK_RIGHT = 1,
		WALK_LEFT = 2,
		FALING = 3,
		ATTACK = 4,
		PURSUIT = 5,
		IDLE = 6,
		DAMAGE = 7,

	};

	//敵が行えるアクション
	enum class ACTION :int {
		ATTACK = 1,
		PURSUIT = 2,
		IDLE = 3,
		DAMAGE = 4,
	};

	//================================================
	// 
	// メンバーに関するコードの追加はここから
	//		
	//		
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

	void hits(CCharacter* pChara)override{}


};

