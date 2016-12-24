/**
*
* ActionController.cpp
*
*	2016 / 11 / 07	Osumi
*
*/
#include "ActionJump.h"
#include "Model/Character/Character.h"

/*
* @desc	�X�V�����i�W�����v�ړ��v�Z�j
* @param	�W�����v����Ώۂ̃L�����N�^�[
* @tips	��L�[�������ꂽ�炱�̊֐����Ăяo��
*/
void  CActionJump::update(CCharacter* pChara) {

	if (this->m_isJumping == true) {

		//�W�����v��

		//�W�����v�u�[�X�g�����炵�Ă���
		this->m_currentBoost--;

		//�W�����v�u�[�X�g��0��菬�����ꍇ
		if ((this->m_isJumpStart == false) || (this->m_currentBoost < 0)) {

			//�����x��0�ɂ���
			pChara->m_pMove->m_accele.y = 0.0f;
		}

	}
	else if (this->m_isJumpStart == true) {

		//�W�����v�J�n

		//y���̉����x�ɒl��ݒ�
		pChara->m_pMove->m_accele.y = this->m_accele;
		//���t���[���A�����x��K�p�����邩�ݒ�
		this->m_currentBoost = this->m_boost;
		//�W�����v�t���O��true�ɂ���
		this->m_isJumping = true;
	}

	//�W�����v�J�n�t���O��������
	this->m_isJumpStart = false;
}

/**
* @desc	�A�N�V�����̍ċN��
* @param	�ċN������L�����N�^�[
* @tips	�L�����N�^�[��Y�����̃��Z�b�g
*/
void CActionJump::restart(CCharacter* pChara) {

	//Y�����̑��x�Ɖ����x�̃��Z���g
	pChara->m_pMove->m_vel.y = 0.0f;
	pChara->m_pMove->m_accele.y = 0.0f;

	//�A�N�V�����̒�~
	this->stop();

	//�A�N�V�����̊J�n
	this->start();
}