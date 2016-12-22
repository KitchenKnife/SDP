////==========================================
////
//// File: GamePadInputType.cpp
////
//// �Q�[���p�b�h���̓^�C�v �t�@�C��
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//
//
////==========================================
//// �w�b�_�C���N���[�h
////==========================================
//#include "GamepadInputController.h"
//
//
////==========================================
////
//// Class: CGamePadInputFlag
////
//// �Q�[���p�b�h�p���̓t���O �N���X
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
///**
//*	@desc	�l�̃N���A
//*/
//void CGamePadInputFlag::clear()
//{
//	this.m_dpad_up = false;	// �����p�b�h��{�^��
//	this.m_dpad_down = false;	// �����p�b�h���{�^��
//	this.m_dpad_left = false;	// �����p�b�h���{�^��
//	this.m_dpad_right = false;	// �����p�b�h�E�{�^��
//	this.m_start = false;	// START�{�^��
//	this.m_back = false;	// BACK�{�^��
//	this.m_left_thumb = false;	// ���X�e�B�b�N�{�^��
//	this.m_right_thumb = false;	// �E�X�e�B�b�N�{�^��
//	this.m_left_shoulder = false;	// LB�{�^��
//	this.m_right_shoulder = false;	// RB�{�^��
//	this.m_a = false;	// A�{�^��
//	this.m_b = false;	// B�{�^��
//	this.m_x = false;	// X�{�^��
//	this.m_y = false;	// Y�{�^��
//}
//
///**
//*	@desc	�{�^���̃t���O���グ�� ( �t���O�A�b�v )
//*	@param	�{�^���[�R�[�h
//*/
//void CGamePadInputFlag::up(GamePadInputType bottomType_)
//{
//	switch (bottomType_)
//	{
//	case GamePadInputType::DPAD_UP:		this.m_dpad_up = true;
//		break;
//
//	case GamePadInputType::DPAD_DOWN:	this.m_dpad_down = true;
//		break;
//
//	case GamePadInputType::DPAD_LEFT:	this.m_dpad_left = true;
//		break;
//
//	case GamePadInputType::DPAD_RIGHT:	this.m_dpad_right = true;
//		break;
//
//	case GamePadInputType::START:		this.m_start = true;
//		break;
//
//	case GamePadInputType::BACK:		this.m_back = true;
//		break;
//
//	case GamePadInputType::LEFT_THUMB:	this.m_left_thumb = true;
//		break;
//
//	case GamePadInputType::RIGHT_THUMB:	this.m_right_thumb = true;
//		break;
//
//	case GamePadInputType::LEFT_SHOULDER: this.m_left_shoulder = true;
//		break;
//
//	case GamePadInputType::RIGHT_SHOULDER: this.m_right_shoulder = true;
//		break;
//
//	case GamePadInputType::A:			this.m_a = true;
//		break;
//
//	case GamePadInputType::B:			this.m_b = true;
//		break;
//
//	case GamePadInputType::X:			this.m_x = true;
//		break;
//
//	case GamePadInputType::Y:			this.m_y = true;
//		break;
//
//	default:break;
//	}
//}
//
///**
//*	@desc	�{�^���̃t���O�������� ( �t���O�_�E�� )
//*	@praram	�{�^���R�[�h
//*/
//void CGamePadInputFlag::down(GamePadInputType bottomType_)
//{
//	switch (bottomType_)
//	{
//	case GamePadInputType::DPAD_UP:		this.m_dpad_up = false;
//		break;
//
//	case GamePadInputType::DPAD_DOWN:	this.m_dpad_down = false;
//		break;
//
//	case GamePadInputType::DPAD_LEFT:	this.m_dpad_left = false;
//		break;
//
//	case GamePadInputType::DPAD_RIGHT:	this.m_dpad_right = false;
//		break;
//
//	case GamePadInputType::START:		this.m_start = false;
//		break;
//
//	case GamePadInputType::BACK:		this.m_back = false;
//		break;
//
//	case GamePadInputType::LEFT_THUMB:	this.m_left_thumb = false;
//		break;
//
//	case GamePadInputType::RIGHT_THUMB:	this.m_right_thumb = false;
//		break;
//
//	case GamePadInputType::LEFT_SHOULDER: this.m_left_shoulder = false;
//		break;
//
//	case GamePadInputType::RIGHT_SHOULDER: this.m_right_shoulder = false;
//		break;
//
//	case GamePadInputType::A:			this.m_a = false;
//		break;
//
//	case GamePadInputType::B:			this.m_b = false;
//		break;
//
//	case GamePadInputType::X:			this.m_x = false;
//		break;
//
//	case GamePadInputType::Y:			this.m_y = false;
//		break;
//
//	default:break;
//	}
//}
//
///**
//*	@desc	�w�肵���{�^����������Ă��邩�ǂ������擾
//*	@param	�{�^���^�C�v
//*	@return	true...������Ă���
//*/
//bool CGamePadInputFlag::isBottomPressed(GamePadInputType bottomType_)
//{
//	switch (bottomType_)
//	{
//	case GamePadInputType::DPAD_UP:			return this.m_dpad_up;
//		break;
//
//	case GamePadInputType::DPAD_DOWN:		return  this.m_dpad_down;
//		break;
//
//	case GamePadInputType::DPAD_LEFT:		return this.m_dpad_left;
//		break;
//
//	case GamePadInputType::DPAD_RIGHT:		return this.m_dpad_right;
//		break;
//
//	case GamePadInputType::START:			return this.m_start;
//		break;
//
//	case GamePadInputType::BACK:			return this.m_back;
//		break;
//
//	case GamePadInputType::LEFT_THUMB:		return this.m_left_thumb;
//		break;
//
//	case GamePadInputType::RIGHT_THUMB:		return this.m_right_thumb;
//		break;
//
//	case GamePadInputType::LEFT_SHOULDER:	return this.m_left_shoulder;
//		break;
//
//	case GamePadInputType::RIGHT_SHOULDER:	return this.m_right_shoulder;
//		break;
//
//	case GamePadInputType::A:				return this.m_a;
//		break;
//
//	case GamePadInputType::B:				return this.m_b;
//		break;
//
//	case GamePadInputType::X:				return this.m_x;
//		break;
//
//	case GamePadInputType::Y:				return this.m_y;
//		break;
//
//	default:break;
//	}
//
//	
//	return false;
//}
////EOF