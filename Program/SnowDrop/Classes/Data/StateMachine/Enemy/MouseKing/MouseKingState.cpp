//==========================================
//
// File: MouseKingState.cpp
//
// MouseKing 状態遷移 ファイル
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "MouseKingState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\MouseKing\MouseKingCharacter.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CMouseKingState
//
// MouseKing 状態 基底クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseKingState::CMouseKingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseKingState::~CMouseKingState(void)
{

}

/**
* @desc 待機状態へ移行
*/
void CMouseKingState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 徘徊状態へ移行
*/
void CMouseKingState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 攻撃状態へ移行
*/
void CMouseKingState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}



/**
* @desc 攻撃を受けている状態へ移行
*/
void CMouseKingState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 死亡状態へ移行
*/
void CMouseKingState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MOUSEKING_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 攻撃できる取得
* @return true...できる false...出来ない
*/
bool CMouseKingState::checkEnableAttack(void)
{

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();


	if (this->m_pOwner->m_attackInterval <= 0)
	{
		if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 384.0f ||
			customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 384.0f)
		{
			return true;
		}
	}
	else
	{
		//攻撃間隔を減らす
		this->m_pOwner->m_attackInterval--;
	}

	return false;
}


//==========================================
//
// Class: CMouseKingIdleState
//
// MouseKing 待機 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseKingIdleState::CMouseKingIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseKingIdleState::~CMouseKingIdleState()
{

}

/**
* @desc	開始処理
*/
void CMouseKingIdleState::start(void)
{
	//オーナーのアクションのstartを呼ぶ
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

	//ランダムでアクション時間を設定(30~60)
	this->m_actionInterval = rand() % 30 + 31;
}

/**
* @desc 更新処理
*/
void CMouseKingIdleState::update(void)
{
	//カウンターをインクリメント
	this->m_actionCounter++;

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//攻撃できるか？
	if (this->checkEnableAttack())
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

	//カウンターがインターバル以上なら
	if (this->m_actionCounter >= this->m_actionInterval) {
		//カウンターをリセット
		this->m_actionCounter = 0;

		//さまよい行動に移行
		this->toWandering();
		return;
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CMouseKingIdleState::onChangeEvent(void)
{
	//オーナーのアクションのstopを呼ぶ
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->stop();

	this->m_actionInterval = 45;

	this->m_actionCounter = 0;

	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseKingWanderingState
//
// MouseKing 徘徊 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseKingWanderingState::CMouseKingWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseKingWanderingState::~CMouseKingWanderingState()
{

}

/**
* @desc	開始処理
*/
void CMouseKingWanderingState::start(void)
{
	//オーナーのアクションのstartを呼ぶ
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

	//ランダムで歩く向きを設定
	this->m_vec = (rand() % 3) - 1;
	//ランダムでアクション時間を設定(30~60)
	this->m_actionInterval = rand() % 30 + 31;

	if (this->m_vec == 0)
	{
		//動作を停止
		for (CAction* pAction : (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState]))
		{
			pAction->stop();
		}
		//待機状態に移行
		this->toIdle();
		return;
	}

	//速さを設定
	this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(-1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(1.0);
	}
}

/**
* @desc 更新処理
*/
void CMouseKingWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//攻撃できるか？
	if (this->checkEnableAttack())
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

	//カウンターをインクリメント
	this->m_actionCounter++;
	//カウンターがインターバル以上なら
	if (this->m_actionCounter >= this->m_actionInterval) {
		//カウンターをリセット
		this->m_actionCounter = 0;
		//開始状態に移行
		this->start();
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CMouseKingWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseKingAttackState
//
// MouseKing　攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseKingAttackState::CMouseKingAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseKingAttackState::~CMouseKingAttackState()
{

}

/**
* @desc	開始処理
*/
void CMouseKingAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//アニメーションをリセット
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();

	CMouseKingCharacter* pOwner = (CMouseKingCharacter*)this->m_pOwner;

	this->m_nextAttackOrder = m_nextAttackOrder * -1;
	switch (this->m_nextAttackOrder)
	{
	case 1:
			if (pOwner->m_pHenchmans[0])
			{
				if (pOwner->m_pHenchmans[0]->m_isAlive)
				{
					pOwner->m_pHenchmans[0]->setAttackOrder(true);
					this->m_pOrderChara = pOwner->m_pHenchmans[0];
				}
				else
				{
					//メモ：ここでNULLを入れないと何故か予期しないデータが残る
					pOwner->m_pHenchmans[0] = NULL;
				}
			}
			
			break;

	case -1:
			if (pOwner->m_pHenchmans[1])
			{
				if (pOwner->m_pHenchmans[1]->m_isAlive)
				{
					pOwner->m_pHenchmans[1]->setAttackOrder(true);
					this->m_pOrderChara = pOwner->m_pHenchmans[1];
				}
				else
				{
					//メモ：ここでNULLを入れないと何故か予期しないデータが残る
					pOwner->m_pHenchmans[1] = NULL;
				}
			}
			break;

	default:break;
	}
}

/**
* @desc 更新処理
*/
void CMouseKingAttackState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if (!this->m_pOrderChara || this->m_pOrderChara->getAttackOrder() == false)
	{
			//待機状態へ移行
			this->toIdle();
			return;
	}
	
}

/**
* @desc 状態が変わるときの処理
*/
void CMouseKingAttackState::onChangeEvent(void)
{
	this->m_pOrderChara = NULL;
	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CMouseKingUnderAttackState
//
// MouseKing 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseKingUnderAttackState::CMouseKingUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseKingUnderAttackState::~CMouseKingUnderAttackState()
{

}

/**
* @desc	開始処理
*/
void CMouseKingUnderAttackState::start(void)
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
void CMouseKingUnderAttackState::update(void)
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
void CMouseKingUnderAttackState::onChangeEvent(void)
{
	//速さを０に
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//アクションリセット
	(*this->m_pOwner->m_mapAction[(int)ENEMY_MOUSEKING_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CMouseKingDeadState
//
// MouseKing 攻撃を受けた 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMouseKingDeadState::CMouseKingDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMouseKingState::CMouseKingState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMouseKingDeadState::~CMouseKingDeadState()
{

}

/**
* @desc	開始処理
*/
void CMouseKingDeadState::start(void)
{
	//消滅カウンターを設定
	this->m_disappearanceCounter = 300;
}

/**
* @desc 更新処理
*/
void CMouseKingDeadState::update(void)
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
void CMouseKingDeadState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}


//EOF