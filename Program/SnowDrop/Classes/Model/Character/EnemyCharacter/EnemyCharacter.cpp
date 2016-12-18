
/*
* EnemyCharacter.cpp
*
*	2016/11/11	Yamasaki
*
*/
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "EnemyCharacter.h"
#include "Lib/Input/InputManager.h"
#include "Model/Map/Map.h"
#include "Data/ActionController/ActionController.h"
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"


//================================================	
//	敵キャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CEnemyCharacter::CEnemyCharacter() {

}

//デストラクタ
CEnemyCharacter::~CEnemyCharacter() {

}

//初期化処理
bool CEnemyCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("キャラクターの初期化に失敗");
		return false;
	}

	return true;
}

/*
* @desc	初期化処理
* @param　初期化位置X
* @param　初期化位置Y
*/
bool CEnemyCharacter::init(float posX, float posY) {

	//キャラクタークラスの初期化
	if (CCharacter::init() == false) {
		CCLOG("キャラクターの初期化に失敗");
		return false;
	}

	return true;
}

// アクション処理
void CEnemyCharacter::actionFunc(CCharacter* pChara) {

	if (this->m_state != (int)STATE::ATTACK) {

		// 打撃攻撃
		//(*this->m_pActions)[(int)ACTION::BLOW_ATTACK]->start(pChara->m_pStatus);

	}
}


//移動処理
void CEnemyCharacter::moveFunc() {

	//ジャンプ移動計算
	(*this->m_pActions)[(int)ACTION::JUMP]->update(this);

	//ジャンプ移動計算
	(*this->m_pActions)[(int)ACTION::ATTACK]->update(this);

	//物理計算
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}

//アニメーション処理
void CEnemyCharacter::animationFunc() {

	//アニメーション
	(*this->m_pAnimations)[m_state]->update();
}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
void CEnemyCharacter::checkState() {

	//向きを判定
	if (this->m_pMove->m_vel.x != 0) {
		if (this->m_pMove->m_vel.x > 0) {
			//右向きに設定
			this->m_state = (int)STATE::WALK_RIGHT;
		}
		else {
			//左向きに設定
			this->m_state = (int)STATE::WALK_LEFT;
		}
	}

	//状態の判定
	if (this->m_pMove->m_vel.y > 0.0f) {

		//ｙ軸の速度がプラスということはジャンプしている状態
		m_state = (int)STATE::JUMPING;

	}
	else if (this->m_pMove->m_vel.y < 0.0f) {
		//ｙ軸の速度がマイナスといことは落ちている状態
		m_state = (int)STATE::FALING;
	}
	else if ((*this->m_pActions)[(int)ACTION::ATTACK]->getActionFlag()) {
	
		// 打撃攻撃中
		m_state = (int)STATE::ATTACK;

	}
	else if (this->m_pMove->m_vel.x > 0.0f) {
		//右に歩いている
		m_state = (int)STATE::WALK_RIGHT;
	}
	else if (this->m_pMove->m_vel.x < 0.0f) {
		//左に歩いている
		m_state = (int)STATE::WALK_LEFT;
	}
	else {
		//立っている
		m_state = (int)STATE::STAND;
	}

	// 現在のステートをログに表示
	CCLOG(" NowState = %d ,\nStand Jumping = 0,\nWalk = 1 ,\nHit = 2,\nFaling = 3,Attack = 4 ,\n", m_state);


}

//反映処理
void CEnemyCharacter::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect((*this->m_pAnimations)[m_state]->getCurrentChip());

}

/**
* @desc キャラクター1体との衝突判定処理
* @param キャラクターのアドレス
* @return true...衝突した
*/
bool CEnemyCharacter::collision(CCharacter* pChara) {

	//プレイヤーと敵の矩形を生成
	CCollisionRect pEnemyCollisionRect = CCollisionRect(*this->m_pBody, this->m_pMove->m_pos);

	CCollisionRect pPlayerCollisionRect = CCollisionRect(*pChara->m_pBody, pChara->m_pMove->m_pos);

	// 矩形と矩形の衝突判定
	return pEnemyCollisionRect.collision(&pPlayerCollisionRect);

}

/**
* @desc マップとの衝突判定
* @return true...衝突した
*/
/*
bool CEnemyCharacter::collisionMap() {

	//マップを取得
	CMap* pMap = CMapManager::getInstance()->getMap();

	//状態で判定するので一旦状態のチェックを行う
	this->checkState();


	//複数の点で判定する
	float byI = 6;
	for (int i = 1; i < byI; ++i) {
		//下に移動している場合に下に障害物があったら上に戻す
		if (this->m_pMove->m_vel.y < 0.0f) {
			//画像の幅を設定
			float width = abs(this->m_pBody->m_left) + abs(this->m_pBody->m_right);

			//キャラクターの位置から真下にある点の座標を取得
			Point pt(this->m_pMove->m_pos.x + this->m_pBody->m_left + (width * i / byI), this->m_pMove->m_pos.y + this->m_pBody->m_bottom);

			/*
			*　点が画面のどの座標にあるかを調べてその座標に
			*　マップチップが存在するかを調べマップチップが存在したら
			*　trueを返す。
			*
			if (pMap->hitTest(pt.x, pt.y)) {

				//ブロックのタイプを取得
				BLOCK_TYPE mapChipID = pMap->checkTile(pt.x, pt.y);

				if (mapChipID != BLOCK_TYPE::NONE) {

					//タイルのサイズ
					Size tileSize = pMap->getTileSize();

					//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロック数*ブロックの高さ
					float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

					//修正位置（キャラクターがめり込んでるブロックの下の位置）＝
					//キャラクターがめり込んでるブロックの下のブロックの位置　+　ブロック1個分　-位置ｙ
					float boundary = (pt.y) - (blockPos + tileSize.height);

					//めり込んでる分を修正
					this->m_pMove->m_pos.y -= boundary;

					//速度と加速度を0にする
					this->m_pMove->m_vel.y = 0.0f;
					this->m_pMove->m_accele.y = 0.0f;

				}
			}

		}

	}

	return true;

}
*/

//衝突判定処理
void CEnemyCharacter::collisionAll() {

	//死んでいたら飛ばす
	if (this->m_isAlive == false)
		return;

	//空間との衝突判定を行う
	for (CCollisionArea* pArea : (*this->m_pCollisionAreas)) {
		pArea->collision(this);
	}
}


