#include "PlayerStateHold.h"
#include "Data/Enum/EnumPlayer.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Lib/Input/InputManager.h"

/**
 * @desc	コンストラクタ
 */
CPlayerStateHold::CPlayerStateHold(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer), m_pGirl(pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerStateHold::~CPlayerStateHold(void) {}

/**
 * @desc	右向き待機状態へ移行
 */
void CPlayerStateHold::toIdleRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き待機状態へ移行
 */
void CPlayerStateHold::toIdleLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き歩行状態へ移行
 */
void CPlayerStateHold::toWalkRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き歩行状態へ移行
 */
void CPlayerStateHold::toWalkLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	右向きジャンプ状態へ移行
 */
void CPlayerStateHold::toJumpRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::JUMP_RIGHT;
	this->m_pPlayer->m_actionState = (int)PLAYER_ACTION_STATE::JUMP;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向きジャンプ状態へ移行
 */
void CPlayerStateHold::toJumpLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::JUMP_LEFT;
	this->m_pPlayer->m_actionState = (int)PLAYER_ACTION_STATE::JUMP;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	右向き落下状態へ移行
 */
void CPlayerStateHold::toFallRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::FALL_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FALL_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き落下状態へ移行
 */
void CPlayerStateHold::toFallLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::FALL_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FALL_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	お姫様抱っこ状態から通常状態へ移行（右向き）
 */
void CPlayerStateHold::toFreeIdleRight(void) {
	//右向き待機状態へ移行
	this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

	(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);
}

/**
 * @desc	お姫様抱っこ状態から通常状態へ移行（左向き）
 */
void CPlayerStateHold::toFreeIdleLeft(void) {
	//左向き待機状態へ移行
	this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

	(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);
}

//==========================================
//
// Class: CPlayerHoldIdleRightState
//
// プレイヤー お姫様抱っこ 待機 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldIdleRightState::CPlayerHoldIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldIdleRightState::~CPlayerHoldIdleRightState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldIdleRightState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerHoldIdleRightState::update(void)
{
	//優先順で処理していく


	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//手が離されたら
	if (!pointerInputController->getHugFlag())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toWalkRight();
		return;
	}


	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalkLeft();
		return;
	}

	//ジャンプ
	if (pointerInputController->getJumpFlag()) 
	{
		//右向きジャンプ状態へ移行
		this->toJumpRight();
		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldIdleLeftState
//
// プレイヤー お姫様抱っこ 待機 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldIdleLeftState::CPlayerHoldIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldIdleLeftState::~CPlayerHoldIdleLeftState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldIdleLeftState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerHoldIdleLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//手が離されたら
	if (!pointerInputController->getHugFlag())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toWalkRight();
		return;
	}


	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalkLeft();
		return;
	}

	//ジャンプ
	if (pointerInputController->getJumpFlag())
	{
		//左向きジャンプ状態へ移行
		this->toJumpLeft();
		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldWalkRightState
//
// プレイヤー お姫様抱っこ 歩行 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldWalkRightState::CPlayerHoldWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldWalkRightState::~CPlayerHoldWalkRightState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldWalkRightState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerHoldWalkRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//手が離されたら
	if (!pointerInputController->getHugFlag())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向きに歩行する
		this->m_pPlayer->m_pMove->m_accele.x = 0.5f;
		return;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalkLeft();
		return;
	}

	//ジャンプ
	if (pointerInputController->getJumpFlag())
	{
		//右向きジャンプ状態へ移行
		this->toJumpRight();
		return;
	}


	//右向き待機状態へ移行
	this->toIdleRight();
}

/**
 * @desk	状態が変わるときの処理
 */
void CPlayerHoldWalkRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerHoldWalkLeftState
//
// プレイヤー お姫様抱っこ 歩行 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldWalkLeftState::CPlayerHoldWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldWalkLeftState::~CPlayerHoldWalkLeftState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldWalkLeftState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerHoldWalkLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//手が離されたら
	if (!pointerInputController->getHugFlag())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向きに歩行状態へ移行
		this->toWalkRight();
		return;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向きに歩行する
		this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
		return;
	}

	//ジャンプ
	if (pointerInputController->getJumpFlag())
	{
		//左向きジャンプ状態へ移行
		this->toJumpLeft();
		return;
	}

	//左向き待機状態へ移行
	this->toIdleLeft();
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerHoldJumpRightState
//
// プレイヤー お姫様抱っこ ジャンプ 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldJumpRightState::CPlayerHoldJumpRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldJumpRightState::~CPlayerHoldJumpRightState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldJumpRightState::start(void)
{
	//ジャンプアクションのスタート関数を開始
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->start();

	//プレイヤーのX速度を記録する。
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	更新処理
 */
void CPlayerHoldJumpRightState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//プレイヤーのX速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y <= 0.0f) {
		//落下状態へ移行する
		this->toFallRight();

		return;
	}

	//左向きジャンプ
	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
		//開始処理を再起動する
		this->start();
		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldJumpRightState::onChangeEvent(void)
{
	//ジャンプ終了時にプレイヤーのジャンプアクションをリセットする
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldJumpLeftState
//
// プレイヤー お姫様抱っこ ジャンプ 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldJumpLeftState::CPlayerHoldJumpLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldJumpLeftState::~CPlayerHoldJumpLeftState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldJumpLeftState::start(void)
{
	//ジャンプアクションのスタート関数を開始
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->start();

	//プレイヤーのX速度を記録する。
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	更新処理
 */
void CPlayerHoldJumpLeftState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーのX速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y <= 0.0f) {
		//落下状態へ移行する
		this->toFallLeft();

		return;
	}
	//左向きジャンプ
	if (CInputManager::getInstance()->getInputController()->getJumpFlag()) {
		//開始処理を再起動する
		this->start();
		return;
	}

}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldJumpLeftState::onChangeEvent(void)
{
	//ジャンプ終了時にプレイヤーのジャンプアクションをリセットする
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->restart(this->m_pPlayer);

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldFallRightState
//
// プレイヤー お姫様抱っこ 落下 右向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldFallRightState::CPlayerHoldFallRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldFallRightState::~CPlayerHoldFallRightState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldFallRightState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	更新処理
 */
void CPlayerHoldFallRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーの速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y == 0.0f) {
		//落下状態へ移行する
		this->toIdleRight();

		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldFallRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;

	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldFallLeftState
//
// プレイヤー お姫様抱っこ 落下 左向き 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldFallLeftState::CPlayerHoldFallLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldFallLeftState::~CPlayerHoldFallLeftState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldFallLeftState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	更新処理
 */
void CPlayerHoldFallLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーの速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y == 0.0f) {
		//落下状態へ移行する
		this->toIdleLeft();

		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldFallLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;

	this->m_isNext = false;
}
