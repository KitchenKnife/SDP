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
CMouseCharacter::CMouseCharacter(CMouseKingCharacter* pMaster,int positionType)
	:m_pMaster(pMaster),m_positionType(positionType)
{

}

//デストラクタ
CMouseCharacter::~CMouseCharacter()
{


}

/**
* @desc 攻撃命令フラグを設定
* @param true...攻撃させる　false...攻撃させない
*/
void CMouseCharacter::setAttackOrder(bool flag)
{
	this->m_attackOrder = flag;
}


/**
* @desc 攻撃命令フラグを取得
* @param true...攻撃させる　false...攻撃させない
*/
bool CMouseCharacter::getAttackOrder(void)
{
	return this->m_attackOrder;
}


//EOF