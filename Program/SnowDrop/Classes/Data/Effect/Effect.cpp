
#include "Data/Effect/Effect.h"

/*
 * Effect.cpp
 *
 *	2016/11/25	Osumi
 *
 */

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
CEffect::~CEffect() {
	//
	SAFE_DELETE(this->m_pAnimations);

	SAFE_DELETE(this->m_pMove);
}
//初期化処理
bool CEffect::init(){

	if (Sprite::init() == false) {
		CCLOG("スプライトクラスの初期化に失敗");
		return false;
	}

	//エフェクトの更新処理は独自で行うようにする。
	this->scheduleUpdate();

	return true;
}

//更新処理
void CEffect::update(float delta) {

	//移動処理
	this->moveFunc();

	//アニメーション処理
	this->animationFunc();

	//反映処理
	this->applyFunc();
}

/**
 * @desc	移動処理
 * @tips	何か特殊な動きをさせたい場合はこのクラスを継承して
 *			オーバーライドさせる
 */
void CEffect::moveFunc() {
	//処理なし。
}

//アニメーション処理
void CEffect::animationFunc() {

	//アニメーション更新
	this->m_pAnimations->update();

	//アニメーションの終了フラグを確認
	if (this->m_pAnimations->isEnd()) {
		//終了していればアクティブフラグを false に変更
		this->m_activeFlag = false;
	}
}

//反映処理
void CEffect::applyFunc() {

	//位置データを反映
	this->setPosition(this->m_pMove->m_pos);

	//チップデータを反映
	this->setTextureRect(this->m_pAnimations->getCurrentChip());

}



//=============================================
// エフェクト集合体
//=============================================
//共有インスタンスの本体
CEffectAggregate* CEffectAggregate::m_pSareedAggregate = NULL;

//コンストラクタ
CEffectAggregate::CEffectAggregate() {}

//デストラクタ
CEffectAggregate::~CEffectAggregate() {}

//共有インスタンスの取得
CEffectAggregate* CEffectAggregate::getInstance() {

	if (CEffectAggregate::m_pSareedAggregate == NULL) {
		CEffectAggregate::m_pSareedAggregate = new CEffectAggregate();
	}

	return CEffectAggregate::m_pSareedAggregate;
}

//共有インスタンスの破棄
void CEffectAggregate::removeInstance() {
	SAFE_DELETE(CEffectAggregate::m_pSareedAggregate);
}

/**
 * @desc	エフェクトの集まりの参照を設定 
 * @param	設定するエフェクトの集まりのアドレス
 */
void CEffectAggregate::set(std::vector<CEffect*>* pCharacters) {
	//既に設定されていたら設定しないようにしておく
	if (this->m_pEffects != NULL)
		return;

	//設定されていなければ引数のエフェクト群のアドレスを登録する
	this->m_pEffects = pCharacters;
}

/**
 * @desc	エフェクトの集まりのを取得
 * @return	エフェクトの集まり
 */
std::vector<CEffect*>* CEffectAggregate::get() {
	//エフェクト群のアドレスを返す
	return this->m_pEffects;
}

/**
 * @desc	配列番号から指定したエフェクト１つを取得
 * @param	添え字番号
 * @return	エフェクト
 */
CEffect* CEffectAggregate::getAt(int index) {

	//最大数以上ならNULLを返すように設定しておく
	if (this->m_pEffects->size() <= index) {
		return NULL;
	}

	//最大数以下ならその指定されたエフェクトを返す
	return (*this->m_pEffects)[index];
}

/**
 * @desc	エフェクトの追加
 * @param	追加するエフェクト
 */
void CEffectAggregate::add(CEffect* pEffe) {
	this->m_pEffects->push_back(pEffe);
}

/**
 * @desc	エフェクトの集まりの取り付けられている数を取得
 * @param	取り付けられている数
 */
int CEffectAggregate::getSize() {
	return (int)this->m_pEffects->size();
}