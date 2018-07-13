#include "stdafx.h"
#include "Board.h"
#include "Game.h"
#include "Player.h"


Board::Board()
{
}


Board::~Board()
{
}
bool Board::Start()
{
	//盤面のロード、配置
	//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/Bankari.cmo");
	//m_skinModelRender->SetScale({ 1.0f, 1.0f, 1.0f });
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j < 8; j++) {
			m_skinModelRender[i][j] = NewGO<prefab::CSkinModelRender>(0);
			m_skinModelRender[i][j]->Init(L"modelData/Bankarinaka.cmo");
			m_skinModelRender[i][j]->SetScale({ 1.0f, 1.0f, 1.0f });
			m_skinModelRender[i][j]->SetPosition({ -110.0f*i,0.0f, 110.0f*j });
		}
	}
	//盤面配列の初期化。
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Banmen[i][j] = 0;
		}
	}
	m_game = FindGO<Game>("Game");
	m_player = FindGO<Player>("Player");
	return true;
}
void Board::Update()
{
	//置いた石の周りの色を更新///////////////////////////////////////////つぎここからやれ
	if (Haichi == 1)
	{
		count++;
		if (count == 15) {
			int a = m_player->cursorX;
			int b = m_player->cursorY;
			switch (Banmen[a][b])
			{
			case 2:
			{
				if (b > 0)SetMapB(a, b - 1, 0);//↑
				if (b < 7)SetMapB(a, b + 1, 1);//↓
				if (a > 0)SetMapB(a - 1, b, 2);//←
				if (a < 7)SetMapB(a + 1, b, 3);//→
				turnA--;
			}
			break;
			case -2:
			{
				if (b > 0)SetMapW(a, b - 1, 0);//↑
				if (b < 7)SetMapW(a, b + 1, 1);
				if (a > 0)SetMapW(a - 1, b, 2);
				if (a < 7)SetMapW(a + 1, b, 3);
				turnB--;
			}
			break;
			default:break;
			}
			Haichi = 0;
			Koushin = 1;
			count = 0;
		}
	}
	//得点の計算
	if (Koushin == 1) {
		
		
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					switch (Banmen[i][j])
					{
					case 0:
						m_skinModelRender[i][j]->Init(L"modelData/Bankarinaka.cmo");
						break;
					case 1:
						ScoreA++;
						m_skinModelRender[i][j]->Init(L"modelData/Bankari.cmo");
						break;
					case 2:
						ScoreA++;
						m_skinModelRender[i][j]->Init(L"modelData/Bankari.cmo");
						break;
					case -1:
						ScoreB++;
						m_skinModelRender[i][j]->Init(L"modelData/Bankariwhite.cmo");
						break;
					case -2:
						ScoreB++;
						m_skinModelRender[i][j]->Init(L"modelData/Bankariwhite.cmo");
						break;
					default:
						break;
					}
				}
			}

			Koushin = 0;
			m_player->SousaFlag = 1;
			if (m_player->turn == 1)
			{
				m_player->turn = -1;
			}
			else if (m_player->turn == -1)
			{
				m_player->turn = 1;
			}
			m_game->ResetTimer();	//タイマーリセット
	}
}
void Board::Render(CRenderContext& rc)
{
	/*m_font.Begin(rc);
	m_font.Draw(turnA, { 0.0f, -270.0f }, { 234.0f / 255.0f, 69.0f / 255.0f, 21.0f / 255.0f, 1.0f }, 0.0f, 1.0f, {0.0f,1.0f});
	m_font.End(rc);*/
}
//白のざひょう tが1の時が白、－１のときが青 -1のときのBanXBanYの値は
CInt2 Board::GetMapW(int t)
{
	CInt2 W;
	switch (t)
	{
	case 1:
		W.X = m_player->cursorX;
		W.Y = m_player->cursorY;
		break;
	case -1:
		W.X = BanX;
		W.Y = BanY;
		break;
	default:
		break;
	}
	return W;
}
//青のざひょう
CInt2 Board::GetMapB(int t)

{
	CInt2 B;
	switch (t)
	{
	case 1:
		B.X = BanX;
		B.Y = BanY;
		break;
	case -1:
		B.X = m_player->cursorX;
		B.Y = m_player->cursorY;
		break;
	default:
		break;
	}
	return B;
}