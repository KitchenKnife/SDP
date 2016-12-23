
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

	/**
	*	@desc 継承キャラクター個別の更新処理
	*	@author Shinya Ueba
	*/
	virtual void updatePersonal(void)override;

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
	// イベントコールバック専用関数の列挙	
	//================================================
	/**
	 * @desc	下領域と衝突した際のイベントコールバック
	 * @param	マップチップID
	 *			画面下の際は0
	 */
	virtual void collisionBottomCallback(int event)override {
		//ジャンプを停止させる。
		(*this->m_pActions)[(int)CPlayerCharacterBoy::PLAYER_ACTION::JUMP]->stop();
	}

	//================================================ 
	// CPlayerCharacterBoyクラス専用メンバ
	//================================================
	//プレイヤーのアニメーションの状態
	enum class PLAYER_STATE : int {
		STAND		= 0,	//待機
		JUMP		= 0,	//ジャンプ
		FALLING		= 0,	//落下
		WALK_LEFT	= 1,	//左歩行
		WALK_RIGHT	= 2,	//右歩行
	};

	//現在のプレイヤーの状態
	int m_playerState;

	//プレイヤーの行動
	enum class PLAYER_ACTION : int {
		JUMP		= 0,	//ジャンプ
	};

	/**
	 * @desc	入力処理
	 * @tips	移動処理で呼び出す
	 */
	void inputFunc();

};