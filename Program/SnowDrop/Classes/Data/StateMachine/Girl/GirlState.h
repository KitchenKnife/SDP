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
//
// Class: CGirlStandState
//
// Girl 立ち 状態 クラス
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CGirlStandState :public CStateBase
{
public:
	/**
	* @desc コンストラクタ
	*/
	CGirlStandState(int nextRegisterKey);

	/**
	* @desc デストラクタ
	*/
	~CGirlStandState();

	/**
	* @desc 開始処理
	*/
	void start()override;
	/**
	* @desc 更新処理
	*/
	void update()override;

	// 状態が変わるときの処理
	void onChangeEvent()override;

private:


};

//EOF