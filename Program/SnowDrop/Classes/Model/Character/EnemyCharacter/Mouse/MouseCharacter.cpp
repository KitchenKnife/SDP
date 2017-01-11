/*
* MouseKingCharacter.cpp
*
*	2017/01/09	Shinya Ueba
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "MouseCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Data/ActionController/ActionController.h"


//================================================	
//	敵キャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CMouseCharacter::CMouseCharacter(CMouseKingCharacter* pMaster)
	:m_pMaster(pMaster)
{

}

//デストラクタ
CMouseCharacter::~CMouseCharacter()
{


}

//EOF