#pragma once
//==========================================
//
// File: ActionIdle.h
//
// アクション　待機 ヘッダーファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../Action.h"


//==========================================
//
// Class: ActionIdle
//
// アクション　待機		クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CActionIdle : public CAction
{
private:
	//アクション中かどうかのフラグ true...アクション中
	bool m_inAction = false;

public:

	/**
	* @desc コンストラクタ
	*/
	CActionIdle();

	/**
	* @desc アクション開始
	*/
	void start(void)override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop(void)override;
};

//==========================================
//
// Class: ActionMove
//
// アクション　移動		クラス
//
// 2017/01/12
//						Author Harada
//==========================================
class CActionMove : public CAction
{
private:
	//アクション中かどうかのフラグ true...アクション中
	bool m_inAction = false;

public:

	/**
	* @desc コンストラクタ
	*/
	CActionMove();

	/**
	* @desc アクション開始
	*/
	void start(void)override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop(void)override;
};


//==========================================
//
// Class: CActionPlayerAttack
//
// アクション　プレイヤー攻撃		クラス
//
// 2017/01/12
//						Author Harada
//==========================================
class CActionPlayerAttack : public CAction
{
private:
	//アクション中かどうかのフラグ true...アクション中
	bool m_inAction = false;

public:

	/**
	* @desc コンストラクタ
	*/
	CActionPlayerAttack();

	/**
	* @desc アクション開始
	*/
	void start(void)override;

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop(void)override;
};


//==========================================
//
// Class: CActionPlayerJumpAttack
//
// アクション　プレイヤージャンプ攻撃		クラス
//
// 2017/01/12
//						Author Harada
//==========================================
class CActionPlayerJumpAttack : public CAction
{
private:
	//アクション中かどうかのフラグ true...アクション中
	bool m_inAction = false;

public:

	/**
	* @desc コンストラクタ
	*/
	CActionPlayerJumpAttack(){}

	/**
	* @desc アクション開始
	*/
	void start(void)override{}

	/**
	* @desc 更新処理
	* @param アクションを行う対象のキャラクター
	*/
	void update(CCharacter* pChara)override;

	/**
	* @desc アクション終了
	*/
	void stop(void)override{}
};
//EOF
