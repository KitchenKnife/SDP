//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "DamageFactory.h"

//================================================
// �L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//================================================
//�f�X�g���N�^
CDamagePartsFactory::~CDamagePartsFactory() {}

//�ړ��f�[�^�̎��̂𐶐����擾
CMove* CDamagePartsFactory::getMove() {
	return new CMove();
}

//�������Z�Q�f�[�^�̎��̂𐶐����擾
std::vector<CPhysical* >* CDamagePartsFactory::getPhysicals() {
	return new std::vector<CPhysical*>();
}


//�A�j���[�V�����Q�f�[�^�̎��̂𐶐����擾
std::vector<CAnimation* >* CDamagePartsFactory::getAnimations() {
	return new std::vector<CAnimation*>();
}

//���̃f�[�^�̎��̂𐶐����擾
CBody* CDamagePartsFactory::getBody() {
	return new CBody();
}

//�Փ˔����ԌQ�f�[�^�̎��̂𐶐����擾
std::vector<CCollisionArea* >* CDamagePartsFactory::getCollisionAreas() {
	return new std::vector<CCollisionArea*>();
}

/**
*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
*	@return ��ԑJ�ڃf�[�^
*	@author Shinya Ueba
*/
CStateMachine*	CDamagePartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}


//================================================
// �����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//================================================
//�M�~�b�N�̐����Ƒg�ݗ���
CDamageCharacter* CDamageCreateFactory::createDamage() {

	CDamageCharacter* pDamage = CDamageCharacter::create();

	// �H��
	CDamagePartsFactory factory;

	//�ړ��p�f�[�^�̎擾
	pDamage->m_pMove = factory.getMove();
	//�A�j���[�V�����f�[�^�Q�̎擾
	pDamage->m_pAnimations = factory.getAnimations();
	//�K�p���镨�����Z�Q�̎擾
	pDamage->m_pPhysicals = factory.getPhysicals();
	//�Փ˔���p�f�[�^�̎擾
	pDamage->m_pBody = factory.getBody();
	//�Փ˔����ԌQ�̎擾
	pDamage->m_pCollisionAreas = factory.getCollisionAreas();

	return pDamage;
}


//================================================
// �_���[�W�L�����̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CNearDamageFactory::settingMove(CDamageCharacter* pCharacter,CCharacter* pAttackChara) {

	// �L�����̑O���ɏo��
	if (pAttackChara->m_pMove->m_vel.x > 0) {
		// ��
		//�����ʒu�̐ݒ�
		pCharacter->m_pMove->m_pos.set(pAttackChara->m_pMove->m_pos.x + pAttackChara->m_pBody->m_right ,
										pAttackChara->m_pMove->m_pos.y);

	}
	else if(pAttackChara->m_pMove->m_vel.x < 0) {
		// ��
		//�����ʒu�̐ݒ�
		pCharacter->m_pMove->m_pos.set(pAttackChara->m_pMove->m_pos.x + pAttackChara->m_pBody->m_left,
										pAttackChara->m_pMove->m_pos.y);
	}

}
void CNearDamageFactory::settingTexture(CDamageCharacter* pCharacter) {
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_SAMPLE_WEAPON);

}

void CNearDamageFactory::settingAnimations(CDamageCharacter* pCharacter) {
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());

	(*pCharacter->m_pAnimations)[0]->addChipData(new CChip(0,0,48, 54));
}

void CNearDamageFactory::settingPhysicals(CDamageCharacter* pCharacter) {
}

void CNearDamageFactory::settingActions(CDamageCharacter* pCharacter) {

	//pCharacter->m_pActions->push_back(new CActionMoveStraight(2.0f));
	//CActionJump* pAction = (CActionJump*)(*pCharacter->m_pActions)[0];

	//pAction->set(3.0f, 4);
}

void CNearDamageFactory::settingBody(CDamageCharacter* pCharacter) {

	pCharacter->m_pBody->set(-24.0f, 27.0f, 24.0f, -27.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CNearDamageFactory::settingCollisionArea(CDamageCharacter* pCharacter) {

}

//�Փ˔����Ԃ̐ݒ�
void CNearDamageFactory::settingStateMachine(CDamageCharacter* pCharacter) {

}

void CNearDamageFactory::settingInitialize(CDamageCharacter* pCharacter,int activeFrame) {

	//��Ԃ̐ݒ�
	pCharacter->m_state = 0;

	//�L���t���O�𗧂Ă�
	pCharacter->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pCharacter->m_isAlive = true;

	// ���݂����Ă����t���[����
	pCharacter->m_activeFrame = activeFrame;

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
CDamageFactoryManager* CDamageFactoryManager::m_pDamageFactoryManager = NULL;

//�C���X�^���X�̎擾
CDamageFactoryManager* CDamageFactoryManager::getInstance() {

	//���L�C���X�^���X�����݂��Ă��Ȃ����
	if (CDamageFactoryManager::m_pDamageFactoryManager == NULL) {
		//���L�C���X�^���X�𐶐�
		CDamageFactoryManager::m_pDamageFactoryManager = new CDamageFactoryManager();
	}

	//���L�̃C���X�^���X��Ԃ��B
	return CDamageFactoryManager::m_pDamageFactoryManager;
}