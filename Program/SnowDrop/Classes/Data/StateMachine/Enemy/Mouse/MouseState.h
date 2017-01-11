#pragma once
//==========================================
//
// File: MouseState.h
//
// Mouse　状態遷移 ヘッダーファイル
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "../EnemyState.h"

//==========================================
// 前方宣言
//==========================================
class CCharacter;

//==========================================
//
// Class: CMouseIdleState
//
// Mouse  状態 基底クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseState : public CEnemyState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseState(void);

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

};

//==========================================
//
// Class: CMouseIdleState
//
// Mouse 待機 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseIdleState : public CMouseState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseIdleState(void);

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
// Class: CMouseWanderingState
//
// Mouse 徘徊 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseWanderingState : public CMouseState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseWanderingState(void);

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
	//うろうろする方向
	int m_vec = 1;
};



//==========================================
//
// Class: CMouseAttackState
//
// Mouse 攻撃 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseAttackState : public CMouseState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseAttackState(void);

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
// Class: CMouseUnderAttackState
//
// Mouse 攻撃を受けた 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseUnderAttackState : public CMouseState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseUnderAttackState(void);

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
// Class: CMouseDeadState
//
// Mouse 死亡 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseDeadState : public CMouseState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseDeadState(void);

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