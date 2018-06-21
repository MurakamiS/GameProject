#pragma once

class Board;
class Game;
class TurnSprite;

class Player:public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	int SousaFlag=1;//操作フラグ　１が操作可能、０が操作不能
	int turn = -1; //現在のターン　1が白、-1が青
	int cursorX=3;
	int cursorY=3;
	
	int time = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	Board* m_board = nullptr;
	Game* m_game = nullptr;
	TurnSprite* m_turnsp =nullptr;
	CVector3 m_position = CVector3::Zero;
	//void PostRender(CRenderContext& rc);




};

