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
// 生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//ギミックの生成と組み立て
CDamageCharacter* CDamageCreateFactory::createDamage() {

	CDamageCharacter* pDamage = CDamageCharacter::create();

	// 工場
	CDamagePartsFactory factory;

	//移動用データの取得
	pDamage->m_pMove = factory.getMove();
	//アニメーションデータ群の取得
	pDamage->m_pAnimations = factory.getAnimations();
	//適用する物理演算群の取得
	pDamage->m_pPhysicals = factory.getPhysicals();
	//衝突判定用データの取得
	pDamage->m_pBody = factory.getBody();
	//衝突判定空間群の取得
	pDamage->m_pCollisionAreas = factory.getCollisionAreas();

	return pDamage;
}


//================================================
// ダメージキャラのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CNearDamageFactory::settingMove(CDamageCharacter* pCharacter,CCharacter* pAttackChara) {

	// キャラの前方に出現
	if (pAttackChara->m_pMove->m_vel.x > 0) {
		// →
		//初期位置の設定
		pCharacter->m_pMove->m_pos.set(pAttackChara->m_pMove->m_pos.x + pAttackChara->m_pBody->m_right ,
										pAttackChara->m_pMove->m_pos.y);

	}
	else if(pAttackChara->m_pMove->m_vel.x < 0) {
		// ←
		//初期位置の設定
		pCharacter->m_pMove->m_pos.set(pAttackChara->m_pMove->m_pos.x + pAttackChara->m_pBody->m_left,
										pAttackChara->m_pMove->m_pos.y);
	}

}
void CNearDamageFactory::settingTexture(CDamageCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_SAMPLE_WEAPON);

}

void CNearDamageFactory::settingAnimations(CDamageCharacter* pCharacter) {
	pCharacter->m_pAnimations->push_back(new CChipNotAnimation());

	(*pCharacter->m_pAnimations)[0]->addChipData(new CChip(0,0,48, 54));
}

void CNearDamageFactory::settingPhysicals(CDamageCharacter* pCharacter) {
}

void CNearDamageFactory::settingActions(CDamageCharacter* pCharacter) {

	//pCharacter->m_pActions->push_back(new CActionMoveStraight(2.0f));
	//CActionJump* pAction = (CActionJump*)(*pCharacter->m_pActions)[0];

	//pAction->set(3.0f, 4);
}

void CNearDamageFactory::settingBody(CDamageCharacter* pCharacter) {

	pCharacter->m_pBody->set(-24.0f, 27.0f, 24.0f, -27.0f);
}

//衝突判定空間の設定
void CNearDamageFactory::settingCollisionArea(CDamageCharacter* pCharacter) {

}

//衝突判定空間の設定
void CNearDamageFactory::settingStateMachine(CDamageCharacter* pCharacter) {

}

void CNearDamageFactory::settingInitialize(CDamageCharacter* pCharacter,int activeFrame) {

	//状態の設定
	pCharacter->m_state = 0;

	//有効フラグを立てる
	pCharacter->m_activeFlag = true;

	//生きているフラグを立てる
	pCharacter->m_isAlive = true;

	// 存在させておくフレーム数
	pCharacter->m_activeFrame = activeFrame;

	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pCharacter->applyFunc();

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