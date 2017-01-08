#pragma once
//==========================================
//
// File: AudioManager.h
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
#include"cocos2d.h"
#include"Constants.h"
#include <AudioEngine.h>

using namespace cocos2d::experimental;


// ���y�}�l�[�W���[
class CAudioManager {
private:
	CAudioManager() {}

	// ���L�C���X�^���X
	static CAudioManager* m_pSharedAudioManager;

	// �Ώۉ��yID
	std::map<std::string, int> m_musicID;

	// BGM�̉���
	float m_BGMVolume;
	// ���ʉ��̉���
	float m_SEVolume;

public:
	// �f�X�g���N�^
	~CAudioManager() {

		std::map<std::string, int>::iterator itr = this->m_musicID.begin();

		while (itr != this->m_musicID.end()) {
			itr->second = NULL;
			itr++;
		}
		this->m_musicID.clear();

	}

	// ���L�C���X�^���X�擾
	static CAudioManager* getInstance() {
		if (CAudioManager::m_pSharedAudioManager == NULL)
		{
			CAudioManager::m_pSharedAudioManager = new CAudioManager();
		}
		return CAudioManager::m_pSharedAudioManager;
	}

	// ���L�C���X�^���X�̔j��
	static void removeInstance() {
		SAFE_DELETE(CAudioManager::m_pSharedAudioManager);
	}

	/*
	*	@desc	BGM�̉��ʐݒ�
	*	@param�@�C�ӂ̉���
	*/
	void setBGMVolume(float volume) {
		this->m_BGMVolume = volume;
	}
	/*
	*	@desc	���ʉ��̉��ʐݒ�
	*	@param�@�C�ӂ̉���
	*/
	void setSEVolume(float volume) {
		this->m_SEVolume = volume;
	}
	/*
	*	@desc	���ʉ��̉��ʂ̎擾
	*/
	float getSEVolume() {
		return this->m_SEVolume;
	}

	/*
	*	@desc	�Ώۉ��yID�̓o�^
	*	@param	�o�^���鉹�y�̖���
	*	@param	�����������y��ID
	*/
	void setMusicID(std::string musicName, int musicID) {
		this->m_musicID[musicName] = musicID;
	}

	/*
	*	@desc	�Ώۉ��yID�̎擾
	*	@param	�����������y�̖���
	*	@return	�����������y��ID
	*/
	int getMusicID(std::string musicName) {
		return this->m_musicID[musicName];
	}

	/*
	*	@desc	�t�F�[�h�C��
	*	@param	�Ώۉ��y�̖���
	*/
	void fadeIn(std::string musicName);

	/*
	*	@desc	�t�F�[�h�A�E�g
	*	@param	�Ώۉ��y�̖���
	*/
	void fadeOut(std::string musicName);

};