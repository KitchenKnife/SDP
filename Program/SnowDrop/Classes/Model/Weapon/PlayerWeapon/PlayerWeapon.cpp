
/*
* PlayerWeapon.cpp
*
*	2016/12/1	Osumi
*
*/

#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
/*
//================================================
//
//�@�v���C���[�̕�����N���X
//
//================================================

//�R���X�g���N�^
CPlayerWeapon::CPlayerWeapon() {

}

//�f�X�g���N�^
CPlayerWeapon::~CPlayerWeapon() {

	//�A�j���[�V�����Q�̉��
	std::map<ATTACK_ANIME, CAnimation*>::iterator animeItr = this->m_mapAnimations.begin();
	while (animeItr != this->m_mapAnimations.end()) {
		SAFE_DELETE(animeItr->second);
		animeItr++;
	}
	this->m_mapAnimations.clear();

	//�A�j���[�V�����Q�̉��
	std::map<ATTACK_ACT, CPlayerWeaponAttack*>::iterator actItr = this->m_mapActions.begin();
	while (actItr != this->m_mapActions.end()) {
		SAFE_DELETE(actItr->second);
		actItr++;
	}
	this->m_mapActions.clear();

}

//����������
bool CPlayerWeapon::init() {

	if (CWeapon::init() == false) {
		CCLOG("����̒��ۃN���X�̏������Ɏ��s");
		return false;
	}

	//�x�N�^�[�̃A�j���[�V�����Q�̐���
	this->m_pAnimations = new std::vector<CAnimation*>;

	//�x�N�^�[�̃A�N�V�����Q�̐���
	this->m_pActions = new std::vector<CAction*>;

	return true;
}

//�X�V����
void CPlayerWeapon::update() {

	//�ړ�����
	this->moveFunc();

	//��Ԃ̃`�F�b�N
	this->checkState();

	//�A�j���[�V��������
	this->animationFunc();

	//�A�N�V��������
	this->actionFunc();

	//���f����
	this->applyFunc();

}

//��Ԃ̃`�F�b�N
void CPlayerWeapon::checkState() {

	if (this->m_attackAnime == ATTACK_ANIME::RETURN) {
		//this->m_activeFlag = false;
		//this->setVisible(false);

	}else{ 
		//this->m_activeFlag = true;
		//this->setVisible(true);
	}
	
	//�L���t���O�ɉ����ĉ���
	this->setVisible(this->m_activeFlag);

}

//����̔[��
void CPlayerWeapon::returnSword() {

	this->m_attackAnime = ATTACK_ANIME::RETURN;
	this->m_attackAct = ATTACK_ACT::NONE;

	CPlayerBoy* pBoy = CPlayerBoy::getInstance();
	pBoy->m_playerAct = CPlayerCharacter::ACTION::NONE;
	pBoy->m_playerState = CPlayerCharacter::STATE::STAND;
}

//���C���[����̎��O��
void CPlayerWeapon::removeFromeLayer() {
	this->removeFromParent();
}

//�ړ�����
void CPlayerWeapon::moveFunc() {

	//���͏���
	this->inputFunc();
	//�v���C���[�L�����N�^�[�̎擾
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	CBody* pBody = pPlayerChara->m_pBody;

	//�ړ��v�Z(�v���C���[��̍��W)
	this->m_pMove->setPos((pBody->m_right)+this->m_offset.x, -(pBody->m_bottom)+this->m_offset.y);

}

//�A�j���[�V��������
void  CPlayerWeapon::animationFunc() {
	
	//�L���t���O������Ă��炱���ŏ������~�߂�
	if (this->m_activeFlag == false) {
		return;
	}

	//�v���C���[�A�j���[�V����
	(this->m_mapAnimations)[m_attackAnime]->update();

}

//�A�N�V��������
void CPlayerWeapon::actionFunc() {

	//�L���t���O������Ă��炱���ŏ������~�߂�
	if (this->m_activeFlag == false) {
		return;
	}

	//��Ԃɉ������A�N�V����
	(this->m_mapActions)[m_attackAct]->update(CPlayerBoy::getInstance());

}

//���f����
void  CPlayerWeapon::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�L���t���O������Ă��炱���ŏ������~�߂�
	if (this->m_activeFlag == false) {
		return;
	}

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect(this->m_mapAnimations[m_attackAnime]->getCurrentChip());
	
}




//���͏���
void  CPlayerWeapon::inputFunc() {

	CPlayerBoy* pBoy = CPlayerBoy::getInstance();

	if (inputflag.m_z == true) {
		if (this->m_zKeyDown == false) {

			this->m_zKeyDown = true;

			if (this->m_attackAnime == CPlayerWeapon::ATTACK_ANIME::RETURN) {

				this->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::DRAWN;
				this->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;//::DRAWN;

			}
			else if (this->m_attackAnime == CPlayerWeapon::ATTACK_ANIME::DRAWN) {

				this->m_mapActions[CPlayerWeapon::ATTACK_ACT::SLASH_01]->start();

				this->m_attackAct = CPlayerWeapon::ATTACK_ACT::SLASH_01;
				this->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::SLASH_01_1;

				CPlayerBoy::getInstance()->m_playerAct = CPlayerCharacter::ACTION::ATTACK;
				CPlayerBoy::getInstance()->m_playerState = CPlayerCharacter::STATE::SLASH_ATTACK_01_1;

			}
			else {
				this->m_mapActions[this->m_attackAct]->m_nextActionFlag = true;
			}

		}
	}
	else {
		this->m_zKeyDown = false;

	}


}

//================================================
//
//�@�v���C���[�̒ʏ핐��N���X
//
//================================================

//���L�C���X�^���X
CPlayerNormalWeapon* CPlayerNormalWeapon::m_pPlayerWeapon = NULL;

//�C���X�^���X�̎擾
CPlayerNormalWeapon* CPlayerNormalWeapon::getInstance() {

	if (CPlayerNormalWeapon::m_pPlayerWeapon == NULL) {
		//CPlayerNormalWeapon::m_pPlayerWeapon = (CPlayerNormalWeapon*)CPlayerWeaponFactoryManager::getInstance()->create(WEAPON_TYPE::NORMAL);
		CPlayerNormalWeapon::m_pPlayerWeapon = (CPlayerNormalWeapon*)CCharacterAggregate::getInstance()->getAtTag(TAG_WEAPON_1);
	}

	return CPlayerNormalWeapon::m_pPlayerWeapon;
}

//�C���X�^���X�̉��
void CPlayerNormalWeapon::removeInstance() {

	SAFE_DELETE(CPlayerNormalWeapon::m_pPlayerWeapon);
}

//����̃��C���[�ւ̎��t��
void CPlayerNormalWeapon::addChildPlayer(CPlayerCharacter* pChara) {
	pChara->addChild(this);
	
}

//�R���X�g���N�^
CPlayerNormalWeapon::CPlayerNormalWeapon(){}

//�f�X�g���N�^
CPlayerNormalWeapon::~CPlayerNormalWeapon(){}

//����������
bool CPlayerNormalWeapon::init() {

	if (CPlayerWeapon::init() == false) {
		CCLOG("�v���C���[����N���X�̏������Ɏ��s");
		return false;
	}

	return true;
}

//�X�V����
void CPlayerNormalWeapon::update() {

	CPlayerWeapon::update();

}

//�A�j���[�V��������
void CPlayerNormalWeapon::animationFunc() {


	if (this->m_mapActions[this->m_attackAct]->m_delayCounter > 0 )
		return;

	CPlayerWeapon::animationFunc();

}
*/