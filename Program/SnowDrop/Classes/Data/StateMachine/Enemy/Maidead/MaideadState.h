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
	CMaideadState(	int nextRegisterKey,
					CEnemyCharacter* const pOwner,
					CPlayerCharacterBoy* const pPlayer,
					CGirlCharacter* const pGirl);

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
	CMaideadIdleState(	int nextRegisterKey,
						CEnemyCharacter* const pOwner,
						CPlayerCharacterBoy* const pPlayer,
						CGirlCharacter* const pGirl);

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
	CMaideadWanderingState(int nextRegisterKey,
		CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

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

//EOF