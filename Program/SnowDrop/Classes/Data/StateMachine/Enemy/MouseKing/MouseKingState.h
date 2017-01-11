#pragma once
//==========================================
//
// File: MouseKingState.h
//
// MouseKing　状態遷移 ヘッダーファイル
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
class CMouseCharacter;
//==========================================
//
// Class: CMouseKingIdleState
//
// MouseKing  状態 基底クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingState : public CEnemyState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseKingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseKingState(void);

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
// Class: CMouseKingIdleState
//
// MouseKing 待機 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingIdleState : public CMouseKingState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseKingIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseKingIdleState(void);

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
// Class: CMouseKingWanderingState
//
// MouseKing 徘徊 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingWanderingState : public CMouseKingState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseKingWanderingState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl

	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseKingWanderingState(void);

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
// Class: CMouseKingAttackState
//
// MouseKing 攻撃 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingAttackState : public CMouseKingState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseKingAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseKingAttackState(void);

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
	int m_nextAttackOrder = -1;
	CMouseCharacter* m_pOrderChara = NULL;

};

//==========================================
//
// Class: CMouseKingUnderAttackState
//
// MouseKing 攻撃を受けた 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingUnderAttackState : public CMouseKingState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseKingUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseKingUnderAttackState(void);

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
// Class: CMouseKingDeadState
//
// MouseKing 死亡 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
class CMouseKingDeadState : public CMouseKingState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMouseKingDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMouseKingDeadState(void);

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