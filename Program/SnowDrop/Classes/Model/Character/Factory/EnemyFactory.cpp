//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "EnemyFactory.h"
#include "../EnemyCharacter/EnemyCharacter.h"
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"
#include "Data/ActionController/EnemyActionController/EnemyActionPursuit/EnemyActionPursuit.h"
#include "Data/ActionController/EnemyActionController/EnemyActionAttack/EnemyActionAttack.h"



//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================

std::map<CEnemyCharacter::STATE, CAnimation*> CEnemeyPartsFactory::getAnimations() {
	//�A�j���[�V�����f�[�^�Q�̍쐬
	std::map<CEnemyCharacter::STATE, CAnimation*> pAnimations;

	return pAnimations;
}

CMove* CEnemeyPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}


std::vector<CPhysical* >* CEnemeyPartsFactory::getPhysicals() {
	//�K�p�����镨�����Z�쐬
	std::vector<CPhysical* >* pPhysicals = new std::vector<CPhysical*>;

	return pPhysicals;
}


std::map<CEnemyCharacter::STATE, CAction*> CEnemeyPartsFactory::getActions(){
	//�s����A�N�V�����Q���쐬
	std::map<CEnemyCharacter::STATE, CAction*> pActions;

	return pActions;
}

CBody* CEnemeyPartsFactory::getBody() {
	//���̃f�[�^�̍쐬
	return new CBody();
}

std::vector<CCollisionArea* >* CEnemeyPartsFactory::getCollisionAreas() {
	//	�Փ˔����Ԃ̐���
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}

CStatus* CEnemeyPartsFactory::getStatus() {
	// �X�e�[�^�X�̍쐬
	return new CStatus();
}

//================================================
// ���C�f�b�h�H��
//================================================
void CMaideadFactory::settingMove(CEnemyCharacter* pCharacter, float posX, float posY) {

	//�����ʒu�̐ݒ�
	pCharacter->m_pMove->m_pos.set(posX,posY);
	// �������x
	pCharacter->m_pMove->m_vel.set(-1.0f, 0.0f);
}
void CMaideadFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_MEIDEAD);
}

void CMaideadFactory::settingAnimations(CEnemyCharacter* pCharacter) {


	//�����A�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY] = (new CChipNotAnimation());
	//���܂悤�A�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING] = (new CChipAnimation(5, 2 ,true));
	//�ǐՃA�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE] = (new CChipAnimation(5, 2, true));


	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY]->addChipData(new CChip(0, 0, 64, 64));
	//���܂悤�A�j���[�V�����̃`�b�v�f�[�^�ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING]->addChipData(new CChip(0, 0, 64, 64));
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING]->addChipData(new CChip(64, 0, 64, 64));
	//�ǐՃA�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE]->addChipData(new CChip(0, 0, 64, 64));
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE]->addChipData(new CChip(64, 0, 64, 64));
	
	
}

void CMaideadFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

	// ���s�L�����ɂ͏d�͂���
	pCharacter->m_pPhysicals->push_back(new CPhysicalGravity());

}

void CMaideadFactory::settingActions(CEnemyCharacter* pCharacter) {
	// �U���̐ݒ�
	
	//���Ԃɂ��ҋ@�A�N�V�����̐ݒ�
	pCharacter->m_pActions[CEnemyCharacter::STATE::STAY] = (new CEnemyActionStayAtTime(CEnemyAction::TARGET_TYPE::BOTH));
	//���܂悢�A�N�V�����̐ݒ�
	pCharacter->m_pActions[CEnemyCharacter::STATE::WANDERING] = (new CEnemyActionWondering(CEnemyAction::TARGET_TYPE::BOTH));
	//�ǐՃA�N�V�����̐ݒ�
	pCharacter->m_pActions[CEnemyCharacter::STATE::CHASE] = (new CEnemyActionChase());
}

void CMaideadFactory::settingBody(CEnemyCharacter* pCharacter) {

	pCharacter->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
	
}

//�Փ˔����Ԃ̐ݒ�
void CMaideadFactory::settingCollisionArea(CEnemyCharacter* pCharacter) {

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
	for (int i = 1; i < 4; i++) {
		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(32 - i *4 , -32)));

		//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(32 - i * 4, 32)));

		//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32,32 - i *4)));

		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32,32 - i *4)));
	}

	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pMapArea);

}

void CMaideadFactory::settingStatus(CEnemyCharacter* pCharacter) {

	pCharacter->m_pStatus->set(3, 3, 1);
	pCharacter->m_pStatus->setSpeed(2.0);
}


void CMaideadFactory::settingInitialize(CEnemyCharacter* pCharacter) {
	//��Ԃ̐ݒ�
	pCharacter->m_state = CEnemyCharacter::STATE::WANDERING;

	//�v���C���[�����m�A�ǐՂ���͈�
	pCharacter->m_chaseRange = 360;

	//���݂̗D��U���Ώ�(���C�f�b�h�͋߂���)
	//pCharacter->m_currentTarget = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//�U���͈�
	pCharacter->m_attackRange = 60;

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
// �R�E�����H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CBatFactory::settingMove(CEnemyCharacter* pCharacter,float x, float y) {

	//�����ʒu�̐ݒ�
	pCharacter->m_pMove->m_pos.set(x, y);
	// �������x
	pCharacter->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CBatFactory::settingTexture(CEnemyCharacter* pCharacter) {
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_BAT);

}

void CBatFactory::settingAnimations(CEnemyCharacter* pCharacter) {

	//�����A�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY] = (new CChipNotAnimation());
	//���܂悤�A�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING] = (new CChipAnimation(7, 6, true));
	//�ǐՃA�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE] = (new CChipAnimation(7, 6, true));


	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	pCharacter->m_pAnimations[CEnemyCharacter::STATE::STAY]->addChipData(new CChip(64*0, 62.7*2, 64, 62.7));

	//���܂悤�A�j���[�V�����̃`�b�v�f�[�^�ݒ�
	for (int i = 0; i<6; i++) {
		pCharacter->m_pAnimations[CEnemyCharacter::STATE::WANDERING]->addChipData(new CChip(64 * i, 62.7 * 0, 64, 62.7));
	}
	//�ǐՃA�j���[�V�����̐ݒ�
	for (int i = 0; i<6; i++) {
		pCharacter->m_pAnimations[CEnemyCharacter::STATE::CHASE]->addChipData(new CChip(64 * i, 62.7 * 0, 64, 62.7));
	}

}

void CBatFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

}

void CBatFactory::settingActions(CEnemyCharacter* pCharacter) {
	// �U���̐ݒ�

	//�ҋ@�A�N�V�����̐ݒ�
	pCharacter->m_pActions[CEnemyCharacter::STATE::STAY] = (new CEnemyActionStay(CEnemyAction::TARGET_TYPE::GIRL));
	//���܂悢�A�N�V�����̐ݒ�
	pCharacter->m_pActions[CEnemyCharacter::STATE::WANDERING] = (new CEnemyActionReturnLanchPos(CEnemyAction::TARGET_TYPE::GIRL, pCharacter));
	//�ǐՃA�N�V�����̐ݒ�
	pCharacter->m_pActions[CEnemyCharacter::STATE::CHASE] = (new CEnemyActionChase(true));
}

void CBatFactory::settingBody(CEnemyCharacter* pCharacter) {

	pCharacter->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CBatFactory::settingCollisionArea(CEnemyCharacter* pCharacter) {

	//��ʒ[�Փˋ�Ԃ̐���
	//�����ɉ�ʒ[�̏Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pCharacter->m_pBody);
	//��ʒ[�̈�̐���
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//��ʒ[�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N�ݒ�
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);

	//��ʒ[�̏Փ˔����Ԃɗ̈��ݒ�
	//��ʒ[�̗̈��ݒ�
	//pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//��ʍ��[�̈�̐����Ǝ��t��
	//pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
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
	//pMapArea->addTerritory(pMapChipBottomTerritory);
	//pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//��_�̐ݒ�
	for (int i = 0; i < 9; i++) {
		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(8 * i - (32), -32)));

		//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(8 * i - (32), 32)));
	}

	for (int i = 0; i < 9; i++) {
		//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(32, 8 * i - (32))));

		//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
		pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-32, 8 * i - (132))));
	}

	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pMapArea);

}

void CBatFactory::settingStatus(CEnemyCharacter* pCharacter) {

	pCharacter->m_pStatus->set(3, 3, 1);
	pCharacter->m_pStatus->setSpeed(1.8f);
}


void CBatFactory::settingInitialize(CEnemyCharacter* pCharacter) {

	//��Ԃ̐ݒ�
	pCharacter->m_state = CEnemyCharacter::STATE::STAY;

	//�v���C���[�����m�A�ǐՂ���͈�
	pCharacter->m_chaseRange = 350;

	//���݂̗D��U���Ώ�
	pCharacter->m_currentTarget = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//�U���͈�
	pCharacter->m_attackRange = 70;

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
CEnemyFactoryManager* CEnemyFactoryManager::m_pEnemyFactoryManager = NULL;

//�C���X�^���X�̎擾
CEnemyFactoryManager* CEnemyFactoryManager::getInstance() {

	if (CEnemyFactoryManager::m_pEnemyFactoryManager == NULL) {
		CEnemyFactoryManager::m_pEnemyFactoryManager = new CEnemyFactoryManager();
	}

	return CEnemyFactoryManager::m_pEnemyFactoryManager;
}