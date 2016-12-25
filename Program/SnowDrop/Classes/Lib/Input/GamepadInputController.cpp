//==========================================
//
// File: GamepadInputController.cpp
//
// ゲームパッド入力コントローラー ファイル
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "GamepadInputController.h"
#include "cocos2d.h"


/**
* @desc コンストラクタ
* @author Shinya Ueba
*/
CGamepadInputController::CGamepadInputController()
{

}

/**
* @desc デストラクタ
* @author Shinya Ueba
*/
CGamepadInputController::~CGamepadInputController()
{

}


/*
* @desc 左移動入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getLeftMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::DPAD_LEFT);
}

/*
* @desc 右移動入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getRightMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::DPAD_RIGHT);
}

/*
* @desc ジャンプ入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getJumpFlag()
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::A);
}

/*
* @desc 攻撃入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getAttackFlag()
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::X);
}

/*
* @desc 装備入力フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getEquipFlag(void)
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::Y);
}

/*
* @desc 装備解除フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getUnEquipFlag(void)
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::Y);
}



/*
* @desc 手をつなぐフラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getHolodHandsFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::LEFT_SHOULDER);
}

/*
* @desc お姫様抱っこフラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getHugFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::RIGHT_SHOULDER);
}

/*
* @desc	ゲーム終了フラグ取得
* @return true...入力あり　false...入力なし
* @author Shinya Ueba
*/
bool CGamepadInputController::getGameExitFlag(void) 
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::BACK);
}

/**
*	@desc デバッグモードフラグ取得
*	@return true...入力あり　false...入力なし
*/
bool CGamepadInputController::getDebugModeFlag(void)
{

//デバッグ用
#ifdef _DEBUG
	if (this->m_inputFlag.isKeyPressed((int)GamePadInputType::LEFT_SHOULDER) &&
		this->m_inputFlag.isKeyPressed((int)GamePadInputType::RIGHT_SHOULDER))
	{
		return true;
	}
#endif // DEBUG

	return false;
}



/**
* @desc 入力フラグインスタンスの取得
* @return　 入力フラグインスタンス
*/
CInputFlag* CGamepadInputController::getInputFlagInstance(void)
{
return &this->m_inputFlag;
}

//EOF