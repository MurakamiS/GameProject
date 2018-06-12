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
	
	//CVector3 scale =/* { 10.0f, 10.0f, 10.0f };*/{ 50.0f, 50.0f, 50.0f };
	int count = 1;
};

