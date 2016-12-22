#pragma once
////==========================================
////
//// File: GamepadInputController.h
////
//// �Q�[���p�b�h���̓R���g���[���[ �t�@�C��
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//
////==========================================
//// �w�b�_�C���N���[�h
////==========================================
//#include<Xinput.h>
//
////==========================================
//// ���C�u�����ǉ�
////==========================================
//#pragma comment (lib, "XInput.lib")
//
//
//
////==========================================
////
//// Struct: CONTROLLER_STATE
////
//// �Q�[���p�b�h��ԊǗ� �\����
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//
///*
//struct CONTROLER_STATE
//{
//	XINPUT_STATE state;
//	bool bConnected;
//};*/
//
//
//
////==========================================
////
//// Enum : GamePadInputType
////
//// �Q�[���p�b�h�{�^�����̓^�C�v
////
//// 2016/12/22
////						Author Shinya Ueba
////==========================================
//enum class GamePadInputType : int {
//	NONE = -1,
//	DPAD_UP = 0,	// �����p�b�h��L�[
//	DPAD_DOWN = 1,	// �����p�b�h���L�[
//	DPAD_LEFT = 2,	// �����p�b�h���L�[
//	DPAD_RIGHT = 3,	// �����p�b�h�E�L�[
//	START = 4,	// START�{�^��
//	BACK = 5,	// BACK�{�^��
//	LEFT_THUMB = 6,	// ���X�e�B�b�N�{�^��
//	RIGHT_THUMB = 7,	// �E�X�e�B�b�N�{�^��
//	LEFT_SHOULDER = 8,	// LB�{�^��
//	RIGHT_SHOULDER = 9,	// RB�{�^��
//	A = 10,	// A�{�^��
//	B = 11,	// B�{�^��
//	X = 12,	// X�{�^��
//	Y = 13,	// Y�{�^��	
//};
//
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
//class CGamePadInputFlag {
//public:
//	bool m_dpad_up = false;	// �����p�b�h��{�^��
//	bool m_dpad_down = false;	// �����p�b�h���{�^��
//	bool m_dpad_left = false;	// �����p�b�h���{�^��
//	bool m_dpad_right = false;	// �����p�b�h�E�{�^��
//	bool m_start = false;	// START�{�^��
//	bool m_back = false;	// BACK�{�^��
//	bool m_left_thumb = false;	// ���X�e�B�b�N�{�^��
//	bool m_right_thumb = false;	// �E�X�e�B�b�N�{�^��
//	bool m_left_shoulder = false;	// LB�{�^��
//	bool m_right_shoulder = false;	// RB�{�^��
//	bool m_a = false;	// A�{�^��
//	bool m_b = false;	// B�{�^��
//	bool m_x = false;	// X�{�^��
//	bool m_y = false;	// Y�{�^��
//	BYTE  m_left_trigger = 0;		// ���g���K�[
//	BYTE  m_right_trigger = 0;		// �E�g���K�[
//	SHORT m_thumb_L_X = 0;		// ���X�e�B�b�NX��
//	SHORT m_thumb_L_Y = 0;		// ���X�e�B�b�NY��
//	SHORT m_thumb_R_X = 0;		// �E�X�e�B�b�NX��
//	SHORT m_thumb_R_Y = 0;		// �E�X�e�B�b�NY��
//
//								/**
//								*	@desc	�l�̃N���A
//								*/
//	virtual void clear();
//
//	/**
//	*	@desc	�{�^���̃t���O���グ�� ( �t���O�A�b�v )
//	*	@param	�{�^���[�R�[�h
//	*/
//	virtual void up(GamePadInputType bottomType_);
//	/**
//	*	@desc	�{�^���̃t���O�������� ( �t���O�_�E�� )
//	*	@praram	�{�^���R�[�h
//	*/
//	virtual void down(GamePadInputType bottomType_);
//
//	/**
//	*	@desc	�w�肵���{�^����������Ă��邩�ǂ������擾
//	*	@param	�{�^���^�C�v
//	*	@return	true...������Ă���
//	*/
//	virtual bool isBottomPressed(GamePadInputType bottomType_);
//};
//EOF