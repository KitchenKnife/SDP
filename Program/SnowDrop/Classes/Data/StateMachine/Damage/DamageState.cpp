//==========================================
//
// File: DamageState.cpp
//
// ダメージ 状態遷移 ファイル
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "DamageState.h"


//==========================================
//
// Class: CDamageState
//
// ダメージ  状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================



/**
* @desc コンストラクタ
* @param 所有するキャラクターのアドレス
*
*/
CDamageState::CDamageState(CDamageCharacter* const pOwner)
	:m_pOwner(pOwner)
{

}

/**
* @desc デストラクタ
*/
CDamageState::~CDamageState()
{

}

//EOF