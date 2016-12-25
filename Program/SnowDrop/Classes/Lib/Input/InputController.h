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
#include "InputFlag.h"


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
	CInputController(void);


	/**
	* @desc デストラクタ
	* @author Shinya Ueba
	*/
	virtual ~CInputController(void);
	
	/*
	* @desc 左移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getLeftMoveFlag(void) = 0;

	/*
	* @desc 右移動入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getRightMoveFlag(void) = 0;
	
	/*
	* @desc ジャンプ入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getJumpFlag(void) = 0;

	/*
	* @desc 攻撃入力フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getAttackFlag(void) = 0;

	/*
	* @desc 手をつなぐフラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getHolodHandsFlag(void) = 0;

	/*
	* @desc お姫様抱っこフラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getHugFlag(void) = 0;


	/*
	* @desc	ゲーム終了フラグ取得
	* @return true...入力あり　false...入力なし
	* @author Shinya Ueba
	*/
	virtual bool getGameExitFlag(void) = 0;

	/**
	*	@desc デバッグモードフラグ取得
	*	@return true...入力あり　false...入力なし
	*/
	virtual bool getDebugModeFlag(void) = 0;

	/**
	* @desc 入力フラグインスタンスの取得
	* @return　 入力フラグインスタンス
	*/
	virtual CInputFlag* getInputFlagInstance(void) = 0;


};
//EOF