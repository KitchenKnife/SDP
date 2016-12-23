//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "CollisionArea.h"
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"

//=====================================
//
// 衝突判定領域
//
//=====================================
/**
 * @desc	イベントコールバックの呼び出し
 * @param	呼びだすインスタンス
 * @param	イベント
 *　　　	マップちっぷの際はマップチップIDをイベントとして渡すが
 *　　　　	画面端などはイベントは存在しないので
 *　　　	デフォルト値として0を設定しておく
 * @tips	領域のイベントの発生時にこのメンバ関数を呼び出すことで
 *　　　	登録したメンバ関数が呼び出される　
 */
void CCollisionTerritory::callEventCallback(CCharacter* pChara, int event) {

	//イベントコールバックが設定されていれば。。。
	//つまりNULLなら呼び出しを行わない
	if (this->m_pEventCallBack != NULL) {

		//イベントコールバックを呼び出すメンバ関数が実装されている
		//キャラクターから呼び出しを行う
		(pChara->*m_pEventCallBack)(event);
	}
}

//=====================================
// 下にある画面端領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryEndOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//下に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.y < 0.0f) {

		//下に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_BOTTOM;

			//最終的に戻す値
			pChara->m_pMove->m_pos.y -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}

//=====================================
// 上にある画面端領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryEndOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//上に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.y > 0.0f) {

		//上に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.y + basePt.y) - WINDOW_TOP;

			//最終的に戻す値
			pChara->m_pMove->m_pos.y -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}
//=====================================
// 右にある画面端領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryEndOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//右に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.x > 0.0f) {

		//右に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算	//basePt.x
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_RIGHT;

			//最終的に戻す値
			pChara->m_pMove->m_pos.x -= boundary;

			//リセットする値
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}
//=====================================
// 左にある画面端領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryEndOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//左に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.x < 0.0f) {

		//左に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//めり込んだ分の計算
			float boundary = (pChara->m_pMove->m_pos.x + basePt.x) - WINDOW_LEFT;

			//最終的に戻す値
			pChara->m_pMove->m_pos.x -= (boundary);

			//リセットする値
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}


//=====================================
// 下にある画面外領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryOutOfScreenBottom::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//下に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.y < 0.0f) {

		//下に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) < WINDOW_BOTTOM) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}

//=====================================
// 上にある画面外領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryOutOfScreenTop::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//上に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.y > 0.0f) {

		//上に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.y + basePt.y) > WINDOW_TOP) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//リセットする値
			pChara->m_pMove->m_vel.y = 0.0f;
			pChara->m_pMove->m_accele.y = 0.0f;
		}
	}
}

//=====================================
// 右にある画面外領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryOutOfScreenRight::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//右に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.x > 0.0f) {

		//右に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) > WINDOW_RIGHT * 3) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//リセットする値
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}
//=====================================
// 左にある画面外領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryOutOfScreenLeft::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//左に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.x < 0.0f) {

		//左に画面端があるかどうかをチェック
		if ((pChara->m_pMove->m_pos.x + basePt.x) < WINDOW_LEFT) {

			//イベントコールバックの呼び出し
			this->callEventCallback(pChara);

			//リセットする値
			pChara->m_pMove->m_vel.x = 0.0f;
			pChara->m_pMove->m_accele.x = 0.0f;
		}
	}
}



//=====================================
// 下にあるマップチップ領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryMapChipBottom::collision(CCharacter* pChara, cocos2d::Point basePt){

	//下に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.y < 0.0f) {

		//衝突してきた点（キャラクターの点）
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y+ basePt.y);

		//衝突いてるかどうか
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {

			//衝突してた

			//ブロックのタイプを取得
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapCcipID != BLOCK_TYPE::NONE) {

				

				//戻すべき位置の値

				//タイルのサイズ（32,32）
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロック数*ブロックの高さ
				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

				//戻すべき位置
				//		修正位置（キャラクターがめり込んでるブロックの下の位置）＝
				//		キャラクターがめり込んでるブロックの下のブロックの位置　+　ブロック1個分　-位置ｙ
				//めり込んだ分の計算
				float boundary = (pt.y) - (blockPos + tileSize.height);

				//最終的に戻す（値めり込んでる分を修正）
				pChara->m_pMove->m_pos.y -= boundary;

				//リセット値
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;

				//イベントコールバックの呼び出し
				this->callEventCallback(pChara, (int)mapCcipID);
			}
		}
	}
}
//=====================================
// 上にあるマップチップ領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryMapChipTop::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//上に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.y > 0.0f) {

		//衝突してきた点（キャラクターの点）
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);

		//衝突いてるかどうか
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {

			//衝突してた

			//ブロックのタイプを取得
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapCcipID != BLOCK_TYPE::NONE) {

				//イベントコールバックの呼び出し
				this->callEventCallback(pChara);

				//戻すべき位置の値

				//タイルのサイズ（32,32）
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロック数*ブロックの高さ
				float blockPos = floor((pt.y) / tileSize.height)*(tileSize.height);

				//戻すべき位置
				//		修正位置（キャラクターがめり込んでるブロックの上の位置）＝
				//		キャラクターがめり込んでるブロックの下のブロックの位置　-位置ｙ
				//めり込んだ分の計算
				float boundary = (pt.y) - (blockPos);

				//最終的に戻す（値めり込んでる分を修正）
				pChara->m_pMove->m_pos.y -= boundary;

				//リセット値
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;
			}
		}
	}
}
//=====================================
// 右にあるマップチップ領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryMapChipRight::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//右に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.x > 0.0f) {

		//衝突してきた点（キャラクターの点）
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);

		//衝突いてるかどうか
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {

			//衝突してた

			//ブロックのタイプを取得
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapCcipID != BLOCK_TYPE::NONE) {

				//イベントコールバックの呼び出し
				this->callEventCallback(pChara);

				//戻すべき位置の値

				//タイルのサイズ（32,32）
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロック数*ブロックの高さ
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//戻すべき位置
				//		修正位置（キャラクターがめり込んでるブロックの下の位置）＝
				//		キャラクターがめり込んでるブロックの下のブロックの位置　+　ブロック1個分　-位置ｙ
				//めり込んだ分の計算
				float boundary = (pt.x) - (blockPos); // + tileSize.width

				//最終的に戻す（値めり込んでる分を修正）
				pChara->m_pMove->m_pos.x -= boundary;

				//リセット値
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}
	}
}
//=====================================
// 左にあるマップチップ領域との衝突判定
//=====================================
/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 * @param	基準点
 */
void CCollisionTerritoryMapChipLeft::collision(CCharacter* pChara, cocos2d::Point basePt) {

	//左に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.x < 0.0f) {

		//衝突してきた点（キャラクターの点）
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);

		//衝突いてるかどうか
		if (CMapManager::getInstance()->getMap()->hitTest(pt.x, pt.y)) {


			//衝突してた

			//ブロックのタイプを取得
			BLOCK_TYPE mapCcipID = CMapManager::getInstance()->getMap()->checkTile(pt.x, pt.y);

			//衝突するブロックかどうか
			if (mapCcipID != BLOCK_TYPE::NONE) {

				//イベントコールバックの呼び出し
				this->callEventCallback(pChara);

				//戻すべき位置の値

				//タイルのサイズ（32,32）
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロック数*ブロックの高さ
				float blockPos = floor((pt.x) / tileSize.width)*tileSize.width;

				//戻すべき位置
				//		修正位置（キャラクターがめり込んでるブロックの下の位置）＝
				//		キャラクターがめり込んでるブロックの下のブロックの位置　+　ブロック1個分　-位置ｙ
				//めり込んだ分の計算
				float boundary = (pt.x) - (blockPos + tileSize.width);

				//最終的に戻す（値めり込んでる分を修正）
				pChara->m_pMove->m_pos.x -= boundary;

				//リセット値
				pChara->m_pMove->m_vel.x = 0.0f;
				pChara->m_pMove->m_accele.x = 0.0f;
			}
		}
	}
}



//====================================================================
//
//	Class: CCollisionTerritoryMapObjectBottom
//	
//	下にあるマップオブジェクト領域との衝突判定
//
//	2016/12/19
//									Author Shinya Ueba
//====================================================================
/**
* @desc コンストラクタ
*		領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
*		設定しておく
*/
CCollisionTerritoryMapObjectBottom::CCollisionTerritoryMapObjectBottom() 
	:CCollisionTerritory(TERRITORY_TYPE::BOTTOM)
{


}

/**
* @desc デストラクタ
*/
CCollisionTerritoryMapObjectBottom::~CCollisionTerritoryMapObjectBottom()
{


}

/**
* @desc 衝突判定
* @param 衝突対象のキャラクター
* @param 基準点
*/
void CCollisionTerritoryMapObjectBottom::collision(CCharacter* pChara, cocos2d::Point basePt)
{
	//下に移動しているかどうかチェック
	if (pChara->m_pMove->m_vel.y < 0.0f) 
	{
		//衝突してきた点（キャラクターの点）
		cocos2d::Point pt(pChara->m_pMove->m_pos.x + basePt.x, pChara->m_pMove->m_pos.y + basePt.y);

		//衝突いてるかどうか
		if (CMapManager::getInstance()->getMap()->hitTestObject(pt.x, pt.y))
		{

				//衝突してた
				//タイルのサイズ（32,32）
				Size tileSize = CMapManager::getInstance()->getMap()->getTileSize();

				//キャラクターがめり込んでいるブロックの下のブロックの位置　＝　ブロック数*ブロックの高さ
				float blockPos = floor((pt.y) / tileSize.height)*tileSize.height;

				//戻すべき位置
				//		修正位置（キャラクターがめり込んでるブロックの下の位置）＝
				//		キャラクターがめり込んでるブロックの下のブロックの位置　+　ブロック1個分　-位置ｙ
				//めり込んだ分の計算
				float boundary = (pt.y) - (blockPos + tileSize.height);

				//最終的に戻す（値めり込んでる分を修正）
				pChara->m_pMove->m_pos.y -= boundary;

				//リセット値
				pChara->m_pMove->m_vel.y = 0.0f;
				pChara->m_pMove->m_accele.y = 0.0f;

				//イベントコールバックの呼び出し
				this->callEventCallback(pChara);
		}
	}
}



//=====================================
//
// 衝突判定空間
//
//=====================================

//=====================================
// 画面端との衝突判定空間
//=====================================
//デフォルトコンストラクタ
CCollsionAreaEndOfScreen::CCollsionAreaEndOfScreen() {}

//コンストラクタ
CCollsionAreaEndOfScreen::CCollsionAreaEndOfScreen(CBody* pBody){

	//画面端の衝突空間に衝突を行う基準点を設定
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(pBody->m_left, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(0, pBody->m_top)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(pBody->m_right, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, pBody->m_bottom)));
}

/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 */
void CCollsionAreaEndOfScreen::collision(CCharacter* pChara) {

	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories)) {
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints)) {

			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type) {
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}

}



//=====================================
// 画面上にある全てのマップチップとの衝突判定空間
//　つまりマップチップとの衝突判定空間
//=====================================
//デフォルトコンストラクタ
CCollsionAreaMap::CCollsionAreaMap(){}

//コンストラクタ
CCollsionAreaMap::CCollsionAreaMap(CBody* pBody,float width, float height) {

	//繰り返し回数を設定
	float repetitionNumber = (pBody->m_right - pBody->m_left) / (CMapManager::getInstance()->getMap()->getTileSize().width * 0.5f);
	//基準点の設定
	for (int i = 1; i < repetitionNumber; i++) {
		//下のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(width - (16.0f * i), pBody->m_bottom)));

		//上のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(width - (16.0f * i), pBody->m_top)));
	}

	//繰り返し回数を設定
	repetitionNumber = (pBody->m_top - pBody->m_bottom) / (CMapManager::getInstance()->getMap()->getTileSize().height * 0.5f);
	for (int i = 1; i < repetitionNumber; i++) {
		//右のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(pBody->m_right * 0.5f, height - (16.0f * i))));

		//左のマップチップ衝突空間に衝突を行う下の基準点を設定（下に落ちないようにxをちょっとずらす）
		this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(pBody->m_left * 0.5f, height - (16.0f * i))));
	}

}

/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 */
void CCollsionAreaMap::collision(CCharacter* pChara) {

	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories)) {
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints)) {

			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type) {
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}

}

//====================================================================
//
//	Class: CCollsionAreaMapObject
//	
//	画面上にある全てのマップオブジェクトとの衝突判定空間
//
//	2016/12/19
//									Author Shinya Ueba
//====================================================================

/**
 * @desc	コンストラクタ
 */
CCollsionAreaMapObject::CCollsionAreaMapObject(void)
{

}

/**
 * @desc	デストラクタ
 */
CCollsionAreaMapObject::~CCollsionAreaMapObject(void)
{

}

/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 */
void CCollsionAreaMapObject::collision(CCharacter* pChara)
{
	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories)) {
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints)) {

			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type) {
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}
}



//=====================================
// 画面外との衝突判定空間
//=====================================
//デフォルトコンストラクタ
CCollsionAreaOutOfScreen::CCollsionAreaOutOfScreen() {}


//コンストラクタ
CCollsionAreaOutOfScreen::CCollsionAreaOutOfScreen(CBody* pBody) {

	//画面端の衝突空間に衝突を行う基準点を設定
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::LEFT, cocos2d::Point(pBody->m_right, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::TOP, cocos2d::Point(0, pBody->m_bottom)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::RIGHT, cocos2d::Point(pBody->m_left, 0)));
	this->addBasePoint(new CCollisionBasePoint(TERRITORY_TYPE::BOTTOM, cocos2d::Point(0, pBody->m_top)));
}

/**
 * @desc	衝突判定
 * @param	衝突対象のキャラクター
 */
void CCollsionAreaOutOfScreen::collision(CCharacter* pChara) {

	//領域分繰り返す
	for (CCollisionTerritory* pTerritory : (*this->m_pTerritories)) {
		//基準点分繰り返す
		for (CCollisionBasePoint* pBasePt : (*this->m_pBasePoints)) {

			//基準点の中に登録されている衝突判定領域タイプが一致したらその基準点で衝突判定を行う
			if (pBasePt->m_type == pTerritory->m_type) {
				pTerritory->collision(pChara, pBasePt->m_pt);
			}
		}
	}
}