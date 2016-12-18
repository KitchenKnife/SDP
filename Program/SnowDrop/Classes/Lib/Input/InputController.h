#pragma once
//==========================================
//
// File: InputController.h
//
// 入力コントローラー基底クラス
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================



//==========================================
//
// Class: CInputController
//
// 入力コントローラー基底クラス
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CInputController
{
public:
	/**
	* @desc コンストラクタ
	* @author Shinya Ueba
	*/
	CInputController();


	/**
	* @desc デストラクタ
	* @author Shinya Ueba
	*/
	virtual ~CInputController();
	
	/*
	* @desc 左移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getLeftMoveFlag() = 0;

	/*
	* @desc 右移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getRightMoveFlag() = 0;
	
	/*
	* @desc ジャンプ入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getJumpFlag() = 0;

	/*
	* @desc 攻撃入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getAttackFlag() = 0;

	/*
	* @desc 攻撃入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getCheckFlag() = 0;

	/*
	* @desc セーブ入力フラグ取得 
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getSaveFlag() = 0;
};
//EOF