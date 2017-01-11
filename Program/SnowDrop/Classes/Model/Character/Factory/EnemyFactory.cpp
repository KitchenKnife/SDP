//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "EnemyFactory.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data\StateMachine\Enemy\Maidead\MaideadState.h"
#include "Data\StateMachine\Enemy\NutCracker\NutCrackerState.h"
#include "Data\StateMachine\Enemy\Baron\BaronState.h"
#include "Model\Character\CharacterAggregate.h"

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐����Ǝ擾
*	@return ��ԑJ�ڃf�[�^
*	@author Shinya Ueba
*/
CStateMachine*	CEnemeyPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}

//================================================
// ���C�f�b�h�H��
//================================================
//�ړ��f�[�^�̐ݒ�
template <class Ty>
void CMaideadFactory<Ty>::settingMove(CEnemyCharacter* pChara, float posX, float posY) {

	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(posX,posY);

}

template <class Ty>
void CMaideadFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_MEIDEAD);
}

template <class Ty>
void CMaideadFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {

	//�J�n���̃A�j���[�V�����̏��
	pChara->m_animationState = (int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE;

	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 0, 256, 256));

	//���s �̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 8, true));
	(*pChara->m_pAnimations)[(int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING]->addChipData(new CChip(0, 0, 256, 256));

	//���S�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MAIDEAD_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 768, 256, 256));

	//�ǐՃA�j���[�V����
	//�����s�A�j���[�V�����Ɠ���

}

template <class Ty>
void CMaideadFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {
	//���s�L�����ɂ͏d�͂���
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

template <class Ty>
void CMaideadFactory<Ty>::settingActions(CEnemyCharacter* pChara) {
	//�J�n���̃A�N�V�����̏��
	int m_actionState = (int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;

	//--------------------------------------------------------------------
	//
	//	�ҋ@�A�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

		//�ҋ@��ԃA�N�V�����̐���
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//�ҋ@��Ԓ��ɍs���A�N�V�����𐶐����Ď�肯��
	pActionIdle->push_back(new CActionIdle());
	//�ҋ@��ԃA�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::IDLE] = pActionIdle;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------

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
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::WANDERING] = pActionStraight;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	�ǐՃA�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ǐՃA�N�V�����̐���
	std::vector<CAction*>* pActionChase = new std::vector<CAction*>();
	//�ǐՃA�N�V�������ɍs���A�N�V�����𐶐����Ď�肯��
	pActionChase->push_back(new CActionChase(false));
	//�ǐՃA�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::CHASE] = pActionChase;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	�U���󂯂��A�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U���󂯂��A�N�V�����̐���
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//�U���󂯂��A�N�V�������ɍs���A�N�V�����𐶐����Ď�肯��
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//�U���󂯂��A�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------
}


template <class Ty>
void CMaideadFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//�Փ˔����Ԃ̐ݒ�
template <class Ty>
void CMaideadFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

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
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 64.0f, 128.0f);

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
template <class Ty>
void CMaideadFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{
	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)ENEMY_MAIDEAD_STATE::IDLE;

	//�K�v�ȏ�Ԃ��쐬���Ă���

//--------------------------------------------------------------------
//
//	�ҋ@��Ԃ�ݒ肷�� ��������
//
//--------------------------------------------------------------------

	//�ҋ@���
	CStateBase* pIdleState = new CMaideadIdleState(	pChara,NULL,NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::IDLE, pIdleState);

//--------------------------------------------------------------------
//
//	�����܂�
//
//--------------------------------------------------------------------


//--------------------------------------------------------------------
//
//	�p�j��Ԃ�ݒ肷�� ��������
//
//--------------------------------------------------------------------

	//�ҋ@���
	CStateBase* pWanderingState = new CMaideadWanderingState(pChara,NULL,NULL);
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::WANDERING, pWanderingState);

//--------------------------------------------------------------------
//
//	�����܂�
//
//--------------------------------------------------------------------


//--------------------------------------------------------------------
//
//	�ǐՏ�Ԃ�ݒ肷�� ��������
//
//--------------------------------------------------------------------

//�ǐՏ��
CStateBase* pChaseState = new CMaideadChaseState(pChara, NULL, NULL);
//�쐬������Ԃ�o�^���Ă���
pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::CHASE, pChaseState);

//--------------------------------------------------------------------
//
//	�����܂�
//
//-------------------------------------------------------------------


//--------------------------------------------------------------------
//
//	�U�����󂯂���Ԃ�ݒ肷�� ��������
//
//--------------------------------------------------------------------

	//�ҋ@���
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::UNDER_ATTACK, new CMaideadUnderAttackState(pChara, NULL, NULL));

//--------------------------------------------------------------------
//
//	���S��Ԃ�ݒ肷�� ��������
//
//--------------------------------------------------------------------

	//���S���
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::DEAD, new CMaideadDeadState(pChara, NULL, NULL));


	//�Ō�ɍŏ��̏�Ԃ�ݒ肷��I�I�I�I�I
	pChara->m_pStateMachine->setStartState((int)ENEMY_MAIDEAD_STATE::IDLE);
}

template <class Ty>
void CMaideadFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//��ȃ^�[�Q�b�g
	pChara->m_targetType = TARGET_TYPE::BOTH;

	//���݂̗D��U���Ώ�
	pChara->m_currentTarget = NULL;

	//�v���C���[�����m�A�ǐՂ���͈�
	float m_chaseRange = 400;

	//�U���͈�
	float m_attackRange = 80;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;
	
	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//�X�e�[�^�X��ݒ肷��
	pChara->m_status.set(3,3,1,1);
	
	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f������B
	pChara->applyFunc();

}

//================================================
// �R�E�����H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
template <class Ty>
void CBatFactory<Ty>::settingMove(CEnemyCharacter* pChara,float x, float y) {
	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(x, y);
	//�������x
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

template <class Ty>
void CBatFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_BAT);
}

template <class Ty>
void CBatFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)ENEMY_BAT_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 64, 64, 64));

}

template <class Ty>
void CBatFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {

}

template <class Ty>
void CBatFactory<Ty>::settingActions(CEnemyCharacter* pChara) {
	

}

template <class Ty>
void CBatFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//�Փ˔����Ԃ̐ݒ�
template <class Ty>
void CBatFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
template <class Ty>
void CBatFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{

}

template <class Ty>
void CBatFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�X�e�[�^�X��ݒ肷��
	pChara->m_status.set(3, 3, 1, 3);

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;
	
	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f
	pChara->applyFunc();

}


//================================================
// �}���X�H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
template <class Ty>
void CMaliceFactory<Ty>::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(x, y);
	//�������x
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

template <class Ty>
void CMaliceFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_BAT);
}

template <class Ty>
void CMaliceFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)ENEMY_BAT_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 64, 64, 64));

}

template <class Ty>
void CMaliceFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {

}

template <class Ty>
void CMaliceFactory<Ty>::settingActions(CEnemyCharacter* pChara) {


}

template <class Ty>
void CMaliceFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//�Փ˔����Ԃ̐ݒ�
template <class Ty>
void CMaliceFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
template <class Ty>
void CMaliceFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{

}

template <class Ty>
void CMaliceFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�X�e�[�^�X��ݒ肷��
	pChara->m_status.set(3, 3, 1, 3);

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f
	pChara->applyFunc();

}

//================================================
// NutCracker�H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
template <class Ty>
void CNutCrackerFactory<Ty>::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(x, y);
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_NUTCRACKER);
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 0, 128, 128));

	//�U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)ENEMY_NUTCRACKER_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 128, 128, 128));

	//���S�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, false));
	(*pChara->m_pAnimations)[(int)ENEMY_NUTCRACKER_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 0, 128, 128));

	//�ŏ��̃A�j���[�V������ݒ�
	pChara->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {
	//���s�L�����ɂ͏d�͂���
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingActions(CEnemyCharacter* pChara) {

	//�J�n���̃A�N�V�����̏��
	int m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;

	//--------------------------------------------------------------------
	//
	//	�ҋ@�A�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ҋ@��ԃA�N�V�����̐���
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//�ҋ@��Ԓ��ɍs���A�N�V�����𐶐����Ď�肯��
	pActionIdle->push_back(new CActionIdle());
	//�ҋ@��ԃA�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE] = pActionIdle;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------

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
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::WANDERING] = pActionStraight;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	�ǐՃA�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ǐՃA�N�V�����̐���
	std::vector<CAction*>* pActionChase = new std::vector<CAction*>();
	//�ǐՃA�N�V�������ɍs���A�N�V�����𐶐����Ď�肯��
	pActionChase->push_back(new CActionChase(false));
	//�ǐՃA�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::CHASE] = pActionChase;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	�U���󂯂��A�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U���󂯂��A�N�V�����̐���
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//�U���󂯂��A�N�V�������ɍs���A�N�V�����𐶐����Ď�肯��
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//�U���󂯂��A�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-64.0f, 64.0f, 64.0f, -64.0f);
}

//�Փ˔����Ԃ̐ݒ�
template <class Ty>
void CNutCrackerFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

	//��ʒ[�Փˋ�Ԃ̐���
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//��ʉ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 64.0f);

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
template <class Ty>
void CNutCrackerFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{
	//--------------------------------------------------------------------
	//
	//	�ҋ@��Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ҋ@���
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::IDLE, new CNutCrackerIdleState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	�p�j��Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�p�j���
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::WANDERING, new CNutCrackerWanderingState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	�ǐՏ�Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ǐՏ��
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::CHASE, new CNutCrackerChaseState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	�U����Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U�����
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::ATTACK, new CNutCrackerAttackState(pChara, NULL, NULL));


	//--------------------------------------------------------------------
	//
	//	�U�����󂯂���Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U�����󂯂����
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::UNDER_ATTACK, new CNutCrackerUnderAttackState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	���S��Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//���S���
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::DEAD, new CNutCrackerDeadState(pChara, NULL, NULL));


	//�Ō�ɍŏ��̏�Ԃ�ݒ肷��I�I�I�I�I
	pChara->m_pStateMachine->setStartState((int)ENEMY_NUTCRACKER_STATE::IDLE);

}

template <class Ty>
void CNutCrackerFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�X�e�[�^�X��ݒ肷��
	pChara->m_status.set(3, 3, 1, 1);

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f
	pChara->applyFunc();

}


//================================================
// Baron�H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
template <class Ty>
void CBaronFactory<Ty>::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(x, y);
	//�������x
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

template <class Ty>
void CBaronFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_BARON);
}

template <class Ty>
void CBaronFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)ENEMY_BARON_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 0, 256, 256));

	//�U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 9, false));
	(*pChara->m_pAnimations)[(int)ENEMY_BARON_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 256, 256, 256));

	//���S�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 13, false));
	(*pChara->m_pAnimations)[(int)ENEMY_BARON_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 0, 256, 256));

	//�ŏ��̃A�j���[�V������ݒ�
	pChara->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::IDLE;

}

template <class Ty>
void CBaronFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {
	//���s�L�����ɂ͏d�͂���
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

template <class Ty>
void CBaronFactory<Ty>::settingActions(CEnemyCharacter* pChara) {


	//�J�n���̃A�N�V�����̏��
	int m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;

	//--------------------------------------------------------------------
	//
	//	�ҋ@�A�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ҋ@��ԃA�N�V�����̐���
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//�ҋ@��Ԓ��ɍs���A�N�V�����𐶐����Ď�肯��
	pActionIdle->push_back(new CActionIdle());
	//�ҋ@��ԃA�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_BARON_ACTION_STATE::IDLE] = pActionIdle;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------

	//--------------------------------------------------------------------
	//
	//	�U���󂯂��A�N�V������ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U���󂯂��A�N�V�����̐���
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//�U���󂯂��A�N�V�������ɍs���A�N�V�����𐶐����Ď�肯��
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//�U���󂯂��A�N�V�������}�b�v�z��Ɏ��t����
	pChara->m_mapAction[(int)ENEMY_BARON_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;

	//--------------------------------------------------------------------
	//
	//	�����܂�
	//
	//--------------------------------------------------------------------
}

template <class Ty>
void CBaronFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//�Փ˔����Ԃ̐ݒ�
template <class Ty>
void CBaronFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

	//��ʒ[�Փˋ�Ԃ̐���
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//��ʉ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 64.0f, 128.0f);

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
template <class Ty>
void CBaronFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{
	//--------------------------------------------------------------------
	//
	//	�ҋ@��Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�ҋ@���
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::IDLE, new CBaronIdleState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	�U����Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U�����
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::ATTACK, new CBaronAttackState(pChara, NULL, NULL));


	//--------------------------------------------------------------------
	//
	//	�U�����󂯂���Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//�U�����󂯂����
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::UNDER_ATTACK, new CBaronUnderAttackState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	���S��Ԃ�ݒ肷�� ��������
	//
	//--------------------------------------------------------------------

	//���S���
	//�쐬������Ԃ�o�^���Ă���
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::DEAD, new CBaronDeadState(pChara, NULL, NULL));


	//�Ō�ɍŏ��̏�Ԃ�ݒ肷��I�I�I�I�I
	pChara->m_pStateMachine->setStartState((int)ENEMY_BARON_STATE::IDLE);
}

template <class Ty>
void CBaronFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�X�e�[�^�X��ݒ肷��
	pChara->m_status.set(3, 3, 1, 3);

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f
	pChara->applyFunc();

}

//================================================
// MouseKing�H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CMouseKingFactory::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(x, y);
	//�������x
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CMouseKingFactory::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_MOUSEKING);
}

void CMouseKingFactory::settingAnimations(CEnemyCharacter* pChara) {
	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 128, 128, 128));

	//�U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSEKING_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 128, 128, 128));

	//���S�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSEKING_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 0, 128, 128));

	//�ŏ��̃A�j���[�V������ݒ�
	pChara->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
}

void CMouseKingFactory::settingPhysicals(CEnemyCharacter* pChara) {
	//���s�L�����ɂ͏d�͂���
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

void CMouseKingFactory::settingActions(CEnemyCharacter* pChara) {


}


void CMouseKingFactory::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-64.0f, 64.0f, 64.0f, -64.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CMouseKingFactory::settingCollisionArea(CEnemyCharacter* pChara) {

	//��ʒ[�Փˋ�Ԃ̐���
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//��ʉ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 64.0f);

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
void CMouseKingFactory::settingStateMachine(CEnemyCharacter* pChara)
{

}

void CMouseKingFactory::settingInitialize(CEnemyCharacter* pChara) {

	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�X�e�[�^�X��ݒ肷��
	pChara->m_status.set(3, 3, 1, 3);

	//�����t���O�𗧂Ă�
	pChara->m_isAlive = true;

	//���݂̈ړ��f�[�^�ƃA�j���[�V�����𔽉f
	pChara->applyFunc();

	//CMouseKingCharacter�ɃA�b�v�L���X�g����
	CMouseKingCharacter* pMouseKing = (CMouseKingCharacter*)pChara;

	//�q���𐶐�����
	CMouseFactory henchmansFactory;

	pMouseKing->m_pHenchmans[0] = henchmansFactory.create(pMouseKing->m_pMove->m_pos.x, pMouseKing->m_pMove->m_pos.y, pMouseKing);
	pMouseKing->m_pHenchmans[1] = henchmansFactory.create(pMouseKing->m_pMove->m_pos.x, pMouseKing->m_pMove->m_pos.y, pMouseKing);

	//�L�����N�^�[���L�����N�^�[�̏W���̂Ɏ��t����
	CCharacterAggregate::getInstance()->add(pMouseKing->m_pHenchmans[0]);
	CCharacterAggregate::getInstance()->add(pMouseKing->m_pHenchmans[1]);

	//�L�����N�^�[�����C�����C���[�Ɏ��t����
	CCharacterAggregate::getInstance()->getLayer()->addChild(pMouseKing->m_pHenchmans[0]);
	CCharacterAggregate::getInstance()->getLayer()->addChild(pMouseKing->m_pHenchmans[1]);
}

//================================================
// Mouse�H��
//	�iFactoryMethod�j
//================================================
//�e�X�̃p�[�c�̃Z�b�e�B���O
void CMouseFactory::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//�����ʒu�̐ݒ�
	pChara->m_pMove->m_pos.set(x, y);
	//�������x
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CMouseFactory::settingTexture(CEnemyCharacter* pChara) {
	//�e�N�X�`���̐ݒ�
	pChara->setTexture(IMAGE_MOUSEKING);
}

void CMouseFactory::settingAnimations(CEnemyCharacter* pChara) {
	//�����A�j���[�V�����̐ݒ�
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//�����A�j���[�V�����ɐݒ肷��ׂ̃`�b�v�f�[�^�̐ݒ�
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 640, 128, 128));

	//�p�j�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::WANDERING]->addChipData(new CChip(0, 640, 128, 128));

	//�U���̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 256, 128, 128));

	//���S�̃A�j���[�V������ݒ�
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, false,3));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 384, 128, 128));

	//�ŏ��̃A�j���[�V������ݒ�
	pChara->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::IDLE;
}

void CMouseFactory::settingPhysicals(CEnemyCharacter* pChara) {
	//���s�L�����ɂ͏d�͂���
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

void CMouseFactory::settingActions(CEnemyCharacter* pChara) {


}


void CMouseFactory::settingBody(CEnemyCharacter* pChara) {
	//���̂̃{�f�B��ݒ�
	pChara->m_pBody->set(-64.0f, 64.0f, 64.0f, -64.0f);
}

//�Փ˔����Ԃ̐ݒ�
void CMouseFactory::settingCollisionArea(CEnemyCharacter* pChara) {

	//��ʒ[�Փˋ�Ԃ̐���
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//��ʉ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//��ʍ��[�̈�̐����Ǝ��t��
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//��ʒ[�̏Փ˔�������t����
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//�}�b�v�Փˋ�Ԃ̐���
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 64.0f);

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

/**
*	@desc ��ԑJ�ڃf�[�^�̐ݒ�
*	@param �ݒ肷��L�����N�^�[
*	@author Shinya Ueba
*/
void CMouseFactory::settingStateMachine(CEnemyCharacter* pChara)
{

}

void CMouseFactory::settingInitialize(CEnemyCharacter* pChara) {

	//��Ԃ�ҋ@��ԂɕύX
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//�L���t���O�𗧂Ă�
	pChara->m_activeFlag = true;

	//�X�e�[�^�X��ݒ肷��
	pChara->m_status.set(3, 3, 1, 3);

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

//�C���X�^���X�̔j��
void CEnemyFactoryManager::removeInstance() {
	if (CEnemyFactoryManager::m_pEnemyFactoryManager != NULL) {
		SAFE_DELETE(CEnemyFactoryManager::m_pEnemyFactoryManager);
	}
}