/*
* Constants.h
*
*	2016/11/15	Osumi
*
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

// プレイヤー
//#define IMAGE_PLAYER			"Images/player.png"
#define IMAGE_PLAYER			"Images/knight_1.png"

//消失エフェクト
#define IMAGE_DIAPPEAR_EFFECT	"Images/bakuhatsuM01.png"

//武器（仮）
#define IMAGE_SAMPLE_WEAPON		"Images/slash_sample.png"

//少女
//#define IMAGE_PLAYER_GIRL		"Images/shoujo.png"
#define IMAGE_PLAYER_GIRL       "Images/1s.png"

//敵
//#define IMAGE_ENEMY			"Images/kuribo.png"
#define IMAGE_ENEMY				"Images/kari.png"

// 敵武器もち
#define IMAGE_ENEMY_WEAPON		"Images/kari_weapon.png"

//背景
// 
#define IMAGE_BACK_GROUND		"Images/castle_exit.jpg"
#define IMAGE_BACK_HORIZON		"Images/gaikan_map.png"

//=========================================================================
//	タグ
//=========================================================================
#define TAG_PLAYER_1	(1000)
#define TAG_PLAYER_2	(1001)
#define TAG_WEAPON_1	(2000)

//=========================================================================
//	サウンドファイルのマクロはここから書く
//=========================================================================

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
