/*
* PlayerEffectFactory.h
*
*	2016/11/25	Osumi
*
*/

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//　追加のインクルードはここから
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Data/Effect/PlayerEffect/PlayerEffectFactory.h"

//================================================
// エフェクトパーツクラス工場
//	（AbstractFactory）
//================================================

CMove* CPlayerEffactPartsFactory::getMove() {
	//移動データの作成
	return new CMove();
}
/*
CAnimation* CPlayerEffactPartsFactory::getAnimation() {

	//アニメーションデータの作成
	CAnimation* pAnimation = new CChipListAnimation();

	return pAnimation;
}
*/


//================================================
// エフェクトの生成と組み立てを担当するクラス
//	（FactoryMethod）
//================================================
//プレイヤーの生成と組み立て
CPlayerEffect* CDisappearEffectCreateFactory::createEffect() {

	CPlayerEffect* pEffect = CBoyDisappearEffect::create();

	//移動用データの取得
	pEffect->m_pMove = this->partsFactories[(int)CPlayerCharacter::EFFECT::DISAPPEAR]->getMove();

	return pEffect;
}

//================================================
// エフェクトのパーツのセッティングを担当するクラス
//	（FactoryMethod）
//================================================

//各々のパーツのセッティング
void CDisappearEffectFactory::settingMove(CPlayerEffect* pEffct, cocos2d::Point pt) {

	//初期位置の設定
	pEffct->m_pMove->m_pos.set(pt.x, pt.y);

	//初期速度の設定
	pEffct->m_pMove->setVel(0.0f, 3.0f);

}
void CDisappearEffectFactory::settingTexture(CPlayerEffect* pEffct) {
	//テクスチャの設定
	pEffct->setTexture(IMAGE_DIAPPEAR_EFFECT);

}

void CDisappearEffectFactory::settingAnimations(CPlayerEffect* pEffct) {

	//消失アニメーションの設定
	pEffct->m_pAnimationDatas = (new CChipListAnimation(10, false));

	//消失アニメーションに設定する為のチップデータの設定
	//1枚目
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 0, 256 * 1, 96, 96));
	//2枚目
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 1, 256 * 1, 96, 96));
	//3枚目
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 2, 256 * 1, 96, 96));
	//4枚目
	pEffct->m_pAnimationDatas->addChipData(new CChip(96 * 3, 256 * 1, 96, 96));

}


void CDisappearEffectFactory::settingInitialize(CPlayerEffect* pEffct) {

	//有効フラグを立てる
	pEffct->m_activeFlag = true;

	/*
	*　計算データのままで起動すると1フレームずれが発生するので
	*　初期化時に最後に値をSpriteに反映する
	*/
	pEffct->applyFunc();
}


//================================================
// パーツセッティングクラスを管理するクラス
//	（FactoryMethod）
//================================================
//共有のインスタンスの実体
CPlayerEffectFactoryManager* CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager = NULL;

//インスタンスの取得
CPlayerEffectFactoryManager* CPlayerEffectFactoryManager::getInstance() {

	if (CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager == NULL) {
		CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager = new CPlayerEffectFactoryManager();
	}

	return CPlayerEffectFactoryManager::m_pPlayerEffectFactoryManager;
}
