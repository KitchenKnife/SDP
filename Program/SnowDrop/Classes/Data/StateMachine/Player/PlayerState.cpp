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
CPlayerState::CPlayerState(int nextRegisterKey, CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CStateBase::CStateBase(nextRegisterKey),m_pPlayer(pPlayer),m_pGirl(pGirl)
{

}

/**
* @desc デストラクタ
*/
CPlayerState::~CPlayerState(void)
{

}

//==========================================
//
// Class: CPlayerStandState
//
// プレイヤー 立ち 状態 クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CPlayerStandState::CPlayerStandState(int nextRegisterKey,CPlayerCharacterBoy* const pPlayer, CGirlCharacter* const pGirl)
	:CPlayerState::CPlayerState(nextRegisterKey,pPlayer,pGirl)
{


}

/**
* @desc デストラクタ
*/
CPlayerStandState::~CPlayerStandState(void)
{


}

/**
* @desc 開始処理
*/
void CPlayerStandState::start(void)
{

}

/**
* @desc 更新処理
*/
void CPlayerStandState::update(void)
{
	//優先順で処理していく
	
	//右に移動しているか
	if (this->m_pPlayer->m_pMove->m_vel.x > 0)
	{
		this->m_pPlayer->m_state = (int)CPlayerCharacterBoy::PLAYER_STATE::WALK_RIGHT;
		
		//ここで次のキーを指定

		this->m_isNext = true;
		return;
	}

	//左に移動しているか
	if (this->m_pPlayer->m_pMove->m_vel.x < 0)
	{
		this->m_pPlayer->m_state = (int)CPlayerCharacterBoy::PLAYER_STATE::WALK_RIGHT;

		//ここで次のキーを指定

		this->m_isNext = true;
		return;
	}
}

// 状態が変わるときの処理
void CPlayerStandState::onChangeEvent(void)
{
	this->m_nextRegisterKey = this->m_defaultNextRegisterKey;
	this->m_isNext = false;
}
//EOF