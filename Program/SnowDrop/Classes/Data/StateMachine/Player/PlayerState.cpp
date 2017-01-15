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
#include "PlayerState.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CPlayerState
//
// プレイヤー 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerState::CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer),m_pGirl(pGirl){}

/**
 * @desc	デストラクタ 
 */
CPlayerState::~CPlayerState(void){}

/**
 * @desc	待機状態へ移行
 */
void CPlayerState::toIdle(void)
{

	//プレイヤーの状態
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::IDLE;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	歩行状態へ移行
 */
void CPlayerState::toWalk(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::WALK;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	ジャンプ状態へ移行
 */
void CPlayerState::toJump(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::JUMP;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	落下状態へ移行
 */
void CPlayerState::toFall(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::FALL;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	攻撃状態へ移行
 */
void CPlayerState::toAttack(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	ジャンプ攻撃へ移行
 */
void CPlayerState::toJumpAttack(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_ATTACK;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	攻撃を受けた状態へ移行
 */
void CPlayerState::toUnderAttack(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UNDER_ATTACK;

	this->m_nextRegisterKey = this->m_pPlayer->m_state;

	this->m_isNext = true;
}


/*
 * @desc	手を掴む状態へ移行
 */
void CPlayerState::toGrasp(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::GRASP;

	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/*
 *	@desc	お姫様抱っこ状態へ移行
 */
void CPlayerState::toHold(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::HOLD;

	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pPlayer->m_state;

	//待機動作を終了
	this->m_isNext = true;
}

//==========================================
//
// Class: CPlayerIdleState
//
// プレイヤー 待機 状態クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerIdleState::CPlayerIdleState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer,pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerIdleState::~CPlayerIdleState(void){}

/**
 * @desc	開始処理
 */
void CPlayerIdleState::start(void)
{
	
}

/**
 * @desc	更新処理
 */
void CPlayerIdleState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
	
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//プレイヤーが攻撃を受けたら
	if (this->m_pPlayer->m_underAttack) {
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
	}
	
	//少女にマークパーティクルが出現しているか確認
	if (pGirl->getPlayerAndGirlActionMark()) {
		//出現していたら
		//手を握る　お姫様抱っこ　のキーが押されているかチェック
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//手を繋ぐ右状態へ移行
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
			}
			else
			{
				//手を繋ぐ左状態へ移行
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
			}
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHold();

		}

	}


	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//右向き装備状態へ移行
	//	this->toEquipRight();
	//	return;
	}

	//右攻撃
	if (pointerInputController->getAttackFlag()) {
		//右攻撃状態へ移行(１撃目)
		this->toAttack();
		return;
	}

	//右向きジャンプ
	if (pointerInputController->getJumpFlag()) {
		//右向きジャンプ状態へ移行
		this->toJump();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toWalk();
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
		return;
	}


	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalk();
		this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerIdleState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerWalkState
//
// プレイヤー 歩行 状態クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerWalkState::CPlayerWalkState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerWalkState::~CPlayerWalkState(void){}

/**
 * @desc	 開始処理
 */
void CPlayerWalkState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerWalkState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//プレイヤーが攻撃を受けたら
	if (this->m_pPlayer->m_underAttack) {
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
	}

	//少女にマークパーティクルが出現しているか確認
	if (pGirl->getPlayerAndGirlActionMark()) {
		//出現していたら
		//手を握る　お姫様抱っこ　のキーが押されているかチェック
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//手を繋ぐ右状態へ移行
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::RIGHT;
			}
			else
			{
				//手を繋ぐ左状態へ移行
				this->toGrasp();
				this->m_pPlayer->m_playerDirectionState = (int)PLATYER_DIRECTION_STATE::LEFT;
			}
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHold();

		}

	}

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y < 0.0f) {
		//落下状態へ移行する
		this->toFall();

		return;
	}


	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//右向き装備状態へ移行
	//	this->toEquipRight();
	//	return;
	}
	
	//攻撃
	if (pointerInputController->getAttackFlag()) {
		//攻撃状態へ移行
		this->toAttack();
		return;
	}

	//ジャンプ
	if (pointerInputController->getJumpFlag()) {
		//ジャンプ状態へ移行
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

	//待機状態へ移行
	this->toIdle();
}

/**
 * @desk	状態が変わるときの処理
 */
void CPlayerWalkState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::WALK])[0]->stop();

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerJumpState
//
// プレイヤー ジャンプ 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerJumpState::CPlayerJumpState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerJumpState::~CPlayerJumpState(void) {}

/**
* @desc	開始処理
*/
void CPlayerJumpState::start(void)
{
	//ジャンプアクションのスタート関数を開始
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->start();

	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	更新処理
*/
void CPlayerJumpState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーが攻撃を受けたら
	if (this->m_pPlayer->m_underAttack) {
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
	}

	if (pointerInputController->getAttackFlag()) {
		//右ジャンプ攻撃状態へ移行する
		//this->toJumpAttack();
		return;
	}

	//プレイヤーの速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//右移動
	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
		this->m_pPlayer->m_pMove->m_vel.x += 1.0f;
	}
	//左移動
	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
		this->m_pPlayer->m_pMove->m_vel.x += -1.0f;
	}

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
void CPlayerJumpState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerFallState
//
// プレイヤー 落下 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerFallState::CPlayerFallState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerFallState::~CPlayerFallState(void) {}

/**
* @desc	開始処理
*/
void CPlayerFallState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	更新処理
*/
void CPlayerFallState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//プレイヤーが攻撃を受けたら
	if (this->m_pPlayer->m_underAttack) {
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
	}

	if (pointerInputController->getAttackFlag()) {
		//右ジャンプ攻撃状態へ移行する
		//this->toJumpAttack();
		return;
	}

	//プレイヤーの速度を維持させる
	this->m_pPlayer->m_pMove->m_vel.x = this->m_velX;

	//右移動
	if (CInputManager::getInstance()->getInputController()->getRightMoveFlag()) {
		this->m_pPlayer->m_pMove->m_accele.x = 2.0f;
	}
	//左移動
	if (CInputManager::getInstance()->getInputController()->getLeftMoveFlag()) {
		this->m_pPlayer->m_pMove->m_accele.x = -2.0f;
	}

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
void CPlayerFallState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;


	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerAttackState
//
// プレイヤー 攻撃 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerAttackState::CPlayerAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerAttackState::~CPlayerAttackState(void){}

/**
 * @desc	開始処理
 */
void CPlayerAttackState::start(void)
{

	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();

	//攻撃アクションをスタートさせる
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::ATTACK])[0]->start();

	//連撃フラグをfalseで始める
	this->m_pPlayer->m_chainAttackFlag = false;
}

/**
 * @desc	更新処理
 */
void CPlayerAttackState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//攻撃ボタンが押されたか
	if (pointerInputController->getAttackFlag())
	{
		//攻撃連鎖フラグをtrue にする
		this->m_pPlayer->m_chainAttackFlag = true;
	}

	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//待機状態へ移行
		this->toIdle();
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerAttackState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerJumpAttackState
//
// プレイヤー ジャンプ攻撃 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerJumpAttackState::CPlayerJumpAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerJumpAttackState::~CPlayerJumpAttackState(){}

/**
 * @desc	開始処理
 */
void CPlayerJumpAttackState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
	
	//プレイヤーのジャンプアクションを停止させる。
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::JUMP])[0]->stop();

	//プレイヤーのｙ軸移動速度を０に戻す
	this->m_pPlayer->m_pMove->m_vel.y = 0.0f;


	//ダメージキャラクター生成データを作成
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
		cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_right, this->m_pPlayer->m_pMove->m_pos.y),
		1);
	//ダメージキャラクター生成トリガーを作成
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//作成したトリガーをスケジューラーに登録
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);


}

/**
 * @desc	更新処理
 */
void CPlayerJumpAttackState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd() && this->m_pPlayer->m_pMove->m_vel.y == 0.0f)
	{
		//右向き待機状態へ戻す
		this->toIdle();
		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerJumpAttackState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerUnderAttackState
//
// プレイヤー 攻撃を受けた 状態クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerUnderAttackState::CPlayerUnderAttackState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerUnderAttackState::~CPlayerUnderAttackState() {}

/**
* @desc	開始処理
*/
void CPlayerUnderAttackState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();

	//現在のアクションをスタートさせる。
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_STATE::UNDER_ATTACK])[0]->start();
}

/**
* @desc	更新処理
*/
void CPlayerUnderAttackState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//待機状態へ戻す
		this->toIdle();

		this->m_pPlayer->m_underAttack = false;

		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerUnderAttackState::onChangeEvent(void)
{
	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspState
//
// プレイヤー 手を繋ぐ 状態クラス
//
// 2016/12/26
//						Author Harada 
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerGraspState::CPlayerGraspState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerGraspState::~CPlayerGraspState(void){}

/**
 * @desc	開始処理
 */
void CPlayerGraspState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
 * @desc	更新処理
 */
void CPlayerGraspState::update(void)
{
	//優先順で処理していく

	//手を繋ぐアニメーションが終わったら
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//右向き待機状態へ移行
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE);
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerGraspState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerHoldState
//
// プレイヤー お姫様抱っこ 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerHoldState::CPlayerHoldState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerHoldState::~CPlayerHoldState(void) {}

/**
* @desc	開始処理
*/
void CPlayerHoldState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->reset();
}

/**
* @desc	更新処理
*/
void CPlayerHoldState::update(void)
{
	//優先順で処理していく

	//手を繋ぐアニメーションが終わったら
	if ((*this->m_pPlayer->m_pMapAnimations)[this->m_pPlayer->m_state + this->m_pPlayer->m_playerAndGirlState + this->m_pPlayer->m_playerDirectionState]->isEnd())
	{
		//左向き待機状態へ移行
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE);
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerHoldState::onChangeEvent(void)
{
	this->m_pPlayer->m_underAttack = false;

	this->m_isNext = false;
}
//EOF