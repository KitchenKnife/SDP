/*
* Collision.h
*
*	2016/11/07	Osumi
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"cocos2d.h"
#include"Constants.h"

using namespace cocos2d;

class CCharacter;

//================================================
// 実体データはここから書く
//================================================
class CBody {
public:
	float m_left;
	float m_top;
	float m_right;
	float m_bottom;

	CBody(){}

	CBody(float left, float top, float right, float bottom) :
		m_left(left), m_top(top), m_right(right), m_bottom(bottom) {}

	void set(float left, float top, float right, float bottom) {
		this->m_left = left;
		this->m_top = top;
		this->m_right = right;
		this->m_bottom = bottom;
	}


	void getBody(CCharacter* pChara);

};

//================================================
// 前方宣言に関するコードはここから書く
//================================================
//点
class CCollisionPoint;

//矩形
class CCollisionRect;

//================================================
// 衝突データ用クラスはここから書く
//================================================
class CCollision {
public:
	virtual ~CCollision(){}

	//================================================
	// 衝突判定のメンバ関数の宣言はここから書く
	//================================================
	//点が衝突してきた時の衝突判定
	virtual bool collision(CCollisionPoint*) = 0;
	//矩形が衝突してきたときの衝突判定
	virtual bool collision(CCollisionRect*) = 0;

};


//================================================
// 点
//================================================
class CCollisionPoint :public CCollision{
public:
	//点の位置
	Point m_pos;

	//位置がそのまま衝突判定用の点になる
	CCollisionPoint(Point pos):m_pos(pos){}

	/**
	* @desc 点と点の衝突判定
	* @param 点
	*/
	bool collision(CCollisionPoint* pPt)override;

	/**
	* @desc 点と矩形の衝突判定
	* @param 矩形
	*/
	bool collision(CCollisionRect* pRect)override;
};

//================================================
// 矩形
//================================================
class CCollisionRect :public CCollision {
public:
	CBody m_body;
	
	/*
	float m_midLeft;
	float m_midRight;
	float m_midTop;
	float m_midBottom;
	*/

	/**
	* @desc 実体がそのまま衝突判定用の矩形になる
	*/
	CCollisionRect(CBody body):m_body(body){
		//4つの頂点の設定
		//this->setVec4();
	}

	/**
	* @desc 現在位置と実体から衝突判定用の矩形を設定
	* @param 実体
	* @param 位置
	*/
	CCollisionRect(CBody body, Vec2 pos);

	/**
	* @desc 矩形と点の衝突判定
	* @param 点
	* @tips CPointとCRectの衝突判定はCPointクラスに実装してるので
	*		引数として受け取ったpPtからcollisionを呼び出す
	*/
	bool collision(CCollisionPoint* )override;

	/**
	* @desc 矩形と矩形の衝突判定
	* @param 矩形
	*/
	bool collision(CCollisionRect* )override;

	/*
	//4つの頂点の設定
	void setVec4() {
		this->m_midLeft = m_body.m_left/2.0f;
		this->m_midRight = m_body.m_right / 2.0f;
		this->m_midTop = m_body.m_top / 2.0f;
		this->m_midBottom = m_body.m_bottom / 2.0f;
	}
	*/

};



