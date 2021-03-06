//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "EnemyFactory.h"
#include "Data\Enum\EnumEnemy.h"
#include "Data\StateMachine\Enemy\Maidead\MaideadState.h"
#include "Data\StateMachine\Enemy\NutCracker\NutCrackerState.h"
#include "Data\StateMachine\Enemy\Baron\BaronState.h"
#include "Data\StateMachine\Enemy\MouseKing\MouseKingState.h"
#include "Data\StateMachine\Enemy\Mouse\MouseState.h"
#include "Data\StateMachine\Enemy\Marionette\MarionetteState.h"
#include "Model\Character\CharacterAggregate.h"

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
	(*pChara->m_pAnimations)[(int)ENEMY_MAIDEAD_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 0, 256, 256));

	//歩行 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 8, true));
	(*pChara->m_pAnimations)[(int)ENEMY_MAIDEAD_ANIMATION_STATE::WANDERING]->addChipData(new CChip(0, 0, 256, 256));

	//死亡のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MAIDEAD_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 768, 256, 256));

	//追跡アニメーション
	//※歩行アニメーションと同じ

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
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::IDLE] = pActionIdle;

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
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::WANDERING] = pActionStraight;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	追跡アクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//追跡アクションの生成
	std::vector<CAction*>* pActionChase = new std::vector<CAction*>();
	//追跡アクション中に行うアクションを生成して取りける
	pActionChase->push_back(new CActionChase(false));
	//追跡アクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::CHASE] = pActionChase;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	攻撃受けたアクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃受けたアクションの生成
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//攻撃受けたアクション中に行うアクションを生成して取りける
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//攻撃受けたアクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_MAIDEAD_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------
}


template <class Ty>
void CMaideadFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
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
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 64.0f, 128.0f);

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
	CStateBase* pIdleState = new CMaideadIdleState(	pChara,NULL,NULL);
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::IDLE, pIdleState);

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
	CStateBase* pWanderingState = new CMaideadWanderingState(pChara,NULL,NULL);
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::WANDERING, pWanderingState);

//--------------------------------------------------------------------
//
//	ここまで
//
//--------------------------------------------------------------------


//--------------------------------------------------------------------
//
//	追跡状態を設定する ここから
//
//--------------------------------------------------------------------

//追跡状態
CStateBase* pChaseState = new CMaideadChaseState(pChara, NULL, NULL);
//作成した状態を登録していく
pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::CHASE, pChaseState);

//--------------------------------------------------------------------
//
//	ここまで
//
//-------------------------------------------------------------------


//--------------------------------------------------------------------
//
//	攻撃を受けた状態を設定する ここから
//
//--------------------------------------------------------------------

	//待機状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::UNDER_ATTACK, new CMaideadUnderAttackState(pChara, NULL, NULL));

//--------------------------------------------------------------------
//
//	死亡状態を設定する ここから
//
//--------------------------------------------------------------------

	//死亡状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MAIDEAD_STATE::DEAD, new CMaideadDeadState(pChara, NULL, NULL));


	//最後に最初の状態を設定する！！！！！
	pChara->m_pStateMachine->setStartState((int)ENEMY_MAIDEAD_STATE::IDLE);
}

template <class Ty>
void CMaideadFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//主なターゲット
	pChara->m_targetType = TARGET_TYPE::BOTH;

	//現在の優先攻撃対象
	pChara->m_currentTarget = NULL;

	//プレイヤーを感知、追跡する範囲
	float m_chaseRange = 400;

	//攻撃範囲
	float m_attackRange = 80;

	//有効フラグを立てる
	pChara->m_activeFlag = true;
	
	//生死フラグを立てる
	pChara->m_isAlive = true;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

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
	(*pChara->m_pAnimations)[(int)ENEMY_BAT_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 64, 64, 64));

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
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

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
// マリス工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
template <class Ty>
void CMaliceFactory<Ty>::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//初期位置の設定
	pChara->m_pMove->m_pos.set(x, y);
	//初期速度
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

template <class Ty>
void CMaliceFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_BAT);
}

template <class Ty>
void CMaliceFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)ENEMY_BAT_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 64, 64, 64));

}

template <class Ty>
void CMaliceFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {

}

template <class Ty>
void CMaliceFactory<Ty>::settingActions(CEnemyCharacter* pChara) {


}

template <class Ty>
void CMaliceFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-32.0f, 32.0f, 32.0f, -32.0f);
}

//衝突判定空間の設定
template <class Ty>
void CMaliceFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

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
void CMaliceFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{

}

template <class Ty>
void CMaliceFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//状態を待機状態に変更
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

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
// NutCracker工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
template <class Ty>
void CNutCrackerFactory<Ty>::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//初期位置の設定
	pChara->m_pMove->m_pos.set(x, y);
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_NUTCRACKER);
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 0, 128, 128));

	//攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)ENEMY_NUTCRACKER_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 128, 128, 128));

	//死亡のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, false));
	(*pChara->m_pAnimations)[(int)ENEMY_NUTCRACKER_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 0, 128, 128));

	//最初のアニメーションを設定
	pChara->m_animationState = (int)ENEMY_NUTCRACKER_ANIMATION_STATE::IDLE;
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {
	//歩行キャラには重力つける
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingActions(CEnemyCharacter* pChara) {

	//開始時のアクションの状態
	int m_actionState = (int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE;

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
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::IDLE] = pActionIdle;

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
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::WANDERING] = pActionStraight;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	追跡アクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//追跡アクションの生成
	std::vector<CAction*>* pActionChase = new std::vector<CAction*>();
	//追跡アクション中に行うアクションを生成して取りける
	pActionChase->push_back(new CActionChase(false));
	//追跡アクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::CHASE] = pActionChase;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------


	//--------------------------------------------------------------------
	//
	//	攻撃受けたアクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃受けたアクションの生成
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//攻撃受けたアクション中に行うアクションを生成して取りける
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//攻撃受けたアクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_NUTCRACKER_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------
}

template <class Ty>
void CNutCrackerFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-64.0f, 64.0f, 64.0f, -64.0f);
}

//衝突判定空間の設定
template <class Ty>
void CNutCrackerFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 64.0f);

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
void CNutCrackerFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{
	//--------------------------------------------------------------------
	//
	//	待機状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//待機状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::IDLE, new CNutCrackerIdleState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	徘徊状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//徘徊状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::WANDERING, new CNutCrackerWanderingState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	追跡状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//追跡状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::CHASE, new CNutCrackerChaseState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	攻撃状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::ATTACK, new CNutCrackerAttackState(pChara, NULL, NULL));


	//--------------------------------------------------------------------
	//
	//	攻撃を受けた状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃を受けた状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::UNDER_ATTACK, new CNutCrackerUnderAttackState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	死亡状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//死亡状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_NUTCRACKER_STATE::DEAD, new CNutCrackerDeadState(pChara, NULL, NULL));


	//最後に最初の状態を設定する！！！！！
	pChara->m_pStateMachine->setStartState((int)ENEMY_NUTCRACKER_STATE::IDLE);

}

template <class Ty>
void CNutCrackerFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//状態を待機状態に変更
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//ステータスを設定する
	pChara->m_status.set(3, 3, 1, 1);

	//生死フラグを立てる
	pChara->m_isAlive = true;

	//現在の移動データとアニメーションを反映
	pChara->applyFunc();

}


//================================================
// Baron工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
template <class Ty>
void CBaronFactory<Ty>::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//初期位置の設定
	pChara->m_pMove->m_pos.set(x, y);
	//初期速度
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

template <class Ty>
void CBaronFactory<Ty>::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_BARON);
}

template <class Ty>
void CBaronFactory<Ty>::settingAnimations(CEnemyCharacter* pChara) {
	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)ENEMY_BARON_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 0, 256, 256));

	//攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 9, false));
	(*pChara->m_pAnimations)[(int)ENEMY_BARON_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 256, 256, 256));

	//死亡のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 13, false));
	(*pChara->m_pAnimations)[(int)ENEMY_BARON_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 0, 256, 256));

	//最初のアニメーションを設定
	pChara->m_animationState = (int)ENEMY_BARON_ANIMATION_STATE::IDLE;

}

template <class Ty>
void CBaronFactory<Ty>::settingPhysicals(CEnemyCharacter* pChara) {
	//歩行キャラには重力つける
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

template <class Ty>
void CBaronFactory<Ty>::settingActions(CEnemyCharacter* pChara) {


	//開始時のアクションの状態
	int m_actionState = (int)ENEMY_BARON_ACTION_STATE::IDLE;

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
	pChara->m_mapAction[(int)ENEMY_BARON_ACTION_STATE::IDLE] = pActionIdle;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------

	//--------------------------------------------------------------------
	//
	//	攻撃受けたアクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃受けたアクションの生成
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//攻撃受けたアクション中に行うアクションを生成して取りける
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//攻撃受けたアクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_BARON_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;

	//--------------------------------------------------------------------
	//
	//	ここまで
	//
	//--------------------------------------------------------------------
}

template <class Ty>
void CBaronFactory<Ty>::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//衝突判定空間の設定
template <class Ty>
void CBaronFactory<Ty>::settingCollisionArea(CEnemyCharacter* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 64.0f, 128.0f);

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
void CBaronFactory<Ty>::settingStateMachine(CEnemyCharacter* pChara)
{
	//--------------------------------------------------------------------
	//
	//	待機状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//待機状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::IDLE, new CBaronIdleState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	攻撃状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::ATTACK, new CBaronAttackState(pChara, NULL, NULL));


	//--------------------------------------------------------------------
	//
	//	攻撃を受けた状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃を受けた状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::UNDER_ATTACK, new CBaronUnderAttackState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	死亡状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//死亡状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_BARON_STATE::DEAD, new CBaronDeadState(pChara, NULL, NULL));


	//最後に最初の状態を設定する！！！！！
	pChara->m_pStateMachine->setStartState((int)ENEMY_BARON_STATE::IDLE);
}

template <class Ty>
void CBaronFactory<Ty>::settingInitialize(CEnemyCharacter* pChara) {

	//状態を待機状態に変更
	pChara->m_state = (int)ENEMY_BAT_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

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
// MouseKing工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CMouseKingFactory::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//初期位置の設定
	pChara->m_pMove->m_pos.set(x, y);
	//初期速度
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CMouseKingFactory::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_MOUSEKING);
}

void CMouseKingFactory::settingAnimations(CEnemyCharacter* pChara) {
	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true));
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 128, 128, 128));

	//攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSEKING_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 128, 128, 128));

	//死亡のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSEKING_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 0, 128, 128));

	//最初のアニメーションを設定
	pChara->m_animationState = (int)ENEMY_MOUSEKING_ANIMATION_STATE::IDLE;
}

void CMouseKingFactory::settingPhysicals(CEnemyCharacter* pChara) {
	//歩行キャラには重力つける
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

void CMouseKingFactory::settingActions(CEnemyCharacter* pChara) {
	//開始時のアクションの状態
	int m_actionState = (int)ENEMY_MOUSEKING_ACTION_STATE::IDLE;

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
	pChara->m_mapAction[(int)ENEMY_MOUSEKING_ACTION_STATE::IDLE] = pActionIdle;

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
	pChara->m_mapAction[(int)ENEMY_MOUSEKING_ACTION_STATE::WANDERING] = pActionStraight;

	//--------------------------------------------------------------------
	//
	//	攻撃受けたアクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃受けたアクションの生成
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//攻撃受けたアクション中に行うアクションを生成して取りける
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//攻撃受けたアクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_MOUSEKING_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;
}


void CMouseKingFactory::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-64.0f, 64.0f, 64.0f, -64.0f);
}

//衝突判定空間の設定
void CMouseKingFactory::settingCollisionArea(CEnemyCharacter* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 64.0f);

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
void CMouseKingFactory::settingStateMachine(CEnemyCharacter* pChara)
{
	//--------------------------------------------------------------------
	//
	//	待機状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//待機状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSEKING_STATE::IDLE, new CMouseKingIdleState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	徘徊状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//徘徊状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSEKING_STATE::WANDERING, new CMouseKingWanderingState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	攻撃状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSEKING_STATE::ATTACK, new CMouseKingAttackState(pChara, NULL, NULL));


	//--------------------------------------------------------------------
	//
	//	攻撃を受けた状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃を受けた状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSEKING_STATE::UNDER_ATTACK, new CMouseKingUnderAttackState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	死亡状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//死亡状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSEKING_STATE::DEAD, new CMouseKingDeadState(pChara, NULL, NULL));

	//最後に最初の状態を設定する！！！！！
	pChara->m_pStateMachine->setStartState((int)ENEMY_MOUSEKING_STATE::IDLE);
}

void CMouseKingFactory::settingInitialize(CEnemyCharacter* pChara) {

	//状態を待機状態に変更
	pChara->m_state = (int)ENEMY_MOUSEKING_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//ステータスを設定する
	pChara->m_status.set(3, 3, 1, 1);

	//生死フラグを立てる
	pChara->m_isAlive = true;

	//現在の移動データとアニメーションを反映
	pChara->applyFunc();

	//CMouseKingCharacterにアップキャストする
	CMouseKingCharacter* pMouseKing = (CMouseKingCharacter*)pChara;

	//子分を生成する
	CMouseFactory henchmansFactory;

	pMouseKing->m_pHenchmans[0] = henchmansFactory.create(pMouseKing->m_pMove->m_pos.x, pMouseKing->m_pMove->m_pos.y, pMouseKing, (int)HENCHMAN_POSITION_TYPE::FORWARD);
	pMouseKing->m_pHenchmans[1] = henchmansFactory.create(pMouseKing->m_pMove->m_pos.x, pMouseKing->m_pMove->m_pos.y, pMouseKing, (int)HENCHMAN_POSITION_TYPE::DEFENDER);

	//キャラクターをキャラクターの集合体に取り付ける
	CCharacterAggregate::getInstance()->add(pMouseKing->m_pHenchmans[0]);
	CCharacterAggregate::getInstance()->add(pMouseKing->m_pHenchmans[1]);

	//キャラクターをメインレイヤーに取り付ける
	CCharacterAggregate::getInstance()->getLayer()->addChild(pMouseKing->m_pHenchmans[0]);
	CCharacterAggregate::getInstance()->getLayer()->addChild(pMouseKing->m_pHenchmans[1]);
}

//================================================
// Mouse工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CMouseFactory::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//初期位置の設定
	pChara->m_pMove->m_pos.set(x, y);
	//初期速度
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CMouseFactory::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_MOUSEKING);
}

void CMouseFactory::settingAnimations(CEnemyCharacter* pChara) {
	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 640, 128, 128));

	//徘徊のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::WANDERING]->addChipData(new CChip(0, 640, 128, 128));

	//攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 256, 128, 128));

	//死亡のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 6, false,3));
	(*pChara->m_pAnimations)[(int)ENEMY_MOUSE_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 384, 128, 128));

	//最初のアニメーションを設定
	pChara->m_animationState = (int)ENEMY_MOUSE_ANIMATION_STATE::IDLE;
}

void CMouseFactory::settingPhysicals(CEnemyCharacter* pChara) {
	//歩行キャラには重力つける
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

void CMouseFactory::settingActions(CEnemyCharacter* pChara) {
	//開始時のアクションの状態
	int m_actionState = (int)ENEMY_MOUSE_ACTION_STATE::IDLE;

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
	pChara->m_mapAction[(int)ENEMY_MOUSE_ACTION_STATE::IDLE] = pActionIdle;

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
	pChara->m_mapAction[(int)ENEMY_MOUSE_ACTION_STATE::WANDERING] = pActionStraight;

	//--------------------------------------------------------------------
	//
	//	攻撃受けたアクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃受けたアクションの生成
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//攻撃受けたアクション中に行うアクションを生成して取りける
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//攻撃受けたアクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_MOUSE_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;
}


void CMouseFactory::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-64.0f, 64.0f, 64.0f, -64.0f);
}

//衝突判定空間の設定
void CMouseFactory::settingCollisionArea(CEnemyCharacter* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 64.0f);

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
void CMouseFactory::settingStateMachine(CEnemyCharacter* pChara)
{
	//--------------------------------------------------------------------
	//
	//	待機状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//待機状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSE_STATE::IDLE, new CMouseIdleState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	徘徊状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//徘徊状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSE_STATE::WANDERING, new CMouseWanderingState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	攻撃状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSE_STATE::ATTACK, new CMouseAttackState(pChara, NULL, NULL));


	//--------------------------------------------------------------------
	//
	//	攻撃を受けた状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃を受けた状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSE_STATE::UNDER_ATTACK, new CMouseUnderAttackState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	死亡状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//死亡状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MOUSE_STATE::DEAD, new CMouseDeadState(pChara, NULL, NULL));

	//最後に最初の状態を設定する！！！！！
	pChara->m_pStateMachine->setStartState((int)ENEMY_MOUSE_STATE::IDLE);
}

void CMouseFactory::settingInitialize(CEnemyCharacter* pChara) {

	//状態を待機状態に変更
	pChara->m_state = (int)ENEMY_MOUSE_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

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
// Marionette工場
//	（FactoryMethod）
//================================================
//各々のパーツのセッティング
void CMarionetteFactory::settingMove(CEnemyCharacter* pChara, float x, float y) {
	//初期位置の設定
	pChara->m_pMove->m_pos.set(x, y);
	//初期速度
	pChara->m_pMove->m_vel.set(0.0f, 0.0f);
}

void CMarionetteFactory::settingTexture(CEnemyCharacter* pChara) {
	//テクスチャの設定
	pChara->setTexture(IMAGE_MARIONETTE);
}

void CMarionetteFactory::settingAnimations(CEnemyCharacter* pChara) {
	//直立アニメーションの設定
	pChara->m_pAnimations->push_back(new CChipNotAnimation());
	//直立アニメーションに設定する為のチップデータの設定
	(*pChara->m_pAnimations)[(int)ENEMY_MARIONETTE_ANIMATION_STATE::IDLE]->addChipData(new CChip(0, 512, 128, 128));

	//徘徊のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MARIONETTE_ANIMATION_STATE::WANDERING]->addChipData(new CChip(0, 512, 128, 128));

	//攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MARIONETTE_ANIMATION_STATE::ATTACK]->addChipData(new CChip(0, 384, 128, 128));

	//死亡のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 10, false));
	(*pChara->m_pAnimations)[(int)ENEMY_MARIONETTE_ANIMATION_STATE::DAED]->addChipData(new CChip(0, 128, 128, 128));

	//最初のアニメーションを設定
	pChara->m_animationState = (int)ENEMY_MARIONETTE_ANIMATION_STATE::IDLE;
}

void CMarionetteFactory::settingPhysicals(CEnemyCharacter* pChara) {
	//歩行キャラには重力つける
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());
}

void CMarionetteFactory::settingActions(CEnemyCharacter* pChara) {
	//開始時のアクションの状態
	int m_actionState = (int)ENEMY_MARIONETTE_ACTION_STATE::IDLE;

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
	pChara->m_mapAction[(int)ENEMY_MARIONETTE_ACTION_STATE::IDLE] = pActionIdle;

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
	pChara->m_mapAction[(int)ENEMY_MARIONETTE_ACTION_STATE::WANDERING] = pActionStraight;

	//--------------------------------------------------------------------
	//
	//	攻撃受けたアクションを設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃受けたアクションの生成
	std::vector<CAction*>* pActionUnderAttack = new std::vector<CAction*>();
	//攻撃受けたアクション中に行うアクションを生成して取りける
	pActionUnderAttack->push_back(new CActionJump(6.0f, 16.0f));
	//攻撃受けたアクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)ENEMY_MARIONETTE_ACTION_STATE::UNDER_ATTACK] = pActionUnderAttack;
}


void CMarionetteFactory::settingBody(CEnemyCharacter* pChara) {
	//実体のボディを設定
	pChara->m_pBody->set(-64.0f, 64.0f, 64.0f, -64.0f);
}

//衝突判定空間の設定
void CMarionetteFactory::settingCollisionArea(CEnemyCharacter* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面下端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenBottom());
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody, 32.0f, 64.0f);

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
void CMarionetteFactory::settingStateMachine(CEnemyCharacter* pChara)
{
	//--------------------------------------------------------------------
	//
	//	待機状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//待機状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MARIONETTE_STATE::IDLE, new CMarionetteIdleState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	徘徊状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//徘徊状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MARIONETTE_STATE::WANDERING, new CMarionetteWanderingState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	攻撃状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MARIONETTE_STATE::ATTACK, new CMarionetteAttackState(pChara, NULL, NULL));


	//--------------------------------------------------------------------
	//
	//	攻撃を受けた状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//攻撃を受けた状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MARIONETTE_STATE::UNDER_ATTACK, new CMarionetteUnderAttackState(pChara, NULL, NULL));

	//--------------------------------------------------------------------
	//
	//	死亡状態を設定する ここから
	//
	//--------------------------------------------------------------------

	//死亡状態
	//作成した状態を登録していく
	pChara->m_pStateMachine->registerState((int)ENEMY_MARIONETTE_STATE::DEAD, new CMarionetteDeadState(pChara, NULL, NULL));

	//最後に最初の状態を設定する！！！！！
	pChara->m_pStateMachine->setStartState((int)ENEMY_MARIONETTE_STATE::IDLE);
}

void CMarionetteFactory::settingInitialize(CEnemyCharacter* pChara) {

	//状態を待機状態に変更
	pChara->m_state = (int)ENEMY_MARIONETTE_STATE::IDLE;

	pChara->m_charaType = (int)CHARACTER_TYPE::ENEMY;

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//ステータスを設定する
	pChara->m_status.set(3, 3, 1, 5);

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

//インスタンスの破棄
void CEnemyFactoryManager::removeInstance() {
	if (CEnemyFactoryManager::m_pEnemyFactoryManager != NULL) {
		SAFE_DELETE(CEnemyFactoryManager::m_pEnemyFactoryManager);
	}
}