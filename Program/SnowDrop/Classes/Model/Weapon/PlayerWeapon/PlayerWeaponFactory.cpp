/*
* PlayerWeaponFactory.cpp
*
*	2016/11/27	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
#include "Data/ActionController/PlayerActionController/PlayerWeaponActionController/PlayerWeaponActionController.h"
//#include "PlayerCharacter.h"
/*

//================================================
// ����p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================

CMove* CPlayerWeaponPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}

CBody* CPlayerWeaponPartsFactory::getBody() {
	//���̃f�[�^�̍쐬
	return new CBody();
}

std::map<CPlayerWeapon::ATTACK_ANIME, CAnimation*> CPlayerWeaponPartsFactory::getMapAnimations() {
	//�A�j���[�V�����f�[�^�Q�̍쐬
	std::map<CPlayerWeapon::ATTACK_ANIME, CAnimation*> pAnimations;

	return pAnimations;
}

std::map<CPlayerWeapon::ATTACK_ACT, CPlayerWeaponAttack*> CPlayerWeaponPartsFactory::getMapActions() {
	//�s����A�N�V�����Q���쐬
	std::map<CPlayerWeapon::ATTACK_ACT, CPlayerWeaponAttack*> pActions;

	return pActions;
}

std::vector<cocos2d::Point*>* CPlayerWeaponPartsFactory::getPoints() {

	//�s����A�N�V�����Q���쐬
	std::vector<cocos2d::Point*>* pPoints = new std::vector<cocos2d::Point*>;

	return pPoints;
}

CStatus* CPlayerWeaponPartsFactory::getStatus() {
	// �X�e�[�^�X�̍쐬
	return new CStatus();
}


std::vector<CCollisionArea* >* CPlayerWeaponPartsFactory::getCollisionAreas() {
	//	�Փ˔����Ԃ̐���
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}

//================================================
// ����̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
//����̐����Ƒg�ݗ���
CPlayerWeapon* CPlayerNormalWeaponCreateFactory::createWeapon() {

	CPlayerWeapon* pWeapon = CPlayerNormalWeapon::create();

	//�ړ��p�f�[�^�̎擾
	pWeapon->m_pMove = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getMove();

	//�Փ˔���p�f�[�^�̎擾
	pWeapon->m_pBody = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getBody();

	//�A�j���[�V�����f�[�^�Q�̎擾(map)
	pWeapon->m_mapAnimations = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getMapAnimations();
	//�A�N�V�����Q�̎擾(map)
	pWeapon->m_mapActions = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getMapActions();
	//�Փ˔����_�̎擾
	pWeapon->m_pBasePoints= this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getPoints();

	//�X�e�[�^�X�̎擾
	pWeapon->m_pStatus = this->partsFactories[(int)WEAPON_TYPE::NORMAL]->getStatus();

	return pWeapon;
}

//================================================
// ����̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================

//�e�X�̃p�[�c�̃Z�b�e�B���O
void CPlayerNormalWeaponFactory::settingMove(CPlayerWeapon* pWeapon) {

	//cocos2d::Point pt = CPlayerBoy::getInstance()->m_pMove->m_pos;

	//�����ʒu�̐ݒ�
	pWeapon->m_pMove->m_pos.set(0,0);
}
void CPlayerNormalWeaponFactory::settingTexture(CPlayerWeapon* pWeapon) {
	//�e�N�X�`���̐ݒ�
	pWeapon->setTexture(IMAGE_SAMPLE_WEAPON);

}

void CPlayerNormalWeaponFactory::settingAnimations(CPlayerWeapon* pWeapon) {

	//�[���A�j���[�V�����̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::RETURN] = (new CChipNotAnimation());

	//�����A�j���[�V�����̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::DRAWN] = (new CChipNotAnimation());

	//�a��01-1�A�j���[�V�����̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1] = (new CChipListAnimation(6, false));

	//�a��01-2�A�j���[�V�����̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2] = (new CChipListAnimation(6, false));

	//�a��01-3�A�j���[�V�����̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_3] = (new CChipNotAnimation());


	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::RETURN]->addChipData(new CChip(48 * 0, 54 * 0, 0, 0));

	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::DRAWN]->addChipData(new CChip(48 * 0, 54 * 0, 48, 54));

	//�a��01-1�A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	//1����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 0, 54 * 0, 48, 54));
	//2����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 1, 54 * 0, 48, 54));
	//3����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 2, 54 * 0, 48, 54));
	//4����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1]->addChipData(new CChip(48 * 3, 54 * 0, 48, 54));

	//�a��01-2�A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	//1����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 0, 54 * 1, 48, 54));
	//2����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 1, 54 * 1, 48, 54));
	//3����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 2, 54 * 1, 48, 54));
	//4����
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2]->addChipData(new CChip(48 * 3, 54 * 1, 48, 54));


	//�a��01-3�A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_3]->addChipData(new CChip(48 * 3, 54 * 0, 48, 54));

}


void CPlayerNormalWeaponFactory::settingActions(CPlayerWeapon* pWeapon) {
	//�Ȃ��A�N�V�����̐ݒ�
	pWeapon->m_mapActions[CPlayerWeapon::ATTACK_ACT::NONE] = (new CPlayerNoneWeaponAction());

	//�a��01�A�N�V�����̐ݒ�
	pWeapon->m_mapActions[CPlayerWeapon::ATTACK_ACT::SLASH_01] = (new CNormalSlashAttack_01());

}

void CPlayerNormalWeaponFactory::settingBody(CPlayerWeapon* pWeapon) {

	pWeapon->m_pBody->set(-20.0f, 20.0f, 20.0f, 20.0f);
}


void CPlayerNormalWeaponFactory::settingStatus(CPlayerWeapon* pWeapon) {

	pWeapon->m_pStatus->set(10, 10, 1);
}

//�Փ˔���̊�_��ݒ�
void CPlayerNormalWeaponFactory::settingPoints(CPlayerWeapon* pWeapon) {

	(pWeapon->m_pBasePoints)->push_back(new cocos2d::Point(24,24));
}

void CPlayerNormalWeaponFactory::settingInitialize(CPlayerWeapon* pWeapon) {

	//�U���A�j��
	pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::RETURN;
	//�U���A�N�V����
	pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;

	//����̑����ʒu
	pWeapon->m_offset.set(26.0f, 4.0f);

	//�L���t���O��������
	pWeapon->m_activeFlag = true;

	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*
	pWeapon->applyFunc();

}


//================================================
// �p�[�c�Z�b�e�B���O�N���X���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//���L�̃C���X�^���X�̎���
CPlayerWeaponFactoryManager* CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager = NULL;

//�C���X�^���X�̎擾
CPlayerWeaponFactoryManager* CPlayerWeaponFactoryManager::getInstance() {

	if (CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager == NULL) {
		CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager = new CPlayerWeaponFactoryManager();
	}

	return CPlayerWeaponFactoryManager::m_pPlayerWeaponFactoryManager;
}
*/