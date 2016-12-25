//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "DamageFactory.h"

//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================
//デストラクタ
CDamagePartsFactory::~CDamagePartsFactory() {}

//移動データの実体を生成し取得
CMove* CDamagePartsFactory::getMove() {
	return new CMove();
}

//物理演算群データの実体を生成し取得
std::vector<CPhysical* >* CDamagePartsFactory::getPhysicals() {
	return new std::vector<CPhysical*>();
}


//アニメーション群データの実体を生成し取得
std::vector<CAnimation* >* CDamagePartsFactory::getAnimations() {
	return new std::vector<CAnimation*>();
}

//実体データの実体を生成し取得
CBody* CDamagePartsFactory::getBody() {
	return new CBody();
}

//衝突判定空間群データの実体を生成し取得
std::vector<CCollisionArea* >* CDamagePartsFactory::getCollisionAreas() {
	return new std::vector<CCollisionArea*>();
}

/**
*	@desc 状態遷移データの生成と取得
*	@return 状態遷移データ
*	@author Shinya Ueba
*/
CStateMachine*	CDamagePartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}

//================================================
// パーツセッティングクラスを管理するクラス
//	（FactoryMethod）
//================================================
//共有のインスタンスの実体
CDamageFactoryManager* CDamageFactoryManager::m_pDamageFactoryManager = NULL;

//インスタンスの取得
CDamageFactoryManager* CDamageFactoryManager::getInstance() {

	//共有インスタンスが存在していなければ
	if (CDamageFactoryManager::m_pDamageFactoryManager == NULL) {
		//共有インスタンスを生成
		CDamageFactoryManager::m_pDamageFactoryManager = new CDamageFactoryManager();
	}

	//共有のインスタンスを返す。
	return CDamageFactoryManager::m_pDamageFactoryManager;
}