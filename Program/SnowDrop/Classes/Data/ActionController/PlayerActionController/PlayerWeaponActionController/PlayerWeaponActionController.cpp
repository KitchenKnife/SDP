
/*
* PlayerWeaponActionController.cpp
*
*	2016/11/27	Osumi
*
*/

#include "Data/ActionController/PlayerActionController/PlayerWeaponActionController/PlayerWeaponActionController.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
#include <math.h>

//===================================================================
//
//	����U���̒��ۃN���X
//�@�@�v���C���[�̓������S��
//
//===================================================================
CPlayerWeaponAttack::CPlayerWeaponAttack() {

	//���N�̃C���X�^���X
	//this->m_pBoy = CPlayerBoy::getInstance();

	//����̃C���X�^���X
	//this->m_pWeapon = this->m_pBoy->m_pWeapon;
}


//===================================================================
//	�a���A�N�V�����Q01		
//===================================================================
/*
* @desc �J�n����
*/
void CNormalSlashAttack_01::start() {
	
	//�v���C���[�L�����N�^�[�̎擾
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	//���N�̃C���X�^���X
	this->m_pBoy = (CPlayerBoy*)pPlayerChara;

	//����̃C���X�^���X
	this->m_pWeapon = this->m_pBoy->m_pWeapon;

	//�a��1�̃^�C�v
	this->m_pBoy->m_playerState = CPlayerCharacter::STATE::SLASH_ATTACK_01_1;
	this->m_pBoy->m_playerAct = CPlayerCharacter::ACTION::ATTACK;

	this->m_pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::SLASH_01;
	this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::SLASH_01_1;

	this->m_delayCounter = 0;
	this->m_attackStep = 0;

}

/*
* @desc �X�V���� 
*        ��_�̍X�V�ƁA�v���C���[�̈ړ�
* @param �Ώۂ̃L�����N�^�[
*/
void CNormalSlashAttack_01::update(CCharacter* pChara) {
	
	//�����̐ݒ�
	this->m_attackVec = this->m_pBoy->getScaleX();

	if (this->m_attackStep == 0) {
		this->start();
		this->m_attackStep = 1;
	}


	if (this->m_attackStep == 1) {
		CAnimation* pAnime = this->m_pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1];

		static int deg_1 = 90;

		if (pAnime->isEnd() != true) {
			//���͎�t�����ۂɂ���
			this->m_pBoy->m_nonInputFlag = true;
			static int actionTime = pAnime->getAnimationTime();

			deg_1 -= 90 / actionTime;

			for (cocos2d::Point* pt : (*this->m_pWeapon->m_pBasePoints)) {
				pt->x = pt->y*cos(deg_1)*this->m_attackVec;
				pt->y = pt->x*sin(deg_1);
			}
		}

		else if (pAnime->isEnd() == true) {
			
			this->m_delayCounter++;

			if (this->m_delayCounter == this->m_delayTime) {
				deg_1 = 90;

				pAnime->clear();
				this->m_pBoy->m_mapAnimations[m_pBoy->m_playerState]->clear();
				this->stop();
			}
			else if (this->m_nextActionFlag == true) {
				deg_1 = 90;

				pAnime->clear();
				this->m_pBoy->m_mapAnimations[m_pBoy->m_playerState]->clear();
				this->m_nextActionFlag = false;
				this->m_delayCounter = 0;
				this->m_attackStep = 2;
			}

		}
	}


	if (this->m_attackStep == 2) {
		this->m_pBoy->m_playerState = CPlayerCharacter::STATE::SLASH_ATTACK_01_2;
		this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::SLASH_01_2;

		CAnimation* pAnime = this->m_pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_2];

		static int deg_2 = 0;

		if (pAnime->isEnd() != true) {
			this->m_pBoy->m_nonInputFlag = true;
			static int actionTime = pAnime->getAnimationTime();

			deg_2 += 90 / actionTime;

			for (cocos2d::Point* pt : (*this->m_pWeapon->m_pBasePoints)) {
				pt->x = pt->y*cos(deg_2)*this->m_attackVec;
				pt->y = pt->x*sin(deg_2);
			}
		}

		else if (pAnime->isEnd() == true) {
			
			this->m_delayCounter++;

			if (this->m_delayCounter == this->m_delayTime) {
				deg_2 = 0;

				pAnime->clear();
				this->m_pBoy->m_mapAnimations[m_pBoy->m_playerState]->clear();
				this->stop();
			}

			else if (this->m_nextActionFlag == true) {
				deg_2 = 0;

				pAnime->clear();
				this->m_pBoy->m_mapAnimations[m_pBoy->m_playerState]->clear();
				this->m_nextActionFlag = false;
				this->m_delayCounter = 0;
				this->m_attackStep = 3;
			}

		}
	}


	if (this->m_attackStep ==3) {
		this->m_pBoy->m_playerState = CPlayerCharacter::STATE::SLASH_ATTACK_01_3;
		this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::SLASH_01_3;

		CAnimation* pAnime = this->m_pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_3];
		static const int actionTime = 40;
		static  int actionTimeCounter = 0;

		if (actionTime > actionTimeCounter) {

			actionTimeCounter++;

			this->m_pBoy->m_pMove->m_vel.x = 3.0f*this->m_attackVec;
			this->m_pWeapon->m_pMove->m_vel.x = 3.0f*this->m_attackVec;

		}
		else if (actionTime <= actionTimeCounter) {
			

			actionTimeCounter = 0;
			this->m_nextActionFlag == false;
			pAnime->clear();
			this->m_pBoy->m_mapAnimations[m_pBoy->m_playerState]->clear();	
			this->stop();

		}

	}

}


/*
* @desc �I��
* @tips ���n�����ۂɂ��̊֐����Ăяo��
*/
void CNormalSlashAttack_01::stop() {

	//���͎�t���\�ɂ���
	this->m_pBoy->m_nonInputFlag = false;

	//�a��1���I�����鏈��
	this->m_pBoy->m_playerState = CPlayerCharacter::STATE::DRAWN_STAND;//:DRAWN_WEAPON;
	//this->m_pBoy->m_playerAct = CPlayerCharacter::ACTION::NONE;

	this->m_pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;
	this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::DRAWN;

	this->m_nextActionFlag = false;

	this->m_delayCounter = 0;
	this->m_attackStep = 0;
}

