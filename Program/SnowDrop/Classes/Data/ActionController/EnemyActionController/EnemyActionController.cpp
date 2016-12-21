/*
* EnemyActionController.cpp
*
*	2016/12/20	Osumi
*
*/
#include "Data/ActionController/EnemyActionController/EnemyActionController.h"
#include "Model/Character/EnemyCharacter/EnemyCharacter.h"

//===================================================================
//　敵の動作の派生元
//===================================================================
/*
* @desc 2点間の距離を求める式
* @param 点1
* @param 点2
* @return 点1と点2の距離
*/
float CEnemyAction::length(cocos2d::Point pt1, cocos2d::Point pt2) {

	float length;
	length = sqrt(pow(pt1.x-pt2.x, 2)+ pow(pt1.y - pt2.y, 2));

	return length;
}

/*
* @desc 2体のキャラの距離を求める式
* @param　キャラ1
* @param　キャラ2
* @return キャラ1とキャラ2の距離
*/
float CEnemyAction::lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2) {
	
	float length  = this->length(pChara1->m_pMove->m_pos, pChara2->m_pMove->m_pos);

	return length;
}

/*
* @desc ターゲットの選択
* @return ターゲットが決まったかどうか　true...決まった
* @tips 少女と騎士で敵に近い方の距離を導き
*　　　 近い方が追跡範囲にならターゲットに設定
*/
bool CEnemyAction::seachAndSelectTarget(CCharacter* pChara) {
	CCharacter* pBoy = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	CCharacter* pGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	//敵と少年の距離
	float lemgthFromBoy = this->lengthBitweenChara(pChara,pBoy);
	//敵と少女の距離
	float lemgthFromGirl = this->lengthBitweenChara(pChara, pGirl);

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	//近い方が敵の追跡範囲内なら、近い方を敵のターゲットに設定
	if ((lemgthFromBoy < lemgthFromGirl)  && lemgthFromBoy <= pEne->m_chaseRange) {
		pEne->setTarget(pBoy);
		return true;
	}
	else if ((lemgthFromBoy >= lemgthFromGirl) && lemgthFromGirl <= pEne->m_chaseRange) {
		pEne->setTarget(pGirl); 
		return true;
	}

	return false;
}

/*
* @desc ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
* @param アクションを行うキャラクター
* @param ターゲットのタイプ
*/
void CEnemyAction::checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type) {

	CEnemyCharacter* pEne = (CEnemyCharacter*) pChara;

	//優先ターゲットが両方でなければ
	if (type != TARGET_TYPE::BOTH) {
		//ターゲットとの距離が追跡範囲内なら
		if (pEne->m_chaseRange >= this->lengthBitweenChara(pEne, pEne->m_currentTarget)) {
			//動作を停止
			this->stop();
			//敵を追跡状態に移行
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
	}
	//両方なら
	else {
		//ターゲットの検索と設定
		if (seachAndSelectTarget(pEne) == true) {
			//動作を停止
			this->stop();
			//敵を追跡状態に移行
			pEne->m_state = CEnemyCharacter::STATE::CHASE;
			pEne->m_pActions[pEne->m_state]->start();
		}
	}
}

/*
* @desc キャラからターゲットへのX方向の正規化ベクトルを求めて水平移動速度を設定
* @param アクションを行うキャラクター
* @param 目標地点の座標
*/
void CEnemyAction::normalizeVel_X(CCharacter* pChara, cocos2d::Point pt) {

	float nomalizevelX = (pt.x - pChara->m_pMove->m_pos.x) / abs(pt.x - pChara->m_pMove->m_pos.x);

	pChara->m_pMove->m_vel.x = pChara->m_pStatus->getSpeed()*nomalizevelX;
}

/*
* @desc 目標地点までの正規化ベクトルにキャラのスピードかけた値を設定する
* @param アクションを行うキャラクター
* @param 目標地点の座標
*/
void CEnemyAction::normalizeVel(CCharacter* pChara, cocos2d::Point pt){

	//ターゲットまでの距離を求める
	float length = this->length(pChara->m_pMove->m_pos, pt);
	float lengthX = pt.x - pChara->m_pMove->m_pos.x;
	float lengthY = pt.y - pChara->m_pMove->m_pos.y;

	//キャラクターのスピードに各成分の正規化ベクトルをかける
	float velX = (pChara->m_pStatus->getSpeed()*lengthX) / length;
	float velY = (pChara->m_pStatus->getSpeed()*lengthY) / length;

	pChara->m_pMove->m_vel.set(velX, velY);
}

//===================================================================
//　敵の待機動作 CEnemyActionStay
//===================================================================
//コンストラクタ
CEnemyActionStay::CEnemyActionStay(TARGET_TYPE type) {
	//コンストラクタでアクション中状態に設定
	this->m_inAction = true;

	//タイプを設定
	this->m_defaultTarget = type;
}

/*
* @desc 開始処理
*/
void CEnemyActionStay::start() {
	//アクション中状態に設定
	this->m_inAction = true;
}

/*
* @desc 更新処理
*/
void CEnemyActionStay::update(CCharacter* pChara) {

	//アクション中なら
	if (this->m_inAction == true) {

		// ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
		this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

/*
* @desc 終了処理処理
*/
void CEnemyActionStay::stop() {

	//フラグを全て下げる
	this->m_isStart = false;
	this->m_inAction = false;

}
//===================================================================
//　敵の時間経過による待機動作
//===================================================================
//コンストラクタ
CEnemyActionStayAtTime::CEnemyActionStayAtTime(TARGET_TYPE type): CEnemyActionStay(type){
	//コンストラクタでアクション開始状態に設定
	this->m_isStart = true;
}

/*
* @desc 開始処理
*/
void CEnemyActionStayAtTime::start() {
	//アクション開始状態に設定
	this->m_isStart = true;
}

/*
* @desc 更新処理
*/
void CEnemyActionStayAtTime::update(CCharacter* pChara) {

	//開始状態なら
	if (this->m_isStart == true) {
		//ランダムでアクション時間を設定(30~60)
		this->m_actionInterval = rand() % 30 + 31;

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
			//待機動作を終了
			this->stop();
			//さまよい行動に移行
			CEnemyCharacter* pEne = (CEnemyCharacter*) pChara;
			pEne->m_state = CEnemyCharacter::STATE::WANDERING;
			pEne->m_pActions[pEne->m_state]->start();
		}
		// ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
		this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

//===================================================================
//　敵のうろうろ動作
//===================================================================
//コンストラクタ
CEnemyActionWondering::CEnemyActionWondering(TARGET_TYPE type) {
	//コンストラクタでアクション開始状態に設定
	this->m_isStart = true;

	//タイプを設定
	this->m_defaultTarget = type;
}

/*
* @desc 開始処理
*/
void CEnemyActionWondering::start() {
	//アクション開始状態に設定
	this->m_isStart = true;
}

/*
* @desc 更新処理
*/
void CEnemyActionWondering::update(CCharacter* pChara) {
	
	//開始状態なら
	if (this->m_isStart == true) {
		//ランダムで歩く向きを設定
		this->m_vec = (rand() % 3) -1;
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
			pChara->m_pStatus->getSpeed()*this->m_vec,
			0.0f
		);

		//ランダムでアクション時間を設定(30~60)
		this->m_actionInterval = rand() % 30 + 31;

		//開始状態を離脱
		this->m_isStart = false;
		//アクション中状態に移行
		this->m_inAction = true;
	}

	//アクション中なら
	if (this->m_inAction == true ) {
		//カウンターをインクリメント
		this->m_actionCounter++;
		//カウンターがインターバル以上なら
		if(this->m_actionCounter >= this->m_actionInterval) {
			//カウンターをリセット
			this->m_actionCounter = 0;
			//開始状態に移行
			this->m_isStart = true;
			//アクション中状態から離脱
			this->m_inAction = false;
		}

		// ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
		this->checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

/*
* @desc 終了処理処理
*/
void CEnemyActionWondering::stop() {

	//フラグを全て下げる
	this->m_isStart = false;
	this->m_inAction = false;

}

//===================================================================
//　敵の追跡動作
//===================================================================
/*
* @desc コンストラクタ
* @param キャラクターが飛ぶかどうか（デフォルトはfalse）
*/
CEnemyActionChase::CEnemyActionChase(bool isFlying)
:m_isFlying(isFlying){}

/*
* @desc 開始処理
*/
void CEnemyActionChase::start() {
	this->m_inAction = true;
}

/*
* @desc 更新処理
* @param アクションを行うキャラクター
*/
void CEnemyActionChase::update(CCharacter* pChara) {

	CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;

	if (this->m_inAction == true) {
		//アクションを行うキャラが空を飛ばなければ
		if (this->m_isFlying == false) {
			//キャラからターゲットへのX方向の正規化ベクトルを求めて水平移動速度を設定
			this->normalizeVel_X(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
		else {
			// 目標地点までの正規化ベクトルにキャラのスピードかけた値を設定する
			this->normalizeVel(pEne, pEne->m_currentTarget->m_pMove->m_pos);
		}
	}

	//敵がある程度離れたらワンダリング状態に移行する
	if (pEne->m_chaseRange < this->lengthBitweenChara(pEne,pEne->m_currentTarget)) {
		this->stop();
		pEne->m_state = CEnemyCharacter::STATE::WANDERING;
		pEne->m_pActions[CEnemyCharacter::STATE::WANDERING]->start();
	}
}

/*
* @desc 終了処理処理
*/
void CEnemyActionChase::stop() {
	this->m_inAction = false;
}

//===================================================================
//　敵の出現地点に戻る動作 CEnemyActionReturnLanchPos
//===================================================================
/*
* @desc コンストラクタ
* @param 追跡すべきプレイヤータイプ
* @param 出現したキャラクター
*/
CEnemyActionReturnLanchPos::CEnemyActionReturnLanchPos(TARGET_TYPE type, CCharacter* pChara)
	:CEnemyActionStay(type), m_launchPos(pChara->m_pMove->m_pos){
	//コンストラクタでアクション中状態に設定
	this->m_inAction = true;
}

/*
* @desc 開始処理
*/
void CEnemyActionReturnLanchPos::start() {
	this->m_isStart = true;
}

/*
* @desc 更新処理
* @param アクションを行うキャラクター
*/
void CEnemyActionReturnLanchPos::update(CCharacter* pChara) {

	if (this->m_isStart == true) {
		// 目標地点までの正規化ベクトルにキャラのスピードかけた値を設定する
		this->normalizeVel(pChara, this->m_launchPos);

		//開始状態を離脱
		this->m_isStart = false;
		//アクション中状態に移行
		this->m_inAction = true;
	}

	if (this->m_inAction == true) {

		//出現位置までの距離を求める
		float length = this->length(this->m_launchPos, pChara->m_pMove->m_pos);
		//距離がある程度近ければ
		if (length <= 5) {
			//出現位置にキャラクターの位置を設定
			pChara->m_pMove->m_pos.set(this->m_launchPos.x, this->m_launchPos.y);
			//速度を0に設定
			pChara->m_pMove->m_vel.set(0.0f, 0.0f);
			//現在の動作の停止
			this->stop();
			//待機状態に移行
			CEnemyCharacter* pEne = (CEnemyCharacter*)pChara;
			pEne->m_state = CEnemyCharacter::STATE::STAY;
			pEne->m_pActions[pEne->m_state]->start();
		}

		//ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
		checkTargetAndSwitchChase(pChara, this->m_defaultTarget);
	}
}

/*
* @desc 終了処理処理
*/
void CEnemyActionReturnLanchPos::stop() {
	this->m_isStart = false;
	this->m_inAction = false;
}
