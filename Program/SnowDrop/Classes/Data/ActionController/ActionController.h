/*
 * ActionController.h
 *
 *	2016/11/09	Osumi
 *
 */
#pragma once

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include"cocos2d.h"
#include"Constants.h"

//================================================
// 前方宣言に関するコードはここから書く
//================================================
class CCharacter;

//================================================
// アクションクラス
//================================================
class CAction {
public:
	//デストラクタ
	virtual ~CAction(){}

	//アクションを開始するたびに呼び出す
	virtual void start() = 0;

	//アクションの更新処理
	virtual void update(CCharacter* pChara) = 0;

	//アクションを終了するたびに呼び出す
	virtual void stop() = 0;


	/**
	 * @desc	アクションの再起動
	 * @param	再起動するキャラクター
	 * @tips	標準的なアクションの再起動
	 *　		ここではキャラクターは使用しない
	 */
	virtual void restart(CCharacter* pChara) {
		//アクションの停止
		this->stop();

		//アクションの開始
		this->start();
	}

};

//===================================================================
// ジャンプ
//		ジャンプに関する処理を行い内部処理として移動データに対して変更を加える
//		 tips:
//			cocos2dxのActionクラスにもジャンプは存在するが
//			Actionクラスに依存しているので重力や摩擦やマップチップなどの影響を考えると
//			初めのうちは分離して考えた方が理解しやすい
//===================================================================
class CActionJump :public CAction {
protected:

	//ジャンプの加速度
	float m_accele = 0.0f;
	//ジャンプブースト
	int m_boost = 0;

	//現在のジャンプブースト
	int m_currentBoost = 0;

	//ジャンプ中かどうかのフラグ	true...ジャンプ中
	bool m_isJumping = false;

	//ジャンプ開始フラグ
	bool m_isJumpStart = false;

public:
	//デフォルトコンストラクタ
	CActionJump(){}
	//コンストラクタ（各種設定）
	CActionJump(float accele, int boost)
		:m_accele(accele),m_boost(boost){}

	/*
	 * @desc	加速度とブーストの設定
	 * @param	加速度
	 * @param	ジャンプブースト
	 */
	void set(float accele, int boost)  {
		m_accele = accele;
		m_boost = boost;
	}

	/*
	 * @desc	ジャンプ開始
	 * @tips	ジャンプボタンが押された際に呼び出す
	 */
	void start()override {
		//ジャンプ開始フラグを上げる
		this->m_isJumpStart = true;
	}


	/*
	 * @desc	更新処理（ジャンプ移動計算）
	 * @param	ジャンプする対象のキャラクター
	 * @tips	上キーが押されたらこの関数を呼び出す
	 */
	void update(CCharacter* pChara); 

	/*
	 * @desc	ジャンプ終了
	 * @tips	着地した際に呼び出す
	 */
	void stop()override {
		//ジャンプ中フラグを下す
		this->m_isJumping = false;
	}

	/**
	* @desc	アクションの再起動
	* @param 再起動するキャラクター
	* @tips キャラクターのY成分のリセット
	*/
	void restart(CCharacter* pChara)override;
};
