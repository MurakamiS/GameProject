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
private:
	Player * m_player = nullptr;
	Board* m_board = nullptr;
	CSkinModelData m_skinModelData;	//スキンモデルデータ。
	CSkinModel m_skinModel;			//スキンモデル。
	CVector3 m_position = {100.0f,100.0f,100.0f};
	CVector3 scale = { 0.6f,0.6f,0.6f };
	CQuaternion rot = CQuaternion::Identity;
	int a = 0;
	int b = 0;
};

