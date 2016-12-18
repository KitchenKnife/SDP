
#include "Data/Effect/Effect.h"

/*
* Effect.cpp
*
*	2016/11/25	Osumi
*
*/

//================================================
// 
// �G�t�F�N�g�̊��N���X
//
//================================================
//����������
bool CEffect::init(){

	if (Sprite::init() == false) {
		CCLOG("�X�v���C�g�N���X�̏������Ɏ��s");
		return false;
	}

	//================================================	
	//	�����o�֐��̃R�[�h�̒ǉ��͂�������
	//================================================


	//================================================	
	//	�l�̐ݒ�Ɋւ���R�[�h�̒ǉ��͂�������
	//================================================


	return true;

}

//�X�V����
void CEffect::update() {

	//�ړ�����
	this->moveFunc();

	//�A�j���[�V��������
	this->animationFunc();

	//���f����
	this->applyFunc();
}

//�A�j���[�V��������
void CEffect::animationFunc() {

	//�A�j���[�V����
	this->m_pAnimationDatas->update();
}

//���f����
void CEffect::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect(this->m_pAnimationDatas->getCurrentChip());

}
