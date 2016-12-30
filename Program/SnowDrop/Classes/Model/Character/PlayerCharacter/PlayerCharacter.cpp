
/*
* PlayerCharacter.cpp
*
*	2016/12/1	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "PlayerCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Data\Enum\EnumPlayer.h"
#include "Model\Character\CharacterAggregate.h"

//================================================	
//	���N�N���X�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//
//	2016/12/22
//									Author Harada
//================================================
//�R���X�g���N�^
CPlayerCharacterBoy::CPlayerCharacterBoy() {}

//�f�X�g���N�^
CPlayerCharacterBoy::~CPlayerCharacterBoy() {}

//����������
bool CPlayerCharacterBoy::init() {

	if (CCharacter::init() == false) {
		CCLOG("�v���C���[�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	return true;
}

//�ړ�����
void CPlayerCharacterBoy::moveFunc() {

	//����ł����΂�
	if (this->m_activeFlag == false)
		return;

	//���͏���
	//this->inputFunc();

	//�A�N�V�����̍X�V����
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
void CPlayerCharacterBoy::animationFunc() {


	//�v���C���[�A�j���[�V����
	(*this->m_pAnimations)[this->m_animationState]->update();



	//�p�[�e�B�N���A�j���[�V����
	if (this->m_pGrapsMark)
	{
		this->m_counterGrapsMark--;

		if (this->m_counterGrapsMark <= 0)
		{
			this->m_pGrapsMark->removeFromParent();

			this->m_pGrapsMark = NULL;
		}
	}
}


//�Փ˔��菈��
void CPlayerCharacterBoy::collisionAll() {
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

//��ԃ`�F�b�N
void CPlayerCharacterBoy::checkState() 
{
	if (this->m_pStateMachine)
	{
		this->m_pStateMachine->update();
	}
}


//���f����
void  CPlayerCharacterBoy::applyFunc() {


	



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
bool  CPlayerCharacterBoy::collision(CCharacter* pChara) {

	return true;
}

/**
 * @desc	���N���X����Փ˔�����󂯂��ۂ̏���
 * @param	�L�����N�^�[�̃A�h���X
 */
void CPlayerCharacterBoy::hits(CCharacter* pChara) {

}

/**
* @desc ����Ȃ����Ԃ��`�F�b�N
* @param �����i�����j
* @tips ����Ȃ����ԂȂ�"��Ȃ��t���O"���グ��
* @author Osumi
* @author Shinya Ueba
*/
void CPlayerCharacterBoy::checkHoldHands(CPlayerCharacterGirl* pGirl) {

}

/**
 * @desc ���͏���
 * @tips �ړ������ŌĂяo��
 */
void  CPlayerCharacterBoy::inputFunc() {

}

/**
*	@desc ��Ȃ��\�}�[�N�̐ݒ�
*	@param �p�[�e�B�N���C���X�^���X
*	@author	Shinya Ueba
*/
void CPlayerCharacterBoy::setGrapsMark(cocos2d::CCParticleSystemQuad* const pGrapsMark)
{
	this->m_pGrapsMark = pGrapsMark;

	this->m_durationGrapsMark = 1.0f;
	this->m_pGrapsMark->setDuration(this->m_durationGrapsMark);
	this->m_counterGrapsMark = this->m_durationGrapsMark * 60;
}

/**
*	@desc ��Ȃ��\�}�[�N�̐ݒ�
*	@param �p�[�e�B�N���C���X�^���X
*	@author	Shinya Ueba
*/
cocos2d::CCParticleSystemQuad* CPlayerCharacterBoy::getGrapsMark(void)
{
	return this->m_pGrapsMark;
}
