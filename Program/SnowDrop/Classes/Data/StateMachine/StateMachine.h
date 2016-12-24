#pragma once
//==========================================
//
// File: StateMachine.h
//
// 状態遷移マシン ヘッダーファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include <map>

//==========================================
//
// Class: CStateBase
//
// 状態遷移 基底クラス  
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CStateBase
{
public:
	/**
	* @desc コンストラクタ
	*/
	CStateBase(void);

	/**
	* @desc デストラクタ
	*/
	virtual ~CStateBase(void);

	/**
	* @desc	開始処理
	*/
	virtual void start(void) = 0;

	/**
	* @desc 更新処理
	*/
	virtual void update(void) = 0;

	/**
	* @desc 状態が変わるときの処理
	*/
	virtual void onChangeEvent(void) = 0;

	/**
	* @desc 切り替える条件を取得
	*/
	bool isNext(void);

	/**
	* @desc 次の状態のキーを取得する
	*/
	int getNextKey(void);

protected:
	// 次に行くための条件
	bool m_isNext = false;

	//次に進むステートのキー
	int m_nextRegisterKey = 0;
};


//==========================================
//
// Class: CStateMachine
//
// 状態管理クラス
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
class CStateMachine
{
public:
	/**
	* @desc コンストラクタ
	*/
	CStateMachine(void);

	/**
	* @desc デストラクタ
	*/
	~CStateMachine(void);

	/**
	* @desc 更新処理
	*/
	void update(void);
	
	/**
	* @desc 状態を登録する
	* @param 登録する唯一無二のキー
	* @param 登録する状態
	*/
	void registerState(const int key, CStateBase* const pState);

	// 最初から始める状態を設定
	
	/**
	* @desc 最初から開始する状態を設定する
	* @param　設定するキー
	*/
	void setStartState(const int key);

	// 登録したものを削除する
	
	/**
	* @desc 登録したものを削除する
	* @param 削除するキー
	*/
	void deregistration(const int key);

	/**
	* @desc 全ての登録を削除する
	*/
	void allDeregistration(void);

private:
	//状態格納用マップ
	std::map<int, CStateBase* > m_mapState;
	//現在の状態
	CStateBase* m_pNowState = NULL;
};
//EOF