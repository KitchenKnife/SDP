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
#include "Data\StateMachine\Player\PlayerState.h"
#include "Data\Enum\EnumPlayer.h"

//================================================
// ���N�L�����N�^�[�p�[�c�N���X�H��
//	�iAbstractFactory�j
//
//	2016/12/22
//									Author Harada
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

/**
*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
*	@return ��ԑJ�ڃf�[�^
*	@author Shinya Ueba
*/
CStateMachine*	CPlayerBoyPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}


//================================================
// �L�����N�^�[�̐����ߒ��𒊏ۉ������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
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
	//��ԑJ�ڃf�[�^�̐ݒ�
	this->settingStateMachine(pChara);
	//���̂ق�������
	this->settingInitialize(pChara);


	return pChara;
}

//================================================
// �L�����N�^�[�̐����Ƒg�ݗ��Ă�S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
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
	
	//���̂̎擾
	pPlayerBoy->m_pBody = factory.getBody();

	//�Փ˔����ԌQ�̎擾
	pPlayerBoy->m_pCollisionAreas = factory.getCollisionAreas();

	//��ԑJ�ڃf�[�^�̐����Ǝ擾
	pPlayerBoy->m_pStateMachine = factory.getStateMachine();

	return pPlayerBoy;
}

//================================================
// �L�����N�^�[�̃p�[�c�̃Z�b�e�B���O��S������N���X
//	�iFactoryMethod�j
//
//	2016/12/22
//									Author Harada
//================================================

//�ړ��f�[�^�̐ݒ�
void CBasePlayerBoyFactory::settingMove(CPlayerCharacterBoy* pChara){

	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(WINDOW_TOP * 0.5f, WINDOW_RIGHT * 0.5f);
}
void CBasePlayerBoyFactory::settingTexture(CPlayerCharacterBoy* pChara){
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_PLAYER);

	pChara->setScale(2.0f);
	
}

void CBasePlayerBoyFactory::settingAnimations(CPlayerCharacterBoy* pChara) {

	//�J�n���̃A�j���[�V�����̏��
	pChara->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;

	//================================================
	// �ҋ@�E���s�̃A�j���[�V�����ݒ�
	//================================================
	//�E�ҋ@ �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true, 4));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::IDLE_RIGHT]->addChipData(new CChip(512, 384, 128, 128));

	//���ҋ@ �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::IDLE_LEFT]->addChipData(new CChip(0, 384, 128, 128));

	//�E���s �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::WALK_RIGHT]->addChipData(new CChip(0, 128, 128, 128));

	//�����s �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::WALK_LEFT]->addChipData(new CChip(0, 256, 128, 128));

	//================================================
	// �U���̃A�j���[�V�����ݒ�
	//================================================
	//�E�U���i�P���ځj�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT]->addChipData(new CChip(0, 640, 128, 128));

	//�E�U���i�Q���ځj�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_RIGHT]->addChipData(new CChip(0, 768, 128, 128));

	//�E�U���i�R���ځj�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::THURD_ATTACK_RIGHT]->addChipData(new CChip(0, 896, 128, 128));

	//���U���i�P���ځj�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT]->addChipData(new CChip(0, 640, 128, 128));

	//���U���i�Q���ځj�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_LEFT]->addChipData(new CChip(0, 768, 128, 128));

	//���U���i�R���ځj�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::THURD_ATTACK_LEFT]->addChipData(new CChip(0, 896, 128, 128));

	//================================================
	// ���̑��̃A�j���[�V�����ݒ�
	//================================================
	//�E������������ �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 8, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::EQUIP_RIGHT]->addChipData(new CChip(384, 0, 128, 128));

	//�������������� �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 8, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::EQUIP_LEFT]->addChipData(new CChip(384, 0, 128, 128));

	//�E�����������O�� �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::UN_EQUIP_RIGHT]->addChipData(new CChip(0, 0, 128, 128));

	//�������������O�� �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::UN_EQUIP_LEFT]->addChipData(new CChip(0, 0, 128, 128));
	
	//���͂މE���� �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_RIGHT]->addChipData(new CChip(256, 512, 128, 128));

	//���͂ލ����� �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_LEFT]->addChipData(new CChip(0, 512, 128, 128));
}

void CBasePlayerBoyFactory::settingPhysicals(CPlayerCharacterBoy* pChara){
	//�d�͂�ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//���C��ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(4.0f, 0.45f));
}

void CBasePlayerBoyFactory::settingActions(CPlayerCharacterBoy* pChara){

	//�W�����v�A�N�V�����̐���
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//�W�����v���ɍs���A�N�V�����𐶐����Ď�肯��
	pActionIdle->push_back(new CActionJump(3.0f,4.0f));
	//�W�����v�A�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[0] = pActionIdle;


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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
void CBasePlayerBoyFactory::settingStateMachine(CPlayerCharacterBoy* pChara)
{
	
	//�K�v�ȏ�Ԃ��쐬���Ă���

	//�E�����ҋ@���
	CStateBase* pIdleRightState = new CPlayerIdleRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::IDLE_RIGHT, pIdleRightState);

//------------------------------------------------------------------------------------------

	//�������ҋ@���
	CStateBase* pIdleLeftState = new CPlayerIdleLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::IDLE_LEFT, pIdleLeftState);

//------------------------------------------------------------------------------------------

	//�E�������s���
	CStateBase* pWalkRightState = new CPlayerWalkRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::WALK_RIGHT, pWalkRightState);

//------------------------------------------------------------------------------------------

	//���������s���
	CStateBase* pWalkLeftState = new CPlayerWalkLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::WALK_LEFT, pWalkLeftState);

//------------------------------------------------------------------------------------------


	//�E�����U����Ԃ��쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::ATTACK_RIGHT, new CPlayerAttackRightState(pChara, NULL));

//------------------------------------------------------------------------------------------



	//�������U����Ԃ��쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::ATTACK_LEFT, new CPlayerAttackLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E��������������
	CStateBase* pEquipRightState = new CPlayerEquipRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::EQUIP_RIGHT, pEquipRightState);

//------------------------------------------------------------------------------------------

	//����������������
	CStateBase* pEquipLeftState = new CPlayerEquipLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::EQUIP_LEFT, pEquipLeftState);

//------------------------------------------------------------------------------------------


	//�E������������������
	CStateBase* pUnEquipRightState = new CPlayerUnEquipRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::UN_EQUIP_RIGHT, pUnEquipRightState);

//------------------------------------------------------------------------------------------

	//��������������������
	CStateBase* pUnEquipLeftState = new CPlayerUnEquipLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)PLAYER_STATE::UN_EQUIP_LEFT, pUnEquipLeftState);

//------------------------------------------------------------------------------------------



	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)PLAYER_STATE::IDLE_RIGHT;
	//�Ō�ɍŏ��̏�Ԃ�ݒ肷��I�I�I�I�I
	pChara->m_pStateMachine->setStartState(pChara->m_state);
}

void CBasePlayerBoyFactory::settingInitialize(CPlayerCharacterBoy* pChara){

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//��܂��ȃ^�C�v�ʁi�L�����N�^�[�^�C�v�j
	pChara->m_charaType = (int)CHARACTER_TYPE::PLAYER_BOY;

	//�ׂ��ȃ^�C�v�ʁi�^�O�j
	pChara->m_tag = TAG_PLAYER_1;

	//�L�����N�^�[���
	pChara->m_state = (int)PLAYER_STATE::IDLE_RIGHT;

	/*
	 *�@�v�Z�f�[�^�̂܂܂ŋN�������1�t���[�����ꂪ��������̂�
	 *�@���������ɍŌ�ɒl��Sprite�ɔ��f����
	 */
	pChara->applyFunc();

}


//================================================
// ���N�L�����N�^�[�����H����Ǘ�����N���X
//	�iSingleton�j
//
//	2016/12/22
//									Author Harada
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

//�C���X�^���X�̔j��
void CPlayerBoyFactoryManager::removeInstance() {
	if (CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager != NULL) {
		//���L�C���X�^���X�̍폜
		SAFE_DELETE(CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager);
	}
}