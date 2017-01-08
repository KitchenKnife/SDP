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

	// BGMの音量
	float m_BGMVolume;
	// 効果音の音量
	float m_SEVolume;

public:
	// デストラクタ
	~CAudioManager() {

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
	static void removeInstance() {
		SAFE_DELETE(CAudioManager::m_pSharedAudioManager);
	}

	/*
	*	@desc	BGMの音量設定
	*	@param　任意の音量
	*/
	void setBGMVolume(float volume) {
		this->m_BGMVolume = volume;
	}
	/*
	*	@desc	効果音の音量設定
	*	@param　任意の音量
	*/
	void setSEVolume(float volume) {
		this->m_SEVolume = volume;
	}
	/*
	*	@desc	効果音の音量の取得
	*/
	float getSEVolume() {
		return this->m_SEVolume;
	}

	/*
	*	@desc	対象音楽IDの登録
	*	@param	登録する音楽の名称
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