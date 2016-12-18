/*
* Collision.h
*
*	2016/11/07	Osumi
*
*/

#pragma once
//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"cocos2d.h"
#include"Constants.h"

using namespace cocos2d;

class CCharacter;

//================================================
// ���̃f�[�^�͂������珑��
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
// �O���錾�Ɋւ���R�[�h�͂������珑��
//================================================
//�_
class CCollisionPoint;

//��`
class CCollisionRect;

//================================================
// �Փ˃f�[�^�p�N���X�͂������珑��
//================================================
class CCollision {
public:
	virtual ~CCollision(){}

	//================================================
	// �Փ˔���̃����o�֐��̐錾�͂������珑��
	//================================================
	//�_���Փ˂��Ă������̏Փ˔���
	virtual bool collision(CCollisionPoint*) = 0;
	//��`���Փ˂��Ă����Ƃ��̏Փ˔���
	virtual bool collision(CCollisionRect*) = 0;

};


//================================================
// �_
//================================================
class CCollisionPoint :public CCollision{
public:
	//�_�̈ʒu
	Point m_pos;

	//�ʒu�����̂܂܏Փ˔���p�̓_�ɂȂ�
	CCollisionPoint(Point pos):m_pos(pos){}

	/**
	* @desc �_�Ɠ_�̏Փ˔���
	* @param �_
	*/
	bool collision(CCollisionPoint* pPt)override;

	/**
	* @desc �_�Ƌ�`�̏Փ˔���
	* @param ��`
	*/
	bool collision(CCollisionRect* pRect)override;
};

//================================================
// ��`
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
	* @desc ���̂����̂܂܏Փ˔���p�̋�`�ɂȂ�
	*/
	CCollisionRect(CBody body):m_body(body){
		//4�̒��_�̐ݒ�
		//this->setVec4();
	}

	/**
	* @desc ���݈ʒu�Ǝ��̂���Փ˔���p�̋�`��ݒ�
	* @param ����
	* @param �ʒu
	*/
	CCollisionRect(CBody body, Vec2 pos);

	/**
	* @desc ��`�Ɠ_�̏Փ˔���
	* @param �_
	* @tips CPoint��CRect�̏Փ˔����CPoint�N���X�Ɏ������Ă�̂�
	*		�����Ƃ��Ď󂯎����pPt����collision���Ăяo��
	*/
	bool collision(CCollisionPoint* )override;

	/**
	* @desc ��`�Ƌ�`�̏Փ˔���
	* @param ��`
	*/
	bool collision(CCollisionRect* )override;

	/*
	//4�̒��_�̐ݒ�
	void setVec4() {
		this->m_midLeft = m_body.m_left/2.0f;
		this->m_midRight = m_body.m_right / 2.0f;
		this->m_midTop = m_body.m_top / 2.0f;
		this->m_midBottom = m_body.m_bottom / 2.0f;
	}
	*/

};



