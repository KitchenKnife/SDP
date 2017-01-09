//==========================================
//
// File: SmokeState.cpp
//
// Smoke 状態遷移 ファイル
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "SmokeState.h"
#include "Model\Character\CharacterAggregate.h"
#include "Model\Character\DamageCharacter\DamageCharacter.h"
#include "Data\Enum\EnumDamage.h"

//==========================================
//
// Class: CSmokeState
//
// Smoke 状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CSmokeState::CSmokeState(CDamageCharacter* const pOwner)
	:CDamageState::CDamageState(pOwner)
{

}

/**
* @desc デストラクタ
*/
CSmokeState::~CSmokeState(void)
{

}


/**
* @desc 攻撃状態へ移行
*/
void CSmokeState::toAttack(void)
{
	this->m_pOwner->m_state = (int)DAMAGE_SMOKE_STATE::ATTACK;
	this->m_pOwner->m_animationState = (int)DAMAGE_SMOKE_ANIMATION_STATE::ATTACK;
	this->m_pOwner->m_actionState = (int)DAMAGE_SMOKE_ACTION_STATE::ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}



/**
* @desc 死亡状態へ移行
*/
void CSmokeState::toDead(void)
{
	this->m_pOwner->m_state = (int)DAMAGE_SMOKE_STATE::DEAD;
	this->m_pOwner->m_animationState = (int)DAMAGE_SMOKE_ANIMATION_STATE::DEAD;
	this->m_pOwner->m_actionState = (int)DAMAGE_SMOKE_ACTION_STATE::ATTACK;
	this->m_nextRegisterKey = this->m_pOwner->m_state;
	//待機動作を終了
	this->m_isNext = true;
}



//==========================================
//
// Class: CSmokeAttackState
//
// Smoke　攻撃 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CSmokeAttackState::CSmokeAttackState(CDamageCharacter* const pOwner)
	:CSmokeState::CSmokeState(pOwner)
{

}

/**
* @desc デストラクタ
*/
CSmokeAttackState::~CSmokeAttackState()
{

}

/**
* @desc	開始処理
*/
void CSmokeAttackState::start(void)
{
	//アニメーションをリセット
	(*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->reset();


	CPlayerCharacterGirl*	pGirl = CCharacterAggregate::getInstance()->getGirl();

	if (this->m_pOwner->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x >= 0.0f)
	{
		this->m_vec = -1;
	}
	else
	{
		this->m_vec = 1;
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
void CSmokeAttackState::update(void)
{
	//攻撃を受けたか？
	if (this->m_pOwner->m_underAttack)
	{
		//死亡状態へ移行
		this->toDead();
		return;
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CSmokeAttackState::onChangeEvent(void)
{
	this->m_pOwner->m_pMove->m_vel.set(0.0f, 0.0f);

	//待機動作を終了
	this->m_isNext = false;
}



//==========================================
//
// Class: CSmokeDeadState
//
// Smoke 死亡 状態 クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CSmokeDeadState::CSmokeDeadState(CDamageCharacter* const pOwner)
	:CSmokeState::CSmokeState(pOwner)
{

}

/**
* @desc デストラクタ
*/
CSmokeDeadState::~CSmokeDeadState()
{

}

/**
* @desc	開始処理
*/
void CSmokeDeadState::start(void)
{

}

/**
* @desc 更新処理
*/
void CSmokeDeadState::update(void)
{
	//アニメーションが終了したかどうかのフラグ
	if ((*this->m_pOwner->m_pAnimations)[this->m_pOwner->m_animationState]->isEnd())
	{
		//有効フラグを下げる
		this->m_pOwner->m_activeFlag = false;
	}
}

/**
* @desc 状態が変わるときの処理
*/
void CSmokeDeadState::onChangeEvent(void)
{
	//待機動作を終了
	this->m_isNext = false;
}