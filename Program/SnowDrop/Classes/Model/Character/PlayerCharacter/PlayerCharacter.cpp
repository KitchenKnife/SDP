
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
#include "Model\Character\CharacterAggregate.h"

//================================================	
//	少年クラスのメンバ関数のコードの追加はここから
//
//	2016/12/22
//									Author Harada
//================================================
//コンストラクタ
CPlayerCharacterBoy::CPlayerCharacterBoy() {}

//デストラクタ
CPlayerCharacterBoy::~CPlayerCharacterBoy() {
	
	//ステートマシーン群の削除
	std::map<int, CStateMachine*>::iterator itr = (*this->m_pStateMachines).begin();
	while (itr != (*this->m_pStateMachines).end()) {
		SAFE_DELETE(itr->second);

		itr++;
	}
	SAFE_DELETE(this->m_pStateMachines);
	
	//マップ型アニメーション群の削除
	std::map<int, CAnimation*>::iterator anim_itr = (*this->m_pMapAnimations).begin();
	while (anim_itr != (*this->m_pMapAnimations).end()) {
		SAFE_DELETE(anim_itr->second);
		
		anim_itr++;
	}
	SAFE_DELETE(this->m_pMapAnimations);
	
}

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
	//this->inputFunc();

	//アクションの更新処理
	if (this->m_mapAction[this->m_state])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_state])) {
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
	if ((*this->m_pMapAnimations)[this->m_state + this->m_playerAndGirlState + this->m_playerDirectionState])
	{
		(*this->m_pMapAnimations)[this->m_state + this->m_playerAndGirlState + this->m_playerDirectionState]->update();
	}
	
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
	if (this->m_pStateMachines)
	{
		(*this->m_pStateMachines)[this->m_playerAndGirlState]->update();
	}
}


//反映処理
void  CPlayerCharacterBoy::applyFunc() {
	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);


	//チップデータを反映
	this->setTextureRect((*this->m_pMapAnimations)[this->m_state + this->m_playerAndGirlState + this->m_playerDirectionState ]->getCurrentChip());

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