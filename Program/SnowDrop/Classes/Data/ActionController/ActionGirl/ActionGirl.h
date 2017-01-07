#pragma once
//==========================================
// ヘッダインクルード
//==========================================
#include "../Action.h"


//===================================================================
// 少女の手つなぎアクション
//===================================================================
class CGirlActionGraspHand :public CAction {
protected:

	//プレイヤーのアドレス
	CCharacter* m_pPlayerChara;
public:

	//デフォルトコンストラクタ
	CGirlActionGraspHand() {}
	//コンストラクタ（各種設定）
	CGirlActionGraspHand(CCharacter* pChara)
		:m_pPlayerChara(pChara) {}

	/*
	 * @desc	アクション開始
	 */
	void start()override {

	}


	/*
	 * @desc	更新処理
	 * @param	アクションする対象のキャラクター（少女）
	 */
	void update(CCharacter* pChara);

	/*
	 * @desc	アクション終了
	 */
	void stop()override {

	}
};

//===================================================================
// 少女のお姫様抱っこアクション
//===================================================================
class CGirlActionHoldThePrincess :public CAction {
protected:

	//プレイヤーのアドレス
	CCharacter* m_pPlayerChara;
public:

	//デフォルトコンストラクタ
	CGirlActionHoldThePrincess() {}
	//コンストラクタ（各種設定）
	CGirlActionHoldThePrincess(CCharacter* pChara)
		:m_pPlayerChara(pChara) {}

	/*
	* @desc	アクション開始
	*/
	void start()override {

	}


	/*
	* @desc	更新処理
	* @param	アクションする対象のキャラクター（少女）
	*/
	void update(CCharacter* pChara);

	/*
	* @desc	アクション終了
	*/
	void stop()override {

	}
};