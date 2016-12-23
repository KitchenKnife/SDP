
/*
* EnemyCharacter.cpp
*
*	2016/11/11	Yamasaki
*
*/
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "EnemyCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Data/ActionController/ActionController.h"


//================================================	
//	�G�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CEnemyCharacter::CEnemyCharacter() {}

//�f�X�g���N�^
CEnemyCharacter::~CEnemyCharacter() {}



//����������
bool CEnemyCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	return true;
}


//�ړ�����
void CEnemyCharacter::moveFunc() {
	// �A�N�V����
	for (CAction* pAction : (*m_pActions)) {
		pAction->update(this);
	}

	//�����v�Z
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

//�A�j���[�V��������
void CEnemyCharacter::animationFunc() {
	(*this->m_pAnimations)[this->m_state]->update();
}

//�Փ˔��菈��
void CEnemyCharacter::collisionAll() {

	//����ł������΂�
	if (this->m_isAlive == false)
		return;

	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}
}

//��ԃ`�F�b�N
void CEnemyCharacter::checkState() {
	
}

//���f����
void CEnemyCharacter::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[0]->getCurrentChip());

}

/**
 * @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
 * @param �L�����N�^�[�̃A�h���X
 * @return true...�Փ˂���
 */
bool CEnemyCharacter::collision(CCharacter* pChara) {

	//�v���C���[�ƓG�̋�`�𐶐�
	CCollisionRect pEnemyCollisionRect = CCollisionRect(*this->m_pBody, this->m_pMove->m_pos);

	CCollisionRect pPlayerCollisionRect = CCollisionRect(*pChara->m_pBody, pChara->m_pMove->m_pos);

	// ��`�Ƌ�`�̏Փ˔���
	return pEnemyCollisionRect.collision(&pPlayerCollisionRect);

}

/**
 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
 * @param	�L�����N�^�[�̃A�h���X
 */
void CEnemyCharacter::hits(CCharacter* pChara) {

}