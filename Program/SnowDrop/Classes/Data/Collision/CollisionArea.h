#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "cocos2d.h"
#include "Constants.h"
#include "Collision.h"

//=====================================
// 前方宣言
//=====================================
class CCharacter;

//=====================================
// 領域タイプ
//=====================================
enum class TERRITORY_TYPE :int {
	LEFT,
	TOP,
	RIGHT,
	BOTTOM,
};

//=====================================
// 衝突基準点
//=====================================
class CCollisionBasePoint {
public:
	//領域タイプ
	TERRITORY_TYPE m_type;
	//基準点
	cocos2d::Point m_pt;

	//コンストラクタ
	CCollisionBasePoint(TERRITORY_TYPE type, cocos2d::Point pt) 
		:m_type(type), m_pt(pt){}
};

//=====================================
//
// 衝突判定領域
//
//=====================================
class CCollisionTerritory {
public:
	//領域タイプ
	TERRITORY_TYPE m_type;

	//コンストラクタ
	CCollisionTerritory(TERRITORY_TYPE type):m_type(type) {}

	//デストラクタ
	virtual ~CCollisionTerritory() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	virtual void collision(CCharacter* pChara, cocos2d::Point basePt) = 0;

public:
	//イベントコールバック
	//void (CCharacter::*型名)（int event）typedef
	//typedefをクラス内に記述することで
	//クラスだけに有効なtypedefとなる
	typedef void(CCharacter::*EventCallback)(int event);

	//ここで　*EventCallback　は　戻り値がvoid、引数がint　の関数のアドレスを格納できる関数ポインタを意味する。
	//引数の　変数eventは　今回イベントのコールバックということをわかりやすくするための単なる名前なので　event自体に意味はない

protected:
	//イベントコールバック
	EventCallback m_pEventCallBack = NULL;
public:
	/**
	 * @desc	イベントコールバックの設定
	 * @param	設定するコールバックイベント
	 * @tips	領域を生成し、生成した領域に
	 *　　　	イベントコールバック（メンバ関数ポインタ）を設定することで　
	 *　　　　	その領域イベントが発生したときに
	 *　　　　	登録したメンバ関数ポインタが呼び出される
	 */
	void setEventCallback(EventCallback pEventCallback) {
		this->m_pEventCallBack = pEventCallback;
	}

	/**
	 * @desc	イベントコールバックの呼び出し
	 * @param	呼びだすインスタンス
	 * @param	イベント
	 *　　　	マップちっぷの際はマップチップIDをイベントとして渡すが
	 *　　　	画面端などはイベントは存在しないので
	 *　　　	デフォルト値として0を設定しておく
	 * @tips	領域のイベントの発生時にこのメンバ関数を呼び出すことで
	 *　　　	登録したメンバ関数が呼び出される　
	 */
	void callEventCallback(CCharacter* pChara, int event = 0);

};

//=====================================
// 下にある画面端領域との衝突判定
//=====================================
class CCollisionTerritoryEndOfScreenBottom :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryEndOfScreenBottom():CCollisionTerritory(TERRITORY_TYPE::BOTTOM) {}

	//デストラクタ
	virtual ~CCollisionTerritoryEndOfScreenBottom() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;

};
//=====================================
// 上にある画面端領域との衝突判定
//=====================================
class CCollisionTerritoryEndOfScreenTop :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryEndOfScreenTop() :CCollisionTerritory(TERRITORY_TYPE::TOP) {}

	//デストラクタ
	virtual ~CCollisionTerritoryEndOfScreenTop() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// 右にある画面端領域との衝突判定
//=====================================
class CCollisionTerritoryEndOfScreenRight :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryEndOfScreenRight() :CCollisionTerritory(TERRITORY_TYPE::RIGHT) {}

	//デストラクタ
	virtual ~CCollisionTerritoryEndOfScreenRight() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// 左にある画面端領域との衝突判定
//=====================================
class CCollisionTerritoryEndOfScreenLeft :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryEndOfScreenLeft() :CCollisionTerritory(TERRITORY_TYPE::LEFT) {}

	//デストラクタ
	virtual ~CCollisionTerritoryEndOfScreenLeft() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//=====================================
// 下にある画面外領域との衝突判定
//=====================================
class CCollisionTerritoryOutOfScreenBottom :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryOutOfScreenBottom() :CCollisionTerritory(TERRITORY_TYPE::BOTTOM) {}

	//デストラクタ
	virtual ~CCollisionTerritoryOutOfScreenBottom() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;

};
//=====================================
// 上にある画面外領域との衝突判定
//=====================================
class CCollisionTerritoryOutOfScreenTop :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryOutOfScreenTop() :CCollisionTerritory(TERRITORY_TYPE::TOP) {}

	//デストラクタ
	virtual ~CCollisionTerritoryOutOfScreenTop() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// 右にある画面外領域との衝突判定
//=====================================
class CCollisionTerritoryOutOfScreenRight :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryOutOfScreenRight() :CCollisionTerritory(TERRITORY_TYPE::RIGHT) {}

	//デストラクタ
	virtual ~CCollisionTerritoryOutOfScreenRight() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// 左にある画面外領域との衝突判定
//=====================================
class CCollisionTerritoryOutOfScreenLeft :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryOutOfScreenLeft() :CCollisionTerritory(TERRITORY_TYPE::LEFT) {}

	//デストラクタ
	virtual ~CCollisionTerritoryOutOfScreenLeft() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};


//=====================================
// 下にあるマップチップ領域との衝突判定
//=====================================
class CCollisionTerritoryMapChipBottom :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryMapChipBottom():CCollisionTerritory(TERRITORY_TYPE::BOTTOM) {}

	//デストラクタ
	virtual ~CCollisionTerritoryMapChipBottom() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// 上にあるマップチップ領域との衝突判定
//=====================================
class CCollisionTerritoryMapChipTop :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryMapChipTop() :CCollisionTerritory(TERRITORY_TYPE::TOP) {}

	//デストラクタ
	virtual ~CCollisionTerritoryMapChipTop() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// 右にあるマップチップ領域との衝突判定
//=====================================
class CCollisionTerritoryMapChipRight :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryMapChipRight() :CCollisionTerritory(TERRITORY_TYPE::RIGHT) {}

	//デストラクタ
	virtual ~CCollisionTerritoryMapChipRight() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};
//=====================================
// 左にあるマップチップ領域との衝突判定
//=====================================
class CCollisionTerritoryMapChipLeft :public CCollisionTerritory {
public:
	/**
	 * @desc	コンストラクタ
	 *			領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	 *			設定しておく
	 */
	CCollisionTerritoryMapChipLeft() :CCollisionTerritory(TERRITORY_TYPE::LEFT) {}

	//デストラクタ
	virtual ~CCollisionTerritoryMapChipLeft() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @param	基準点
	 */
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};





//====================================================================
//
//	Class: CCollisionTerritoryMapObjectBottom
//	
//	下にあるマップオブジェクト領域との衝突判定
//
//	2016/12/19
//									Author Shinya Ueba
//====================================================================
class CCollisionTerritoryMapObjectBottom :public CCollisionTerritory {
public:
	/**
	* @desc コンストラクタ
	*		領域タイプの設定を初期化子でTERRITORY_TYPE::BOTTOMに
	*		設定しておく
	*/
	CCollisionTerritoryMapObjectBottom();

	/**
	* @desc デストラクタ
	*/
	virtual ~CCollisionTerritoryMapObjectBottom();

	/**
	* @desc 衝突判定
	* @param 衝突対象のキャラクター
	* @param 基準点
	*/
	void collision(CCharacter* pChara, cocos2d::Point basePt)override;
};



//=====================================
//
// 衝突判定空間
//
//=====================================
class CCollisionArea {
protected:
	//衝突基準点群
	std::vector<CCollisionBasePoint*>* m_pBasePoints = NULL;

	//衝突判定群
	std::vector<CCollisionTerritory*>* m_pTerritories = NULL;


public:
	//コンストラクタ
	CCollisionArea(){
		//衝突基準点群の生成
		this->m_pBasePoints = new std::vector<CCollisionBasePoint*>();

		//衝突判定群の生成
		this->m_pTerritories = new std::vector<CCollisionTerritory*>();
	}

	//デストラクタ
	virtual ~CCollisionArea(){

		//衝突基準点群の解放
		for (CCollisionBasePoint* pBasePoint : (*this->m_pBasePoints)) {

			SAFE_DELETE(pBasePoint);
		}
		SAFE_DELETE(this->m_pBasePoints);

		//衝突判定群の解放
		for(CCollisionTerritory* pTerritory: (*this->m_pTerritories)){

			SAFE_DELETE(pTerritory);
		}
		SAFE_DELETE(this->m_pTerritories);
	}

	/**
	 * @desc	衝突基準点の追加
	 * @param	衝突基準点
	 */
	void addBasePoint(CCollisionBasePoint* pBasePoints) {
		this->m_pBasePoints->push_back(pBasePoints);
	}

	/**
	 * @desc	衝突判定領域の追加
	 * @param	衝突判定領域
	 */
	void addTerritory(CCollisionTerritory* pTerritory) {
		this->m_pTerritories->push_back(pTerritory);
	}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 * @tips	毎フレーム呼び出す
	 */
	virtual void collision(CCharacter* pChara) = 0;

};

//=====================================
// 画面端との衝突判定空間
//=====================================
class CCollsionAreaEndOfScreen : public CCollisionArea {
public:
	//デフォルトコンストラクタ
	CCollsionAreaEndOfScreen();

	//コンストラクタ
	CCollsionAreaEndOfScreen(CBody* pBody);

	//デストラクタ
	~CCollsionAreaEndOfScreen(){}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 */
	void collision(CCharacter* pChara)override;

};

//=====================================
// 画面上にある全てのマップチップとの衝突判定空間
//　つまりマップチップとの衝突判定空間
//=====================================
class CCollsionAreaMap : public CCollisionArea {
public:
	//デフォルトコンストラクタ
	CCollsionAreaMap();

	//コンストラクタ
	CCollsionAreaMap(CBody* pBody, float width, float height);

	//デストラクタ
	~CCollsionAreaMap() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 */
	void collision(CCharacter* pChara)override;

};


//====================================================================
//
//	Class: CCollsionAreaMapObject
//	
//	画面上にある全てのマップオブジェクトとの衝突判定空間
//
//	2016/12/19
//									Author Shinya Ueba
//====================================================================
class CCollsionAreaMapObject : public CCollisionArea {
public:
	
	/**
	* @desc コンストラクタ
	*/
	CCollsionAreaMapObject(void);

	/**
	* @desc デストラクタ
	*/
	~CCollsionAreaMapObject(void);

	/**
	* @desc 衝突判定
	* @param 衝突対象のキャラクター
	*/
	void collision(CCharacter* pChara)override;

};


//=====================================
// 画面外との衝突判定空間
//=====================================
class CCollsionAreaOutOfScreen : public CCollisionArea {
public:
	//デフォルトコンストラクタ
	CCollsionAreaOutOfScreen();

	//コンストラクタ
	CCollsionAreaOutOfScreen(CBody* pBody);

	//デストラクタ
	~CCollsionAreaOutOfScreen() {}

	/**
	 * @desc	衝突判定
	 * @param	衝突対象のキャラクター
	 */
	void collision(CCharacter* pChara)override;

};
