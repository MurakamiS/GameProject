#pragma once
class Game;
class Board:public IGameObject
{
public:
	Board();
	~Board();
	int Banmen[8][8];			//左から横方向、縦方向 
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	prefab::CSkinModelRender* m_skinModelRender[8][8] = { {nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } };	//スキンモデルレンダラー。
	CFont m_font;
	int ScoreA = 0;
	int ScoreB = 0;
	wchar_t A;
	wchar_t B;
	int Koushin = 1;//この変数が0の場合得点が更新される
	int Haichi = 0;//新しい石を配置して配列の更新が必要な時1になる
private:
	//残りターン数。
	int turnA = 10;
	int turnB = 10;
	////現在のターン　1が青、-1が白
	//int turn = 1;
	Game* m_game = nullptr;
	void SetMapB(int a, int b)
	{
		switch (Banmen[a][b])
		{
		case -1:Banmen[a][b] = 0;
			break;
		case 0:Banmen[a][b] = 1;
			break;
		default:break;
		}
	}

	void SetMapW(int a, int b)
	{
		switch (Banmen[a][b])
		{
		case 1:Banmen[a][b] = 0;
			break;
		case 0:Banmen[a][b] = -1;
			break;
		default:break;
		}
	}
};
