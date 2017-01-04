#include "Action.h"
#include "Model/Character/Character.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"


//===================================================================
//　敵のうろうろ動作
//===================================================================
//コンストラクタ
CActionWondering::CActionWondering() {
	//コンストラクタでアクション開始状態に設定
	this->m_isStart = true;

}

/*
* @desc 開始処理
*/
void CActionWondering::start() {
	//アクション開始状態に設定
	this->m_isStart = true;
}

/*
* @desc 更新処理
*/
void CActionWondering::update(CCharacter* pChara) {

	/*
	//開始状態なら
	if (this->m_isStart == true) {
		
		//ランダムで歩く向きを設定
		this->m_vec = (rand() % 3) - 1;
		if (this->m_vec == 0) {
			//動作を停止
			this->stop();
			//待機状態に移行
			CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;
			pEne->m_state = CEnemyCharacter::STATE::STAY;
			pEne->m_pActions[pEne->m_state]->start();
			
		}

		//速さを設定
		pChara->m_pMove->m_vel.set(
			pChara->m_status.getSpeed()*this->m_vec,
			0.0f
		);

		//開始状態を離脱
		this->m_isStart = false;
		//アクション中状態に移行
		this->m_inAction = true;
	}

	//アクション中なら
	if (this->m_inAction == true) {
		
		//カウンターをインクリメント
		this->m_actionCounter++;
		//カウンターがインターバル以上なら
		if (this->m_actionCounter >= this->m_actionInterval) {
			//カウンターをリセット
			this->m_actionCounter = 0;
			//開始状態に移行
			this->m_isStart = true;
			//アクション中状態から離脱
			this->m_inAction = false;
		}
		
		// ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
		//customMath->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
		
	}
	*/
}

/*
* @desc 終了処理処理
*/
void CActionWondering::stop() {

	//フラグを全て下げる
	this->m_isStart = false;
	this->m_inAction = false;

}

//===================================================================
//　敵の追跡動作
//===================================================================
/*
* @desc コンストラクタ
* @param キャラクターが飛ぶかどうか
*/
CActionChase::CActionChase(bool isFlying)
	:m_isFlying(isFlying) {}

/*
* @desc 開始処理
*/
void CActionChase::start() {
	this->m_inAction = true;
}

/*
* @desc 更新処理
* @param アクションを行うキャラクター
*/
void CActionChase::update(CCharacter* pChara) {

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	if (this->m_inAction == true) {
		//アクションを行うキャラが空を飛ばなければ
		if (this->m_isFlying == false) {
			//キャラからターゲットへのX方向の正規化ベクトルを求めて水平移動速度を設定
			customMath->normalizeVel_X(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
		else {
			// 目標地点までの正規化ベクトルにキャラのスピードかけた値を設定する
			customMath->normalizeVel(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
	}
}

/*
* @desc 終了処理処理
*/
void CActionChase::stop() {
	this->m_inAction = false;
}