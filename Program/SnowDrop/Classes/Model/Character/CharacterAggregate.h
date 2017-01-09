#pragma once
//==========================================
//
// File: CharacterAggregate.h
//
// キャラクターの集合体 ヘッダーファイル
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "Model\Character\PlayerCharacter\PlayerCharacter.h"
#include "Model\Character\GirlCharacter\GirlCharacter.h"



//=============================================
// キャラクターの集合体
//	シングルトン化させてほかのファイルで扱えるようにしておくこと
//
//	2016/12/22
//									Author Harada
//=============================================
class CCharacterAggregate {
private:
	//=============================================
	// シングルトン設定はここから
	//=============================================
	//共有インスタンス
	static CCharacterAggregate* m_pSareedAggregate;

	//コンストラクタ
	CCharacterAggregate();

public:
	//デストラクタ
	~CCharacterAggregate();

	//共有インスタンスの取得
	static CCharacterAggregate* getInstance();
	//共有インスタンスの破棄
	static void removeInstance();
	//=============================================
	// シングルトン設定はここまで
	//=============================================

private:
	//=============================================
	// Aggregate設定はここから
	//=============================================
	//キャラクターの集まり
	std::vector<CCharacter*>* m_pCharacters = NULL;

	//プレイヤー
	CPlayerCharacterBoy* m_pPlayer = NULL;

	//ガール
	CPlayerCharacterGirl* m_pGirl = NULL;

public:
	/**
	* @desc	キャラタクーの集まりの参照を設定
	* @param	設定するキャラクターの集まりのアドレス
	*/
	void set(std::vector<CCharacter*>* pCharacters);
	/**
	* @desc	キャラタクーの集まりの参照を変更
	* @param	設定するキャラクターの集まりのアドレス
	*/
	void change(std::vector<CCharacter*>* pCharacters);


	/**
	* @desc	キャラタクーの集まりのを取得
	* @return	キャラクターの集まり
	*/
	std::vector<CCharacter*>* get();

	/**
	* @desc	配列番号から指定したキャラタクー１体を取得
	* @param	添え字番号
	* @return	キャラクター
	*/
	CCharacter* getAt(int index);

	/**
	* @desc	タグから指定したキャラタクー１体を取得
	* @param	タグ
	* @return	キャラクター
	* @tips	存在しなければNULLを返す
	*/
	CCharacter* getAtTag(int tag);

	/**
	* @desc	キャラクターの追加
	* @param	追加するキャラクター
	*/
	void add(CCharacter* pCharacter);

	/**
	* @desc	キャラタクーの集まりの取り付けられている数を取得
	* @param	取り付けられている数
	*/
	int getSize();

	/**
	* @desc プレイヤーキャラクターを設定
	*/
	void setPlayer(CPlayerCharacterBoy* const pPlayer);

	/**
	* @desc	プレイヤーキャラクターを取得
	* @param プレイヤーキャラクター
	*/
	CPlayerCharacterBoy* getPlayer(void);


	/**
	* @desc	ガールキャラクターを設定
	* @param ガールのインスタンス
	*/
	void setGirl(CPlayerCharacterGirl* const pGirl);

	/**
	* @desc	ガールキャラクターを取得
	* @return ガールのインスタンス
	*/
	CPlayerCharacterGirl* getGirl(void);
};

