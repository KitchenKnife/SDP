//==========================================
//
// File: MaideadState.cpp
//
// Maidead 状態遷移 ファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "MaideadState.h"
#include "Model\Character\EnemyCharacter\EnemyCharacter.h"
#include "Data\Enum\EnumEnemy.h"

//==========================================
//
// Class: CMaideadState
//
// Maidead 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMaideadState::CMaideadState(	CEnemyCharacter* const pOwner,
								CPlayerCharacterBoy* const pPlayer,
								CGirlCharacter* const pGirl)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMaideadState::~CMaideadState(void)
{

}

/**
* @desc 待機状態へ移行
*/
void CMaideadState::toIdle(void)
{
	this->m_pOwner->m_state				=	(int)ENEMY_MAIDEAD_STATE::IDLE;
	this->m_pOwner->m_animationState	=	(int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState		=	(int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey				=	this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 徘徊状態へ移行
*/
void CMaideadState::toWandering(void)
{
	this->m_pOwner->m_state				= (int)ENEMY_MAIDEAD_STATE::WANDERING;
	this->m_pOwner->m_animationState	= (int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState		= (int)ENEMY_MAIDEAD_ACTION_STATE::WANDERING;
	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 追跡状態へ移行
*/
void CMaideadState::toChase(void)
{
	this->m_pOwner->m_state				= (int)ENEMY_MAIDEAD_STATE::IDLE;
	this->m_pOwner->m_animationState	= (int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState		= (int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey				= this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 攻撃を受けている状態へ移行
*/
void CMaideadState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MAIDEAD_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 死亡状態へ移行
*/
void CMaideadState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MAIDEAD_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MAIDEAD_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


//==========================================
//
// Class: CMaideadIdleState
//
// Maidead 待機 状態 クラス
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMaideadIdleState::CMaideadIdleState(	CEnemyCharacter* const pOwner,
										CPlayerCharacterBoy* const pPlayer,
										CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner,pPlayer,pGirl)
{

}

/**
* @desc デストラクタ
*/
CMaideadIdleState::~CMaideadIdleState()
{

}

/**
* @desc	開始処理
*/
void CMaideadIdleState::start(void)
{
	//ランダムでアクション時間を設定(30~60)
	this->m_actionInterval = rand() % 30 + 31;
}

/**
* @desc 更新処理
*/
void CMaideadIdleState::update(void)
{
	// ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
	//this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);

	//カウンターをインクリメント
	this->m_actionCounter++;


	//攻撃を受けたか？
	if (this->m_pOwner->m_underAttack)
	{
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
	}




	//カウンターがインターバル以上なら
	if (this->m_actionCounter >= this->m_actionInterval) {
		//カウンターをリセット
		this->m_actionCounter = 0;
		
		//さまよい行動に移行
		this->toWandering();
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CMaideadIdleState::onChangeEvent(void)
{
	int m_actionInterval = 45;

	this->m_actionCounter = 0;

	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CMaideadWanderingState
//
// Maidead 徘徊 状態 クラス
//
//						Author Osumi
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMaideadWanderingState::CMaideadWanderingState(	CEnemyCharacter* const pOwner,
												CPlayerCharacterBoy* const pPlayer,
												CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMaideadWanderingState::~CMaideadWanderingState()
{

}

/**
* @desc	開始処理
*/
void CMaideadWanderingState::start(void)
{
	//ランダムで歩く向きを設定
	this->m_vec = (rand() % 3) - 1;

	if (this->m_vec == 0)
	{
		//動作を停止
		for(CAction* pAction : (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState]))
		{
			pAction->stop();
		}
		//待機状態に移行
		this->toIdle();
	}

	//速さを設定
	this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec,0.0f);

	//ランダムでアクション時間を設定(30~60)
	this->m_actionInterval = rand() % 30 + 31;

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(-1.0);
	}
	
	
}

/**
* @desc 更新処理
*/
void CMaideadWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	//攻撃を受けたか？
	if (this->m_pOwner->m_underAttack)
	{
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
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

	// ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
	//this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
}

/**
* @desc 状態が変わるときの処理
*/
void CMaideadWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//待機動作を終了
	this->m_isNext = false;
}



//==========================================
//
// Class: CMaideadUnderAttackState
//
// Maidead 攻撃を受けた 状態 クラス
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMaideadUnderAttackState::CMaideadUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMaideadUnderAttackState::~CMaideadUnderAttackState()
{

}

/**
* @desc	開始処理
*/
void CMaideadUnderAttackState::start(void)
{

}

/**
* @desc 更新処理
*/
void CMaideadUnderAttackState::update(void)
{

	//死亡したか？
	if (!this->m_pOwner->m_isAlive)
	{
		this->toDead();
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CMaideadUnderAttackState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CMaideadDeadState
//
// Maidead 攻撃を受けた 状態 クラス
//
// 2016/12/30
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMaideadDeadState::CMaideadDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMaideadState::CMaideadState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMaideadDeadState::~CMaideadDeadState()
{

}

/**
* @desc	開始処理
*/
void CMaideadDeadState::start(void)
{
	//消滅カウンターを設定
	this->m_disappearanceCounter = 300;
}

/**
* @desc 更新処理
*/
void CMaideadDeadState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		if(this->m_pOwner->getNumberOfRunningActions()<=0 && 
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
void CMaideadDeadState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}

//EOF