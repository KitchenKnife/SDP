
/*
* Move.h
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

//=====================================
// �ړ��f�[�^
//=====================================
class CMove {
public:
	//�ʒu
	Vec2 m_pos;
	//���x
	Vec2 m_vel;
	//�����x
	Vec2 m_accele;
	//����
	float m_speed;

	//�ʒu�̐ݒ�
	void setPos(float xx, float yy) {
		m_pos.set(xx, yy);
	}

	//���x�̐ݒ�
	void setVel(float xx, float yy) {
		m_vel.set(xx, yy);
	}

	/**
	* @desc �ړ�
	*/
	virtual void moveBy() {

		//���x�ɂ��ړ�
		m_pos += m_vel;
	}
};


