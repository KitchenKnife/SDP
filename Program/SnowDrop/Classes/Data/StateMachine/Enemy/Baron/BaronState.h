#pragma once
//==========================================
//
// File: BaronState.h
//
// Baron　状態遷移 ヘッダーファイル
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
// Class: CBaronIdleState
//
// Baron  状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronState : public CEnemyState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBaronState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CBaronState(void);

	/**
	* @desc 待機状態へ移行
	*/
	void toIdle(void);

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
// Class: CBaronIdleState
//
// Baron 待機 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronIdleState : public CBaronState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBaronIdleState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CBaronIdleState(void);

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
// Class: CBaronAttackState
//
// Baron 攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronAttackState : public CBaronState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBaronAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl
	);

	/**
	* @desc デストラクタ
	*/
	virtual ~CBaronAttackState(void);

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
// Class: CBaronUnderAttackState
//
// Baron 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronUnderAttackState : public CBaronState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBaronUnderAttackState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CBaronUnderAttackState(void);

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
// Class: CBaronDeadState
//
// Baron 死亡 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CBaronDeadState : public CBaronState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CBaronDeadState(CEnemyCharacter* const pOwner,
		CPlayerCharacterBoy* const pPlayer,
		CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CBaronDeadState(void);

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