//==========================================
//
// File: EnemyState.cpp
//
// 敵 状態遷移 ファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "EnemyState.h"


//==========================================
//
// Class: CEnemyState
//
// 敵  状態 基底クラス
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================



/**
* @desc コンストラクタ
*/
CEnemyState::CEnemyState(	int nextRegisterKey,
							CEnemyCharacter* const pOwner,
							CPlayerCharacterBoy* const pPlayer,
							CGirlCharacter* const pGirl)
	:CStateBase::CStateBase(nextRegisterKey),
	m_pOwner(pOwner),
	m_pPlayer(pPlayer),
	m_pGirl(pGirl)
{

}

/**
* @desc デストラクタ
*/
CEnemyState::~CEnemyState()
{

}

//EOF