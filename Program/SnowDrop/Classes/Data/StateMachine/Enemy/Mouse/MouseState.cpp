//==========================================
//
// File: MouseState.cpp
//
// Mouse 状態遷移 ファイル
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "MouseState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Model\Character\EnemyCharacter\MouseKing\MouseKingCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CMouseState
//
// Mouse 状態 基底クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseState::CMouseState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseState::~CMouseState(void)
{

}

/**
* @desc 待機状態へ移行
*/
void CMouseState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 徘徊状態へ移行
*/
void CMouseState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 攻撃状態へ移行
*/
void CMouseState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}



/**
* @desc 攻撃を受けている状態へ移行
*/
void CMouseState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 死亡状態へ移行
*/
void CMouseState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSE_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}




//==========================================
//
// Class: CMouseIdleState
//
// Mouse 待機 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseIdleState::CMouseIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseIdleState::~CMouseIdleState()
{

}

/**
* @desc	開始処理
*/
void CMouseIdleState::start(void)
{
	//オーナーのアクションのstartを呼ぶ
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();
}

/**
* @desc 更新処理
*/
void CMouseIdleState::update(void)
{
	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//マウスキャラクターへアップキャスト
	CMouseCharacter* pOwner = (CMouseCharacter*)this->m_pOwner;

	if (!pOwner->m_pMaster->m_isAlive)
	{
		pOwner->m_isAlive = false;
		this->toDead();
	}


	//攻撃できるか？
	if (pOwner->getAttackOrder())
	{
		//攻撃状態へ移行
		this->toAttack();
		return;
	}

	//攻撃を受けたか？
	if (this->m_pOwner->m_underAttack)
	{
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
		return;
	}



	cocos2d::Vec2 vec2TargetPos = pOwner->m_pMaster->m_pMove->m_pos;
	if (pOwner->m_pMaster->getScaleX() < 0)
	{
		switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
		{
		case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x += 128.0f;
			break;
		case HENCHMAN_POSITION_TYPE::DEFENDER:
			vec2TargetPos.x += 64.0f;
			break;
		default:break;
		}
	}
	else
	{
		switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
		{
		case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x -= 128.0f;
			break;
		case HENCHMAN_POSITION_TYPE::DEFENDER:
			vec2TargetPos.x -= 64.0f;
			break;
		default:break;
		}
	}



	//アイドル状態に戻るか
	if (customMath->length(vec2TargetPos, pOwner->m_pMove->m_pos) >= 3.0f && pOwner->m_pMove->m_vel.y >= 0.0f)
	{
		//さまよい行動に移行
		this->toWandering();
		return;
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CMouseIdleState::onChangeEvent(void)
{
	//オーナーのアクションのstopを呼ぶ
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->stop();

	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseWanderingState
//
// Mouse 徘徊 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseWanderingState::CMouseWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseWanderingState::~CMouseWanderingState()
{

}

/**
* @desc	開始処理
*/
void CMouseWanderingState::start(void)
{
	//オーナーのアクションのstartを呼ぶ
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

}

/**
* @desc 更新処理
*/
void CMouseWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//マウスキャラクターへアップキャスト
	CMouseCharacter* pOwner = (CMouseCharacter*)this->m_pOwner;

	if (!pOwner->m_pMaster->m_isAlive)
	{
		pOwner->m_isAlive = false;
		this->toDead();
	}


	////攻撃できるか？
	//if (pOwner->getAttackOrder())
	//{
	//	//攻撃状態へ移行
	//	this->toAttack();
	//	return;
	//}

	//攻撃を受けたか？
	if (this->m_pOwner->m_underAttack)
	{
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
		return;
	}

	//if (pOwner->m_pMaster)
	//{
	//	cocos2d::Vec2 vec2TargetPos = pOwner->m_pMaster->m_pMove->m_pos;
	//	if (pOwner->m_pMaster->getScaleX() < 0)
	//	{
	//		switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
	//		{
	//		case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x += 128.0f;
	//			break;
	//		case HENCHMAN_POSITION_TYPE::DEFENDER:
	//			vec2TargetPos.x += 64.0f;
	//			break;
	//		default:break;
	//		}
	//		this->m_vec = 1;
	//	}
	//	else
	//	{
	//		switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
	//		{
	//		case HENCHMAN_POSITION_TYPE::FORWARD:	vec2TargetPos.x -= 128.0f;
	//			break;
	//		case HENCHMAN_POSITION_TYPE::DEFENDER:
	//			vec2TargetPos.x -= 64.0f;
	//			break;
	//		default:break;
	//		}
	//		this->m_vec = -1;
	//	}



	//	//アイドル状態に戻るか
	//	if (customMath->length(vec2TargetPos, pOwner->m_pMove->m_pos) < 3.0f)
	//	{
	//		if (pOwner->m_pMaster->getScaleX() < 0)
	//		{
	//			switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
	//			{
	//			case HENCHMAN_POSITION_TYPE::FORWARD:	pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x + 128.0f;
	//				break;
	//			case HENCHMAN_POSITION_TYPE::DEFENDER:
	//				pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x + 64.0f;
	//				break;
	//			default:break;
	//			}
	//		}
	//		else
	//		{
	//			switch ((HENCHMAN_POSITION_TYPE)pOwner->m_positionType)
	//			{
	//			case HENCHMAN_POSITION_TYPE::FORWARD:	pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x - 128.0f;
	//				break;
	//			case HENCHMAN_POSITION_TYPE::DEFENDER:
	//				pOwner->m_pMove->m_pos.x = pOwner->m_pMaster->m_pMove->m_pos.x - 64.0f;
	//				break;
	//			default:break;
	//			}
	//		}



	//		this->toIdle();
	//		return;
	//	}
	//	else
	//	{
	//		//速さを設定
	//		this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

	//		pOwner->setScaleX(this->m_vec * -1.0f);
	//	}
	//}

}

/**
* @desc 状態が変わるときの処理
*/
void CMouseWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseAttackState
//
// Mouse　攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseAttackState::CMouseAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseAttackState::~CMouseAttackState()
{

}

/**
* @desc	開始処理
*/
void CMouseAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//アニメーションをリセット
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();
}

/**
* @desc 更新処理
*/
void CMouseAttackState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		//待機状態へ移行
		this->toIdle();
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CMouseAttackState::onChangeEvent(void)
{
	//マウスキャラクターへアップキャスト
	CMouseCharacter* pOwner = (CMouseCharacter*)this->m_pOwner;
	//攻撃命令フラグを下ろす
	pOwner->setAttackOrder(false);

	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseUnderAttackState
//
// Mouse 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseUnderAttackState::CMouseUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseUnderAttackState::~CMouseUnderAttackState()
{

}

/**
* @desc	開始処理
*/
void CMouseUnderAttackState::start(void)
{
	//ジャンプアクションのスタート関数を開始
	(*this->m_pOwner->m_mapAction[(int)this->m_pOwner->m_actionState])[0]->start();


	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	if (this->m_pOwner->m_pMove->m_pos.x >= pPlayer->m_pMove->m_pos.x)
	{
		this->m_vec = 1;
	}
	else
	{
		this->m_vec = -1;
	}
}

/**
* @desc 更新処理
*/
void CMouseUnderAttackState::update(void)
{

	//死亡したか？
	if (!this->m_pOwner->m_isAlive)
	{
		this->toDead();
		return;
	}

	if (this->m_pOwner->m_pMove->m_vel.y == 0.0f)
	{
		//攻撃受けている状態を下ろす
		this->m_pOwner->m_underAttack = false;

		//待機状態へ
		this->toIdle();
		return;
	}

	//速さを設定
	this->m_pOwner->m_pMove->m_vel.x = 6.0f * this->m_vec;
}

/**
* @desc 状態が変わるときの処理
*/
void CMouseUnderAttackState::onChangeEvent(void)
{
	//速さを０に
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//アクションリセット
	(*this->m_pOwner->m_mapAction[(int)ENEMY_MOUSE_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseDeadState
//
// Mouse 攻撃を受けた 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseDeadState::CMouseDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseState::CMouseState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseDeadState::~CMouseDeadState()
{

}

/**
* @desc	開始処理
*/
void CMouseDeadState::start(void)
{
	//消滅カウンターを設定
	this->m_disappearanceCounter = 300;
}

/**
* @desc 更新処理
*/
void CMouseDeadState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		if (this->m_pOwner->getNumberOfRunningActions() <= 0 &&
			this->m_disappearanceCounter <= 120)
		{

			this->m_pOwner->setOpacity(50);
			this->m_pOwner->runAction(CCBlink::create((float)3.0f, (int)15));
		}

		//時間経過で消滅
		if (this->m_disappearanceCounter <= 0)
		{
			//有効フラグを下げる
			this->m_pOwner->m_activeFlag = false;
		}

		this->m_disappearanceCounter--;
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CMouseDeadState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}


//EOF