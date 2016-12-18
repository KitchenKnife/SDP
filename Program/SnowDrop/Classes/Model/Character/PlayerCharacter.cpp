
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
#include "Model/Map/Map.h"
#include "Model/Character/PlayerFactory.h"
#include "Data/Effect/PlayerEffect/PlayerEffectFactory.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeapon.h"
#include "Model/Weapon/PlayerWeapon/PlayerWeaponFactory.h"
#include "Data/ActionController/PlayerActionController/PlayerWeaponActionController/PlayerWeaponActionController.h"
#include "Scene/GameMain/GameMain.h"

//================================================	
//	プレイヤーキャラクターのメンバ関数のコードの追加はここから
//================================================
//コンストラクタ
CPlayerCharacter::CPlayerCharacter() {

}

//デストラクタ
CPlayerCharacter::~CPlayerCharacter() {
	//アニメーション群の解放
	std::map<STATE, CAnimation*>::iterator animeItr = this->m_mapAnimations.begin();
	while (animeItr != this->m_mapAnimations.end()) {
		SAFE_DELETE(animeItr->second);
		animeItr++;
	}
	this->m_mapAnimations.clear();

	//アニメーション群の解放
	std::map<ACTION, CAction*>::iterator actItr = this->m_mapActions.begin();
	while (actItr != this->m_mapActions.end()) {
		SAFE_DELETE(actItr->second);
		actItr++;
	}
	this->m_mapActions.clear();

	//エフェクト群の解放
	for (CPlayerEffect* pEffect : (*m_pEffects)) {
		SAFE_DELETE(pEffect);
	}

	//武器の解放
	CPlayerNormalWeapon::removeInstance();

}

//初期化処理
bool CPlayerCharacter::init() {

	if (CCharacter::init() == false) {
		CCLOG("プレイヤーキャラクターの初期化に失敗");
		return false;
	}

	//================================================	
	//	プレイヤーキャラクターのメンバ関数のコードの追加はここから
	//================================================
	
	//ベクターのアニメーション群の生成
	this->m_pAnimations = new std::vector<CAnimation*>;

	//ベクターのアクション群の生成
	this->m_pActions = new std::vector<CAction*>;
	
	
	//================================================	
	//	値の設定に関するコードの追加はここから
	//================================================


	return true;
}


//更新処理
void CPlayerCharacter::update(float deltaTime) {


	//x軸の加速度の初期化
	this->m_pMove->m_accele.x = 0.0f;

	//移動処理
	this->moveFunc();

	//エフェクトの更新処理
	this->effectUpdate();

	//死んでたらここで飛ばす
	if (this->m_isAlive == false)
		return;


	//アニメーション処理
	this->animationFunc();

	//衝突判定
	this->collisionAll();

	//状態チェック
	this->checkState();

	//有効フラグの確認とその後の処理
	this->checkActiveFlagAndFunc();

	//反映処理
	this->applyFunc();
	

}

/**
* @desc 手をつなげる状態かチェック
* @param 相方（少女）
* @tips 手をつなげる状態なら"手つなぎフラグ"を上げる
*/
void CPlayerCharacter::checkSakeHands(CPlayerCharacter* pCharacter) {
	//お互いの距離
	float length = sqrt(pow(this->m_pMove->m_pos.x - pCharacter->m_pMove->m_pos.x, 2.0) + pow(this->m_pMove->m_pos.y - pCharacter->m_pMove->m_pos.y, 2.0));

	//お互いの距離がある程度近ければお互いの"手つなぎフラグを上げる"
	if (length <= 45) {
		this->m_isShakeHands = true;
		pCharacter->m_isShakeHands = true;
	}

}

//アニメーション処理
void CPlayerCharacter::animationFunc() {

	//プレイヤーアニメーション
	(this->m_mapAnimations)[m_playerState]->update();

}

/**
* @desc 画面範囲外判定処理
* @tips こういった実装の仕方はこれからは少なくして行くように
*		心がけよう。
*		どのようにすれば汎用的に、つまり他のキャラクターでも使いまわしできるかを
*		考えて実装していこう
*/
/*
void  CPlayerCharacter::endOfScreen() {

	
	//左に移動している場合は画面左で止めるようにする
	if (this->m_pMove->m_vel.x < 0.0f  &&  this->m_pMove->m_pos.x + this->m_pBody->m_left < WINDOW_LEFT) {
		//設定　修正値
		auto boundary = (this->m_pMove->m_pos.x + this->m_pBody->m_left) - WINDOW_LEFT;
		this->m_pMove->m_pos.x -= boundary;

		//速度と加速度を0にするかはゲームによって変わる
		this->m_pMove->m_vel.x = 0.0f;
		this->m_pMove->m_accele.x = 0.0f;
	}
	
	/*
	//右に移動している場合は画面右で止めるようにする
	if (this->m_pMove->m_vel.x > 0.0f  &&  this->m_pMove->m_pos.x + this->m_pBody->m_right > WINDOW_RIGHT) {
		//設定　修正値
		auto boundary = (this->m_pMove->m_pos.x + this->m_pBody->m_right) - WINDOW_RIGHT;
		this->m_pMove->m_pos.x -= boundary;

		//速度と加速度を0にするかはゲームによって変わる
		this->m_pMove->m_vel.x = 0.0f;
		this->m_pMove->m_accele.x = 0.0f;
	}
	*

	//画面下で止めるようにする
	if (this->m_pMove->m_pos.y + this->m_pBody->m_bottom < WINDOW_BOTTOM) {
		//設定　修正値
		auto boundary = (this->m_pMove->m_pos.y + this->m_pBody->m_bottom - WINDOW_BOTTOM);
		this->m_pMove->m_pos.y -= boundary;

		//速度と加速度を0にするかはゲームによって変わる
		this->m_pMove->m_vel.y = 0.0f;
		this->m_pMove->m_accele.y = 0.0f;

		//ジャンプを停止させる
		(this->m_mapActions)[CPlayerCharacter::ACTION::JUMP]->stop();
	}

}
*/

//反映処理
void  CPlayerCharacter::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect(this->m_mapAnimations[m_playerState]->getCurrentChip());
}

/**
* @desc キャラクター1体との衝突判定処理
* @param キャラクターのアドレス
* @return true...衝突した
*/
bool  CPlayerCharacter::collision(CCharacter* pChara) {
	
	return true;
}

//衝突判定処理
void CPlayerCharacter::collisionAll() {
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


//エフェクトの更新処理
void CPlayerCharacter::effectUpdate() {
	

	if (this->m_pEffects != NULL){

		std::vector<CPlayerEffect*>::iterator eftItr = (*this->m_pEffects).begin();

		while (eftItr != (*this->m_pEffects).end()) {

			//有効フラグが下りてたら
			if ((*eftItr)->m_activeFlag == false) {

				//レイヤーから取り外す
				(*eftItr)->removeFromParent();
				//プレイヤーから取り外す
				eftItr = (*this->m_pEffects).erase(eftItr);
			}
			else{
				//更新処理
				(*eftItr)->update();
				eftItr++;
			}
		}
	}

}

//エフェクトの取り外し
void CPlayerCharacter::removeEffect(CPlayerEffect* pEffect) {
	SAFE_DELETE(pEffect);
}

//有効フラグの確認とその後の処理
void CPlayerCharacter::checkActiveFlagAndFunc() {
	CStatus* pStatus = this->m_pStatus;

	if (pStatus->getHp() <= 0) {
		pStatus->set(0, pStatus->getmaxHp(), pStatus->getAttackPt());
		this->m_isAlive = false;
		this->setVisible(false);
	}

	if (this->m_isAlive == true) {
		this->setVisible(true);
	}
}

//================================================	
//	少年クラスのメンバ関数のコードの追加はここから
//================================================
//共有インスタンス
CPlayerBoy* CPlayerBoy::m_pBoy = NULL;

//インスタンスの取得
CPlayerBoy* CPlayerBoy::getInstance() {
	if (CPlayerBoy::m_pBoy == NULL) {
		CPlayerBoy::m_pBoy =  (CPlayerBoy*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);
	}
	return CPlayerBoy::m_pBoy;
}

//コンストラクタ
CPlayerBoy::CPlayerBoy() {

}

//デストラクタ
CPlayerBoy::~CPlayerBoy() {

	if (m_pWeapon != NULL);
	//武器の解放
	//SAFE_DELETE(m_pWeapon);

}

//初期化処理
bool CPlayerBoy::init() {

	if (CPlayerCharacter::init() == false) {
		CCLOG("プレイヤーキャラクターの初期化に失敗");
		return false;
	}

	//================================================	
	//	プレイヤーキャラクターのメンバ関数のコードの追加はここから
	//================================================


	//================================================	
	//	値の設定に関するコードの追加はここから
	//================================================
	if (this != NULL) {
		CCLOG("");
	}

	return true;
}


//エフェクトのプレイヤーへの取り付け
void CPlayerBoy::jointEffect(CPlayerCharacter::EFFECT effectType) {

	cocos2d::Point boyPt = this->m_pMove->m_pos;

	//エフェクトの生成
	CPlayerEffect* pEffect
		= CPlayerEffectFactoryManager::getInstance()->create((int)effectType, boyPt);

	//エフェクトのレイヤーへの取り付け
	pEffect->jointToLayer(CGameMain::m_pMainLayer);
	//エフェクトのプレイヤーへの取り付け
	(this->m_pEffects)->push_back(pEffect);
}

//武器の装備
void CPlayerBoy::equipWeapon() {

	//武器の生成
	CPlayerWeapon* pWeapon = CPlayerWeaponFactoryManager::getInstance()->create(WEAPON_TYPE::NORMAL);
	//タグ付け
	pWeapon->m_tag = TAG_WEAPON_1;
	//CCharacterAggregateにプレイヤーを追加
	CCharacterAggregate::getInstance()->add(pWeapon);
	//武器の取り付け
	pWeapon->addChildPlayer(this);
	//武器のプレイヤーへの取り付け
	this->m_pWeapon = pWeapon;
}

//少女との距離
float CPlayerBoy::lengthFromGirl() {

	//少女の取得
	CCharacter* pPlayerGirl = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	cocos2d::Point boyPt = this->m_pMove->m_pos;
	cocos2d::Point girlPt = pPlayerGirl->m_pMove->m_pos;

	float length = sqrt( pow((boyPt.x- girlPt.x),2)+pow((boyPt.y - girlPt.y),2));

	return length;
}


//消失状態のチェック（カウンターのデクリメントも担当）
void CPlayerBoy::checkDisappear() {

	this->m_disappearCounter--;
	//ある程度距離が離れてて、消失カウンターが0以下なら
	if (this->lengthFromGirl() >= 200.0f && this->m_disappearCounter<= 0) {
		//カウンターのリセット
		this->m_disappearCounter = this->m_disappearInterval;
		//エフェクトの取り付け
		this->jointEffect(EFFECT::DISAPPEAR);
		//HPの減少
		this->m_pStatus->decreaseHP(1);
	}
}


//移動処理
void CPlayerBoy::moveFunc() {

	/*
	*　入力処理
	*		今回入力は、入力による移動というカテゴリで扱う
	*/
	this->inputFunc();


	//死んでたら飛ばす
	if (this->m_activeFlag == false)
		return;

	/*
	if (this->m_playerAct == ACTION::ATTACK) {
		this->m_pWeapon->update();
	}
	*/
	this->m_pWeapon->update();

	//アクション状態に応じた更新処理
	(this->m_mapActions)[this->m_playerAct]->update(this);
	
	
	//物理計算
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}


	//移動計算
	this->m_pMove->moveBy();

}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
void CPlayerBoy::checkState() {

	if (this->m_playerState == STATE::LIFT_UPING)
		return;

	
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

	if (this->m_playerAct == ACTION::ATTACK)
		return;

	//状態の判定
	if (this->m_pMove->m_vel.y > 0.0f) {

		//ｙ軸の速度がプラスといことはジャンプしている状態
		m_playerState = STATE::JUMPING;

	}
	else if (this->m_pMove->m_vel.y < 0.0f) {
		//ｙ軸の速度がマイナスといことは落ちている状態
		m_playerState = STATE::FALING;
	}
	else if (this->m_pMove->m_vel.x != 0.0f) {
		//歩いている
		m_playerState = STATE::WALK;
	}
	else {
		//立っている
		m_playerState = STATE::STAND;
	}

	//消失状態のチェック
	this->checkDisappear();

}

//更新処理
void  CPlayerBoy::update(float deltaTime) {

	//キャラクタークラスの更新処理の呼び出し
	//CPlayerCharacter::update(deltaTime);


	//x軸の加速度の初期化
	this->m_pMove->m_accele.x = 0.0f;

	//移動処理
	this->moveFunc();

	//エフェクトの更新処理
	this->effectUpdate();

	//死んでたらここで飛ばす
	if (this->m_isAlive == false)
		return;


	//アニメーション処理
	this->animationFunc();

	//衝突判定
	this->collisionAll();

	//状態チェック
	this->checkState();

	//有効フラグの確認とその後の処理
	this->checkActiveFlagAndFunc();

	//反映処理
	this->applyFunc();
}

/**
* @desc 入力処理
* @tips 移動処理で呼び出す
*/
void  CPlayerBoy::inputFunc() {

	//受付拒否状態なら抜ける
	if(m_nonInputFlag == true && this->m_activeFlag== true) {
		return;
	}

	if (this->m_isAlive == true) {

		if (inputflag.m_left == true) {
			this->m_pMove->m_accele.x = -0.5f;
		}

		if (inputflag.m_right == true) {
			this->m_pMove->m_accele.x = 0.5f;
		}

		
		if (inputflag.m_up == true) {
			//手をつないでなければ
			if (this->m_isShakeHands == false) {

				this->m_playerAct = ACTION::JUMP;

				//ジャンプを開始させる
				(this->m_mapActions)[ACTION::JUMP]->start();
			}
		}

		if (inputflag.m_space == true) {
			if (this->m_spaceKeyDown == false) {

				this->m_spaceKeyDown = true;

				//少女の取得
				CPlayerGirl* pPlayerGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

				//手をつなげる状態かチェック
				this->checkSakeHands(pPlayerGirl);
			}
		}else {
			this->m_spaceKeyDown = false;

		}

		if (inputflag.m_z == true ) {
			if (this->m_zKeyDown == false) {

				this->m_zKeyDown = true;
				if (this->m_pWeapon->m_attackAnime == CPlayerWeapon::ATTACK_ANIME::RETURN) {
					//手を放す
					this->removeHands();

					//this->m_pWeapon->m_attackAnime = CPlayerWeapon::ATTACK_ANIME::DRAWN;
					//this->m_pWeapon->m_attackAct = CPlayerWeapon::ATTACK_ACT::NONE;//::DRAWN;

					this->m_playerState = STATE::DRAWN_STAND;
					this->m_playerAct = ACTION::ATTACK;
					
				}
				
			}
		}else {
			this->m_zKeyDown = false;

		}
	}

	//死んでたら復活（デバック用）
	else {
		if (inputflag.m_space == true) {
			if (this->m_spaceKeyDown == false) {

				this->m_spaceKeyDown = true;
				this->m_isAlive = true;
				this->m_pStatus->recoveryHp();
			}
		}
		else {
			this->m_spaceKeyDown = false;

		}
	}

}

/**
* @desc 手をつなげる状態かチェック
* @param 相方（少女）
* @tips 手をつなげる状態なら"手つなぎフラグ"を上げる
*/
void CPlayerBoy::checkSakeHands(CPlayerCharacter* pGirl) {

	if (this->m_isShakeHands == true) {
		this->removeHands();
		return;
	}

	//お互いの距離
	float length = sqrt(pow(this->m_pMove->m_pos.x - pGirl->m_pMove->m_pos.x, 2.0) + pow(this->m_pMove->m_pos.y - pGirl->m_pMove->m_pos.y, 2.0));

	float lengthY = (this->m_pMove->m_pos.y + this->m_pBody->m_bottom) - (pGirl->m_pMove->m_pos.y + pGirl->m_pBody->m_bottom);

	//お互いの距離がある程度近ければお互いの"手つなぎフラグを上げる"
	if (length <= 50) {

		this->m_isShakeHands = true;
		//武器の納刀
		this->m_pWeapon->returnSword();

		CPlayerGirl*pGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);
		pGirl->m_mapActions[pGirl->m_playerAct]->stop();

		if (lengthY >= 32 && this->m_pMove->m_vel.y == 0) {
			
			this->m_playerAct = ACTION::LIFT_UP;
			this->m_playerState = STATE::LIFT_UPING;
			return;
		}

		return;
	}
}

/**
* @desc お互いの手を放す
*/
void CPlayerBoy::removeHands() {
	CPlayerGirl*pGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	this->m_isShakeHands = false;
	pGirl->m_isShakeHands = false;
}

//================================================
// 少女クラスのメンバ関数のコードの追加はここから
//================================================
//共有インスタンス
CPlayerGirl* CPlayerGirl::m_pGirl = NULL;

//インスタンスの取得
CPlayerGirl* CPlayerGirl::getInstance() {
	if (CPlayerGirl::m_pGirl == NULL) {
		//CPlayerGirl::m_pGirl = (CPlayerGirl*)CPlayerFactoryManager::getInstance()->create(PLAYER_TYPE::GIRL);
		CPlayerGirl::m_pGirl = (CPlayerGirl*)CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_2);

	}
	return CPlayerGirl::m_pGirl;
}

//コンストラクタ
CPlayerGirl::CPlayerGirl() {

}

//デストラクタ
CPlayerGirl::~CPlayerGirl() {

}

//初期化処理
bool CPlayerGirl::init() {

	if (CPlayerCharacter::init() == false) {
		CCLOG("プレイヤーキャラクターの初期化に失敗");
		return false;
	}

	//================================================	
	//	プレイヤーキャラクターのメンバ関数のコードの追加はここから
	//================================================


	//================================================	
	//	値の設定に関するコードの追加はここから
	//================================================

	return true;
}

//更新処理
void  CPlayerGirl::update(float deltaTime) {


	if (this->m_pMove->m_vel.x != 0) {
		CCLOG("%f,%f", this->m_pMove->m_vel.x, this->m_pMove->m_vel.y);
		CCLOG("!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	//キャラクタークラスの更新処理の呼び出し
	CPlayerCharacter::update(deltaTime);

}

/**
* @desc 状態チェック
* @tips 値をチェックして現在の状態を変更する
*/
void CPlayerGirl::checkState() {

	if (this->m_playerState == STATE::LIFT_UPING)
		return;

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

	//状態の判定
	if (this->m_pMove->m_vel.y > 0.0f) {

		//ｙ軸の速度がプラスといことはジャンプしている状態
		m_playerState = STATE::JUMPING;

	}
	else if (this->m_pMove->m_vel.y < 0.0f && this->m_wasteActFlag == false) {
		//ｙ軸の速度がマイナスといことは落ちている状態
		m_playerState = STATE::FALING;
	}
	else if (this->m_pMove->m_vel.x != 0.0f) {
		//歩いている
		m_playerState = STATE::WALK;
	}
	else if(this->m_wasteActFlag == false){
		//立っている(暇つぶしカウンター起動)
		
		this->m_mapActions[ACTION::WASTE]->start();
	}

}

//移動処理
void CPlayerGirl::moveFunc() {

	/*
	*　入力処理は行はない
	*/
	//this->inputFunc();
	
	if(this->m_isShakeHands == false  && CPlayerBoy::getInstance()->m_isShakeHands ==true)
	//少年に向かってい近づく処理
	closeWithBoyFunc(&CPlayerBoy::getInstance()->m_pMove->m_pos);

	if (this->m_isShakeHands == true)
	//少年についていく処理
	goWithBoyFunc(&CPlayerBoy::getInstance()->m_pMove->m_pos);

	
	//暇つぶし
	if (CPlayerBoy::getInstance()->m_isShakeHands == true || this->m_playerState == STATE::HIT) {

 		this->m_mapActions[ACTION::WASTE]->stop();
	}
	
	//アクション状態に応じた行動
	this->m_mapActions[this->m_playerAct]->update(this);
	
	//物理計算
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		pPhysical->update(this->m_pMove);
	}

	//移動計算
	this->m_pMove->moveBy();
}

/**
* @desc 少年に向かってい近づく処理
* @param	少年の位置
*/
void  CPlayerGirl::closeWithBoyFunc(Point* pPos) {

	//お互いのｘ軸上の距離
	float length = (pPos->x - this->m_pMove->m_pos.x);
	
	//距離から少年のいる向きを導く
	int vectol = length / abs(length);

	//距離が空いていれば
	if (abs(length) >= 64) {
		//少年の向きに加速
		this->m_pMove->m_accele.x = 0.65f*vectol;
	}

	//ある程度近づけば”手つなぎフラグを上げる”
	if (abs(length) <= 35){
		this->m_isShakeHands = true;
	}


}

/**
* @desc 少年についていく処理
* @param	少年の位置
*/
void CPlayerGirl::goWithBoyFunc(Point* pPos) {

	//少年の移動用データを取得
	CMove* pBoyMove = CPlayerBoy::getInstance()->m_pMove;

	//お互いのｘ軸上の距離
	float length = (pPos->x - this->m_pMove->m_pos.x);

	//少女から見た少年のいる向き
	int vectolToBoy = length / abs(length);

	//少年から見た少女のいる向き
	int vectolToGirl = -1.0f*vectolToBoy;

	//ある程度距離が空きそうなら
	//少女の位置を少年の後ろに調整
	if (abs(length) >= 32.0) {
		//画像の向きを合わせるために速度を設定
		this->m_pMove->m_pos.x = pBoyMove->m_pos.x - (85* vectolToBoy);
		this->m_pMove->m_vel.x = pBoyMove->m_vel.x;

		//this->m_pMove->m_pos.x = pBoyMove->m_pos.x - (vectolToGirl*32.0f);
	}
	//少年が少女のいる側に移動してたら
	else if(vectolToGirl == pBoyMove->m_vel.x/abs(pBoyMove->m_vel.x)) {

		this->m_pMove->m_vel.x = 0;
	}

}