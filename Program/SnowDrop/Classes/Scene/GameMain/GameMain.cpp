/*
* GameMain.cpp
*
*	2016/11/10	Osumi
*
*/

#include "GameMain.h"
#include "Model/Map/Map.h"

//�v���C���[�H��
#include "Model/Character/Factory/PlayerFactory.h"

//�����H��
#include "Model/Character/Factory/GirlCharacterFactory.h"

//�G�H��
#include "Model/Character/Factory/EnemyFactory.h"

//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
// Deback

#include "Model/Character/Factory/DamageFactory.h"
#include "Data/LaunchData/LaunchData.h"

//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P

//�G�t�F�N�g�H��
#include "Model/Character/Factory/EffectFactory.h"

//�M�~�b�N�H��
#include "Model/Character/Factory/GimmickFactory.h"

//�v���C���[�̕���A�N�V����

// ����
#include "Lib/Input/InputManager.h"
// ���������p
#include <stdlib.h>
#include <time.h>
// �T�E���h�p
#include "Lib/Sound/AudioManager.h"

// �Q�[���I�[�o�[�V�[��
#include "Scene/GameOver/GameOver.h"
//==================================================
// �@�ÓI�����o�ϐ��̎���
//==================================================
Layer* CGameMain::m_pMainLayer = NULL;

/**
 *	@desc	�V�[���̐���
 *	@return	CMain ���C���[�������V�[���N���X�C���X�^���X
 *	@tips	�ÓI�����o�֐�
 */
cocos2d::Scene* CGameMain::createScene() {
	
	// �V�[���̐���
	cocos2d::Scene* pScene = cocos2d::Scene::create();
	
	// GameMain ���C���[�̐���
	CGameMain* pLayer = CGameMain::create() ;
	
	// CMain ���C���[���V�[���Ɏ��t����
	pScene->addChild( pLayer, 0, TAG_GAME_MAIN ) ;
	
	// ���������V�[����Ԃ�
	return pScene ;
}

/**
 *	@desc	�L�[�{�[�h�̃L�[���������ۂ̃C�x���g
 *	@param	�L�[�R�[�h
 *	@param	�C�x���g
 */
void CGameMain::onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event ) {

	// ���͊Ǘ��ɓ��͏������ϑ�
	CInputManager::getInstance()->onKeyPressed( keyCode ) ;
}

/**
 *	@desc	�L�[�{�[�h�̃L�[�𗣂����ۂ̃C�x���g
 *	@param	�L�[�R�[�h
 *	@param	�C�x���g
 */
void CGameMain::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event ) {

	// ���͊Ǘ��ɓ��͏������ϑ�
	CInputManager::getInstance()->onKeyReleased( keyCode ) ;
}

// �f�X�g���N�^
CGameMain::~CGameMain() {
	// �_���[�W�H��̍폜
	CDamageFactoryManager::getInstance()->removeInstance();
	// �}�b�v�̍폜
	CMapManager::getInstance()->removeInstance();
	// �L�����̍폜
	CCharacterAggregate::getInstance()->removeInstance();
	// �g���K�[�폜
	CLaunchScheduler::getInstance()->removeInstance();

	//�v���C���[�H��̍폜
	CPlayerBoyFactoryManager::getInstance()->removeInstance();
	//�����H��̍폜
	CPlayerGirlFactoryManager::getInstance()->removeInstance();
	//�G�����H��̍폜
	CEnemyFactoryManager::getInstance()->removeInstance();
	//�G�t�F�N�g�H��̍폜
	CEffectFactoryManager::getInstance()->removeInstance();
	//�M�~�b�N�H��̍폜
	CGimmickFactoryManager::getInstance()->removeInstance();
}



/**
 *	@desc	������
 *	@return	true...����	false...���s
 */
bool CGameMain::init() {

	// �e���C���[�̏�����
	if ( Layer::init() == false ) {
		return false ;
	}

	// ��������
	srand( (unsigned int)time( NULL ) ) ;
	
	// �L�[�{�[�h���̓C�x���g�󂯎��ݒ�
	this->setKeyboardEnabled(true) ;
	
	// update �֐� ( �X�V�����֐� ) �Ăяo���ݒ�
	// ���̕�������������R�����g�A�E�g����� update �֐����Ă΂�Ȃ��Ȃ�̂Œ���
	this->scheduleUpdate() ;
	
	
	//=========================================================================
	//
	//	�������珉�����A�����ݒ�̃R�[�h��ǉ�
	//
	//=========================================================================

	//�L�����N�^�[�̏W�܂�̐���
	this->m_pCharacters = new std::vector<CCharacter*>();
	//�L�����N�^�[�̏W�܂��CCharacterAggregate�ɐݒ肷��
	CCharacterAggregate::getInstance()->set(this->m_pCharacters);

	//�o���X�P�W���[���̐���
	this->m_pLaunchSchedule = new std::vector<CLaunchTrigger*>();
	//�o���X�P�W���[�����o���X�P�W���[���Ɏ��t����
	CLaunchScheduler::getInstance()->createLauncher(this->m_pLaunchSchedule);

	//���C�����C���[�̐����Ǝ��t��
	this->m_pMainLayer = Layer::create();
	this->addChild(this->m_pMainLayer);

	//UI���C���[�̐����Ǝ��t��
	this->m_pUILayer = Layer::create();
	this->addChild(this->m_pUILayer,-1);

	
	//�w�i�̐����Ǝ��t��
	this->m_pBackGround = Sprite::create();
	this->m_pBackGround->setTexture(IMAGE_BACK_GROUND);
	this->m_pBackGround->setPosition(WINDOW_RIGHT*0.5, WINDOW_TOP*0.5);
	this->m_pMainLayer->addChild(this->m_pBackGround);
	

	//�}�b�v�̐����Ǝ��t��
	this->m_pMainLayer->addChild(CMapManager::getInstance()->createMap(MAP_DATA_SAMPLE));

	
	//�n�����̐����Ǝ��t��
	this->m_pHrizon = Sprite::create();
	this->m_pHrizon->setTexture(IMAGE_BACK_HORIZON);
	this->m_pHrizon->setPosition(WINDOW_RIGHT*0.5, WINDOW_TOP*0.5);
	this->m_pMainLayer->addChild(this->m_pHrizon);
	

	
	// �v���C���[�̐���
	CCharacter* pPlayerChara = CPlayerBoyFactoryManager::getInstance()->create((int)PLAYER_TYPE::BASE);
	//CCharacterAggregate�Ƀv���C���[��ǉ�
	CCharacterAggregate::getInstance()->add(pPlayerChara);
	//���t��
	this->m_pMainLayer->addChild(pPlayerChara);


	// �����̐����Ǝ��t��
	CCharacter* playerGirl = CPlayerGirlFactoryManager::getInstance()->create((int)GIRL_TYPE::BASE);
	
	
	//CCharacterAggregate�Ƀv���C���[��ǉ�
	CCharacterAggregate::getInstance()->add(playerGirl);

	playerGirl->m_pMove->m_pos.set(1200,500);

	//���t��
	this->m_pMainLayer->addChild(playerGirl);


	//������ʂɂ���G�̐���
	CMapManager::getInstance()->getMap()->initCheckEnemyLaunch();
	//�S�̂̊g��
	this->setScale(SCALE_MAIN);
	//�g��ɔ�����ʈʒu�̐ݒ�
	this->setPosition((SCREEN_WIDTH*(SCALE_MAIN-1))/2, (SCREEN_HEIGHT*(SCALE_MAIN-1))/2);


	//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
	// �����@�f�o�b�N�p�@�����[�X�������܂�
	//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
	/*
	* @desc		���j���[�A�C�e���̐����@�Q�[���J�n�{�^��
	* @param	�ʏ�̉摜��ݒ�
	* @param	�����ꂽ���̉摜��ݒ�
	* @param	�����ꂽ���ɌĂяo����郁���o�֐��̐ݒ�
	*/
	cocos2d::MenuItemImage* pointerStartBtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_END,
		IMAGE_TITLE_BUTTON_END,
		CC_CALLBACK_1(CGameMain::callbackChangeGameOver, this)
	);

	//�ʒu�ݒ�
	pointerStartBtnItem->setPosition(WINDOW_RIGHT*0.9f, WINDOW_TOP*0.1f);
	//���j���[�̐����ƃ��j���[�A�C�e���̓o�^
	cocos2d::Menu* pointerMenu = cocos2d::Menu::create(pointerStartBtnItem, NULL);

	//�ʒu�̏�����
	pointerMenu->setPosition(0.0f, 0.0f);
	//���C���[�Ƀ��j���[��o�^����
	this->addChild(pointerMenu);

	//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
	// �f�o�b�N�p�����@�����܂�
	//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P




	// BGM�̍Đ�
	int musicID = AudioEngine::play2d(SOUND_FILE_BGM_STAGE_FIRST, true, 0.0f);
	// ID�ݒ�
	CAudioManager::getInstance()->setMusicID(BGM_STAGE1, musicID);


	//=========================================================================
	//
	//	�����܂łɏ������A�����ݒ�̃R�[�h��ǉ�
	//
	//=========================================================================

	return true ;
	
}


/*
* @desc ��ʃX�N���[��
* @tips ����͋����X�N���[���ł͂Ȃ��L�����N�^�[�̈ړ��ɂ���ʂ̃X�N���[���ƂȂ�
*/
void CGameMain::scroll() {

	//�}�b�v�̈ʒu���擾
	Point pt = this->m_pMainLayer->getPosition();

	//�v���C���[�L�����N�^�[�̎擾
	CCharacter* pPlayerChara = CCharacterAggregate::getInstance()->getAtTag(TAG_PLAYER_1);

	
	//�v���C���[�̈ʒu��320.0���𒴂�����
	if (pt.x > WINDOW_RIGHT * 3/5 - pPlayerChara->m_pMove->m_pos.x) {
		//���_�𒴂������ɐݒ肷��
		pt.x = WINDOW_RIGHT * 3/5 - pPlayerChara->m_pMove->m_pos.x;


		//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
		// �_���[�W�L���������m�F
		//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
		//�o���f�[�^���쐬
		CDamageLaunchData* pLaunchData = new CDamageLaunchData(pPlayerChara, 3);

		//�o���g���K�[�𐶐����A�_���[�W�o���f�[�^��ݒ�
		CDamageLaunchTrigger* pTrigger = new CDamageLaunchTrigger(pLaunchData);

		//�o���g���K�[���o���X�P�W���[���Ƃ��Ēǉ�����
		CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

		//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
	}

	if (pt.x < WINDOW_RIGHT * 1/3 - pPlayerChara->m_pMove->m_pos.x) {
		//���_�𒴂������ɐݒ肷��
		pt.x = WINDOW_RIGHT * 1/3 - pPlayerChara->m_pMove->m_pos.x;
	}
	

	//����������ݒ肷��
	this->m_pMainLayer->setPosition(pt);

	//�X�N���[�����s��ꂽ�Ƃ��ɓG�̏o��������s��
	CMapManager::getInstance()->getMap()->checkEnemyLaunch(this->m_pMainLayer->getPosition());
	
}



/**
 *	@desc	�X�V����
 *	@param	�P�t���[���o�ߎ���
 */
void CGameMain::update( float deltaTime_ ) {
	
	//���͏�Ԃ̍X�V����
	CInputManager::getInstance()->update();

	// esc �L�[����������Q�[���I��
	if ( CInputManager::getInstance()->getInputController()->getGameExitFlag())
	{
		cocos2d::Director::getInstance()->end() ;
	}


	//=========================================================================
	//
	//	��������X�V�����̃R�[�h��ǉ�
	//
	//=========================================================================
	//=========================================================================
	// �T�E���h �t�F�[�h�C��
	//=========================================================================
	CAudioManager::getInstance()->fadeIn(BGM_STAGE1);

	//=========================================================================
	//	�o���X�P�W���[���̋N��
	//=========================================================================
	//�L�����N�^�[���o��������
	CLaunchScheduler::getInstance()->launchCharacter(this->m_pMainLayer);
	//�o�����������g���K�[��S�Ď��O��
	this->checkAndDelete(this->m_pLaunchSchedule);


	//=========================================================================
	//	�Փ˔��菈���Ɋւ���R�[�h�̒ǉ��͂�������
	//=========================================================================


	//=========================================================================
	//	��ʂ̃X�N���[��
	//=========================================================================
	this->scroll();

	//=========================================================================
	//	���O���Ɋւ���R�[�h�̒ǉ��͂�������
	//=========================================================================
	this->checkAndRemove(this->m_pCharacters);

	//=========================================================================
	//
	//	�����܂łɍX�V�����̃R�[�h��ǉ�
	//
	//=========================================================================
}





/**
* @desc		�Q�[�����C���ɑJ��
* @param	�^�C�g�����C���[�̃C���X�^���X
* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
*/
void CGameMain::callbackChangeGameOver(cocos2d::Ref* pSender)
{
	// ���ʉ��Đ�
	int musicID = AudioEngine::play2d(SOUND_FILE_SE_BUTTON);
	//BGM��~
	AudioEngine::stop(CAudioManager::getInstance()->getMusicID(BGM_STAGE1));

	// ���ʉ��Đ��I����
	AudioEngine::setFinishCallback(musicID, [](int musicID, const std::string) {

		//�V�[���𐶐�����
		cocos2d::Scene* pScene = CGameOver::createScene();
		//�V�[����؂�ւ���
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionShrinkGrow::create(1.0f, pScene));

	});
}