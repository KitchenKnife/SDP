//==========================================
//
// File: GirlState.cpp
//
// Girl状態遷移 ファイル
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "GirlState.h"


//==========================================
//
// Class: CGirlStandState
//
// Girl 立ち 状態 クラス
//
// 2016/12/23
//						Author Shinya Ueba
//==========================================
/**
* @desc コンストラクタ
*/
CGirlStandState::CGirlStandState(int nextRegisterKey)
	:CStateBase::CStateBase(nextRegisterKey)
{


}

/**
* @desc デストラクタ
*/
CGirlStandState::~CGirlStandState()
{

}

/**
* @desc 開始処理
*/
void CGirlStandState::start()
{
	//std::cout << "PlayerMover : " << "スタート" << std::endl;
}

/**
* @desc 更新処理
*/
void CGirlStandState::update()
{
	//std::cout << "PlayerMover : " << "アップデート" << std::endl;
	//isNext = true;
}

// 状態が変わるときの処理
void CGirlStandState::onChangeEvent()
{
	this->m_isNext = false;
	//		std::cout << "PlayerMover : " << "切り替わるイベントに入った" << std::endl;
}
//EOF