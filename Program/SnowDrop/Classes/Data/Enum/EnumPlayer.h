#pragma once
//==========================================
//
// File: EnumPlayer.h
//
// プレイヤー　情報　列挙型			ヘッダーファイル
//
// 2016/12/24
//						Author Shinya Ueba
//==========================================



/********************************************************************
*
*
* プレイヤー　の列挙型 ここから
*
*
********************************************************************/

//---------------------------------------------------------
// Enum Class: PLAYER_AND_GIRL_STATE { int }
//
// プレイヤー　と　少女　の状態を列挙
//
//
//---------------------------------------------------------
enum class PLAYER_AND_GIRL_STATE :int
{
	FREE			= 0,	//少女となにもしていない状態
	GRAPS_HANDS		= 1,	//少女と手を握っている状態

};

//---------------------------------------------------------
// Enum Class: PLAYER_STATE { int }
//
// プレイヤー　の状態を列挙
//
//
//---------------------------------------------------------
enum class PLAYER_STATE :int
{
	IDLE_RIGHT			= 0,	//右待機状態
	IDLE_LEFT			= 1,	//左待機状態
	WALK_RIGHT			= 2,	//右歩行
	WALK_LEFT			= 3,	//左歩行
	JUMP_RIGHT			= 4,	//右向きジャンプ
	JUMP_LEFT			= 5,	//左向きジャンプ
	FALL_RIGHT			= 6,	//右向き落下
	FALL_LEFT			= 7,	//左向き落下
	ATTACK_RIGHT		= 8,	//右向き攻撃
	ATTACK_LEFT			= 9,	//左向き攻撃
	EQUIP_RIGHT			= 10,	//装備する		右向き
	EQUIP_LEFT			= 11,	//装備する		左向き
	UN_EQUIP_RIGHT		= 12,	//装備を外す	右向き	
	UN_EQUIP_LEFT		= 13,	//装備を外す	左向き
	GRASP_RIGHT			= 14,	//手を掴む・離す　右向き
	GRASP_LEFT			= 15,	//手を掴む・離す　左向き

};

//---------------------------------------------------------
// Enum Class: PLAYER_ANIMATION_STATE { int }
//
// プレイヤー　アニメーションの状態を列挙
//
//
//---------------------------------------------------------
enum class PLAYER_ANIMATION_STATE :int
{
	IDLE_RIGHT			= 0,	//右待機状態
	IDLE_LEFT			= 1,	//左待機状態
	WALK_RIGHT			= 2,	//右歩行
	WALK_LEFT			= 3,	//左歩行
	JUMP_RIGHT			= 4,	//右向きジャンプ
	JUMP_LEFT			= 5,	//左向きジャンプ
	FALL_RIGHT			= 6,	//右向き落下
	FALL_LEFT			= 7,	//左向き落下
	FIRST_ATTACK_RIGHT	= 8,	//右向き攻撃（１撃目）
	SECOND_ATTACK_RIGHT	= 9,	//右向き攻撃（２撃目）
	THURD_ATTACK_RIGHT	= 10,	//右向き攻撃（３撃目）
	FIRST_ATTACK_LEFT	= 11,	//左向き攻撃（１撃目）
	SECOND_ATTACK_LEFT	= 12,	//左向き攻撃（２撃目）
	THURD_ATTACK_LEFT	= 13,	//左向き攻撃（３撃目）
	EQUIP_RIGHT			= 14,	//装備する		右向き
	EQUIP_LEFT			= 15,	//装備する		左向き
	UN_EQUIP_RIGHT		= 16,	//装備を外す	右向き	
	UN_EQUIP_LEFT		= 17,	//装備を外す	左向き
	GRASP_RIGHT			= 18,	//手を掴む　右向き
	GRASP_LEFT			= 19,	//手を掴む　左向き
	GRAPS_ATTACK_RIGHT	= 20,	//手を掴んだ状態での攻撃	右向き
	GRAPS_ATTACK_LEFT	= 21,	//手を掴んだ状態での攻撃	左向き
};

//---------------------------------------------------------
// Enum Class: PLAYER_ACTION_STATE { int }
//
// プレイヤー　アクションの状態を列挙
//
//
//---------------------------------------------------------
enum class PLAYER_ACTION_STATE :int
{
	IDLE = 0,//待機状態
	JUMP = 1,//ジャンプ
	WANDERING = 2,
};

/********************************************************************
*
*
* ここからまで
*
*
********************************************************************/
//EOF