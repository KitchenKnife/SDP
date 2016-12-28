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
 * @desc	右向き攻撃状態（１撃目）へ移行
 */
void CPlayerState::toAttackFirstRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き攻撃状態（２撃目）へ移行
 */
void CPlayerState::toAttackSecondRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	右向き攻撃状態（３撃目）へ移行
 */
void CPlayerState::toAttackThirdRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き攻撃状態（１撃目）へ移行
 */
void CPlayerState::toAttackFirstLeft(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き攻撃状態（２撃目）へ移行
 */
void CPlayerState::toAttackSecondLeftt(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
 * @desc	左向き攻撃状態（３撃目）へ移行
 */
void CPlayerState::toAttackThirdLeft(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::THURD_ATTACK_LEFT;
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
	this->m_pPlayer->m_state = (int)PLAYER_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::EQUIP_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/*
 * @desc	右向き　装備解除状態へ移行
 */
void CPlayerState::toUnEquipRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::UN_EQUIP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
 * @desc	左向き　装備解除状態へ移行
 */
void CPlayerState::toUnEquipLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::UN_EQUIP_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::UN_EQUIP_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/*
 * @desc	右向き手を掴む状態へ移行
 */
void CPlayerState::toGraspRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRASP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
 * @desc	左向き手を掴む状態へ移行
 */
void CPlayerState::toGraspLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRASP_LEFT;
	//現在のプレイヤーのアクション状態
	this->m_pPlayer->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
*	@desc	右向き手を掴みながら待機状態へ移行
*/
void CPlayerState::toGraspIdleRight(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_IDLE_RIGHT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;
	//現在のプレイヤーのアクション状態
	this->m_pPlayer->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
*	@desc	左向き手を掴みながら待機状態へ移行
*/
void CPlayerState::toGraspIdleLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_IDLE_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_LEFT;
	//現在のプレイヤーのアクション状態
	this->m_pPlayer->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/*
*	@desc	右向き手を掴みながら歩く状態へ移行
*/
void CPlayerState::toGraspWalkRight(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_WALK_RIGHT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_RIGHT;
	//現在のプレイヤーのアクション状態
	this->m_pPlayer->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;

}

/*
*	@desc	左向き手を掴みながら歩く状態へ移行
*/
void CPlayerState::toGraspWalkLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pPlayer->m_state = (int)PLAYER_STATE::GRASP_WALK_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
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
	//プレイヤーを取得
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	//ガールを取得
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();


	float distanceToGirl = customMath->lengthBitweenChara(pPlayer, pGirl);
	if (distanceToGirl <= 100.0f)
	{

		if (!pPlayer->getGrapsMark())
		{
			cocos2d::CCParticleSystemQuad* pGrapsMark = cocos2d::CCParticleSystemQuad::create(PARTICLE_GRAPS_MARK);
			pGrapsMark->resetSystem();
			pPlayer->setGrapsMark(pGrapsMark);
			pPlayer->getParent()->addChild(pGrapsMark);
			if (pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
			{
				pGrapsMark->setPosition(pPlayer->m_pMove->m_pos.x + distanceToGirl*0.5f, pPlayer->m_pMove->m_pos.y - 10.0f);
			}
			else
			{
				pGrapsMark->setPosition(pPlayer->m_pMove->m_pos.x - distanceToGirl*0.5f, pPlayer->m_pMove->m_pos.y - 10.0f);
			}
		}

		if (pointerInputController->getHolodHandsFlag())
		{

			//手を繋ぐ
			pGirl->setHoldHandsFlag(true);


			if (pPlayer->m_pMove->m_pos.x <= pGirl->m_pMove->m_pos.x)
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

	}



	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//右向き装備状態へ移行
	//	this->toEquipRight();
		return;
	}

	//右攻撃
	if (pointerInputController->getAttackFlag()) {
		//右攻撃状態へ移行(１撃目)
		this->toAttackFirstRight();
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

	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//左向き装備状態へ移行
		this->toEquipLeft();
		return;
	}
	
	//左攻撃
	if (pointerInputController->getAttackFlag()) {
		//左攻撃状態へ移行(１撃目)
		this->toAttackFirstLeft();
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

	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//右向き装備状態へ移行
		this->toEquipRight();
		return;
	}
	
	//右攻撃
	if (pointerInputController->getAttackFlag()) {
		//右攻撃状態へ移行(１撃目)
		this->toAttackFirstRight();
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

	//武器を装備
	if (pointerInputController->getEquipFlag())
	{
		//左向き装備状態へ移行
		this->toEquipLeft();
		return;
	}

	//左攻撃
	if (pointerInputController->getAttackFlag()) {
		//左攻撃状態へ移行(１撃目)
		this->toAttackFirstLeft();
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
		this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
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
// Class: CPlayerAttackRightState
//
// プレイヤー 右向き　攻撃 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
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
															30);
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
															30);
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
//						Author Shinya Ueba
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

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//装備アニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//右向き待機状態へ移行
		this->toGraspIdleRight();
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
//						Author Shinya Ueba
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

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//装備アニメーションが終わったら
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//左向き待機状態へ移行
		this->toGraspIdleLeft();
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
// Class: CPlayerGraspIdleRightState
//
// プレイヤー 右向き　手を繋ぐ 待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspIdleRightState::CPlayerGraspIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspIdleRightState::~CPlayerGraspIdleRightState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGraspIdleRightState::start(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerGraspIdleRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		//右向き待機状態へ移行
		this->toIdleRight();
		return;
	}


	//左攻撃
	if (pointerInputController->getAttackFlag()) {
		//左攻撃状態へ移行(１撃目)
	//	this->toAttackFirstLeft();
		return;
	}


	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toGraspWalkRight();
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toGraspWalkLeft();
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGraspIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CPlayerGraspIdleLeftState
//
// プレイヤー 左向き　手を繋ぐ 待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspIdleLeftState::CPlayerGraspIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspIdleLeftState::~CPlayerGraspIdleLeftState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGraspIdleLeftState::start(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerGraspIdleLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		//右向き待機状態へ移行
		this->toIdleLeft();
		return;
	}


	//左攻撃
	if (pointerInputController->getAttackFlag()) {
		//左攻撃状態へ移行(１撃目)
	//	this->toAttackFirstLeft();
		return;
	}


	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toGraspWalkRight();

		//this->m_pMove->m_accele.x = 0.5f;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toGraspWalkLeft();


		//this->m_pMove->m_accele.x = -0.5f;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGraspIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGraspWalkRightState
//
// プレイヤー 右向き 手を繋ぐ　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspWalkRightState::CPlayerGraspWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspWalkRightState::~CPlayerGraspWalkRightState(void) {}

/**
* @desc	 開始処理
*/
void CPlayerGraspWalkRightState::start(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerGraspWalkRightState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		//右向き待機状態へ移行
		this->toIdleRight();
		return;
	}

	//右攻撃
	if (pointerInputController->getAttackFlag()) {
		//右  手を繋ぐ攻撃状態へ移行
		//this->toAttackFirstRight();
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
		this->toGraspWalkLeft();
		return;
	}

	//右向き待機状態へ移行
	this->toGraspIdleRight();
}

/**
* @desk	状態が変わるときの処理
*/
void CPlayerGraspWalkRightState::onChangeEvent(void)
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
CPlayerGraspWalkLeftState::CPlayerGraspWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspWalkLeftState::~CPlayerGraspWalkLeftState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGraspWalkLeftState::start(void)
{

}

/**
* @desc	更新処理
*/
void CPlayerGraspWalkLeftState::update(void)
{
	//優先順で処理していく

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		//左向き待機状態へ移行
		this->toIdleLeft();
		return;
	}

	//左攻撃
	if (pointerInputController->getAttackFlag()) {
		//左攻撃状態へ移行(１撃目)
		//this->toAttackFirstLeft();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toGraspWalkRight();
		return;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向きに歩行する
		this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
		return;
	}

	//左向き待機状態へ移行
	this->toGraspIdleLeft();
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGraspWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;


	this->m_isNext = false;
}



//EOF