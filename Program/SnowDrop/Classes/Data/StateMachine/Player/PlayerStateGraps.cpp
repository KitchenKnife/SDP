//==========================================
//
// File: PlayerState.cpp
//
// プレイヤー状態遷移 ヘッダーファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "PlayerStateGraps.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"


//==========================================
//
// Class: CPlayerStateGraps
//
// プレイヤー 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerStateGraps::CPlayerStateGraps(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer), m_pGirl(pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerStateGraps::~CPlayerStateGraps(void) {}


/**
 * @desc	待機状態へ移行
 */
void CPlayerStateGraps::toIdle(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::IDLE;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	歩行状態へ移行
 */
void CPlayerStateGraps::toWalk(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	攻撃状態へ移行
 */
void CPlayerStateGraps::toAttack(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
 * @desc	手を離す状態へ移行
 */
void CPlayerStateGraps::toGrasp(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP;
	
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


//==========================================
//
// Class: CPlayerGraspIdleState
//
// プレイヤー 手を繋ぐ 待機 状態クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspIdleState::CPlayerGraspIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspIdleState::~CPlayerGraspIdleState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGraspIdleState::start(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerGraspIdleState::update(void)
{
	//優先順で処理していく


	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーを取得
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		this->toGrasp();

		return;
	}

	//右向き攻撃状態へ移行
	if (pointerInputController->getAttackFlag()) {
		//右向き攻撃状態へ移行
		//this->toAttack();
		return;
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
		//右へ移動（歩行）
		if (pointerInputController->getRightMoveFlag())
		{
			//右向き歩行状態へ移行
			this->toWalk();
			return;
		}
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
		//左へ移動（歩行）
		if (pointerInputController->getLeftMoveFlag())
		{
			//歩行状態へ移行
			this->toWalk();
			return;
		}
	}

	
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGraspIdleState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspWalkState
//
// プレイヤー 手を繋ぐ 歩行 状態クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspWalkState::CPlayerGraspWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspWalkState::~CPlayerGraspWalkState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGraspWalkState::start(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerGraspWalkState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーを取得
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		this->toGrasp();

		return;
	}

	//右向き攻撃状態へ移行
	if (pointerInputController->getAttackFlag()) {
		//右向き攻撃状態へ移行
		//this->toAttack();
		return;
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
		//右へ移動（歩行）
		if (pointerInputController->getRightMoveFlag())
		{
			//右向き歩行状態へ移行
			this->toWalk();
			return;
		}
	}

	if (this->m_pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
		//左へ移動（歩行）
		if (pointerInputController->getLeftMoveFlag())
		{
			//歩行状態へ移行
			this->toWalk();
			return;
		}
	}

	//待機状態へ移行
	this->toIdle();
}

/**
* @desk	状態が変わるときの処理
*/
void CPlayerGraspWalkState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::WALK])[0]->stop();

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspAttackState
//
// プレイヤー 手を繋ぐ 攻撃 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspAttackState::CPlayerGraspAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspAttackState::~CPlayerGraspAttackState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGraspAttackState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();

	//攻撃アクションをスタートさせる
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();

}

/**
* @desc	更新処理
*/
void CPlayerGraspAttackState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//右向き待機状態へ戻す
		this->toIdle();
		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGraspAttackState::onChangeEvent(void)
{
	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerGraspReleaseState
//
// プレイヤー 手を繋ぐ 手を離す 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspReleaseState::CPlayerGraspReleaseState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspReleaseState::~CPlayerGraspReleaseState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGraspReleaseState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
* @desc	更新処理
*/
void CPlayerGraspReleaseState::update(void)
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
void CPlayerGraspReleaseState::onChangeEvent(void)
{
	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}