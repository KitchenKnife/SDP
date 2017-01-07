#include "GirlCharacter.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data/Enum/EnumPlayer.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"

//====================================================
// �����N���X�̃����o�֐���`
//
//	2016/12/22
//									Author Harada
//									Author Shinya Ueba
//====================================================
//�R���X�g���N�^
CPlayerCharacterGirl::CPlayerCharacterGirl() {}

//�f�X�g���N�^
CPlayerCharacterGirl::~CPlayerCharacterGirl() {}

//����������
bool CPlayerCharacterGirl::init() {

	if (CCharacter::init() == false) {
		CCLOG("CCharacter�������Ɏ��s");
		return false;
	}

	return true;
}


//�ړ�����
void CPlayerCharacterGirl::moveFunc() {

	//����ł����΂�
	if (this->m_activeFlag == false)
		return;

	//�A�N�V������Ԃ̍X�V����
	if (this->m_mapAction[this->m_actionState])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_actionState])) {
			pAction->update(this);
		}
	}


	//�����v�Z
	for (CPhysical* pPhysical : (*this->m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}


//�A�j���[�V��������
void CPlayerCharacterGirl::animationFunc() {

	//�v���C���[�A�j���[�V����
	(*this->m_pAnimations)[this->m_animationState]->update();

}


//�Փ˔��菈��
void CPlayerCharacterGirl::collisionAll() {
	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}

	//�S�ẴL�����N�^�[�Ƃ̏Փ˔���
	std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();
	for (CCharacter* pChara : (*pCharacters)) {
		//��̂̃L�����Ƃ̏Փ˔���
		this->collision(pChara);
	}
}


/**
*	@desc ��Ԃ̃`�F�b�N
*	@author					Harada
*	@author					Shinya Ueba
*/
void CPlayerCharacterGirl::checkState() {

	//�v���C���[�Ə����̏�Ԃ��t���[��������
	if (this->m_pPlayerChara->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE) {
		//�v���C���[�Ƃ̋������v�����ăp�[�e�B�N���𐶐����邩���肷��
		this->checkPlayerAndGirlActionMark();
	}

	//�p�[�e�B�N���A�j���[�V����
	//�p�[�e�B�N�������݂��Ă����
	if (this->m_pActionMark)
	{
		//�J�E���^�[�X�V
		this->m_counterActionMark--;

		//�J�E���^�[���O�ȉ��ɂȂ��
		if (this->m_counterActionMark <= 0)
		{
			//�p�[�e�B�N�����O��
			this->m_pActionMark->removeFromParent();

			//�p�[�e�B�N���ۊǗp�ϐ���NULL����
			this->m_pActionMark = NULL;
		}
	}

	if(this->m_pStateMachine)
	{
		//��ԑJ�ڃ}�V���̍X�V
		this->m_pStateMachine->update();
	}
}


//���f����
void CPlayerCharacterGirl::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pAnimations)[this->m_animationState]->getCurrentChip());
}


/**
 * @desc	�L�����N�^�[1�̂Ƃ̏Փ˔��菈��
 * @param	�L�����N�^�[�̃A�h���X
 * @return	true...�Փ˂���
 */
bool CPlayerCharacterGirl::collision(CCharacter* pChara) {

	return true;
}

/**
 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
 * @param	�L�����N�^�[�̃A�h���X
 */
void CPlayerCharacterGirl::hits(CCharacter* pChara) {

}

/**
 * @desc	�v���C���[�Ə����̃A�N�V�����\�}�[�N���o�������邩�`�F�b�N����
 */
void CPlayerCharacterGirl::checkPlayerAndGirlActionMark(void) {
	//���łɃ}�[�N���o�����Ă����珈�����Ȃ�
	if (this->m_pActionMark) {
		return;
	}
	//�v���C���[�Ə����̋������v��
	float distanceToGirl = customMath->lengthBitweenChara(this->m_pPlayerChara, this);
	
	//�������P�O�O�ȉ��Ȃ�
	if (distanceToGirl <= 100.0f)
	{
		//�p�[�e�B�N���𐶐����ݒ肷��B
		this->setPlayerAndGirlActionMark();
	}
}

/**
 * @desc	�v���C���[�Ə����̃A�N�V�����\�}�[�N���o�Ă��邩�擾
 * @author	Shinya Ueba
 */
void CPlayerCharacterGirl::setPlayerAndGirlActionMark(void)
{
	//�}�[�N�̃p�[�e�B�N���𐶐�
	cocos2d::CCParticleSystemQuad* pGrapsMark = cocos2d::CCParticleSystemQuad::create(PARTICLE_GRAPS_MARK);
	//�p�[�e�B�N�����n�߂�����Đ�������
	pGrapsMark->resetSystem();
	//�����̃p�[�e�B�N���ۊǕϐ��ɑ��
	this->m_pActionMark = pGrapsMark;

	//
	this->m_durationMark = 1.0f;
	this->m_pActionMark->setDuration(this->m_durationMark);
	this->m_counterActionMark = this->m_durationMark * 60;


	this->getParent()->addChild(this->m_pActionMark);
	if (this->m_pPlayerChara->m_pMove->m_pos.x <= this->m_pMove->m_pos.x)
	{
		this->m_pActionMark->setPosition(this->m_pMove->m_pos.x + this->m_pBody->m_left * 0.2f,this->m_pMove->m_pos.y);
	}
	else
	{
		this->m_pActionMark->setPosition(this->m_pMove->m_pos.x + this->m_pBody->m_right * 0.2f, this->m_pMove->m_pos.y);
	}
}

/**
 * @desc	�v���C���[�Ə����̃A�N�V�����\�}�[�N���쐬���ăK�[���Ɏ��t����
 * @return	true...�}�[�N���o�����Ă���B
 * @author	Shinya Ueba
 */
bool CPlayerCharacterGirl::getPlayerAndGirlActionMark(void)
{
	if (this->m_pActionMark) {
		return true;
	}
	else {
		return false;
	}
}
