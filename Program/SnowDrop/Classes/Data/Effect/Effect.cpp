/*
 * Effect.cpp
 *
 *	2016/11/25	Osumi
 *
 */
#include "Data/Effect/Effect.h"
//================================================
// 
// エフェクトの基底クラス
//
//	2016/12/22
//									Author Harada
//
//================================================
//コンストラクタ
CEffect::CEffect(){}

//デストラクタ
CEffect::~CEffect() {}
//初期化処理
bool CEffect::init(){

	if (CCharacter::init() == false) {
		CCLOG("スプライトクラスの初期化に失敗");
		return false;
	}

	return true;
}

/**
 * @desc	移動処理
 * @tips	何か特殊な動きをさせたい場合はこのクラスを継承して
 *			オーバーライドさせる
 */
void CEffect::moveFunc() {

	//物理計算
	for (CPhysical* pPhysical : (*this->m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CEffect::animationFunc() {

	//アニメーション更新
	(*this->m_pAnimations)[0]->update();

	//アニメーションの終了フラグを確認
	if ((*this->m_pAnimations)[0]->isEnd()) {
		//終了していればアクティブフラグを false に変更
		this->m_activeFlag = false;
	}
}

//衝突判定処理
void CEffect::collisionAll() {
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
void CEffect::checkState() {

}

//反映処理
void CEffect::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect((*this->m_pAnimations)[0]->getCurrentChip());

}

/**
 * @desc	キャラクター1体との衝突判定処理
 * @param	キャラクターのアドレス
 * @return	true...衝突した
 */
bool CEffect::collision(CCharacter* pChara) {
	return true;
}

/**
 * @desc	他クラスから衝突判定を受けた際の処理
 * @param	キャラクターのアドレス
 */
void CEffect::hits(CCharacter* pChara) {

}