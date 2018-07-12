#include "stdafx.h"
#include "Player.h"
#include "Stone.h"
#include "Board.h"
#include "Game.h"
#include "Enshutsu.h"
#include "TurnSprite.h"
#include "Count.h"

Player::Player()
{
}


Player::~Player()
{
}
bool Player::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/whitekari.cmo");
	m_skinModelRender->SetScale({ 1.0f, 1.0f, 1.0f });
	m_skinModelRender->SetPosition({ 0.0f,50.0f,0.0f });
	m_board = FindGO<Board>("board");
	
	m_game = FindGO<Game>("Game");
	NewGO<TurnSprite>(0, "turnsp");
	NewGO<Count>(0, "count");
	return true;
}
void Player::Update()
{
	//模索中

	
	//タイマースタート？
	if (SousaFlag == 1 && turn == 1) {
		//time++;
		if (Pad(0).IsTrigger(enButtonRight))
		{
			cursorX++;
			if (cursorX > 7)cursorX = 7;
		}
		if (Pad(0).IsTrigger(enButtonLeft))
		{
			cursorX--;
			if (cursorX < 0)cursorX = 0;
		}
		if (Pad(0).IsTrigger(enButtonDown))
		{
			cursorY++;
			if (cursorY > 7)cursorY = 7;
		}
		if (Pad(0).IsTrigger(enButtonUp))
		{
			cursorY--;
			if (cursorY < 0)cursorY = 0;
		}

		//石を配置して盤面の更新を行う 同じマスに複数おけるのを修正予定 置けない時は置けないというのをだす？
		if (Pad(0).IsTrigger(enButtonStart))
		{
			if (m_board->Banmen[cursorX][cursorY] != -2 && m_board->Banmen[cursorX][cursorY] != 2) {
				SousaFlag = 0;//操作を不可能にする

				m_board->Banmen[cursorX][cursorY] = 2;
				NewGO<Stone>(0, nullptr);
				m_board->Haichi = 1;
				NewGO<Enshutsu>(0, "enshutsu");
				
			}
		}
	}
	if (SousaFlag == 1 && turn == -1) {
		//time++;
		if (Pad(1).IsTrigger(enButtonRight))
		{
			cursorX++;
			if (cursorX > 7)cursorX = 7;
		}
		if (Pad(1).IsTrigger(enButtonLeft))
		{
			cursorX--;
			if (cursorX < 0)cursorX = 0;
		}
		if (Pad(1).IsTrigger(enButtonDown))
		{
			cursorY++;
			if (cursorY > 7)cursorY = 7;
		}
		if (Pad(1).IsTrigger(enButtonUp))
		{
			cursorY--;
			if (cursorY < 0)cursorY = 0;
		}

		//石を配置して盤面の更新を行う 同じマスに複数おけるのを修正予定 置けない時は置けないというのをだす？
		if (Pad(1).IsTrigger(enButtonStart))
		{
			if (m_board->Banmen[cursorX][cursorY] != -2 && m_board->Banmen[cursorX][cursorY] != 2)
			{
				m_board->Banmen[cursorX][cursorY] = -2;
				NewGO<Stone>(0, nullptr);
				SousaFlag = 0;
				m_board->Haichi = 1;
				NewGO<Enshutsu>(0, "enshutsu");
			
			}
		}
		}
		m_skinModelRender->SetPosition({ cursorX*-110.0f,50.0f,cursorY*110.0f });
		m_position = { cursorX*-110.0f,50.0f,cursorY*110.0f };
	}
