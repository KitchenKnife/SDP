//==========================================
//
// File: ActionMoveStraight.h
//
// �A�N�V�����@�����ړ� �w�b�_�[�t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "ActionMoveStraight.h"
#include "Model\Character\Character.h"

//==========================================
//
// Class: ActionMoveStraight
//
// �A�N�V�����@�����ړ�		�N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CActionMoveStraight::CActionMoveStraight()
{
	//�����Ɠ����ɊJ�n
	this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionMoveStraight::start(void)
{
	//�A�N�V�����J�n
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionMoveStraight::update(CCharacter* pChara)
{
	if (this->m_inAction != false)
	{
		pChara->m_pMove->m_vel.x = pChara->m_pMove->m_vel.x;
		pChara->m_pMove->m_vel.y = pChara->m_pMove->m_vel.y;
	}
	this->stop();
}

/**
* @desc �A�N�V�����I��
*/
void CActionMoveStraight::stop(void)
{
	//�A�N�V�����I��
	this->m_inAction = false;
}