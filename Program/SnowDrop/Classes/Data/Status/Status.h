#pragma once
//=========================================================================
// ƒXƒe[ƒ^ƒXƒNƒ‰ƒX
//=========================================================================

class CStatus {
public:
	CStatus() {}
	~CStatus() {}


private:
	// ‚g‚o
	int m_hp = 0;

	// Å‘å‚g‚o
	int m_maxHp = 0;

	// ‘¬“x
	float m_speed = 0;

	// UŒ‚—Í
	int m_attackPt = 0;

public:

	/**
	*	@desc İ’è
	*	@param ‚g‚o
	*	@param Å‘å‚g‚o
	*	@param UŒ‚—Í
	*	@param ˆÚ“®‘¬“x
	*/

	void set(int hp, int maxHp, int attackPt,int speed) {

		this->m_hp = hp;
		this->m_maxHp = maxHp;
		this->m_attackPt = attackPt;
		this->m_speed = speed; 

	}

	//ƒXƒs[ƒh‚ğİ’è‚·‚é
	void setSpeed(float speed) {
		this->m_speed = speed;
	}

	// ‚g‚o‚Ìæ“¾
	int getHp() {
		return this->m_hp;
	}

	// Å‘å‚g‚o‚Ìæ“¾
	int getmaxHp() {
		return this->m_maxHp;
	}

	// UŒ‚—Í‚Ìæ“¾
	int getAttackPt() {
		return this->m_attackPt;
	}

	// ƒXƒs[ƒh‚Ìæ“¾
	float getSpeed() {
		return this->m_speed;
	}



	/**
	*	@desc ‚g‚o‚ÌŒ¸­
	*	@param Œ¸­‚·‚é’li‘Šè‚ÌUŒ‚—Íj
	*/

	void decreaseHP(int attackPt) {
		this->m_hp -= attackPt;
	}

	/**
	*	@desc ‚g‚o‚Ì‘S‰ñ•œ
	*/

	void recoveryHp() {
		this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc ‚g‚o‚Ì‚P‰ñ•œ
	*/

	void CureHp(int hp) {
		this->m_hp += hp;
		if (this->m_hp > this->m_maxHp)
			this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc ƒXƒs[ƒh‚Ì‚PUP
	*/

	void SpeedVel(float speed) {
		this->m_speed += speed;

	}
	
};

