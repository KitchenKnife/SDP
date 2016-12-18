
/*
* Character.cpp
*
*	2016/11/07	Osumi
*
*/
#include "Character.h"

using namespace cocos2d;

//コンストラクタ
CCharacter::CCharacter() {

}

//デストラクタ
CCharacter::~CCharacter() {

	SAFE_DELETE(this->m_pBody);

	if ((this->m_pActions) == NULL) {
		CCLOG(" ");
		return;
	}

	for (CAction* pAction: (*m_pActions)) {
		SAFE_DELETE(pAction);
	}
	SAFE_DELETE(this->m_pActions);

	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		SAFE_DELETE(pPhysical);
	}
	SAFE_DELETE(this->m_pPhysicals);

	SAFE_DELETE(this->m_pMove);

	for (CAnimation* pAnimation: (*m_pAnimations)) {
		SAFE_DELETE(pAnimation);
	}
	SAFE_DELETE(this->m_pAnimations);

	SAFE_DELETE(this->m_pStatus);

}

//初期化処理
bool CCharacter::init() {

	if (Sprite::init() == false) {
		CCLOG("Characterの初期化に失敗");
		return false;
	}

	//update()メンバ関数の呼び出し
	this->scheduleUpdate();

	return true;
}

//更新処理
void CCharacter::update(float deltaTime) {

	if ((this->m_pActions) == NULL) {
		CCLOG(" ");
		return;
	}

	//移動処理
	this->moveFunc();

	//アニメーション処理
	this->animationFunc();

	//衝突判定
	this->collisionAll();

	/*
	//画面範囲外判定処理
	this->endOfScreen();
	//マップチップとの衝突判定
	this->collisionMap();
	*/

	//状態チェック
	this->checkState();

	//反映処理
	this->applyFunc();
}

//=============================================
// キャラクターの集合体
//	シングルトン化させてほかのファイルで扱えるようにしておくこと
//=============================================
//共有インスタンスの本体
CCharacterAggregate* CCharacterAggregate::m_pSareedAggregate = NULL;

//コンストラクタ
CCharacterAggregate::CCharacterAggregate() {}


//デストラクタ
CCharacterAggregate::~CCharacterAggregate() {}

//共有インスタンスの取得
CCharacterAggregate* CCharacterAggregate::getInstance() {

	if (CCharacterAggregate::m_pSareedAggregate == NULL) {
		CCharacterAggregate::m_pSareedAggregate = new CCharacterAggregate();
	}

	return CCharacterAggregate::m_pSareedAggregate;
}
//共有インスタンスの破棄
void CCharacterAggregate::removeInstance() {
	SAFE_DELETE(CCharacterAggregate::m_pSareedAggregate);
}

/**
* @desc キャラタクーの集まりの参照を設定
* @param 設定するキャラクターの集まりのアドレス
*/
void CCharacterAggregate::set(std::vector<CCharacter*>* pCharacters) {
	//既に設定されていたら設定しないようにしておく
	if (this->m_pCharacters != NULL)
		return;

	this->m_pCharacters = pCharacters;

}

/**
* @desc キャラタクーの集まりのを取得
* @return キャラクターの集まり
*/
std::vector<CCharacter*>* CCharacterAggregate::get() {
	return this->m_pCharacters;
}

/**
* @desc キャラタクー１体を取得
* @param  添え字番号
* @return キャラクター
*/
CCharacter* CCharacterAggregate::getAt(int index) {

	//最大数以上ならNULLを返すように設定しておく
	if (this->m_pCharacters->size() <= index) {
		return NULL;
	}

	return (*this->m_pCharacters)[index];
}

/**
* @desc キャラタクー１体を取得
* @param  タグ
* @return キャラクター
*　　　　　存在しなければNULLを返す
*/
CCharacter* CCharacterAggregate::getAtTag(int tag) {

	for (CCharacter* pChara : (*this->m_pCharacters)) {
		if (pChara->m_tag == tag) {
			return pChara;
		}
	}

	//存在しなければNULLを返す
	return NULL;
}

/**
* @desc キャラタクーの追加
* @param  追加するキャラクター
*/
void CCharacterAggregate::add(CCharacter* pCharacter) {
	this->m_pCharacters->push_back(pCharacter);
}

/**
* @desc キャラタクーの集まりの取り付けられている数を取得
* @param  取り付けられている数
*/
int CCharacterAggregate::getSize() {
	return (int)this->m_pCharacters->size();
}