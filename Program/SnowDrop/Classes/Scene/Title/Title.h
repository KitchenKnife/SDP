#pragma once
//==========================================
//
// File: Title.h
//
// �^�C�g���V�[���t�@�C��
//
// 2016/12/21
//						Author Shinya Ueba
//
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"cocos2d.h"
#include"Constants.h"

//==========================================
//
// Class: CTitle
//
// �L�[�{�[�h���̓R���g���[���[�N���X
//
// 2016/12/18
//						Author Shinya Ueba
//==========================================
class CTitle : public cocos2d::Layer
{
public:
	/*
	* @desc �R���X�g���N�^
	*/
	CTitle();

	/*
	* @desc �f�X�g���N�^
	*/
	~CTitle();

	/**
	* @desc		�V�[���̐���
	* @return	CTitle���C���[�������V�[���N���X�C���X�^���X
	* @tips		�ÓI�����o�֐�
	*/
	static cocos2d::Scene* createScene();

	//create()�ÓI�����o�֐��̍쐬
	CREATE_FUNC(CTitle);

	/**
	* @desc ������
	* @return true...���� false...���s
	*/
	bool init() override;

	/**
	* @desc  �X�V����
	* @param �o�ߎ���
	*/
	void update(float deltaTime) override;

	/**
	* @desc		�Q�[�����C���ɑJ��
	* @param	�^�C�g�����C���[�̃C���X�^���X
	* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
	*/
	void callbackChangeGameMain(cocos2d::Ref* pSender);

	/*
	* @desc�@�Q�[���I��
	* @param �^�C�g�����C���[�̃C���X�^���X
	* @tips	 �Q�[���I���{�^���������ꂽ���ɌĂяo�����
	*/
	void callbackEndGame(cocos2d::Ref* pSender);
};


// ���y�}�l�[�W���[
class CAudioManager {
private:
	CAudioManager(){}

	// ���L�C���X�^���X
	static CAudioManager* m_pSharedAudioManager;

	// �Ώۉ��yID
	std::map<std::string,int> m_musicID;

public:
	// �f�X�g���N�^
	~CAudioManager(){
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




//EOF