//==========================================
//
// File: GamePadInputType.cpp
//
// ゲームパッド入力タイプ ファイル
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "GamePadInputType.h"


//==========================================
//
// Class: CGamePadInputFlag
//
// ゲームパッド用入力フラグ クラス
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
/**
*	@desc	コンストラクタ
*/
CGamePadInputFlag::CGamePadInputFlag(void)
{
	
}

/**
*	@desc	デストラクタ
*/
CGamePadInputFlag::~CGamePadInputFlag(void)
{

}



/**
*	@desc	値のクリア
*/
void CGamePadInputFlag::clear(void)
{
	this->m_dpad_up = false;	// 方向パッド上ボタン
	this->m_dpad_down = false;	// 方向パッド下ボタン
	this->m_dpad_left = false;	// 方向パッド左ボタン
	this->m_dpad_right = false;	// 方向パッド右ボタン
	this->m_start = false;	// STARTボタン
	this->m_back = false;	// BACKボタン
	this->m_left_thumb = false;	// 左スティックボタン
	this->m_right_thumb = false;	// 右スティックボタン
	this->m_left_shoulder = false;	// LBボタン
	this->m_right_shoulder = false;	// RBボタン
	this->m_a = false;	// Aボタン
	this->m_b = false;	// Bボタン
	this->m_x = false;	// Xボタン
	this->m_y = false;	// Yボタン
}

/**
*	@desc	ボタンのフラグを上げる ( フラグアップ )
*	@param	ボタンーコード
*/
void CGamePadInputFlag::up(int bottomType_)
{
	switch ((GamePadInputType)bottomType_)
	{
	case GamePadInputType::DPAD_UP:		this->m_dpad_up = true;
										this->m_dpad_upTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_UP] ^ this->m_dpad_up & this->m_dpad_up;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_UP] = this->m_dpad_up;
										break;

	case GamePadInputType::DPAD_DOWN:	this->m_dpad_down = true;
										this->m_dpad_downTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_DOWN] ^ this->m_dpad_down & this->m_dpad_down;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_DOWN] = this->m_dpad_down;
										break;

	case GamePadInputType::DPAD_LEFT:	this->m_dpad_left = true;
										this->m_dpad_leftTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_LEFT] ^ this->m_dpad_left & this->m_dpad_left;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_LEFT] = this->m_dpad_left;
										break;

	case GamePadInputType::DPAD_RIGHT:	this->m_dpad_right = true;
										this->m_dpad_rightTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_RIGHT] ^ this->m_dpad_right & this->m_dpad_right;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_RIGHT] = this->m_dpad_right;
										break;

	case GamePadInputType::START:		this->m_start = true;
										this->m_startTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::START] ^ this->m_start & this->m_start;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::START] = this->m_start;
										break;

	case GamePadInputType::BACK:		this->m_back = true;
										this->m_backTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::BACK] ^ this->m_back & this->m_back;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::BACK] = this->m_back;
										break;

	case GamePadInputType::LEFT_THUMB:	this->m_left_thumb = true;
										this->m_left_thumbTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::LEFT_THUMB] ^ this->m_left_thumb & this->m_left_thumb;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::LEFT_THUMB] = this->m_left_thumb;
										break;

	case GamePadInputType::RIGHT_THUMB:	this->m_right_thumb = true;
										this->m_right_thumbTrigger = this->m_arrayTriggerLastSate[(int)GamePadInputType::RIGHT_THUMB] ^ this->m_right_thumb & this->m_right_thumb;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::RIGHT_THUMB] = this->m_right_thumb;
										break;

	case GamePadInputType::LEFT_SHOULDER:	this->m_left_shoulder = true;
											this->m_left_shoulder = this->m_arrayTriggerLastSate[(int)GamePadInputType::LEFT_SHOULDER] ^ this->m_left_shoulder & this->m_left_shoulder;
											this->m_arrayTriggerLastSate[(int)GamePadInputType::LEFT_SHOULDER ] = this->m_left_shoulder;
											break;

	case GamePadInputType::RIGHT_SHOULDER:	this->m_right_shoulder = true;
											this->m_right_shoulder = this->m_arrayTriggerLastSate[(int)GamePadInputType::RIGHT_SHOULDER] ^ this->m_right_shoulder & this->m_right_shoulder;
											this->m_arrayTriggerLastSate[(int)GamePadInputType::RIGHT_SHOULDER] = this->m_right_shoulder;
											break;

	case GamePadInputType::A:			this->m_a = true;
										this->m_a = this->m_arrayTriggerLastSate[(int)GamePadInputType::A] ^ this->m_a & this->m_a;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::A] = this->m_a;
										break;



	case GamePadInputType::B:			this->m_b = true;
										this->m_b = this->m_arrayTriggerLastSate[(int)GamePadInputType::B] ^ this->m_b & this->m_b;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::B] = this->m_b;
										break;

	case GamePadInputType::X:			this->m_x = true;
										this->m_x = this->m_arrayTriggerLastSate[(int)GamePadInputType::X] ^ this->m_x & this->m_x;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::X] = this->m_x;
										break;

	case GamePadInputType::Y:			this->m_y = true;
										this->m_y = this->m_arrayTriggerLastSate[(int)GamePadInputType::Y] ^ this->m_y & this->m_y;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::Y] = this->m_y;
										break;
	default:break;
	}
}

/**
*	@desc	ボタンのフラグを下げる ( フラグダウン )
*	@praram	ボタンコード
*/
void CGamePadInputFlag::down(int bottomType_)
{
	switch ((GamePadInputType)bottomType_)
	{
	case GamePadInputType::DPAD_UP:		this->m_dpad_up = false;
										this->m_dpad_upTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_UP] = false;
										break;

	case GamePadInputType::DPAD_DOWN:	this->m_dpad_down = false;
										this->m_dpad_downTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_DOWN] = false;
										break;

	case GamePadInputType::DPAD_LEFT:	this->m_dpad_left = false;
										this->m_dpad_leftTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_LEFT] = false;
										break;

	case GamePadInputType::DPAD_RIGHT:	this->m_dpad_right = false;
										this->m_dpad_rightTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::DPAD_RIGHT] = false;
										break;

	case GamePadInputType::START:		this->m_start = false;
										this->m_startTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::START] = false;
										break;

	case GamePadInputType::BACK:		this->m_back = false;
										this->m_backTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::BACK] = false;
										break;

	case GamePadInputType::LEFT_THUMB:	this->m_left_thumb = false;
										this->m_left_thumbTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::LEFT_THUMB] = false;
										break;

	case GamePadInputType::RIGHT_THUMB:	this->m_right_thumb = false;
										this->m_right_thumbTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::RIGHT_THUMB] = false;
										break;

	case GamePadInputType::LEFT_SHOULDER: this->m_left_shoulder = false;
										this->m_left_shoulderTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::LEFT_SHOULDER] = false;

										break;

	case GamePadInputType::RIGHT_SHOULDER: this->m_right_shoulder = false;
										this->m_right_shoulderTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::RIGHT_SHOULDER ] = false;
										break;

	case GamePadInputType::A:			this->m_a = false;
										this->m_aTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::A] = false;
										break;

	case GamePadInputType::B:			this->m_b = false;
										this->m_bTrigger = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::B] = false;
										break;

	case GamePadInputType::X:			this->m_x = false;
										this->m_x = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::X] = false;
										break;

	case GamePadInputType::Y:			this->m_y = false;
										this->m_y = false;
										this->m_arrayTriggerLastSate[(int)GamePadInputType::Y] = false;
										break;

	default:break;
	}
}

/**
*	@desc	指定したボタンが押されているかどうかを取得
*	@param	ボタンタイプ
*	@return	true...押されている
*/
bool CGamePadInputFlag::isKeyPressed(int bottomType_)
{
	switch ((GamePadInputType)bottomType_)
	{
	case GamePadInputType::DPAD_UP:			return this->m_dpad_up;
		break;

	case GamePadInputType::DPAD_DOWN:		return  this->m_dpad_down;
		break;

	case GamePadInputType::DPAD_LEFT:		return this->m_dpad_left;
		break;

	case GamePadInputType::DPAD_RIGHT:		return this->m_dpad_right;
		break;

	case GamePadInputType::START:			return this->m_start;
		break;

	case GamePadInputType::BACK:			return this->m_back;
		break;

	case GamePadInputType::LEFT_THUMB:		return this->m_left_thumb;
		break;

	case GamePadInputType::RIGHT_THUMB:		return this->m_right_thumb;
		break;

	case GamePadInputType::LEFT_SHOULDER:	return this->m_left_shoulder;
		break;

	case GamePadInputType::RIGHT_SHOULDER:	return this->m_right_shoulder;
		break;

	case GamePadInputType::A:				return this->m_a;
		break;

	case GamePadInputType::B:				return this->m_b;
		break;

	case GamePadInputType::X:				return this->m_x;
		break;

	case GamePadInputType::Y:				return this->m_y;
		break;

	default:break;
	}

	
	return false;
}

/**
*	@desc	指定したキーがトリガー入力状態を取得
*	@param	ボタンタイプ
*	@return	true...押されている
*	@tips	入力のタイプによって変化
*/
bool CGamePadInputFlag::isKeyTrigger(int bottomType_)
{
	switch ((GamePadInputType)bottomType_)
	{
	case GamePadInputType::DPAD_UP:			return this->m_dpad_upTrigger;
		break;

	case GamePadInputType::DPAD_DOWN:		return  this->m_dpad_downTrigger;
		break;

	case GamePadInputType::DPAD_LEFT:		return this->m_dpad_leftTrigger;
		break;

	case GamePadInputType::DPAD_RIGHT:		return this->m_dpad_rightTrigger;
		break;

	case GamePadInputType::START:			return this->m_startTrigger;
		break;

	case GamePadInputType::BACK:			return this->m_backTrigger;
		break;

	case GamePadInputType::LEFT_THUMB:		return this->m_left_thumbTrigger;
		break;

	case GamePadInputType::RIGHT_THUMB:		return this->m_right_thumbTrigger;
		break;

	case GamePadInputType::LEFT_SHOULDER:	return this->m_left_shoulderTrigger;
		break;

	case GamePadInputType::RIGHT_SHOULDER:	return this->m_right_shoulderTrigger;
		break;

	case GamePadInputType::A:				return this->m_aTrigger;
		break;

	case GamePadInputType::B:				return this->m_bTrigger;
		break;

	case GamePadInputType::X:				return this->m_xTrigger;
		break;

	case GamePadInputType::Y:				return this->m_yTrigger;
		break;

	default:break;
	}


	return false;

}
//EOF