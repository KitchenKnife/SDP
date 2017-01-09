#pragma once
//==========================================
//
// File: NutCrackerState.h
//
// NutCracker　状態遷移 ヘッダーファイル
//
// 2017/01/09
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
// Class: CNutCrackerIdleState
//
// NutCracker  状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerState : public CEnemyState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNutCrackerState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CNutCrackerState(void);

	/**
	* @desc 待機状態へ移行
	*/
	void toIdle(void);

	/**
	* @desc 徘徊状態へ移行
	*/
	void toWandering(void);

	/**
	* @desc 追跡状態へ移行
	*/
	void toChase(void);

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
// Class: CNutCrackerIdleState
//
// NutCracker 待機 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerIdleState : public CNutCrackerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNutCrackerIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CNutCrackerIdleState(void);

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
// Class: CNutCrackerWanderingState
//
// NutCracker 徘徊 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerWanderingState : public CNutCrackerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNutCrackerWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CNutCrackerWanderingState(void);

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

	//うろうろする方向
	int m_vec = 1;
};


//==========================================
//
// Class: CNutCrackerChaseState
//
// NutCracker 追跡 状態 クラス
//
//						Author Shinya Ueba
// 2017/01/09
//==========================================
class CNutCrackerChaseState : public CNutCrackerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNutCrackerChaseState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CNutCrackerChaseState(void);

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
	CCharacter* m_pTarget = NULL;
	int m_vec = 0;
};

//==========================================
//
// Class: CNutCrackerAttackState
//
// NutCracker 攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerAttackState : public CNutCrackerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNutCrackerAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CNutCrackerAttackState(void);

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
// Class: CNutCrackerUnderAttackState
//
// NutCracker 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerUnderAttackState : public CNutCrackerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNutCrackerUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CNutCrackerUnderAttackState(void);

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
// Class: CNutCrackerDeadState
//
// NutCracker 死亡 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CNutCrackerDeadState : public CNutCrackerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CNutCrackerDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CNutCrackerDeadState(void);

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