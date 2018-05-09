#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
class Game;
class Enshutsu : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	
private:
	Game * m_game = nullptr;
	//CVector3 m_position = CVector3::Zero;
};

