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
	 *	@desc	左向きジャンプ状態へ移行
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
	void toAttackFirstRight(void);

	/**
	 * @desc	右向き攻撃状態（２撃目）へ移行
	 */
	void toAttackSecondRight(void);

	/**
	 * @desc	右向き攻撃状態（３撃目）へ移行
	 */
	void toAttackThirdRight(void);

	/**
	 * @desc	左向き攻撃状態（１撃目）へ移行
	 */
	void toAttackFirstLeft(void);

	/**
	 * @desc	左向き攻撃状態（２撃目）へ移行
	 */
	void toAttackSecondLeftt(void);

	/**
	 * @desc	左向き攻撃状態（３撃目）へ移行
	 */
	void toAttackThirdLeft(void);

	/**
	 * @desc	右向きジャンプ攻撃へ移行
	 */
	void toJumpAttackRight(void);

	/**
	 * @desc	左向きジャンプ攻撃へ移行
	 */
	void toJumpAttackLeft(void);

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

	/*
	 *	@desc	右向きお姫様抱っこ状態へ移行
	 */
	void toHoldRight(void);

	/*
	 *	@desc	左向きお姫様抱っこ状態へ移行
	 */
	void toHoldLeft(void);


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
	 * @desc	コンストラクタ
	 */
	CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerIdleRightState(void);

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
	 * @desc	コンストラクタ
	 */
	CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerIdleLeftState(void);

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
	 * @desc	コンストラクタ
	 */
	CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerWalkRightState(void);

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
	 * @desc	コンストラクタ
	 */
	CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerWalkLeftState(void);

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
// Class: CPlayerJumpRightState
//
// プレイヤー 右向き　ジャンプ 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerJumpRightState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerJumpRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerJumpRightState(void);

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
// Class: CPlayerJumpLeftState
//
// プレイヤー 左向き　ジャンプ 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerJumpLeftState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerJumpLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerJumpLeftState(void);

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
// Class: CPlayerFallRightState
//
// プレイヤー 右向き　落下 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerFallRightState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerFallRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerFallRightState(void);

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
// Class: CPlayerFallLeftState
//
// プレイヤー 左向き　落下 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerFallLeftState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerFallLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerFallLeftState(void);

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
// Class: CPlayerAttackRightState
//
// プレイヤー 右向き　攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerAttackRightState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerAttackRightState(void);

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
// Class: CPlayerAttackLeftState
//
// プレイヤー 左向き　攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerAttackLeftState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerAttackLeftState(void);

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
// Class: CPlayerJumpAttackRightState
//
// プレイヤー 右向き　ジャンプ攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerJumpAttackRightState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerJumpAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerJumpAttackRightState(void);

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
// Class: CPlayerJumpAttackLeftState
//
// プレイヤー 左向き　ジャンプ攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
class CPlayerJumpAttackLeftState :public CPlayerState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CPlayerJumpAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	* @desc	デストラクタ
	*/
	~CPlayerJumpAttackLeftState(void);

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
// Class: CPlayerEquipRightState
//
// プレイヤー 右向き　装備する状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerEquipRightState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerEquipRightState(void);

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
// Class: CPlayerEquipLeftState
//
// プレイヤー 左向き　装備する 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerEquipLeftState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerEquipLeftState(void);

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
// Class: CPlayerUnEquipRightState
//
// プレイヤー 右向き　装備解除 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerUnEquipRightState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerUnEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerUnEquipRightState(void);

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
// Class: CPlayerUnEquipLeftState
//
// プレイヤー 右向き　装備解除 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
class CPlayerUnEquipLeftState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerUnEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerUnEquipLeftState(void);

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
// Class: CPlayerGraspRightState
//
// プレイヤー 右向き　手をつなぐ クラス
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CPlayerGraspRightState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerGraspRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerGraspRightState(void);

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
// Class: CPlayerGraspLeftState
//
// プレイヤー 左向き　手をつなぐ 状態 クラス
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CPlayerGraspLeftState :public CPlayerState
{
public:
	/**
	 * @desc コンストラクタ
	 */
	CPlayerGraspLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc デストラクタ
	 */
	~CPlayerGraspLeftState(void);

	/**
	 * @desc 開始処理
	 */
	void start(void)override;
	
	/**
	 * @desc 更新処理
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
// Class: CPlayerHoldRightState
//
// プレイヤー 右向き お姫様抱っこ待機 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldRightState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldRightState(void);

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
// Class: CPlayerHoldLeftState
//
// プレイヤー 左向き お姫様抱っこ待機 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
class CPlayerHoldLeftState :public CPlayerState
{
public:
	/**
	 * @desc	コンストラクタ
	 */
	CPlayerHoldLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl);

	/**
	 * @desc	デストラクタ
	 */
	~CPlayerHoldLeftState(void);

	/**
	 * @desc	開始処理
	 */
	void start(void)override;
	
	/**
	 * @desc	更新処理
	 */
	void update(void)override;

	/**
	 * @desc	状態が変わる時の処理
	 */
	void onChangeEvent(void)override;

private:
};

//EOF