#pragma once
//==========================================
//
// File: Title.h
//
// タイトルシーンファイル
//
// 2016/12/21
//						Author Shinya Ueba
//
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"cocos2d.h"
#include"Constants.h"

//==========================================
//
// Class: CTitle
//
// キーボード入力コントローラークラス
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CTitle : public cocos2d::Layer
{
public:
	/*
	* @desc コンストラクタ
	*/
	CTitle();

	/*
	* @desc デストラクタ
	*/
	~CTitle();

	/**
	* @desc		シーンの生成
	* @return	CTitleレイヤーを内包したシーンクラスインスタンス
	* @tips		静的メンバ関数
	*/
	static cocos2d::Scene* createScene();

	//create()静的メンバ関数の作成
	CREATE_FUNC(CTitle);

	/**
	* @desc 初期化
	* @return true...成功 false...失敗
	*/
	bool init() override;

	/**
	* @desc  更新処理
	* @param 経過時間
	*/
	void update(float deltaTime) override;

	/**
	* @desc		ゲームメインに遷移
	* @param	タイトルレイヤーのインスタンス
	* @tips		スタートボタンが押された時に呼び出される
	*/
	void callbackChangeGameMain(cocos2d::Ref* pSender);

	/*
	* @desc　ゲーム終了
	* @param タイトルレイヤーのインスタンス
	* @tips	 ゲーム終了ボタンが押された時に呼び出される
	*/
	void callbackEndGame(cocos2d::Ref* pSender);
};


// 音楽マネージャー
class CAudioManager {
private:
	CAudioManager(){}

	// 共有インスタンス
	static CAudioManager* m_pSharedAudioManager;

	// 対象音楽ID
	std::map<std::string,int> m_musicID;

public:
	// デストラクタ
	~CAudioManager(){
		SAFE_DELETE(m_pSharedAudioManager);

		std::map<std::string, int>::iterator itr = this->m_musicID.begin();

		while (itr != this->m_musicID.end()) {
			itr->second = NULL;
			itr++;
		}
		this->m_musicID.clear();

	}

	// 共有インスタンス取得
	static CAudioManager* getInstance() {
		if (CAudioManager::m_pSharedAudioManager == NULL)
		{
			CAudioManager::m_pSharedAudioManager = new CAudioManager();
		}
		return CAudioManager::m_pSharedAudioManager;
	}

	// 共有インスタンスの破棄
	void removeInstance() {
		SAFE_DELETE(CAudioManager::m_pSharedAudioManager);
	}

	/*
	*	@desc	対象音楽IDの設定
	*	@param	扱いたい音楽のID
	*/
	void setMusicID(std::string musicName, int musicID) {
		this->m_musicID[musicName] = musicID;
	}

	/*
	*	@desc	対象音楽IDの取得
	*	@param	扱いたい音楽の名称
	*	@return	扱いたい音楽のID
	*/
	int getMusicID(std::string musicName) {
		return this->m_musicID[musicName];
	}

	/*
	*	@desc	フェードイン
	*	@param	対象音楽の名称
	*/
	void fadeIn(std::string musicName);

	/*
	*	@desc	フェードアウト
	*	@param	対象音楽の名称
	*/
	void fadeOut(std::string musicName);

};




//EOF