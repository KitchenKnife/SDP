/*
* Collision.cpp
*
*	2016/11/07	Osumi
*
*/

//
//@ΗΑΜCN[hΝ±±©η
//
#include"Collision.h"
#include "Model/Character/Character.h"

using namespace cocos2d;

//================================================
// _
//================================================
/**
* @desc _Ζ_ΜΥΛ»θ
* @param _
*/
bool CCollisionPoint::collision(CCollisionPoint* pPt) {


	//ΩΪ θΎΘ’ͺκΐ΅Δ¨­

	if (this->m_pos.x == pPt->m_pos.x)
		if (this->m_pos.y == pPt->m_pos.y)
			return true;

	return false;
}

/**
* @desc _Ζι`ΜΥΛ»θ
* @param ι`
*/
bool CCollisionPoint::collision(CCollisionRect* pRect){

	//©ͺΜE€ΖΞΫΜΆ€@Ζ@©ͺΜΆ€ΖΞΫΜE€
	if (this->m_pos.x > pRect->m_body.m_left  &&  this->m_pos.x < pRect->m_body.m_right) {
		//©ͺΜγ€ΖΞΫΜΊ€@Ζ@©ͺΜΊ€ΖΞΫΜγ€
		if (this->m_pos.y > pRect->m_body.m_bottom  &&  this->m_pos.y < pRect->m_body.m_top) {
			//dΘΑ½iΥΛ΅Διj
			return true;

		}
	}



	//ΥΛ΅Δ’Θ’
	return false;

}


//================================================
// ι`
//================================================
/**
* @desc »έΚuΖΐΜ©ηΥΛ»θpΜι`πέθ
* @param ΐΜ
* @param Κu
*/
CCollisionRect::CCollisionRect(CBody body, Vec2 pos) {

	this->m_body.set(
		body.m_left + pos.x,
		body.m_top + pos.y,
		body.m_right + pos.x,
		body.m_bottom + pos.y
	);

	//4ΒΜΈ_Μέθ
	//this->setVec4();
}

/**
* @desc ι`Ζ_ΜΥΛ»θ
* @param _
* @tips CPointΖCRectΜΥΛ»θΝCPointNXΙΐ΅ΔιΜΕ
*		ψΖ΅Δσ―ζΑ½pPt©ηcollisionπΔΡo·
*/
bool CCollisionRect::collision(CCollisionPoint* pPt) {

	return pPt->collision(this);
}

/**
* @desc ι`Ζι`ΜΥΛ»θ
* @param ι`
*/
bool CCollisionRect::collision(CCollisionRect* pRect) {
	
	//©ͺΜE€ΖΞΫΜΆ€@Ζ@©ͺΜΆ€ΖΞΫΜE€
	if (this->m_body.m_right > pRect->m_body.m_left  &&  this->m_body.m_left < pRect->m_body.m_right) {
		//©ͺΜγ€ΖΞΫΜΊ€@Ζ@©ͺΜΊ€ΖΞΫΜγ€
		if (this->m_body.m_top > pRect->m_body.m_bottom  &&  this->m_body.m_bottom < pRect->m_body.m_top) {
			//dΘΑ½iΥΛ΅Διj
			return true;

		}
	}

	//ΥΛ΅Δ’Θ’
	return false;

}

