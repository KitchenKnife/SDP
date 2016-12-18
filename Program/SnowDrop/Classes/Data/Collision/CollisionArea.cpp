
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "CollisionArea.h"
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"


//=====================================
//
// �Փ˔���̈�
//
//=====================================


/**
* @desc �C�x���g�R�[���o�b�N�̌Ăяo��
* @param �Ăт����C���X�^���X
* @param �C�x���g
*�@�@�@�@�}�b�v�����Ղ̍ۂ̓}�b�v�`�b�vID���C�x���g�Ƃ��ēn����
*�@�@�@�@��ʒ[�Ȃǂ̓C�x���g�͑��݂��Ȃ��̂�
*�@�@�@�@�f�t�H���g�l�Ƃ���0��ݒ肵�Ă���
* @tips�@�̈�̃C�x���g�̔������ɂ��̃����o�֐����Ăяo�����Ƃ�
*�@�@�@�@�o�^���������o�֐����Ăяo�����@
*/
void CCollisionTerritory::callEventCallback(CCharacter* pChara, int event) {

	//�C�x���g�R�[���o�b�N���ݒ肳��Ă���΁B�B�B
	//�܂�NULL�Ȃ�Ăяo�����s��Ȃ�
	if (this->m_pEventCallBack != NULL) {

		//�C�x���g�R�[���o�b�N���Ăяo�������o�֐�����������Ă���
		//�L�����N�^�[����Ăяo�����s��
		(pChara->*m_pEventCallBack)(event);
	}
}

//=====================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryEndOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//���Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.y < 0.0f) {

		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_BOTTOM;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.y -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�

		}
	}
}

//=====================================
// ��ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryEndOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//��Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.y > 0.0f) {

		//��ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_TOP;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.y -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�
		}
	}
}
//=====================================
// �E�ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryEndOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//�E�Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.x > 0.0f) {

		//�E�ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//�߂荞�񂾕��̌v�Z	//basePt.x
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_RIGHT;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.x -= boundary;

			//���Z�b�g����l
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�
		}
	}
}
//=====================================
// ���ɂ����ʒ[�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryEndOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//���Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.x < 0.0f) {

		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);



			//�߂荞�񂾕��̌v�Z
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_LEFT;

			//�ŏI�I�ɖ߂��l
			pChara->m_pMove->m_pos.x -= (boundary);

			//���Z�b�g����l
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�
		}
	}
}


//=====================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[0
* @param ��_
*/
void CCollisionTerritoryOutOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//���Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.y < 0.0f) {

		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�

		}
	}
}

//=====================================
// ��ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryOutOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//��Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.y > 0.0f) {

		//��ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//���Z�b�g����l
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�
		}
	}
}
//=====================================
// �E�ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryOutOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//�E�Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.x > 0.0f) {

		//�E�ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT * 3) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//���Z�b�g����l
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�
		}
	}
}
//=====================================
// ���ɂ����ʊO�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryOutOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//���Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.x < 0.0f) {

		//���ɉ�ʒ[�����邩�ǂ������`�F�b�N
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT) {

			//�C�x���g�R�[���o�b�N�̌Ăяo��
			this->callEventCallback(pChara);

			//���Z�b�g����l
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;

			//�W�����v�̒�~�͂�������R�����g�A�E�g���Ă���
			//���̕����͍l���Ȃ��Ă͂Ȃ�Ȃ������l����Ƃ܂Ƃ܂�Ȃ��̂�
			//���͍l���Ȃ�
		}
	}
}



//=====================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryMapChipBottom::collision(CCharacter* pChara, cocos2d::Point basePt){

	//���Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.y < 0.0f) {

		//�Փ˂��Ă����_�i�L�����N�^�[�̓_�j
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y+ basePt.y);

		//�Փ˂��Ă邩�ǂ���
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {

			//�Փ˂��Ă�

			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapCcipID != BLOCK_TYPE::NONE) {

				

				//�߂��ׂ��ʒu�̒l

				//�^�C���̃T�C�Y�i32,32�j
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@���@�u���b�N��*�u���b�N�̍���
				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

				//�߂��ׂ��ʒu
				//		�C���ʒu�i�L�����N�^�[���߂荞��ł�u���b�N�̉��̈ʒu�j��
				//		�L�����N�^�[���߂荞��ł�u���b�N�̉��̃u���b�N�̈ʒu�@+�@�u���b�N1���@-�ʒu��
				//�߂荞�񂾕��̌v�Z
				float boundary = (pt.y) - (blockPos + tileSize.height);

				//�ŏI�I�ɖ߂��i�l�߂荞��ł镪���C���j
				pChara->m_pMove->m_pos.y -= boundary;

				//���Z�b�g�l
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;

				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara, (int)mapCcipID);
			}
		}
	}

}
//=====================================
// ��ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryMapChipTop::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//��Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.y > 0.0f) {

		//�Փ˂��Ă����_�i�L�����N�^�[�̓_�j
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);

		//�Փ˂��Ă邩�ǂ���
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {

			//�Փ˂��Ă�

			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapCcipID != BLOCK_TYPE::NONE) {

				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara);

				//�߂��ׂ��ʒu�̒l

				//�^�C���̃T�C�Y�i32,32�j
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@���@�u���b�N��*�u���b�N�̍���
				float blockPos = floor((pt.y) / tileSize.height)*(tileSize.height);

				//�߂��ׂ��ʒu
				//		�C���ʒu�i�L�����N�^�[���߂荞��ł�u���b�N�̏�̈ʒu�j��
				//		�L�����N�^�[���߂荞��ł�u���b�N�̉��̃u���b�N�̈ʒu�@-�ʒu��
				//�߂荞�񂾕��̌v�Z
				float boundary = (pt.y) - (blockPos);

				//�ŏI�I�ɖ߂��i�l�߂荞��ł镪���C���j
				pChara->m_pMove->m_pos.y -= boundary;

				//���Z�b�g�l
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;
			}
		}
	}

}
//=====================================
// �E�ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryMapChipRight::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//�E�Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.x > 0.0f) {

		//�Փ˂��Ă����_�i�L�����N�^�[�̓_�j
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);

		//�Փ˂��Ă邩�ǂ���
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {

			//�Փ˂��Ă�

			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapCcipID != BLOCK_TYPE::NONE) {

				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara);

				//�߂��ׂ��ʒu�̒l

				//�^�C���̃T�C�Y�i32,32�j
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@���@�u���b�N��*�u���b�N�̍���
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//�߂��ׂ��ʒu
				//		�C���ʒu�i�L�����N�^�[���߂荞��ł�u���b�N�̉��̈ʒu�j��
				//		�L�����N�^�[���߂荞��ł�u���b�N�̉��̃u���b�N�̈ʒu�@+�@�u���b�N1���@-�ʒu��
				//�߂荞�񂾕��̌v�Z
				float boundary = (pt.x) - (blockPos); // + tileSize.width

				//�ŏI�I�ɖ߂��i�l�߂荞��ł镪���C���j
				pChara->m_pMove->m_pos.x -= boundary;

				//���Z�b�g�l
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}
	}

}
//=====================================
// ���ɂ���}�b�v�`�b�v�̈�Ƃ̏Փ˔���
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
* @param ��_
*/
void CCollisionTerritoryMapChipLeft::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//���Ɉړ����Ă��邩�ǂ����`�F�b�N
	if (pChara->m_pMove->m_vel.x < 0.0f) {

		//�Փ˂��Ă����_�i�L�����N�^�[�̓_�j
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);

		//�Փ˂��Ă邩�ǂ���
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {


			//�Փ˂��Ă�

			//�u���b�N�̃^�C�v���擾
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//�Փ˂���u���b�N���ǂ���
			if (mapCcipID != BLOCK_TYPE::NONE) {

				//�C�x���g�R�[���o�b�N�̌Ăяo��
				this->callEventCallback(pChara);

				//�߂��ׂ��ʒu�̒l

				//�^�C���̃T�C�Y�i32,32�j
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//�L�����N�^�[���߂荞��ł���u���b�N�̉��̃u���b�N�̈ʒu�@���@�u���b�N��*�u���b�N�̍���
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//�߂��ׂ��ʒu
				//		�C���ʒu�i�L�����N�^�[���߂荞��ł�u���b�N�̉��̈ʒu�j��
				//		�L�����N�^�[���߂荞��ł�u���b�N�̉��̃u���b�N�̈ʒu�@+�@�u���b�N1���@-�ʒu��
				//�߂荞�񂾕��̌v�Z
				float boundary = (pt.x) - (blockPos + tileSize.width);

				//�ŏI�I�ɖ߂��i�l�߂荞��ł镪���C���j
				pChara->m_pMove->m_pos.x -= boundary;

				//���Z�b�g�l
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}
	}

}



//=====================================
//
// �Փ˔�����
//
//=====================================

//=====================================
// ��ʒ[�Ƃ̏Փ˔�����
//=====================================
//�f�t�H���g�R���X�g���N�^
CCollsionAreaEndOfScreen::CCollsionAreaEndOfScreen() {}

//�R���X�g���N�^
CCollsionAreaEndOfScreen::CCollsionAreaEndOfScreen(CBody* pBody){

	//��ʒ[�̏Փˋ�ԂɏՓ˂��s����_��ݒ�
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(pBody->m_left, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(0, pBody->m_top)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(pBody->m_right, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, pBody->m_bottom)));
}

/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
*/
void CCollsionAreaEndOfScreen::collision(CCharacter* pChara) {

	//�̈敪�J��Ԃ�
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories)) {
		//��_���J��Ԃ�
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints)) {

			//��_�̒��ɓo�^����Ă���Փ˔���̈�^�C�v����v�����炻�̊�_�ŏՓ˔�����s��
			if (pBasePt->m_type == pTerritory->m_type) {
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}

}



//=====================================
// ��ʏ�ɂ���S�Ẵ}�b�v�`�b�v�Ƃ̏Փ˔�����
//�@�܂�}�b�v�`�b�v�Ƃ̏Փ˔�����
//=====================================
/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
*/
void CCollsionAreaMap::collision(CCharacter* pChara) {

	//�̈敪�J��Ԃ�
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories)) {
		//��_���J��Ԃ�
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints)) {

			//��_�̒��ɓo�^����Ă���Փ˔���̈�^�C�v����v�����炻�̊�_�ŏՓ˔�����s��
			if (pBasePt->m_type == pTerritory->m_type) {
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}

}


//=====================================
// ��ʊO�Ƃ̏Փ˔�����
//=====================================
//�f�t�H���g�R���X�g���N�^
CCollsionAreaOutOfScreen::CCollsionAreaOutOfScreen() {}


//�R���X�g���N�^
CCollsionAreaOutOfScreen::CCollsionAreaOutOfScreen(CBody* pBody) {

	//��ʒ[�̏Փˋ�ԂɏՓ˂��s����_��ݒ�
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(pBody->m_right, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(0, pBody->m_bottom)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(pBody->m_left, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, pBody->m_top)));
}

/**
* @desc �Փ˔���
* @param �ՓˑΏۂ̃L�����N�^�[
*/
void CCollsionAreaOutOfScreen::collision(CCharacter* pChara) {

	//�̈敪�J��Ԃ�
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories)) {
		//��_���J��Ԃ�
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints)) {

			//��_�̒��ɓo�^����Ă���Փ˔���̈�^�C�v����v�����炻�̊�_�ŏՓ˔�����s��
			if (pBasePt->m_type == pTerritory->m_type) {
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}

}

