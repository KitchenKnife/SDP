
//==========================================
//
// File: AudioManager.cpp
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
#include "AudioManager.h"


// 共有インスタンス
CAudioManager* CAudioManager::m_pSharedAudioManager = NULL;

/*
*	@desc	フェードイン
*	@param	対象音楽の名称
*/
void CAudioManager::fadeIn(std::string musicName) {

	int musicID = this->getMusicID(musicName);

	float volume = AudioEngine::getVolume(musicID);

	// MAX Volume 出なければ足す
	if (volume < this->m_BGMVolume) {
		AudioEngine::setVolume(musicID, volume + 0.01f);
	}

}

/*
*	@desc	フェードアウト
*	@param	対象音楽の名称
*/
void CAudioManager::fadeOut(std::string musicName) {

	int musicID = this->getMusicID(musicName);

	float volume = AudioEngine::getVolume(musicID);

	// MAX Volume 出なければ足す
	if (volume > 0.0f) {
		AudioEngine::setVolume(musicID, volume - 0.01f);
	}
	else {
		// 音楽を止める
		AudioEngine::stop(musicID);
	}

}
