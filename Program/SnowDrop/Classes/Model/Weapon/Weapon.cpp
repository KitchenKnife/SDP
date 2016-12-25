
/*
* weapon.cpp
*
*	2016/11/26	Osumi
*
*/

#include "Model/Weapon/Weapon.h"

//================================================
//
//�@����̒��ۃN���X
//
//================================================

//�R���X�g���N�^
CWeapon::CWeapon(){}

//�f�X�g���N�^
CWeapon::~CWeapon(){

	for (cocos2d::Point* pPoint : (*m_pBasePoints)) {
		SAFE_DELETE(pPoint);
	}
	SAFE_DELETE(this->m_pBasePoints);

	SAFE_DELETE(this->m_pBody);


	
}

//����������
bool CWeapon::init() {

	if (Sprite::init() == false) {
		CCLOG("Character�̏������Ɏ��s");
		return false;
	}

	//update()�����o�֐��̌Ăяo��
	//this->scheduleUpdate();
	return true;
}

//�X�V����
void CWeapon::update() {

	//�ړ�����
	this->moveFunc();

	//�A�j���[�V��������
	this->animationFunc();

	//���f����
	this->applyFunc();

	/**
	* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
	* @param �L�����N�^�[�̃A�h���X
	* @return true...�Փ˂���
	*/
	//this->collision(CCharacter* pChara);

}