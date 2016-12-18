
#include "Data/Effect/Effect.h"

/*
* Effect.cpp
*
*	2016/11/25	Osumi
*
*/

//================================================
// 
// エフェクトの基底クラス
//
//================================================
//初期化処理
bool CEffect::init(){

	if (Sprite::init() == false) {
		CCLOG("スプライトクラスの初期化に失敗");
		return false;
	}

	//================================================	
	//	メンバ関数のコードの追加はここから
	//================================================


	//================================================	
	//	値の設定に関するコードの追加はここから
	//================================================


	return true;

}

//更新処理
void CEffect::update() {

	//移動処理
	this->moveFunc();

	//アニメーション処理
	this->animationFunc();

	//反映処理
	this->applyFunc();
}

//アニメーション処理
void CEffect::animationFunc() {

	//アニメーション
	this->m_pAnimationDatas->update();
}

//反映処理
void CEffect::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect(this->m_pAnimationDatas->getCurrentChip());

}
