
/*
* Physical.h
*
*	2016/11/07	Osumi
*
*/
#pragma once

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include"Data/Move/Move.h"


//������������������������������������������������
//�@�������Z�N���X
//������������������������������������������������
class CPhysical {
public:
	virtual ~CPhysical(){}
	virtual void update(CMove* pMove) = 0;

};


//=====================================
// �d�͂Ɋ�Â������x�v�Z�Ɋւ���R�[�h�̒ǉ��͂�������
//=====================================
class CPhysicalGravity : public CPhysical {
public:
	//�d�͌W��
	constexpr static const float GRAVITY = -0.5f;

public:
	void update(CMove* pMove)override {

		//y���̑��x(�d�͌v�Z)
		pMove->m_vel.y += pMove->m_accele.y + CPhysicalGravity::GRAVITY;
	}

};


//=====================================
// ���C�W���Ɋ�Â������x�v�Z�Ɋւ���R�[�h�̒ǉ��͂�������
//=====================================
class CPhysicalFriction : public CPhysical {
protected:
	//�X�̖��C�W��
	float m_personalFriction = 0.0f;
	
	//�ō����x
	float m_maxSpeed = 0.0f;

public:
	//�S�̖̂��C�W��
	constexpr static const float FRICTION = 0.3f;

	CPhysicalFriction(){}
	CPhysicalFriction(float maxSpeed):m_maxSpeed(maxSpeed){}

	/**
	* @desc �ō����x�ƌX�̖��C�W���̐ݒ�
	* @param �ō����x
	* @param �X�̖��C�W��
	*/
	void set(float maxSpeed, float friction) {
		m_maxSpeed = maxSpeed;
		m_personalFriction = friction;
	}

	/**
	* @desc �X�V�����i���C�v�Z�j
	*/
	void update(CMove* pMove)override {


		
		//���C
		float friction = 0.0f;

		//�E�Ɉړ����Ă�����
		if (pMove->m_vel.x > this->m_personalFriction) {
			friction = - this->m_personalFriction;
		}else if(pMove->m_vel.x > 0){
			//���x�����C�W���ȉ��ɂȂ�����
			//���C�@-�@���x�@��0
			//�ɂȂ�悤�ɂ���
			friction = -pMove->m_vel.x;
		}

		//���Ɉړ����Ă�����
		if (pMove->m_vel.x < -this->m_personalFriction) {
			friction = this->m_personalFriction;
		}
		else if (pMove->m_vel.x < 0) {
			//���C�@-�@���x�@��0
			friction = -pMove->m_vel.x;
		}

		//x���̑��x���v�Z�i���C�v�Z�j
		pMove->m_vel.x += pMove->m_accele.x + friction;
	

		//�����̍ō����x���v�Z
		if (pMove->m_vel.x < -this->m_maxSpeed) {
			pMove->m_vel.x = -this->m_maxSpeed;
		}else if (pMove->m_vel.x > this->m_maxSpeed) {
			pMove->m_vel.x = this->m_maxSpeed;
		}
	}

};