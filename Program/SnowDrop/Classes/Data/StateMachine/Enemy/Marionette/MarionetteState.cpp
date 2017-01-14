//==========================================
//
// File: MarionetteState.cpp
//
// Marionette 状態遷移 ファイル
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "MarionetteState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\EnemyCharacter\Marionette\MarionetteCharacter.h"
#include "Model\Character\EnemyCharacter\Mouse\MouseCharacter.h"
#include "Model\Map\Map.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

//==========================================
//
// Class: CMarionetteState
//
// Marionette 状態 基底クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMarionetteState::CMarionetteState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CEnemyState::CEnemyState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMarionetteState::~CMarionetteState(void)
{

}

/**
* @desc 待機状態へ移行
*/
void CMarionetteState::toIdle(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::IDLE;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 徘徊状態へ移行
*/
void CMarionetteState::toWandering(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::WANDERING;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::WANDERING;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}

/**
* @desc 攻撃状態へ移行
*/
void CMarionetteState::toAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}



/**
* @desc 攻撃を受けている状態へ移行
*/
void CMarionetteState::toUnderAttack(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::UNDER_ATTACK;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::IDLE;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::UNDER_ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 死亡状態へ移行
*/
void CMarionetteState::toDead(void)
{
	this->m_pOwner->m_state = (int)ENEMY_MARIONETTE_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::DAED;
	this->m_pOwner->m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}


/**
* @desc 攻撃できる取得
* @return true...できる false...出来ない
*/
bool CMarionetteState::checkEnableAttack(void)
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
// Class: CMarionetteIdleState
//
// Marionette 待機 状態 クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMarionetteIdleState::CMarionetteIdleState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMarionetteIdleState::~CMarionetteIdleState()
{

}

/**
* @desc	開始処理
*/
void CMarionetteIdleState::start(void)
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
void CMarionetteIdleState::update(void)
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
void CMarionetteIdleState::onChangeEvent(void)
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
// Class: CMarionetteWanderingState
//
// Marionette 徘徊 状態 クラス
//
// 2017/01/12
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMarionetteWanderingState::CMarionetteWanderingState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{
	this->m_targetPositions[CMarionetteCharacter::IDLE_POSITION::RIGHT] = cocos2d::Point(WINDOW_RIGHT - this->m_pOwner->m_pBody->m_right,0);
	this->m_targetPositions[CMarionetteCharacter::IDLE_POSITION::CENTER] = cocos2d::Point(WINDOW_RIGHT*0.5f, 0);
	this->m_targetPositions[CMarionetteCharacter::IDLE_POSITION::LEFT] = cocos2d::Point(0, 0);
}

/**
* @desc デストラクタ
*/
CMarionetteWanderingState::~CMarionetteWanderingState()
{

}

/**
* @desc	開始処理
*/
void CMarionetteWanderingState::start(void)
{
	//オーナーのアクションのstartを呼ぶ
	CAction* pAction = (*this->m_pOwner->m_mapAction[this->m_pOwner->m_actionState])[0];
	pAction->start();

	//アップキャスト
	CMarionetteCharacter* pMarionette = (CMarionetteCharacter*)this->m_pOwner;

	pMarionette->m_numIdlePosition = rand() % (int)CMarionetteCharacter::IDLE_POSITION::MAX_IDLE_POSITION;

	cocos2d::Vec2 positionLayer = CCharacterAggregate::getInstance()->getLayer()->getPosition();
	if ( (this->m_targetPositions[pMarionette->m_numIdlePosition].x - positionLayer.x) - this->m_pOwner->m_pMove->m_pos.x >= 0.0f)
	{
		this->m_vec = 1;
	}
	else
	{
		this->m_vec = -1;
	}

	//速さを設定
	this->m_pOwner->m_pMove->m_vel.set(this->m_pOwner->m_status.getSpeed()*this->m_vec, 0.0f);

	if (this->m_pOwner->m_pMove->m_vel.x > 0)
	{
		this->m_pOwner->setScaleX(1.0);
	}
	else
	{
		this->m_pOwner->setScaleX(-1.0);
	}


	//アニメーションをリセット
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();


}

/**
* @desc 更新処理
*/
void CMarionetteWanderingState::update(void)
{
	if (this->isNext())
	{
		return;
	}

	CPlayerCharacterBoy*	pPlayer = CCharacterAggregate::getInstance()->getPlayer();
	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	
	//攻撃を受けたか？
	if (this->m_pOwner->m_underAttack)
	{
		//攻撃を受けた状態へ移行
		this->toUnderAttack();
		return;
	}

	//アップキャスト
	CMarionetteCharacter* pMarionette = (CMarionetteCharacter*)this->m_pOwner;

	cocos2d::Vec2 positionLayer = CCharacterAggregate::getInstance()->getLayer()->getPosition();
	if (abs( (this->m_targetPositions[pMarionette->m_numIdlePosition].x - positionLayer.x ) - this->m_pOwner->m_pMove->m_pos.x) < this->m_pOwner->m_status.getSpeed() + 256)
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
}

/**
* @desc 状態が変わるときの処理
*/
void CMarionetteWanderingState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CMarionetteAttackState
//
// Marionette　攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMarionetteAttackState::CMarionetteAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl
)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMarionetteAttackState::~CMarionetteAttackState()
{

}

/**
* @desc	開始処理
*/
void CMarionetteAttackState::start(void)
{
	this->m_pOwner->m_attackInterval = 60;

	//アニメーションをリセット
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();

	
}

/**
* @desc 更新処理
*/
void CMarionetteAttackState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		cocos2d::Point fallKnifeLaunchPoints[4];

		//アップキャスト
		CMarionetteCharacter* pMarionette = (CMarionetteCharacter*)this->m_pOwner;

		cocos2d::Vec2 positionLayer = CCharacterAggregate::getInstance()->getLayer()->getPosition();
		switch(pMarionette->m_numIdlePosition)
		{
		case CMarionetteCharacter::IDLE_POSITION::RIGHT:
															fallKnifeLaunchPoints[0] = cocos2d::Point( -positionLayer.x + 224.0f,952.0f);
															fallKnifeLaunchPoints[1] = cocos2d::Point(-positionLayer.x + 704.0f, 952.0f);
															fallKnifeLaunchPoints[2] = cocos2d::Point(-positionLayer.x + 1184.0f, 952.0f);
															fallKnifeLaunchPoints[3] = cocos2d::Point(-positionLayer.x + 1664.0f, 952.0f);
															break;
		case CMarionetteCharacter::IDLE_POSITION::CENTER:
															fallKnifeLaunchPoints[0] = cocos2d::Point(-positionLayer.x + 224.0f, 952.0f);
															fallKnifeLaunchPoints[1] = cocos2d::Point(-positionLayer.x + 704.0f, 952.0f);
															fallKnifeLaunchPoints[2] = cocos2d::Point(-positionLayer.x + 1184.0f, 952.0f);
															fallKnifeLaunchPoints[3] = cocos2d::Point(-positionLayer.x + 1664.0f, 952.0f);

															break;
		case CMarionetteCharacter::IDLE_POSITION::LEFT:	
															fallKnifeLaunchPoints[0] = cocos2d::Point(-positionLayer.x + 224.0f, 952.0f);
															fallKnifeLaunchPoints[1] = cocos2d::Point(-positionLayer.x + 704.0f, 952.0f);
															fallKnifeLaunchPoints[2] = cocos2d::Point(-positionLayer.x + 1184.0f, 952.0f);
															fallKnifeLaunchPoints[3] = cocos2d::Point(-positionLayer.x + 1664.0f, 952.0f);

															break;
		default:
			break;
		}

		CDamageLaunchData* pLaunchData = NULL;
		CDamageLaunchTrigger* pLaunchTrigger = NULL;
		for (int index = 0; index < CMarionetteCharacter::IDLE_POSITION::MAX_IDLE_POSITION; index++)
		{
			//ダメージキャラクター生成データを作成
			pLaunchData = new CDamageLaunchData(this->m_pOwner,
				fallKnifeLaunchPoints[index],
				500, DAMAGE_TYPE::FALL_KNIFE);
			//ダメージキャラクター生成トリガーを作成
			pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

			//作成したトリガーをスケジューラーに登録
			CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);
		}

		//待機状態へ移行
		this->toIdle();
		return;
	}

}

/**
* @desc 状態が変わるときの処理
*/
void CMarionetteAttackState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}


//==========================================
//
// Class: CMarionetteUnderAttackState
//
// Marionette 攻撃を受けた 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMarionetteUnderAttackState::CMarionetteUnderAttackState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMarionetteUnderAttackState::~CMarionetteUnderAttackState()
{

}

/**
* @desc	開始処理
*/
void CMarionetteUnderAttackState::start(void)
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
void CMarionetteUnderAttackState::update(void)
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
void CMarionetteUnderAttackState::onChangeEvent(void)
{
	//速さを０に
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//アクションリセット
	(*this->m_pOwner->m_mapAction[(int)ENEMY_MARIONETTE_ACTION_STATE::UNDER_ATTACK])[0]->restart(this->m_pOwner);

	//待機動作を終了
	this->m_isNext = false;
}

//==========================================
//
// Class: CMarionetteDeadState
//
// Marionette 攻撃を受けた 状態 クラス
//
// 2017/01/11
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CMarionetteDeadState::CMarionetteDeadState(CEnemyCharacter* const pOwner,
	CPlayerCharacterBoy* const pPlayer,
	CGirlCharacter* const pGirl)
	:CMarionetteState::CMarionetteState(pOwner, pPlayer, pGirl)
{

}

/**
* @desc デストラクタ
*/
CMarionetteDeadState::~CMarionetteDeadState()
{

}

/**
* @desc	開始処理
*/
void CMarionetteDeadState::start(void)
{
	//消滅カウンターを設定
	this->m_disappearanceCounter = 300;
}

/**
* @desc 更新処理
*/
void CMarionetteDeadState::update(void)
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
void CMarionetteDeadState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}


//EOF