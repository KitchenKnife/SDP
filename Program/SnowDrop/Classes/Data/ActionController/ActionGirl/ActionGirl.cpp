#include "ActionGirl.h"
#include "Model/Character/Character.h"
#include "Lib\Math\CustomMath.h"

/*
 * @desc	更新処理
 * @param	アクションする対象のキャラクター（少女）
 */
void CGirlActionGraspHand::update(CCharacter* pChara) {
	//プレイヤーと少女の距離を求める
	float distanceToGirl = customMath->lengthBitweenChara(this->m_pPlayerChara, pChara);

	//距離が35以上なら
	if (distanceToGirl >= 35) {
		//プレイヤーが少女より右の位置にいれば
		if (this->m_pPlayerChara->m_pMove->m_pos.x > pChara->m_pMove->m_pos.x) {
			pChara->m_pMove->m_pos.set(this->m_pPlayerChara->m_pMove->m_pos.x - 35.0f, this->m_pPlayerChara->m_pMove->m_pos.y);
		}
		//左にいれば
		else {
			pChara->m_pMove->m_pos.set(this->m_pPlayerChara->m_pMove->m_pos.x + 35.0f, this->m_pPlayerChara->m_pMove->m_pos.y);
		}
	}
}


//===================================================================
// 少女のお姫様抱っこアクション
//===================================================================
/*
 * @desc	更新処理
 * @param	アクションする対象のキャラクター（少女）
 */
void CGirlActionHoldThePrincess::update(CCharacter* pChara) {
	
	pChara->m_pMove->m_pos.set(this->m_pPlayerChara->m_pMove->m_pos.x, this->m_pPlayerChara->m_pMove->m_pos.y + 30);

}