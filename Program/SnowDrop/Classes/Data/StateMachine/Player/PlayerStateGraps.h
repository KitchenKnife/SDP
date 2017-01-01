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
	 *	@desc	右向き待機状態へ移行
	 */
	void toIdleRight(void);

	/**
	 *	@desc	左向き待機状態へ移行
	 */
	void toIdleLeft(void);

	/**
	 *	@desc	右向き歩行状態へ移行
	 */
	void toWalkRight(void);

	/**
	 *	@desc	左向き歩行状態へ移行
	 */
	void toWalkLeft(void);


	/**
	 *	@desc	右向きジャンプ状態へ移行
	 */
	void toJumpRight(void);

	/**
	 *	@desc	左向き落下状態へ移行
	 */
	void toJumpLeft(void);


	/**
	 *	@desc	右向き落下状態へ移行
	 */
	void toFallRight(void);

	/**
	 *	@desc	左向き落下状態へ移行
	 */
	void toFallLeft(void);

	/**
	 * @desc	右向き攻撃状態（１撃目）へ移行
	 */
	void toAttackRight(void);

	/**
	 * @desc	左向き攻撃状態（１撃目）へ移行
	 */
	void toAttackLeft(void);

	/**
	 * @desc	右向き装備する状態へ移行
	 */
	void toEquipRight(void);

	/**
	 *	@desc	左向き装備する状態へ移行
	 */
	void toEquipLeft(void);

	/**
	 *	@desc	右向き装備を解除する状態へ移行
	 */
	void toUnEquipRight(void);

	/*
	 *	@desc	左向き装備を解除する状態へ移行
	 */
	void toUnEquipLeft(void);

	/*
	 *	@desc	右向き手を掴む状態へ移行
	 */
	void toGraspRight(void);

	/*
	 *	@desc	左向き手を掴む状態へ移行
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
// Class: CPlayerGraspIdleRightState
//
// プレイヤー 右向き　手を繋ぐ待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CPlayerGraspIdleRightState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspIdleRightState(void);

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
// Class: CPlayerGraspWalkLeftState
//
// プレイヤー 左向き　手を繋ぐ待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CPlayerGraspIdleLeftState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspIdleLeftState(void);

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
// Class: CPlayerGraspWalkRightState
//
// プレイヤー 右向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerGraspWalkRightState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspWalkRightState(void);

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
// Class: CPlayerGraspWalkLeftState
//
// プレイヤー 左向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerGraspWalkLeftState :public CPlayerStateGraps
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerGraspWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerGraspWalkLeftState(void);

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