
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
CPlayerCharacterBoy::~CPlayerCharacterBoy() {
	
	//�X�e�[�g�}�V�[���Q�̍폜
	std::map<int, CStateMachine*>::iterator itr = (*this->m_pStateMachines).begin();
	while (itr != (*this->m_pStateMachines).end()) {
		SAFE_DELETE(itr->second);

		itr++;
	}
	SAFE_DELETE(this->m_pStateMachines);
	
	//�}�b�v�^�A�j���[�V�����Q�̍폜
	std::map<int, CAnimation*>::iterator anim_itr = (*this->m_pMapAnimations).begin();
	while (anim_itr != (*this->m_pMapAnimations).end()) {
		SAFE_DELETE(anim_itr->second);
		
		anim_itr++;
	}
	SAFE_DELETE(this->m_pMapAnimations);
	
}

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
	if (this->m_mapAction[this->m_state])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_state])) {
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
	if ((*this->m_pMapAnimations)[this->m_state + this->m_playerAndGirlState + this->m_playerDirectionState])
	{
		(*this->m_pMapAnimations)[this->m_state + this->m_playerAndGirlState + this->m_playerDirectionState]->update();
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
	if (this->m_pStateMachines)
	{
		(*this->m_pStateMachines)[this->m_playerAndGirlState]->update();
	}
}


//���f����
void  CPlayerCharacterBoy::applyFunc() {
	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);


	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect((*this->m_pMapAnimations)[this->m_state + this->m_playerAndGirlState + this->m_playerDirectionState ]->getCurrentChip());

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