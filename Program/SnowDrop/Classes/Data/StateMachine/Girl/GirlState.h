#pragma once
//==========================================
//
// File: GirlState.h
//
// Girl状態遷移 ヘッダーファイル
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
class CPlayerCharacterGirl;

//==========================================
//
// Class: CGirlState
//
// ガール 状態 基底クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlState : public CStateBase
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	virtual ~CGirlState(void);

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

	/*
	*	@desc	右向き手を掴む状態へ移行
	*/
	void toGraspRight(void);

	/*
	*	@desc	左向き手を掴む状態へ移行
	*/
	void toGraspLeft(void);

	/*
	*	@desc	右向き手を掴みながら待機状態へ移行
	*/
	void toGraspIdleRight(void);

	/*
	*	@desc	左向き手を掴みながら待機状態へ移行
	*/
	void toGraspIdleLeft(void);

	/*
	*	@desc	右向き手を掴みながら歩く状態へ移行
	*/
	void toGraspWalkRight(void);

	/*
	*	@desc	左向き手を掴みながら歩く状態へ移行
	*/
	void toGraspWalkLeft(void);

	/**
	 * @desc	右向きお姫様抱っこ状態へ移行
	 */
	void toHoldRight(void);

	/**
	 * @desc	左向きお姫様抱っこ状態へ移行
	 */
	void toHoldLeft(void);

protected:
	CPlayerCharacterGirl* m_pGirl = NULL;
};


//==========================================
//
// Class: CGirlIdleRightState
//
// ガール 右向き　待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlIdleRightState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlIdleRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlIdleRightState(void);

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
// Class: CGirlIdleLeftState
//
// ガール 左向き　待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlIdleLeftState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlIdleLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlIdleLeftState(void);

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
// Class: CGirlGraspRightState
//
// ガール 右向き　手をつなぐ クラス
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CGirlGraspRightState :public CGirlState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CGirlGraspRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc デストラクタ
	*/
	~CGirlGraspRightState(void);

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
// Class: CGirlGraspLeftState
//
// ガール 左向き　手をつなぐ 状態 クラス
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================
class CGirlGraspLeftState :public CGirlState
{
public:
	/**
	* @desc コンストラクタ
	*/
	CGirlGraspLeftState(CPlayerCharacterGirl* const pGirl);

	/**
	* @desc デストラクタ
	*/
	~CGirlGraspLeftState(void);

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
// Class: CGirlGraspIdleRightState
//
// プレイヤー 右向き　手を繋ぐ待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspIdleRightState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlGraspIdleRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlGraspIdleRightState(void);

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
// Class: CGirlGraspIdleLeftState
//
// プレイヤー 左向き　手を繋ぐ待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspIdleLeftState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlGraspIdleLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlGraspIdleLeftState(void);

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
// Class: CGirlGraspWalkRightState
//
// プレイヤー 右向き　歩行 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspWalkRightState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlGraspWalkRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlGraspWalkRightState(void);

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
// Class: CGirlGraspWalkLeftState
//
// プレイヤー 左向き　歩行 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlGraspWalkLeftState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlGraspWalkLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlGraspWalkLeftState(void);

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
// Class: CGirlHoldIdleRightState
//
// プレイヤー 右向き　お姫様抱っこ待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlHoldIdleRightState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlHoldIdleRightState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlHoldIdleRightState(void);

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
// Class: CGirlHoldIdleLeftState
//
// プレイヤー 左向き　手を繋ぐ待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
class CGirlHoldIdleLeftState :public CGirlState
{
public:
	/**
	* @desc	コンストラクタ
	*/
	CGirlHoldIdleLeftState(CPlayerCharacterGirl* const pOwner);

	/**
	* @desc	デストラクタ
	*/
	~CGirlHoldIdleLeftState(void);

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