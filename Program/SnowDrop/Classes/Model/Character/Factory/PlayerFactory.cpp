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
#include "Data/StateMachine/Player/PlayerStateGraps.h"
#include "Data/StateMachine/Player/PlayerStateHold.h"
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
CStateMachine*	CPlayerBoyPartsFactory::getStateMachine(void){
	//�X�e�[�g�}�V�[���f�[�^�̍쐬
	return new CStateMachine();
}

/**
 * @desc	��ԑJ�ڃf�[�^�Q�̐����Ǝ擾
 * @return	��ԑJ�ڃf�[�^�Q
 * @author	Harada
 */
std::map<int, CStateMachine*>* CPlayerBoyPartsFactory::getStateMachines(void) {
	//�X�e�[�g�}�V�[���f�[�^�Q�̍쐬
	return new std::map<int, CStateMachine*>();
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

	//��ԑJ�ڌQ�̐����Ǝ擾
	pPlayerBoy->m_pStateMachines = factory.getStateMachines();

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

	//�E�W�����v �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_RIGHT]->addChipData(new CChip(0, 384, 128, 128));

	//���W�����v �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true, 4));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_LEFT]->addChipData(new CChip(512, 384, 128, 128));

	//�E���� �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FALL_RIGHT]->addChipData(new CChip(0, 384, 128, 128));

	//������ �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true, 4));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FALL_LEFT]->addChipData(new CChip(512, 384, 128, 128));

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

	//�E�W�����v�U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(5, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_ATTACK_RIGHT]->addChipData(new CChip(0, 640, 128, 128));

	//���W�����v�U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(5, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_ATTACK_LEFT]->addChipData(new CChip(0, 640, 128, 128));

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
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false,2));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_RIGHT]->addChipData(new CChip(256, 512, 128, 128));

	//���͂ލ����� �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_LEFT]->addChipData(new CChip(0, 512, 128, 128));

	//���͂񂾏�Ԃł̉E�U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_RIGHT]->addChipData(new CChip(0, 896, 128, 128));

	//���͂񂾏�Ԃł̍��U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_LEFT]->addChipData(new CChip(0, 896, 128, 128));

	//�E�������P�l��������Ԃ̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::HOLD_RIGHT]->addChipData(new CChip(256, 512, 128, 128));

	//���������P�l��������Ԃ̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::HOLD_LEFT]->addChipData(new CChip(0, 512, 128, 128));
}

void CBasePlayerBoyFactory::settingPhysicals(CPlayerCharacterBoy* pChara){
	//�d�͂�ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//���C��ݒ�
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(5.0f, 0.45f));
}

void CBasePlayerBoyFactory::settingActions(CPlayerCharacterBoy* pChara){

	//�ҋ@���̃A�N�V�����Q�̎��̂𐶐�
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//�ҋ@���ɍs���A�N�V�����𐶐����Ď�肯��
	pActionIdle->push_back(new CActionIdle());
	//�ҋ@�A�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)PLAYER_ACTION_STATE::IDLE] = pActionIdle;


	//�W�����v���̃A�N�V�����Q�̎��̂𐶐�
	std::vector<CAction*>* pActionJump = new std::vector<CAction*>();
	//�W�����v���ɍs���A�N�V�����𐶐����Ď��t����
	pActionJump->push_back(new CActionJump(5.0f, 4.0f));
	//�W�����v�A�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP] = pActionJump;
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

	//===============================================================================
	// �����Ƃ̊֌W���t���[�ȏ�Ԃ̃X�e�[�g�}�V�[���ݒ�͂�������
	//===============================================================================

	//���t����X�e�[�g�}�V�[���𐶐�����
	CStateMachine* pStateMachine = new CStateMachine();

	//�E�����ҋ@���
	CStateBase* pIdleRightState = new CPlayerIdleRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::IDLE_RIGHT, pIdleRightState);

//------------------------------------------------------------------------------------------

	//�������ҋ@���
	CStateBase* pIdleLeftState = new CPlayerIdleLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::IDLE_LEFT, pIdleLeftState);

//------------------------------------------------------------------------------------------

	//�E�������s���
	CStateBase* pWalkRightState = new CPlayerWalkRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::WALK_RIGHT, pWalkRightState);

//------------------------------------------------------------------------------------------

	//���������s���
	CStateBase* pWalkLeftState = new CPlayerWalkLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::WALK_LEFT, pWalkLeftState);

//------------------------------------------------------------------------------------------

	//�E�����W�����v��Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_RIGHT, new CPlayerJumpRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�������W�����v��Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_LEFT, new CPlayerJumpLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E����������Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::FALL_RIGHT, new CPlayerFallRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//������������Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::FALL_LEFT, new CPlayerFallLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E�����U����Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::ATTACK_RIGHT, new CPlayerAttackRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�������U����Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::ATTACK_LEFT, new CPlayerAttackLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E�����W�����v�U����Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_ATTACK_RIGHT, new CPlayerJumpAttackRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�������W�����v�U����Ԃ��쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_ATTACK_LEFT, new CPlayerJumpAttackLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E��������������
	CStateBase* pEquipRightState = new CPlayerEquipRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::EQUIP_RIGHT, pEquipRightState);

//------------------------------------------------------------------------------------------

	//����������������
	CStateBase* pEquipLeftState = new CPlayerEquipLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::EQUIP_LEFT, pEquipLeftState);

//------------------------------------------------------------------------------------------


	//�E������������������
	CStateBase* pUnEquipRightState = new CPlayerUnEquipRightState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::UN_EQUIP_RIGHT, pUnEquipRightState);

//------------------------------------------------------------------------------------------

	//��������������������
	CStateBase* pUnEquipLeftState = new CPlayerUnEquipLeftState(pChara, NULL);
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::UN_EQUIP_LEFT, pUnEquipLeftState);

//------------------------------------------------------------------------------------------


	//�E��������q�����
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::GRASP_RIGHT, new CPlayerGraspRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//����������q�����
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::GRASP_LEFT, new CPlayerGraspLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E��������q�����
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::HOLD_RIGHT, new CPlayerHoldRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//����������q�����
	//�쐬������Ԃ�o�^���Ă���
	pStateMachine->registerState((int)PLAYER_STATE::HOLD_LEFT, new CPlayerHoldLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------
	
	//�v���C���[�ɍ쐬�����X�e�[�g�}�V�[�������t����
	(*pChara->m_pStateMachines)[(int)PLAYER_AND_GIRL_STATE::FREE] = pStateMachine;



	//===============================================================================
	// �����Ƃ̊֌W�������������Ԃ̃X�e�[�g�}�V�[���ݒ�͂�������
	//===============================================================================
	//���t����X�e�[�g�}�V�[���𐶐�����
	CStateMachine* pStateMachineGrips = new CStateMachine();


	//�E��������q���őҋ@������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineGrips->registerState((int)PLAYER_STATE::IDLE_RIGHT, new CPlayerGraspIdleRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//����������q���őҋ@������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineGrips->registerState((int)PLAYER_STATE::IDLE_LEFT, new CPlayerGraspIdleLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E��������q���ŕ��s������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineGrips->registerState((int)PLAYER_STATE::WALK_RIGHT, new CPlayerGraspWalkRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//����������q���ŕ��s������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineGrips->registerState((int)PLAYER_STATE::WALK_LEFT, new CPlayerGraspWalkLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------
	//����������q���ōU��������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineGrips->registerState((int)PLAYER_STATE::ATTACK_RIGHT, new CPlayerGrapsAttackRightState(pChara, NULL));

//------------------------------------------------------------------------------------------


	//����������q���ōU��������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineGrips->registerState((int)PLAYER_STATE::ATTACK_LEFT, new CPlayerGrapsAttackLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�v���C���[�ɍ쐬�����X�e�[�g�}�V�[�������t����
	(*pChara->m_pStateMachines)[(int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS] = pStateMachineGrips;

	//===============================================================================
	// �����Ƃ̊֌W�����P�l��������Ԃ̃X�e�[�g�}�V�[���ݒ�͂�������
	//===============================================================================
	//���t����X�e�[�g�}�V�[���𐶐�����
	CStateMachine* pStateMachineHold = new CStateMachine();


	//�E�������P�l�������őҋ@������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::IDLE_RIGHT, new CPlayerHoldIdleRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//���������P�l�������őҋ@������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::IDLE_LEFT, new CPlayerHoldIdleLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E�������P�l�������ŕ��s������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::WALK_RIGHT, new CPlayerHoldWalkRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//���������P�l�������ŕ��s������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::WALK_LEFT, new CPlayerHoldWalkLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------
	//�E�������P�l�������ŃW�����v������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::JUMP_RIGHT, new CPlayerHoldJumpRightState(pChara, NULL));

//------------------------------------------------------------------------------------------


	//���������P�l�������ŃW�����v������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::JUMP_LEFT, new CPlayerHoldJumpLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�E�������P�l�������ŗ���������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::FALL_RIGHT, new CPlayerHoldFallRightState(pChara, NULL));

//------------------------------------------------------------------------------------------


	//���������P�l�������ŗ���������
	//�쐬������Ԃ�o�^���Ă���
	pStateMachineHold->registerState((int)PLAYER_STATE::FALL_LEFT, new CPlayerHoldFallLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//�v���C���[�ɍ쐬�����X�e�[�g�}�V�[�������t����
	(*pChara->m_pStateMachines)[(int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS] = pStateMachineHold;



	//�����Ƃ̏�Ԃ�FREE�ɕύX
	pChara->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;
	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)PLAYER_STATE::IDLE_RIGHT;
	//�Ō�ɍŏ��̏�Ԃ�ݒ肷��I�I�I�I�I
	(*pChara->m_pStateMachines)[pChara->m_playerAndGirlState]->setStartState(pChara->m_state);
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