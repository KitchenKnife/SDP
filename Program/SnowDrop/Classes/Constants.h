/*
* Constants.h
*
*	2016/11/15	Osumi
*   2016/12/18 Ueba
*/
#pragma once

//=========================================================================
//	�萔��}�N���͂������珑��
//=========================================================================


// ���������
#define SAFE_DELETE( p_ ) if ( p_ ) { delete p_ ; p_ = NULL ; }
// �z�񃁃������
#define SAFE_DELETE_ARRAY( p_ ) if ( p_ ) { delete [] p_ ; p_ = NULL ; }

// �C�e���[�^�[�L���p�V�e�B�̃N���A
template <typename Ty>
void ClearAndSwap( Ty p_ ) { p_->clear() ; Ty().swap( *p_ ) ; }
#define CLEAR_AND_SWAP( p_ ) ClearAndSwap( p_ )

// CGameMain �̃^�O
#define TAG_GAME_MAIN (1000)


#define getCurrentLayer( tag_ ) cocos2d::Director::getInstance()->getRunningScene()->getChildByTag( tag_ )

//�g�嗦
#define SCALE_MAIN			1.0f

// �E�B���h�E�T�C�Y
#define WINDOW_LEFT			(0)
#define WINDOW_TOP			(1080/SCALE_MAIN)
#define WINDOW_RIGHT		(1920/SCALE_MAIN)
#define WINDOW_BOTTOM		(0)

//�}�b�v�^�C���T�C�Y
#define TILE_SIZE			(32.0)


//�X�N���[���T�C�Y
// ��
#define SCREEN_WIDTH	(CCDirector::sharedDirector()->getVisibleSize().width)
// ����
#define SCREEN_HEIGHT	(CCDirector::sharedDirector()->getVisibleSize().height)

//#define SCREEN_HEIGHT	(CCDirector::sharedDirector()->getVisibleSize().height)

//=========================================================================
//	�摜�t�@�C���̃}�N���͂������珑��
//=========================================================================
//�^�C�g��
#define IMAGE_TITLE						"Images/Title.jpg"
#define IMAGE_TITLE_BUTTON_START		"Images/button/Start.png"
#define IMAGE_TITLE_BUTTON_END			"Images/button/End.png"


// �v���C���[
//#define IMAGE_PLAYER			"Images/player.png"
#define IMAGE_PLAYER			"Images/Boy/1knight1ss.png"

//�����G�t�F�N�g
#define IMAGE_DIAPPEAR_EFFECT	"Images/bakuhatsuM01.png"

//����i���j
#define IMAGE_SAMPLE_WEAPON		"Images/slash_sample.png"

//����
//#define IMAGE_PLAYER_GIRL		"Images/shoujo.png"
#define IMAGE_PLAYER_GIRL       "Images/1s.png"

//�G
//#define IMAGE_ENEMY			"Images/kuribo.png"
#define IMAGE_ENEMY				"Images/Enemy/kari.png"
#define IMAGE_MEIDEAD			"Images/Enemy/Maidead/meid.png"
#define IMAGE_BAT				"Images/Enemy/Bat/bat.png"

// �G�������
#define IMAGE_ENEMY_WEAPON		"Images/kari_weapon.png"

//�w�i
// 
#define IMAGE_BACK_GROUND		"Images/castle_exit.jpg"
#define IMAGE_BACK_HORIZON		"Images/gaikan_map.png"

//=========================================================================
//	�p�[�e�B�N���t�@�C���̃}�N���͂������珑��
//=========================================================================
#define PARTICLE_GRAPS_MARK		"Particle/circle.plist"


//=========================================================================
//	�^�O
//=========================================================================
#define TAG_PLAYER_1	(1000)
#define TAG_PLAYER_2	(1001)
#define TAG_WEAPON_1	(2000)

// 1st Enemy
#define TAG_ENEMY_MEIDEAD	(10000)
#define TAG_ENEMY_BAT		(10001)
#define TAG_ENEMY_MALICE	(10002)
#define TAG_ENEMY_SOLDIER	(10003)
#define TAG_ENEMY_BOSS_1	(10004)



//=========================================================================
//	�Ȗ��̃}�N���͂������珑��
//=========================================================================

#define BGM_TITLE	("TitleBGM")
#define BGM_STAGE1	("Stage1BGM")


//=========================================================================
//	�T�E���h�t�@�C���̃}�N���͂������珑��
//=========================================================================
//BGM
#define SOUND_FILE_BGM_TITLE  "Sound/Title_01.mp3"
//#define SOUND_FILE_BGM_ENDING "Sound/BGM_ENDING.mp3"
#define SOUND_FILE_BGM_STAGE_FIRST "Sound/BGM_01.mp3"
#define SOUND_FILE_BGM_STAGE_SECOND "Sound/BGM_02.mp3"
#define SOUND_FILE_BGM_STAGE_THIRD "Sound/BGM_03.mp3"

// �{�^���̉�����
#define SOUND_FILE_SE_BUTTON		"Sound/button83.mp3"


//=========================================================================
//	�t�H���g�̃}�N���͂������珑��
//=========================================================================


//=========================================================================
//	���̑��̊O���t�@�C���̃}�N���͂������珑��
//=========================================================================
//#define MAP_DATA_SAMPLE "MapData/sampleMapData.tmx"
#define MAP_DATA_SAMPLE "MapData/MapData.tmx"
//#define MAP_DATA_SAMPLE "MapData/ST02_2.tmx"

/**
*	@desc	�z��� NULL �������Ă���Y���ԍ����擾
*	@param	��������z��
*	@return	NULL �������Ă���Y���ԍ�
*/
template<typename Ty, typename vecTy>
int getFreeIndex(Ty* item, vecTy* vecteor) {
	int i = -1;
	for (Ty* item : *vecteor) {
		i++;
		if (item == NULL) {
			return i;
		}
	}
	return -1;
}
