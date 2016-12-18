
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

// �A�N�V��������
void CEnemyCharacter::actionFunc(CCharacter* pChara) {

	if (this->m_state != (int)STATE::ATTACK) {

		// �Ō��U��
		//(*this->m_pActions)[(int)ACTION::BLOW_ATTACK]->start(pChara->m_pStatus);

	}
}


//�ړ�����
void CEnemyCharacter::moveFunc() {

	//�W�����v�ړ��v�Z
	(*this->m_pActions)[(int)ACTION::JUMP]->update(this);

	//�W�����v�ړ��v�Z
	(*this->m_pActions)[(int)ACTION::ATTACK]->update(this);

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
	(*this->m_pAnimations)[m_state]->update();
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
			this->m_state = (int)STATE::WALK_RIGHT;
		}
		else {
			//�������ɐݒ�
			this->m_state = (int)STATE::WALK_LEFT;
		}
	}

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

	// ���݂̃X�e�[�g�����O�ɕ\��
	CCLOG(" NowState = %d ,\nStand Jumping = 0,\nWalk = 1 ,\nHit = 2,\nFaling = 3,Attack = 4 ,\n", m_state);


}

//���f����
void CEnemyCharacter::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[m_state]->getCurrentChip());

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
* @desc �}�b�v�Ƃ̏Փ˔���
* @return true...�Փ˂���
*/
/*
bool CEnemyCharacter::collisionMap() {

	//�}�b�v���擾
	CMap* pMap = CMapManager::getInstance()->getMap();

	//��ԂŔ��肷��̂ň�U��Ԃ̃`�F�b�N���s��
	this->checkState();


	//�����̓_�Ŕ��肷��
	float byI = 6;
	for (int i = 1; i < byI; ++i) {
		//���Ɉړ����Ă���ꍇ�ɉ��ɏ�Q�������������ɖ߂�
		if (this->m_pMove->m_vel.y < 0.0f) {
			//�摜�̕���ݒ�
			float width = abs(this->m_pBody->m_left) + abs(this->m_pBody->m_right);

			//�L�����N�^�[�̈ʒu����^���ɂ���_�̍��W���擾
			Point pt(this->m_pMove->m_pos.x + this->m_pBody->m_left + (width * i / byI), this->m_pMove->m_pos.y + this->m_pBody->m_bottom);

			/*
			*�@�_����ʂ̂ǂ̍��W�ɂ��邩�𒲂ׂĂ��̍��W��
			*�@�}�b�v�`�b�v�����݂��邩�𒲂׃}�b�v�`�b�v�����݂�����
			*�@true��Ԃ��B
			*
			if (pMap->hitTest(pt.x, pt.y)) {

				//�u���b�N�̃^�C�v���擾
				BLOCK_TYPE mapChipID = pMap->checkTile(pt.x, pt.y);

				if (mapChipID != BLOCK_TYPE::NONE) {

					//�^�C���̃T�C�Y
					Size tileSize = pMap->getTileSize();

					//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@���@�u���b�N��*�u���b�N�̍���
					float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

					//�C���ʒu�i�L�����N�^�[���߂荞��ł�u���b�N�̉��̈ʒu�j��
					//�L�����N�^�[���߂荞��ł�u���b�N�̉��̃u���b�N�̈ʒu�@+�@�u���b�N1���@-�ʒu��
					float boundary = (pt.y) - (blockPos + tileSize.height);

					//�߂荞��ł镪���C��
					this->m_pMove->m_pos.y -= boundary;

					//���x�Ɖ����x��0�ɂ���
					this->m_pMove->m_vel.y = 0.0f;
					this->m_pMove->m_accele.y = 0.0f;

				}
			}

		}

	}

	return true;

}
*/

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


