/*
* EnemyActionController.h
*
*	2016/12/20	Osumi
*
*/
#include "Data/ActionController/ActionController.h"

/*
//===================================================================
//　敵の動作の派生元
//===================================================================
class CEnemyAction :public CAction {
public:
	virtual ~CEnemyAction() {}
	//アクションを開始するたびに呼び出す
	void start()override {};
	//アクションの更新処理
	virtual void update(CCharacter* pChara) override {};
	//アクションを終了するたびに呼び出す
	virtual void stop() override {};
};

//===================================================================
//　敵のうろうろ動作
//===================================================================
class CEnemyActionWondering :public CEnemyAction {
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
	*
	int m_actionStep = 0;

	int m_vec = 1;

public:
	//コンストラクタ
	CEnemyActionWondering();

	/*
	* @desc 暇つぶし処理
	*
	void start()override;

	/*
	* @desc 更新処理
	*
	void update(CCharacter* pChara);

};
*/