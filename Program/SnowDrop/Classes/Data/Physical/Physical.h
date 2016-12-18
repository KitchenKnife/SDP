
/*
* Physical.h
*
*	2016/11/07	Osumi
*
*/
#pragma once

//
//@’Ç‰Á‚ÌƒCƒ“ƒNƒ‹[ƒh‚Í‚±‚±‚©‚ç
//
#include"Data/Move/Move.h"


//
//@•¨—‰‰ŽZƒNƒ‰ƒX
//
class CPhysical {
public:
	virtual ~CPhysical(){}
	virtual void update(CMove* pMove) = 0;

};


//=====================================
// d—Í‚ÉŠî‚Ã‚¢‚½‘¬“xŒvŽZ‚ÉŠÖ‚·‚éƒR[ƒh‚Ì’Ç‰Á‚Í‚±‚±‚©‚ç
//=====================================
class CPhysicalGravity : public CPhysical {
public:
	//d—ÍŒW”
	constexpr static const float GRAVITY = -0.5f;

public:
	void update(CMove* pMove)override {

		//yŽ²‚Ì‘¬“x(d—ÍŒvŽZ)
		pMove->m_vel.y += pMove->m_accele.y + CPhysicalGravity::GRAVITY;
	}

};


//=====================================
// –€ŽCŒW”‚ÉŠî‚Ã‚¢‚½‘¬“xŒvŽZ‚ÉŠÖ‚·‚éƒR[ƒh‚Ì’Ç‰Á‚Í‚±‚±‚©‚ç
//=====================================
class CPhysicalFriction : public CPhysical {
protected:
	//ŒÂX‚Ì–€ŽCŒW”
	float m_personalFriction = 0.0f;
	
	//Å‚‘¬“x
	float m_maxSpeed = 0.0f;

public:
	//‘S‘Ì‚Ì–€ŽCŒW”
	constexpr static const float FRICTION = 0.3f;

	CPhysicalFriction(){}
	CPhysicalFriction(float maxSpeed):m_maxSpeed(maxSpeed){}

	/**
	* @desc Å‚‘¬“x‚ÆŒÂX‚Ì–€ŽCŒW”‚ÌÝ’è
	* @param Å‚‘¬“x
	* @param ŒÂX‚Ì–€ŽCŒW”
	*/
	void set(float maxSpeed, float friction) {
		m_maxSpeed = maxSpeed;
		m_personalFriction = friction;
	}

	/**
	* @desc XVˆ—i–€ŽCŒvŽZj
	*/
	void update(CMove* pMove)override {


		
		//–€ŽC
		float friction = 0.0f;

		//‰E‚ÉˆÚ“®‚µ‚Ä‚¢‚½‚ç
		if (pMove->m_vel.x > this->m_personalFriction) {
			friction = - this->m_personalFriction;
		}else if(pMove->m_vel.x > 0){
			//‘¬“x‚ª–€ŽCŒW”ˆÈ‰º‚É‚È‚Á‚½‚ç
			//–€ŽC@-@‘¬“x@0
			//‚É‚È‚é‚æ‚¤‚É‚·‚é
			friction = -pMove->m_vel.x;
		}

		//¶‚ÉˆÚ“®‚µ‚Ä‚¢‚½‚ç
		if (pMove->m_vel.x < -this->m_personalFriction) {
			friction = this->m_personalFriction;
		}
		else if (pMove->m_vel.x < 0) {
			//–€ŽC@-@‘¬“x@0
			friction = -pMove->m_vel.x;
		}

		//xŽ²‚Ì‘¬“x‚ðŒvŽZi–€ŽCŒvŽZj
		pMove->m_vel.x += pMove->m_accele.x + friction;
	

		//‚˜Ž²‚ÌÅ‚‘¬“x‚ðŒvŽZ
		if (pMove->m_vel.x < -this->m_maxSpeed) {
			pMove->m_vel.x = -this->m_maxSpeed;
		}else if (pMove->m_vel.x > this->m_maxSpeed) {
			pMove->m_vel.x = this->m_maxSpeed;
		}
	}

};