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
	return this->m_inputFlag.isKeyPressed((int)kInputType::LEFT);
}

/*
* @desc 右移動入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getRightMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::RIGHT);
}

/*
* @desc ジャンプ入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getJumpFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::UP);
}

/*
* @desc 攻撃入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getAttackFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::Z);
}

/*
* @desc 手をつなぐフラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHolodHandsFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::X);
}

/*
* @desc お姫様抱っこフラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getHugFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::C);
}

/*
* @desc	ゲーム終了フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CKeyboardInputController::getGameExitFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)kInputType::ESC);
}


/**
*	@desc デバッグモードフラグ取得
*	@return true...入力あり　false...入力なし
*/
bool CKeyboardInputController::getDebugModeFlag(void)
{
	//デバッグ用
#ifdef _DEBUG
	return this->m_inputFlag.isKeyPressed((int)kInputType::D);
#endif // DEBUG

	return false;
}



/**
* @desc 入力フラグインスタンスの取得
* @return　 入力フラグインスタンス
*/
CInputFlag* CKeyboardInputController::getInputFlagInstance(void)
{
	return &this->m_inputFlag;
}
//EOF