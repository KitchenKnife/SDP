/*
* PlayerFactory.cpp
*
*	2016/11/25	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "PlayerFactory.h"
#include "Data\StateMachine\Player\PlayerState.h"
#include "Data/StateMachine/Player/PlayerStateGraps.h"
#include "Data/StateMachine/Player/PlayerStateHold.h"
#include "Data\Enum\EnumPlayer.h"

//================================================
// 少年キャラクターパーツクラス工場
//	（AbstractFactory）
//
//	2016/12/22
//									Author Harada
//================================================
//アニメーション群データの生成と取得
std::vector<CAnimation* >* CPlayerBoyPartsFactory::getAnimations() {
	//アニメーション群の作成
	return new std::vector<CAnimation*>();
}

//移動データの生成と取得
CMove* CPlayerBoyPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}

//物理演算群データの生成と取得
std::vector<CPhysical* >* CPlayerBoyPartsFactory::getPhysicals() {
	//物理演算群作成
	return new std::vector<CPhysical*>();
}



//実体データの生成と取得
CBody* CPlayerBoyPartsFactory::getBody() {
	//実体データの作成
	return new CBody();
}

//衝突判定空間群データの生成と取得
std::vector<CCollisionArea* >* CPlayerBoyPartsFactory::getCollisionAreas() {
	//衝突判定空間群の生成
	return new std::vector<CCollisionArea*>();
}

/**
*	@desc 状態遷移データの生成と取得
*	@return 状態遷移データ
*	@author Shinya Ueba
*/
CStateMachine*	CPlayerBoyPartsFactory::getStateMachine(void){
	//ステートマシーンデータの作成
	return new CStateMachine();
}

/**
 * @desc	状態遷移データ群の生成と取得
 * @return	状態遷移データ群
 * @author	Harada
 */
std::map<int, CStateMachine*>* CPlayerBoyPartsFactory::getStateMachines(void) {
	//ステートマシーンデータ群の作成
	return new std::map<int, CStateMachine*>();
}

//================================================
// キャラクターの生成過程を抽象化したクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//================================================
//プレイヤーの生成と設定
CPlayerCharacterBoy* CPlayerBoyFactory::create() {

	//プレイヤーの生成と組み立て
	CPlayerCharacterBoy* pChara = this->createPlayer();

	//移動データの設定
	this->settingMove(pChara);
	//テクスチャの設定
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
	//状態遷移データの設定
	this->settingStateMachine(pChara);
	//そのほか初期化
	this->settingInitialize(pChara);


	return pChara;
}

//================================================
// キャラクターの生成と組み立てを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//================================================
//プレイヤーの生成と組み立て
CPlayerCharacterBoy* CPlayerBoyCreateFactory::createPlayer() {

	//少年キャラクターの生成
	CPlayerCharacterBoy* pPlayerBoy = CPlayerCharacterBoy::create();

	//少年キャラクターパーツ工場を生成
	CPlayerBoyPartsFactory  factory;

	//移動の取得
	pPlayerBoy->m_pMove = factory.getMove();

	//アニメーション群の取得
	pPlayerBoy->m_pAnimations = factory.getAnimations();
	
	//物理演算群の取得
	pPlayerBoy->m_pPhysicals = factory.getPhysicals();
	
	//実体の取得
	pPlayerBoy->m_pBody = factory.getBody();

	//衝突判定空間群の取得
	pPlayerBoy->m_pCollisionAreas = factory.getCollisionAreas();

	//状態遷移群の生成と取得
	pPlayerBoy->m_pStateMachines = factory.getStateMachines();

	return pPlayerBoy;
}

//================================================
// キャラクターのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//
//	2016/12/22
//									Author Harada
//================================================

//移動データの設定
void CBasePlayerBoyFactory::settingMove(CPlayerCharacterBoy* pChara){

	//初期位置の設定
	pChara->m_pMove->m_pos.set(WINDOW_TOP * 0.5f, WINDOW_RIGHT * 0.5f);
}
void CBasePlayerBoyFactory::settingTexture(CPlayerCharacterBoy* pChara){
	//テクスチャの設定
	pChara->setTexture(IMAGE_PLAYER);

	pChara->setScale(2.0f);
	
}

void CBasePlayerBoyFactory::settingAnimations(CPlayerCharacterBoy* pChara) {

	//開始時のアニメーションの状態
	pChara->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;

	//================================================
	// 待機・歩行のアニメーション設定
	//================================================
	//右待機 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true, 4));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::IDLE_RIGHT]->addChipData(new CChip(512, 384, 128, 128));

	//左待機 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::IDLE_LEFT]->addChipData(new CChip(0, 384, 128, 128));

	//右歩行 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::WALK_RIGHT]->addChipData(new CChip(0, 128, 128, 128));

	//左歩行 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 7, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::WALK_LEFT]->addChipData(new CChip(0, 256, 128, 128));

	//右ジャンプ のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_RIGHT]->addChipData(new CChip(0, 384, 128, 128));

	//左ジャンプ のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true, 4));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_LEFT]->addChipData(new CChip(512, 384, 128, 128));

	//右落下 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 4, true));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FALL_RIGHT]->addChipData(new CChip(0, 384, 128, 128));

	//左落下 のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, true, 4));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FALL_LEFT]->addChipData(new CChip(512, 384, 128, 128));

	//================================================
	// 攻撃のアニメーション設定
	//================================================
	//右攻撃（１撃目）のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_RIGHT]->addChipData(new CChip(0, 640, 128, 128));

	//右攻撃（２撃目）のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_RIGHT]->addChipData(new CChip(0, 768, 128, 128));

	//右攻撃（３撃目）のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::THURD_ATTACK_RIGHT]->addChipData(new CChip(0, 896, 128, 128));

	//左攻撃（１撃目）のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::FIRST_ATTACK_LEFT]->addChipData(new CChip(0, 640, 128, 128));

	//左攻撃（２撃目）のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::SECOND_ATTACK_LEFT]->addChipData(new CChip(0, 768, 128, 128));

	//左攻撃（３撃目）のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::THURD_ATTACK_LEFT]->addChipData(new CChip(0, 896, 128, 128));

	//右ジャンプ攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(5, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_ATTACK_RIGHT]->addChipData(new CChip(0, 640, 128, 128));

	//左ジャンプ攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(5, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::JUMP_ATTACK_LEFT]->addChipData(new CChip(0, 640, 128, 128));

	//================================================
	// その他のアニメーション設定
	//================================================
	//右向き装備する のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 8, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::EQUIP_RIGHT]->addChipData(new CChip(384, 0, 128, 128));

	//左向き装備する のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 8, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::EQUIP_LEFT]->addChipData(new CChip(384, 0, 128, 128));

	//右向き装備を外す のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::UN_EQUIP_RIGHT]->addChipData(new CChip(0, 0, 128, 128));

	//左向き装備を外す のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 3, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::UN_EQUIP_LEFT]->addChipData(new CChip(0, 0, 128, 128));
	
	//手を掴む右向き のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false,2));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_RIGHT]->addChipData(new CChip(256, 512, 128, 128));

	//手を掴む左向き のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 2, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRASP_LEFT]->addChipData(new CChip(0, 512, 128, 128));

	//手を掴んだ状態での右攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_RIGHT]->addChipData(new CChip(0, 896, 128, 128));

	//手を掴んだ状態での左攻撃のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::GRAPS_ATTACK_LEFT]->addChipData(new CChip(0, 896, 128, 128));

	//右向きお姫様抱っこ状態のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::HOLD_RIGHT]->addChipData(new CChip(256, 512, 128, 128));

	//左向きお姫様抱っこ状態のアニメーションを設定
	pChara->m_pAnimations->push_back(new CChipAnimation(10, 5, false));
	(*pChara->m_pAnimations)[(int)PLAYER_ANIMATION_STATE::HOLD_LEFT]->addChipData(new CChip(0, 512, 128, 128));
}

void CBasePlayerBoyFactory::settingPhysicals(CPlayerCharacterBoy* pChara){
	//重力を設定
	pChara->m_pPhysicals->push_back(new CPhysicalGravity());

	//摩擦を設定
	pChara->m_pPhysicals->push_back(new CPhysicalFriction(5.0f, 0.45f));
}

void CBasePlayerBoyFactory::settingActions(CPlayerCharacterBoy* pChara){

	//待機中のアクション群の実体を生成
	std::vector<CAction*>* pActionIdle = new std::vector<CAction*>();
	//待機中に行うアクションを生成して取りける
	pActionIdle->push_back(new CActionIdle());
	//待機アクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)PLAYER_ACTION_STATE::IDLE] = pActionIdle;


	//ジャンプ中のアクション群の実体を生成
	std::vector<CAction*>* pActionJump = new std::vector<CAction*>();
	//ジャンプ中に行うアクションを生成して取り付ける
	pActionJump->push_back(new CActionJump(5.0f, 4.0f));
	//ジャンプアクションをマップ配列に取り付ける
	pChara->m_mapAction[(int)PLAYER_ACTION_STATE::JUMP] = pActionJump;
}

void CBasePlayerBoyFactory::settingBody(CPlayerCharacterBoy* pChara){

	pChara->m_pBody->set(-128.0f, 128.0f, 128.0f, -128.0f);
}

//衝突判定空間の設定
void CBasePlayerBoyFactory::settingCollisionArea(CPlayerCharacterBoy* pChara) {

	//画面端衝突空間の生成
	CCollisionArea* pEndOfScreenArea = new CCollsionAreaEndOfScreen(pChara->m_pBody);

	//画面端領域の生成
	CCollisionTerritory* pEndOfScreenBottomTerritory = new CCollisionTerritoryEndOfScreenBottom();
	//画面端領域と衝突した際のイベントコールバック設定
	pEndOfScreenBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//画面下端領域を取り付け
	pEndOfScreenArea->addTerritory(pEndOfScreenBottomTerritory);
	//画面左端領域の生成と取り付け
	pEndOfScreenArea->addTerritory(new CCollisionTerritoryEndOfScreenLeft());
	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pEndOfScreenArea);


	//マップ衝突空間の生成
	CCollisionArea* pMapArea = new CCollsionAreaMap(pChara->m_pBody , 64.0f , 128.0f);

	//マップチップ下領域の生成
	CCollisionTerritory* pMapChipBottomTerritory = new CCollisionTerritoryMapChipBottom();
	//マップチップ下領域と衝突した際のイベントコールバックを設定
	pMapChipBottomTerritory->setEventCallback(&CCharacter::collisionBottomCallback);
	//マップチップ下領域を取り付け
	pMapArea->addTerritory(pMapChipBottomTerritory);
	//マップチップ上領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipTop());
	//マップチップ右領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipRight());
	//マップチップ左領域の生成と取り付け
	pMapArea->addTerritory(new CCollisionTerritoryMapChipLeft());

	//画面端の衝突判定を取り付ける
	pChara->m_pCollisionAreas->push_back(pMapArea);
	
}

/**
*	@desc 状態遷移データの設定
*	@param 設定するキャラクター
*	@author Shinya Ueba
*/
void CBasePlayerBoyFactory::settingStateMachine(CPlayerCharacterBoy* pChara)
{
	
	//必要な状態を作成していく

	//===============================================================================
	// 少女との関係がフリーな状態のステートマシーン設定はここから
	//===============================================================================

	//取り付けるステートマシーンを生成する
	CStateMachine* pStateMachine = new CStateMachine();

	//右向き待機状態
	CStateBase* pIdleRightState = new CPlayerIdleRightState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::IDLE_RIGHT, pIdleRightState);

//------------------------------------------------------------------------------------------

	//左向き待機状態
	CStateBase* pIdleLeftState = new CPlayerIdleLeftState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::IDLE_LEFT, pIdleLeftState);

//------------------------------------------------------------------------------------------

	//右向き歩行状態
	CStateBase* pWalkRightState = new CPlayerWalkRightState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::WALK_RIGHT, pWalkRightState);

//------------------------------------------------------------------------------------------

	//左向き歩行状態
	CStateBase* pWalkLeftState = new CPlayerWalkLeftState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::WALK_LEFT, pWalkLeftState);

//------------------------------------------------------------------------------------------

	//右向きジャンプ状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_RIGHT, new CPlayerJumpRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向きジャンプ状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_LEFT, new CPlayerJumpLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向き落下状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::FALL_RIGHT, new CPlayerFallRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向き落下状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::FALL_LEFT, new CPlayerFallLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向き攻撃状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::ATTACK_RIGHT, new CPlayerAttackRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向き攻撃状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::ATTACK_LEFT, new CPlayerAttackLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向きジャンプ攻撃状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_ATTACK_RIGHT, new CPlayerJumpAttackRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向きジャンプ攻撃状態を作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::JUMP_ATTACK_LEFT, new CPlayerJumpAttackLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向き装備する状態
	CStateBase* pEquipRightState = new CPlayerEquipRightState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::EQUIP_RIGHT, pEquipRightState);

//------------------------------------------------------------------------------------------

	//左向き装備する状態
	CStateBase* pEquipLeftState = new CPlayerEquipLeftState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::EQUIP_LEFT, pEquipLeftState);

//------------------------------------------------------------------------------------------


	//右向き装備解除する状態
	CStateBase* pUnEquipRightState = new CPlayerUnEquipRightState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::UN_EQUIP_RIGHT, pUnEquipRightState);

//------------------------------------------------------------------------------------------

	//左向き装備解除する状態
	CStateBase* pUnEquipLeftState = new CPlayerUnEquipLeftState(pChara, NULL);
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::UN_EQUIP_LEFT, pUnEquipLeftState);

//------------------------------------------------------------------------------------------


	//右向き手を繋ぐ状態
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::GRASP_RIGHT, new CPlayerGraspRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向き手を繋ぐ状態
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::GRASP_LEFT, new CPlayerGraspLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向き手を繋ぐ状態
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::HOLD_RIGHT, new CPlayerHoldRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向き手を繋ぐ状態
	//作成した状態を登録していく
	pStateMachine->registerState((int)PLAYER_STATE::HOLD_LEFT, new CPlayerHoldLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------
	
	//プレイヤーに作成したステートマシーンを取り付ける
	(*pChara->m_pStateMachines)[(int)PLAYER_AND_GIRL_STATE::FREE] = pStateMachine;



	//===============================================================================
	// 少女との関係が手を握った状態のステートマシーン設定はここから
	//===============================================================================
	//取り付けるステートマシーンを生成する
	CStateMachine* pStateMachineGrips = new CStateMachine();


	//右向き手を繋いで待機する状態
	//作成した状態を登録していく
	pStateMachineGrips->registerState((int)PLAYER_STATE::IDLE_RIGHT, new CPlayerGraspIdleRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向き手を繋いで待機する状態
	//作成した状態を登録していく
	pStateMachineGrips->registerState((int)PLAYER_STATE::IDLE_LEFT, new CPlayerGraspIdleLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向き手を繋いで歩行する状態
	//作成した状態を登録していく
	pStateMachineGrips->registerState((int)PLAYER_STATE::WALK_RIGHT, new CPlayerGraspWalkRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向き手を繋いで歩行する状態
	//作成した状態を登録していく
	pStateMachineGrips->registerState((int)PLAYER_STATE::WALK_LEFT, new CPlayerGraspWalkLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------
	//左向き手を繋いで攻撃する状態
	//作成した状態を登録していく
	pStateMachineGrips->registerState((int)PLAYER_STATE::ATTACK_RIGHT, new CPlayerGrapsAttackRightState(pChara, NULL));

//------------------------------------------------------------------------------------------


	//左向き手を繋いで攻撃する状態
	//作成した状態を登録していく
	pStateMachineGrips->registerState((int)PLAYER_STATE::ATTACK_LEFT, new CPlayerGrapsAttackLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//プレイヤーに作成したステートマシーンを取り付ける
	(*pChara->m_pStateMachines)[(int)PLAYER_AND_GIRL_STATE::GRAPS_HANDS] = pStateMachineGrips;

	//===============================================================================
	// 少女との関係がお姫様抱っこ状態のステートマシーン設定はここから
	//===============================================================================
	//取り付けるステートマシーンを生成する
	CStateMachine* pStateMachineHold = new CStateMachine();


	//右向きお姫様抱っこで待機する状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::IDLE_RIGHT, new CPlayerHoldIdleRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向きお姫様抱っこで待機する状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::IDLE_LEFT, new CPlayerHoldIdleLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向きお姫様抱っこで歩行する状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::WALK_RIGHT, new CPlayerHoldWalkRightState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//左向きお姫様抱っこで歩行する状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::WALK_LEFT, new CPlayerHoldWalkLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------
	//右向きお姫様抱っこでジャンプする状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::JUMP_RIGHT, new CPlayerHoldJumpRightState(pChara, NULL));

//------------------------------------------------------------------------------------------


	//左向きお姫様抱っこでジャンプする状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::JUMP_LEFT, new CPlayerHoldJumpLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//右向きお姫様抱っこで落下する状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::FALL_RIGHT, new CPlayerHoldFallRightState(pChara, NULL));

//------------------------------------------------------------------------------------------


	//左向きお姫様抱っこで落下する状態
	//作成した状態を登録していく
	pStateMachineHold->registerState((int)PLAYER_STATE::FALL_LEFT, new CPlayerHoldFallLeftState(pChara, NULL));

//------------------------------------------------------------------------------------------

	//プレイヤーに作成したステートマシーンを取り付ける
	(*pChara->m_pStateMachines)[(int)PLAYER_AND_GIRL_STATE::HOLD_THE_PRINCESS] = pStateMachineHold;



	//少女との状態をFREEに変更
	pChara->m_playerAndGirlState = (int)PLAYER_AND_GIRL_STATE::FREE;
	//状態を待機状態に変更
	pChara->m_state = (int)PLAYER_STATE::IDLE_RIGHT;
	//最後に最初の状態を設定する！！！！！
	(*pChara->m_pStateMachines)[pChara->m_playerAndGirlState]->setStartState(pChara->m_state);
}

void CBasePlayerBoyFactory::settingInitialize(CPlayerCharacterBoy* pChara){

	//有効フラグを立てる
	pChara->m_activeFlag = true;

	//生死フラグを立てる
	pChara->m_isAlive = true;

	//大まかなタイプ別（キャラクタータイプ）
	pChara->m_charaType = (int)CHARACTER_TYPE::PLAYER_BOY;

	//細かなタイプ別（タグ）
	pChara->m_tag = TAG_PLAYER_1;

	/*
	 *　計算データのままで起動すると1フレームずれが発生するので
	 *　初期化時に最後に値をSpriteに反映する
	 */
	pChara->applyFunc();

}


//================================================
// 少年キャラクター生成工場を管理するクラス
//	（Singleton）
//
//	2016/12/22
//									Author Harada
//================================================
//共有のインスタンスの実体
CPlayerBoyFactoryManager* CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager = NULL;

//インスタンスの取得
CPlayerBoyFactoryManager* CPlayerBoyFactoryManager::getInstance() {

	if (CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager == NULL) {
		CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager = new CPlayerBoyFactoryManager();
	}

	return CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager;
}

//インスタンスの破棄
void CPlayerBoyFactoryManager::removeInstance() {
	if (CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager != NULL) {
		//共有インスタンスの削除
		SAFE_DELETE(CPlayerBoyFactoryManager::m_pPlayerBoyFactoryManager);
	}
}