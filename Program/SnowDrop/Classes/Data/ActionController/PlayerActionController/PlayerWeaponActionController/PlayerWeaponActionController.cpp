
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
//	武器攻撃の抽象クラス
//　　プレイヤーの動きも担う
//
//===================================================================
CPlayerWeaponAttack::CPlayerWeaponAttack() {

	//少年のインスタンス
	//this->m_pBoy = CPlayerBoy::getInstance();

	//武器のインスタンス
	//this->m_pWeapon = this->m_pBoy->m_pWeapon;
}


//===================================================================
//	斬撃アクション＿01		
//===================================================================
/*
* @desc 開始処理
*/
void CNormalSlashAttack_01::start() {
	
	//プレイヤーキャラクターの取得
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	//少年のインスタンス
	this->m_pBoy = (CPlayerBoy*)pPlayerChara;

	//武器のインスタンス
	this->m_pWeapon = this->m_pBoy->m_pWeapon;

	//斬撃1のタイプ
	this->m_pBoy->m_playerState = CPlayerCharacter::STATE::SLASH_ATTACK_01_1;
	this->m_pBoy->m_playerAct = CPlayerCharacter::ACTION::ATTACK;

	this->m_pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::SLASH_01;
	this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::SLASH_01_1;

	this->m_delayCounter = 0;
	this->m_attackStep = 0;

}

/*
* @desc 更新処理 
*        基準点の更新と、プレイヤーの移動
* @param 対象のキャラクター
*/
void CNormalSlashAttack_01::update(CCharacter* pChara) {
	
	//方向の設定
	this->m_attackVec = this->m_pBoy->getScaleX();

	if (this->m_attackStep == 0) {
		this->start();
		this->m_attackStep = 1;
	}


	if (this->m_attackStep == 1) {
		CAnimation* pAnime = this->m_pWeapon->m_mapAnimations[CPlayerWeapon::ATTACK_ANIME::SLASH_01_1];

		static int deg_1 = 90;

		if (pAnime->isEnd() != true) {
			//入力受付を拒否にする
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
* @desc 終了
* @tips 着地した際にこの関数を呼び出す
*/
void CNormalSlashAttack_01::stop() {

	//入力受付を可能にする
	this->m_pBoy->m_nonInputFlag = false;

	//斬撃1を終了する処理
	this->m_pBoy->m_playerState = CPlayerCharacter::STATE::DRAWN_STAND;//:DRAWN_WEAPON;
	//this->m_pBoy->m_playerAct = CPlayerCharacter::ACTION::NONE;

	this->m_pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;
	this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::DRAWN;

	this->m_nextActionFlag = false;

	this->m_delayCounter = 0;
	this->m_attackStep = 0;
}

