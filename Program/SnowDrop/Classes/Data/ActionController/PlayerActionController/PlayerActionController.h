#pragma once

/*
* PlayerActionController.h
*
*	2016/11/24	Osumi
*
*/


#include "Data/ActionController/ActionController.h"
//#include "Model/Character/PlayerCharacter.h"

class CPlayerBoy;
class CPlayerGirl;
class CPlayerCharacter;
//class CPlayerCharacter;

class CPlayerAction :public CAction {
public:
	virtual ~CPlayerAction() {}
	//アクションを開始するたびに呼び出す
	void start()override {};
	//アクションの更新処理
	virtual void update(CCharacter* pChara) override {};
	//アクションを終了するたびに呼び出す
	virtual void stop() override {};

};


class CPlayerNoneAction:public CPlayerAction {
public:
	virtual ~CPlayerNoneAction() {}
	//アクションを開始するたびに呼び出す
	void start()override {};
	//アクションの更新処理
	virtual void update(CCharacter* pChara) override {};
	//アクションを終了するたびに呼び出す
	virtual void stop() override {};

};

//===================================================================
//	プレイヤーの持ち上げアクション	
//===================================================================
class CPlayerLiftUpAction :public CPlayerAction {
protected:

	//少女の基準点
	float m_girlGoalPoint = 0;

	//持ち上げ行動時の基準方向
	int m_liftVec = 0;

	//持ち上げ段階
	//  0...少年しゃがむ
	//　1...少女持ち上げ
	//　2...いったん停止　m_pauseTime　に依存
	//　...マップチップの沿うように円運動（少女）＆横に動く（少年）
	//  3...終了
	int m_LiftStep = 0;

	//停止時間
	int m_pauseTimeCounter = 0;

	//しゃがみにかかるコマ数
	int m_crouchFrame = 3;

	//しゃがみ中かどうかのフラグ	true...しゃがみ中
	//bool m_isCrouching = false;

	//持ち上げ開始フラグ
	//bool m_isLiftUpStart = false;

public:
	//コンストラクタ
	CPlayerLiftUpAction() {}
	CPlayerLiftUpAction(int crouchFrame) :
		 m_crouchFrame(crouchFrame){}

	/*
	* @desc 処理
	* @param 加速度
	* @tips ジャンプボタンが押された際に値の設定と共に呼び出す
	*/
	void start()override;

	/*
	* @desc 更新処理（ジャンプ移動計算）
	* @param 対象のキャラクター
	* @tips 関数を呼び出す
	*/
	void update(CCharacter* pChara);

	/*
	* @desc 終了
	* @tips 持ち上げ終わった時に関数を呼び出す
	*/
	void stop()override;

};


//===================================================================
//
//	少女の暇つぶしアクションの派生元
//
//===================================================================
class CGirlBaseWasteTimeAction :public CPlayerAction {
protected:

	//暇つぶしアクションの数
	const int m_actions = 2;

public:
	//コンストラクタ
	CGirlBaseWasteTimeAction() {}

	/*
	* @desc 暇つぶし開始処理
	* @tips 暇つぶし時間がある程度経過したらに呼び出す
	*/
	void start()override;

	/*
	* @desc 更新処理（ジャンプ移動計算）
	* @param 対象のキャラクター
	* @tips 関数を呼び出す
	*/
	void update(CCharacter* pChara);

	//暇つぶし行動の枝分かれ
	void branchWasteAction();

	/*
	* @desc　終了
	* @tips　着地した際にこの関数を呼び出す
	*/
	void stop()override;

};
//===================================================================
//
//	少女の暇つぶしアクション_00　基底クラス
//
//===================================================================
class CGirlWasteBaseAction :public CPlayerAction {
protected:

public:
	//コンストラクタ
	CGirlWasteBaseAction();
	//CGirlWasteBaseAction(CPlayerCharacter::STATE state);

	int m_actionTime;

	//少女のインスタンス
	CPlayerGirl* m_pGirl = NULL;

	//このアクションクラスのステイトタイプ
	//CPlayerCharacter::STATE m_stateType = CPlayerCharacter::STATE::NONE;

	/*
	* @desc 暇つぶし処理
	*/
	void start()override;

	/*
	* @desc　終了
	*/
	void stop()override;

};
//===================================================================
//	少女の暇つぶしアクション_01
//  上下に揺れる
//===================================================================
class CGirlWasteAction_01 :public CGirlWasteBaseAction {
protected:

	//このアクションクラスのステイトタイプ
	//CPlayerCharacter::STATE m_stateType = CPlayerCharacter::STATE::NONE;

public:
	//コンストラクタ
	CGirlWasteAction_01();

	/*
	* @desc 暇つぶし処理
	*/
	void start()override;

	/*
	* @desc 更新処理
	*/
	void update(CCharacter* pChara);

};

//===================================================================
//	少女の暇つぶしアクション_02
//　左右に歩く
//===================================================================
class CGirlWasteAction_02 :public CGirlWasteBaseAction {
protected:

	//このアクションクラスのステイトタイプ
	//CPlayerCharacter::STATE m_stateType;

	//const int m_waitTime = 30;
	int m_waitCounter = 0;

	/*
	* 0.移動する向きの設定
	* 1.向きに沿って移動
	* 2.立ち止まる
	* 3.向きに沿って移動
	*/
	int m_actionStep = 0;
	
	int m_vec = 1;

public:
	//コンストラクタ
	CGirlWasteAction_02();

	/*
	* @desc 暇つぶし処理
	*/
	void start()override;

	/*
	* @desc 更新処理
	*/
	void update(CCharacter* pChara);

};
