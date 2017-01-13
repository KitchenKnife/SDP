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
 * @desc	待機状態へ移行
 */
void CPlayerStateHold::toIdle(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	歩行状態へ移行
 */
void CPlayerStateHold::toWalk(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	ジャンプ状態へ移行
 */
void CPlayerStateHold::toJump(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	落下状態へ移行
 */
void CPlayerStateHold::toFall(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::FALL;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	お姫様抱っこ状態から通常状態へ移行（右向き）
 */
void CPlayerStateHold::toFreeIdle(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::HOLD;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

//==========================================
//
// Class: CPlayerHoldIdleState
//
// プレイヤー お姫様抱っこ 待機 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldIdleState::CPlayerHoldIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldIdleState::~CPlayerHoldIdleState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldIdleState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerHoldIdleState::update(void)
{
	//優先順で処理していく


	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//手が離されたら
	if (!pointerInputController->getHugFlag())
	{
		this->toFreeIdle();

		return;
	}

	//ジャンプ
	if (pointerInputController->getJumpFlag())
	{
		//右向きジャンプ状態へ移行
		this->toJump();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//歩行状態へ移行
		this->toWalk();

		//右向きへ変更
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;

		return;
	}


	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//歩行状態へ移行
		this->toWalk();
		
		//左向きへ変更
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;

		return;
	}

	
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldIdleState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldWalkState
//
// プレイヤー お姫様抱っこ 歩行 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldWalkState::CPlayerHoldWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldWalkState::~CPlayerHoldWalkState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldWalkState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerHoldWalkState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//手が離されたら
	if (!pointerInputController->getHugFlag())
	{
		this->toFreeIdle();

		return;
	}

	//ジャンプ
	if (pointerInputController->getJumpFlag())
	{
		//右向きジャンプ状態へ移行
		this->toJump();
		return;
	}


	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向きに歩行する
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
		return;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
		return;
	}

	

	//右向き待機状態へ移行
	this->toIdle();
}

/**
 * @desk	状態が変わるときの処理
 */
void CPlayerHoldWalkState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::WALK])[0]->stop();

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldJumpState
//
// プレイヤー お姫様抱っこ ジャンプ 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldJumpState::CPlayerHoldJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldJumpState::~CPlayerHoldJumpState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldJumpState::start(void)
{
	//ジャンプアクションのスタート関数を開始
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->start();

	//プレイヤーのX速度を記録する。
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	更新処理
 */
void CPlayerHoldJumpState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//プレイヤーのX速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y <= 0.0f) {
		//落下状態へ移行する
		this->toFall();

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
void CPlayerHoldJumpState::onChangeEvent(void)
{
	//ジャンプ終了時にプレイヤーのジャンプアクションをリセットする
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldFallState
//
// プレイヤー お姫様抱っこ 落下 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerHoldFallState::CPlayerHoldFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerHoldFallState::~CPlayerHoldFallState(void) {}

/**
 * @desc	開始処理
 */
void CPlayerHoldFallState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
 * @desc	更新処理
 */
void CPlayerHoldFallState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーの速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y == 0.0f) {
		//落下状態へ移行する
		this->toIdle();

		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerHoldFallState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;

	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldReleaseState
//
// プレイヤー お姫様抱っこ 下ろす 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerHoldReleaseState::CPlayerHoldReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateHold::CPlayerStateHold(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerHoldReleaseState::~CPlayerHoldReleaseState(void) {}

/**
* @desc	開始処理
*/
void CPlayerHoldReleaseState::start(void)
{
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
* @desc	更新処理
*/
void CPlayerHoldReleaseState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE);

		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerHoldReleaseState::onChangeEvent(void)
{

	this->m_isNext = false;
}
