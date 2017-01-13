/*
* GameMain.cpp
*
*	2016/11/10	Osumi
*
*/

#include "GameMain.h"
#include "Scene/GameMain2/GameMain2.h"
#include "Model/Map/Map.h"

//�L�����N�^�[�W����
#include "Model\Character\CharacterAggregate.h"

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

	//�o���X�P�W���[���̍폜
	if (this->m_pLaunchSchedule)
	{
		for (CLaunchTrigger* pTrigger : (*this->m_pLaunchSchedule))
		{
			SAFE_DELETE(pTrigger);
		}
	}
	//�o���X�P�W���[���̔j��
	SAFE_DELETE(this->m_pLaunchSchedule);



	SAFE_DELETE(this->m_pCharacters);
}



/**
 *	@desc	������
 *	@return	true...����	false...���s
 */
bool CGameMain::init() {

	// �e���C���[�̏�����
	if ( CCLayerColor::initWithColor(ccc4(51, 75, 112, 255)) == false ) {
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

	////�L�����N�^�[�̏W�܂�̐���
	this->m_pCharacters = new std::vector<CCharacter*>();
	//�L�����N�^�[�̏W�܂��CCharacterAggregate�ɐݒ肷��
	CCharacterAggregate::getInstance()->set(this->m_pCharacters);

	//�o���X�P�W���[���̐���
	this->m_pLaunchSchedule = new std::vector<CLaunchTrigger*>();
	//�o���X�P�W���[�����o���X�P�W���[���Ɏ��t����
	CLaunchScheduler::getInstance()->createLauncher(this->m_pLaunchSchedule);

	////���C�����C���[�̐����Ǝ��t��
	this->m_pMainLayer = LayerColor::create(ccc4(51, 75, 112, 255));
	this->addChild(this->m_pMainLayer);

	//�L�����N�^�[�����t���郌�C���[��ݒ�
	CCharacterAggregate::getInstance()->setLayer(this->m_pMainLayer);

	////UI���C���[�̐����Ǝ��t��
	this->m_pUILayer = LayerColor::create();
	this->addChild(this->m_pUILayer,-1);

	//
	//�w�i�̐����Ǝ��t��
	this->m_pBackGround = Sprite::create();
	this->m_pBackGround->setTexture(IMAGE_BACK_GROUND);
	this->m_pBackGround->setPosition(WINDOW_RIGHT*0.5, WINDOW_TOP*0.5);
	this->m_pMainLayer->addChild(this->m_pBackGround);
	

	//�}�b�v�̐����Ǝ��t��
	CMap* pMap = CMapManager::getInstance()->createMap(MAP_DATA_SAMPLE);
	pMap->setVisible(false);
	this->m_pMainLayer->addChild(pMap);

	
	//�n�����̐����Ǝ��t��
	this->m_pHrizon = Sprite::create();
	this->m_pHrizon->setTexture(IMAGE_BACK_HORIZON);
	this->m_pHrizon->setPosition(WINDOW_RIGHT*0.5, WINDOW_TOP*0.5);
	this->m_pMainLayer->addChild(this->m_pHrizon);
	

	
	// �v���C���[�̐���
	CPlayerCharacterBoy* pPlayerChara = CPlayerBoyFactoryManager::getInstance()->create((int)PLAYER_TYPE::BASE);
	////CCharacterAggregate�Ƀv���C���[��ǉ�
	CCharacterAggregate::getInstance()->add(pPlayerChara);
	//�Q�Ɛ�Ƃ��ēo�^
	CCharacterAggregate::getInstance()->setPlayer(pPlayerChara);
	////���t��
	this->m_pMainLayer->addChild(pPlayerChara);


	//// �����̐����Ǝ��t��
	CPlayerCharacterGirl* playerGirl = CPlayerGirlFactoryManager::getInstance()->create((int)GIRL_TYPE::BASE);
	//CCharacterAggregate�Ƀv���C���[��ǉ�
	CCharacterAggregate::getInstance()->add(playerGirl);
	//�Q�Ɛ�Ƃ��ēo�^
	CCharacterAggregate::getInstance()->setGirl(playerGirl);
	playerGirl->m_pMove->m_pos.set(1200,500);

	//���t��
	this->m_pMainLayer->addChild(playerGirl);


	////������ʂɂ���G�̐���
	CMapManager::getInstance()->getMap()->initCheckEnemyLaunch();


	//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
	// �����@�f�o�b�N�p�@�����[�X�������܂�
	//�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
	/*
	* @desc		���j���[�A�C�e���̐����@�Q�[���I���{�^��
	* @param	�ʏ�̉摜��ݒ�
	* @param	�����ꂽ���̉摜��ݒ�
	* @param	�����ꂽ���ɌĂяo����郁���o�֐��̐ݒ�
	*/
	cocos2d::MenuItemImage* pointerEndBtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_END,
		IMAGE_TITLE_BUTTON_END,
		CC_CALLBACK_1(CGameMain::callbackChangeGameOver, this)
	);

	//�ʒu�ݒ�
	pointerEndBtnItem->setPosition(WINDOW_RIGHT*0.9f, WINDOW_TOP*0.1f);


	/*
	* @desc		���j���[�A�C�e���̐����@�Q�[���X�e�[�W�{�^��
	* @param	�ʏ�̉摜��ݒ�
	* @param	�����ꂽ���̉摜��ݒ�
	* @param	�����ꂽ���ɌĂяo����郁���o�֐��̐ݒ�
	*/
	cocos2d::MenuItemImage* pointerSt2BtnItem = cocos2d::MenuItemImage::create(
		IMAGE_TITLE_BUTTON_START,
		IMAGE_TITLE_BUTTON_START,
		CC_CALLBACK_1(CGameMain::callbackChangeStage2, this)
	);

	//�ʒu�ݒ�
	pointerSt2BtnItem->setPosition(WINDOW_RIGHT*0.9f, WINDOW_TOP*0.2f);

	//���j���[�̐����ƃ��j���[�A�C�e���̓o�^
	cocos2d::Menu* pointerMenu = cocos2d::Menu::create(pointerEndBtnItem, pointerSt2BtnItem, NULL);

	//�ʒu�̏�����
	pointerMenu->setPosition(0.0f, 0.0f);
	//���C���[�Ƀ��j���[��o�^����
	this->addChild(pointerMenu);

	//GLProgramState* pGl = GLProgramState::getOrCreateWithGLProgram();
	this->m_pMainLayer->runAction(CCTintTo::create(1.0, 255, 0, 0));



	//�G�𐶐�
	//�G�o���f�[�^���쐬
	CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(ENEMY_TYPE::MARIONETTE, cocos2d::Point(700,700));


	//�����ɏo��������|�C���g�ƓG�̃^�C�v��n��
	CCharacter* pEnemyCharacter = CEnemyFactoryManager::getInstance()->create(
		pLaunchData->m_pos,
		pLaunchData->m_type
	);
	//CCharacterAggregate�Ƀv���C���[��ǉ�
	CCharacterAggregate::getInstance()->add(pEnemyCharacter);

	this->m_pMainLayer->addChild(pEnemyCharacter);
	SAFE_DELETE(pLaunchData);


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
	int musicID = AudioEngine::play2d(SOUND_FILE_SE_BUTTON, false, CAudioManager::getInstance()->getSEVolume());
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


/**
* @desc		�X�e�[�W2�ɑJ��
* @param	�^�C�g�����C���[�̃C���X�^���X
* @tips		�X�^�[�g�{�^���������ꂽ���ɌĂяo�����
*/
void CGameMain::callbackChangeStage2(cocos2d::Ref* pSender) {

	// ���ʉ��Đ�
	int musicID = AudioEngine::play2d(SOUND_FILE_SE_BUTTON, false, CAudioManager::getInstance()->getSEVolume());
	//BGM��~
	AudioEngine::stop(CAudioManager::getInstance()->getMusicID(BGM_STAGE1));

	// ���ʉ��Đ��I����
	AudioEngine::setFinishCallback(musicID, [](int musicID, const std::string) {

		//�V�[���𐶐�����
		cocos2d::Scene* pScene = CGameMain2::createScene();
		//�V�[����؂�ւ���
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionShrinkGrow::create(1.0f, pScene));

	});
}