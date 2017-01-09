//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "DamageFactory.h"
#include "Data\Enum\EnumDamage.h"
#include "Data\StateMachine\Damage\Smoke\SmokeState.h"


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
	//��ԑJ�ڃ}�V���̎擾
	pDamage->m_pStateMachine = factory.getStateMachine();

	return pDamage;
}


//================================================
// �_���[�W�L�����̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CNearDamageFactory::settingMove(CDamageCharacter* pCharacter,cocos2d::Point pos) {
	//�ʒu�̐ݒ�
	pCharacter->m_pMove->m_pos.set(pos);

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

void CNearDamageFactory::settingInitialize(CDamageCharacter* pChara, CCharacter* pAttackChara, int activeFrame) {

	//��Ԃ̐ݒ�
	pChara->m_state = 0;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//�_���[�W�L�����N�^�[���o���������L�����N�^�[
	pChara->m_pChara = pAttackChara;

	// ���݂����Ă����t���[����
	pChara->m_activeFrame = activeFrame;

	//�X�e�[�^�X��ݒ�
	pChara->m_status.set(1,1,1,1);

	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*/
	pChara->applyFunc();

}


//================================================
// ���_���[�W�H��
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CSmokeDamageFactory::settingMove(CDamageCharacter* pCharacter, cocos2d::Point pos) {
	
	pCharacter->m_status.setSpeed(3);
	
	//�ʒu�̐ݒ�
	pCharacter->m_pMove->m_pos.set(pos);
}
void CSmokeDamageFactory::settingTexture(CDamageCharacter* pCharacter) {
	//�e�N�X�`���̐ݒ�
	pCharacter->setTexture(IMAGE_BARON);
}

void CSmokeDamageFactory::settingAnimations(CDamageCharacter* pCharacter) {
	
	//�U���̃A�j���[�V������ݒ�
	pCharacter->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pCharacter->m_pAnimations)[(int)DAMAGE_SMOKE_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 1024, 256, 256));

	//���S�̃A�j���[�V������ݒ�
	pCharacter->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pCharacter->m_pAnimations)[(int)DAMAGE_SMOKE_ANIMATION_STATE::DEAD]->addChipData(new CChip(0, 768, 256, 256));

	//�ŏ��̃A�j���[�V������ݒ�
	pCharacter->m_animationState = (int)DAMAGE_SMOKE_ANIMATION_STATE::ATTACK;

}

void CSmokeDamageFactory::settingPhysicals(CDamageCharacter* pCharacter) {
}

void CSmokeDamageFactory::settingActions(CDamageCharacter* pCharacter) {
	//�J�n���̃A�N�V�����̏��
	int m_actionState = (int)DAMAGE_SMOKE_ACTION_STATE::ATTACK;
	//--------------------------------------------------------------------
	//
	//	�ړ��A�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ړ��A�N�V�����̐���
	std::vector<CAction*>* pActionStraight = new std::vector<CAction*>();
	//�ړ��A�N�V�������ɍs���A�N�V�����𐶐����Ď�肯��
	pActionStraight->push_back(new CActionMoveStraight());
	//�ړ��A�N�V�������}�b�v�z��Ɏ��t����
	pCharacter->m_mapAction[(int)DAMAGE_SMOKE_ACTION_STATE::ATTACK] = pActionStraight;
}

void CSmokeDamageFactory::settingBody(CDamageCharacter* pCharacter) {

	pCharacter->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CSmokeDamageFactory::settingCollisionArea(CDamageCharacter* pCharacter) {
	//��ʒ[�Փˋ�Ԃ̐���
	//�����ɉ�ʒ[�̏Փˋ�ԂɏՓ˂��s�����̊�_��ݒ�
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pCharacter->m_pBody);

	//��ʉ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//��ʒ[�̏Փ˔�������t����
	pCharacter->m_pCollisionAreas->push_back(pEndOfScreenArea);

}

//�Փ˔����Ԃ̐ݒ�
void CSmokeDamageFactory::settingStateMachine(CDamageCharacter* pCharacter) {

	//��Ԃ�ҋ@��ԂɕύX
	pCharacter->m_state = (int)DAMAGE_SMOKE_STATE::ATTACK;

	//--------------------------------------------------------------------
	//
	//	�U����Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U�����
	//�쐬������Ԃ�o�^���Ă���
	pCharacter->m_pStateMachine->registerState((int)DAMAGE_SMOKE_STATE::ATTACK, new CSmokeAttackState(pCharacter));


	//--------------------------------------------------------------------
	//
	//	���S��Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//���S���
	//�쐬������Ԃ�o�^���Ă���
	pCharacter->m_pStateMachine->registerState((int)DAMAGE_SMOKE_STATE::DEAD, new CSmokeDeadState(pCharacter));


	//�Ō�ɍŏ��̏�Ԃ�ݒ肷��I�I�I�I�I
	pCharacter->m_pStateMachine->setStartState((int)DAMAGE_SMOKE_STATE::ATTACK);
}

void CSmokeDamageFactory::settingInitialize(CDamageCharacter* pChara, CCharacter* pAttackChara, int activeFrame) {

	//��Ԃ̐ݒ�
	pChara->m_state = 0;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�����Ă���t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//�_���[�W�L�����N�^�[���o���������L�����N�^�[
	pChara->m_pChara = pAttackChara;

	// ���݂����Ă����t���[����
	pChara->m_activeFrame = activeFrame;

	//�X�e�[�^�X��ݒ�
	pChara->m_status.set(1, 1, 1, 3);

	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*/
	pChara->applyFunc();

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