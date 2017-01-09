#pragma once
//==========================================
//
// File: DamageState.h
//
// ダメージ　状態遷移 ヘッダーファイル
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../StateMachine.h"

//==========================================
// 前方宣言
//==========================================
class CDamageCharacter;

//==========================================
//
// Class: CDamageState
//
// ダメージ 状態 基底クラス
//
// 2017/01/09
//						Author Shinya Ueba
//==========================================
class CDamageState : public CStateBase
{
public:

	/**
	* @desc コンストラクタ
	* @param 所有するキャラクター
	*/
	CDamageState(CDamageCharacter* const pOwner);

	/**
	* @desc デストラクタ
	*/
	virtual ~CDamageState(void);

protected:
	//この状態を保有するキャラクター
	CDamageCharacter* m_pOwner = NULL;
};
//EOF