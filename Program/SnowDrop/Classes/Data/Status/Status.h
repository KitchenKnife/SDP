#pragma once
//=========================================================================
// Xe[^XNX
//=========================================================================

class CStatus {
public:
	CStatus() {}
	~CStatus() {}


private:
	// go
	int m_hp = 0;

	// Åågo
	int m_maxHp = 0;

	// ¬x
	float m_speed = 0;

	// UÍ
	int m_attackPt = 0;

public:

	/**
	*	@desc Ýè
	*	@param go
	*	@param Åågo
	*	@param UÍ
	*/

	void set(int hp, int maxHp, int attackPt) {

		this->m_hp = hp;
		this->m_maxHp = maxHp;
		this->m_attackPt = attackPt;

	}


	// goÌæ¾
	int getHp() {
		return this->m_hp;
	}

	// ÅågoÌæ¾
	int getmaxHp() {
		return this->m_maxHp;
	}

	// UÍÌæ¾
	int getAttackPt() {
		return this->m_attackPt;
	}

	// Xs[hÌæ¾
	float getSpeed() {
		return this->m_speed;
	}



	/**
	*	@desc goÌ¸­
	*	@param ¸­·élièÌUÍj
	*/

	void decreaseHP(int attackPt) {
		this->m_hp -= attackPt;
	}

	/**
	*	@desc goÌSñ
	*/

	void recoveryHp() {
		this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc goÌPñ
	*/

	void CureHp(int hp) {
		this->m_hp += hp;
		if (this->m_hp > this->m_maxHp)
			this->m_hp = this->m_maxHp;
	}

	/**
	*	@desc Xs[hÌPUP
	*/

	void SpeedVel(float speed) {
		this->m_speed += speed;

	}
	
};

