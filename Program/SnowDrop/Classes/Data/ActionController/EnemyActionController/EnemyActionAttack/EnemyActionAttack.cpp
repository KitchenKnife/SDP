/*
* ActionController.cpp
*
*	2016/11/11	Yamasaki
*
*/
#include"EnemyActionAttack.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"


//================================================
//‘ÅŒ‚UŒ‚	
//================================================


/*
* @desc XVˆ—
* @param UŒ‚‚ðs‚¤ƒLƒƒƒ‰ƒNƒ^[‚ÌƒAƒhƒŒƒX
*/
void CEnemyActionAttack::update(CCharacter* pChara) {


	//‹RŽm‚ÌŽæ“¾
	CCharacter* pKnightChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	//­—‚ÌŽæ“¾
	CCharacter* pGirlChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	if (this->m_isAttacking == true) {

		//UŒ‚’†
		this->attack(pChara);

		//ƒtƒŒ[ƒ€‚ð‘«‚µ‚Ä‚¢‚­ 
		this->m_currentFrame++;

		//Õ“Ë‚µ‚Ä‚¢‚È‚¯‚ê‚Î
		if (!(pChara->collision(pKnightChara)) || !(pChara->collision(pGirlChara))) {

			//Ä¶‚ðŽ~‚ß‚é
			this->stop();
			return;
		}

	}
	else if (this->m_isAttackStart == true) {

		//Ý’è‚³‚ê‚½•b”UŒ‚ŠJŽn
		m_currentFrame = 0;

		//‘ÅŒ‚UŒ‚ƒtƒ‰ƒO‚ðtrue‚É‚·‚é
		this->m_isAttacking = true;
	}

	//‘ÅŒ‚UŒ‚ŠJŽnƒtƒ‰ƒO‚ð‰º‚°‚é
	this->m_isAttackStart = false;


}

//======================================
// BOSS1 ˜r‰ñ‚µ
//======================================
void CEnemyBOSS1Attack::attack(CCharacter* pChara) {
	
	//pChara->m_state = (int)CEnemyCharacter::STATE::ATTACK;

	// 3‰ñ’†‰½‰ñ“–‚½‚Á‚½‚©Šm”F
	if (this->m_currentFrame % 60 == 0) {
		//CPlayerBoy::getInstance()->m_pStatus->decreaseHP(1);
		CCLOG("BOSS ATTACK!!");
		//CCLOG("%d", CPlayerBoy::getInstance()->m_pStatus->getHp());
	}

}

//======================================
// BOSS1 ƒNƒGƒCƒN
//======================================
void CEnemyBOSS1AttackQuake::attack(CCharacter* pChara) {

	// ƒvƒŒƒCƒ„[‚ªUŒ‚”ÍˆÍ“à‚È‚çUŒ‚‚·‚é

	//‹RŽm‚ÌŽæ“¾
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	if (pChara->collision(pPlayerChara) == true) {

		// 3‰ñ’†‰½‰ñ“–‚½‚Á‚½‚©Šm”F
		if (this->m_currentFrame % 60 == 0) {
			//CPlayerBoy::getInstance()->m_pStatus->decreaseHP(1);
			CCLOG("BOSS Quake!!");
			//CCLOG("%d", CPlayerBoy::getInstance()->m_pStatus->getHp());
		}
	}

}