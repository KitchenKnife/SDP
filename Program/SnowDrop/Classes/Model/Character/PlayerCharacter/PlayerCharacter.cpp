
/*
* PlayerCharacter.cpp
*
*	2016/12/1	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "PlayerCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Data\Enum\EnumPlayer.h"

//================================================	
//	少年クラスのメンバ関数のコードの追加はここから
//
//	2016/12/22
//									Author Harada
//================================================
//コンストラクタ
CPlayerCharacterBoy::CPlayerCharacterBoy() {}

//デストラクタ
CPlayerCharacterBoy::~CPlayerCharacterBoy() {}

//初期化処理
bool CPlayerCharacterBoy::init() {

	if (CCharacter::init() == false) {
		CCLOG("プレイヤーキャラクターの初期化に失敗");
		return false;
	}

	return true;
}

//移動処理
void CPlayerCharacterBoy::moveFunc() {

	//死んでたら飛ばす
	if (this->m_activeFlag == false)
		return;

	//入力処理
	this->inputFunc();

	//アクションの更新処理
	if (this->m_mapAction[this->m_actionState])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_actionState])) {
			pAction->update(this);
		}
	}

	
	//物理計算
	for (CPhysical* pPhysical : (*this->m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}


//アニメーション処理
void CPlayerCharacterBoy::animationFunc() {


	//プレイヤーアニメーション
	(*this->m_pAnimations)[this->m_animationState]->update();

}


//衝突判定処理
void CPlayerCharacterBoy::collisionAll() {
	//空間との衝突判定を行う
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}

	//全てのキャラクターとの衝突判定
	std::vector<CCharacter*>* pCharacters = CCharacterAggregate::getInstance()->get();
	for (CCharacter* pChara : (*pCharacters)) {
		//一体のキャラとの衝突判定
		this->collision(pChara);
	}
}

//状態チェック
void CPlayerCharacterBoy::checkState() 
{
	if (this->m_pStateMachine)
	{
		this->m_pStateMachine->update();
	}

	return;


	//状態の判定
	if (this->m_pMove->m_vel.x > 0) {
		//右歩行状態
//		m_playerState = (int)PLAYER_STATE::WALK_RIGHT;
		this->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_RIGHT;
	}
	else if (this->m_pMove->m_vel.x < 0) {
		//左歩行状態
//		m_playerState = (int)PLAYER_STATE::WALK_LEFT;
		this->m_animationState = (int)PLAYER_ANIMATION_STATE::WALK_LEFT;
	}
	else if (this->m_pMove->m_vel.y > 0.0f) {
		//ジャンプ状態
//		m_playerState = (int)PLAYER_STATE::JUMP;
	}
	else if (this->m_pMove->m_vel.y < 0.0f) {
		//落下状態
		m_playerState = (int)PLAYER_STATE::FALLING;
	}
	else {
		//待機状態
//		m_playerState = (int)PLAYER_STATE::STAND;

		this->m_animationState = (int)PLAYER_ANIMATION_STATE::IDLE_RIGHT;
	}
}


//反映処理
void  CPlayerCharacterBoy::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	

	//チップデータを反映
	this->setTextureRect((*this->m_pAnimations)[this->m_animationState]->getCurrentChip());
}


/**
 * @desc	キャラクター1体との衝突判定処理
 * @param	キャラクターのアドレス
 * @return	true...衝突した
 */
bool  CPlayerCharacterBoy::collision(CCharacter* pChara) {

	return true;
}

/**
 * @desc	他クラスから衝突判定を受けた際の処理
 * @param	キャラクターのアドレス
 */
void CPlayerCharacterBoy::hits(CCharacter* pChara) {

}

/**
* @desc 手をつなげる状態かチェック
* @param 相方（少女）
* @tips 手をつなげる状態なら"手つなぎフラグ"を上げる
* @author Osumi
* @author Shinya Ueba
*/
void CPlayerCharacterBoy::checkHoldHands(CPlayerCharacterGirl* pGirl) {
	
	/*
	//お互いの距離
	float length = sqrt(pow(this->m_pMove->m_pos.x - pCharacter->m_pMove->m_pos.x, 2.0) + pow(this->m_pMove->m_pos.y - pCharacter->m_pMove->m_pos.y, 2.0));

	//お互いの距離がある程度近ければお互いの"手つなぎフラグを上げる"
	if (length <= 45) {


		this->m_playerState = 

		WALK_LEFT = 1,	//左歩行
			WALK_RIGHT = 2,	//右歩行

		this->m_enableHoldHands = true;

		pCharacter->m_isShakeHands = true;
	}
	else
	{

	}*/
}

/**
 * @desc 入力処理
 * @tips 移動処理で呼び出す
 */
void  CPlayerCharacterBoy::inputFunc() {
	
	return;

	//入力コントローラーの取得
	CInputController* pointerInputController = CInputManager::getInstance()->getInputController();


	//左へ移動（歩行）
	if (pointerInputController->getLeftMoveFlag())
	{
		this->m_pMove->m_accele.x = -0.5f;
	}

	//右へ移動（歩行）
	if (pointerInputController->getRightMoveFlag())
	{
		this->m_pMove->m_accele.x = 0.5f;
	}

	if (!pointerInputController->getRightMoveFlag() && 
		!pointerInputController->getLeftMoveFlag())
	{
		this->m_pMove->m_accele.x = 0.0f;
	}
		
	if (pointerInputController->getJumpFlag() == true) 
	{
		//ジャンプを開始させる
	//	(*this->m_pActions)[(int)PLAYER_ACTION::JUMP]->start();
	}

	if (pointerInputController->getAttackFlag() == true) {
		//攻撃を開始させる。
	//	(*this->m_pActions)[(int)PLAYER_ACTION::ATTACK]->start();
	}

}