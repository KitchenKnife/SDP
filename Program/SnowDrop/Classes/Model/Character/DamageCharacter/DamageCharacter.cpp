
/*
* DamageCharacter.cpp
*
*	2016/12/26	Yamasaki
*
*/
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "DamageCharacter.h"
#include "Data/ActionController/ActionController.h"
#include "Model/Character/CharacterAggregate.h"
#include "Data/Enum/EnumPlayer.h"


//================================================	
//	�_���[�W�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CDamageCharacter::CDamageCharacter() {
	this->m_charaType = (int)CHARACTER_TYPE::DAMAGE;

}

//�f�X�g���N�^
CDamageCharacter::~CDamageCharacter() {}



//����������
bool CDamageCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	return true;
}


//�ړ�����
void CDamageCharacter::moveFunc() {

	//�_���[�W�L�����N�^�[�͏�ɏ��L�҂̉摜�E�[�ɒ����Ă����悤�Ɉړ�����B
	//this->m_pMove->m_pos.set(this->m_pChara->m_pMove->m_pos.x + this->m_pBody->m_right, this->m_pChara->m_pMove->m_pos.y);

	// �A�N�V����
	if (this->m_mapAction[this->m_actionState])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_actionState])) {
			pAction->update(this);
		}
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

//�A�j���[�V��������
void CDamageCharacter::animationFunc() {
	(*this->m_pAnimations)[this->m_animationState]->update();
}

//�Փ˔��菈��
void CDamageCharacter::collisionAll() {
	if (this->m_pChara->m_charaType == (int)CHARACTER_TYPE::PLAYER_BOY) {
		std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();

		for (CCharacter* pChara : (*pCharacters)) {
			if (pChara->m_charaType == (int)CHARACTER_TYPE::ENEMY ||
				pChara->m_charaType == (int)CHARACTER_TYPE::DAMAGE)
			{
				//�����Ă�����
				if (pChara->m_isAlive)
				{
					if (this->collision(pChara)) {
						//�U���͕��̃_���[�W��^����
						pChara->decreaseHP(this->m_status.getAttackPt());
						//�U�����󂯂Ă����ԃt���O���グ��
						pChara->m_underAttack = true;
					}
				}
			}
		}
	}

	//�_���[�W���o�����̂��G��������
	if (this->m_pChara->m_charaType == (int)CHARACTER_TYPE::ENEMY) {

		CPlayerCharacterBoy* pTarget = CCharacterAggregate::getInstance()->getPlayer();
		if (pTarget->m_isAlive)
		{
			if (this->collision(pTarget)) {
				//�U���͕��̃_���[�W��^����
			//	pTarget->decreaseHP(this->m_status.getAttackPt());
				//�U�����󂯂Ă����ԃt���O���グ��
				pTarget->m_underAttack = true;

				if (this->m_pMove->m_pos.x < pTarget->m_pMove->m_pos.x) {
					pTarget->m_underAttackDirection = (int)PLAYER_UNDER_ATTACK_DIRECTION::LEFT;
				}
				else {
					pTarget->m_underAttackDirection = (int)PLAYER_UNDER_ATTACK_DIRECTION::RIGHT;
				}

				
			}
		}
	}
}

//��ԃ`�F�b�N
void CDamageCharacter::checkState() {
	if (this->m_pStateMachine)
	{
		//��ԑJ�ڃ}�V���̍X�V
		this->m_pStateMachine->update();
	}
}

//���f����
void CDamageCharacter::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[this->m_animationState]->getCurrentChip());


	// �L�������̍X�V
	this->m_activeFrame--;

	if (this->m_activeFrame < 0) {

		// �L���������؂ꂽ�玀�ʁB
		this->m_activeFlag = false;
	}

}

/**
* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
* @param �L�����N�^�[�̃A�h���X
* @return true...�Փ˂���
*/
bool CDamageCharacter::collision(CCharacter* pChara) {

	//�_���[�W�L�����N�^�[�ƓG�̋�`�𐶐�
	CCollisionRect damageCollisionRect = CCollisionRect(*this->m_pBody, this->m_pMove->m_pos);

	CCollisionRect enemyCollisionRect = CCollisionRect(*pChara->m_pBody, pChara->m_pMove->m_pos);

	// ��`�Ƌ�`�̏Փ˔���
	return damageCollisionRect.collision(&enemyCollisionRect);

}

/**
* @desc	���N���X����Փ˔�����󂯂��ۂ̏���
* @param	�L�����N�^�[�̃A�h���X
*/
void CDamageCharacter::hits(CCharacter* pChara) {

}