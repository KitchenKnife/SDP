
#include "Model/Character/PlayerCharacter.h"
#include "Data/Effect/PlayerEffect/PlayerEffect.h"
#include "Data/Effect/PlayerEffect/PlayerEffectFactory.h"

//================================================
// 
// プレイヤーのエフェクトの基底クラス
//
//================================================

//初期化処理
bool CPlayerEffect::init() {

	if (CEffect::init() == false) {
		CCLOG("エフェクトクラスの初期化に失敗");
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


//==========================================
//
//  消失ダメージエッフェクトクラス
//
//==========================================
//初期化処理
bool CBoyDisappearEffect::init(){

	if (CPlayerEffect::init() == false) {
		CCLOG("プレイヤーエフェクトクラスの初期化に失敗");
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


//==========================================
//
//  少年のダメージエフェクトクラス
//
//==========================================
//初期化処理
bool CBoyDamageEffect::init() {

	if (CPlayerEffect::init() == false) {
		CCLOG("プレイヤーエフェクトクラスの初期化に失敗");
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
