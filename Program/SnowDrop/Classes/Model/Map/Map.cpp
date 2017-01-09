
/*
* Map.cpp
*
*	2016/11/13	Osumi
*
*/

#include "Map.h"
#include "Constants.h"
#include "Data/Collision/Collision.h"
#include "Data/LaunchData/LaunchData.h"
#include "Data/LaunchTrigger/LaunchTrigger.h"

using namespace cocos2d;

//=========================================================================
//	マップクラス
//=========================================================================
/**
* @desc	タイルの2次元配列上の座標を取得
* @param 対象位置
*/
Point CMap::getTileCoord(Point pos) {

	//マップの原点位置
	Point pt = this->getPosition();

	//マップタイルサイズ
	Size tileSize = this->getTileSize();

	//マップの配列サイズ
	Size mapSize = this->getMapSize();

	int x = (pos.x + pt.x) / tileSize.width;
	int y = ((mapSize.height*tileSize.height) - pos.y) / tileSize.height;

	//左上原点の場合
	//int y =(pos_.y + this->getPosition().y)/this->getTileSize().height;

	return Point(x,y);
}

/**
* @desc		タイル位置の取得
* @param	対象位置
*/
Point CMap::getTilePosition(cocos2d::Point pos) {

	//マップの原点位置
	Point pt = this->getPosition();

	//マップタイルサイズ
	Size tileSize = this->getTileSize();

	int x = (pos.x + pt.x)/tileSize.width;
	int y = (pos.y + pt.y) /tileSize.height;

	return Point(x*tileSize.width, y*tileSize.height);

}


/**
* @desc	点とマップチップの衝突判定
* @param 対象位置X
* @param 対象位置Y
*/
bool CMap::hitTest(float posX, float posY) {

	//対象の衝突判定の点
	CCollisionPoint cpt(Point(posX, posY));

	//点と衝突しているマップチップの原点（左下の点）を取得
	Point basePoint = this->getTilePosition(Point(posX, posY));

	//マップチップの位置（マップチップの中心位置）
	Point tilePos = Point(basePoint.x + 16.0f, basePoint.y + 16.0f);

	//(-16,16,16,-16)
	CCollisionRect crect(CBody(-16, 16, 16, -16),tilePos);

	//collisionを使用して判定
	return cpt.collision(&crect);

}

/**
* @desc	点とオブジェクトの衝突判定
* @param 対象位置X
* @param 対象位置Y
* @author Shinya Ueba
*/
bool CMap::hitTestObject(float posX, float posY)
{
	//対象の衝突判定の点
	CCollisionPoint cpt(Point(posX, posY));

	cocos2d::CCTMXObjectGroup* pointerTiledMapObjectGroup = this->getObjectGroup(this->m_layerName[3]);
	if (!pointerTiledMapObjectGroup)
	{
		return false;
	}

	auto arrayAutoObjects = pointerTiledMapObjectGroup->getObjects();

	for (auto autoObject : arrayAutoObjects)
	{
		// objectに設定されているプロパティなどを取得
		cocos2d::ValueMap valueMapObjectInfomation = autoObject.asValueMap();

		cocos2d::Vec2 vec2MapPosition = this->getPosition();
		cocos2d::Vec2 vec2ObjectPosition;
		vec2ObjectPosition.x = valueMapObjectInfomation["x"].asFloat() + vec2MapPosition.x + this->getTileSize().width * 0.5f;
		vec2ObjectPosition.y = valueMapObjectInfomation["y"].asFloat() + vec2MapPosition.y + this->getTileSize().height * 0.5f;
		
		CCollisionRect crectObject(CBody(	valueMapObjectInfomation["width"].asFloat() * -0.5,
									valueMapObjectInfomation["height"].asFloat() * 0.5,
									valueMapObjectInfomation["width"].asFloat() * 0.5,
									valueMapObjectInfomation["height"].asFloat() * -0.5),
									vec2ObjectPosition);
		
		cocos2d::log("X:%f,Y%f", vec2ObjectPosition.x, vec2ObjectPosition.y);

		//collisionを使用して判定
		if (cpt.collision(&crectObject))
		{
			
			return true;
		}
	}
	return false;
}


/**
* @desc		タイル番号確認
* @param	点が衝突しているタイル、その点のｘ座標
* @param	点が衝突しているタイル、その点のｙ座標
* @param	レイヤータイプ
* @return	ブロックのタイプ
*/
BLOCK_TYPE CMap::checkTile(float posX, float posY, LAYER_TYPE layerType) {

	//レイヤーを取得
	TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//タイルの2次元配列上の座標を取得
	Point tileCoord = this->getTileCoord(Point( posX, posY));

	//マップの配列サイズ
	Size mapSize = this->getMapSize();

	//タイルの2次元配列上の座標が0未満、またはマップサイズより大きい場合
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false) {

		return BLOCK_TYPE::NONE;
	}

	//マップデータの取得
	return (BLOCK_TYPE)pLayer->getTileGIDAt(tileCoord);

}

/**
* @desc	タイルの変更
* @param  変更するマップチップID
* @param  点が衝突しているタイル、その点のｘ座標
* @param  点が衝突しているタイル、その点のｙ座標
* @param	レイヤータイプ
* @return true...成功
*/
bool CMap::changeTile(int mapChipID, float posX, float posY, LAYER_TYPE layerType) {

	//レイヤーを取得
	TMXLayer* pLayer = this->getLayer(this->m_layerName[(int)layerType]);

	//タイルの2次元配列上の座標を取得
	Point tileCoord = this->getTileCoord(Point(posX, posY));

	//マップの配列サイズ
	Size mapSize = this->getMapSize();

	//////
	//タイルの2次元配列上の座標が0未満、またはマップサイズより大きい場合
	if ((0 <= tileCoord.x && tileCoord.x < mapSize.width) == false ||
		(0 <= tileCoord.y && tileCoord.y < mapSize.height) == false) {

		return false;
	}

	//マップチップデータの反映
	pLayer->setTileGID(mapChipID,tileCoord);

	return true;

}

/*
* @desc	初期化時の敵出撃判定
* @return	敵のタイプ
*/
void CMap::initCheckEnemyLaunch() {

	//マップを取得
	CMap* pMap = CMapManager::getInstance()->getMap();

	//マップチップのサイズを取得（32,32）
	Size tileSize = pMap->getTileSize();

	//敵の出撃データ群
	std::vector<CEnemyLaunchData*>* pLaunchDatas = new std::vector<CEnemyLaunchData*>;

	//左から順にタイルサイズ分づつタイルをチェックしていく
	for (float chackPosX = tileSize.width * 0.5f; chackPosX< WINDOW_RIGHT; chackPosX += tileSize.width){
	//下から順にタイルサイズ分づつタイルをチェックしていく
		for (float y = tileSize.height * 0.5f; y < WINDOW_TOP; y += tileSize.height) {

			//チェックするタイルの座標を設定（xは固定でy座標をチェックしていく）
			Point tilePos(chackPosX, y);

			//そのx座標の2次元配列上のｙ位置にある全てのタイルを取得
			//そのタイルのタイルタイプ（＝敵タイプ）を取得
			ENEMY_TYPE eneType = (ENEMY_TYPE)pMap->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_ENEMY);

			//敵のタイプがNONEじゃなかったら出撃
			if (eneType != ENEMY_TYPE::NONE) {

				//敵出撃データを作成
				CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(eneType, tilePos);

				//出撃トリガーを生成し、敵出撃データを設定
				CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

				//出撃トリガーを出撃スケジュールとして追加する
				CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

				//敵出撃タイルの削除
				CMapManager::getInstance()->getMap()->removeLaunchEnemy(pLaunchData);
				
			}
		}
	}
	
	
}


/*
* @desc	敵出撃判定
* @param	メインレイヤーの位置
* @return	敵のタイプ
*/
void CMap::checkEnemyLaunch(cocos2d::Point pt) {

	//マップを取得
	CMap* pMap = CMapManager::getInstance()->getMap();

	//レイヤーのｘ位置に画面の右サイズ分を足すことで
	//表示されている画面の右端の位置を取得できる
	float checkPosX = -pt.x + WINDOW_RIGHT;

	//マップチップのサイズを取得（32,32）
	Size tileSize = pMap->getTileSize();

	//タイルの2次元配列上の座標を取得（ｘ座標のみをチェック）
	Point tileCoord = pMap->getTileCoord(Point(checkPosX, 0.0f));

	//現在参照中の敵出撃ライン
	if (m_launchEnemyLine == tileCoord.x) {

		//下から順にタイルサイズ分づつタイルをチェックしていく
		for (float y = tileSize.height * 0.5f; y< WINDOW_TOP; y+=tileSize.height) {

			//チェックするタイルの座標を設定（xは固定でy座標をチェックしていく）
			Point tilePos(checkPosX, y);

			//そのx座標の2次元配列上のｙ位置にある全てのタイルを取得
			//そのタイルのタイルタイプ（＝敵タイプ）を取得
			ENEMY_TYPE eneType = (ENEMY_TYPE)pMap->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::LAUNCH_ENEMY);

			//敵のタイプがNONEじゃなかったら出撃
			if (eneType != ENEMY_TYPE::NONE) {

				//敵出撃データを作成
				CEnemyLaunchData* pLaunchData = new CEnemyLaunchData(eneType, tilePos);

				//出撃トリガーを生成し、敵出撃データを設定
				CEnemyLaunchTrigger* pTrigger = new CEnemyLaunchTrigger(pLaunchData);

				//出撃トリガーを出撃スケジュールとして追加する
				CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

				//敵出撃タイルの削除
				CMapManager::getInstance()->getMap()->removeLaunchEnemy(pLaunchData);
				
			}

		}
		//敵出撃ラインの更新
		m_launchEnemyLine++;
	}
}


/*
* @desc	敵出撃後の敵出撃レイヤーのタイルの削除
* @param	敵出撃データ
*/
void CMap::removeLaunchEnemy(CEnemyLaunchData* pLaunchData) {

	//マップを取得
	CMap* pMap = CMapManager::getInstance()->getMap();

	//出撃した場所の敵出撃レイヤーのマップチップタイプをENEMY::NONEにする
	pMap->changeTile(
		(int)ENEMY_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::LAUNCH_ENEMY
	);

}


/*
* @desc	ギミック出撃判定
* @param	メインレイヤーのアドレス
*/
void CMap::checkGimmickLaunch(cocos2d::Point pt) {

	//マップを取得
	CMap* pMap = CMapManager::getInstance()->getMap();

	//レイヤーのｘ位置に画面の右サイズ分を足すことで
	//表示されている画面の右端の位置を取得できる
	float checkPosX = -pt.x + WINDOW_RIGHT;

	//マップチップのサイズを取得（32,32）
	Size tileSize = pMap->getTileSize();

	//タイルの2次元配列上の座標を取得（ｘ座標のみをチェック）
	Point tileCoord = pMap->getTileCoord(Point(checkPosX, 0.0f));

	//現在参照中の敵出撃ライン
	if (this->m_launchGimmickLine == tileCoord.x) {

		//下から順にタイルサイズ分づつタイルをチェックしていく
		for (float y = tileSize.height*0.5f; y < WINDOW_TOP; y += tileSize.height) {

			//チェックするタイルの座標を設定（xは固定でy座標をチェックしていく）
			Point tilePos(checkPosX, y);

			//そのx座標の2次元配列上のｙ位置にある全てのタイルを取得
			//そのタイルのタイルタイプ（＝敵タイプ）を取得
			GIMMICK_TYPE gimType = (GIMMICK_TYPE)pMap->checkTile(tilePos.x, tilePos.y, CMap::LAYER_TYPE::GIMMICK);

			//敵のタイプがNONEじゃなかったら出撃
			if (gimType != GIMMICK_TYPE::NONE) {

				//敵出撃データを作成
				CGimmickLaunchData* pLaunchData = new CGimmickLaunchData(gimType, tilePos);

				//出撃トリガーを生成し、敵出撃データを設定
				CGimmickLaunchTrigger* pTrigger = new CGimmickLaunchTrigger(pLaunchData);

				//出撃トリガーを出撃スケジュールとして追加する
				CLaunchScheduler::getInstance()->m_pLauncher->add(pTrigger);

				//敵出撃タイルの削除
				CMapManager::getInstance()->getMap()->removeLaunchGimmick(pLaunchData);

			}

		}
		//敵出撃ラインの更新
		this->m_launchGimmickLine++;
	}
}

/*
* @desc	ギミック出撃後のギミック出撃レイヤーのタイルの削除
* @param	ギミック出撃データ
*/
void CMap::removeLaunchGimmick(CGimmickLaunchData* pLaunchData) {

	//マップを取得
	CMap* pMap = CMapManager::getInstance()->getMap();

	//出撃した場所の敵出撃レイヤーのマップチップタイプをENEMY::NONEにする
	pMap->changeTile(
		(int)GIMMICK_TYPE::NONE,
		pLaunchData->m_pos.x,
		pLaunchData->m_pos.y,
		CMap::LAYER_TYPE::GIMMICK
	);
}

//=========================================================================
//	マップ管理クラス
//=========================================================================
//共有インスタンス本体
CMapManager*  CMapManager::m_pSharedMapManager = NULL;

//コンストラクタ
CMapManager::CMapManager(){}
CMapManager::CMapManager(const CMapManager& customMapMgr) {

}

//共有インスタンスの取得
CMapManager* CMapManager::getInstance(){
	if (CMapManager::m_pSharedMapManager == NULL) {
		CMapManager::m_pSharedMapManager = new CMapManager();
	}
	return CMapManager::m_pSharedMapManager;
}


//デストラクタ
CMapManager::~CMapManager(){}

//破棄
void CMapManager::removeInstance() {
	if (CMapManager::m_pSharedMapManager != NULL) {
		SAFE_DELETE(CMapManager::m_pSharedMapManager);
	}
}
	

//マップ生成
CMap* CMapManager::createMap(const std::string& fileName_) {

	//マップクラスの生成
	this->m_pMap = CMap::create(fileName_);

	if (this->m_pMap == NULL) {
		CCLOG("マップの生成に失敗しました！！！");
		return NULL;
	}

	//初期設定の位置
	this->m_pMap->setPosition(0.0f, 0.0f);


	//取り付けられてるすべてのタイルのエイリアスのデフォルトをアンチエイリアスに設定
	//ちらつき防止
	for (const auto& child:this->m_pMap->getChildren()) {
		static_cast<cocos2d::SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
	}


	return this->m_pMap;
}

//マップの取得
CMap* CMapManager::getMap() {
	return this->m_pMap;
}
