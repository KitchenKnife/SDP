#pragma once
//==========================================
//
// File: PlayerStateGraps.h
//
// プレイヤー状態遷移 ヘッダーファイル
//		少女と手を繋いだ状態
//
// 2017/ 1/ 1
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
// Class: CPlayerState
//
// プレイヤー 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CPlayerStateGraps : public CStateBase {
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerStateGraps(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	virtual ~CPlayerStateGraps(void);

	/**
	 *	@desc	待機状態へ移行
	 */
	void toIdle(void);

	/**
	 *	@desc	歩行状態へ移行
	 */
	void toWalk(void);

	/**
	 * @desc	攻撃状態へ移行
	 */
	void toAttack(void);

	/*
	 *	@desc	手を離した状態へ移行
	 */
	void toGrasp(void);

protected:
	//参照するプレイヤーキャラクター
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//参照するガールキャラクター
	CGirlCharacter*		m_pGirl = NULL;
};




//==========================================
//
// Class: CPlayerGraspIdleState
//
// プレイヤー 手を繋ぐ 待機 状態クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CPlayerGraspIdleState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspIdleState(void);

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
// Class: CPlayerGraspWalkState
//
// プレイヤー 手を繋ぐ 歩行 状態クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerGraspWalkState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspWalkState(void);

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
// Class: CPlayerGraspAttackState
//
// プレイヤー 手を繋ぐ 攻撃 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerGraspAttackState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspAttackState(void);

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
// Class: CPlayerGraspReleaseState
//
// プレイヤー 手を繋ぐ 手を離す 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerGraspReleaseState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspReleaseState(void);

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
