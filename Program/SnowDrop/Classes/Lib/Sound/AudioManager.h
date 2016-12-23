#pragma once
//==========================================
//
// File: AudioManager.h
//
// 音楽マネージャーファイル
//
// 2016/12/23
//						Author Koyuki Yamasaki
//
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include"cocos2d.h"
#include"Constants.h"
#include <AudioEngine.h>

using namespace cocos2d::experimental;


// 音楽マネージャー
class CAudioManager {
private:
	CAudioManager() {}

	// 共有インスタンス
	static CAudioManager* m_pSharedAudioManager;

	// 対象音楽ID
	std::map<std::string, int> m_musicID;

public:
	// デストラクタ
	~CAudioManager() {
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