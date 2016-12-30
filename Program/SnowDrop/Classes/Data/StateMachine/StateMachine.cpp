//==========================================
//
// File: StateMachine.cpp
//
// 状態遷移マシン ファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
#include"StateMachine.h"
#include "Constants.h"


/**
* @desc コンストラクタ
*/
CStateBase::CStateBase(void)
{

}

/**
* @desc デストラクタ
*/
CStateBase::~CStateBase(void)
{

}

/**
* @desc	開始処理
*/
void CStateBase::start(void)
{


}

/**
* @desc 更新処理
*/
void CStateBase::update(void)
{


}

/**
* @desc 状態が変わるときの処理
*/
void CStateBase::onChangeEvent(void)
{

}

/**
* @desc 切り替える条件を取得
*/
bool CStateBase::isNext(void)
{ 
	return this->m_isNext;
}

/**
* @desc 次の状態のキーを取得する
*/
int CStateBase::getNextKey(void)
{
	return this->m_nextRegisterKey;
}



//==========================================
//
// Class: CStateMachine
//
// 状態管理クラス
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CStateMachine::CStateMachine(void) :m_pNowState()
{

}

/**
* @desc デストラクタ
*/
CStateMachine::~CStateMachine(void)
{
	//取り付けた状態データを削除
	std::map<int, CStateBase* >::iterator itr = this->m_mapState.begin();
	while (itr != this->m_mapState.end()) {
		//クラスのインスタンスを削除
		SAFE_DELETE(itr->second);
		//イテレーターを更新
		itr++;
	}
}

/**
* @desc 更新処理
*/
void CStateMachine::update(void)
{
	if (!this->m_pNowState)
	{
		return;
	}
	
	//現在の状態を更新
	this->m_pNowState->update();

	//次の状態へ移れるか確認
	if (this->m_pNowState->isNext())
	{
		//現在のステートの終了処理を行う
		this->m_pNowState->onChangeEvent();

		std::map<int, CStateBase* >::iterator itr = this->m_mapState.find(this->m_pNowState->getNextKey());
		if (itr == this->m_mapState.end())
		{
			return;
		}
		//次の状態へ遷移
		this->m_pNowState = itr->second;
		//次の状態を開始
		this->m_pNowState->start();
	}
}

/**
* @desc 状態を登録する
* @param 登録する唯一無二のキー
* @param 
*/
void CStateMachine::registerState(const int key,CStateBase* const pState)
{
	//状態を登録する
	this->m_mapState[key] = pState;
}

/**
* @desc 最初から開始する状態を設定する
* @param 設定するキー
*/
void CStateMachine::setStartState(const int key)
{
	std::map<int, CStateBase* >::iterator itr = this->m_mapState.find(key);
	if (itr == this->m_mapState.end())
	{
		return;
	}
	
	this->m_pNowState = itr->second;
	this->m_pNowState->start();
}

/**
* @desc 登録したものを削除する
* @param 削除するキー
*/
void CStateMachine::deregistration(const int key)
{
	std::map<int, CStateBase* >::iterator itr = this->m_mapState.find(key);
	if (itr == this->m_mapState.end())
	{
		return;
	}
	this->m_mapState.erase(itr);
}

/**
* @desc 全ての登録を削除する
*/
void CStateMachine::allDeregistration(void)
{
	this->m_mapState.clear();
}
//EOF