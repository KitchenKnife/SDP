/*
* PlayerActionController.cpp
*
*	2016/11/24	Osumi
*
*/

#include "Data/ActionController/PlayerActionController/PlayerActionController.h"
#include "Model/Character/PlayerCharacter.h"

//===================================================================
//	プレイヤーの持ち上げアクション	
//===================================================================
/*
* @desc 処理
*/
void CPlayerLiftUpAction::start() {

	//ジャンプ開始
	//this->m_isCrouching = true;

	//CAnimation* pAnime = pBoy->m_mapAnimations[CPlayerCharacter::STATE::LIFT_UPING];
}

/*
* @desc 更新処理
* @param 対象のキャラクター
* @tips 関数を呼び出す
*/
void CPlayerLiftUpAction::update(CCharacter* pChara) {
	
	CPlayerBoy* pBoy = CPlayerBoy::getInstance();
	CPlayerGirl* pGirl = CPlayerGirl::getInstance();

	if (this->m_LiftStep == 0) {

		//持ち上げ行動時の基準方向の設定
		this->m_liftVec = (pBoy->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x) / abs(pBoy->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x);

		//画像の向きを設定
		pBoy->setScale(this->m_liftVec*-1.0f,1.0);
		pGirl->setScale(this->m_liftVec, 1.0);

		//少女の座標を保存
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
* @desc ジャンプ終了
* @tips 着地した際にこの関数を呼び出す
*/
void CPlayerLiftUpAction::stop(){

	//アクションフラグをNONEにする
	CPlayerBoy::getInstance()->m_playerAct = CPlayerCharacter::ACTION::NONE;
	CPlayerBoy::getInstance()->m_playerState = CPlayerCharacter::STATE::STAND;
	CPlayerGirl::getInstance()->m_playerState = CPlayerCharacter::STATE::WASTE;

	CPlayerBoy::getInstance()->m_nonInputFlag = false;
	this->m_LiftStep = 0;
}


//===================================================================
//
//	少女の暇つぶしアクションの派生元
//
//===================================================================

/*
* @desc 暇つぶし開始処理
* @tips 暇つぶし時間がある程度経過したらに呼び出す
*/
void CGirlBaseWasteTimeAction::start(){

	CPlayerGirl* pGirl = CPlayerGirl::getInstance();
	//暇つぶしフラグを上げる
	pGirl->m_wasteActFlag = true;
	pGirl->m_playerState = CPlayerCharacter::STATE::WASTE;
	pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE;
	
}

/*
* @desc 更新処理（ジャンプ移動計算）
* @param 対象のキャラクター
* @tips 関数を呼び出す
*/
void CGirlBaseWasteTimeAction::update(CCharacter* pChara){

	CPlayerGirl* pGirl = CPlayerGirl::getInstance();

	//暇つぶしカウンターをインクリメント
	pGirl->m_wasteActCounter++;

	//暇つぶしカウンターがたまったら
	if (pGirl->m_wasteActCounter >= pGirl->m_wasteTime) {
		//カウンターをリセット
		pGirl->m_wasteActCounter = 0;
		
		this->branchWasteAction();
	}

}

//暇つぶし行動の枝分かれ
void CGirlBaseWasteTimeAction::branchWasteAction(){

	//ランダムで暇つぶし行動に派生
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
* @desc　終了
*/
void CGirlBaseWasteTimeAction::stop() {
	CPlayerGirl* pGirl = CPlayerGirl::getInstance();
	//カウンターをリセット
	pGirl->m_wasteActCounter = 0;
	//暇つぶしフラグうぃ下げる
	pGirl->m_wasteActFlag = false;
}

//===================================================================
//
//	少女の暇つぶしアクション_00　基底クラス
//
//===================================================================
//コンストラクタ
CGirlWasteBaseAction::CGirlWasteBaseAction(){
	//this->m_pGirl = CPlayerGirl::getInstance();
	//this->m_stateType = state;
}

/*
* @desc 暇つぶし処理
*/
void CGirlWasteBaseAction::start() {
	this->m_pGirl = CPlayerGirl::getInstance();
}

/*
* @desc　終了
*/
void CGirlWasteBaseAction::stop() {

	if (CPlayerBoy::getInstance()->m_isShakeHands == true) {
 		CCLOG("");
	}

	//暇つぶしフラグうぃ下げる
	this->m_pGirl->m_wasteActFlag = false;
	//カウンターをリセット
	this->m_pGirl->m_wasteActCounter = 0;
	this->m_pGirl->m_pMove->m_vel.x = 0.0f;
	//アクション状態を待機（暇つぶし）に
	this->m_pGirl->m_playerAct = CPlayerCharacter::ACTION::WASTE;
	this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE;
	
} 

//===================================================================
//	少女の暇つぶしアクション_01
//  上下に揺れる
//===================================================================
//コンストラクタ
CGirlWasteAction_01::CGirlWasteAction_01(){
	//this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_01;
	//this->m_stateType = CPlayerCharacter::STATE::WASTE_ANIME_01;
	this->m_actionTime = 240;
}

/*
* @desc 暇つぶし処理
*/
void CGirlWasteAction_01::start() {
	CGirlWasteBaseAction::start();
	this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_01;
}

/*
* @desc 更新処理
*/
void CGirlWasteAction_01::update(CCharacter* pChara) {
	//暇つぶしカウンターをインクリメント
	this->m_pGirl->m_wasteActCounter++;

	//暇つぶしカウンターがたまったら
	if (this->m_pGirl->m_wasteActCounter >= this->m_actionTime) {
		//カウンターをリセット
		//this->m_pGirl->m_wasteActCounter = 0;

		this->stop();
	}
}


//===================================================================
//	少女の暇つぶしアクション_02
//　左右に歩く
//===================================================================
//コンストラクタ
CGirlWasteAction_02::CGirlWasteAction_02() {
	//CGirlWasteBaseAction(CPlayerCharacter::STATE::WASTE_ANIME_02) {
	//this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_02;
	//this->m_stateType = CPlayerCharacter::STATE::WASTE_ANIME_02;
	this->m_actionTime = 200;
}

/*
* @desc 暇つぶし処理
*/
void CGirlWasteAction_02::start() {
	CGirlWasteBaseAction::start();
	//※this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WASTE_ANIME_02;
	this->m_pGirl->m_playerState = CPlayerCharacter::STATE::WALK;

}

/*
* @desc 更新処理
*/
void CGirlWasteAction_02::update(CCharacter* pChara) {
	//暇つぶしカウンターをインクリメント
	this->m_pGirl->m_wasteActCounter++;

	//暇つぶしカウンターがたまったら
	if (this->m_pGirl->m_wasteActCounter >= this->m_actionTime) {
		//ステップをリセット
		this->m_actionStep = 0;
		this->stop();
	}

	
	// 0.移動する向きの設定
	if (this->m_actionStep == 0) {
		int vec = rand() % 2;
		if (vec == 0) { this->m_vec = 1; }
		else { this->m_vec = -1; }

		this->m_actionStep = 1;
	}

	// 1.向きに沿って移動
	if (this->m_actionStep == 1) {
		this->m_pGirl->m_pMove->m_vel.x = 1.5f*this->m_vec;

		this->m_waitCounter++;
		if (this->m_waitCounter == 120) {
			this->m_waitCounter = 0;

			this->m_actionStep = 2;
		}
	}

	// 2.立ち止まる
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

	// 3.向きに沿って移動
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


