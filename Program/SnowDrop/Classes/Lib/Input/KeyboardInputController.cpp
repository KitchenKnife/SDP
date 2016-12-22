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
CKeyboardInputController::CKeyboardInputController(void)
{

}

/**
* @desc デストラクタ
* @author Shinya Ueba
*/
CKeyboardInputController::~CKeyboardInputController(void)
{

}

/*
* @desc 左移動入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getLeftMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::LEFT);
}

/*
* @desc 右移動入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getRightMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::RIGHT);
}

/*
* @desc ジャンプ入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getJumpFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::UP);
}

/*
* @desc 攻撃入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getAttackFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::Z);
}

/*
* @desc 手をつなぐフラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHolodHandsFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::X);
}

/*
* @desc お姫様抱っこフラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHugFlag(void)
{
	return this->m_inputFlag.isKeyPressed(kInputType::C);
}
//EOF