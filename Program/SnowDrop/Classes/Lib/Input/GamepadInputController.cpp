//==========================================
//
// File: GamepadInputController.cpp
//
// �Q�[���p�b�h���̓R���g���[���[ �t�@�C��
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "GamepadInputController.h"
#include "cocos2d.h"


/**
* @desc �R���X�g���N�^
* @author Shinya Ueba
*/
CGamepadInputController::CGamepadInputController()
{

}

/**
* @desc �f�X�g���N�^
* @author Shinya Ueba
*/
CGamepadInputController::~CGamepadInputController()
{

}


/*
* @desc ���ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getLeftMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::DPAD_LEFT);
}

/*
* @desc �E�ړ����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getRightMoveFlag(void)
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::DPAD_RIGHT);
}

/*
* @desc �W�����v���̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getJumpFlag()
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::A);
}

/*
* @desc �U�����̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getAttackFlag()
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::X);
}

/*
* @desc �������̓t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getEquipFlag(void)
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::Y);
}

/*
* @desc ���������t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getUnEquipFlag(void)
{
	return this->m_inputFlag.isKeyTrigger((int)GamePadInputType::Y);
}



/*
* @desc ����Ȃ��t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getHolodHandsFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::LEFT_SHOULDER);
}

/*
* @desc ���P�l�������t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getHugFlag()
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::RIGHT_SHOULDER);
}

/*
* @desc	�Q�[���I���t���O�擾
* @return true...���͂���@false...���͂Ȃ�
* @author Shinya Ueba
*/
bool CGamepadInputController::getGameExitFlag(void) 
{
	return this->m_inputFlag.isKeyPressed((int)GamePadInputType::BACK);
}

/**
*	@desc �f�o�b�O���[�h�t���O�擾
*	@return true...���͂���@false...���͂Ȃ�
*/
bool CGamepadInputController::getDebugModeFlag(void)
{

//�f�o�b�O�p
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
* @desc ���̓t���O�C���X�^���X�̎擾
* @return�@ ���̓t���O�C���X�^���X
*/
CInputFlag* CGamepadInputController::getInputFlagInstance(void)
{
return &this->m_inputFlag;
}

//EOF