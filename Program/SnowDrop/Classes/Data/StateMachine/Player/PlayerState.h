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
	 * @desc	コンストラクタ
	 */
	CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	virtual ~CPlayerState(void);

	/**
	 *	@desc	待機状態へ移行
	 */
	void toIdle(void);

	/**
	 *	@desc	歩行状態へ移行
	 */
	void toWalk(void);


	/**
	 *	@desc	ジャンプ状態へ移行
	 */
	void toJump(void);

	/**
 	 *	@desc	落下状態へ移行
	 */
	void toFall(void);

	/**
	 * @desc	攻撃状態へ移行
	 */
	void toAttack(void);

	/**
	 * @desc	ジャンプ攻撃へ移行
	 */
	void toJumpAttack(void);

	/**
	 * @desc	攻撃を受けた状態へ移行
	 */
	void toUnderAttack(void);

	/*
	 *	@desc	手を掴む状態へ移行
	 */
	void toGrasp(void);

	/*
	 *	@desc	お姫様抱っこ状態へ移行
	 */
	void toHold(void);

protected:
	//参照するプレイヤーキャラクター
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//参照するガールキャラクター
	CGirlCharacter*		m_pGirl = NULL;
};

//==========================================
//
// Class: CPlayerIdleState
//
// プレイヤー 待機 状態クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerIdleState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerIdleState(void);

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
// Class: CPlayerWalkState
//
// プレイヤー 歩行 状態クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerWalkState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerWalkState(void);

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
// Class: CPlayerJumpState
//
// プレイヤー ジャンプ 状態クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerJumpState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerJumpState(void);

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

	//ジャンプ中のX軸速度
	float m_velX;

private:
};

//==========================================
//
// Class: CPlayerFallState
//
// プレイヤー 落下 状態クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerFallState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerFallState(void);

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

	//ジャンプ中のX軸速度
	float m_velX;

private:
};


//==========================================
//
// Class: CPlayerAttackState
//
// プレイヤー 攻撃 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerAttackState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerAttackState(void);

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
	//連撃フラグ
	bool m_chainAttackFlag = false;

};

//==========================================
//
// Class: CPlayerJumpAttackState
//
// プレイヤー ジャンプ攻撃 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerJumpAttackState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerJumpAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerJumpAttackState(void);

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

};


//==========================================
//
// Class: CPlayerUnderAttackState
//
// プレイヤー 攻撃を受けた 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerUnderAttackState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerUnderAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerUnderAttackState(void);

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

};

//==========================================
//
// Class: CPlayerGraspState
//
// プレイヤー 手をつなぐ 状態クラス
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CPlayerGraspState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerGraspState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerGraspState(void);

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
// Class: CPlayerHoldState
//
// プレイヤー お姫様抱っこ 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldState(void);

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


//EOF