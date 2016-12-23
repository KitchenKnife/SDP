//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "EnemyFactory.h"
#include "../EnemyCharacter/EnemyCharacter.h"



//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================


CMove* CEnemeyPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}


std::vector<CPhysical* >* CEnemeyPartsFactory::getPhysicals() {
	//�K�p�����镨�����Z�쐬
	std::vector<CPhysical* >* pPhysicals = new std::vector<CPhysical*>;

	return pPhysicals;
}

std::vector<CAction* >* CEnemeyPartsFactory::getActions() {
	//�K�p�����镨�����Z�쐬
	std::vector<CAction* >* pActions = new std::vector<CAction*>();

	return pActions;
}

std::vector<CAnimation* >* CEnemeyPartsFactory::getAnimations() {
	//�K�p�����镨�����Z�쐬
	std::vector<CAnimation* >* pAnimations = new std::vector<CAnimation*>;

	return pAnimations;
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
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 0, 64, 64));

}

void CMaideadFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

	// ���s�L�����ɂ͏d�͂���
	pCharacter->m_pPhysicals->push_back(new CPhysicalGravity());

}

void CMaideadFactory::settingActions(CEnemyCharacter* pCharacter) {

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



void CMaideadFactory::settingInitialize(CEnemyCharacter* pCharacter) {
	//��Ԃ̐ݒ�
	//pCharacter->m_state = (int)CEnemyCharacter::STATE::FALING;

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
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pCharacter->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 64, 64, 64));

}

void CBatFactory::settingPhysicals(CEnemyCharacter* pCharacter) {

}

void CBatFactory::settingActions(CEnemyCharacter* pCharacter) {
	

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



void CBatFactory::settingInitialize(CEnemyCharacter* pCharacter) {

	

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