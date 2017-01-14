#pragma once
//==========================================
//
// File: MarionetteState.h
//
// Marionette　状態遷移 ヘッダーファイル
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "../EnemyState.h"
#include "cocos2d.h"

//==========================================
// 前方宣言
//==========================================

//==========================================
//
// Class: CMarionetteIdleState
//
// Marionette  状態 基底クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteState : public CEnemyState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMarionetteState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMarionetteState(void);

	/**
	* @desc 待機状態へ移行
	*/
	void toIdle(void);

	/**
	* @desc 徘徊状態へ移行
	*/
	void toWandering(void);

	/**
	* @desc 攻撃状態へ移行
	*/
	void toAttack(void);

	/**
	* @desc 攻撃を受けている状態へ移行
	*/
	void toUnderAttack(void);


	/**
	* @desc 死亡状態へ移行
	*/
	void toDead(void);


	/**
	* @desc 攻撃できる取得
	* @return true...できる false...出来ない
	*/
	bool checkEnableAttack(void);

};

//==========================================
//
// Class: CMarionetteIdleState
//
// Marionette 待機 状態 クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteIdleState : public CMarionetteState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMarionetteIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMarionetteIdleState(void);

	/**
	* @desc	開始処理
	*/
	void start(void);

	/**
	* @desc 更新処理
	*/
	void update(void);

	/**
	* @desc 状態が変わるときの処理
	*/
	void onChangeEvent(void);

private:
	//アクションを行う時間（ランダムで30～60で設定される）
	int m_actionInterval = 45;

	int m_actionCounter = 0;
};

//==========================================
//
// Class: CMarionetteWanderingState
//
// Marionette 徘徊 状態 クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteWanderingState : public CMarionetteState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMarionetteWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMarionetteWanderingState(void);

	/**
	* @desc	開始処理
	*/
	void start(void);

	/**
	* @desc 更新処理
	*/
	void update(void);

	/**
	* @desc 状態が変わるときの処理
	*/
	void onChangeEvent(void);

private:
	cocos2d::Vec2 m_targetPositions[3];

	//うろうろする方向
	int m_vec = 1;
};



//==========================================
//
// Class: CMarionetteAttackState
//
// Marionette 攻撃 状態 クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteAttackState : public CMarionetteState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMarionetteAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMarionetteAttackState(void);

	/**
	* @desc	開始処理
	*/
	void start(void);

	/**
	* @desc 更新処理
	*/
	void update(void);

	/**
	* @desc 状態が変わるときの処理
	*/
	void onChangeEvent(void);

private:
};

//==========================================
//
// Class: CMarionetteUnderAttackState
//
// Marionette 攻撃を受けた 状態 クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteUnderAttackState : public CMarionetteState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMarionetteUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMarionetteUnderAttackState(void);

	/**
	* @desc	開始処理
	*/
	void start(void);

	/**
	* @desc 更新処理
	*/
	void update(void);

	/**
	* @desc 状態が変わるときの処理
	*/
	void onChangeEvent(void);

private:
	//吹っ飛ぶ方向
	int m_vec = 1;
};


//==========================================
//
// Class: CMarionetteDeadState
//
// Marionette 死亡 状態 クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
class CMarionetteDeadState : public CMarionetteState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMarionetteDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMarionetteDeadState(void);

	/**
	* @desc	開始処理
	*/
	void start(void);

	/**
	* @desc 更新処理
	*/
	void update(void);

	/**
	* @desc 状態が変わるときの処理
	*/
	void onChangeEvent(void);

private:
	//アクションを行う時間（ランダムで30～60で設定される）
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//消滅するまでのカウンター
	int m_disappearanceCounter = 0;
};
//EOF