#pragma once
//==========================================
//
// File: GamepadInputController.h
//
// �Q�[���p�b�h���̓R���g���[���[ �t�@�C��
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"cocos2d.h"
#include<Xinput.h>
#include"InputFlag.h"

//==========================================
// ���C�u�����ǉ�
//==========================================
#pragma comment (lib, "Xinput.lib")


//==========================================
//
// Enum : GamePadInputType
//
// �Q�[���p�b�h�{�^�����̓^�C�v
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
enum class GamePadInputType : int {
	NONE = -1,
	DPAD_UP = 0,	// �����p�b�h��L�[
	DPAD_DOWN = 1,	// �����p�b�h���L�[
	DPAD_LEFT = 2,	// �����p�b�h���L�[
	DPAD_RIGHT = 3,	// �����p�b�h�E�L�[
	START = 4,	// START�{�^��
	BACK = 5,	// BACK�{�^��
	LEFT_THUMB = 6,	// ���X�e�B�b�N�{�^��
	RIGHT_THUMB = 7,	// �E�X�e�B�b�N�{�^��
	LEFT_SHOULDER = 8,	// LB�{�^��
	RIGHT_SHOULDER = 9,	// RB�{�^��
	A = 10,	// A�{�^��
	B = 11,	// B�{�^��
	X = 12,	// X�{�^��
	Y = 13,	// Y�{�^��
	MAX_INPUT_TYPE
};



//==========================================
//
// Class: CGamePadInputFlag
//
// �Q�[���p�b�h�p���̓t���O �N���X
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
class CGamePadInputFlag : public CInputFlag
{
public:

	//�v���X����
	bool m_dpad_up = false;			// �����p�b�h��{�^��
	bool m_dpad_down = false;		// �����p�b�h���{�^��
	bool m_dpad_left = false;		// �����p�b�h���{�^��
	bool m_dpad_right = false;		// �����p�b�h�E�{�^��
	bool m_start = false;			// START�{�^��
	bool m_back = false;			// BACK�{�^��
	bool m_left_thumb = false;		// ���X�e�B�b�N�{�^��
	bool m_right_thumb = false;		// �E�X�e�B�b�N�{�^��
	bool m_left_shoulder = false;	// LB�{�^��
	bool m_right_shoulder = false;	// RB�{�^��
	bool m_a = false;				// A�{�^��
	bool m_b = false;				// B�{�^��
	bool m_x = false;				// X�{�^��
	bool m_y = false;				// Y�{�^��
	
	//�g���K�[����
	bool m_dpad_upTrigger		= false;	// �����p�b�h��{�^��
	bool m_dpad_downTrigger		= false;	// �����p�b�h���{�^��
	bool m_dpad_leftTrigger		= false;	// �����p�b�h���{�^��
	bool m_dpad_rightTrigger	= false;	// �����p�b�h�E�{�^��
	bool m_startTrigger			= false;	// START�{�^��
	bool m_backTrigger			= false;	// BACK�{�^��
	bool m_left_thumbTrigger	= false;	// ���X�e�B�b�N�{�^��
	bool m_right_thumbTrigger	= false;	// �E�X�e�B�b�N�{�^��
	bool m_left_shoulderTrigger = false;	// LB�{�^��
	bool m_right_shoulderTrigger = false;	// RB�{�^��
	bool m_aTrigger				= false;	// A�{�^��
	bool m_bTrigger				= false;	// B�{�^��
	bool m_xTrigger				= false;	// X�{�^��
	bool m_yTrigger				= false;	// Y�{�^��



	//�A�i���O����
	BYTE  m_left_trigger = 0;		// ���g���K�[
	BYTE  m_right_trigger = 0;		// �E�g���K�[
	SHORT m_thumb_L_X = 0;			// ���X�e�B�b�NX��
	SHORT m_thumb_L_Y = 0;			// ���X�e�B�b�NY��
	SHORT m_thumb_R_X = 0;			// �E�X�e�B�b�NX��
	SHORT m_thumb_R_Y = 0;			// �E�X�e�B�b�NY��

private:

	bool m_arrayTriggerLastSate[(int)GamePadInputType::MAX_INPUT_TYPE];
public:

	/**
	*	@desc	�R���X�g���N�^
	*/
	CGamePadInputFlag(void);

	/**
	*	@desc	�f�X�g���N�^
	*/
	~CGamePadInputFlag(void);

	/**
	*	@desc	�l�̃N���A
	*/
	void clear(void)override;

	/**
	*	@desc	�{�^���̃t���O���グ�� ( �t���O�A�b�v )
	*	@param	�{�^���[�R�[�h
	*/
	void up(int bottomType_)override;
	/**
	*	@desc	�{�^���̃t���O�������� ( �t���O�_�E�� )
	*	@praram	�{�^���R�[�h
	*/
	void down(int bottomType_)override;

	/**
	*	@desc	�w�肵���{�^����������Ă��邩�ǂ������擾
	*	@param	�{�^���^�C�v
	*	@return	true...������Ă���
	*/
	bool isKeyPressed(int bottomType_)override;

	/**
	*	@desc	�w�肵���L�[���g���K�[���͏�Ԃ��擾
	*	@param	�{�^���^�C�v
	*	@return	true...������Ă���
	*	@tips	���͂̃^�C�v�ɂ���ĕω�
	*/
	bool isKeyTrigger(int bottomType_) override;
};
//EOF