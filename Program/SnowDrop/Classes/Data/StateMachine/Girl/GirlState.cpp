//==========================================
//
// File: GirlState.cpp
//
// Girl状態遷移 ファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "GirlState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\GirlCharacter\GirlCharacter.h"
#include "Data\Enum\EnumGirl.h"
#include "Data\Enum\EnumPlayer.h"
#include "Lib\Input\InputManager.h"
#include "Lib\Math\CustomMath.h"


//==========================================
//
// Class: CGirlState
//
// プレイヤー 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CGirlState::CGirlState(CPlayerCharacterGirl* pOwner)
:m_pGirl(pOwner){}

/**
* @desc	デストラクタ
*/
CGirlState::~CGirlState(void) {}

/**
* @desc	右向き待機状態へ移行
*/
void CGirlState::toIdleRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::IDLE_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	左向き待機状態へ移行
*/
void CGirlState::toIdleLeft(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::IDLE_LEFT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	右向き歩行状態へ移行
*/
void CGirlState::toWalkRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::WALK_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc	左向き歩行状態へ移行
*/
void CGirlState::toWalkLeft(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::WALK_LEFT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_LEFT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}



/*
* @desc	右向き手を掴む状態へ移行
*/
void CGirlState::toGraspRight(void)
{
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_RIGHT;
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::GRASP_RIGHT;
	this->m_pGirl->m_actionState = 0;
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
* @desc	左向き手を掴む状態へ移行
*/
void CGirlState::toGraspLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::GRASP_LEFT;
	//現在のプレイヤーのアクション状態
	this->m_pGirl->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
*	@desc	右向き手を掴みながら待機状態へ移行
*/
void CGirlState::toGraspIdleRight(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_IDLE_RIGHT;
	//現在のプレイヤーのアニメーション状態
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_RIGHT;
	//現在のプレイヤーのアクション状態
	this->m_pGirl->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/*
*	@desc	左向き手を掴みながら待機状態へ移行
*/
void CGirlState::toGraspIdleLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_IDLE_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::IDLE_LEFT;
	//現在のプレイヤーのアクション状態
	this->m_pGirl->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/*
*	@desc	右向き手を掴みながら歩く状態へ移行
*/
void CGirlState::toGraspWalkRight(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_WALK_RIGHT;
	//現在のプレイヤーのアニメーション状態
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_RIGHT;
	//現在のプレイヤーのアクション状態
	this->m_pGirl->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;

}

/*
*	@desc	左向き手を掴みながら歩く状態へ移行
*/
void CGirlState::toGraspWalkLeft(void)
{
	//次の総合的なプレイヤーの状態
	this->m_pGirl->m_state = (int)GIRL_STATE::GRASP_WALK_LEFT;
	//現在のプレイヤーのアニメーション状態
	this->m_pGirl->m_animationState = (int)GIRL_ANIMATION_STATE::WALK_LEFT;
	//現在のプレイヤーのアクション状態
	this->m_pGirl->m_actionState = 0;
	//次の総合的なプレイヤーの状態を次に行くステートとして指定
	this->m_nextRegisterKey = this->m_pGirl->m_state;
	//待機動作を終了
	this->m_isNext = true;

}

//==========================================
//
// Class: CGirlIdleRightState
//
// ガール 右向き 待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CGirlIdleRightState::CGirlIdleRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	デストラクタ
*/
CGirlIdleRightState::~CGirlIdleRightState(void) {}

/**
* @desc	開始処理
*/
void CGirlIdleRightState::start(void)
{

}

/**
* @desc	更新処理
*/
void CGirlIdleRightState::update(void)
{
	//優先順で処理していく

	//プレイヤーを取得
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	

	if (this->m_pGirl->getHoldHandsFlag())
	{
		if (pPlayer->m_pMove->m_pos.x <= this->m_pGirl->m_pMove->m_pos.x)
		{
			this->toGraspLeft();
		}
		else
		{
			this->toGraspRight();
		}
	}	
}

/**
* @desc	状態が変わるときの処理
*/
void CGirlIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CGirlIdleLeftState
//
// ガール 左向き　待機 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CGirlIdleLeftState::CGirlIdleLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	デストラクタ
*/
CGirlIdleLeftState::~CGirlIdleLeftState(void) {}

/**
* @desc	開始処理
*/
void CGirlIdleLeftState::start(void)
{

}

/**
* @desc	更新処理
*/
void CGirlIdleLeftState::update(void)
{
	//優先順で処理していく

	//プレイヤーを取得
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	if (this->m_pGirl->getHoldHandsFlag())
	{
		if (pPlayer->m_pMove->m_pos.x <= this->m_pGirl->m_pMove->m_pos.x)
		{
			this->toGraspLeft();
		}
		else
		{
			this->toGraspRight();
		}
	}
}

/**
* @desc	状態が変わるときの処理
*/
void CGirlIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGrapsRightState
//
// ガール 右向き　手を繋ぐ 状態 クラス
//
// 2016/12/26
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CGirlGraspRightState::CGirlGraspRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner)
{


}

/**
* @desc デストラクタ
*/
CGirlGraspRightState::~CGirlGraspRightState(void)
{


}

/**
* @desc 開始処理
*/
void CGirlGraspRightState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->reset();
}

/**
* @desc 更新処理
*/
void CGirlGraspRightState::update(void)
{
	//優先順で処理していく

	//装備アニメーションが終わったら
	if ((*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->isEnd())
	{
		//右向き待機状態へ移行
		this->toGraspIdleRight();
	}
}

// 状態が変わるときの処理
void CGirlGraspRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGrapsLeftState
//
// ガール 左向き　手を繋ぐ 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CGirlGraspLeftState::CGirlGraspLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner)
{


}

/**
* @desc デストラクタ
*/
CGirlGraspLeftState::~CGirlGraspLeftState(void)
{


}

/**
* @desc 開始処理
*/
void CGirlGraspLeftState::start(void)
{
	//現在のアニメーションをリセット
	(*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->reset();
}

/**
* @desc 更新処理
*/
void CGirlGraspLeftState::update(void)
{
	//優先順で処理していく

	//装備アニメーションが終わったら
	if ((*this->m_pGirl->m_pAnimations)[this->m_pGirl->m_animationState]->isEnd())
	{
		//左向き待機状態へ移行
		this->toGraspIdleLeft();
	}
}

// 状態が変わるときの処理
void CGirlGraspLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlGraspIdleRightState
//
// ガール 右向き　手を繋ぐ 待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CGirlGraspIdleRightState::CGirlGraspIdleRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	デストラクタ
*/
CGirlGraspIdleRightState::~CGirlGraspIdleRightState(void) {}

/**
* @desc	開始処理
*/
void CGirlGraspIdleRightState::start(void)
{

}

/**
* @desc	更新処理
*/
void CGirlGraspIdleRightState::update(void)
{
	//優先順で処理していく

	//手が離されたら
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//右向き待機状態へ移行
		this->toIdleRight();
		return;
	}


	//プレイヤーを取得
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_RIGHT)
	{
		this->toGraspWalkRight();
	}
	else if(pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_LEFT)
	{
		this->toGraspWalkLeft();
	}

}

/**
* @desc	状態が変わるときの処理
*/
void CGirlGraspIdleRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}

//==========================================
//
// Class: CGirlGraspIdleLeftState
//
//　ガール 左向き　手を繋ぐ 待機 状態 クラス
//
// 2016/12/28
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CGirlGraspIdleLeftState::CGirlGraspIdleLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	デストラクタ
*/
CGirlGraspIdleLeftState::~CGirlGraspIdleLeftState(void) {}

/**
* @desc	開始処理
*/
void CGirlGraspIdleLeftState::start(void)
{

}

/**
* @desc	更新処理
*/
void CGirlGraspIdleLeftState::update(void)
{
	//優先順で処理していく

	//手が離されたら
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//左向き待機状態へ移行
		this->toIdleLeft();
		return;
	}

	//プレイヤーを取得
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_RIGHT)
	{
		this->toGraspWalkRight();
	}
	else if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_WALK_LEFT)
	{
		this->toGraspWalkLeft();
	}

}

/**
* @desc	状態が変わるときの処理
*/
void CGirlGraspIdleLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//==========================================
//
// Class: CGirlGraspWalkRightState
//
// ガール 右向き 手を繋ぐ　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CGirlGraspWalkRightState::CGirlGraspWalkRightState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	デストラクタ
*/
CGirlGraspWalkRightState::~CGirlGraspWalkRightState(void) {}

/**
* @desc	開始処理
*/
void CGirlGraspWalkRightState::start(void)
{

}


/**
* @desc	更新処理
*/
void CGirlGraspWalkRightState::update(void)
{
	//優先順で処理していく
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	//手が離されたら
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//右向き待機状態へ移行
		this->toIdleRight();
		return;
	}

	if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_IDLE_RIGHT)
	{
		this->toGraspIdleRight();
		return;
	}

	this->m_pGirl->m_pMove->m_pos.set(pPlayer->m_pMove->m_pos.x - 35.0f, pPlayer->m_pMove->m_pos.y);
}

/**
* @desk	状態が変わるときの処理
*/
void CGirlGraspWalkRightState::onChangeEvent(void)
{
	this->m_isNext = false;
}



//==========================================
//
// Class: CGirlGraspWalkLeftState
//
// プレイヤー 左向き　歩行 状態 クラス
//
// 2016/12/25
//						Author Shinya Ueba
//==========================================
/**
* @desc	コンストラクタ
*/
CGirlGraspWalkLeftState::CGirlGraspWalkLeftState(CPlayerCharacterGirl* const pOwner)
	:CGirlState::CGirlState(pOwner) {}

/**
* @desc	デストラクタ
*/
CGirlGraspWalkLeftState::~CGirlGraspWalkLeftState(void) {}

/**
* @desc	開始処理
*/
void CGirlGraspWalkLeftState::start(void)
{

}

/**
* @desc	更新処理
*/
void CGirlGraspWalkLeftState::update(void)
{
	//優先順で処理していく
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	//手が離されたら
	if (!this->m_pGirl->getHoldHandsFlag())
	{
		//右向き待機状態へ移行
		this->toIdleLeft();
		return;
	}

	if (pPlayer->m_state == (int)PLAYER_STATE::GRASP_IDLE_LEFT)
	{
		this->toGraspIdleLeft();
		return;
	}

	this->m_pGirl->m_pMove->m_pos.set(pPlayer->m_pMove->m_pos.x + 35.0f, pPlayer->m_pMove->m_pos.y);
}

/**
* @desc	状態が変わるときの処理
*/
void CGirlGraspWalkLeftState::onChangeEvent(void)
{
	this->m_isNext = false;
}


//EOF