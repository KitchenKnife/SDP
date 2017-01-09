#pragma once
//==========================================
//
// File: SmokeState.h
//
// Smoke　状態遷移 ヘッダーファイル
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../DamageState.h"

//==========================================
//
// Class: CSmokeState
//
// Smoke  状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CSmokeState : public CDamageState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CSmokeState(CDamageCharacter* const pOwner);

	/**
	* @desc デストラクタ
	*/
	virtual ~CSmokeState(void);

	/**
	* @desc 攻撃状態へ移行
	*/
	void toAttack(void);

	/**
	* @desc 死亡状態へ移行
	*/
	void toDead(void);

};

//==========================================
//
// Class: CSmokeAttackState
//
// Smoke 攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CSmokeAttackState : public CSmokeState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CSmokeAttackState(CDamageCharacter* const pOwner);

	/**
	* @desc デストラクタ
	*/
	virtual ~CSmokeAttackState(void);

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

	int m_vec = 0;
};

//==========================================
//
// Class: CSmokeDeadState
//
// Smoke 死亡 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CSmokeDeadState : public CSmokeState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CSmokeDeadState(CDamageCharacter* const pOwner);
	/**
	* @desc デストラクタ
	*/
	virtual ~CSmokeDeadState(void);

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

//EOF