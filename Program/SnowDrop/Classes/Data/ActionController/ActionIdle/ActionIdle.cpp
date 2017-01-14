//==========================================
//
// File: ActionIdle.cpp
//
// アクション　待機 　ファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "ActionIdle.h"
#include "Model\Character\Character.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"
#include "Data/Enum/EnumPlayer.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"
#include "Model/Character/CharacterAggregate.h"

//==========================================
//
// Class: ActionIdle
//
// アクション　待機		クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CActionIdle::CActionIdle()
{
	//生成と同時に開始
	this->start();
}

/**
* @desc アクション開始
*/
void CActionIdle::start(void)
{
	//アクション開始
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionIdle::update(CCharacter* pChara)
{
	
}

/**
* @desc アクション終了
*/
void CActionIdle::stop(void)
{
	//アクション終了
	this->m_inAction = false;
}

//==========================================
//
// Class: ActionMove
//
// アクション　移動		クラス
//
// 2017/01/12
//						Author Harada
//==========================================
CActionMove::CActionMove(){}

void CActionMove::start() {

}

void CActionMove::update(CCharacter* pChara) {
	//引数のキャラクターをプレイヤーキャラクターに変換する
	CPlayerCharacterBoy* pPlayer = (CPlayerCharacterBoy*)pChara;

	//プレイヤーの向いている方向によって割り当てる値を変化させる。
	if (pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
		pPlayer->m_pMove->m_accele.x = 2.0f;
	}
	else if (pPlayer->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
		pPlayer->m_pMove->m_accele.x = -2.0f;
	}
}

void CActionMove::stop() {
	CPlayerCharacterBoy* pPlayer = CCharacterAggregate::getInstance()->getPlayer();

	pPlayer->m_pMove->m_accele.x = 0.0f;
}


//==========================================
//
// Class: CActionPlayerAttack
//
// アクション　プレイヤー攻撃		クラス
//
// 2017/01/12
//						Author Harada
//==========================================
CActionPlayerAttack::CActionPlayerAttack() {}

void CActionPlayerAttack::start() {
	this->m_inAction = true;
}

void CActionPlayerAttack::update(CCharacter* pChara) {
	if (this->m_inAction == true) {
		//プレイヤーキャラクターに変換
		CPlayerCharacterBoy* pBoy = (CPlayerCharacterBoy*)pChara;
		
		//ダメージキャラクター生成データを作成
		CDamageLaunchData* pLaunchData;

		//プレイヤーの向きが右向きなら
		if (pBoy->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::RIGHT) {
			pLaunchData = new CDamageLaunchData(pChara,
				cocos2d::Point(pChara->m_pMove->m_pos.x + pChara->m_pBody->m_right, pChara->m_pMove->m_pos.y),
				1);
		}
		else if (pBoy->m_playerDirectionState == (int)PLATYER_DIRECTION_STATE::LEFT) {
			pLaunchData = new CDamageLaunchData(pChara,
				cocos2d::Point(pChara->m_pMove->m_pos.x + pChara->m_pBody->m_left, pChara->m_pMove->m_pos.y),
				1);
		}
		//ダメージキャラクター生成トリガーを作成
		CDamageLaunchTrigger* pLaunchTrigger = new CDamageLaunchTrigger(pLaunchData);

		//作成したトリガーをスケジューラーに登録
		CLaunchScheduler::getInstance()->m_pLauncher->add(pLaunchTrigger);

		this->m_inAction = false;
		
	}
	
}

void CActionPlayerAttack::stop() {

}

//==========================================
//
// Class: CActionPlayerUnderAttack
//
// アクション　プレイヤー 攻撃を受けた	クラス
//
// 2017/01/12
//						Author Harada
//==========================================
void CActionPlayerUnderAttack::update(CCharacter* pChara) {
	if (this->m_inAction == true) {
		//プレイヤーキャラクターに変換
		CPlayerCharacterBoy* pBoy = (CPlayerCharacterBoy*)pChara;

		//プレイヤーの向きが右向きなら
		if (pBoy->m_underAttackDirection == (int)PLAYER_UNDER_ATTACK_DIRECTION::RIGHT) {
			pBoy->m_pMove->m_accele.y = 4.0;

			pBoy->m_pMove->m_accele.x = -4.0;
		}
		else if (pBoy->m_underAttackDirection == (int)PLAYER_UNDER_ATTACK_DIRECTION::LEFT) {
			pBoy->m_pMove->m_accele.y = 4.0;

			pBoy->m_pMove->m_accele.x = 4.0;
		}

		this->m_inAction = false;
	}
	else {
		CPlayerCharacterBoy* pBoy = CCharacterAggregate::getInstance()->getPlayer();

		pBoy->m_pMove->m_accele.y = 0.0f;

		pBoy->m_pMove->m_accele.x = 0.0f;
	}
}

/**
* @desc アクション終了
*/
void CActionPlayerUnderAttack::stop(void) {
	
}