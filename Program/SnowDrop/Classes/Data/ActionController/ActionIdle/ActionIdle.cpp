//==========================================
//
// File: ActionIdle.cpp
//
// �A�N�V�����@�ҋ@ �@�t�@�C��
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "ActionIdle.h"
#include "Model\Character\Character.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Data/Enum/EnumPlayer.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"
#include "Model/Character/CharacterAggregate.h"

//==========================================
//
// Class: ActionIdle
//
// �A�N�V�����@�ҋ@		�N���X
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc �R���X�g���N�^
*/
CActionIdle::CActionIdle()
{
	//�����Ɠ����ɊJ�n
	this->start();
}

/**
* @desc �A�N�V�����J�n
*/
void CActionIdle::start(void)
{
	//�A�N�V�����J�n
	this->m_inAction = true;
}

/**
* @desc �X�V����
* @param �A�N�V�������s���Ώۂ̃L�����N�^�[
*/
void CActionIdle::update(CCharacter* pChara)
{
	
}

/**
* @desc �A�N�V�����I��
*/
void CActionIdle::stop(void)
{
	//�A�N�V�����I��
	this->m_inAction = false;
}

//==========================================
//
// Class: ActionMove
//
// �A�N�V�����@�ړ�		�N���X
//
// 2017/01/12
//						Author Harada
//==========================================
CActionMove::CActionMove(){}

void CActionMove::start() {

}

void CActionMove::update(CCharacter* pChara) {
	//�����̃L�����N�^�[���v���C���[�L�����N�^�[�ɕϊ�����
	CPlayerCharacterBoy* pPlayer = (CPlayerCharacterBoy*)pChara;

	//�v���C���[�̌����Ă�������ɂ���Ċ��蓖�Ă�l��ω�������B
	if (pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
		pPlayer->m_pMove->m_accele.x = 2.0f;
	}
	else if (pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
		pPlayer->m_pMove->m_accele.x = -2.0f;
	}
}

void CActionMove::stop() {
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	pPlayer->m_pMove->m_accele.x = 0.0f;
}


//==========================================
//
// Class: CActionPlayerAttack
//
// �A�N�V�����@�v���C���[�U��		�N���X
//
// 2017/01/12
//						Author Harada
//==========================================
CActionPlayerAttack::CActionPlayerAttack() {}

void CActionPlayerAttack::start() {
	this->m_inAction = true;
}

void CActionPlayerAttack::update(CCharacter* pChara) {
	if (this->m_inAction == true) {
		//�v���C���[�L�����N�^�[�ɕϊ�
		CPlayerCharacterBoy* pBoy = (CPlayerCharacterBoy*)pChara;
		
		//�_���[�W�L�����N�^�[�����f�[�^���쐬
		CDamageLaunchData* pLaunchData;

		//�v���C���[�̌������E�����Ȃ�
		if (pBoy->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
			pLaunchData = new CDamageLaunchData(pChara,
				cocos2d::Point(pChara->m_pMove->m_pos.x + pChara->m_pBody->m_right, pChara->m_pMove->m_pos.y),
				1);
		}
		else if (pBoy->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
			pLaunchData = new CDamageLaunchData(pChara,
				cocos2d::Point(pChara->m_pMove->m_pos.x + pChara->m_pBody->m_left, pChara->m_pMove->m_pos.y),
				1);
		}
		//�_���[�W�L�����N�^�[�����g���K�[���쐬
		CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

		//�쐬�����g���K�[���X�P�W���[���[�ɓo�^
		CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);

		this->m_inAction = false;
		
	}
	
}

void CActionPlayerAttack::stop() {

}

//==========================================
//
// Class: CActionPlayerUnderAttack
//
// �A�N�V�����@�v���C���[ �U�����󂯂�	�N���X
//
// 2017/01/12
//						Author Harada
//==========================================
void CActionPlayerUnderAttack::update(CCharacter* pChara) {
	if (this->m_inAction == true) {
		//�v���C���[�L�����N�^�[�ɕϊ�
		CPlayerCharacterBoy* pBoy = (CPlayerCharacterBoy*)pChara;

		//�v���C���[�̌������E�����Ȃ�
		if (pBoy->m_underAttackDirection == (int)PLAYER_UNDER_ATTACK_DIRECTION::RIGHT) {
			pBoy->m_pMove->m_accele.y = 4.0;

			pBoy->m_pMove->m_accele.x = -4.0;
		}
		else if (pBoy->m_underAttackDirection == (int)PLAYER_UNDER_ATTACK_DIRECTION::LEFT) {
			pBoy->m_pMove->m_accele.y = 4.0;

			pBoy->m_pMove->m_accele.x = 4.0;
		}

		this->m_inAction = false;
	}
	else {
		CPlayerCharacterBoy* pBoy = CCharacterAggregate::getInstance()->getPlayer();

		pBoy->m_pMove->m_accele.y = 0.0f;

		pBoy->m_pMove->m_accele.x = 0.0f;
	}
}

/**
* @desc �A�N�V�����I��
*/
void CActionPlayerUnderAttack::stop(void) {
	
}