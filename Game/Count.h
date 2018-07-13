#pragma once
class Player;
class Board;
class Game;
class Count:public IGameObject
{
public:
	Count();
	~Count();
	bool Start();
	void Update();
	Player* m_player = nullptr;
	Board* m_board = nullptr;
	Game* m_game=nullptr;
	int BanmenGoukei = 0;
	int Banmen[10][10];
	int ten = 0;
	int ten1;
	int ten2;
	int ten3;
	int count = 0;
	int countB = 0;
	int countW = 0;
	int win;
};

