#pragma once
//==========================================
//
// File: CharacterFactory.h
//
// キャラクター工場 ヘッダーファイル
//
// 2016/12/27
//						Author Shinya Ueba
//==========================================

//==========================================
// ヘッダインクルード
//==========================================
#include "Model\Character\Character.h"


//=============================================
//
// 前方宣言
//
//=============================================
class CCharacter;
class CGirlCharacter;
class CPlayerCharacterBoy;


//================================================
// キャラクターパーツクラス工場
//	（AbstractFactory）
//
//	2016/12/22
//									Author Harada
//================================================
class CCharacterPartsFactory {
public:
	//デストラクタ
	virtual ~CCharacterPartsFactory() {}

	//移動データの実体を生成して返す
	virtual CMove* getMove() = 0;
	//アニメーションデータ群の実体を生成して返す
	virtual std::vector<CAnimation* >* getAnimations() = 0;
	//物理演算データ群の実体を生成して返す
	virtual std::vector<CPhysical* >* getPhysicals() = 0;
	//実体データの実体を生成して返す
	virtual CBody* getBody() = 0;
	//衝突判定空間データ群の実体を生成して返す
	virtual std::vector<CCollisionArea* >* getCollisionAreas() = 0;
	//状態遷移データの生成と取得
	virtual	CStateMachine*	getStateMachine(void) { return NULL; }
};