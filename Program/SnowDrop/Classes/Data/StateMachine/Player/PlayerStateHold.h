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
	 * @desc	待機状態へ移行
	 */
	void toIdle(void);

	/**
	 * @desc	歩行状態へ移行
	 */
	void toWalk(void);

	/**
	 * @desc	ジャンプ状態へ移行
	 */
	void toJump(void);

	/**
	 * @desc	落下状態へ移行
	 */
	void toFall(void);

	/**
	 * @desc	お姫様抱っこ状態から通常状態へ移行
	 */
	void toFreeIdle(void);

protected:
	//参照するプレイヤーキャラクター
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//参照するガールキャラクター
	CGirlCharacter*		m_pGirl = NULL;
};



//==========================================
//
// Class: CPlayerHoldIdleState
//
// プレイヤー お姫様抱っこ 待機 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldIdleState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldIdleState(void);

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
// Class: CPlayerHoldWalkState
//
// プレイヤー お姫様抱っこ 歩行 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldWalkState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
 	 */
	~CPlayerHoldWalkState(void);

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
// Class: CPlayerHoldJumpState
//
// プレイヤー お姫様抱っこ ジャンプ 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldJumpState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldJumpState(void);

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
// Class: CPlayerHoldFallState
//
// プレイヤー お姫様抱っこ 落下 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldFallState :public CPlayerStateHold
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldFallState(void);

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
// Class: CPlayerHoldReleaseState
//
// プレイヤー お姫様抱っこ 下ろす 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldReleaseState :public CPlayerStateHold
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerHoldReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerHoldReleaseState(void);

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
