//==========================================
//
// File: BaronState.cpp
//
// Baron 状態遷移 ファイル
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "BaronState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\EnemyCharacter.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CBaronState
//
// Baron 状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CBaronState::CBaronState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CBaronState::~CBaronState(void)
{

}

/**
* @desc 待機状態へ移行
*/
void CBaronState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 攻撃状態へ移行
*/
void CBaronState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 攻撃を受けている状態へ移行
*/
void CBaronState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 死亡状態へ移行
*/
void CBaronState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_BARON_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 攻撃できる取得
* @return true...できる false...出来ない
*/
bool CBaronState::checkEnableAttack(void)
{

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();


	if (this->m_pOwner->m_attackInterval <= 0)
	{
		if (customMath->lengthBitweenChara(this->m_pOwner, pPlayer) <= 768.0f ||
			customMath->lengthBitweenChara(this->m_pOwner, pGirl) <= 768.0f)
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
// Class: CBaronIdleState
//
// Baron 待機 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CBaronIdleState::CBaronIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CBaronIdleState::~CBaronIdleState()
{

}

/**
* @desc	開始処理
*/
void CBaronIdleState::start(void)
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
void CBaronIdleState::update(void)
{
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
}

/**
* @desc 状態が変わるときの処理
*/
void CBaronIdleState::onChangeEvent(void)
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
// Class: CBaronAttackState
//
// Baron　攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CBaronAttackState::CBaronAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CBaronAttackState::~CBaronAttackState()
{

}

/**
* @desc	開始処理
*/
void CBaronAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 120;

	//アニメーションをリセット
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();
}

/**
* @desc 更新処理
*/
void CBaronAttackState::update(void)
{
	//攻撃を受けたか？
	if (this->m_pOwner->m_underAttack)
	{
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
		return;
	}

	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		//ダメージキャラクター生成データを作成
		CDamageLaunchData* pLaunchData = new CDamageLaunchData(this->m_pOwner,
			cocos2d::Point(this->m_pOwner->m_pMove->m_pos.x + this->m_pOwner->m_pBody->m_right, this->m_pOwner->m_pMove->m_pos.y),
			300, DAMAGE_TYPE::SMOKE);
		//ダメージキャラクター生成トリガーを作成
		CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

		//作成したトリガーをスケジューラーに登録
		CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);

		//待機状態へ移行
		this->toIdle();
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CBaronAttackState::onChangeEvent(void)
{

	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CBaronUnderAttackState
//
// Baron 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CBaronUnderAttackState::CBaronUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CBaronUnderAttackState::~CBaronUnderAttackState()
{

}

/**
* @desc	開始処理
*/
void CBaronUnderAttackState::start(void)
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
void CBaronUnderAttackState::update(void)
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
void CBaronUnderAttackState::onChangeEvent(void)
{
	//速さを０に
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//アクションリセット
	(*this->m_pOwner->m_mapAction[(int)ENEMY_BARON_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CBaronDeadState
//
// Baron 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CBaronDeadState::CBaronDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CBaronState::CBaronState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CBaronDeadState::~CBaronDeadState()
{

}

/**
* @desc	開始処理
*/
void CBaronDeadState::start(void)
{
	//消滅カウンターを設定
	this->m_disappearanceCounter = 300;
}

/**
* @desc 更新処理
*/
void CBaronDeadState::update(void)
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
void CBaronDeadState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}

