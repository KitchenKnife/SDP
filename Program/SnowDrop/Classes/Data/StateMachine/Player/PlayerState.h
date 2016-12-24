#pragma once
//==========================================
//
// File: PlayerState.h
//
// プレイヤー状態遷移 ヘッダーファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../StateMachine.h"

//==========================================
// 前方宣言
//==========================================
class CPlayerCharacterBoy;
class CGirlCharacter;

//==========================================
//
// Class: CPlayerState
//
// プレイヤー 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerState : public CStateBase
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	virtual ~CPlayerState(void);

	/**
	*	@desc 右向き待機状態へ移行
	*/
	void toIdleRight(void);

	/**
	*	@desc 左向き待機状態へ移行
	*/
	void toIdleLeft(void);

	/**
	*	@desc 右向き歩行状態へ移行
	*/
	void toWalkRight(void);

	/**
	*	@desc 左向き歩行状態へ移行
	*/
	void toWalkLeft(void);

	/**
	*	@desc 装備する状態へ移行
	*/
	void toEquip(void);

	/*
	*	@desc 装備解除状態へ移行
	*/
	void toUnEquip(void);


	/*
	*	@desc 右向き手を掴む状態へ移行
	*/
	void toGraspRight(void);


	/*
	*	@desc 左向き手を掴む状態へ移行
	*/
	void toGraspLeft(void);


protected:
	//参照するプレイヤーキャラクター
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//参照するガールキャラクター
	CGirlCharacter*		m_pGirl = NULL;
};


//==========================================
//
// Class: CPlayerIdleRightState
//
// プレイヤー 右向き　待機 状態 クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerIdleRightState :public CPlayerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	~CPlayerIdleRightState(void);

	/**
	* @desc 開始処理
	*/
	void start(void)override;
	/**
	* @desc 更新処理
	*/
	void update(void)override;

	// 状態が変わるときの処理
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerIdleLeftState
//
// プレイヤー 左向き　待機 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerIdleLeftState :public CPlayerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	~CPlayerIdleLeftState(void);

	/**
	* @desc 開始処理
	*/
	void start(void)override;
	/**
	* @desc 更新処理
	*/
	void update(void)override;

	// 状態が変わるときの処理
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerWalkRightState
//
// プレイヤー 右向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerWalkRightState :public CPlayerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	~CPlayerWalkRightState(void);

	/**
	* @desc 開始処理
	*/
	void start(void)override;
	/**
	* @desc 更新処理
	*/
	void update(void)override;

	// 状態が変わるときの処理
	void onChangeEvent(void)override;

private:
};


//==========================================
//
// Class: CPlayerWalkLeftState
//
// プレイヤー 左向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerWalkLeftState :public CPlayerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	~CPlayerWalkLeftState(void);

	/**
	* @desc 開始処理
	*/
	void start(void)override;
	/**
	* @desc 更新処理
	*/
	void update(void)override;

	// 状態が変わるときの処理
	void onChangeEvent(void)override;

private:
};

//EOF
