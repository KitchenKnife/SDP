//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "GimmickCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"


//================================================	
//	ギミックキャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CGimmickCharacter::CGimmickCharacter() {
	//キャラクタータイプ
	this->m_charaType = (int)CHARACTER_TYPE::GIMMICK;
}

//デストラクタ
CGimmickCharacter::~CGimmickCharacter() {

}

//初期化処理
bool CGimmickCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("キャラクターの初期化に失敗");
		return false;
	}

	return true;
}

//移動処理
void CGimmickCharacter::moveFunc() {

	//取り付けらてるアクションの更新
	if (this->m_mapAction[this->m_actionState])
	{
		for (CAction* pAction : (*this->m_mapAction[this->m_actionState])) {
			pAction->update(this);
		}
	}

	//物理計算
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CGimmickCharacter::animationFunc() {

	//アニメーション
	(*this->m_pAnimations)[0]->update();
}

//衝突判定処理
void CGimmickCharacter::collisionAll() {

	//死んでいたら飛ばす
	if (this->m_isAlive == false)
		return;

	//空間との衝突判定を行う
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}
}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
void CGimmickCharacter::checkState() {

	//向きを判定
	if (this->m_pMove->m_vel.x != 0) {
		if (this->m_pMove->m_vel.x > 0) {
			//右向きに設定
			this->setScale(1.0f, 1.0f);
		}
		else {
			//左向きに設定
			this->setScale(-1.0f, 1.0f);
		}
	}
}

//反映処理
void CGimmickCharacter::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect((*this->m_pAnimations)[0]->getCurrentChip());

}

/**
* @desc 衝突してきた後の処理
* @param 衝突してきたキャラクター
*/
/**
void CGimmickCharacter::hits(CCharacter* pChara) {

	//死んでいたら飛ばす
	if (this->m_isAlive == false)
		return;

	//プレイヤーなら
	if (pChara->m_charaType == CHARACTER_TYPE::PLAYER) {
		this->hitsPlayerCharacter(pChara);
	}

	//プレイヤー以外なら
	if (pChara->m_charaType != CHARACTER_TYPE::PLAYER) {
		this->hitsNotPlayerCharacter(pChara);
	}
}
*/
//プレイヤーとの衝突判定後の処理
void CGimmickCharacter::hitsPlayerCharacter(CCharacter* pChara) {

	//プレイヤーの足元の位置
	float playerFeetPosY = pChara->m_pMove->m_pos.y + pChara->m_pBody->m_bottom;

	//敵の中心位置
	float enePosY = this->m_pMove->m_pos.y;

	//敵より上かどうか
	float posY = playerFeetPosY - enePosY;
	if (posY > 0.0f) {

		//上だった
		CCLOG("WIN");
		//敵の死亡フラグを立てる
		//つまり生きているか死んでいるかのフラグにfalseを入れる
		//this->m_isAlive = false;

		//速度をリセット
		pChara->m_pMove->m_vel.y = 0.0f;

		//====================================================
		// めり込んだ分戻す
		//====================================================
		//めり込んだ分の計算
		float boundary = (this->m_pMove->m_pos.y + this->m_pBody->m_top) - playerFeetPosY;
		//最終的に戻す値
		pChara->m_pMove->m_pos.y += (boundary);

		//プレイヤーを若干上に跳ね返す
		//pChara->m_pMove->m_vel.y = 3.0f;

		//====================================================
		// ジャンプアクションの再起動
		//===================================================
		//ジャンプアクションの再起動
		//(*pChara->m_pActions)[0]->restart(pChara);

		//敵キャラクターのアクションに敵死亡アクション
		(*pChara->m_mapAction[0])[0]->stop();
		//↑死亡フラグの操作も内包
		//↑ジャンプアクションの再起動も内包

	}
	else {

		//下だった
		CCLOG("FALSE");
	}

}

//プレイヤー以外との衝突判定後の処理
void CGimmickCharacter::hitsNotPlayerCharacter(CCharacter* pChara) {

	//敵キャラクターのアクションに敵死亡アクションを取り付ける
	(*this->m_mapAction[0])[0]->start();
	//↑死亡フラグの操作も内包

}

/**
* @desc キャラクター1体との衝突判定処理
* @param キャラクターのアドレス
* @return true...衝突した
*/
bool CGimmickCharacter::collision(CCharacter* pChara) {

	return true;
}



