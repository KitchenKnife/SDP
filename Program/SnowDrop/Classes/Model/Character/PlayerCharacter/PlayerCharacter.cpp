
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
	//this->inputFunc();

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



	//パーティクルアニメーション
	if (this->m_pGrapsMark)
	{
		this->m_counterGrapsMark--;

		if (this->m_counterGrapsMark <= 0)
		{
			this->m_pGrapsMark->removeFromParent();

			this->m_pGrapsMark = NULL;
		}
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
	if (this->m_pStateMachine)
	{
		this->m_pStateMachine->update();
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

}

/**
 * @desc 入力処理
 * @tips 移動処理で呼び出す
 */
void  CPlayerCharacterBoy::inputFunc() {

}

/**
*	@desc 手つなぎ可能マークの設定
*	@param パーティクルインスタンス
*	@author	Shinya Ueba
*/
void CPlayerCharacterBoy::setGrapsMark(cocos2d::CCParticleSystemQuad* const pGrapsMark)
{
	this->m_pGrapsMark = pGrapsMark;

	this->m_durationGrapsMark = 1.0f;
	this->m_pGrapsMark->setDuration(this->m_durationGrapsMark);
	this->m_counterGrapsMark = this->m_durationGrapsMark * 60;
}

/**
*	@desc 手つなぎ可能マークの設定
*	@param パーティクルインスタンス
*	@author	Shinya Ueba
*/
cocos2d::CCParticleSystemQuad* CPlayerCharacterBoy::getGrapsMark(void)
{
	return this->m_pGrapsMark;
}
