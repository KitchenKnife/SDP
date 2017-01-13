//==========================================
// ヘッダインクルード
//==========================================
#include "Model\Character\CharacterAggregate.h"

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
* @desc	キャラタクーの集まりの参照を設定
* @param	設定するキャラクターの集まりのアドレス
*/
void CCharacterAggregate::set(std::vector<CCharacter*>* pCharacters) {
	//引数のキャラクター群のアドレスを登録する
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

/**
* @desc プレイヤーキャラクターを設定
*/
void CCharacterAggregate::setPlayer(CPlayerCharacterBoy* const pPlayer)
{
	this->m_pPlayer = pPlayer;
}

/**
* @desc	ガールキャラクターを取得
*/
CPlayerCharacterBoy* CCharacterAggregate::getPlayer(void)
{
	return this->m_pPlayer;
}


/**
* @desc	ガールキャラクターを設定
*/
void CCharacterAggregate::setGirl(CPlayerCharacterGirl* const pGirl)
{
	this->m_pGirl = pGirl;
}

/**
* @desc	ガールキャラクターを取得
*/
CPlayerCharacterGirl* CCharacterAggregate::getGirl(void)
{
	return this->m_pGirl;
}

/**
* @desc	キャラクターを取り付けるレイヤーを設定
* @param キャラクターを取り付けるレイヤーのインスタンス
*/
void CCharacterAggregate::setLayer(cocos2d::Layer* pLayer)
{
	this->m_pLayer = pLayer;
}

/**
* @desc	キャラクターを取り付けるレイヤーを取得
* @return キャラクターを取り付けるレイヤーのインスタンス
*/
cocos2d::Layer* CCharacterAggregate::getLayer(void)
{
	return this->m_pLayer;
}
