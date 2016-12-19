/*
* PlayerFactory.cpp
*
*	2016/11/25	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "PlayerFactory.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
#include "Data/Collision/CollisionArea.h"

//#include "PlayerCharacter.h"

//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================
/*
std::vector<CAnimation* >* CPlayerPartsFactory::getAnimations() {
	//�A�j���[�V�����f�[�^�Q�̍쐬
	std::vector<CAnimation*>* pAnimations = new std::vector<CAnimation*>;


	return pAnimations;
}
*/

CMove* CPlayerPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}

std::vector<CPhysical* >* CPlayerPartsFactory::getPhysicals() {
	//�K�p�����镨�����Z�쐬
	std::vector<CPhysical* >* pPhysicals = new std::vector<CPhysical*>;
	//�d�͉��Z�̐ݒ�
	pPhysicals->push_back(new CPhysicalGravity());
	//���C���Z�̐ݒ�
	pPhysicals->push_back(new CPhysicalFriction());

	return pPhysicals;
}

/*
std::vector<CAction* >* CPlayerPartsFactory::getActions() {
	//�s����A�N�V�����Q���쐬
	std::vector<CAction* >* pActions = new std::vector<CAction*>;
	
	//�W�����v�A�N�V�����̐ݒ�
	pActions->push_back(new CActionJump());
	//�a��01�A�N�V�����̒ǉ�
	//pActions->push_back(new CPlayerSlashAtack());
	

	return pActions;
}
*/

CBody* CPlayerPartsFactory::getBody() {
	//���̃f�[�^�̍쐬
	return new CBody();
}

std::vector<CCollisionArea* >* CPlayerPartsFactory::getCollisionAreas() {
	//	�Փ˔����Ԃ̐���
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}

std::map<CPlayerCharacter::STATE, CAnimation*> CPlayerPartsFactory::getMapAnimations(){
	//�A�j���[�V�����f�[�^�Q�̍쐬
	std::map<CPlayerCharacter::STATE, CAnimation*> pAnimations;

	return pAnimations;
}

std::map<CPlayerCharacter::ACTION, CAction*> CPlayerPartsFactory::getMapActions(){
	//�s����A�N�V�����Q���쐬
	std::map<CPlayerCharacter::ACTION, CAction*> pActions;

	return pActions;
}

std::vector<CPlayerEffect*>* CPlayerPartsFactory::getEffects() {
	//�G�t�F�N�g�Q���쐬
	std::vector<CPlayerEffect*>* pEffects = new std::vector<CPlayerEffect*>;

	return pEffects;
}

CPlayerWeapon* CPlayerPartsFactory::getWeapon() {
	//����̐���
	CPlayerWeapon* pWeapon = NULL; //CPlayerNormalWeapon::getInstance();

	return pWeapon;
}

CStatus* CPlayerPartsFactory::getStatus() {
	// �X�e�[�^�X�̍쐬
	return new CStatus();
}

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
//�v���C���[�̐����Ƒg�ݗ���
CPlayerCharacter* CPlayerBoyCreateFactory::createPlayer() {

	CPlayerCharacter* pPlayer = CPlayerBoy::create();

	//�ړ��p�f�[�^�̎擾
	pPlayer->m_pMove = this->partsFactories[(int)PLAYER_TYPE::BOY]->getMove();
	//�A�j���[�V�����f�[�^�Q�̎擾
	//pPlayer->m_pAnimations = this->partsFactories[(int)PLAYER_TYPE::BOY]->getAnimations();
	//�K�p���镨�����Z�Q�̎擾
	pPlayer->m_pPhysicals = this->partsFactories[(int)PLAYER_TYPE::BOY]->getPhysicals();
	//�A�N�V�����Q�̎擾
	//pPlayer->m_pActions = this->partsFactories[(int)PLAYER_TYPE::BOY]->getActions();
	//�Փ˔���p�f�[�^�̎擾
	pPlayer->m_pBody = this->partsFactories[(int)PLAYER_TYPE::BOY]->getBody();
	pPlayer->m_pCollisionAreas = this->partsFactories[(int)PLAYER_TYPE::BOY]->getCollisionAreas();

	//�A�j���[�V�����f�[�^�Q�̎擾(map)
	pPlayer->m_mapAnimations = this->partsFactories[(int)PLAYER_TYPE::BOY]->getMapAnimations();
	//�A�N�V�����Q�̎擾(map)
	pPlayer->m_mapActions = this->partsFactories[(int)PLAYER_TYPE::BOY]->getMapActions();
	//�G�t�F�N�g�f�[�^�̎擾
	pPlayer->m_pEffects = this->partsFactories[(int)PLAYER_TYPE::BOY]->getEffects();
	//����f�[�^�̎擾
	//pPlayer->m_pWeapon = this->partsFactories[(int)PLAYER_TYPE::BOY]->getWeapon();

	//�X�e�[�^�X�̎擾
	pPlayer->m_pStatus = this->partsFactories[(int)PLAYER_TYPE::BOY]->getStatus();

	return pPlayer;
}

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================

//�e�X�̃p�[�c�̃Z�b�e�B���O
void CPlayerBoyFactory::settingMove(CPlayerCharacter* pCharacter){

	//�����ʒu�̐ݒ�
	//pCharacter->m_pMove->m_pos.set(320.0f, 32.0f);
	pCharacter->m_pMove->m_pos.set(900, WINDOW_RIGHT / 2.0f);
}
void CPlayerBoyFactory::settingTexture(CPlayerCharacter* pCharacter){
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_PLAYER);
	
}

void CPlayerBoyFactory::settingAnimations(CPlayerCharacter* pCharacter) {

	//�����A�j���[�V�����̐ݒ�
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::STAND] = (new CChipNotAnimation());
	//���s�A�j���[�V�����̐ݒ�
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WALK] = (new CChipListAnimation(10, true));
	//�_���[�W���󂯎��̃A�j���[�V�����ݒ�
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::HIT] = (new CChipNotAnimation());
	//�����Ă���Ƃ��̃A�j���[�V����
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::FALING] = (new CChipNotAnimation());
	//�����グ��Ƃ��̃A�j���[�V����
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING] = (new CChipListAnimation(15, true));


	//��������
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::DRAWN_STAND] = (new CChipNotAnimation());

	//�U���A�j���[�V����1-1
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_1] = (new CChipListAnimation(8, false));
	//�U���A�j���[�V����1-2
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_2] = (new CChipListAnimation(8, false));
	//�U���A�j���[�V����1-3
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_3] = (new CChipNotAnimation());


	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::STAND]->addChipData(new CChip(256 * 0, 256 * 2, 256, 256));

	//���s�A�j���[�V�����ɐݒ肷��1���ڂ̃`�b�v�f�[�^�̐ݒ�
	for (int i = 0; i < 7; i++) {
		(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WALK]->addChipData(new CChip(256 * i, 256 * 0, 256, 256));
	}

	//�_���[�W���󂯂����̃A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::HIT]->addChipData(new CChip(256 * 2, 256 * 4, 256, 256));

	//�����Ă��鎞�̃A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::FALING]->addChipData(new CChip(256 * 0, 256 * 2, 256, 256));

	//�����グ��Ƃ��̃A�j���[�V����
	for (int i = 2; i < 5; i++) {
		pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * i, 256 * 0, 256, 256));
	}
	

	//��������
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::DRAWN_STAND]->addChipData(new CChip(256 * 0, 256 * 2, 256, 256));

	//�U���A�j���[�V����1-1
	for (int i = 2; i < 6; i++) {
		pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_1]->addChipData(new CChip(256 * i, 256 * 2, 256, 256));
	}
	
	//�U���A�j���[�V����1-2
	for (int i = 2; i < 6; i++) {
		pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_2]->addChipData(new CChip(256 * i, 256 * 2, 256, 256));
	}
	
	//�U���A�j���[�V����1-3
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::SLASH_ATTACK_01_3]->addChipData(new CChip(256 * 5, 256 * 0, 256, 256));

}

void CPlayerBoyFactory::settingPhysicals(CPlayerCharacter* pCharacter){
	
	//�ō����x�Ɩ��C�̐ݒ�
	CPhysicalFriction* pFriction = (CPhysicalFriction*)(*pCharacter->m_pPhysicals)[1];
	pFriction->set(4.0f, 0.3f);
}

void CPlayerBoyFactory::settingActions(CPlayerCharacter* pCharacter){
	//�Ȃ��A�N�V�����̐ݒ�
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::NONE] = (new CPlayerNoneAction());

	//�����グ�A�N�V�����̐ݒ�
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::LIFT_UP] = (new CPlayerLiftUpAction());

	//�W�����v�A�N�V�����̐ݒ�
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::JUMP] = (new CActionJump());
	CActionJump* pAction = (CActionJump*)(pCharacter->m_mapActions)[CPlayerCharacter::ACTION::JUMP];
	//�����x�ƃu�[�X�g�̐ݒ�
	pAction->set(3.0f, 4);

	//�A�^�b�N�A�N�V�����̐ݒ�
	//�i�g���邱�Ƃ͂Ȃ��j
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::ATTACK] = (new CPlayerNoneAction());

}

void CPlayerBoyFactory::settingBody(CPlayerCharacter* pCharacter){

	pCharacter->m_pBody->set(-60.0f, 128.0f, 60.0f, -128.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CPlayerBoyFactory::settingCollisionArea(CPlayerCharacter* pCharacter) {

	//��ʒ[�Փˋ�Ԃ̐���
	//�����ɉ�ʒ[�̏Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pCharacter->m_pBody);
	//��ʒ[�̈�̐���
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//��ʒ[�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N�ݒ�
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//��ʒ[�̏Փ˔����Ԃɗ̈��ݒ�
	//��ʒ[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pEndOfScreenArea);

	
	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap();
	//�}�b�v�`�b�v�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N��ݒ�
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//���̃}�b�v�`�b�v�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N��ݒ�
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�
	//�}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pMapChipBottomTerritory);
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//��_�̐ݒ�
	for (int i = 0; i < 9; i++) {
		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16*i - (64), -128)));

		//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16*i - (64), 128)));
	}

	for (int i = 0; i < 17; i++) {
		//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(64, 16*i - (128))));

		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-64, 16*i - (128))));
	}

	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pMapArea);
	
}


void CPlayerBoyFactory::settingStatus(CPlayerCharacter* pCharacter) {

	pCharacter->m_pStatus->set(10, 10, 1);
}

//�G�t�F�N�g�̐ݒ�
void CPlayerBoyFactory::settingEffects(CPlayerCharacter* pCharacter) {
	//�����G�t�F�N�g

}

//����̐ݒ�
void CPlayerBoyFactory::settingWeapon(CPlayerCharacter* pCharacter) {
	//���̂Ƃ��떳��

}


void CPlayerBoyFactory::settingInitialize(CPlayerCharacter* pCharacter){
	//��Ԃ̐ݒ�
	pCharacter->m_playerState = CPlayerCharacter::STATE::FALING;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;
	pCharacter->m_isAlive = true;
	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*/
	pCharacter->applyFunc();

}


//================================================
// ���̎q�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
//�v���C���[�̐����Ƒg�ݗ���
CPlayerCharacter* CPlayerGirlCreateFactory::createPlayer() {

	CPlayerCharacter* pPlayer = CPlayerGirl::create();

	//�ړ��p�f�[�^�̎擾
	pPlayer->m_pMove = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getMove();
	//�A�j���[�V�����f�[�^�Q�̎擾
	//pPlayer->m_pAnimations = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getAnimations();
	//�K�p���镨�����Z�Q�̎擾
	pPlayer->m_pPhysicals = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getPhysicals();
	//�A�N�V�����Q�̎擾
	//pPlayer->m_pActions = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getActions();
	//�Փ˔���p�f�[�^�̎擾
	pPlayer->m_pBody = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getBody();
	pPlayer->m_pCollisionAreas = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getCollisionAreas();

	//�A�j���[�V�����f�[�^�Q�̎擾(map)
	pPlayer->m_mapAnimations = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getMapAnimations();
	//�A�N�V�����Q�̎擾(map)
	pPlayer->m_mapActions = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getMapActions();
	//�G�t�F�N�g�f�[�^�̎擾�imap�j
	pPlayer->m_pEffects = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getEffects();

	//������̎擾�͍s��Ȃ�

	//�X�e�[�^�X�̎擾
	pPlayer->m_pStatus = this->partsFactories[(int)PLAYER_TYPE::GIRL]->getStatus();

	return pPlayer;

}

//================================================
// ���̎q�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CPlayerGirlFactory::settingMove(CPlayerCharacter* pCharacter) {

	//�����ʒu�̐ݒ�
	//pCharacter->m_pMove->m_pos.set(288.0f, 128.0f);
	pCharacter->m_pMove->m_pos.set(980, WINDOW_RIGHT / 2.0f);
}
void CPlayerGirlFactory::settingTexture(CPlayerCharacter* pCharacter) {
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_PLAYER_GIRL);
	
}

void CPlayerGirlFactory::settingAnimations(CPlayerCharacter* pCharacter) {
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE_ANIME_01] = (new CChipListAnimation(20, true));
	//�����A�j���[�V�����̐ݒ�i�ɏ�ԁj
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE] = (new CChipNotAnimation());
	//���s�A�j���[�V�����̐ݒ�
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WALK] = (new CChipListAnimation(8, true));
	//�_���[�W���󂯎��̃A�j���[�V�����ݒ�
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::HIT] = (new CChipNotAnimation());
	//�����Ă���Ƃ��̃A�j���[�V����
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::FALING] = (new CChipNotAnimation());
	//�����グ��Ƃ��̃A�j���[�V����
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING] = (new CChipListAnimation(15, true));
	//�ɂԂ��A�j��-�V�����i�P�j
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE_ANIME_01] = (new CChipListAnimation(8, true));
	//�ɂԂ��A�j��-�V�����i�Q�j���������[�V�����Ɠ���
	//pCharacter->m_mapAnimations[CPlayerCharacter::STATE::WASTE_ANIME_02] = (new CChipListAnimation(10, true));


	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WASTE]->addChipData(new CChip(256 * 0, 256 * 3, 256 * 1, 256 * 1));

	//���s�A�j���[�V�����ɐݒ肷��1���ڂ̃`�b�v�f�[�^�̐ݒ�
	for (int i = 0; i <7; i++)  /* 7�� */ {
		(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WALK]->addChipData(new CChip(256 * i, 256 * 1, 256 * 1, 256 * 1));

	}

	//�_���[�W���󂯂����̃A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::HIT]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));

	//�����Ă��鎞�̃A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::FALING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));

	//�����グ��Ƃ��̃A�j���[�V����
	//1����
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));
	//2����
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));
	//3����
	pCharacter->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING]->addChipData(new CChip(256 * 0, 256 * 0, 256 * 1, 256 * 1));


	//�ɂԂ��A�j���[�V�����i�P�j�ɐݒ肷��`�b�v�f�[�^�̐ݒ�
	for (int i = 0; i < 6; i++)  /* 6�� */ {
		(pCharacter->m_mapAnimations)[CPlayerCharacter::STATE::WASTE_ANIME_01]->addChipData(new CChip(256 * i, 256 * 3, 256 * 1, 256 * 1));
		
	}

}

void CPlayerGirlFactory::settingPhysicals(CPlayerCharacter* pCharacter) {
	//�ō����x�Ɩ��C�̐ݒ�
	CPhysicalFriction* pFriction = (CPhysicalFriction*)(*pCharacter->m_pPhysicals)[1];
	pFriction->set(6.0f, 0.3f);
}

void CPlayerGirlFactory::settingActions(CPlayerCharacter* pCharacter) {

	//�Ȃ��A�N�V�����̐ݒ�
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::NONE] = (new CPlayerNoneAction());
	
	//�W�����v�A�N�V�����̐ݒ�
	//pCharacter->m_mapActions[CPlayerCharacter::ACTION::JUMP] = (new CActionJump());
	//CActionJump* pAction = (CActionJump*)(pCharacter->m_mapActions)[CPlayerCharacter::ACTION::JUMP];
	//�����x�ƃu�[�X�g�̐ݒ�
	//pAction->set(3.0f, 4);

	//�ɂԂ��A�N�V�����̐ݒ�
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::WASTE] = (new CGirlBaseWasteTimeAction());

	//�ɂԂ��A�N�V�����i�P�j�̐ݒ�
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::WASTE_ACT_01] = (new CGirlWasteAction_01());
	//�ɂԂ��A�N�V�����i�Q�j�̐ݒ�
	pCharacter->m_mapActions[CPlayerCharacter::ACTION::WASTE_ACT_02] = (new CGirlWasteAction_02());


}

void CPlayerGirlFactory::settingBody(CPlayerCharacter* pCharacter) {

	pCharacter->m_pBody->set(-60.0f, 128.0f, 60.0f, -128.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CPlayerGirlFactory::settingCollisionArea(CPlayerCharacter* pCharacter) {

	//��ʒ[�Փˋ�Ԃ̐���
	//�����ɉ�ʒ[�̏Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pCharacter->m_pBody);
	//��ʒ[�̈�̐���
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//��ʒ[�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N�ݒ�
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//��ʒ[�̏Փ˔����Ԃɗ̈��ݒ�
	//��ʒ[�̗̈��ݒ�
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap();
	//�}�b�v�`�b�v�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N��ݒ�
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//���̃}�b�v�`�b�v�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N��ݒ�
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�
	//�}�b�v�`�b�v�̈��ݒ�
	pMapArea->addTerritory(pMapChipBottomTerritory);
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//��_�̐ݒ�
	for (int i = 0; i < 9; i++) {
		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(16 * i - (64), -128)));

		//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(16 * i - (64), 128)));
	}

	for (int i = 0; i < 17; i++) {
		//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(64, 16 * i - (128))));

		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-64, 16 * i - (128))));
	}

	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pMapArea);

}

void CPlayerGirlFactory::settingStatus(CPlayerCharacter* pCharacter) {

	pCharacter->m_pStatus->set(10, 10, 1);
}

//�G�t�F�N�g�̐ݒ�
void CPlayerGirlFactory::settingEffects(CPlayerCharacter* pCharacter) {
	//�����G�t�F�N�g
	

}

//����̐ݒ�
void CPlayerGirlFactory::settingWeapon(CPlayerCharacter* pCharacter) {
	//���̂Ƃ��떳��

}

void CPlayerGirlFactory::settingInitialize(CPlayerCharacter* pCharacter) {
	//��Ԃ̐ݒ�
	pCharacter->m_playerState = CPlayerCharacter::STATE::FALING;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;
	pCharacter->m_isAlive = true;
	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*/
	pCharacter->applyFunc();

}


//================================================
// �p�[�c�Z�b�e�B���O�N���X���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//���L�̃C���X�^���X�̎���
CPlayerFactoryManager* CPlayerFactoryManager::m_pPlayerFactoryManager = NULL;

//�C���X�^���X�̎擾
CPlayerFactoryManager* CPlayerFactoryManager::getInstance() {

	if (CPlayerFactoryManager::m_pPlayerFactoryManager == NULL) {
		CPlayerFactoryManager::m_pPlayerFactoryManager = new CPlayerFactoryManager();
	}

	return CPlayerFactoryManager::m_pPlayerFactoryManager;
}