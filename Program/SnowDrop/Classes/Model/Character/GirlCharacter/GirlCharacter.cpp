#include "GirlCharacter.h"

//====================================================
// 少女クラスのメンバ関数定義
//
//	2016/12/22
//									Author Harada
//									Author Shinya Ueba
//====================================================
//コンストラクタ
CPlayerCharacterGirl::CPlayerCharacterGirl() {}

//デストラクタ
CPlayerCharacterGirl::~CPlayerCharacterGirl() {}

//初期化処理
bool CPlayerCharacterGirl::init() {

	if (CCharacter::init() == false) {
		CCLOG("CCharacter初期化に失敗");
		return false;
	}

	return true;
}

/**
*	@desc 継承キャラクター個別の更新処理
*	@author Shinya Ueba
*/
void CPlayerCharacterGirl::updatePersonal(void)
{


}


//移動処理
void CPlayerCharacterGirl::moveFunc() {

	//死んでたら飛ばす
	if (this->m_activeFlag == false)
		return;

	//アクション状態の更新処理
	for (CAction* pAction : (*this->m_pActions)) {
		pAction->update(this);
	}

	//物理計算
	for (CPhysical* pPhysical : (*this->m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}


//アニメーション処理
void CPlayerCharacterGirl::animationFunc() {

	//プレイヤーアニメーション
	(*this->m_pAnimations)[this->m_state]->update();

}


//衝突判定処理
void CPlayerCharacterGirl::collisionAll() {
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


/**
*	@desc 状態のチェック
*	@author					Harada
*	@author					Shinya Ueba
*/
void CPlayerCharacterGirl::checkState() {

	if(this->m_pStateMachine)
	{
		//状態遷移マシンの更新
		this->m_pStateMachine->update();
	}
}


//反映処理
void  CPlayerCharacterGirl::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect((*this->m_pAnimations)[this->m_state]->getCurrentChip());
}


/**
 * @desc	キャラクター1体との衝突判定処理
 * @param	キャラクターのアドレス
 * @return	true...衝突した
 */
bool  CPlayerCharacterGirl::collision(CCharacter* pChara) {

	return true;
}

/**
 * @desc	他クラスから衝突判定を受けた際の処理
 * @param	キャラクターのアドレス
 */
void CPlayerCharacterGirl::hits(CCharacter* pChara) {

}
