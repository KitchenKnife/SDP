#pragma once
//==========================================
//
// File: EnemyState.h
//
// 敵　状態遷移 ヘッダーファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================


//==========================================
// ヘッダインクルード
//==========================================
#include "../StateMachine.h"

//==========================================
// 前方宣言
//==========================================
class CEnemyCharacter;
class CPlayerCharacterBoy;
class CGirlCharacter;

//==========================================
//
// Class: CEnemyState
//
// 敵 状態 基底クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
class CEnemyState : public CStateBase
{
public:

	/**
	* @desc コンストラクタ
	* @param 騎士のアドレス
	* @param 少女のアドレス
	* @param ターゲットの種類 
	*/
	CEnemyState(CEnemyCharacter* const pOwner,
				CPlayerCharacterBoy* const pPlayer,
				CGirlCharacter* const pGirl
		);

	/**
	* @desc デストラクタ
	*/
	virtual ~CEnemyState(void);
	
protected:
	//この状態を保有するキャラクター
	CEnemyCharacter* m_pOwner = NULL;

	//参照するプレイヤーキャラクターr
	CPlayerCharacterBoy* m_pPlayer = NULL;
	//参照するガールキャラクター
	CGirlCharacter*		m_pGirl = NULL;
};
//EOF