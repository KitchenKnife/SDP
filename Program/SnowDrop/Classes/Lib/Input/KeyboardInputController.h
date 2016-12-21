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
public:
	/**
	* @desc コンストラクタ
	* @author Shinya Ueba
	*/
	CKeyboardInputController();


	/**
	* @desc デストラクタ
	* @author Shinya Ueba
	*/
	virtual ~CKeyboardInputController();

	/*
	* @desc 左移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getLeftMoveFlag()override;

	/*
	* @desc 右移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getRightMoveFlag()override;

	/*
	* @desc ジャンプ入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getJumpFlag()override;

	/*
	* @desc 攻撃入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	bool getAttackFlag()override;

	/*
	* @desc 攻撃入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getCheckFlag()override;

	/*
	* @desc セーブ入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getSaveFlag()override;
};
//EOF