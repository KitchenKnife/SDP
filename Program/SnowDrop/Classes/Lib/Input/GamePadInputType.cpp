//==========================================
//
// File: GamePadInputType.cpp
//
// �Q�[���p�b�h���̓^�C�v �t�@�C��
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================


//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "GamePadInputType.h"


//==========================================
//
// Class: CGamePadInputFlag
//
// �Q�[���p�b�h�p���̓t���O �N���X
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
/**
*	@desc	�R���X�g���N�^
*/
CGamePadInputFlag::CGamePadInputFlag(void)
{
	
}

/**
*	@desc	�f�X�g���N�^
*/
CGamePadInputFlag::~CGamePadInputFlag(void)
{

}



/**
*	@desc	�l�̃N���A
*/
void CGamePadInputFlag::clear(void)
{
	this->m_dpad_up = false;	// �����p�b�h��{�^��
	this->m_dpad_down = false;	// �����p�b�h���{�^��
	this->m_dpad_left = false;	// �����p�b�h���{�^��
	this->m_dpad_right = false;	// �����p�b�h�E�{�^��
	this->m_start = false;	// START�{�^��
	this->m_back = false;	// BACK�{�^��
	this->m_left_thumb = false;	// ���X�e�B�b�N�{�^��
	this->m_right_thumb = false;	// �E�X�e�B�b�N�{�^��
	this->m_left_shoulder = false;	// LB�{�^��
	this->m_right_shoulder = false;	// RB�{�^��
	this->m_a = false;	// A�{�^��
	this->m_b = false;	// B�{�^��
	this->m_x = false;	// X�{�^��
	this->m_y = false;	// Y�{�^��
}

/**
*	@desc	�{�^���̃t���O���グ�� ( �t���O�A�b�v )
*	@param	�{�^���[�R�[�h
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
*	@desc	�{�^���̃t���O�������� ( �t���O�_�E�� )
*	@praram	�{�^���R�[�h
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
*	@desc	�w�肵���{�^����������Ă��邩�ǂ������擾
*	@param	�{�^���^�C�v
*	@return	true...������Ă���
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
*	@desc	�w�肵���L�[���g���K�[���͏�Ԃ��擾
*	@param	�{�^���^�C�v
*	@return	true...������Ă���
*	@tips	���͂̃^�C�v�ɂ���ĕω�
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