
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


//================================================	
//	�_���[�W�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CDamageCharacter::CDamageCharacter() {}

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
}

//�A�j���[�V��������
void CDamageCharacter::animationFunc() {
}

//�Փ˔��菈��
void CDamageCharacter::collisionAll() {
	if (this->m_pChara->m_charaType == (int)CHARACTER_TYPE::PLAYER_BOY) {
		std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();

		for (CCharacter* pChara : (*pCharacters)) {
			if (pChara->m_charaType == (int)CHARACTER_TYPE::ENEMY)
			{
				if (this->collision(pChara)) {
					pChara->m_activeFlag = false;
				}
			}
		}
	}
}

//��ԃ`�F�b�N
void CDamageCharacter::checkState() {
}

//���f����
void CDamageCharacter::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

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