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
//#include"GamePadInputType.h"
#include"InputController.h"


//==========================================
//
// Class: CGamepadInputController
//
// �Q�[���p�b�h���̓R���g���[���[�N���X
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================
class CGamepadInputController : public CInputController
{
//private:
//	//�Q�[���p�b�h�ő�ڑ���(����͂P)
//	static const int MAX_CONTROLLERS = 1;
//
//	//�Q�[���p�b�h��ԃf�[�^�Q
//	//CONTROLER_STATE m_controllers[MAX_CONTROLLERS];
//
//
//	//���͏�ԃt���O
//	CGamePadInputFlag m_inputFlag;
//
//public:
//	/**
//	* @desc �R���X�g���N�^
//	* @author Shinya Ueba
//	*/
//	CGamepadInputController(void);
//
//	/**
//	* @desc �f�X�g���N�^
//	* @author Shinya Ueba
//	*/
//	virtual ~CGamepadInputController(void);
//
//	/**
//	* @desc �X�V����
//	* @author Shinya Ueba
//	*/
//	void update(void);
//
//	/*
//	* @desc ���ړ����̓t���O�擾
//	* @return true...���͂���@false...���͂Ȃ�
//	* @author Shinya Ueba
//	*/
//	bool getLeftMoveFlag(void)override;
//
//	/*
//	* @desc �E�ړ����̓t���O�擾
//	* @return true...���͂���@false...���͂Ȃ�
//	* @author Shinya Ueba
//	*/
//	bool getRightMoveFlag(void)override;
//
//	/*
//	* @desc �W�����v���̓t���O�擾
//	* @return true...���͂���@false...���͂Ȃ�
//	* @author Shinya Ueba
//	*/
//	bool getJumpFlag(void)override;
//
//	/*
//	* @desc �U�����̓t���O�擾
//	* @return true...���͂���@false...���͂Ȃ�
//	* @author Shinya Ueba
//	*/
//	bool getAttackFlag(void)override;
//
//	/*
//	* @desc ����Ȃ��t���O�擾
//	* @return true...���͂���@false...���͂Ȃ�
//	* @author Shinya Ueba
//	*/
//	bool getHolodHandsFlag(void)override;
//
//	/*
//	* @desc ���P�l�������t���O�擾
//	* @return true...���͂���@false...���͂Ȃ�
//	* @author Shinya Ueba
//	*/
//	bool getHugFlag(void)override;

	/**
	* @desc ���̓t���O�C���X�^���X�̎擾
	* @return�@ ���̓t���O�C���X�^���X
	*/
	//CInputFlag* getInputFlagInstance(void)override;
};
//EOF