//==========================================
//
// File: Title.cpp
//
// �^�C�g���V�[���t�@�C��
//
// 2016/12/21
//						Author Shinya Ueba
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"Title.h"
#include"Constants.h"
#include "Scene\GameMain\GameMain.h"
#include "Lib/Sound/AudioManager.h"
using namespace experimental;

/*
* @desc �R���X�g���N�^
*/
CTitle::CTitle()
{

}

/*
* @desc �f�X�g���N�^
*/
CTitle::~CTitle()
{

}

/**
* @desc ������
* @return true...���� false...���s
*/
bool CTitle::init()
{
	//��ꃌ�C���[�̏�����
	if (Layer::init() == false)
	{
		return false;
	}

	//update�֐�(�X�V�����֐�)�Ăяo���ݒ�
	this->scheduleUpdate();

	//�^�C�g���w�i�̐����Ǝ��t��
	cocos2d::Sprite* pointerBackGround = cocos2d::Sprite::create(IMAGE_TITLE);
	//�����ʒu�̐ݒ�
	pointerBackGround->setPosition(810.0f, 540.0f);
	//�g�k�T�C�Y��ݒ�
	pointerBackGround->setScale(0.5,0.5);
	
	//���C���[�Ɏ��t��
	this->addChild(pointerBackGround);

	/*
	* @desc		���j���[�A�C�e���̐����@�Q�[���J�n�{�^��
	* @param	�ʏ�̉摜��ݒ�
	* @param	�����ꂽ���̉摜��ݒ�
	* @param	�����ꂽ���ɌĂяo����郁���o�֐��̐ݒ�
	*/
	cocos2d::MenuItemImage* pointerStartBtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_START,
		IMAGE_TITLE_BUTTON_START,
		CC_CALLBACK_1(CTitle::callbackChangeGameMain, this)
	);

	//�ʒu�ݒ�
	pointerStartBtnItem->setPosition(WINDOW_RIGHT*0.5f, WINDOW_TOP*0.4f);
	
	
	/*
	* @desc		���j���[�A�C�e���̐����@�Q�[���I���{�^��
	* @param	�ʏ�̉摜��ݒ�
	* @param	�����ꂽ���̉摜��ݒ�
	* @param	�����ꂽ���ɌĂяo����郁���o�֐��̐ݒ�
	*/
	cocos2d::MenuItemImage* pointerEndBtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_END,
		IMAGE_TITLE_BUTTON_END,
		CC_CALLBACK_1(CTitle::callbackEndGame, this)
	);

	//�ʒu�ݒ�
	pointerEndBtnItem->setPosition(WINDOW_RIGHT*0.5f, WINDOW_TOP*0.2f);


	//���j���[�̐����ƃ��j���[�A�C�e���̓o�^
	cocos2d::Menu* pointerMenu = cocos2d::Menu::create(pointerStartBtnItem, pointerEndBtnItem, NULL);

	//�ʒu�̏�����
	pointerMenu->setPosition(0.0f, 0.0f);
	//���C���[�Ƀ��j���[��o�^����
	this->addChild(pointerMenu);


	// �^�C�g��BGM�̍Đ�
	int musicID = AudioEngine::play2d(SOUND_FILE_BGM_TITLE, true,0.0f);
	// ID�ݒ�
	CAudioManager::getInstance()->setMusicID("TitleBGM", musicID);
	
	
	return true;
}
/**
* @desc		�V�[���̐���
* @return	CTitle���C���[�������V�[���N���X�C���X�^���X
* @tips		�ÓI�����o�֐�
*/
cocos2d::Scene* CTitle::createScene()
{
	//�V�[���̐���
	cocos2d::Scene* pScene = cocos2d::Scene::create();

	//CTitle���C���[�̐���
	CTitle* pLayer = CTitle::create();

	//CTitle���C���[���V�[���Ɏ��t����
	pScene->addChild(pLayer);

	//���������V�[����Ԃ�
	return pScene;
}

/**
* @desc  �X�V����
* @param �o�ߎ���
*/
void CTitle::update(float deltaTime)
{
	//==============================================================================
	//
	// �����ɍX�V�����̃R�[�h��ǉ����Ă���
	//
	//==============================================================================
	CAudioManager::getInstance()->fadeIn("Title");



}

/**
* @desc		�Q�[�����C���ɑJ��
* @param	�^�C�g�����C���[�̃C���X�^���X
* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
*/
void CTitle::callbackChangeGameMain(cocos2d::Ref* pSender)
{
	// ���ʉ��Đ�
	int musicID = AudioEngine::play2d(SOUND_FILE_SE_BUTTON);
	//BGM��~
	AudioEngine::stop(CAudioManager::getInstance()->getMusicID("Title"));

	// ���ʉ��Đ��I����
	AudioEngine::setFinishCallback(musicID, [](int musicID,const std::string) {
		

		//�V�[���𐶐�����
		cocos2d::Scene* pScene = CGameMain::createScene();
		//�V�[����؂�ւ���
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionShrinkGrow::create(1.0f, pScene));

	});
}

/*
* @desc�@�Q�[���I��
* @param �^�C�g�����C���[�̃C���X�^���X
* @tips	 �Q�[���I���{�^���������ꂽ���ɌĂяo�����
*/
void CTitle::callbackEndGame(cocos2d::Ref* pSender)
{
	cocos2d::Director::getInstance()->end();
}







//EOF