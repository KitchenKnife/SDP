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
* @param 騎士のアドレス
* @param 少女のアドレス
* @param ターゲットの種類 
*
*/
CEnemyState::CEnemyState(	CEnemyCharacter* const pOwner,
							CPlayerCharacterBoy* const pPlayer,
							CGirlCharacter* const pGirl
	)
	:m_pOwner(pOwner),m_pPlayer(pPlayer),m_pGirl(pGirl)
{

}

/**
* @desc デストラクタ
*/
CEnemyState::~CEnemyState()
{

}

//EOF