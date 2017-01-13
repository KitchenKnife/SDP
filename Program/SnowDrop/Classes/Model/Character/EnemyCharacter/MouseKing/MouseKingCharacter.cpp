/*
* MouseKingCharacter.cpp
*
*	2017/01/09	Shinya Ueba
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "MouseKingCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Data/ActionController/ActionController.h"


//================================================	
//	敵キャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CMouseKingCharacter::CMouseKingCharacter() 
{
	//初期化処理
	ZeroMemory(this->m_pHenchmans, sizeof(this->m_pHenchmans));
}

//デストラクタ
CMouseKingCharacter::~CMouseKingCharacter() 
{


}

//EOF