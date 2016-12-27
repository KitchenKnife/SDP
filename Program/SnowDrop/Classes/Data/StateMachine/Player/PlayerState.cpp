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
#include "Model\Character\PlayerCharacter\PlayerCharacter.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"

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
* @desc コンストラクタ
*/
CPlayerState::CPlayerState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:m_pPlayer(pPlayer),m_pGirl(pGirl)
{

}

/**
* @desc デストラクタ
*/
CPlayerState::~CPlayerState(void)
{

}

/**
*	@desc 右向き待機状態へ移行
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
*	@desc 左向き待機状態へ移行
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
*	@desc 右向き歩行状態へ移行
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
*	@desc 左向き歩行状態へ移行
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
*	@desc 右向き　装備する状態へ移行
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
*	@desc 左向き　装備する状態へ移行
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
*	@desc 右向き　装備解除状態へ移行
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
*	@desc 左向き　装備解除状態へ移行
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
*	@desc 右向き手を掴む状態へ移行
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
*	@desc 左向き手を掴む状態へ移行
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


//==========================================
//
// Class: CPlayerIdleRightState
//
// プレイヤー 立ち 状態 クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CPlayerIdleRightState::CPlayerIdleRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer,pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerIdleRightState::~CPlayerIdleRightState(void)
{
	

}

/**
* @desc 開始処理
*/
void CPlayerIdleRightState::start(void)
{

}

/**
* @desc 更新処理
*/
void CPlayerIdleRightState::update(void)
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

// 状態が変わるときの処理
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
* @desc コンストラクタ
*/
CPlayerIdleLeftState::CPlayerIdleLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerIdleLeftState::~CPlayerIdleLeftState(void)
{


}

/**
* @desc 開始処理
*/
void CPlayerIdleLeftState::start(void)
{

}

/**
* @desc 更新処理
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

// 状態が変わるときの処理
void CPlayerIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CPlayerWalkRightState
//
// プレイヤー 左向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CPlayerWalkRightState::CPlayerWalkRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerWalkRightState::~CPlayerWalkRightState(void)
{


}

/**
* @desc 開始処理
*/
void CPlayerWalkRightState::start(void)
{

}

/**
* @desc 更新処理
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

// 状態が変わるときの処理
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
* @desc コンストラクタ
*/
CPlayerWalkLeftState::CPlayerWalkLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerWalkLeftState::~CPlayerWalkLeftState(void)
{


}

/**
* @desc 開始処理
*/
void CPlayerWalkLeftState::start(void)
{

}

/**
* @desc 更新処理
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

// 状態が変わるときの処理
void CPlayerWalkLeftState::onChangeEvent(void)
{
	this->m_pPlayer->m_pMove->m_accele.x = 0.0f;


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
* @desc コンストラクタ
*/
CPlayerEquipRightState::CPlayerEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerEquipRightState::~CPlayerEquipRightState(void)
{


}

/**
* @desc 開始処理
*/
void CPlayerEquipRightState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc 更新処理
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

// 状態が変わるときの処理
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
* @desc コンストラクタ
*/
CPlayerEquipLeftState::CPlayerEquipLeftState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerEquipLeftState::~CPlayerEquipLeftState(void)
{


}

/**
* @desc 開始処理
*/
void CPlayerEquipLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pPlayer->m_pAnimations)[this->m_pPlayer->m_animationState]->reset();
}

/**
* @desc 更新処理
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

// 状態が変わるときの処理
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
* @desc コンストラクタ
*/
CPlayerUnEquipRightState::CPlayerUnEquipRightState(CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerUnEquipRightState::~CPlayerUnEquipRightState(void)
{


}

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

// 状態が変わるときの処理
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
	:CPlayerState::CPlayerState(pPlayer, pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerUnEquipLeftState::~CPlayerUnEquipLeftState(void)
{


}

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

// 状態が変わるときの処理
void CPlayerUnEquipLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}
//EOF