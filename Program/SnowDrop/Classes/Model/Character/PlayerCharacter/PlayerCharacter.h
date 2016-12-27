
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


	/**
	* @desc 手をつなげる状態かチェック
	* @param 相方（少女）
	* @tips 手をつなげる状態なら"手つなぎフラグ"を上げる
	* @author Osumi
	* @author Shinya Ueba
	*/
	void checkHoldHands(CPlayerCharacterGirl* pGirl);


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
		//(*this->m_mapAction[(int)CPlayerCharacterBoy::PLAYER_ACTION::JUMP])[(int)CPlayerCharacterBoy::PLAYER_ACTION::JUMP]->stop();
	}

	//================================================ 
	// CPlayerCharacterBoyクラス専用メンバ
	//================================================

	/**
	 * @desc	入力処理
	 * @tips	移動処理で呼び出す
	 */
	void inputFunc();

private:
	//手をつなぐことが可能かどうか true...可能 false 無理
	bool m_enableHoldHands = false;

};