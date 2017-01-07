#pragma once
//==========================================
//
// File: PlayerStateGraps.h
//
// プレイヤー状態遷移 ヘッダーファイル
//		少女と手を繋いだ状態
//
// 2017/ 1/ 5
//						Author Harada
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
// Class: CPlayerStateHold
//
// プレイヤー お姫様抱っこ　状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateHold : public CStateBase {
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerStateHold(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	virtual ~CPlayerStateHold(void);

	/**
	 * @desc	右向き待機状態へ移行
	 */
	void toIdleRight(void);

	/**
	 * @desc	左向き待機状態へ移行
	 */
	void toIdleLeft(void);

	/**
	 * @desc	右向き歩行状態へ移行
	 */
	void toWalkRight(void);

	/**
	 * @desc	左向き歩行状態へ移行
	 */
	void toWalkLeft(void);

	/**
	 * @desc	右向きジャンプ状態へ移行
	 */
	void toJumpRight(void);

	/**
	 * @desc	左向きジャンプ状態へ移行
	 */
	void toJumpLeft(void);

	/**
	 * @desc	右向き落下状態へ移行
	 */
	void toFallRight(void);

	/**
	 * @desc	左向き落下状態へ移行
	 */
	void toFallLeft(void);

	/**
	 * @desc	お姫様抱っこ状態から通常状態へ移行（右向き）
	 */
	void toFreeIdleRight(void);

	/**
	 * @desc	お姫様抱っこ状態から通常状態へ移行（左向き）
	 */
	void toFreeIdleLeft(void);

protected:
	//参照するプレイヤーキャラクター
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//参照するガールキャラクター
	CGirlCharacter*		m_pGirl = NULL;
};



//==========================================
//
// Class: CPlayerHoldIdleRightState
//
// プレイヤー お姫様抱っこ 待機 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldIdleRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldIdleRightState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldIdleLeftState
//
// プレイヤー お姫様抱っこ 待機 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldIdleLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldIdleLeftState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldWalkRightState
//
// プレイヤー お姫様抱っこ 歩行 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldWalkRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
 	 */
	~CPlayerHoldWalkRightState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldWalkLeftState
//
// プレイヤー お姫様抱っこ 歩行 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldWalkLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldWalkLeftState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:
};

//==========================================
//
// Class: CPlayerHoldJumpRightState
//
// プレイヤー お姫様抱っこ ジャンプ 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldJumpRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldJumpRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldJumpRightState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:

	//ジャンプ中のX軸速度
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldJumpLeftState
//
// プレイヤー お姫様抱っこ ジャンプ 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldJumpLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldJumpLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldJumpLeftState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:
	//ジャンプ中のX軸速度
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldFallRightState
//
// プレイヤー お姫様抱っこ 落下 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldFallRightState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldFallRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldFallRightState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:
	//ジャンプ中のX軸速度
	float m_velX;
};

//==========================================
//
// Class: CPlayerHoldFallLeftState
//
// プレイヤー お姫様抱っこ 落下 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldFallLeftState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldFallLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldFallLeftState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;

	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わるときの処理
	 */
	void onChangeEvent(void)override;

private:
	//ジャンプ中のX軸速度
	float m_velX;
};