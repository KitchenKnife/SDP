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
 * @desc	右向き待機状態へ移行
 */
void CPlayerState::toIdleRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き待機状態へ移行
 */
void CPlayerState::toIdleLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::IDLE_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::IDLE_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き歩行状態へ移行
 */
void CPlayerState::toWalkRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::WALK_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::WALK_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き歩行状態へ移行
 */
void CPlayerState::toWalkLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::WALK_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	右向きジャンプ状態へ移行
 */
void CPlayerState::toJumpRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::JUMP_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::JUMP_RIGHT;
	this->m_pPlayer->m_actionState		= (int)PLAYER_ACTION_STATE::JUMP;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向きジャンプ状態へ移行
 */
void CPlayerState::toJumpLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::JUMP_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::JUMP_LEFT;
	this->m_pPlayer->m_actionState		= (int)PLAYER_ACTION_STATE::JUMP;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
 * @desc	右向き落下状態へ移行
 */
void CPlayerState::toFallRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::FALL_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::FALL_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	左向き落下状態へ移行
*/
void CPlayerState::toFallLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::FALL_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::FALL_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き攻撃状態（１撃目）へ移行
 */
void CPlayerState::toAttackFirstRight(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き攻撃状態（２撃目）へ移行
 */
void CPlayerState::toAttackSecondRight(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き攻撃状態（３撃目）へ移行
 */
void CPlayerState::toAttackThirdRight(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き攻撃状態（１撃目）へ移行
 */
void CPlayerState::toAttackFirstLeft(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き攻撃状態（２撃目）へ移行
 */
void CPlayerState::toAttackSecondLeftt(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き攻撃状態（３撃目）へ移行
 */
void CPlayerState::toAttackThirdLeft(void) {
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向きジャンプ攻撃へ移行
 */
void CPlayerState::toJumpAttackRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::JUMP_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向きジャンプ攻撃へ移行
 */
void CPlayerState::toJumpAttackLeft(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::JUMP_ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::JUMP_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き　装備する状態へ移行
 */
void CPlayerState::toEquipRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き　装備する状態へ移行
 */
void CPlayerState::toEquipLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/*
 * @desc	右向き　装備解除状態へ移行
 */
void CPlayerState::toUnEquipRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
 * @desc	左向き　装備解除状態へ移行
 */
void CPlayerState::toUnEquipLeft(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::UN_EQUIP_LEFT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::UN_EQUIP_LEFT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/*
 * @desc	右向き手を掴む状態へ移行
 */
void CPlayerState::toGraspRight(void)
{
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_actionState		= 0;
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
 * @desc	左向き手を掴む状態へ移行
 */
void CPlayerState::toGraspLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state			= (int)PLAYER_STATE::GRASP_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState	= (int)PLAYER_ANIMATION_STATE::GRASP_LEFT;
	//現在のプレイヤーのアクション状態
	this->m_pPlayer->m_actionState		= 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey				= this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
 *	@desc	右向きお姫様抱っこ状態へ移行
 */
void CPlayerState::toHoldRight(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::HOLD_RIGHT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::HOLD_RIGHT;
	//現在のプレイヤーのアクション状態
	this->m_pPlayer->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
 *	@desc	左向きお姫様抱っこ状態へ移行
 */
void CPlayerState::toHoldLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::HOLD_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::HOLD_LEFT;
	//現在のプレイヤーのアクション状態
	this->m_pPlayer->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

//==========================================
//
// Class: CPlayerIdleRightState
//
// プレイヤー 右向き 待機 状態 クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerIdleRightState::CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer,pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerIdleRightState::~CPlayerIdleRightState(void){}

/**
 * @desc	開始処理
 */
void CPlayerIdleRightState::start(void)
{
	
}

/**
 * @desc	更新処理
 */
void CPlayerIdleRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();
	
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();
	
	//少女にマークパーティクルが出現しているか確認
	if (pGirl->getPlayerAndGirlActionMark()) {
		//出現していたら
		//手を握る　お姫様抱っこ　のキーが押されているかチェック
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//手を繋ぐ右状態へ移行
				this->toGraspRight();
			}
			else
			{
				//手を繋ぐ左状態へ移行
				this->toGraspLeft();
			}
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHoldRight();
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
		this->toAttackFirstRight();
		return;
	}

	//右向きジャンプ
	if (pointerInputController->getJumpFlag()) {
		//右向きジャンプ状態へ移行
		this->toJumpRight();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toWalkRight();
		return;
		//this->m_pMove->m_accele.x = 0.5f;
	}


	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalkLeft();
		return;
		
		//this->m_pMove->m_accele.x = -0.5f;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerIdleLeftState
//
// プレイヤー 左向き　待機 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerIdleLeftState::CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerIdleLeftState::~CPlayerIdleLeftState(void){}

/**
 * @desc	開始処理
 */
void CPlayerIdleLeftState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerIdleLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//少女にマークパーティクルが出現しているか確認
	if (pGirl->getPlayerAndGirlActionMark()) {
		//出現していたら
		//手を握る　お姫様抱っこ　のキーが押されているかチェック
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//手を繋ぐ右状態へ移行
				this->toGraspRight();
			}
			else
			{
				//手を繋ぐ左状態へ移行
				this->toGraspLeft();
			}
			return;
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHoldLeft();
		}
	}

	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//左向き装備状態へ移行
	//	this->toEquipLeft();
	//	return;
	}
	
	//左攻撃
	if (pointerInputController->getAttackFlag()) {
		//左攻撃状態へ移行(１撃目)
		this->toAttackFirstLeft();
		return;
	}

	//左向きジャンプ
	if (pointerInputController->getJumpFlag()) {
		//左向きジャンプ状態へ移行
		this->toJumpLeft();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toWalkRight();

		//this->m_pMove->m_accele.x = 0.5f;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalkLeft();

		
		//this->m_pMove->m_accele.x = -0.5f;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerWalkRightState
//
// プレイヤー 右向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerWalkRightState::CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerWalkRightState::~CPlayerWalkRightState(void){}

/**
 * @desc	 開始処理
 */
void CPlayerWalkRightState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerWalkRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//少女にマークパーティクルが出現しているか確認
	if (pGirl->getPlayerAndGirlActionMark()) {
		//出現していたら
		//手を握る　お姫様抱っこ　のキーが押されているかチェック
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//手を繋ぐ右状態へ移行
				this->toGraspRight();
			}
			else
			{
				//手を繋ぐ左状態へ移行
				this->toGraspLeft();
			}
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHoldRight();
		}

	}

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y < 0.0f) {
		//落下状態へ移行する
		this->toFallRight();

		return;
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
		this->toAttackFirstRight();
		return;
	}

	//右向きジャンプ
	if (pointerInputController->getJumpFlag()) {
		//右向きジャンプ状態へ移行
		this->toJumpRight();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向きに歩行する
		this->m_pPlayer->m_pMove->m_accele.x = 1.0f;
		return;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalkLeft();
		return;
	}

	//右向き待機状態へ移行
	this->toIdleRight();
}

/**
 * @desk	状態が変わるときの処理
 */
void CPlayerWalkRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerWalkLeftState
//
// プレイヤー 左向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerWalkLeftState::CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerWalkLeftState::~CPlayerWalkLeftState(void){}

/**
 * @desc	開始処理
 */
void CPlayerWalkLeftState::start(void)
{

}

/**
 * @desc	更新処理
 */
void CPlayerWalkLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//少女にマークパーティクルが出現しているか確認
	if (pGirl->getPlayerAndGirlActionMark()) {
		//出現していたら
		//手を握る　お姫様抱っこ　のキーが押されているかチェック
		if (pointerInputController->getHolodHandsFlag()) {
			if (this->m_pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				//手を繋ぐ右状態へ移行
				this->toGraspRight();
			}
			else
			{
				//手を繋ぐ左状態へ移行
				this->toGraspLeft();
			}
			return;
		}
		if (pointerInputController->getHugFlag()) {
			this->toHoldLeft();
		}
	}

	//プレイヤーが下へ移動していたら
	if (this->m_pPlayer->m_pMove->m_vel.y < 0.0f) {
		//落下状態へ移行する
		this->toFallRight();

		return;
	}


	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//左向き装備状態へ移行
	//	this->toEquipLeft();
	//	return;
	}

	//左攻撃
	if (pointerInputController->getAttackFlag()) {
		//左攻撃状態へ移行(１撃目)
		this->toAttackFirstLeft();
		return;
	}

	//左向きジャンプ
	if (pointerInputController->getJumpFlag()) {
		//左向きジャンプ状態へ移行
		this->toJumpLeft();
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
		//左向きに歩行する
		this->m_pPlayer->m_pMove->m_accele.x = -1.0f;
		return;
	}

	//左向き待機状態へ移行
	this->toIdleLeft();
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerJumpRightState
//
// プレイヤー 右向き ジャンプ 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerJumpRightState::CPlayerJumpRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerJumpRightState::~CPlayerJumpRightState(void) {}

/**
* @desc	開始処理
*/
void CPlayerJumpRightState::start(void)
{
	//ジャンプアクションのスタート関数を開始
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->start();

	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	更新処理
*/
void CPlayerJumpRightState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	if (pointerInputController->getAttackFlag()) {
		//右ジャンプ攻撃状態へ移行する
		this->toJumpAttackRight();
		return;
	}

	//プレイヤーの速度を維持させる
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
void CPlayerJumpRightState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerJumpRightState
//
// プレイヤー 左向き ジャンプ 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerJumpLeftState::CPlayerJumpLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerJumpLeftState::~CPlayerJumpLeftState(void) {}

/**
* @desc	開始処理
*/
void CPlayerJumpLeftState::start(void)
{
	//ジャンプアクションのスタート関数を開始
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->start();

	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	更新処理
*/
void CPlayerJumpLeftState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	if (pointerInputController->getAttackFlag()) {
		//左ジャンプ攻撃状態へ移行する
		this->toJumpAttackLeft();
		return;
	}

	//プレイヤーの速度を維持させる
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
void CPlayerJumpLeftState::onChangeEvent(void)
{
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->restart(this->m_pPlayer);


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerFallRightState
//
// プレイヤー 右向き 落下 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerFallRightState::CPlayerFallRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerFallRightState::~CPlayerFallRightState(void) {}

/**
* @desc	開始処理
*/
void CPlayerFallRightState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	更新処理
*/
void CPlayerFallRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	if (pointerInputController->getAttackFlag()) {
		//右ジャンプ攻撃状態へ移行する
		this->toJumpAttackRight();
		return;
	}

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
void CPlayerFallRightState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;


	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerFallLeftState
//
// プレイヤー 左向き 落下 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerFallLeftState::CPlayerFallLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerFallLeftState::~CPlayerFallLeftState(void) {}

/**
* @desc	開始処理
*/
void CPlayerFallLeftState::start(void)
{
	this->m_velX = this->m_pPlayer->m_pMove->m_vel.x;
}

/**
* @desc	更新処理
*/
void CPlayerFallLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	if (pointerInputController->getAttackFlag()) {
		//左ジャンプ攻撃状態へ移行する
		this->toJumpAttackLeft();
		return;
	}

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
void CPlayerFallLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_vel.x = 0.0f;


	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerAttackRightState
//
// プレイヤー 右向き　攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerAttackRightState::CPlayerAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerAttackRightState::~CPlayerAttackRightState(void){}

/**
 * @desc	開始処理
 */
void CPlayerAttackRightState::start(void)
{
	this->m_pPlayer->setScaleX(-2.0f);

	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

	//連撃フラグをfalseで始める
	this->m_chainAttackFlag = false;

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
void CPlayerAttackRightState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//攻撃ボタンが押されたか
	if (pointerInputController->getAttackFlag())
	{
		//攻撃連鎖フラグをtrue にする
		this->m_chainAttackFlag = true;
	}

	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//攻撃連鎖フラグが false なら
		if (this->m_chainAttackFlag == false) {
			//右向き待機状態へ戻す
			this->toIdleRight();
			return;
		}

		(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

		//終了していたら
		//現在のプレイヤーのアニメーション状態が１撃目なら
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT) {
			//２撃目に移行する。
			this->toAttackSecondRight();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_RIGHT) {
			//３撃目に移行する
			this->toAttackThirdRight();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_RIGHT) {
			//右向き待機状態へ戻す
			this->toIdleRight();
			return;
		}
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerAttackRightState::onChangeEvent(void)
{
	this->m_pPlayer->setScaleX(2.0f);

	//連撃フラグをfalseに戻す
	//startでfalseにしているが念のためここにも記述しておく
	this->m_chainAttackFlag = false;

	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerAttackLeftState
//
// プレイヤー 左向き　攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerAttackLeftState::CPlayerAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerAttackLeftState::~CPlayerAttackLeftState(){}

/**
 * @desc	開始処理
 */
void CPlayerAttackLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

	//連撃フラグをfalseで始める
	this->m_chainAttackFlag = false;

	//ダメージキャラクター生成データを作成
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
															cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_left, this->m_pPlayer->m_pMove->m_pos.y),
															1);
	//ダメージキャラクター生成トリガーを作成
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//作成したトリガーをスケジューラーに登録
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
}

/**
 * @desc	更新処理
 */
void CPlayerAttackLeftState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//攻撃ボタンが押されたか
	if (pointerInputController->getAttackFlag())
	{
		//攻撃連鎖フラグをtrue にする
		this->m_chainAttackFlag = true;
	}

	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//攻撃連鎖フラグが false なら
		if (this->m_chainAttackFlag == false) {
			//左向き向き待機状態へ戻す
			this->toIdleLeft();
			return;
		}

		(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

		//終了していたら
		//現在のプレイヤーのアニメーション状態が１撃目なら
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT) {
			//２撃目に移行する。
			this->toAttackSecondLeftt();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_LEFT) {
			//３撃目に移行する
			this->toAttackThirdLeft();

			return;
		}
		if (this->m_pPlayer->m_animationState == (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_LEFT) {
			//右向き待機状態へ戻す
			this->toIdleLeft();
			return;
		}
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerAttackLeftState::onChangeEvent(void)
{
	//連撃フラグをfalseに戻す
	//startでfalseにしているが念のためここにも記述しておく
	this->m_chainAttackFlag = false;

	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerJumpAttackRightState
//
// プレイヤー 右向き　ジャンプ攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerJumpAttackRightState::CPlayerJumpAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
 * @desc	デストラクタ
 */
CPlayerJumpAttackRightState::~CPlayerJumpAttackRightState(){}

/**
 * @desc	開始処理
 */
void CPlayerJumpAttackRightState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
	
	//プレイヤーのジャンプアクションを停止させる。
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->stop();

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

	this->m_pPlayer->setScaleX(-2.0f);
}

/**
 * @desc	更新処理
 */
void CPlayerJumpAttackRightState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd() && this->m_pPlayer->m_pMove->m_vel.y == 0.0f)
	{
		//右向き待機状態へ戻す
		this->toIdleRight();
		return;
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerJumpAttackRightState::onChangeEvent(void)
{
	this->m_pPlayer->setScaleX(2.0f);

	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerJumpAttackLeftState
//
// プレイヤー 左向き　ジャンプ攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerJumpAttackLeftState::CPlayerJumpAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerJumpAttackLeftState::~CPlayerJumpAttackLeftState() {}

/**
* @desc	開始処理
*/
void CPlayerJumpAttackLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

	//プレイヤーのジャンプアクションを停止させる。
	(*this->m_pPlayer->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP])[0]->stop();

	//プレイヤーのｙ軸移動速度を０に戻す
	this->m_pPlayer->m_pMove->m_vel.y = 0.0f;


	//ダメージキャラクター生成データを作成
	CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pPlayer,
		cocos2d::Point(this->m_pPlayer->m_pMove->m_pos.x + this->m_pPlayer->m_pBody->m_left, this->m_pPlayer->m_pMove->m_pos.y),
		1);
	//ダメージキャラクター生成トリガーを作成
	CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

	//作成したトリガーをスケジューラーに登録
	CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
}

/**
* @desc	更新処理
*/
void CPlayerJumpAttackLeftState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd() && this->m_pPlayer->m_pMove->m_vel.y >= 0.0f)
	{
		//右向き待機状態へ戻す
		this->toIdleLeft();
		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerJumpAttackLeftState::onChangeEvent(void)
{
	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerEquipRightState
//
// プレイヤー 右向き　装備する 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerEquipRightState::CPlayerEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerEquipRightState::~CPlayerEquipRightState(void){}

/**
 * @desc	開始処理
 */
void CPlayerEquipRightState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc	更新処理
 */
void CPlayerEquipRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//装備アニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{

		//装備解除
		if (pointerInputController->getUnEquipFlag())
		{
			//右向き装備解除状態へ移行
			this->toUnEquipRight();
			return;
		}

		//右へ移動（装備状態 歩行）
		if (pointerInputController->getRightMoveFlag())
		{
			//右向き装備状態　歩行状態へ移行
			//	this->toWalkRight();
			return;
		}

		//左へ移動（装備状態 歩行）
		if (pointerInputController->getLeftMoveFlag())
		{
			//左向きに装備状態　歩行へ移行
			//this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
			return;
		}
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerEquipRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerEquipLeftState
//
// プレイヤー 左向き　装備する 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerEquipLeftState::CPlayerEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerEquipLeftState::~CPlayerEquipLeftState(void){}

/**
 * @desc	開始処理
 */
void CPlayerEquipLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc	更新処理
 */
void CPlayerEquipLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//装備アニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{

		//装備解除
		if (pointerInputController->getUnEquipFlag())
		{
			//左向き装備解除状態へ移行
			this->toUnEquipLeft();
			return;
		}

		//右へ移動（装備状態 歩行）
		if (pointerInputController->getRightMoveFlag())
		{
			//右向き装備状態　歩行状態へ移行
		//	this->toWalkRight();
			return;
		}

		//左へ移動（装備状態 歩行）
		if (pointerInputController->getLeftMoveFlag())
		{
			//左向きに装備状態　歩行へ移行
			//this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
			return;
		}
	}
}


/**
 * @desc	状態が変わるときの処理
 */
void CPlayerEquipLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerUnEquipRightState
//
// プレイヤー 右向き　装備解除する 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerUnEquipRightState::CPlayerUnEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc デストラクタ
 */
CPlayerUnEquipRightState::~CPlayerUnEquipRightState(void){}

/**
 * @desc 開始処理
 */
void CPlayerUnEquipRightState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc 更新処理
 */
void CPlayerUnEquipRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//装備アニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//右向き待機状態へ移行
		this->toIdleRight();
	}
}


/**
 * @desc	状態が変わるときの処理
 */
void CPlayerUnEquipRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerUnEquipLeftState
//
// プレイヤー 左向き　装備解除する 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
 * @desc コンストラクタ
 */
CPlayerUnEquipLeftState::CPlayerUnEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc デストラクタ
 */
CPlayerUnEquipLeftState::~CPlayerUnEquipLeftState(void){}

/**
 * @desc 開始処理
 */
void CPlayerUnEquipLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc 更新処理
 */
void CPlayerUnEquipLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//装備アニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//左向き待機状態へ移行
		this->toIdleLeft();
	}
}


/**
 * @desc	状態が変わるときの処理
 */
void CPlayerUnEquipLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}




//==========================================
//
// Class: CPlayerGrapsRightState
//
// プレイヤー 右向き　手を繋ぐ 状態 クラス
//
// 2016/12/26
//						Author Harada 
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerGraspRightState::CPlayerGraspRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerGraspRightState::~CPlayerGraspRightState(void){}

/**
 * @desc	開始処理
 */
void CPlayerGraspRightState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
 * @desc	更新処理
 */
void CPlayerGraspRightState::update(void)
{
	//優先順で処理していく

	//手を繋ぐアニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//右向き待機状態へ移行
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerGraspRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CPlayerGrapsLeftState
//
// プレイヤー 左向き　手を繋ぐ 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
 * @desc	コンストラクタ
 */
CPlayerGraspLeftState::CPlayerGraspLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl){}

/**
 * @desc	デストラクタ
 */
CPlayerGraspLeftState::~CPlayerGraspLeftState(void){}

/**
 * @desc	開始処理
 */
void CPlayerGraspLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

 /**
 * @desc	更新処理
 */
void CPlayerGraspLeftState::update(void)
{
	//優先順で処理していく

	//手を繋ぐアニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//左向き待機状態へ移行
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);
	}
}

/**
 * @desc	状態が変わるときの処理
 */
void CPlayerGraspLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldRightState
//
// プレイヤー 右向き お姫様抱っこ待機 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerHoldRightState::CPlayerHoldRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerHoldRightState::~CPlayerHoldRightState(void) {}

/**
* @desc	開始処理
*/
void CPlayerHoldRightState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc	更新処理
*/
void CPlayerHoldRightState::update(void)
{
	//優先順で処理していく

	//手を繋ぐアニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//右向き待機状態へ移行
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerHoldRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerHoldLeftState
//
// プレイヤー 左向き お姫様抱っこ待機 状態クラス
//
// 2017/ 1/ 5
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerHoldLeftState::CPlayerHoldLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerHoldLeftState::~CPlayerHoldLeftState(void) {}

/**
* @desc	開始処理
*/
void CPlayerHoldLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc	更新処理
*/
void CPlayerHoldLeftState::update(void)
{
	//優先順で処理していく

	//手を繋ぐアニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//左向き待機状態へ移行
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerHoldLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}
//EOF