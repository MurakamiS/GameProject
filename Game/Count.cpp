#include "stdafx.h"
#include "Count.h"
#include "Player.h"
#include "Animation2.h"
#include "Board.h"
#include "Game.h"
Count::Count()
{
}

Count::~Count()
{
}

bool Count::Start() {

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			Banmen[a][b] = 0;
		}
	}
	m_player = FindGO<Player>("Player");
	m_board = FindGO<Board>("board");
	m_game = FindGO<Game>("Game");
	return true;
}

void Count::Update() {

	if (Pad(0).IsTrigger(enButtonStart) || Pad(1).IsTrigger(enButtonStart))
	{
		int a = m_player->cursorX;
		int b = m_player->cursorY;

		if (m_player->turn == 1) {
			ten1 = 1;
			ten2 = 5;
			ten3 = 2;
		}
		else if (m_player->turn == -1) {
			ten1 = -1;
			ten2 = -5;
			ten3 = -2;
		}

		Banmen[a + 1][b + 1] += ten2;

		if (a >= 0 && a <= 7) {
			Banmen[a][b + 1] += ten1;
			Banmen[a + 2][b + 1] += ten1;

		}
		if (b >= 0 && b <= 7) {
			Banmen[a + 1][b] += ten1;
			Banmen[a + 1][b + 2] += ten1;
		}

			for (int s = 0; s < 10; s++) {
				for (int t = 0; t < 10; t++) {
					if (Banmen[s][t] == 2)
						Banmen[s][t] = 1;

					if (Banmen[s][t] == 4 || Banmen[s][t] == 6)
						Banmen[s][t] = 5;

					if (Banmen[s][t] == -2)
						Banmen[s][t] = -1;

					if (Banmen[s][t] == -4 || Banmen[s][t] == -6)
						Banmen[s][t] = -5;
				}
			}
			
		BanmenGoukei = Banmen[a + 1][b] + Banmen[a][b + 1] + Banmen[a + 1][b + 2] + Banmen[a + 2][b + 1];

		if (m_game->count0flag == 0){
			if (count == 0 && m_board->Animflag == 0 && BanmenGoukei == 2 || BanmenGoukei == -2) {
				NewGO<Animation2>(0, "animation2");
				BanmenGoukei = 0;
				count++;
			}
		}
	}
	if (m_game->count0flag == 1) {
		for (int s = 1; s < 9; s++) {
			for (int t = 1; t < 9; t++) {
				if (Banmen[s][t] == 1)
					countB++;

				if (Banmen[s][t] == -1)
					countW++;
			}
		}
		if (countB > countW)
			win = 1;
		else if (countB < countW)
			win = -1;
		else if(countB == countW){
			win = 0;
		}
	}
}
