#pragma once
//==========================================
//
// File: MaideadState.h
//
// Maidead　状態遷移 ヘッダーファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../EnemyState.h"


//==========================================
//
// Class: CMaideadIdleState
//
// Maidead  状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadState : public CEnemyState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMaideadState(	CEnemyCharacter* const pOwner,
					CPlayerCharacterBoy* const pPlayer,
					CGirlCharacter* const pGirl
		);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMaideadState(void);

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
// Class: CMaideadIdleState
//
// Maidead 待機 状態 クラス
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadIdleState : public CMaideadState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMaideadIdleState(	CEnemyCharacter* const pOwner,
						CPlayerCharacterBoy* const pPlayer,
						CGirlCharacter* const pGirl
		);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMaideadIdleState(void);

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
// Class: CMaideadWanderingState
//
// Maidead 徘徊 状態 クラス
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CMaideadWanderingState : public CMaideadState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMaideadWanderingState(	CEnemyCharacter* const pOwner,
							CPlayerCharacterBoy* const pPlayer,
							CGirlCharacter* const pGirl
	
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMaideadWanderingState(void);

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
// Class: CMaideadChaseState
//
// Maidead 追跡 状態 クラス
//
//						Author Osumi
// 2016/12/27
//==========================================
class CMaideadChaseState : public CMaideadState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMaideadChaseState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMaideadChaseState(void);

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

};

//==========================================
//
// Class: CMaideadUnderAttackState
//
// Maidead 攻撃を受けた 状態 クラス
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
class CMaideadUnderAttackState : public CMaideadState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMaideadUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMaideadUnderAttackState(void);

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
// Class: CMaideadDeadState
//
// Maidead 死亡 状態 クラス
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
class CMaideadDeadState : public CMaideadState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CMaideadDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CMaideadDeadState(void);

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