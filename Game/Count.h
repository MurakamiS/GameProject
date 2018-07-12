#pragma once
class Player;
//class Animation2;
class Count:public IGameObject
{
public:
	Count();
	~Count();
	bool Start();
	void Update();
	Player* m_player = nullptr;
	int BanmenGoukei = 0;
	int Banmen[10][10];
	int ten = 0;
	int ten1;
	int ten2;
	int ten3;
//	Animation2* m_animation2;
};

