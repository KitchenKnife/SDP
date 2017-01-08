
//==========================================
//
// File: AudioManager.cpp
//
// ���y�}�l�[�W���[�t�@�C��
//
// 2016/12/23
//						Author Koyuki Yamasaki
//
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include "AudioManager.h"


// ���L�C���X�^���X
CAudioManager* CAudioManager::m_pSharedAudioManager = NULL;

/*
*	@desc	�t�F�[�h�C��
*	@param	�Ώۉ��y�̖���
*/
void CAudioManager::fadeIn(std::string musicName) {

	int musicID = this->getMusicID(musicName);

	float volume = AudioEngine::getVolume(musicID);

	// MAX Volume �o�Ȃ���Α���
	if (volume < this->m_BGMVolume) {
		AudioEngine::setVolume(musicID, volume + 0.01f);
	}

}

/*
*	@desc	�t�F�[�h�A�E�g
*	@param	�Ώۉ��y�̖���
*/
void CAudioManager::fadeOut(std::string musicName) {

	int musicID = this->getMusicID(musicName);

	float volume = AudioEngine::getVolume(musicID);

	// MAX Volume �o�Ȃ���Α���
	if (volume > 0.0f) {
		AudioEngine::setVolume(musicID, volume - 0.01f);
	}
	else {
		// ���y���~�߂�
		AudioEngine::stop(musicID);
	}

}
