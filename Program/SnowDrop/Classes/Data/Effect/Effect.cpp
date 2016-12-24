/*
 * Effect.cpp
 *
 *	2016/11/25	Osumi
 *
 */
#include "Data/Effect/Effect.h"
//================================================
// 
// �G�t�F�N�g�̊��N���X
//
//	2016/12/22
//									Author Harada
//
//================================================
//�R���X�g���N�^
CEffect::CEffect(){}

//�f�X�g���N�^
CEffect::~CEffect() {}
//����������
bool CEffect::init(){

	if (CCharacter::init() == false) {
		CCLOG("�X�v���C�g�N���X�̏������Ɏ��s");
		return false;
	}

	return true;
}

/**
 * @desc	�ړ�����
 * @tips	��������ȓ��������������ꍇ�͂��̃N���X���p������
 *			�I�[�o�[���C�h������
 */
void CEffect::moveFunc() {

	//�����v�Z
	for (CPhysical* pPhysical : (*this->m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

//�A�j���[�V��������
void CEffect::animationFunc() {

	//�A�j���[�V�����X�V
	(*this->m_pAnimations)[0]->update();

	//�A�j���[�V�����̏I���t���O���m�F
	if ((*this->m_pAnimations)[0]->isEnd()) {
		//�I�����Ă���΃A�N�e�B�u�t���O�� false �ɕύX
		this->m_activeFlag = false;
	}
}

//�Փ˔��菈��
void CEffect::collisionAll() {
	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}

	//�S�ẴL�����N�^�[�Ƃ̏Փ˔���
	std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();
	for (CCharacter* pChara : (*pCharacters)) {
		//��̂̃L�����Ƃ̏Փ˔���
		this->collision(pChara);
	}
}

//��ԃ`�F�b�N
void CEffect::checkState() {

}

//���f����
void CEffect::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[0]->getCurrentChip());

}

/**
 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
 * @param	�L�����N�^�[�̃A�h���X
 * @return	true...�Փ˂���
 */
bool CEffect::collision(CCharacter* pChara) {
	return true;
}

/**
 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
 * @param	�L�����N�^�[�̃A�h���X
 */
void CEffect::hits(CCharacter* pChara) {

}