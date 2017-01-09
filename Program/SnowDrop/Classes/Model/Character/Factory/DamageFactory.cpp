//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "DamageFactory.h"
#include "Data\Enum\EnumDamage.h"
#include "Data\StateMachine\Damage\Smoke\SmokeState.h"


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
	//状態遷移マシンの取得
	pDamage->m_pStateMachine = factory.getStateMachine();

	return pDamage;
}


//================================================
// ダメージキャラのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CNearDamageFactory::settingMove(CDamageCharacter* pCharacter,cocos2d::Point pos) {
	//位置の設定
	pCharacter->m_pMove->m_pos.set(pos);

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

void CNearDamageFactory::settingInitialize(CDamageCharacter* pChara, CCharacter* pAttackChara, int activeFrame) {

	//状態の設定
	pChara->m_state = 0;

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//生きているフラグを立てる
	pChara->m_isAlive = true;

	//ダメージキャラクターを出現させたキャラクター
	pChara->m_pChara = pAttackChara;

	// 存在させておくフレーム数
	pChara->m_activeFrame = activeFrame;

	//ステータスを設定
	pChara->m_status.set(1,1,1,1);

	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pChara->applyFunc();

}


//================================================
// 煙ダメージ工場
//================================================
//各々のパーツのセッティング
void CSmokeDamageFactory::settingMove(CDamageCharacter* pCharacter, cocos2d::Point pos) {
	
	pCharacter->m_status.setSpeed(3);
	
	//位置の設定
	pCharacter->m_pMove->m_pos.set(pos);
}
void CSmokeDamageFactory::settingTexture(CDamageCharacter* pCharacter) {
	//テクスチャの設定
	pCharacter->setTexture(IMAGE_BARON);
}

void CSmokeDamageFactory::settingAnimations(CDamageCharacter* pCharacter) {
	
	//攻撃のアニメーションを設定
	pCharacter->m_pAnimations->push_back(new CChipAnimation(10, 6, true));
	(*pCharacter->m_pAnimations)[(int)DAMAGE_SMOKE_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 1024, 256, 256));

	//死亡のアニメーションを設定
	pCharacter->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pCharacter->m_pAnimations)[(int)DAMAGE_SMOKE_ANIMATION_STATE::DEAD]->addChipData(new CChip(0, 768, 256, 256));

	//最初のアニメーションを設定
	pCharacter->m_animationState = (int)DAMAGE_SMOKE_ANIMATION_STATE::ATTACK;

}

void CSmokeDamageFactory::settingPhysicals(CDamageCharacter* pCharacter) {
}

void CSmokeDamageFactory::settingActions(CDamageCharacter* pCharacter) {
	//開始時のアクションの状態
	int m_actionState = (int)DAMAGE_SMOKE_ACTION_STATE::ATTACK;
	//--------------------------------------------------------------------
	//
	//	移動アクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//移動アクションの生成
	std::vector<CAction*>* pActionStraight = new std::vector<CAction*>();
	//移動アクション中に行うアクションを生成して取りける
	pActionStraight->push_back(new CActionMoveStraight());
	//移動アクションをマップ配列に取り付ける
	pCharacter->m_mapAction[(int)DAMAGE_SMOKE_ACTION_STATE::ATTACK] = pActionStraight;
}

void CSmokeDamageFactory::settingBody(CDamageCharacter* pCharacter) {

	pCharacter->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//衝突判定空間の設定
void CSmokeDamageFactory::settingCollisionArea(CDamageCharacter* pCharacter) {
	//画面端衝突空間の生成
	//同時に画面端の衝突空間に衝突を行う下の基準点を設定
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pCharacter->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//画面端の衝突判定を取り付ける
	pCharacter->m_pCollisionAreas->push_back(pEndOfScreenArea);

}

//衝突判定空間の設定
void CSmokeDamageFactory::settingStateMachine(CDamageCharacter* pCharacter) {

	//状態を待機状態に変更
	pCharacter->m_state = (int)DAMAGE_SMOKE_STATE::ATTACK;

	//--------------------------------------------------------------------
	//
	//	攻撃状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃状態
	//作成した状態を登録していく
	pCharacter->m_pStateMachine->registerState((int)DAMAGE_SMOKE_STATE::ATTACK, new CSmokeAttackState(pCharacter));


	//--------------------------------------------------------------------
	//
	//	死亡状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//死亡状態
	//作成した状態を登録していく
	pCharacter->m_pStateMachine->registerState((int)DAMAGE_SMOKE_STATE::DEAD, new CSmokeDeadState(pCharacter));


	//最後に最初の状態を設定する！！！！！
	pCharacter->m_pStateMachine->setStartState((int)DAMAGE_SMOKE_STATE::ATTACK);
}

void CSmokeDamageFactory::settingInitialize(CDamageCharacter* pChara, CCharacter* pAttackChara, int activeFrame) {

	//状態の設定
	pChara->m_state = 0;

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//生きているフラグを立てる
	pChara->m_isAlive = true;

	//ダメージキャラクターを出現させたキャラクター
	pChara->m_pChara = pAttackChara;

	// 存在させておくフレーム数
	pChara->m_activeFrame = activeFrame;

	//ステータスを設定
	pChara->m_status.set(1, 1, 1, 3);

	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pChara->applyFunc();

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