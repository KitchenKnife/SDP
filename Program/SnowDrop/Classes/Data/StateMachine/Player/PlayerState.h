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

protected:
	//参照するプレイヤーキャラクター
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//参照するガールキャラクター
	CGirlCharacter*		m_pGirl = NULL;
};


//==========================================
//
// Class: CPlayerStandState
//
// プレイヤー 立ち 状態 クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStandState :public CPlayerState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CPlayerStandState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc デストラクタ
	*/
	~CPlayerStandState(void);

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
