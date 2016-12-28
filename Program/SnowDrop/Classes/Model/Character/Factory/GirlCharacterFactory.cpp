#include "GirlCharacterFactory.h"

/*
* PlayerFactory.cpp
*
*	2016/11/25	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "GirlCharacterFactory.h"
#include "Data\StateMachine\Girl\GirlState.h"
#include "Data\Enum\EnumGirl.h"

//=====================================================
// ���N�L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//=====================================================
//�A�j���[�V�����Q�f�[�^�̐����Ǝ擾
std::vector<CAnimation* >* CPlayerGirlPartsFactory::getAnimations() {
	//�A�j���[�V�����Q�̍쐬
	return new std::vector<CAnimation*>();
}

//�ړ��f�[�^�̐����Ǝ擾
CMove* CPlayerGirlPartsFactory::getMove() {
	//�ړ��f�[�^�̍쐬
	return new CMove();
}

//�������Z�Q�f�[�^�̐����Ǝ擾
std::vector<CPhysical* >* CPlayerGirlPartsFactory::getPhysicals() {
	//�������Z�Q�쐬
	return new std::vector<CPhysical*>();
}

//���̃f�[�^�̐����Ǝ擾
CBody* CPlayerGirlPartsFactory::getBody() {
	//���̃f�[�^�̍쐬
	return new CBody();
}

//�Փ˔����ԌQ�f�[�^�̐����Ǝ擾
std::vector<CCollisionArea* >* CPlayerGirlPartsFactory::getCollisionAreas() {
	//�Փ˔����ԌQ�̐���
	return new std::vector<CCollisionArea*>();
}

/**
*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
*	@return ��ԑJ�ڃf�[�^
*	@author Shinya Ueba
*/
CStateMachine*	CPlayerGirlPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}



//=====================================================
// ���̎q�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//=====================================================
//�v���C���[�̐����Ɛݒ�
CPlayerCharacterGirl* CPlayerGirlFactory::create() {

	//�v���C���[�̐����Ƒg�ݗ���
	CPlayerCharacterGirl* pChara = this->createPlayer();

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
	//��ԑJ�ڃf�[�^�̐ݒ�
	this->settingStateMachine(pChara);
	//���̂ق�������
	this->settingInitialize(pChara);


	return pChara;
}



//=====================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//	2016/12/23						Author	Shinya Ueba
//=====================================================
//�v���C���[�̐����Ƒg�ݗ���
CPlayerCharacterGirl* CPlayerGirlCreateFactory::createPlayer() {

	//���N�L�����N�^�[�̐���
	CPlayerCharacterGirl* pPlayerGirl = CPlayerCharacterGirl::create();

	//���N�L�����N�^�[�p�[�c�H��𐶐�
	CPlayerGirlPartsFactory  factory;

	//�ړ��̎擾
	pPlayerGirl->m_pMove = factory.getMove();

	//�A�j���[�V�����Q�̎擾
	pPlayerGirl->m_pAnimations = factory.getAnimations();

	//�������Z�Q�̎擾
	pPlayerGirl->m_pPhysicals = factory.getPhysicals();


	//���̂̎擾
	pPlayerGirl->m_pBody = factory.getBody();

	//�Փ˔����ԌQ�̎擾
	pPlayerGirl->m_pCollisionAreas = factory.getCollisionAreas();

	//��ԑJ�ڃf�[�^�̎擾
	pPlayerGirl->m_pStateMachine = factory.getStateMachine();


	return pPlayerGirl;
}

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//================================================

//�ړ��f�[�^�̐ݒ�
void CBasePlayerGirlFactory::settingMove(CPlayerCharacterGirl* pChara) {

	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(WINDOW_TOP * 0.5f, WINDOW_RIGHT * 0.5f);
}
void CBasePlayerGirlFactory::settingTexture(CPlayerCharacterGirl* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_PLAYER_GIRL);

}

void CBasePlayerGirlFactory::settingAnimations(CPlayerCharacterGirl* pChara) {

	
	//�J�n���̃A�j���[�V�����̏��
	pChara->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;


	//�E�����ҋ@��Ԃ̃A�j���[�V������ݒ�i�z��ԍ��O�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::IDLE_RIGHT]->addChipData(new CChip(0, 768, 256, 256));

	//�������ҋ@��Ԃ̃A�j���[�V������ݒ�i�z��ԍ�1�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::IDLE_LEFT]->addChipData(new CChip(0, 512, 256, 256));

	//�E�������s��Ԃ̃A�j���[�V������ݒ�i�z��ԍ�2�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::WALK_RIGHT]->addChipData(new CChip(0, 256, 256, 256));

	//���������s��ԏ�Ԃ̃A�j���[�V������ݒ�i�z��ԍ�3�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::WALK_LEFT]->addChipData(new CChip(0, 0, 256, 256));

	//�E�����ҋ@��Ԃ̃A�j���[�V������ݒ�i�z��ԍ�4�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false,2));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::GRASP_RIGHT]->addChipData(new CChip(512, 1536, 256, 256));

	//�������ҋ@��Ԃ̃A�j���[�V������ݒ�i�z��ԍ�5�j
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)GIRL_ANIMATION_STATE::GRASP_LEFT]->addChipData(new CChip(0, 1536, 256, 256));
	

}

void CBasePlayerGirlFactory::settingPhysicals(CPlayerCharacterGirl* pChara) {
	//�d�͂�ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//���C��ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(4.0f, 0.3f));
}

void CBasePlayerGirlFactory::settingActions(CPlayerCharacterGirl* pChara) {
	

}

void CBasePlayerGirlFactory::settingBody(CPlayerCharacterGirl* pChara) {

	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CBasePlayerGirlFactory::settingCollisionArea(CPlayerCharacterGirl* pChara) {

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
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 64.0f, 128.0f);

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
void CBasePlayerGirlFactory::settingStateMachine(CPlayerCharacterGirl* pChara)
{
	//�K�v�ȏ�Ԃ��쐬���Ă���

//---------------------------------------------------------------------------------------------------------------------
//
// �ҋ@���
//
//---------------------------------------------------------------------------------------------------------------------
	//�E����
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::IDLE_RIGHT, new CGirlIdleRightState(pChara));
	//������
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::IDLE_LEFT, new CGirlIdleLeftState(pChara));

//---------------------------------------------------------------------------------------------------------------------
//
// ���s���
//
//---------------------------------------------------------------------------------------------------------------------
	//�E����
	//pChara->m_pStateMachine->registerState((int)GIRL_STATE::WALK_RIGHT, new CGirlIdleRightState(pChara));
	//������
	//pChara->m_pStateMachine->registerState((int)GIRL_STATE::WALK_LEFT, new CGirlIdleLeftState(pChara));


//---------------------------------------------------------------------------------------------------------------------
//
// ����q�����
//
//---------------------------------------------------------------------------------------------------------------------
	//�E����
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::GRASP_RIGHT, new CGirlGraspRightState(pChara));
	//������
	pChara->m_pStateMachine->registerState((int)GIRL_STATE::GRASP_LEFT, new CGirlGraspLeftState(pChara));

	

	//�Ō�ɍŏ��̏�Ԃ�ݒ肷��I�I�I�I�I
	pChara->m_state = (int)GIRL_STATE::IDLE_LEFT;
	pChara->m_pStateMachine->setStartState(pChara->m_state);
}


void CBasePlayerGirlFactory::settingInitialize(CPlayerCharacterGirl* pChara) {
	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//��܂��ȃ^�C�v�ʁi�L�����N�^�[�^�C�v�j
	pChara->m_charaType = (int)CHARACTER_TYPE::PLAYER_GIRL;

	//�ׂ��ȃ^�C�v�ʁi�^�O�j
	pChara->m_tag = TAG_PLAYER_2;

	/*
	*�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	*�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	*/
	pChara->applyFunc();

}

//================================================
// �����L�����N�^�[�����H����Ǘ�����N���X
//	�iSingleton�j
//
//	2016/12/22
//									Author Harada
//================================================
//���L�̃C���X�^���X�̎���
CPlayerGirlFactoryManager* CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager = NULL;

//�C���X�^���X�̎擾
CPlayerGirlFactoryManager* CPlayerGirlFactoryManager::getInstance() {

	if (CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager == NULL) {
		CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager = new CPlayerGirlFactoryManager();
	}

	return CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager;
}

//�C���X�^���X�̔j��
void CPlayerGirlFactoryManager::removeInstance() {
	if (CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager != NULL) {
		//���L�C���X�^���X�̍폜
		SAFE_DELETE(CPlayerGirlFactoryManager::m_pPlayerGirlFactoryManager);
	}
}
	