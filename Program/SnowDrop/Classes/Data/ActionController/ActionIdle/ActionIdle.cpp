//==========================================
//
// File: ActionIdle.cpp
//
// �A�N�V�����@�ҋ@ �@�t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "ActionIdle.h"
#include "Model\Character\Character.h"

//==========================================
//
// Class: ActionIdle
//
// �A�N�V�����@�ҋ@		�N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CActionIdle::CActionIdle()
{
	//�����Ɠ����ɊJ�n
	this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionIdle::start(void)
{
	//�A�N�V�����J�n
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionIdle::update(CCharacter* pChara)
{
	
}

/**
* @desc �A�N�V�����I��
*/
void CActionIdle::stop(void)
{
	//�A�N�V�����I��
	this->m_inAction = false;
}


