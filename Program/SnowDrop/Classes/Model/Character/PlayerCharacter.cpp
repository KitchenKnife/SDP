
/*
* PlayerCharacter.cpp
*
*	2016/12/1	Osumi
*
*/

//������������������������������������������������
//�@�ǉ��̃C���N���[�h�͂�������
//������������������������������������������������
#include "PlayerCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Model/Character/PlayerFactory.h"
#include "Data/Effect/PlayerEffect/PlayerEffectFactory.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
#include "Data/ActionController/PlayerActionController/PlayerWeaponActionController/PlayerWeaponActionController.h"
#include "Scene/GameMain/GameMain.h"

//================================================	
//	�v���C���[�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//�R���X�g���N�^
CPlayerCharacter::CPlayerCharacter() {

}

//�f�X�g���N�^
CPlayerCharacter::~CPlayerCharacter() {
	//�A�j���[�V�����Q�̉��
	std::map<STATE, CAnimation*>::iterator animeItr = this->m_mapAnimations.begin();
	while (animeItr != this->m_mapAnimations.end()) {
		SAFE_DELETE(animeItr->second);
		animeItr++;
	}
	this->m_mapAnimations.clear();

	//�A�j���[�V�����Q�̉��
	std::map<ACTION, CAction*>::iterator actItr = this->m_mapActions.begin();
	while (actItr != this->m_mapActions.end()) {
		SAFE_DELETE(actItr->second);
		actItr++;
	}
	this->m_mapActions.clear();

	//�G�t�F�N�g�Q�̉��
	for (CPlayerEffect* pEffect : (*m_pEffects)) {
		SAFE_DELETE(pEffect);
	}

	//����̉��
	CPlayerNormalWeapon::removeInstance();

}

//����������
bool CPlayerCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("�v���C���[�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	//================================================	
	//	�v���C���[�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
	//================================================
	
	//�x�N�^�[�̃A�j���[�V�����Q�̐���
	this->m_pAnimations = new std::vector<CAnimation*>;

	//�x�N�^�[�̃A�N�V�����Q�̐���
	this->m_pActions = new std::vector<CAction*>;
	
	
	//================================================	
	//	�l�̐ݒ�Ɋւ���R�[�h�̒ǉ��͂�������
	//================================================


	return true;
}


//�X�V����
void CPlayerCharacter::update(float deltaTime) {


	//x���̉����x�̏�����
	this->m_pMove->m_accele.x = 0.0f;

	//�ړ�����
	this->moveFunc();

	//�G�t�F�N�g�̍X�V����
	this->effectUpdate();

	//����ł��炱���Ŕ�΂�
	if (this->m_isAlive == false)
		return;


	//�A�j���[�V��������
	this->animationFunc();

	//�Փ˔���
	this->collisionAll();

	//��ԃ`�F�b�N
	this->checkState();

	//�L���t���O�̊m�F�Ƃ��̌�̏���
	this->checkActiveFlagAndFunc();

	//���f����
	this->applyFunc();
	

}

/**
* @desc ����Ȃ����Ԃ��`�F�b�N
* @param �����i�����j
* @tips ����Ȃ����ԂȂ�"��Ȃ��t���O"���グ��
*/
void CPlayerCharacter::checkSakeHands(CPlayerCharacter* pCharacter) {
	//���݂��̋���
	float length = sqrt(pow(this->m_pMove->m_pos.x - pCharacter->m_pMove->m_pos.x, 2.0) + pow(this->m_pMove->m_pos.y - pCharacter->m_pMove->m_pos.y, 2.0));

	//���݂��̋�����������x�߂���΂��݂���"��Ȃ��t���O���グ��"
	if (length <= 45) {
		this->m_isShakeHands = true;
		pCharacter->m_isShakeHands = true;
	}

}

//�A�j���[�V��������
void CPlayerCharacter::animationFunc() {

	//�v���C���[�A�j���[�V����
	(this->m_mapAnimations)[m_playerState]->update();

}

/**
* @desc ��ʔ͈͊O���菈��
* @tips ���������������̎d���͂��ꂩ��͏��Ȃ����čs���悤��
*		�S�����悤�B
*		�ǂ̂悤�ɂ���Δėp�I�ɁA�܂葼�̃L�����N�^�[�ł��g���܂킵�ł��邩��
*		�l���Ď������Ă�����
*/
/*
void  CPlayerCharacter::endOfScreen() {

	
	//���Ɉړ����Ă���ꍇ�͉�ʍ��Ŏ~�߂�悤�ɂ���
	if (this->m_pMove->m_vel.x < 0.0f  &&  this->m_pMove->m_pos.x + this->m_pBody->m_left < WINDOW_LEFT) {
		//�ݒ�@�C���l
		auto boundary = (this->m_pMove->m_pos.x + this->m_pBody->m_left) - WINDOW_LEFT;
		this->m_pMove->m_pos.x -= boundary;

		//���x�Ɖ����x��0�ɂ��邩�̓Q�[���ɂ���ĕς��
		this->m_pMove->m_vel.x = 0.0f;
		this->m_pMove->m_accele.x = 0.0f;
	}
	
	/*
	//�E�Ɉړ����Ă���ꍇ�͉�ʉE�Ŏ~�߂�悤�ɂ���
	if (this->m_pMove->m_vel.x > 0.0f  &&  this->m_pMove->m_pos.x + this->m_pBody->m_right > WINDOW_RIGHT) {
		//�ݒ�@�C���l
		auto boundary = (this->m_pMove->m_pos.x + this->m_pBody->m_right) - WINDOW_RIGHT;
		this->m_pMove->m_pos.x -= boundary;

		//���x�Ɖ����x��0�ɂ��邩�̓Q�[���ɂ���ĕς��
		this->m_pMove->m_vel.x = 0.0f;
		this->m_pMove->m_accele.x = 0.0f;
	}
	*

	//��ʉ��Ŏ~�߂�悤�ɂ���
	if (this->m_pMove->m_pos.y + this->m_pBody->m_bottom < WINDOW_BOTTOM) {
		//�ݒ�@�C���l
		auto boundary = (this->m_pMove->m_pos.y + this->m_pBody->m_bottom - WINDOW_BOTTOM);
		this->m_pMove->m_pos.y -= boundary;

		//���x�Ɖ����x��0�ɂ��邩�̓Q�[���ɂ���ĕς��
		this->m_pMove->m_vel.y = 0.0f;
		this->m_pMove->m_accele.y = 0.0f;

		//�W�����v���~������
		(this->m_mapActions)[CPlayerCharacter::ACTION::JUMP]->stop();
	}

}
*/

//���f����
void  CPlayerCharacter::applyFunc() {

	//�ʒu�f�[�^�𔽉f
	this->setPosition(this->m_pMove->m_pos);

	//�`�b�v�f�[�^�𔽉f
	this->setTextureRect(this->m_mapAnimations[m_playerState]->getCurrentChip());
}

/**
* @desc �L�����N�^�[1�̂Ƃ̏Փ˔��菈��
* @param �L�����N�^�[�̃A�h���X
* @return true...�Փ˂���
*/
bool  CPlayerCharacter::collision(CCharacter* pChara) {
	
	return true;
}

//�Փ˔��菈��
void CPlayerCharacter::collisionAll() {
	//��ԂƂ̏Փ˔�����s��
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}

	//�S�ẴL�����N�^�[�Ƃ̏Փ˔���
	std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();
	for (CCharacter* pChara : (*pCharacters)) {
		//��̂̃L�����Ƃ̏Փ˔���
		this->collision(pChara);
	}
}


//�G�t�F�N�g�̍X�V����
void CPlayerCharacter::effectUpdate() {
	

	if (this->m_pEffects != NULL){

		std::vector<CPlayerEffect*>::iterator eftItr = (*this->m_pEffects).begin();

		while (eftItr != (*this->m_pEffects).end()) {

			//�L���t���O������Ă���
			if ((*eftItr)->m_activeFlag == false) {

				//���C���[������O��
				(*eftItr)->removeFromParent();
				//�v���C���[������O��
				eftItr = (*this->m_pEffects).erase(eftItr);
			}
			else{
				//�X�V����
				(*eftItr)->update();
				eftItr++;
			}
		}
	}

}

//�G�t�F�N�g�̎��O��
void CPlayerCharacter::removeEffect(CPlayerEffect* pEffect) {
	SAFE_DELETE(pEffect);
}

//�L���t���O�̊m�F�Ƃ��̌�̏���
void CPlayerCharacter::checkActiveFlagAndFunc() {
	CStatus* pStatus = this->m_pStatus;

	if (pStatus->getHp() <= 0) {
		pStatus->set(0, pStatus->getmaxHp(), pStatus->getAttackPt());
		this->m_isAlive = false;
		this->setVisible(false);
	}

	if (this->m_isAlive == true) {
		this->setVisible(true);
	}
}

//================================================	
//	���N�N���X�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//���L�C���X�^���X
CPlayerBoy* CPlayerBoy::m_pBoy = NULL;

//�C���X�^���X�̎擾
CPlayerBoy* CPlayerBoy::getInstance() {
	if (CPlayerBoy::m_pBoy == NULL) {
		CPlayerBoy::m_pBoy =  (CPlayerBoy*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	}
	return CPlayerBoy::m_pBoy;
}

//�R���X�g���N�^
CPlayerBoy::CPlayerBoy() {

}

//�f�X�g���N�^
CPlayerBoy::~CPlayerBoy() {

	if (m_pWeapon != NULL);
	//����̉��
	//SAFE_DELETE(m_pWeapon);

}

//����������
bool CPlayerBoy::init() {

	if (CPlayerCharacter::init() == false) {
		CCLOG("�v���C���[�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	//================================================	
	//	�v���C���[�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
	//================================================


	//================================================	
	//	�l�̐ݒ�Ɋւ���R�[�h�̒ǉ��͂�������
	//================================================
	if (this != NULL) {
		CCLOG("");
	}

	return true;
}


//�G�t�F�N�g�̃v���C���[�ւ̎��t��
void CPlayerBoy::jointEffect(CPlayerCharacter::EFFECT effectType) {

	cocos2d::Point boyPt = this->m_pMove->m_pos;

	//�G�t�F�N�g�̐���
	CPlayerEffect* pEffect
		= CPlayerEffectFactoryManager::getInstance()->create((int)effectType, boyPt);

	//�G�t�F�N�g�̃��C���[�ւ̎��t��
	pEffect->jointToLayer(CGameMain::m_pMainLayer);
	//�G�t�F�N�g�̃v���C���[�ւ̎��t��
	(this->m_pEffects)->push_back(pEffect);
}

//����̑���
void CPlayerBoy::equipWeapon() {

	//����̐���
	CPlayerWeapon* pWeapon = CPlayerWeaponFactoryManager::getInstance()->create(WEAPON_TYPE::NORMAL);
	//�^�O�t��
	pWeapon->m_tag = TAG_WEAPON_1;
	//CCharacterAggregate�Ƀv���C���[��ǉ�
	CCharacterAggregate::getInstance()->add(pWeapon);
	//����̎��t��
	pWeapon->addChildPlayer(this);
	//����̃v���C���[�ւ̎��t��
	this->m_pWeapon = pWeapon;
}

//�����Ƃ̋���
float CPlayerBoy::lengthFromGirl() {

	//�����̎擾
	CCharacter* pPlayerGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	cocos2d::Point boyPt = this->m_pMove->m_pos;
	cocos2d::Point girlPt = pPlayerGirl->m_pMove->m_pos;

	float length = sqrt( pow((boyPt.x- girlPt.x),2)+pow((boyPt.y - girlPt.y),2));

	return length;
}


//������Ԃ̃`�F�b�N�i�J�E���^�[�̃f�N�������g���S���j
void CPlayerBoy::checkDisappear() {

	this->m_disappearCounter--;
	//������x����������ĂāA�����J�E���^�[��0�ȉ��Ȃ�
	if (this->lengthFromGirl() >= 200.0f && this->m_disappearCounter<= 0) {
		//�J�E���^�[�̃��Z�b�g
		this->m_disappearCounter = this->m_disappearInterval;
		//�G�t�F�N�g�̎��t��
		this->jointEffect(EFFECT::DISAPPEAR);
		//HP�̌���
		this->m_pStatus->decreaseHP(1);
	}
}


//�ړ�����
void CPlayerBoy::moveFunc() {

	/*
	*�@���͏���
	*		������͂́A���͂ɂ��ړ��Ƃ����J�e�S���ň���
	*/
	this->inputFunc();


	//����ł����΂�
	if (this->m_activeFlag == false)
		return;

	/*
	if (this->m_playerAct == ACTION::ATTACK) {
		this->m_pWeapon->update();
	}
	*/
	this->m_pWeapon->update();

	//�A�N�V������Ԃɉ������X�V����
	(this->m_mapActions)[this->m_playerAct]->update(this);
	
	
	//�����v�Z
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}


	//�ړ��v�Z
	this->m_pMove->moveBy();

}

/**
* @desc ��ԃ`�F�b�N
* @tips �l���`�F�b�N���Č��݂̏�Ԃ�ύX����
*/
void CPlayerBoy::checkState() {

	if (this->m_playerState == STATE::LIFT_UPING)
		return;

	
	//�����𔻒�
	if (this->m_pMove->m_vel.x != 0) {
		if (this->m_pMove->m_vel.x > 0) {
			//�E�����ɐݒ�
			this->setScale(1.0f, 1.0f);
		}
		else {
			//�������ɐݒ�
			this->setScale(-1.0f, 1.0f);
		}
	}

	if (this->m_playerAct == ACTION::ATTACK)
		return;

	//��Ԃ̔���
	if (this->m_pMove->m_vel.y > 0.0f) {

		//�����̑��x���v���X�Ƃ����Ƃ̓W�����v���Ă�����
		m_playerState = STATE::JUMPING;

	}
	else if (this->m_pMove->m_vel.y < 0.0f) {
		//�����̑��x���}�C�i�X�Ƃ����Ƃ͗����Ă�����
		m_playerState = STATE::FALING;
	}
	else if (this->m_pMove->m_vel.x != 0.0f) {
		//�����Ă���
		m_playerState = STATE::WALK;
	}
	else {
		//�����Ă���
		m_playerState = STATE::STAND;
	}

	//������Ԃ̃`�F�b�N
	this->checkDisappear();

}

//�X�V����
void  CPlayerBoy::update(float deltaTime) {

	//�L�����N�^�[�N���X�̍X�V�����̌Ăяo��
	//CPlayerCharacter::update(deltaTime);


	//x���̉����x�̏�����
	this->m_pMove->m_accele.x = 0.0f;

	//�ړ�����
	this->moveFunc();

	//�G�t�F�N�g�̍X�V����
	this->effectUpdate();

	//����ł��炱���Ŕ�΂�
	if (this->m_isAlive == false)
		return;


	//�A�j���[�V��������
	this->animationFunc();

	//�Փ˔���
	this->collisionAll();

	//��ԃ`�F�b�N
	this->checkState();

	//�L���t���O�̊m�F�Ƃ��̌�̏���
	this->checkActiveFlagAndFunc();

	//���f����
	this->applyFunc();
}

/**
* @desc ���͏���
* @tips �ړ������ŌĂяo��
*/
void  CPlayerBoy::inputFunc() {

	//��t���ۏ�ԂȂ甲����
	if(m_nonInputFlag == true && this->m_activeFlag== true) {
		return;
	}

	if (this->m_isAlive == true) {

		if (inputflag.m_left == true) {
			this->m_pMove->m_accele.x = -0.5f;
		}

		if (inputflag.m_right == true) {
			this->m_pMove->m_accele.x = 0.5f;
		}

		
		if (inputflag.m_up == true) {
			//����Ȃ��łȂ����
			if (this->m_isShakeHands == false) {

				this->m_playerAct = ACTION::JUMP;

				//�W�����v���J�n������
				(this->m_mapActions)[ACTION::JUMP]->start();
			}
		}

		if (inputflag.m_space == true) {
			if (this->m_spaceKeyDown == false) {

				this->m_spaceKeyDown = true;

				//�����̎擾
				CPlayerGirl* pPlayerGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

				//����Ȃ����Ԃ��`�F�b�N
				this->checkSakeHands(pPlayerGirl);
			}
		}else {
			this->m_spaceKeyDown = false;

		}

		if (inputflag.m_z == true ) {
			if (this->m_zKeyDown == false) {

				this->m_zKeyDown = true;
				if (this->m_pWeapon->m_attackAnime == CPlayerWeapon::ATTACK_ANIME::RETURN) {
					//������
					this->removeHands();

					//this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::DRAWN;
					//this->m_pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;//::DRAWN;

					this->m_playerState = STATE::DRAWN_STAND;
					this->m_playerAct = ACTION::ATTACK;
					
				}
				
			}
		}else {
			this->m_zKeyDown = false;

		}
	}

	//����ł��畜���i�f�o�b�N�p�j
	else {
		if (inputflag.m_space == true) {
			if (this->m_spaceKeyDown == false) {

				this->m_spaceKeyDown = true;
				this->m_isAlive = true;
				this->m_pStatus->recoveryHp();
			}
		}
		else {
			this->m_spaceKeyDown = false;

		}
	}

}

/**
* @desc ����Ȃ����Ԃ��`�F�b�N
* @param �����i�����j
* @tips ����Ȃ����ԂȂ�"��Ȃ��t���O"���グ��
*/
void CPlayerBoy::checkSakeHands(CPlayerCharacter* pGirl) {

	if (this->m_isShakeHands == true) {
		this->removeHands();
		return;
	}

	//���݂��̋���
	float length = sqrt(pow(this->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x, 2.0) + pow(this->m_pMove->m_pos.y - pGirl->m_pMove->m_pos.y, 2.0));

	float lengthY = (this->m_pMove->m_pos.y + this->m_pBody->m_bottom) - (pGirl->m_pMove->m_pos.y + pGirl->m_pBody->m_bottom);

	//���݂��̋�����������x�߂���΂��݂���"��Ȃ��t���O���グ��"
	if (length <= 50) {

		this->m_isShakeHands = true;
		//����̔[��
		this->m_pWeapon->returnSword();

		CPlayerGirl*pGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);
		pGirl->m_mapActions[pGirl->m_playerAct]->stop();

		if (lengthY >= 32 && this->m_pMove->m_vel.y == 0) {
			
			this->m_playerAct = ACTION::LIFT_UP;
			this->m_playerState = STATE::LIFT_UPING;
			return;
		}

		return;
	}
}

/**
* @desc ���݂��̎�����
*/
void CPlayerBoy::removeHands() {
	CPlayerGirl*pGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	this->m_isShakeHands = false;
	pGirl->m_isShakeHands = false;
}

//================================================
// �����N���X�̃����o�֐��̃R�[�h�̒ǉ��͂�������
//================================================
//���L�C���X�^���X
CPlayerGirl* CPlayerGirl::m_pGirl = NULL;

//�C���X�^���X�̎擾
CPlayerGirl* CPlayerGirl::getInstance() {
	if (CPlayerGirl::m_pGirl == NULL) {
		//CPlayerGirl::m_pGirl = (CPlayerGirl*)CPlayerFactoryManager::getInstance()->create(PLAYER_TYPE::GIRL);
		CPlayerGirl::m_pGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	}
	return CPlayerGirl::m_pGirl;
}

//�R���X�g���N�^
CPlayerGirl::CPlayerGirl() {

}

//�f�X�g���N�^
CPlayerGirl::~CPlayerGirl() {

}

//����������
bool CPlayerGirl::init() {

	if (CPlayerCharacter::init() == false) {
		CCLOG("�v���C���[�L�����N�^�[�̏������Ɏ��s");
		return false;
	}

	//================================================	
	//	�v���C���[�L�����N�^�[�̃����o�֐��̃R�[�h�̒ǉ��͂�������
	//================================================


	//================================================	
	//	�l�̐ݒ�Ɋւ���R�[�h�̒ǉ��͂�������
	//================================================

	return true;
}

//�X�V����
void  CPlayerGirl::update(float deltaTime) {


	if (this->m_pMove->m_vel.x != 0) {
		CCLOG("%f,%f", this->m_pMove->m_vel.x, this->m_pMove->m_vel.y);
		CCLOG("!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	//�L�����N�^�[�N���X�̍X�V�����̌Ăяo��
	CPlayerCharacter::update(deltaTime);

}

/**
* @desc ��ԃ`�F�b�N
* @tips �l���`�F�b�N���Č��݂̏�Ԃ�ύX����
*/
void CPlayerGirl::checkState() {

	if (this->m_playerState == STATE::LIFT_UPING)
		return;

	//�����𔻒�
	if (this->m_pMove->m_vel.x != 0) {
		if (this->m_pMove->m_vel.x > 0) {
			//�E�����ɐݒ�
			this->setScale(1.0f, 1.0f);
		}
		else {
			//�������ɐݒ�
			this->setScale(-1.0f, 1.0f);
		}
	}

	//��Ԃ̔���
	if (this->m_pMove->m_vel.y > 0.0f) {

		//�����̑��x���v���X�Ƃ����Ƃ̓W�����v���Ă�����
		m_playerState = STATE::JUMPING;

	}
	else if (this->m_pMove->m_vel.y < 0.0f && this->m_wasteActFlag == false) {
		//�����̑��x���}�C�i�X�Ƃ����Ƃ͗����Ă�����
		m_playerState = STATE::FALING;
	}
	else if (this->m_pMove->m_vel.x != 0.0f) {
		//�����Ă���
		m_playerState = STATE::WALK;
	}
	else if(this->m_wasteActFlag == false){
		//�����Ă���(�ɂԂ��J�E���^�[�N��)
		
		this->m_mapActions[ACTION::WASTE]->start();
	}

}

//�ړ�����
void CPlayerGirl::moveFunc() {

	/*
	*�@���͏����͍s�͂Ȃ�
	*/
	//this->inputFunc();
	
	if(this->m_isShakeHands == false  && CPlayerBoy::getInstance()->m_isShakeHands ==true)
	//���N�Ɍ������Ă��߂Â�����
	closeWithBoyFunc(&CPlayerBoy::getInstance()->m_pMove->m_pos);

	if (this->m_isShakeHands == true)
	//���N�ɂ��Ă�������
	goWithBoyFunc(&CPlayerBoy::getInstance()->m_pMove->m_pos);

	
	//�ɂԂ�
	if (CPlayerBoy::getInstance()->m_isShakeHands == true || this->m_playerState == STATE::HIT) {

 		this->m_mapActions[ACTION::WASTE]->stop();
	}
	
	//�A�N�V������Ԃɉ������s��
	this->m_mapActions[this->m_playerAct]->update(this);
	
	//�����v�Z
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//�ړ��v�Z
	this->m_pMove->moveBy();
}

/**
* @desc ���N�Ɍ������Ă��߂Â�����
* @param	���N�̈ʒu
*/
void  CPlayerGirl::closeWithBoyFunc(Point* pPos) {

	//���݂��̂�����̋���
	float length = (pPos->x - this->m_pMove->m_pos.x);
	
	//�������班�N�̂�������𓱂�
	int vectol = length / abs(length);

	//�������󂢂Ă����
	if (abs(length) >= 64) {
		//���N�̌����ɉ���
		this->m_pMove->m_accele.x = 0.65f*vectol;
	}

	//������x�߂Â��΁h��Ȃ��t���O���グ��h
	if (abs(length) <= 35){
		this->m_isShakeHands = true;
	}


}

/**
* @desc ���N�ɂ��Ă�������
* @param	���N�̈ʒu
*/
void CPlayerGirl::goWithBoyFunc(Point* pPos) {

	//���N�̈ړ��p�f�[�^���擾
	CMove* pBoyMove = CPlayerBoy::getInstance()->m_pMove;

	//���݂��̂�����̋���
	float length = (pPos->x - this->m_pMove->m_pos.x);

	//�������猩�����N�̂������
	int vectolToBoy = length / abs(length);

	//���N���猩�������̂������
	int vectolToGirl = -1.0f*vectolToBoy;

	//������x�������󂫂����Ȃ�
	//�����̈ʒu�����N�̌��ɒ���
	if (abs(length) >= 32.0) {
		//�摜�̌��������킹�邽�߂ɑ��x��ݒ�
		this->m_pMove->m_pos.x = pBoyMove->m_pos.x - (85* vectolToBoy);
		this->m_pMove->m_vel.x = pBoyMove->m_vel.x;

		//this->m_pMove->m_pos.x = pBoyMove->m_pos.x - (vectolToGirl*32.0f);
	}
	//���N�������̂��鑤�Ɉړ����Ă���
	else if(vectolToGirl == pBoyMove->m_vel.x/abs(pBoyMove->m_vel.x)) {

		this->m_pMove->m_vel.x = 0;
	}

}