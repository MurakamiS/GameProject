#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "Player.h"
class Game;
class Enshutsu : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	
private:
	Player * m_player = nullptr;
	//CVector3 scale = { 2.0f, 2.0f, 2.0f };
};

