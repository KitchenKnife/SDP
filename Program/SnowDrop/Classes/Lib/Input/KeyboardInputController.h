#pragma once
//==========================================
//
// File: KeyboardInputController.h
//
// キーボード入力コントローラー ファイル
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "InputController.h"
#include "KeyboardInputType.h"



//==========================================
//
// Class: CKeyboardInputController
//
// キーボード入力コントローラークラス
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CKeyboardInputController : public CInputController
{
private:
	//キーボード入力フラグ
	CKeyboardInputFlag m_inputFlag;

public:
	/**
	* @desc コンストラクタ
	* @author Shinya Ueba
	*/
	CKeyboardInputController(void);


	/**
	* @desc デストラクタ
	* @author Shinya Ueba
	*/
	virtual ~CKeyboardInputController(void);

	/*
	* @desc 左移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getLeftMoveFlag(void)override;

	/*
	* @desc 右移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getRightMoveFlag(void)override;

	/*
	* @desc ジャンプ入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getJumpFlag(void)override;

	/*
	* @desc 攻撃入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getAttackFlag(void)override;

	/*
	* @desc 手をつなぐフラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getHolodHandsFlag(void)override;

	/*
	* @desc お姫様抱っこフラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getHugFlag(void)override;
};
//EOF