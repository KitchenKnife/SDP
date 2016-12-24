//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "EnemyFactory.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data\StateMachine\Enemy\Maidead\MaideadState.h"

//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//================================================
//デストラクタ
CEnemeyPartsFactory::~CEnemeyPartsFactory(){}

//移動データの実体を生成し取得
CMove* CEnemeyPartsFactory::getMove() {
	return new CMove();
}

//物理演算群データの実体を生成し取得
std::vector<CPhysical* >* CEnemeyPartsFactory::getPhysicals() {
	return new std::vector<CPhysical*>();
}


//アニメーション群データの実体を生成し取得
std::vector<CAnimation* >* CEnemeyPartsFactory::getAnimations() {
	return new std::vector<CAnimation*>();
}

//実体データの実体を生成し取得
CBody* CEnemeyPartsFactory::getBody() {
	return new CBody();
}

//衝突判定空間群データの実体を生成し取得
std::vector<CCollisionArea* >* CEnemeyPartsFactory::getCollisionAreas() {
	return new std::vector<CCollisionArea*>();
}

/**
*	@desc 状態遷移データの生成と取得
*	@return 状態遷移データ
*	@author Shinya Ueba
*/
CStateMachine*	CEnemeyPartsFactory::getStateMachine(void)
{
	return new CStateMachine();
}

//================================================
// メイデッド工場
//================================================
//移動データの設定
template <class Ty>
void CMaideadFactory<Ty>::settingMove(CEnemyCharacter* pChara, float posX, float posY) {

	//初期位置の設定
	pChara->m_pMove->m_pos.set(posX,posY);
	//初期速度
	//pChara->m_pMove->m_vel.set(-1.0f, 0.0f);
}

template <class Ty>
void CMaideadFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_MEIDEAD);
}

template <class Ty>
void CMaideadFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {

	//開始時のアニメーションの状態
	pChara->m_animationState = (int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE;

	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)ENEMY_MAIDEAD_STATE::IDLE]->addChipData(new CChip(0, 0, 64, 64));
}

template <class Ty>
void CMaideadFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {
	//歩行キャラには重力つける
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

template <class Ty>
void CMaideadFactory<Ty>::settingActions(CEnemyCharacter* pChara) {
	//開始時のアクションの状態
	int m_actionState = (int)ENEMY_MAIDEAD_ACTION_STATE::IDLE;

	//--------------------------------------------------------------------
	//
	//	待機アクションを設定する ここから
	//
	//--------------------------------------------------------------------

		//待機状態アクションの生成
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//待機状態中に行うアクションを生成して取りける
	pActionIdle->push_back(new CActionIdle());
	//待機状態アクションをマップ配列に取り付ける
	pChara->m_mapAction.insert(std::map<int, std::vector<CAction*>*>::value_type((int)ENEMY_MAIDEAD_ACTION_STATE::IDLE, pActionIdle));

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------



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
	pChara->m_mapAction.insert(std::map<int, std::vector<CAction*>*>::value_type((int)ENEMY_MAIDEAD_ACTION_STATE::WANDERING, pActionStraight));

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------
}


template <class Ty>
void CMaideadFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//衝突判定空間の設定
template <class Ty>
void CMaideadFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

	//画面端衝突空間の生成
	//同時に画面端の衝突空間に衝突を行う下の基準点を設定
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 32.0f);

	//マップチップ下端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
	//マップチップ上端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//マップチップ右端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//マップチップ左端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pMapArea);
}

/**
*	@desc 状態遷移データの設定
*	@param 設定するキャラクター
*	@author Shinya Ueba
*/
template <class Ty>
void CMaideadFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{
	//状態を待機状態に変更
	pChara->m_state = (int)ENEMY_MAIDEAD_STATE::IDLE;

	//必要な状態を作成していく

//--------------------------------------------------------------------
//
//	待機状態を設定する ここから
//
//--------------------------------------------------------------------

	//待機状態
	CStateSwitch* pIdleStateSwitch = new CStateSwitch(new CMaideadIdleState((int)ENEMY_MAIDEAD_STATE::IDLE,
														pChara,
														NULL,
														NULL));
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::IDLE, pIdleStateSwitch);

//--------------------------------------------------------------------
//
//	ここまで
//
//--------------------------------------------------------------------


//--------------------------------------------------------------------
//
//	徘徊状態を設定する ここから
//
//--------------------------------------------------------------------

	//待機状態
	CStateSwitch* pWanderingStateSwitch = new CStateSwitch(new CMaideadWanderingState((int)ENEMY_MAIDEAD_STATE::CHASE,
															pChara,
															NULL,
															NULL));
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::WANDERING, pWanderingStateSwitch);

//--------------------------------------------------------------------
//
//	ここまで
//
//--------------------------------------------------------------------



	//最後に最初の状態を設定する！！！！！
	pChara->m_pStateMachine->setStartState((int)ENEMY_MAIDEAD_STATE::IDLE);
}

template <class Ty>
void CMaideadFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {


	//有効フラグを立てる
	pChara->m_activeFlag = true;
	
	//生死フラグを立てる
	pChara->m_isAlive = true;

	//ステータスを設定する
	pChara->m_status.set(3,3,1,1);
	
	//現在の移動データとアニメーションを反映させる。
	pChara->applyFunc();

}

//================================================
// コウモリ工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
template <class Ty>
void CBatFactory<Ty>::settingMove(CEnemyCharacter* pChara,float x, float y) {
	//初期位置の設定
	pChara->m_pMove->m_pos.set(x, y);
	//初期速度
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

template <class Ty>
void CBatFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_BAT);
}

template <class Ty>
void CBatFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)CEnemyCharacter::STATE::STAND]->addChipData(new CChip(0, 64, 64, 64));

}

template <class Ty>
void CBatFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {

}

template <class Ty>
void CBatFactory<Ty>::settingActions(CEnemyCharacter* pChara) {
	

}

template <class Ty>
void CBatFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//衝突判定空間の設定
template <class Ty>
void CBatFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 32.0f);

	//マップチップ下端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipBottom());
	//マップチップ上端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//マップチップ右端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//マップチップ左端領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pMapArea);

}

/**
*	@desc 状態遷移データの設定
*	@param 設定するキャラクター
*	@author Shinya Ueba
*/
template <class Ty>
void CBatFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{

}

template <class Ty>
void CBatFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//状態を待機状態に変更
	pChara->m_state = (int)CEnemyCharacter::STATE::STAND;

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//ステータスを設定する
	pChara->m_status.set(3, 3, 1, 3);

	//生死フラグを立てる
	pChara->m_isAlive = true;
	
	//現在の移動データとアニメーションを反映
	pChara->applyFunc();

}

//================================================
// パーツセッティングクラスを管理するクラス
//	（FactoryMethod）
//================================================
//共有のインスタンスの実体
CEnemyFactoryManager* CEnemyFactoryManager::m_pEnemyFactoryManager = NULL;

//インスタンスの取得
CEnemyFactoryManager* CEnemyFactoryManager::getInstance() {

	//共有インスタンスが存在していなければ
	if (CEnemyFactoryManager::m_pEnemyFactoryManager == NULL) {
		//共有インスタンスを生成
		CEnemyFactoryManager::m_pEnemyFactoryManager = new CEnemyFactoryManager();
	}

	//共有のインスタンスを返す。
	return CEnemyFactoryManager::m_pEnemyFactoryManager;
}