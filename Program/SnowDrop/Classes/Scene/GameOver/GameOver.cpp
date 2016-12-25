//==========================================
//
// File: GameOver.cpp
//
// �Q�[���I�[�o�[�V�[���t�@�C��
//
// 2016/12/21
//						Author Koyuki Yamasaki
//==========================================

//==========================================
// �w�b�_�C���N���[�h
//==========================================
#include"GameOver.h"
#include"Constants.h"
#include "Scene\Title\Title.h"
#include "Lib/Sound/AudioManager.h"
using namespace cocos2d::experimental;

/*
* @desc �R���X�g���N�^
*/
CGameOver::CGameOver()
{

}

/*
* @desc �f�X�g���N�^
*/
CGameOver::~CGameOver()
{

}

/**
* @desc ������
* @return true...���� false...���s
*/
bool CGameOver::init()
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
	//�����ʒu�̐ݒ�((((((((�m�F�̈׈ʒu���炷)))))))
	pointerBackGround->setPosition(400.0f, 540.0f);
	//�g�k�T�C�Y��ݒ�
	pointerBackGround->setScale(0.5, 0.5);

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
		CC_CALLBACK_1(CGameOver::callbackChangeTitle, this)
	);

	//�ʒu�ݒ�
	pointerStartBtnItem->setPosition(WINDOW_RIGHT*0.5f, WINDOW_TOP*0.2f);


	//���j���[�̐����ƃ��j���[�A�C�e���̓o�^
	cocos2d::Menu* pointerMenu = cocos2d::Menu::create(pointerStartBtnItem, NULL);

	//�ʒu�̏�����
	pointerMenu->setPosition(0.0f, 0.0f);
	//���C���[�Ƀ��j���[��o�^����
	this->addChild(pointerMenu);


	// �^�C�g��BGM�̍Đ�
	int musicID = AudioEngine::play2d(SOUND_FILE_BGM_TITLE, true, 0.0f);
	// ID�ݒ�
	CAudioManager::getInstance()->setMusicID(BGM_TITLE, musicID);


	return true;
}
/**
* @desc		�V�[���̐���
* @return	CGameOver���C���[�������V�[���N���X�C���X�^���X
* @tips		�ÓI�����o�֐�
*/
cocos2d::Scene* CGameOver::createScene()
{
	//�V�[���̐���
	cocos2d::Scene* pScene = cocos2d::Scene::create();

	//CGameOver���C���[�̐���
	CGameOver* pLayer = CGameOver::create();

	//CGameOver���C���[���V�[���Ɏ��t����
	pScene->addChild(pLayer);

	//���������V�[����Ԃ�
	return pScene;
}

/**
* @desc  �X�V����
* @param �o�ߎ���
*/
void CGameOver::update(float deltaTime)
{
	//==============================================================================
	//
	// �����ɍX�V�����̃R�[�h��ǉ����Ă���
	//
	//==============================================================================
	CAudioManager::getInstance()->fadeIn(BGM_TITLE);



}

/**
* @desc		�Q�[�����C���ɑJ��
* @param	�Q�[���I�[�o�[���C���[�̃C���X�^���X
* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
*/
void CGameOver::callbackChangeTitle(cocos2d::Ref* pSender)
{
	// ���ʉ��Đ�
	int musicID = AudioEngine::play2d(SOUND_FILE_SE_BUTTON);
	//BGM��~
	AudioEngine::stop(CAudioManager::getInstance()->getMusicID(BGM_TITLE));

	// ���ʉ��Đ��I����
	AudioEngine::setFinishCallback(musicID, [](int musicID, const std::string) {

		//�V�[���𐶐�����
		cocos2d::Scene* pScene = CTitle::createScene();
		//�V�[����؂�ւ���
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionShrinkGrow::create(1.0f, pScene));

	});
}







//EOF