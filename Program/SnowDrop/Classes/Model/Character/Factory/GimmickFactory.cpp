//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "GimmickFactory.h"
#include "Model/Character/GimmickCharacter/GimmickCharacter.h"

//�p�[�c�����H��Q
std::vector<CGimmickPartsFactory*>partsFactories{
	new CGimmickPartsFactory(),
};

//================================================
// �M�~�b�N�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================

std::vector<CAnimation* >* CGimmickPartsFactory::getAnimations() {
	//�A�j���[�V�����f�[�^�Q�̍쐬
	std::vector<CAnimation*>* pAnimations = new std::vector<CAnimation*>;

	return pAnimations;
}

CMove* CGimmickPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}

std::vector<CPhysical* >* CGimmickPartsFactory::getPhysicals() {
	//�K�p�����镨�����Z�쐬
	std::vector<CPhysical* >* pPhysicals = new std::vector<CPhysical*>;


	return pPhysicals;
}

std::vector<CAction* >* CGimmickPartsFactory::getActions() {
	//�s����A�N�V�����Q���쐬
	std::vector<CAction* >* pActions = new std::vector<CAction*>;

	return pActions;
}

CBody* CGimmickPartsFactory::getBody() {
	//���̃f�[�^�̍쐬
	return new CBody();
}


std::vector<CCollisionArea* >* CGimmickPartsFactory::getCollisionAreas() {
	//	�Փ˔����Ԃ̐���
	std::vector<CCollisionArea* >* pCollisionAreas = new std::vector<CCollisionArea*>();

	return pCollisionAreas;
}



//================================================
// �M�~�b�N�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
//�M�~�b�N�̐����Ƒg�ݗ���
CGimmickCharacter* CGimmickCreateFactory::createGimmick() {

	CGimmickCharacter* pGimmick = CGimmickCharacter::create();

	//�ړ��p�f�[�^�̎擾
	pGimmick->m_pMove = partsFactories[0]->getMove();
	//�A�j���[�V�����f�[�^�Q�̎擾
	pGimmick->m_pAnimations = partsFactories[0]->getAnimations();
	//�K�p���镨�����Z�Q�̎擾
	pGimmick->m_pPhysicals = partsFactories[0]->getPhysicals();
	//�A�N�V�����Q�̎擾
	pGimmick->m_pActions = partsFactories[0]->getActions();
	//�Փ˔���p�f�[�^�̎擾
	pGimmick->m_pBody = partsFactories[0]->getBody();
	//�Փ˔����ԌQ�̎擾
	pGimmick->m_pCollisionAreas = partsFactories[0]->getCollisionAreas();

	return pGimmick;
}

//================================================
// �_���[�W�u���b�N�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CDamageBlockFactory::settingMove(CGimmickCharacter* pCharacter, cocos2d::Point pt) {

	//�����ʒu�̐ݒ�
	pCharacter->m_pMove->m_pos.set(pt.x, pt.y);

	//�����ʒu�̐ݒ�
	//pCharacter->m_pMove->m_vel.set(4.0f, 0.0f);
}
void CDamageBlockFactory::settingTexture(CGimmickCharacter* pCharacter) {
	//�e�N�X�`���̐ݒ�
	//pCharacter->setTexture(IMAGE_NORMAL_BULLET);

}

void CDamageBlockFactory::settingAnimations(CGimmickCharacter* pCharacter) {

	//�����A�j���[�V�����̐ݒ�
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pCharacter->m_pAnimations)[/*(int)CBulletCharacter::STATE::LAUNCHED*/0]->addChipData(new CChip(0, 0, 16, 16));

}

void CDamageBlockFactory::settingPhysicals(CGimmickCharacter* pCharacter) {
	//�d�͉��Z�̐ݒ�
	//pCharacter->m_pPhysicals->push_back(new CPhysicalGravity());
	//���C���Z�̐ݒ�
	//pCharacter->m_pPhysicals->push_back(new CPhysicalFriction(6.0f));
}

void CDamageBlockFactory::settingActions(CGimmickCharacter* pCharacter) {

	//pCharacter->m_pActions->push_back(new CActionMoveStraight(2.0f));
	//CActionJump* pAction = (CActionJump*)(*pCharacter->m_pActions)[0];

	//pAction->set(3.0f, 4);
}

void CDamageBlockFactory::settingBody(CGimmickCharacter* pCharacter) {

	pCharacter->m_pBody->set(-8.0f, 8.0f, 8.0f, -8.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CDamageBlockFactory::settingColllisionArea(CGimmickCharacter* pCharacter) {


	//��ʁ@�O�@�Փˋ�Ԃ̐���
	//�����ɉ�ʁ@�O�@�̏Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	CCollisionArea* pOutOfScreenArea = new CCollsionAreaOutOfScreen(pCharacter->m_pBody);

	//��ʍ��@�O�@�̈�̐���
	CCollisionTerritory* pEndOfScreenLeftTerritory = new CCollisionTerritoryOutOfScreenLeft();
	//��ʍ��@�O�@�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N�ݒ�
	pEndOfScreenLeftTerritory->setEventCallback(&CCharacter::collisionLeftCallback);

	//��ʉE�@�O�@�̈�̐���
	CCollisionTerritory* pEndOfScreenRightTerritory = new CCollisionTerritoryOutOfScreenRight();
	//��ʉE�@�O�@�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N�ݒ�
	pEndOfScreenRightTerritory->setEventCallback(&CCharacter::collisionRightCallback);

	//��ʒ[�̏Փ˔����Ԃɗ̈��ݒ�
	//��ʍ��@�O�@�̈��ݒ�
	pOutOfScreenArea->addTerritory(pEndOfScreenLeftTerritory);
	//��ʉE�@�O�@�̗̈��ݒ�
	pOutOfScreenArea->addTerritory(pEndOfScreenRightTerritory);

	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pOutOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap();

	//�}�b�v�`�b�v�Փˋ�Ԃɗ̈��ݒ�
	//�}�b�v�`�b�v�̈��ݒ�
	CCollisionTerritory* pBottomMapTerritory = (new CCollisionTerritoryMapChipBottom);
	pBottomMapTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	CCollisionTerritory* pTopMapTerritory = (new CCollisionTerritoryMapChipTop);
	pTopMapTerritory->setEventCallback(&CCharacter::collisionTopCallback);
	CCollisionTerritory* pRightMapTerritory = (new CCollisionTerritoryMapChipRight);
	pRightMapTerritory->setEventCallback(&CCharacter::collisionRightCallback);
	CCollisionTerritory* pLeftMapTerritory = (new CCollisionTerritoryMapChipLeft);
	pLeftMapTerritory->setEventCallback(&CCharacter::collisionLeftCallback);

	pMapArea->addTerritory(pBottomMapTerritory);
	pMapArea->addTerritory(pTopMapTerritory);
	pMapArea->addTerritory(pRightMapTerritory);
	pMapArea->addTerritory(pLeftMapTerritory);

	//��_�̐ݒ�
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(4, -8)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(-4, -8)));

	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(4, 8)));
	//��̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(-4, 8)));

	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, 4)));
	//�E�̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(8, -4)));

	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, 4)));
	//���̃}�b�v�`�b�v�Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�i���ɗ����Ȃ��悤��x��������Ƃ��炷�j
	pMapArea->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(-8, -4)));

	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pMapArea);


}

void CDamageBlockFactory::settingInitialize(CGimmickCharacter* pCharacter) {

	//��Ԃ̐ݒ�
	//pCharacter->m_state = 0;

	//���˕�����ݒ�
	//pCharacter->m_shotVector = vec;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pCharacter->m_isAlive = true;

	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*/
	pCharacter->applyFunc();

}

//================================================
// �M�~�b�N�p�[�c�Z�b�e�B���O�N���X���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//���L�̃C���X�^���X�̎���
CGimmickFactoryManager* CGimmickFactoryManager::m_pGimmickFactoryManager = NULL;


//�C���X�^���X�̎擾
CGimmickFactoryManager* CGimmickFactoryManager::getInstance() {

	if (CGimmickFactoryManager::m_pGimmickFactoryManager == NULL) {
		CGimmickFactoryManager::m_pGimmickFactoryManager = new CGimmickFactoryManager;
	}
	return CGimmickFactoryManager::m_pGimmickFactoryManager;
}