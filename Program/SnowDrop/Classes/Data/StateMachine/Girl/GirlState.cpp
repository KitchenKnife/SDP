//==========================================
//
// File: GirlState.cpp
//
// Girl��ԑJ�� �t�@�C��
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "GirlState.h"


//==========================================
//
// Class: CGirlStandState
//
// Girl ���� ��� �N���X
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CGirlStandState::CGirlStandState(int nextRegisterKey)
	:CStateBase::CStateBase(nextRegisterKey)
{


}

/**
* @desc �f�X�g���N�^
*/
CGirlStandState::~CGirlStandState()
{

}

/**
* @desc �J�n����
*/
void CGirlStandState::start()
{
	//std::cout << "PlayerMover : " << "�X�^�[�g" << std::endl;
}

/**
* @desc �X�V����
*/
void CGirlStandState::update()
{
	//std::cout << "PlayerMover : " << "�A�b�v�f�[�g" << std::endl;
	//isNext = true;
}

// ��Ԃ��ς��Ƃ��̏���
void CGirlStandState::onChangeEvent()
{
	this->m_isNext = false;
	//		std::cout << "PlayerMover : " << "�؂�ւ��C�x���g�ɓ�����" << std::endl;
}
//EOF