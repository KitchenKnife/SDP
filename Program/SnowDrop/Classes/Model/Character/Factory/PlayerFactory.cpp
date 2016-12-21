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

//================================================
// ���N�L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================
//�A�j���[�V�����Q�f�[�^�̐����Ǝ擾
std::vector<CAnimation* >* CPlayerBoyPartsFactory::getAnimations() {
	//�A�j���[�V�����Q�̍쐬
	return new std::vector<CAnimation*>();
}

//�ړ��f�[�^�̐����Ǝ擾
CMove* CPlayerBoyPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}

//�������Z�Q�f�[�^�̐����Ǝ擾
std::vector<CPhysical* >* CPlayerBoyPartsFactory::getPhysicals() {
	//�������Z�Q�쐬
	return new std::vector<CPhysical*>();
}

//�A�N�V�����Q�f�[�^�̐����Ǝ擾
std::vector<CAction* >* CPlayerBoyPartsFactory::getActions() {
	//�A�N�V�����Q���쐬
	return new std::vector<CAction*>();
}

//���̃f�[�^�̐����Ǝ擾
CBody* CPlayerBoyPartsFactory::getBody() {
	//���̃f�[�^�̍쐬
	return new CBody();
}

//�Փ˔����ԌQ�f�[�^�̐����Ǝ擾
std::vector<CCollisionArea* >* CPlayerBoyPartsFactory::getCollisionAreas() {
	//�Փ˔����ԌQ�̐���
	return new std::vector<CCollisionArea*>();
}

//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//================================================
//�v���C���[�̐����Ɛݒ�
CPlayerCharacterBoy* CPlayerBoyFactory::create() {

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerCharacterBoy* pChara = this->createPlayer();

	//�ړ��f�[�^�̐ݒ�
	this->settingMove(pChara);
	//�e�N�X�`���̐ݒ�
	this->settingTexture(pChara);
	//�A�j���[�V�����Q�f�[�^�̐ݒ�
	this->settingAnimations(pChara);
	//�������Z�Q�f�[�^�̐ݒ�
	this->settingPhysicals(pChara);
	//�A�N�V�����Q�f�[�^�̐ݒ�
	this->settingActions(pChara);
	//���̃f�[�^�̐ݒ�
	this->settingBody(pChara);
	//�Փ˔����ԌQ�f�[�^�̐ݒ�
	this->settingCollisionArea(pChara);

	//���̂ق�������
	this->settingInitialize(pChara);


	return pChara;
}

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
//�v���C���[�̐����Ƒg�ݗ���
CPlayerCharacterBoy* CPlayerBoyCreateFactory::createPlayer() {

	//���N�L�����N�^�[�̐���
	CPlayerCharacterBoy* pPlayerBoy = CPlayerCharacterBoy::create();

	//���N�L�����N�^�[�p�[�c�H��𐶐�
	CPlayerBoyPartsFactory  factory;

	//�ړ��̎擾
	pPlayerBoy->m_pMove = factory.getMove();

	//�A�j���[�V�����Q�̎擾
	pPlayerBoy->m_pAnimations = factory.getAnimations();
	
	//�������Z�Q�̎擾
	pPlayerBoy->m_pPhysicals = factory.getPhysicals();

	//�A�N�V�����Q�̎擾
	pPlayerBoy->m_pActions = factory.getActions();
	
	//���̂̎擾
	pPlayerBoy->m_pBody = factory.getBody();

	//�Փ˔����ԌQ�̎擾
	pPlayerBoy->m_pCollisionAreas = factory.getCollisionAreas();

	return pPlayerBoy;
}

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================

//�ړ��f�[�^�̐ݒ�
void CBasePlayerBoyFactory::settingMove(CPlayerCharacterBoy* pChara){

	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(WINDOW_TOP * 0.5f, WINDOW_RIGHT * 0.5f);
}
void CBasePlayerBoyFactory::settingTexture(CPlayerCharacterBoy* pChara){
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_PLAYER);
	
}

void CBasePlayerBoyFactory::settingAnimations(CPlayerCharacterBoy* pChara) {
	//�ҋ@�E�W�����v�B������Ԃ̃A�j���[�V������ݒ�i�z��ԍ��O�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::STAND]->addChipData(new CChip(0, 512, 256, 256));

	//�����s��Ԃ̃A�j���[�V������ݒ�i�z��ԍ��P�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::WALK_LEFT]->addChipData(new CChip(0, 256, 256, 256));

	//�E���s��Ԃ̃A�j���[�V������ݒ�i�z��ԍ��Q�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)CPlayerCharacterBoy::PLAYER_STATE::WALK_RIGHT]->addChipData(new CChip(0, 0, 256, 256));

}

void CBasePlayerBoyFactory::settingPhysicals(CPlayerCharacterBoy* pChara){
	//�d�͂�ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//���C��ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(4.0f, 0.3f));
}

void CBasePlayerBoyFactory::settingActions(CPlayerCharacterBoy* pChara){
	pChara->m_pActions->push_back(new CActionJump(3.0f, 4.0f));

}

void CBasePlayerBoyFactory::settingBody(CPlayerCharacterBoy* pChara){

	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CBasePlayerBoyFactory::settingCollisionArea(CPlayerCharacterBoy* pChara) {

	//��ʒ[�Փˋ�Ԃ̐���
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//��ʒ[�̈�̐���
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//��ʒ[�̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N�ݒ�
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//��ʉ��[�̈�����t��
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody , 64.0f , 128.0f);

	//�}�b�v�`�b�v���̈�̐���
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//�}�b�v�`�b�v���̈�ƏՓ˂����ۂ̃C�x���g�R�[���o�b�N��ݒ�
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//�}�b�v�`�b�v���̈�����t��
	pMapArea->addTerritory(pMapChipBottomTerritory);
	//�}�b�v�`�b�v��̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//�}�b�v�`�b�v�E�̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//�}�b�v�`�b�v���̈�̐����Ǝ��t��
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pMapArea);
	
}

void CBasePlayerBoyFactory::settingInitialize(CPlayerCharacterBoy* pChara){
	//��Ԃ̐ݒ�
	pChara->m_playerState = (int)CPlayerCharacterBoy::PLAYER_STATE::STAND;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//��܂��ȃ^�C�v�ʁi�L�����N�^�[�^�C�v�j
	pChara->m_charaType = (int)CHARACTER_TYPE::PLAYER_BOY;

	//�ׂ��ȃ^�C�v�ʁi�^�O�j
	pChara->m_tag = TAG_PLAYER_1;

	/*
	 *�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	 *�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	 */
	pChara->applyFunc();

}


//================================================
// ���N�L�����N�^�[�����H����Ǘ�����N���X
//	�iSingleton�j
//================================================
//���L�̃C���X�^���X�̎���
CPlayerBoyFactoryManager* CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager = NULL;

//�C���X�^���X�̎擾
CPlayerBoyFactoryManager* CPlayerBoyFactoryManager::getInstance() {

	if (CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager == NULL) {
		CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager = new CPlayerBoyFactoryManager();
	}

	return CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager;
}