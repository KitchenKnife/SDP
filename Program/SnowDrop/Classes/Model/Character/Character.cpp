/*
 * Character.cpp
 *
 *	2016/11/07	Osumi
 *
 */
#include "Character.h"

//================================================
// キャラクタークラス
//		全てのキャラクターの雛形となる抽象クラス
//
//	2016/12/22
//									Author Harada
//================================================
//コンストラクタ
CCharacter::CCharacter() {}

//デストラクタ

/**
*	@desc デストラクタ
*	@autor	Osumi
*	@autor	Harada
*	@autor	Shinya Ueba
*/
CCharacter::~CCharacter() {

	//状態遷移データの削除
	SAFE_DELETE(this->m_pStateMachine);

	//実体データの削除
	SAFE_DELETE(this->m_pBody);

	//アクション群データの削除
	std::map<int, std::vector<CAction*>* >::iterator itr = this->m_mapAction.begin();
	while (itr != this->m_mapAction.end()) {

		if (itr->second)
		{
			std::vector<CAction*>* pActions = itr->second;

			for (CAction* pAction : *pActions)
			{
				SAFE_DELETE(pAction);
			}
			//クラスのインスタンスを削除
			SAFE_DELETE(itr->second);
		}
		//イテレーターを更新
		itr++;
	}

	//物理演算群データの削除
	for (CPhysical* pPhysical : (*m_pPhysicals)) {
		SAFE_DELETE(pPhysical);
	}
	SAFE_DELETE(this->m_pPhysicals);

	//移動データの削除
	SAFE_DELETE(this->m_pMove);


	//アニメーションデータ群の削除
	for (CAnimation* pAnimation: (*m_pAnimations)) {
		SAFE_DELETE(pAnimation);
	}
	SAFE_DELETE(this->m_pAnimations);
}

//初期化処理
bool CCharacter::init() {
	//スプライトの初期化
	if (Sprite::init() == false) {
		//初期化に失敗した場合
		CCLOG("Spriteの初期化に失敗");
		return false;
	}
	//個別に更新処理を起動させる。
	this->scheduleUpdate();

	//初期化に成功した場合
	return true;
}

//更新処理
void CCharacter::update(float deltaTime) {


	//移動処理
	this->moveFunc();

	//アニメーション処理
	this->animationFunc();

	//衝突判定
	this->collisionAll();

	//状態チェック
	this->checkState();

	//反映処理
	this->applyFunc();
}

