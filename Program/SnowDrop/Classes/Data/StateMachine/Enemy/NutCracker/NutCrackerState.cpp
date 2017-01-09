//==========================================
//
// File: NutCrackerState.cpp
//
// NutCracker 状態遷移 ファイル
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "NutCrackerState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\EnemyCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CNutCrackerState
//
// NutCracker 状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CNutCrackerState::CNutCrackerState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CNutCrackerState::~CNutCrackerState(void)
{

}

/**
* @desc 待機状態へ移行
*/
void CNutCrackerState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 徘徊状態へ移行
*/
void CNutCrackerState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 追跡状態へ移行
*/
void CNutCrackerState::toChase(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::CHASE;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;	
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 攻撃状態へ移行
*/
void CNutCrackerState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}



/**
* @desc 攻撃を受けている状態へ移行
*/
void CNutCrackerState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 死亡状態へ移行
*/
void CNutCrackerState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_NUTCRACKER_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 攻撃できる取得
* @return true...できる false...出来ない
*/
bool CNutCrackerState::checkEnableAttack(void)
{

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();


	if (this->m_pOwner->m_attackInterval <= 0)
	{
		if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 128.0f ||
			customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 128.0f)
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
// Class: CNutCrackerIdleState
//
// NutCracker 待機 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CNutCrackerIdleState::CNutCrackerIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CNutCrackerIdleState::~CNutCrackerIdleState()
{

}

/**
* @desc	開始処理
*/
void CNutCrackerIdleState::start(void)
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
void CNutCrackerIdleState::update(void)
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
void CNutCrackerIdleState::onChangeEvent(void)
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
// Class: CNutCrackerWanderingState
//
// NutCracker 徘徊 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CNutCrackerWanderingState::CNutCrackerWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CNutCrackerWanderingState::~CNutCrackerWanderingState()
{

}

/**
* @desc	開始処理
*/
void CNutCrackerWanderingState::start(void)
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
void CNutCrackerWanderingState::update(void)
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


	//敵を見つけたか？
	CCharacter* pTarget = NULL;
	if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 384.0f)
	{
		pTarget = pPlayer;
	}

	if (customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 384.0f)
	{
		pTarget = pGirl;
	}

	if (pTarget)
	{
		//視界に入っているか?
		if (this->m_vec > 0)
		{
			if (pTarget->m_pMove->m_pos.x - this->m_pOwner->m_pMove->m_pos.x >= 0.0f)
			{
				//追いかける状態へ
				this->toChase();
				return;
			}
		}
		else if (this->m_vec < 0)
		{
			if (this->m_pOwner->m_pMove->m_pos.x - pTarget->m_pMove->m_pos.x >= 0.0f)
			{
				//追いかける状態へ
				this->toChase();
				return;
			}
		}
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
void CNutCrackerWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CNutCrackerAttackState
//
// NutCracker　攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CNutCrackerAttackState::CNutCrackerAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CNutCrackerAttackState::~CNutCrackerAttackState()
{

}

/**
* @desc	開始処理
*/
void CNutCrackerAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//アニメーションをリセット
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();
}

/**
* @desc 更新処理
*/
void CNutCrackerAttackState::update(void)
{
	//攻撃を生成するアニメーションフレームの確認
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->getCurrentFrame()==2)
	{
		//ダメージキャラクター生成データを作成
		CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
			cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
			1);
		//ダメージキャラクター生成トリガーを作成
		CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

		//作成したトリガーをスケジューラーに登録
		CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
	}
	else
	{
		//攻撃を受けたか？
		if (this->m_pOwner->m_underAttack)
		{
			//攻撃を受けた状態へ移行
			this->toUnderAttack();
			return;
		}
	}

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
void CNutCrackerAttackState::onChangeEvent(void)
{

	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CNutCrackerUnderAttackState
//
// NutCracker 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CNutCrackerUnderAttackState::CNutCrackerUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CNutCrackerUnderAttackState::~CNutCrackerUnderAttackState()
{

}

/**
* @desc	開始処理
*/
void CNutCrackerUnderAttackState::start(void)
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
void CNutCrackerUnderAttackState::update(void)
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
void CNutCrackerUnderAttackState::onChangeEvent(void)
{
	//速さを０に
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//アクションリセット
	(*this->m_pOwner->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CNutCrackerChaseState
//
// NutCracker 追跡 状態 クラス
//
//						Author Shinya Ueba
// 2017/01/09
//==========================================
/**
* @desc コンストラクタ
*/
CNutCrackerChaseState::CNutCrackerChaseState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CNutCrackerChaseState::~CNutCrackerChaseState()
{

}

/**
* @desc	開始処理
*/
void CNutCrackerChaseState::start(void)
{
	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	//近い方をターゲットにする
	float distanceToPlayer = customMath->lengthBitweenChara(this->m_pOwner, pPlayer);
	float distanceToGirl = customMath->lengthBitweenChara(this->m_pOwner, pGirl);

	if (distanceToPlayer < distanceToGirl)
	{
		this->m_pTarget = pPlayer;
	}
	else
	{
		this->m_pTarget = pGirl;
	}
}

/**
* @desc 更新処理
*/
void CNutCrackerChaseState::update(void)
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

	if (this->m_pTarget->m_pMove->m_pos.x - this->m_pOwner->m_pMove->m_pos.x > 0.0f)
	{
		this->m_vec = 1;
	}
	else
	{
		this->m_vec = -1;
	}

	//速さを設定
	this->m_pOwner->m_pMove->m_vel.set(3.0f * this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(-1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(1.0);
	}

	/*
	//敵がある程度離れたらワンダリング状態に移行する
	float length = customMath->checkTargetRange(this->m_pOwner, this->m_pOwner->m_targetType);
	//もし追跡範囲内なら
	if (length > this->m_pOwner->m_chaseRange) {
		this->toWandering();
	}
	*/
}

/**
* @desc 状態が変わるときの処理
*/
void CNutCrackerChaseState::onChangeEvent(void)
{
	this->m_pTarget = NULL;
	this->m_vec = 0;

	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//待機動作を終了
	this->m_isNext = false;
}
//==========================================
//
// Class: CNutCrackerDeadState
//
// NutCracker 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CNutCrackerDeadState::CNutCrackerDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CNutCrackerState::CNutCrackerState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CNutCrackerDeadState::~CNutCrackerDeadState()
{

}

/**
* @desc	開始処理
*/
void CNutCrackerDeadState::start(void)
{
	//消滅カウンターを設定
	this->m_disappearanceCounter = 300;
}

/**
* @desc 更新処理
*/
void CNutCrackerDeadState::update(void)
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
void CNutCrackerDeadState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}

//EOF