//==========================================
//
// File: ActionIdle.cpp
//
// アクション　待機 　ファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "ActionIdle.h"
#include "Model\Character\Character.h"

//==========================================
//
// Class: ActionIdle
//
// アクション　待機		クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CActionIdle::CActionIdle()
{
	//生成と同時に開始
	this->start();
}

/**
* @desc アクション開始
*/
void CActionIdle::start(void)
{
	//アクション開始
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionIdle::update(CCharacter* pChara)
{
	
}

/**
* @desc アクション終了
*/
void CActionIdle::stop(void)
{
	//アクション終了
	this->m_inAction = false;
}


