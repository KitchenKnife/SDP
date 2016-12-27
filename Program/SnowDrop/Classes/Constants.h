/*
* Constants.h
*
*	2016/11/15	Osumi
*   2016/12/18 Ueba
*/
#pragma once

//=========================================================================
//	定数やマクロはここから書く
//=========================================================================


// メモリ解放
#define SAFE_DELETE( p_ ) if ( p_ ) { delete p_ ; p_ = NULL ; }
// 配列メモリ解放
#define SAFE_DELETE_ARRAY( p_ ) if ( p_ ) { delete [] p_ ; p_ = NULL ; }

// イテレーターキャパシティのクリア
template <typename Ty>
void ClearAndSwap( Ty p_ ) { p_->clear() ; Ty().swap( *p_ ) ; }
#define CLEAR_AND_SWAP( p_ ) ClearAndSwap( p_ )

// CGameMain のタグ
#define TAG_GAME_MAIN (1000)


#define getCurrentLayer( tag_ ) cocos2d::Director::getInstance()->getRunningScene()->getChildByTag( tag_ )

//拡大率
#define SCALE_MAIN			1.0f

// ウィンドウサイズ
#define WINDOW_LEFT			(0)
#define WINDOW_TOP			(1080/SCALE_MAIN)
#define WINDOW_RIGHT		(1920/SCALE_MAIN)
#define WINDOW_BOTTOM		(0)

//マップタイルサイズ
#define TILE_SIZE			(32.0)


//スクリーンサイズ
// 幅
#define SCREEN_WIDTH	(CCDirector::sharedDirector()->getVisibleSize().width)
// 高さ
#define SCREEN_HEIGHT	(CCDirector::sharedDirector()->getVisibleSize().height)

//#define SCREEN_HEIGHT	(CCDirector::sharedDirector()->getVisibleSize().height)

//=========================================================================
//	画像ファイルのマクロはここから書く
//=========================================================================
//タイトル
#define IMAGE_TITLE						"Images/Title.jpg"
#define IMAGE_TITLE_BUTTON_START		"Images/button/Start.png"
#define IMAGE_TITLE_BUTTON_END			"Images/button/End.png"


// プレイヤー
//#define IMAGE_PLAYER			"Images/player.png"
#define IMAGE_PLAYER			"Images/Boy/1knight1ss.png"

//消失エフェクト
#define IMAGE_DIAPPEAR_EFFECT	"Images/bakuhatsuM01.png"

//武器（仮）
#define IMAGE_SAMPLE_WEAPON		"Images/slash_sample.png"

//少女
//#define IMAGE_PLAYER_GIRL		"Images/shoujo.png"
#define IMAGE_PLAYER_GIRL       "Images/1s.png"

//敵
//#define IMAGE_ENEMY			"Images/kuribo.png"
#define IMAGE_ENEMY				"Images/Enemy/kari.png"
#define IMAGE_MEIDEAD			"Images/Enemy/Maidead/meid.png"
#define IMAGE_BAT				"Images/Enemy/Bat/bat.png"

// 敵武器もち
#define IMAGE_ENEMY_WEAPON		"Images/kari_weapon.png"

//背景
// 
#define IMAGE_BACK_GROUND		"Images/castle_exit.jpg"
#define IMAGE_BACK_HORIZON		"Images/gaikan_map.png"

//=========================================================================
//	パーティクルファイルのマクロはここから書く
//=========================================================================
#define PARTICLE_GRAPS_MARK		"Particle/circle.plist"


//=========================================================================
//	タグ
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
//	曲名のマクロはここから書く
//=========================================================================

#define BGM_TITLE	("TitleBGM")
#define BGM_STAGE1	("Stage1BGM")


//=========================================================================
//	サウンドファイルのマクロはここから書く
//=========================================================================
//BGM
#define SOUND_FILE_BGM_TITLE  "Sound/Title_01.mp3"
//#define SOUND_FILE_BGM_ENDING "Sound/BGM_ENDING.mp3"
#define SOUND_FILE_BGM_STAGE_FIRST "Sound/BGM_01.mp3"
#define SOUND_FILE_BGM_STAGE_SECOND "Sound/BGM_02.mp3"
#define SOUND_FILE_BGM_STAGE_THIRD "Sound/BGM_03.mp3"

// ボタンの押下音
#define SOUND_FILE_SE_BUTTON		"Sound/button83.mp3"


//=========================================================================
//	フォントのマクロはここから書く
//=========================================================================


//=========================================================================
//	その他の外部ファイルのマクロはここから書く
//=========================================================================
//#define MAP_DATA_SAMPLE "MapData/sampleMapData.tmx"
#define MAP_DATA_SAMPLE "MapData/MapData.tmx"
//#define MAP_DATA_SAMPLE "MapData/ST02_2.tmx"

/**
*	@desc	配列の NULL が入っている添字番号を取得
*	@param	検索する配列
*	@return	NULL が入っている添字番号
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
