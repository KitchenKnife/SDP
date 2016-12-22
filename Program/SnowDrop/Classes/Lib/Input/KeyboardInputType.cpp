//==========================================
//
// File: KeyboardInputType.cpp
//
// �L�[�{�[�h���̓^�C�v �t�@�C��
//
// 2016/12/22
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"KeyboardInputType.h"


/*
*
*	�L�[�{�[�h���̓t���O
*
*/
/**
*	@desc	�l�̃N���A
*/
void CKeyboardInputFlag::clear() {
	this->m_up = false;
	this->m_down = false;
	this->m_left = false;
	this->m_right = false;
	this->m_esc = false;
	this->m_space = false;

	this->m_z = false;
	this->m_x = false;
	this->m_c = false;

	this->m_a = false;
	this->m_s = false;
	this->m_d = false;
}

/**
*	@desc	�L�[��������Ă��鎞�̔��f
*	@param	�L�[�R�[�h
*/
void CKeyboardInputFlag::up(kInputType keyType_) {

	switch (keyType_) {

	case kInputType::UP: this->m_up = true; break;
	case kInputType::DOWN: this->m_down = true; break;
	case kInputType::LEFT: this->m_left = true; break;
	case kInputType::RIGHT: this->m_right = true; break;
	case kInputType::ESC: this->m_esc = true; break;
	case kInputType::SPACE: this->m_space = true; break;

	case kInputType::Z: this->m_z = true; break;
	case kInputType::X: this->m_x = true; break;
	case kInputType::C: this->m_c = true; break;

	case kInputType::A: this->m_a = true; break;
	case kInputType::S: this->m_s = true; break;
	case kInputType::D: this->m_d = true; break;

	default: break;
	}
}
/**
*	@desc	�L�[��������Ă��鎞�̔��f
*	@param	�L�[�R�[�h
*/
void CKeyboardInputFlag::down(kInputType keyType_) {
	switch (keyType_) {
	case kInputType::UP: this->m_up = false; break;
	case kInputType::DOWN: this->m_down = false; break;
	case kInputType::LEFT: this->m_left = false; break;
	case kInputType::RIGHT: this->m_right = false; break;
	case kInputType::ESC: this->m_esc = false; break;
	case kInputType::SPACE: this->m_space = false; break;

	case kInputType::Z: this->m_z = false; break;
	case kInputType::X: this->m_x = false; break;
	case kInputType::C: this->m_c = false; break;

	case kInputType::A: this->m_a = false; break;
	case kInputType::S: this->m_s = false; break;
	case kInputType::D: this->m_d = false; break;

	default: break;
	}
}

/**
*	@desc	�w�肵���L�[��������Ă��邩�ǂ������擾
*	@param	�L�[�^�C�v
*	@return	true...������Ă���
*	@tips	���͂̃^�C�v�ɂ���ĕω�
*			�L�[�{�[�h�^�C�v�ł͎g�p����K�v�͂Ȃ�
*/
bool CKeyboardInputFlag::isKeyPressed(kInputType keyType_) {

	switch (keyType_) {
	case kInputType::UP: return this->m_up; break;
	case kInputType::DOWN: return this->m_down; break;
	case kInputType::LEFT: return this->m_left; break;
	case kInputType::RIGHT: return this->m_right; break;
	case kInputType::ESC: return this->m_esc; break;
	case kInputType::SPACE: return this->m_space; break;

	case kInputType::Z: return this->m_z; break;
	case kInputType::X: return this->m_x; break;
	case kInputType::C: return this->m_c; break;

	case kInputType::A: return this->m_a; break;
	case kInputType::S: return this->m_s; break;
	case kInputType::D: return this->m_d; break;

	default: break;
	}

	return false;
}
//EOF