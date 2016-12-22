/*
* EnemyActionController.h
*
*	2016/12/20	Osumi
*
*/
#include "Data/ActionController/ActionController.h"

//敵クラスの前方宣言
//class CEnemyCharacter;

//===================================================================
//　敵の動作の派生元
//===================================================================
class CEnemyAction :public CAction {
public:
	//ターゲットの種類
	enum class TARGET_TYPE :int {
		NONE,
		BOY,
		GIRL,
		BOTH
	};

public:
	virtual ~CEnemyAction() {}

	/*
	* @desc 2点間の距離を求める式
	* @param 点1
	* @param 点2
	* @return 点1と点2の距離
	*/
	virtual float length(cocos2d::Point pt1, cocos2d::Point pt2);

	/*
	* @desc 2体のキャラの距離を求める式
	* @param　キャラ1
	* @param　キャラ2
	* @return キャラ1とキャラ2の距離
	*/
	virtual float lengthBitweenChara(CCharacter* pChara1, CCharacter* pChara2);

	/*
	* @desc ターゲットの探索と選択
	* @param アクションを行うキャラクター
	* @return ターゲットが決まったかどうか　true...決まった
	* @tips 少女と騎士で敵に近い方の距離を導き
	*　　　 近い方が追跡範囲にならターゲットに設定
	*/
	virtual bool seachAndSelectTarget(CCharacter* pChara);

	/*
	* @desc ターゲットが間合いにいるかどうかのか確認と追跡状態への移行
	* @param アクションを行うキャラクター
	* @param ターゲットのタイプ
	*/
	virtual void checkTargetAndSwitchChase(CCharacter* pChara, TARGET_TYPE type);

	/*
	* @desc キャラからターゲットへのX方向の正規化ベクトルを求めて水平移動速度を設定
	* @param アクションを行うキャラクター
	* @param 目標地点の座標
	*/
	virtual void normalizeVel_X(CCharacter* pChara, cocos2d::Point pt);

	/*
	* @desc 目標地点までの正規化ベクトルにキャラのスピードかけた値を設定する
	* @param アクションを行うキャラクター
	* @param 目標地点の座標
	*/
	virtual void normalizeVel(CCharacter* pChara, cocos2d::Point pt);

};

//===================================================================
//　敵の待機動作
//===================================================================
class CEnemyActionStay :public CEnemyAction {
protected:

	//アクション中かどうか true...アクション中
	bool m_inAction = false;

	//アクションが開始状態かどうか　true...開始状態
	bool m_isStart = false;

	//検索すべきターゲット
	TARGET_TYPE m_defaultTarget = TARGET_TYPE::NONE;

public:
	/*
	* @desc コンストラクタ
	* @param 追跡すべきプレイヤータイプ
	*/
	CEnemyActionStay(TARGET_TYPE type);

	/*
	* @desc 開始処理
	*/
	virtual void start()override;

	/*
	* @desc 更新処理
	* @param アクションを行うキャラクター
	*/
	virtual void update(CCharacter* pChara)override;

	/*
	* @desc 終了処理処理
	*/
	virtual void stop() override;
};
//===================================================================
//　敵の時間経過による待機動作
//===================================================================
class CEnemyActionStayAtTime :public CEnemyActionStay {
private:
	//アクションを行う時間（ランダムで30～60で設定される）
	int m_actionInterval = 45;

	int m_actionCounter = 0;

public:

	/*
	* @desc 開始処理
	*/
	void start()override;

	/*
	* @desc コンストラクタ
	* @param 追跡すべきプレイヤータイプ
	*/
	CEnemyActionStayAtTime(TARGET_TYPE type);

	/*
	* @desc 更新処理
	* @param アクションを行うキャラクター
	*/
	void update(CCharacter* pChara)override;

};

//===================================================================
//　敵のうろうろ動作
//===================================================================
class CEnemyActionWondering :public CEnemyAction {
private:
	//アクションを行う時間（ランダムで30～60で設定される）
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//うろうろする方向
	int m_vec = 1;

	//アクション中かどうか true...アクション中
	bool m_inAction = false;

	//アクションが開始状態かどうか　true...開始状態
	bool m_isStart = false;
	
	//検索すべきターゲット
	TARGET_TYPE m_defaultTarget = TARGET_TYPE::NONE;

public:
	/*
	* @desc コンストラクタ
	* @param 追跡すべきプレイヤータイプ
	*/
	CEnemyActionWondering(TARGET_TYPE type);

	/*
	* @desc 開始処理
	*/
	void start()override;

	/*
	* @desc 更新処理
	* @param アクションを行うキャラクター
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了処理処理
	*/
	void stop() override;
};

//===================================================================
//　敵の追跡動作
//===================================================================
class CEnemyActionChase :public CEnemyAction {

private:

	//アクションを行う時間（ランダムで30～60で設定される）
	int m_actionInterval = 45;

	int m_actionCounter = 0;

	//うろうろする方向
	int m_vec = 1;

	//アクション中かどうか true...アクション中
	bool m_inAction = false;

	//アクションが開始状態かどうか　true...開始状態
	bool m_isStart = false;

	//追跡動作を行う敵が飛行するかどうか
	bool m_isFlying = false;

public:
	/*
	* @desc コンストラクタ
	* @param キャラクターが飛ぶかどうか（デフォルトはfalse）
	*/
	CEnemyActionChase(bool isFlying = false);

	/*
	* @desc 開始処理
	*/
	void start()override;

	/*
	* @desc 更新処理
	* @param アクションを行うキャラクター
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了処理処理
	*/
	void stop() override;
};

//===================================================================
//　敵の出現地点に戻る動作
//===================================================================
class CEnemyActionReturnLanchPos :public CEnemyActionStay {
private:
	//出現位置
	cocos2d::Point m_launchPos;

public:
	/*
	* @desc コンストラクタ
	* @param 追跡すべきプレイヤータイプ
	*/
	CEnemyActionReturnLanchPos(TARGET_TYPE type, CCharacter* pChara);

	/*
	* @desc 開始処理
	*/
	void start()override;

	/*
	* @desc 更新処理
	* @param アクションを行うキャラクター
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了処理処理
	*/
	void stop() override;
};