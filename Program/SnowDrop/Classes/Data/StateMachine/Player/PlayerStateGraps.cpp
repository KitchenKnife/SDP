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
* @desc	右向き待機状態へ移行
*/
void CPlayerStateGraps::toIdleRight(void)
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
void CPlayerStateGraps::toIdleLeft(void)
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
void CPlayerStateGraps::toWalkRight(void)
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
void CPlayerStateGraps::toWalkLeft(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::WALK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	右向き攻撃状態へ移行
*/
void CPlayerStateGraps::toAttackRight(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	左向き攻撃状態へ移行
*/
void CPlayerStateGraps::toAttackLeft(void) {
	this->m_pPlayer->m_state = (int)PLAYER_STATE::ATTACK_LEFT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_LEFT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	右向き　装備する状態へ移行
*/
void CPlayerStateGraps::toEquipRight(void)
{
	this->m_pPlayer->m_state = (int)PLAYER_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_animationState = (int)PLAYER_ANIMATION_STATE::EQUIP_RIGHT;
	this->m_pPlayer->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pPlayer->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	左向き　装備する状態へ移行
*/
void CPlayerStateGraps::toEquipLeft(void)
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
void CPlayerStateGraps::toUnEquipRight(void)
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
void CPlayerStateGraps::toUnEquipLeft(void)
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
void CPlayerStateGraps::toGraspRight(void)
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
void CPlayerStateGraps::toGraspLeft(void)
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
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

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

	//プレイヤーを取得
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{

		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

		return;
	}

	//右向き攻撃状態へ移行
	if (pointerInputController->getAttackFlag()) {
		//右向き攻撃状態へ移行
		this->toAttackRight();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向き歩行状態へ移行
		this->toWalkRight();
		return;
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
//	プレイヤー 左向き　手を繋ぐ 待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGraspIdleLeftState::CPlayerGraspIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

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

	//プレイヤーを取得
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

		return;
	}

	//左向き攻撃状態へ移行
	if (pointerInputController->getAttackFlag()) {
		//左向き攻撃状態へ移行
		this->toAttackLeft();
		return;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向き歩行状態へ移行
		this->toWalkLeft();
		return;
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
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGraspWalkRightState::~CPlayerGraspWalkRightState(void) {}

/**
* @desc	開始処理
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

	//プレイヤーを取得
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_RIGHT);

		return;
	}

	//右向き攻撃状態へ移行
	if (pointerInputController->getAttackFlag()) {
		//右向き攻撃状態へ移行
		this->toAttackRight();
		return;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		//右向きに歩行する
		this->m_pPlayer->m_pMove->m_accele.x = 0.5f;
		return;
	}

	//右向き待機状態へ移行
	this->toIdleRight();
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
// Class: CPlayerGraspWalkLeftState
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
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

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

	//プレイヤーを取得
	CPlayerCharacterGirl* pGirl = CCharacterAggregate::getInstance()->getGirl();

	//手が離されたら
	if (!pointerInputController->getHolodHandsFlag())
	{
		this->m_pPlayer->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;

		(*this->m_pPlayer->m_pStateMachines)[this->m_pPlayer->m_playerAndGirlState]->setStartState((int)PLAYER_STATE::IDLE_LEFT);

		return;
	}

	//左向き攻撃状態へ移行
	if (pointerInputController->getAttackFlag()) {
		//左向き攻撃状態へ移行
		this->toAttackLeft();
		return;
	}

	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		//左向きに歩行する
		this->m_pPlayer->m_pMove->m_accele.x = -0.5f;
		return;
	}

	//右向き待機状態へ移行
	this->toIdleLeft();
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGraspWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;

	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerGrapsAttackRightState
//
// プレイヤー 右向き　攻撃 状態 クラス
//
// 2016/12/25
//						Author Harada
//==========================================
/**
* @desc	コンストラクタ
*/
CPlayerGrapsAttackRightState::CPlayerGrapsAttackRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGrapsAttackRightState::~CPlayerGrapsAttackRightState(void) {}

/**
* @desc	開始処理
*/
void CPlayerGrapsAttackRightState::start(void)
{
	this->m_pPlayer->setScaleX(-2.0f);

	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

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
void CPlayerGrapsAttackRightState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//右向き待機状態へ戻す
		this->toIdleRight();
		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGrapsAttackRightState::onChangeEvent(void)
{
	this->m_pPlayer->setScaleX(2.0f);


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
CPlayerGrapsAttackLeftState::CPlayerGrapsAttackLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerStateGraps::CPlayerStateGraps(pPlayer, pGirl) {}

/**
* @desc	デストラクタ
*/
CPlayerGrapsAttackLeftState::~CPlayerGrapsAttackLeftState() {}

/**
* @desc	開始処理
*/
void CPlayerGrapsAttackLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();

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
void CPlayerGrapsAttackLeftState::update(void)
{
	//優先順で処理していく
	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();

	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->isEnd())
	{
		//右向き待機状態へ戻す
		this->toIdleLeft();
		return;
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CPlayerGrapsAttackLeftState::onChangeEvent(void)
{
	//次のステートへ移行することが確定しているので元に戻しておく
	this->m_isNext = false;
}

