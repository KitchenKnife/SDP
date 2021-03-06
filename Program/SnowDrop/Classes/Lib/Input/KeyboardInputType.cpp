//==========================================
//
// File: KeyboardInputType.cpp
//
// キーボード入力タイプ ファイル
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"KeyboardInputType.h"
#include"cocos2d.h"

/*
*
*	キーボード入力フラグ
*
*/
/**
*	@desc コンストラクタ
*/
CKeyboardInputFlag::CKeyboardInputFlag()
{
	for (int index = 0; index < (int)kInputType::MAX_KEY_TYPE; index++)
	{
		this->m_arrayTriggerLastSate[index] = false;
	}
}



/**
*	@desc	値のクリア
*/
void CKeyboardInputFlag::clear() {
	this->m_up = false;
	this->m_down = false;
	this->m_left = false;
	this->m_right = false;
	this->m_esc = false;
	this->m_space = false;

	this->m_z = false;
	this->m_x = false;
	this->m_c = false;

	this->m_a = false;
	this->m_s = false;
	this->m_d = false;

	this->m_upTrigger	= false;
	this->m_downTrigger = false;
	this->m_leftTrigger	= false;
	this->m_rightTrigger = false;
	this->m_escTrigger = false;
	this->m_spaceTrigger = false;

	this->m_zTrigger = false;
	this->m_xTrigger = false;
	this->m_cTrigger = false;

	this->m_aTrigger = false;
	this->m_sTrigger = false;
	this->m_dTrigger = false;

	for (int index = 0; index < (int)kInputType::MAX_KEY_TYPE; index++)
	{
		this->m_arrayTriggerLastSate[index] = false;
	}
}

/**
*	@desc	キーが押されている時の反映
*	@param	キーコード
*/
void CKeyboardInputFlag::up(int keyType_) {

	switch ((kInputType)keyType_) {

	case kInputType::UP:	this->m_up = true;
							this->m_upTrigger = this->m_arrayTriggerLastSate[(int)kInputType::UP] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::UP] = this->m_up;
							break;

	case kInputType::DOWN:	this->m_down = true;
							this->m_downTrigger = this->m_arrayTriggerLastSate[(int)kInputType::DOWN] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::DOWN] = this->m_down;
							break;

	case kInputType::LEFT:	this->m_left = true;
							this->m_leftTrigger = this->m_arrayTriggerLastSate[(int)kInputType::LEFT] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::LEFT] = this->m_left;
							break;

	case kInputType::RIGHT: this->m_right = true;
							this->m_rightTrigger = this->m_arrayTriggerLastSate[(int)kInputType::RIGHT] != true ? true : false;							this->m_arrayTriggerLastSate[(int)kInputType::RIGHT] = this->m_right;
							break;

	case kInputType::ESC:	this->m_esc = true;
							this->m_rightTrigger = this->m_arrayTriggerLastSate[(int)kInputType::ESC] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::ESC] = this->m_esc;
							break;

	case kInputType::SPACE: this->m_space			= true;
							this->m_spaceTrigger	= this->m_arrayTriggerLastSate[(int)kInputType::SPACE] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::SPACE] = this->m_space;
							break;

	case kInputType::Z:		this->m_z = true;								
							this->m_zTrigger = true;
							break;

	case kInputType::X:		this->m_x = true;
							this->m_xTrigger = true;
							break;

	case kInputType::C:		this->m_c = true;
							this->m_cTrigger = this->m_arrayTriggerLastSate[(int)kInputType::C] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::C] = this->m_c;
							break;

	case kInputType::A:		this->m_a = true;
							this->m_aTrigger = this->m_arrayTriggerLastSate[(int)kInputType::A] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::A] = this->m_a;
							break;

	case kInputType::S:		this->m_s = true;
							this->m_sTrigger = this->m_arrayTriggerLastSate[(int)kInputType::S] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::S] = this->m_s;
							break;

	case kInputType::D:		this->m_d = true;
							this->m_dTrigger = this->m_arrayTriggerLastSate[(int)kInputType::D] != true ? true : false;
							this->m_arrayTriggerLastSate[(int)kInputType::D] = this->m_d;
							break;
	default: break;
	}
}
/**
*	@desc	キーが離されている時の反映
*	@param	キーコード
*/
void CKeyboardInputFlag::down(int keyType_) {
	switch ((kInputType)keyType_) {
	case kInputType::UP:	this->m_up = false;
							this->m_upTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::UP] = false;
							break;

	case kInputType::DOWN:	this->m_down = false;
							this->m_downTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::DOWN] = false;
							break;

	case kInputType::LEFT:	this->m_left = false;
							this->m_leftTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::LEFT] = false;
							break;

	case kInputType::RIGHT: this->m_right = false;
							this->m_rightTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::RIGHT] = false;
							break;

	case kInputType::ESC:	this->m_esc = false;
							this->m_escTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::ESC] = false;
							break;

	case kInputType::SPACE: this->m_space = false;
							this->m_spaceTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::SPACE] = false;
							break;

	case kInputType::Z:		this->m_z = false;
							if (this->m_arrayTriggerLastSate[(int)kInputType::Z])
							{
								this->m_zTrigger = false;
								this->m_arrayTriggerLastSate[(int)kInputType::Z] = false;
							}
							break;

	case kInputType::X:		this->m_x = false;
							if (this->m_arrayTriggerLastSate[(int)kInputType::X])
							{
								this->m_xTrigger = false;
								this->m_arrayTriggerLastSate[(int)kInputType::X] = false;
							}
							break;

	case kInputType::C:		this->m_c = false;
							this->m_cTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::C] = false;
							break;

	case kInputType::A:		this->m_a = false;
							this->m_aTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::A] = false;
							break;

	case kInputType::S:		this->m_s = false;
							this->m_sTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::S] = false;
							break;

	case kInputType::D:		this->m_d = false;
							this->m_dTrigger = false;
							this->m_arrayTriggerLastSate[(int)kInputType::D] = false;
							break;
	default: break;
	}
}

/**
*	@desc	指定したキーが押されているかどうかを取得
*	@param	キータイプ
*	@return	true...押されている
*	@tips	入力のタイプによって変化
*			キーボードタイプでは使用する必要はない
*/
bool CKeyboardInputFlag::isKeyPressed(int keyType_) {

	switch ((kInputType)keyType_) {
	case kInputType::UP: return this->m_up; break;
	case kInputType::DOWN: return this->m_down; break;
	case kInputType::LEFT: return this->m_left; break;
	case kInputType::RIGHT: return this->m_right; break;
	case kInputType::ESC: return this->m_esc; break;
	case kInputType::SPACE: return this->m_space; break;

	case kInputType::Z: return this->m_z; break;
	case kInputType::X: return this->m_x; break;
	case kInputType::C: return this->m_c; break;

	case kInputType::A: return this->m_a; break;
	case kInputType::S: return this->m_s; break;
	case kInputType::D: return this->m_d; break;

	default: break;
	}

	return false;
}

/**
*	@desc	指定したキーがトリガー入力状態を取得
*	@param	キータイプ
*	@return	true...押されている
*	@tips	入力のタイプによって変化
*/
bool CKeyboardInputFlag::isKeyTrigger(int keyType_)
{
	bool result = false;


	switch ((kInputType)keyType_) 
	{
	case kInputType::UP: return this->m_upTrigger; break;
	case kInputType::DOWN: return this->m_downTrigger; break;
	case kInputType::LEFT: return this->m_leftTrigger; break;
	case kInputType::RIGHT: return this->m_rightTrigger; break;
	case kInputType::ESC: return this->m_escTrigger; break;
	case kInputType::SPACE: return this->m_spaceTrigger; break;

	case kInputType::Z: result = this->m_arrayTriggerLastSate[(int)kInputType::Z] == false && this->m_zTrigger == true ? true : false;
						if (result)
						{
							this->m_arrayTriggerLastSate[(int)kInputType::Z] = true;
						}
						return result;

	case kInputType::X: 
						result = this->m_arrayTriggerLastSate[(int)kInputType::X] == false && this->m_xTrigger == true ? true : false;
						if (result)
						{
							this->m_arrayTriggerLastSate[(int)kInputType::X] = true;
						}
						return result;
						break;
	case kInputType::C: return this->m_cTrigger; break;

	case kInputType::A: return this->m_aTrigger; break;
	case kInputType::S: return this->m_sTrigger; break;
	case kInputType::D: return this->m_dTrigger; break;

	default: break;
	}

	return false;
}

//EOF