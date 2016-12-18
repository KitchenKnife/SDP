//==========================================
//
// File: KeyboardInputController.h
//
// 入力コントローラー基底クラス
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================



//==========================================
// ヘッダインクルード
//==========================================
#include "KeyboardInputController.h"



/**
* @desc コンストラクタ
* @author Shinya Ueba
*/
CKeyboardInputController::CKeyboardInputController()
{

}

/**
* @desc デストラクタ
* @author Shinya Ueba
*/
CKeyboardInputController::~CKeyboardInputController()
{

}

/*
* @desc 左移動入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getLeftMoveFlag()
{
	return false;
}

/*
* @desc 右移動入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getRightMoveFlag()
{
	return false;
}

/*
* @desc ジャンプ入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getJumpFlag()
{
	return false;
}

/*
* @desc 攻撃入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getAttackFlag()
{
	return false;
}

/*
* @desc 攻撃入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getCheckFlag()
{
	return false;
}

/*
* @desc セーブ入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getSaveFlag()
{
	return false;
}
//EOF