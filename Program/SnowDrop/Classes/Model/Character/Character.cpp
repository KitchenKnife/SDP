/*
 * Character.cpp
 *
 *	2016/11/07	Osumi
 *
 */
#include "Character.h"

//================================================
// キャラクタークラス
//		全てのキャラクターの雛形となる抽象クラス
//
//	2016/12/22
//									Author Harada
//================================================
//コンストラクタ
CCharacter::CCharacter() {}

//デストラクタ

/**
*	@desc デストラクタ
*	@autor	Osumi
*	@autor	Harada
*	@autor	Shinya Ueba
*/
CCharacter::~CCharacter() {

	//状態遷移データの削除
	SAFE_DELETE(this->m_pStateMachine);

	//実体データの削除
	SAFE_DELETE(this->m_pBody);

	//アクション群データの削除
	std::map<int, std::vector<CAction*>* >::iterator itr = this->m_mapAction.begin();
	while (itr != this->m_mapAction.end()) {

		if (itr->second)
		{
			std::vector<CAction*>* pActions = itr->second;

			for (CAction* pAction : *pActions)
			{
				SAFE_DELETE(pAction);
			}
			//クラスのインスタンスを削除
			SAFE_DELETE(itr->second);
		}
		//イテレーターを更新
		itr++;
	}

	//物理演算群データの削除
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		SAFE_DELETE(pPhysical);
	}
	SAFE_DELETE(this->m_pPhysicals);

	//移動データの削除
	SAFE_DELETE(this->m_pMove);


	//アニメーションデータ群の削除
	for (CAnimation* pAnimation: (*m_pAnimations)) {
		SAFE_DELETE(pAnimation);
	}
	SAFE_DELETE(this->m_pAnimations);
}

//初期化処理
bool CCharacter::init() {
	//スプライトの初期化
	if (Sprite::init() == false) {
		//初期化に失敗した場合
		CCLOG("Spriteの初期化に失敗");
		return false;
	}
	//個別に更新処理を起動させる。
	this->scheduleUpdate();

	//初期化に成功した場合
	return true;
}

//更新処理
void CCharacter::update(float deltaTime) {


	//移動処理
	this->moveFunc();

	//アニメーション処理
	this->animationFunc();

	//衝突判定
	this->collisionAll();

	//状態チェック
	this->checkState();

	//反映処理
	this->applyFunc();
}

//=============================================
// キャラクターの集合体
//	シングルトン化させてほかのファイルで扱えるようにしておくこと
//
//	2016/12/22
//									Author Harada
//=============================================
//共有インスタンスの本体
CCharacterAggregate* CCharacterAggregate::m_pSareedAggregate = NULL;

//コンストラクタ
CCharacterAggregate::CCharacterAggregate() {}

//デストラクタ
CCharacterAggregate::~CCharacterAggregate() {

	// キャラの解放
	for (CCharacter* pChara : (*this->m_pCharacters)) {
		SAFE_DELETE(pChara);
		}
	SAFE_DELETE(this->m_pCharacters);

}

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
 * @desc	キャラタクーの集まりの参照を設定
 * @param	設定するキャラクターの集まりのアドレス
 */
void CCharacterAggregate::set(std::vector<CCharacter*>* pCharacters) {
	//既に設定されていたら設定しないようにしておく
	if (this->m_pCharacters != NULL)
		return;

	//設定されていなければ引数のキャラクター群のアドレスを登録する
	this->m_pCharacters = pCharacters;
}

/**
 * @desc	キャラタクーの集まりのを取得
 * @return	キャラクターの集まり
 */
std::vector<CCharacter*>* CCharacterAggregate::get() {
	//キャラクター群のアドレスを返す
	return this->m_pCharacters;
}

/**
 * @desc	配列番号から指定したキャラタクー１体を取得
 * @param	添え字番号
 * @return	キャラクター
 */
CCharacter* CCharacterAggregate::getAt(int index) {

	//最大数以上ならNULLを返すように設定しておく
	if (this->m_pCharacters->size() <= index) {
		return NULL;
	}

	//最大数以下ならその指定されたキャラクターを返す
	return (*this->m_pCharacters)[index];
}

/**
 * @desc	タグから指定したキャラタクー１体を取得
 * @param	タグ
 * @return	キャラクター
 * @tips	存在しなければNULLを返す
 */
CCharacter* CCharacterAggregate::getAtTag(int tag) {
	//指定されたタグを保有するキャラクターがいるか検索する。
	for (CCharacter* pChara : (*this->m_pCharacters)) {
		//もし指定されたキャラクターがいればそのキャラクターを返す
		if (pChara->m_tag == tag) {
			return pChara;
		}
	}
	//存在しなければNULLを返す
	return NULL;
}

/**
 * @desc	キャラタクーの追加
 * @param	追加するキャラクター
 */
void CCharacterAggregate::add(CCharacter* pCharacter) {
	this->m_pCharacters->push_back(pCharacter);
}

/**
 * @desc	キャラタクーの集まりの取り付けられている数を取得
 * @param	取り付けられている数
 */
int CCharacterAggregate::getSize() {
	return (int)this->m_pCharacters->size();
}