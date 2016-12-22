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

//�v���C���[�̕���A�N�V����
#include "Data/ActionController/PlayerActionController/PlayerWeaponActionController/PlayerWeaponActionController.h"

// ����
#include "Lib/Input/InputManager.h"
// ���������p
#include <stdlib.h>
#include <time.h>
// �T�E���h�p
#include "SimpleAudioEngine.h"



using namespace CocosDenshion;
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

	// BGM �̒�~
	SimpleAudioEngine::getInstance()->stopBackgroundMusic() ;
	
	// �S�Ă̌��ʉ����~
	SimpleAudioEngine::getInstance()->stopAllEffects() ;
	
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
	//CMapManager::getInstance()->getMap()->initCheckEnemyLaunch();
	//�S�̂̊g��
	this->setScale(SCALE_MAIN);
	//�g��ɔ�����ʈʒu�̐ݒ�
	this->setPosition((SCREEN_WIDTH*(SCALE_MAIN-1))/2, (SCREEN_HEIGHT*(SCALE_MAIN-1))/2);

	//BGM�̓ǂݍ���
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(SOUND_FILE_BGM_STAGE_FIRST);
	//BGM�̍Đ�
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(SOUND_FILE_BGM_STAGE_FIRST, true);



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
	
	// esc �L�[����������Q�[���I��
	if ( CInputManager::getInstance()->getInputController(CONTROLLER_TYPE::KEYBORD)->getGameExitFlag())
	{
		cocos2d::Director::getInstance()->end() ;
	}


	//=========================================================================
	//
	//	��������X�V�����̃R�[�h��ǉ�
	//
	//=========================================================================


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
