#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "Player.h"
class Game;
class Board;
class Enshutsu : public IGameObject
{
public:

	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& rc);
private:
	Player * m_player = nullptr;
	Board* m_board = nullptr;
	CSkinModelData m_skinModelData;	//スキンモデルデータ。
	CSkinModel m_skinModel;			//スキンモデル。
	CVector3 m_position = {100.0f,100.0f,100.0f};
	CVector3 scale = { 0.6f,0.6f,0.6f };/* { 10.0f, 10.0f, 10.0f };*/ /*{50.0f, 50.0f, 50.0f };*/
	int count = 1;
	CQuaternion rot = CQuaternion::Identity;
	int a = 0;
	int b = 0;
};

