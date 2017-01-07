#include "GirlCharacter.h"
#include "Model\Character\Factory\CharacterFactory.h"
#include "Model\Character\CharacterAggregate.h"
#include "Data/Enum/EnumPlayer.h"
#include "Model/Character/PlayerCharacter/PlayerCharacter.h"

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


//移動処理
void CPlayerCharacterGirl::moveFunc() {

	//死んでたら飛ばす
	if (this->m_activeFlag == false)
		return;

	//アクション状態の更新処理
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
void CPlayerCharacterGirl::animationFunc() {

	//プレイヤーアニメーション
	(*this->m_pAnimations)[this->m_animationState]->update();

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

	//プレイヤーと少女の状態がフリーだったら
	if (this->m_pPlayerChara->m_playerAndGirlState == (int)PLAYER_AND_GIRL_STATE::FREE) {
		//プレイヤーとの距離を計測してパーティクルを生成するか判定する
		this->checkPlayerAndGirlActionMark();
	}

	//パーティクルアニメーション
	//パーティクルが存在していれば
	if (this->m_pActionMark)
	{
		//カウンター更新
		this->m_counterActionMark--;

		//カウンターが０以下になれば
		if (this->m_counterActionMark <= 0)
		{
			//パーティクルを外す
			this->m_pActionMark->removeFromParent();

			//パーティクル保管用変数にNULLを代入
			this->m_pActionMark = NULL;
		}
	}

	if(this->m_pStateMachine)
	{
		//状態遷移マシンの更新
		this->m_pStateMachine->update();
	}
}


//反映処理
void CPlayerCharacterGirl::applyFunc() {

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
bool CPlayerCharacterGirl::collision(CCharacter* pChara) {

	return true;
}

/**
 * @desc	他クラスから衝突判定を受けた際の処理
 * @param	キャラクターのアドレス
 */
void CPlayerCharacterGirl::hits(CCharacter* pChara) {

}

/**
 * @desc	プレイヤーと少女のアクション可能マークを出現させるかチェックする
 */
void CPlayerCharacterGirl::checkPlayerAndGirlActionMark(void) {
	//すでにマークが出現していたら処理しない
	if (this->m_pActionMark) {
		return;
	}
	//プレイヤーと少女の距離を計測
	float distanceToGirl = customMath->lengthBitweenChara(this->m_pPlayerChara, this);
	
	//距離が１００以下なら
	if (distanceToGirl <= 100.0f)
	{
		//パーティクルを生成し設定する。
		this->setPlayerAndGirlActionMark();
	}
}

/**
 * @desc	プレイヤーと少女のアクション可能マークが出ているか取得
 * @author	Shinya Ueba
 */
void CPlayerCharacterGirl::setPlayerAndGirlActionMark(void)
{
	//マークのパーティクルを生成
	cocos2d::CCParticleSystemQuad* pGrapsMark = cocos2d::CCParticleSystemQuad::create(PARTICLE_GRAPS_MARK);
	//パーティクルを始めっから再生させる
	pGrapsMark->resetSystem();
	//少女のパーティクル保管変数に代入
	this->m_pActionMark = pGrapsMark;

	//
	this->m_durationMark = 1.0f;
	this->m_pActionMark->setDuration(this->m_durationMark);
	this->m_counterActionMark = this->m_durationMark * 60;


	this->getParent()->addChild(this->m_pActionMark);
	if (this->m_pPlayerChara->m_pMove->m_pos.x <= this->m_pMove->m_pos.x)
	{
		this->m_pActionMark->setPosition(this->m_pMove->m_pos.x + this->m_pBody->m_left * 0.2f,this->m_pMove->m_pos.y);
	}
	else
	{
		this->m_pActionMark->setPosition(this->m_pMove->m_pos.x + this->m_pBody->m_right * 0.2f, this->m_pMove->m_pos.y);
	}
}

/**
 * @desc	プレイヤーと少女のアクション可能マークを作成してガールに取り付ける
 * @return	true...マークが出現している。
 * @author	Shinya Ueba
 */
bool CPlayerCharacterGirl::getPlayerAndGirlActionMark(void)
{
	if (this->m_pActionMark) {
		return true;
	}
	else {
		return false;
	}
}
