/*
* PlayerActionController.cpp
*
*	2016/11/24	Osumi
*
*/

#include "Data/ActionController/PlayerActionController/PlayerActionController.h"
#include "Model/Character/PlayerCharacter.h"

//===================================================================
//	�v���C���[�̎����グ�A�N�V����	
//===================================================================
/*
* @desc ����
*/
void CPlayerLiftUpAction::start() {

	//�W�����v�J�n
	//this->m_isCrouching = true;

	//CAnimation* pAnime = pBoy->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING];
}

/*
* @desc �X�V����
* @param �Ώۂ̃L�����N�^�[
* @tips �֐����Ăяo��
*/
void CPlayerLiftUpAction::update(CCharacter* pChara) {
	
	CPlayerBoy* pBoy = CPlayerBoy::getInstance();
	CPlayerGirl* pGirl = CPlayerGirl::getInstance();

	if (this->m_LiftStep == 0) {

		//�����グ�s�����̊�����̐ݒ�
		this->m_liftVec = (pBoy->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x) / abs(pBoy->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x);

		//�摜�̌�����ݒ�
		pBoy->setScale(this->m_liftVec*-1.0f,1.0);
		pGirl->setScale(this->m_liftVec, 1.0);

		//�����̍��W��ۑ�
		this->m_girlGoalPoint = (pBoy->m_pMove->m_pos.x + pBoy->m_pBody->m_left*this->m_liftVec) + (pGirl->m_pBody->m_right*this->m_liftVec);

		pBoy->m_playerState = CPlayerCharacter::STATE::LIFT_UPING;
		
		pBoy->m_nonInputFlag = true;
		this->m_LiftStep = 1;
	}

	static CAnimation* pAnime = pBoy->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING];

	//pAnime->update();

	if (this->m_LiftStep == 1 && pAnime->getCurrentFrame() >= this->m_crouchFrame) {

		if (pGirl->m_pMove->m_vel.y <= 4.0f) {
			pGirl->m_pMove->m_accele.y = 0.6f;
			pGirl->m_playerState = CPlayerCharacter::STATE::LIFT_UPING;
		}

		if (pGirl->m_pMove->m_pos.y + pGirl->m_pBody->m_bottom > pBoy->m_pMove->m_pos.y + pBoy->m_pBody->m_bottom) {
			pGirl->m_pMove->m_vel.y = 0.0f;
			pGirl->m_pMove->m_accele.y = 0.5f;

			this->m_LiftStep = 2;
		}
	}

	if (this->m_LiftStep == 2){

		this->m_pauseTimeCounter++;

		if (this->m_pauseTimeCounter >= 20) {
			this->m_LiftStep = 3;
		}
	}

	
	if (this->m_LiftStep == 3) {

		pGirl->m_pMove->m_vel.x = 3.0f * this->m_liftVec;

		pBoy->m_pMove->m_vel.x = 3.0f * this->m_liftVec;
		
		if (abs(this->m_girlGoalPoint - pGirl->m_pMove->m_pos.x) <= 3.0f) {
			pBoy->m_pMove->setVel(0,0);
			pGirl->m_pMove->setVel(0, 0);
			pGirl->m_pMove->m_accele.y = 0.0f;
			this->m_LiftStep = 4;

			this->stop();
		}	
	}
}


/*
* @desc �W�����v�I��
* @tips ���n�����ۂɂ��̊֐����Ăяo��
*/
void CPlayerLiftUpAction::stop(){

	//�A�N�V�����t���O��NONE�ɂ���
	CPlayerBoy::getInstance()->m_playerAct = CPlayerCharacter::ACTION::NONE;
	CPlayerBoy::getInstance()->m_playerState = CPlayerCharacter::STATE::STAND;
	CPlayerGirl::getInstance()->m_playerState = CPlayerCharacter::STATE::WASTE;

	CPlayerBoy::getInstance()->m_nonInputFlag = false;
	this->m_LiftStep = 0;
}


//===================================================================
//
//	�����̉ɂԂ��A�N�V�����̔h����
//
//===================================================================

/*
* @desc �ɂԂ��J�n����
* @tips �ɂԂ����Ԃ�������x�o�߂�����ɌĂяo��
*/
void CGirlBaseWasteTimeAction::start(){

	CPlayerGirl* pGirl = CPlayerGirl::getInstance();
	//�ɂԂ��t���O���グ��
	pGirl->m_wasteActFlag = true;
	pGirl->m_playerState = CPlayerCharacter::STATE::WASTE;
	pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE;
	
}

/*
* @desc �X�V�����i�W�����v�ړ��v�Z�j
* @param �Ώۂ̃L�����N�^�[
* @tips �֐����Ăяo��
*/
void CGirlBaseWasteTimeAction::update(CCharacter* pChara){

	CPlayerGirl* pGirl = CPlayerGirl::getInstance();

	//�ɂԂ��J�E���^�[���C���N�������g
	pGirl->m_wasteActCounter++;

	//�ɂԂ��J�E���^�[�����܂�����
	if (pGirl->m_wasteActCounter >= pGirl->m_wasteTime) {
		//�J�E���^�[�����Z�b�g
		pGirl->m_wasteActCounter = 0;
		
		this->branchWasteAction();
	}

}

//�ɂԂ��s���̎}������
void CGirlBaseWasteTimeAction::branchWasteAction(){

	//�����_���ŉɂԂ��s���ɔh��
	int actNum = rand() % m_actions;
	CPlayerGirl* pGirl = CPlayerGirl::getInstance();

	switch (actNum + 1) {

	case 1:
		pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE_ACT_01;
		break;

	case 2:
		pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE_ACT_02;
		break;

	case 3:
		pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE_ACT_03;
		break;

	default:
		pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE;
		break;

	}

	pGirl->m_mapActions[pGirl->m_playerAct]->start();

}

/*
* @desc�@�I��
*/
void CGirlBaseWasteTimeAction::stop() {
	CPlayerGirl* pGirl = CPlayerGirl::getInstance();
	//�J�E���^�[�����Z�b�g
	pGirl->m_wasteActCounter = 0;
	//�ɂԂ��t���O����������
	pGirl->m_wasteActFlag = false;
}

//===================================================================
//
//	�����̉ɂԂ��A�N�V����_00�@���N���X
//
//===================================================================
//�R���X�g���N�^
CGirlWasteBaseAction::CGirlWasteBaseAction(){
	//this->m_pGirl = CPlayerGirl::getInstance();
	//this->m_stateType = state;
}

/*
* @desc �ɂԂ�����
*/
void CGirlWasteBaseAction::start() {
	this->m_pGirl = CPlayerGirl::getInstance();
}

/*
* @desc�@�I��
*/
void CGirlWasteBaseAction::stop() {

	if (CPlayerBoy::getInstance()->m_isShakeHands == true) {
 		CCLOG("");
	}

	//�ɂԂ��t���O����������
	this->m_pGirl->m_wasteActFlag = false;
	//�J�E���^�[�����Z�b�g
	this->m_pGirl->m_wasteActCounter = 0;
	this->m_pGirl->m_pMove->m_vel.x = 0.0f;
	//�A�N�V������Ԃ�ҋ@�i�ɂԂ��j��
	this->m_pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE;
	this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE;
	
} 

//===================================================================
//	�����̉ɂԂ��A�N�V����_01
//  �㉺�ɗh���
//===================================================================
//�R���X�g���N�^
CGirlWasteAction_01::CGirlWasteAction_01(){
	//this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_01;
	//this->m_stateType = CPlayerCharacter::STATE::WASTE_ANIME_01;
	this->m_actionTime = 240;
}

/*
* @desc �ɂԂ�����
*/
void CGirlWasteAction_01::start() {
	CGirlWasteBaseAction::start();
	this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_01;
}

/*
* @desc �X�V����
*/
void CGirlWasteAction_01::update(CCharacter* pChara) {
	//�ɂԂ��J�E���^�[���C���N�������g
	this->m_pGirl->m_wasteActCounter++;

	//�ɂԂ��J�E���^�[�����܂�����
	if (this->m_pGirl->m_wasteActCounter >= this->m_actionTime) {
		//�J�E���^�[�����Z�b�g
		//this->m_pGirl->m_wasteActCounter = 0;

		this->stop();
	}
}


//===================================================================
//	�����̉ɂԂ��A�N�V����_02
//�@���E�ɕ���
//===================================================================
//�R���X�g���N�^
CGirlWasteAction_02::CGirlWasteAction_02() {
	//CGirlWasteBaseAction(CPlayerCharacter::STATE::WASTE_ANIME_02) {
	//this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_02;
	//this->m_stateType = CPlayerCharacter::STATE::WASTE_ANIME_02;
	this->m_actionTime = 200;
}

/*
* @desc �ɂԂ�����
*/
void CGirlWasteAction_02::start() {
	CGirlWasteBaseAction::start();
	//��this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_02;
	this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WALK;

}

/*
* @desc �X�V����
*/
void CGirlWasteAction_02::update(CCharacter* pChara) {
	//�ɂԂ��J�E���^�[���C���N�������g
	this->m_pGirl->m_wasteActCounter++;

	//�ɂԂ��J�E���^�[�����܂�����
	if (this->m_pGirl->m_wasteActCounter >= this->m_actionTime) {
		//�X�e�b�v�����Z�b�g
		this->m_actionStep = 0;
		this->stop();
	}

	
	// 0.�ړ���������̐ݒ�
	if (this->m_actionStep == 0) {
		int vec = rand() % 2;
		if (vec == 0) { this->m_vec = 1; }
		else { this->m_vec = -1; }

		this->m_actionStep = 1;
	}

	// 1.�����ɉ����Ĉړ�
	if (this->m_actionStep == 1) {
		this->m_pGirl->m_pMove->m_vel.x = 1.5f*this->m_vec;

		this->m_waitCounter++;
		if (this->m_waitCounter == 120) {
			this->m_waitCounter = 0;

			this->m_actionStep = 2;
		}
	}

	// 2.�����~�܂�
	if (this->m_actionStep == 2) {
		this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE;
		this->m_waitCounter++;
		if (this->m_waitCounter == 30) {
			this->m_waitCounter = 0;

			int vec = rand() % 2;
			if (vec == 0) { this->m_vec = 1; }
			else { this->m_vec = -1; }
			this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WALK;
			this->m_actionStep = 3;
		}
	}

	// 3.�����ɉ����Ĉړ�
	if (this->m_actionStep == 3) {
		this->m_pGirl->m_pMove->m_vel.x = 1.5f*this->m_vec;

		this->m_waitCounter++;
		if (this->m_waitCounter == 40) {
			this->m_waitCounter = 0;
			this->m_pGirl->m_pMove->m_vel.x = 0.0f;
			this->m_actionStep = 0;
			this->stop();
		}
	}

}


