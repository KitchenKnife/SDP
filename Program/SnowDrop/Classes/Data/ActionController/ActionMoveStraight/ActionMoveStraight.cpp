//==========================================
//
// File: ActionMoveStraight.h
//
// アクション　直線移動 ヘッダーファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "ActionMoveStraight.h"
#include "Model\Character\Character.h"

//==========================================
//
// Class: ActionMoveStraight
//
// アクション　直線移動		クラス
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CActionMoveStraight::CActionMoveStraight()
{
	//生成と同時に開始
	this->start();
}

/**
* @desc アクション開始
*/
void CActionMoveStraight::start(void)
{
	//アクション開始
	this->m_inAction = true;
}

/**
* @desc 更新処理
* @param アクションを行う対象のキャラクター
*/
void CActionMoveStraight::update(CCharacter* pChara)
{
	if (this->m_inAction != false)
	{
		pChara->m_pMove->m_vel.x = pChara->m_pMove->m_vel.x;
		pChara->m_pMove->m_vel.y = pChara->m_pMove->m_vel.y;
	}
	this->stop();
}

/**
* @desc アクション終了
*/
void CActionMoveStraight::stop(void)
{
	//アクション終了
	this->m_inAction = false;
}