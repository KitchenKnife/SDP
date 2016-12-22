
/*
* EnemyCharacter.h
*
*	2016/11/11	Yamasaki 
*
*/

#pragma once
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Model/Character/Character.h"
#include "Model/Map/Map.h"
#include "Data/Status/Status.h"

//================================================
// 
// 敵キャラクターの基底クラスとなるクラス
//		
//================================================
class CEnemyCharacter :public CCharacter {
public:
	//コンストラクタ
	CEnemyCharacter();

	//デストラクタ
	virtual ~CEnemyCharacter();

	//初期化処理
	bool init()override;

	//================================================
	// 
	//	定数に関するコードの追加はここから
	//		
	//================================================
	//敵の状態(アニメーションとアクションを管理)
	enum class STATE :int {
		NONE		= -1,
		STAND		= 0,
		JUMPING		= 0,
		WALK		= 1,
		FALING		= 2,
		ATTACK		= 3,
		CHASE		= 4,
		STAY		= 5,
		WANDERING	= 6,	//コウモリは出現位置に向かう、それ以外はさまよい行動
		DAMAGE		= 7,
		DIE			= 8,
	};


	CREATE_FUNC(CEnemyCharacter);

	//行えるアクション群
	//std::vector<CEnemyAction* >* m_pActions = NULL;

	/*
	* @desc	初期化処理
	* @param　初期化位置X 
	* @param　初期化位置Y
	* @tips　create()メンバ関数の中でinit()メンバ関数を呼び出してるが
	*		　今回、そのcreate()メンバ関数をオーバーロードして
	*		　引数を受け取っているので、init()メンバ関数も
	*		　オーバーロードする必要がある。
	*/
	bool init(float posX, float posY);

	/**
	* @desc CREATE_FUNCマクロの中身をそのままもってきただけ
	* @tips		前回は敵出撃データという敵専用のクラスが存在していたので
	*			このクラスに直書きしても問題なかったが
	*　　　　　 今回はマップの情報による出現位置の決定という項目が必要になる。
	*　　　　　 マップをシングルトン化したので直書きしても問題ないように思われるが
	*　　　　　 このタイミングでこの場所のマップのタイルの位置情報が必要になる。
	*　　　　　最終的に必要になるのは位置だけだ。
	*　　　　　なので生成と同時に位置を取得したい。
	*　　　　　だがしかし、cocos2dｘの機能である自動でdeleteの機能も使いたい
	*　　　　　なので、create静的メンバ関数をカスタマイズする。
	*/
	//CREATE_FUNC(CEnemyCharacter);
	

	

	/**
	* @desc CREATE_FUNCをオーバーロード
	* @param 初期位置
	* @param
	* @tips		前回は敵出撃データという敵専用のクラスが存在していたので
	*			このクラスに直書きしても問題なかったが
	*　　　　　 今回はマップの情報による出現位置の決定という項目が必要になる。
	*　　　　　 マップをシングルトン化したので直書きしても問題ないように思われるが
	*　　　　　 このタイミングでこの場所のマップのタイルの位置情報が必要になる。
	*　　　　　最終的に必要になるのは位置だけだ。
	*　　　　　なので生成と同時に位置を取得したい。
	*　　　　　だがしかし、cocos2dｘの機能である自動でdeleteの機能も使いたい
	*　　　　　なので、create静的メンバ関数をカスタマイズする。
	*/
	static CEnemyCharacter* create(float posX, float posY) {
		CEnemyCharacter* pRet = new(std::nothrow) CEnemyCharacter();

		if (pRet && pRet->init(posX, posY)) {
			pRet->autorelease();
			return pRet;
		}
		else {
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}





	//敵が行えるアクション
	enum class ACTION :int {
		ATTACK = 1,
		PURSUIT = 2,
		IDLE = 3,
		DAMAGE = 4,
	};

	//================================================
	// 
	// メンバーに関するコードの追加はここから
	//		
	//		
	//================================================

	//移動処理
	void moveFunc() override;

	//アニメーション処理
	void animationFunc()override;

	//衝突判定処理
	void collisionAll()override;

	//状態チェック
	void checkState() override;

	//反映処理
	void applyFunc() override;

	/**
	* @desc キャラクター1体との衝突判定処理
	* @param キャラクターのアドレス
	* @return true...衝突した
	*/
	bool collision(CCharacter* pChara)override;

	void hits(CCharacter* pChara)override{}


};

