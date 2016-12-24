//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "EffectFactory.h"

//================================================
// 少年キャラクターパーツクラス工場
//	（AbstractFactory）
//
//	2016/12/23
//									Author Harada
//================================================
//アニメーション群データの生成と取得
std::vector<CAnimation* >* CEffectPaartsFactory::getAnimations() {
	//アニメーション群の作成
	return new std::vector<CAnimation*>();
}

//移動データの生成と取得
CMove* CEffectPaartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}

//物理演算群データの生成と取得
std::vector<CPhysical* >* CEffectPaartsFactory::getPhysicals() {
	//物理演算群作成
	return new std::vector<CPhysical*>();
}

//アクション群データの生成と取得
std::vector<CAction* >* CEffectPaartsFactory::getActions() {
	//アクション群を作成
	return new std::vector<CAction*>();
}

//実体データの生成と取得
CBody* CEffectPaartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}

//衝突判定空間群データの生成と取得
std::vector<CCollisionArea* >* CEffectPaartsFactory::getCollisionAreas() {
	//衝突判定空間群の生成
	return new std::vector<CCollisionArea*>();
}

//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//
//	2016/12/23
//									Author Harada
//================================================
//エフェクトの生成と設定
CEffect* CEffectFactory::create(cocos2d::Point pos) {

	//エフェクトの生成と組み立て
	CEffect* pChara = this->createPlayer();

	//移動データの設定
	this->settingMove(pChara, pos);
	//画像の設定
	this->settingTexture(pChara);
	//アニメーション群データの設定
	this->settingAnimations(pChara);
	//物理演算群データの設定
	this->settingPhysicals(pChara);
	//アクション群データの設定
	this->settingActions(pChara);
	//実体データの設定
	this->settingBody(pChara);
	//衝突判定空間群データの設定
	this->settingCollisionArea(pChara);

	//そのほか初期化
	this->settingInitialize(pChara);


	return pChara;
}

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//
//	2016/12/23
//									Author Harada
//================================================
//エフェクトの生成と組み立て
CEffect* CEffectCreateFactory::createPlayer() {

	//少年キャラクターの生成
	CEffect* pEffe = CEffect::create();

	//エフェクトパーツ工場を生成
	CEffectPaartsFactory  factory;

	//移動データの実体の取得
	pEffe->m_pMove = factory.getMove();

	//アニメーション群データの実体の取得
	pEffe->m_pAnimations = factory.getAnimations();

	//物理演算群データの実体の取得
	pEffe->m_pPhysicals = factory.getPhysicals();

	//アクション群データの実体の取得
	pEffe->m_pActions = factory.getActions();

	//実体データの実体の取得
	pEffe->m_pBody = factory.getBody();

	//衝突判定空間群データの実体の取得
	pEffe->m_pCollisionAreas = factory.getCollisionAreas();

	return pEffe;
}

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//
//	2016/12/23
//									Author Harada
//================================================

//移動データの設定
void CBaseEffectFactory::settingMove(CEffect* pChara, cocos2d::Point pos) {
	
}

//画像の設定
void CBaseEffectFactory::settingTexture(CEffect* pChara) {

}

//アニメーション群データの設定
void CBaseEffectFactory::settingAnimations(CEffect* pChara) {

}

//物理演算群データの設定
void CBaseEffectFactory::settingPhysicals(CEffect* pChara) {

}

//アクション群データの設定
void CBaseEffectFactory::settingActions(CEffect* pChara) {
	
}

//実体データの設定
void CBaseEffectFactory::settingBody(CEffect* pChara) {

}

//衝突判定空間群データの設定
void CBaseEffectFactory::settingCollisionArea(CEffect* pChara) {


}

//その他初期設定
void CBaseEffectFactory::settingInitialize(CEffect* pChara) {

}


//================================================
// 少年キャラクター生成工場を管理するクラス
//	（Singleton）
//
//	2016/12/22
//									Author Harada
//================================================
//共有インスタンスの実体
CEffectFactoryManager* CEffectFactoryManager::m_pEffectFactoryManager = NULL;

//共有インスタンスの取得
CEffectFactoryManager* CEffectFactoryManager::getInstance() {
	//共有インスタンスの実体が存在しなければ
	if (CEffectFactoryManager::m_pEffectFactoryManager == NULL) {
		//共有インスタンスの実体を生成
		CEffectFactoryManager::m_pEffectFactoryManager = new CEffectFactoryManager();
	}
	//共有インスタンスを返す。
	return CEffectFactoryManager::m_pEffectFactoryManager;
}