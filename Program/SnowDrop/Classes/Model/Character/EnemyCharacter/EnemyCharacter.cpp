
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
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"


//================================================	
//	�G�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CEnemyCharacter::CEnemyCharacter() {

}

//�f�X�g���N�^
CEnemyCharacter::~CEnemyCharacter() {

	//�A�j���[�V�����Q�̉��
	std::map<STATE, CAnimation*>::iterator animeItr = this->m_pAnimations.begin();
	while (animeItr != this->m_pAnimations.end()) {
		SAFE_DELETE(animeItr->second);
		animeItr++;
	}
	this->m_pAnimations.clear();

	//�A�N�V�����֐��Q�̉��
	std::map<STATE, CAction*>::iterator actItr = this->m_pActions.begin();
	while (actItr != this->m_pActions.end()) {
		SAFE_DELETE(actItr->second);
		actItr++;
	}
	this->m_pActions.clear();

}

//����������
bool CEnemyCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	return true;
}

/*
* @desc	����������
* @param�@�������ʒuX
* @param�@�������ʒuY
*/
bool CEnemyCharacter::init(float posX, float posY) {

	//�L�����N�^�[�N���X�̏�����
	if (CCharacter::init() == false) {
		CCLOG("�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	return true;
}

//�^�[�Q�b�g�̐ݒ�
void CEnemyCharacter::setTarget(CCharacter* pChara) {
	this->m_currentTarget = pChara;
}

// �A�N�V��������
void CEnemyCharacter::actionFunc(CCharacter* pChara) {

	this->m_pAnimations[this->m_state]->update();
}


//�ړ�����
void CEnemyCharacter::moveFunc() {
	// �A�N�V����
	/*
	for (CAction* pAction : (*m_pActions)) {
		pAction->update(this);
	}
	*/

	//�A�N�V��������
	(this->m_pActions)[this->m_state]->update(this);

	//�����v�Z
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

//�A�j���[�V��������
void CEnemyCharacter::animationFunc() {

	//�A�j���[�V����
	(this->m_pAnimations)[this->m_state]->update();
}

/**
* @desc ��ԃ`�F�b�N
* @tips �l���`�F�b�N���Č��݂̏�Ԃ�ύX����
*/
void CEnemyCharacter::checkState() {

	
	//�����𔻒�
	if (this->m_pMove->m_vel.x != 0) {
		if (this->m_pMove->m_vel.x > 0) {
			//�E�����ɐݒ�
			this->setScale(-1.0, 1.0);
		}
		else {
			//�������ɐݒ�
			this->setScale(1.0, 1.0);
		}
	}
	/*
	//��Ԃ̔���
	if (this->m_pMove->m_vel.y > 0.0f) {

		//�����̑��x���v���X�Ƃ������Ƃ̓W�����v���Ă�����
		m_state = (int)STATE::JUMPING;

	}
	else if (this->m_pMove->m_vel.y < 0.0f) {
		//�����̑��x���}�C�i�X�Ƃ����Ƃ͗����Ă�����
		m_state = (int)STATE::FALING;
	}
	else if ((*this->m_pActions)[(int)ACTION::ATTACK]->getActionFlag()) {
	
		// �Ō��U����
		m_state = (int)STATE::ATTACK;

	}
	else if (this->m_pMove->m_vel.x > 0.0f) {
		//�E�ɕ����Ă���
		m_state = (int)STATE::WALK_RIGHT;
	}
	else if (this->m_pMove->m_vel.x < 0.0f) {
		//���ɕ����Ă���
		m_state = (int)STATE::WALK_LEFT;
	}
	else {
		//�����Ă���
		m_state = (int)STATE::STAND;
	}
	*/

}

//���f����
void CEnemyCharacter::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect(this->m_pAnimations[this->m_state]->getCurrentChip());

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


