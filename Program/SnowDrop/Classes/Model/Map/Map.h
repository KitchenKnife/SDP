/*
 * Map.h
 *
 *	2016/11/15	Osumi
 *
 */

#pragma once
//=========================================================================
//　追加のインクルードはここから
//=========================================================================
#include <stdio.h>
#include "cocos2d.h"
#include"Constants.h"

class CEnemyLaunchData;
class CGimmickLaunchData;

//=========================================================================
//	ブロック（マップチップの事）種類
//		新しい種類が出来たらここに増やしていく
//=========================================================================
enum class BLOCK_TYPE :int {
	NONE			= 0,	//何もない
	KURIBO = 101,
	MAIDEAD = 102,		//メイド
	BAT = 103,		//コウモリ
	REDMAIDEAD = 104,		//赤クリボー
	BLUEMAIDEAD = 105,

};

//=========================================================================
//	敵の種類
//		ブロック番号に依存
//=========================================================================
enum class ENEMY_TYPE :int {
	NONE		= 0,	//何もない
	KURIBO		= 101,	//通常クリボー
	MAIDEAD		= 102,	//メイド
	BAT			= 103,	//コウモリ
	REDMAIDEAD	= 104,	//赤クリボー
	BLUEMAIDEAD = 105,	//青クリボー

};

//ギミックの種類
enum class GIMMICK_TYPE :int {
	NONE = -1,
};

//=========================================================================
//	マップクラス
//=========================================================================
class CMap :public cocos2d::TMXTiledMap {
public:
	//=========================================================================
	//	レイヤータイプ
	//=========================================================================
	enum class LAYER_TYPE :int {
		NOMAL			= 0,	//通常マップ
		LAUNCH_ENEMY	= 1,	//敵出現用マップ
		GIMMICK			= 2,    //ギミック用マップ

	};

	//=========================================================================
	//	マップタイプによるレイヤーの名前
	//=========================================================================
	std::vector<std::string>m_layerName{
		"normal",
		"launchenemy",
		"gimmick",
		"collision",
	};

public:

	//コンストラクタ
	CMap(){
		
	}

	//生成
	static CMap* create(const std::string& tmxFile) {
		CMap* pMap = new(std::nothrow)CMap();
		if (pMap->initWithTMXFile(tmxFile)) {
			pMap->autorelease();
			return pMap;
		}
		CC_SAFE_DELETE(pMap);
		return NULL;
	}

	/**
	 * @desc	タイルの2次元配列上の座標を取得
	 * @param	左下を原点として配列上の座標位置
	 */
	cocos2d::Point getTileCoord(cocos2d::Point pos);


	/**
	 * @desc	タイル位置の取得
	 * @param	左下を原点として対象の座標位置
	 */
	cocos2d::Point getTilePosition(cocos2d::Point pos);


	/**
	 * @desc	オブジェクト位置の取得
	 * @param	左下を原点として対象の座標位置
	 * @author	Shinya Ueba
	 */
	//cocos2d::Point getObjectPosition(cocos2d::Point pos);

	/**
	 * @desc	点とマップチップの衝突判定
	 * @param	対象位置X
	 * @param	対象位置Y
	 */
	bool hitTest(float posX, float posY);

	/**
	 * @desc	点とオブジェクトの衝突判定
	 * @param	対象位置X
	 * @param	対象位置Y
	 * @author	Shinya Ueba
	 */
	bool hitTestObject(float posX, float posY);

	/**
	 * @desc	タイル番号確認
	 * @param	2次元配列上の位置X
	 * @param	2次元配列上の位置Y
	 * @param	レイヤータイプ
	 * @return	ブロックの種類
	 * @tips	checkTileという名前にしてるのは
	 *  		enchant.js にはデフォルトでマップクラスに
	 *			checkTileという関数が存在しいていて
	 *			同じ機能を持っているので名前を統一している
	 */
	BLOCK_TYPE checkTile(float posX, float posY , LAYER_TYPE = LAYER_TYPE::NOMAL);
	

	/**
	 * @desc	タイルの変更
	 * @param	変更するマップチップID(タイル番号、ブロック番号、マップチップ番号)
	 * @param	点が衝突しているタイル、その点のｘ座標
	 * @param	点が衝突しているタイル、その点のｙ座標
	 * @param	レイヤータイプ
	 * @return	true...成功	
	 */
	bool changeTile(int mapChipID, float posX, float posY, LAYER_TYPE = LAYER_TYPE::NOMAL);


	/*
	 * @desc	初期化時の敵出撃判定
	 * @return	敵の出撃データ群
	 */
	void initCheckEnemyLaunch();

	/*
	 * @desc	敵出撃判定
	 * @param	メインレイヤーのアドレス
	 */
	void checkEnemyLaunch(cocos2d::Point pt);

	//敵出撃ライン（マップ2次元配列上のタイルのｘ位置）
	//20は画面端+1つ分
	int m_launchEnemyLine = WINDOW_RIGHT/TILE_SIZE;

	/*
	 * @desc	敵出撃後の敵出撃レイヤーのタイルの削除
	 * @param	敵出撃データ
	 */
	void removeLaunchEnemy(CEnemyLaunchData* pLaunchData);

	/*
	 * @desc	ギミック出撃判定
	 * @param	メインレイヤーのアドレス
	 */
	void checkGimmickLaunch(cocos2d::Point pt);

	//敵出撃ライン（マップ2次元配列上のタイルのｘ位置）
	//20は画面端+1つ分
	int m_launchGimmickLine = 20;

	/*
	 * @desc	ギミック出撃後のギミック出撃レイヤーのタイルの削除
	 * @param	ギミック出撃データ
	 */
	void removeLaunchGimmick(CGimmickLaunchData* pLaunchData);
};

//=========================================================================
//	マップ管理クラス
//=========================================================================
class CMapManager {
private:
	//=========================================================================
	//	シングルトン設定
	//=========================================================================

	//コンストラクタ
	CMapManager();
	CMapManager(const CMapManager& customMapMgr);

	//共有インスタンス
	static CMapManager* m_pSharedMapManager;

public:
	//共有インスタンスの取得
	static CMapManager* getInstance();

	//破棄
	static void removeInstance();
	//デストラクタ
	~CMapManager();

private:
	//マップ
	CMap* m_pMap = NULL;

public:
	//マップ生成
	CMap* createMap(const std::string& fileName_);

	//マップ取得
	CMap* getMap();

};



