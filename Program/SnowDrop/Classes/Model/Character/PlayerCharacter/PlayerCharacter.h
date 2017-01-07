
/*
* PlayerCharacter.h
*
*	2016/11/24	Osumi
*
*/

#pragma once
//================================================
//　追加のインクルードはここから
//================================================
#include "Model/Character/Character.h"


//================================================
//　前方宣言
//================================================
class CPlayerCharacterGirl;

//================================================
// 少年クラス
//
//	2016/12/22
//									Author Harada
//================================================
class CPlayerCharacterBoy :public CCharacter {
public:
	//================================================ 
	// 必須関数の列挙	
	//================================================
	//コンストラクタ
	CPlayerCharacterBoy();

	//デストラクタ
	~CPlayerCharacterBoy();

	CREATE_FUNC(CPlayerCharacterBoy);

	//初期化処理
	bool init()override;

	//================================================ 
	// キャラクタークラスのオーバーライドさせる関数群
	//================================================

	//移動処理
	virtual void moveFunc();

	//アニメーション処理
	virtual void animationFunc();

	//衝突判定処理
	virtual void collisionAll();

	//状態チェック
	virtual void checkState();

	//反映処理
	virtual void applyFunc();

	/**
	 * @desc	キャラクター1体との衝突判定処理
	 * @param	キャラクターのアドレス
	 * @return	true...衝突した
	 */
	virtual bool collision(CCharacter* pChara);

	/**
	 * @desc	他クラスから衝突判定を受けた際の処理
	 * @param	キャラクターのアドレス
	 */
	virtual void hits(CCharacter* pChara);

	//================================================ 
	// CPlayerCharacterBoyクラス専用メンバ
	//================================================

	//プレイヤー専用のステートマシーンデータ群
	std::map<int, CStateMachine*>* m_pStateMachines = NULL;

	//プレイヤーと少女の状態
	int m_playerAndGirlState = 0;


private:
};