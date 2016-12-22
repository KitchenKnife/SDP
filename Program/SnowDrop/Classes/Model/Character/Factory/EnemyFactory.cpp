//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "EnemyFactory.h"

//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================
//�f�X�g���N�^
CEnemeyPartsFactory::~CEnemeyPartsFactory(){}

//�ړ��f�[�^�̎��̂𐶐����擾
CMove* CEnemeyPartsFactory::getMove() {
	return new CMove();
}

//�������Z�Q�f�[�^�̎��̂𐶐����擾
std::vector<CPhysical* >* CEnemeyPartsFactory::getPhysicals() {
	return new std::vector<CPhysical*>();
}

//�A�N�V�����Q�f�[�^�̎��̂𐶐����擾
std::vector<CAction* >* CEnemeyPartsFactory::getActions() {
	return new std::vector<CAction*>();
}

//�A�j���[�V�����Q�f�[�^�̎��̂𐶐����擾
std::vector<CAnimation* >* CEnemeyPartsFactory::getAnimations() {
	return new std::vector<CAnimation*>();
}

//���̃f�[�^�̎��̂𐶐����擾
CBody* CEnemeyPartsFactory::getBody() {
	return new CBody();
}

//�Փ˔����ԌQ�f�[�^�̎��̂𐶐����擾
std::vector<CCollisionArea* >* CEnemeyPartsFactory::getCollisionAreas() {
	return new std::vector<CCollisionArea*>();
}


//================================================
// ���C�f�b�h�H��
//================================================
void CMaideadFactory::settingMove(CEnemyCharacter* pChara, float posX, float posY) {

	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(posX,posY);
	//�������x
	pChara->m_pMove->m_vel.set(-1.0f, 0.0f);
}
void CMaideadFactory::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_MEIDEAD);
}

void CMaideadFactory::settingAnimations(CEnemyCharacter* pChara) {


	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 0, 64, 64));

}

void CMaideadFactory::settingPhysicals(CEnemyCharacter* pChara) {
	//���s�L�����ɂ͏d�͂���
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

void CMaideadFactory::settingActions(CEnemyCharacter* pChara) {

}

void CMaideadFactory::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CMaideadFactory::settingCollisionArea(CEnemyCharacter* pChara) {

	//��ʒ[�Փˋ�Ԃ̐���
	//�����ɉ�ʒ[�̏Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//��ʉ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 32.0f);

	//�}�b�v�`�b�v���[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
	//�}�b�v�`�b�v��[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//�}�b�v�`�b�v�E�[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//�}�b�v�`�b�v���[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pMapArea);
}



void CMaideadFactory::settingInitialize(CEnemyCharacter* pChara) {
	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)CEnemyCharacter::STATE::STAND;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;
	
	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;
	
	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f������B
	pChara->applyFunc();

}

//================================================
// �R�E�����H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CBatFactory::settingMove(CEnemyCharacter* pChara,float x, float y) {
	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(x, y);
	//�������x
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CBatFactory::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_BAT);
}

void CBatFactory::settingAnimations(CEnemyCharacter* pChara) {
	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 64, 64, 64));

}

void CBatFactory::settingPhysicals(CEnemyCharacter* pChara) {

}

void CBatFactory::settingActions(CEnemyCharacter* pChara) {
	

}

void CBatFactory::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CBatFactory::settingCollisionArea(CEnemyCharacter* pChara) {

	//��ʒ[�Փˋ�Ԃ̐���
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//��ʉ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 32.0f);

	//�}�b�v�`�b�v���[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
	//�}�b�v�`�b�v��[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//�}�b�v�`�b�v�E�[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//�}�b�v�`�b�v���[�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pMapArea);

}



void CBatFactory::settingInitialize(CEnemyCharacter* pChara) {

	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)CEnemyCharacter::STATE::STAND;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;
	
	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f
	pChara->applyFunc();

}

//================================================
// �p�[�c�Z�b�e�B���O�N���X���Ǘ�����N���X
//	�iFactoryMethod�j
//================================================
//���L�̃C���X�^���X�̎���
CEnemyFactoryManager* CEnemyFactoryManager::m_pEnemyFactoryManager = NULL;

//�C���X�^���X�̎擾
CEnemyFactoryManager* CEnemyFactoryManager::getInstance() {

	//���L�C���X�^���X�����݂��Ă��Ȃ����
	if (CEnemyFactoryManager::m_pEnemyFactoryManager == NULL) {
		//���L�C���X�^���X�𐶐�
		CEnemyFactoryManager::m_pEnemyFactoryManager = new CEnemyFactoryManager();
	}

	//���L�̃C���X�^���X��Ԃ��B
	return CEnemyFactoryManager::m_pEnemyFactoryManager;
}