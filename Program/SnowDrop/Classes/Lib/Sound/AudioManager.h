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

public:
	// �f�X�g���N�^
	~CAudioManager() {
		SAFE_DELETE(m_pSharedAudioManager);

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
	void removeInstance() {
		SAFE_DELETE(CAudioManager::m_pSharedAudioManager);
	}

	/*
	*	@desc	�Ώۉ��yID�̐ݒ�
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