//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "GimmickCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"


//================================================	
//	�M�~�b�N�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CGimmickCharacter::CGimmickCharacter() {
	//�L�����N�^�[�^�C�v
	this->m_charaType = (int)CHARACTER_TYPE::GIMMICK;
}

//�f�X�g���N�^
CGimmickCharacter::~CGimmickCharacter() {

}

//����������
bool CGimmickCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	return true;
}

//�ړ�����
void CGimmickCharacter::moveFunc() {

	//���t����Ă�A�N�V�����̍X�V
	if (this->m_mapAction[this->m_actionState])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_actionState])) {
			pAction->update(this);
		}
	}

	//�����v�Z
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

//�A�j���[�V��������
void CGimmickCharacter::animationFunc() {

	//�A�j���[�V����
	(*this->m_pAnimations)[0]->update();
}

//�Փ˔��菈��
void CGimmickCharacter::collisionAll() {

	//����ł������΂�
	if (this->m_isAlive == false)
		return;

	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}
}

/**
* @desc ��ԃ`�F�b�N
* @tips �l���`�F�b�N���Č��݂̏�Ԃ�ύX����
*/
void CGimmickCharacter::checkState() {

	//�����𔻒�
	if (this->m_pMove->m_vel.x != 0) {
		if (this->m_pMove->m_vel.x > 0) {
			//�E�����ɐݒ�
			this->setScale(1.0f, 1.0f);
		}
		else {
			//�������ɐݒ�
			this->setScale(-1.0f, 1.0f);
		}
	}
}

//���f����
void CGimmickCharacter::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[0]->getCurrentChip());

}

/**
* @desc �Փ˂��Ă�����̏���
* @param �Փ˂��Ă����L�����N�^�[
*/
/**
void CGimmickCharacter::hits(CCharacter* pChara) {

	//����ł������΂�
	if (this->m_isAlive == false)
		return;

	//�v���C���[�Ȃ�
	if (pChara->m_charaType == CHARACTER_TYPE::PLAYER) {
		this->hitsPlayerCharacter(pChara);
	}

	//�v���C���[�ȊO�Ȃ�
	if (pChara->m_charaType != CHARACTER_TYPE::PLAYER) {
		this->hitsNotPlayerCharacter(pChara);
	}
}
*/
//�v���C���[�Ƃ̏Փ˔����̏���
void CGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara) {

	//�v���C���[�̑����̈ʒu
	float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

	//�G�̒��S�ʒu
	float enePosY = this->m_pMove->m_pos.y;

	//�G���ォ�ǂ���
	float posY = playerFeetPosY - enePosY;
	if (posY > 0.0f) {

		//�ゾ����
		CCLOG("WIN");
		//�G�̎��S�t���O�𗧂Ă�
		//�܂萶���Ă��邩����ł��邩�̃t���O��false������
		//this->m_isAlive = false;

		//���x�����Z�b�g
		pChara->m_pMove->m_vel.y = 0.0f;

		//====================================================
		// �߂荞�񂾕��߂�
		//====================================================
		//�߂荞�񂾕��̌v�Z
		float boundary = (this->m_pMove->m_pos.y + this->m_pBody->m_top) - playerFeetPosY;
		//�ŏI�I�ɖ߂��l
		pChara->m_pMove->m_pos.y += (boundary);

		//�v���C���[���኱��ɒ��˕Ԃ�
		//pChara->m_pMove->m_vel.y = 3.0f;

		//====================================================
		// �W�����v�A�N�V�����̍ċN��
		//===================================================
		//�W�����v�A�N�V�����̍ċN��
		//(*pChara->m_pActions)[0]->restart(pChara);

		//�G�L�����N�^�[�̃A�N�V�����ɓG���S�A�N�V����
		(*pChara->m_mapAction[0])[0]->stop();
		//�����S�t���O�̑��������
		//���W�����v�A�N�V�����̍ċN��������

	}
	else {

		//��������
		CCLOG("FALSE");
	}

}

//�v���C���[�ȊO�Ƃ̏Փ˔����̏���
void CGimmickCharacter::hitsNotPlayerCharacter(CCharacter* pChara) {

	//�G�L�����N�^�[�̃A�N�V�����ɓG���S�A�N�V���������t����
	(*this->m_mapAction[0])[0]->start();
	//�����S�t���O�̑��������

}

/**
* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
* @param �L�����N�^�[�̃A�h���X
* @return true...�Փ˂���
*/
bool CGimmickCharacter::collision(CCharacter* pChara) {

	return true;
}



