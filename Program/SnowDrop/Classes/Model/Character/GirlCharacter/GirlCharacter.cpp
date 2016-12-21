#include "GirlCharacter.h"

//================================================
// �����N���X�̃����o�֐���`
//================================================
//�R���X�g���N�^
CPlayerCharacterGirl::CPlayerCharacterGirl() {}

//�f�X�g���N�^
CPlayerCharacterGirl::~CPlayerCharacterGirl() {}

//����������
bool CPlayerCharacterGirl::init() {

	if (CCharacter::init() == false) {
		CCLOG("CCharacter�������Ɏ��s");
		return false;
	}

	return true;
}



//�ړ�����
void CPlayerCharacterGirl::moveFunc() {

	//����ł����΂�
	if (this->m_activeFlag == false)
		return;

	//�A�N�V������Ԃ̍X�V����
	for (CAction* pAction : (*this->m_pActions)) {
		pAction->update(this);
	}

	//�����v�Z
	for (CPhysical* pPhysical : (*this->m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}


//�A�j���[�V��������
void CPlayerCharacterGirl::animationFunc() {

	//�v���C���[�A�j���[�V����
	(*this->m_pAnimations)[this->m_state]->update();

}


//�Փ˔��菈��
void CPlayerCharacterGirl::collisionAll() {
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
void CPlayerCharacterGirl::checkState() {


}


//���f����
void  CPlayerCharacterGirl::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[this->m_state]->getCurrentChip());
}


/**
 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
 * @param	�L�����N�^�[�̃A�h���X
 * @return	true...�Փ˂���
 */
bool  CPlayerCharacterGirl::collision(CCharacter* pChara) {

	return true;
}

/**
 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
 * @param	�L�����N�^�[�̃A�h���X
 */
void CPlayerCharacterGirl::hits(CCharacter* pChara) {

}
