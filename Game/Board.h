#pragma once
#include "Animation.h"
class Game;
class Player;
class Animation;
class Board;
class Board :public IGameObject
{
public:
	Board();
	~Board();
	int Banmen[8][8];			//左から横方向、縦方向 
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	prefab::CSkinModelRender* m_skinModelRender[8][8] = { { nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } };	//スキンモデルレンダラー。
	CFont m_font;
	int ScoreA = 0;
	int ScoreB = 0;
	int k = 0;
	wchar_t A;
	wchar_t B;
	int Koushin = 1;//この変数が0の場合得点が更新される
	int Haichi = 0;//新しい石を配置して配列の更新が必要な時1になる
				   /*int BanX;
				   int BanY;*/
	int count = 0;
	int Animflag = 0;
	int GetBanX()
	{
		return BanX;
	}
	int GetBanY()
	{
		return BanY;
	}
	int GetstonePos()
	{
		return stonePos;
	}
	////上下左右に応じた座標を返す
	//CInt2 GetPos(int c)
	//{
	//	CInt2 re;
	//	switch (c)
	//	{
	//	case 0:
	//		re.X = BanX;
	//		re.Y = BanY - 1;
	//		break;
	//	case 1:

	//		re.X = BanX;
	//		re.Y = BanY + 1;
	//		break;
	//	case 2:

	//		re.X = BanX-1;
	//		re.Y = BanY;
	//		break;
	//	case 3:

	//		re.X = BanX+1;
	//		re.Y = BanY;
	//		break;
	//	}
	//	return re;
	//}
	//白のざひょう tが1の時が白、－１のときが青 -1のときのBanXBanYの値は
	CInt2 GetMapW(int t);
	CInt2 GetMapB(int t);

private:

	//残りターン数。残コマ数表示の時はこれ使う。
	int turnA = 10;	//青
	int turnB = 10;	//白

					//Animationにもっていく座標
	int BanX;
	int BanY;
	int stonePos;//Animationを呼び出したとき配置した石からみてどの方向のマスか　0123で上下左右の順番
	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Animation* m_animation = nullptr;
	void SetMapB(int a, int b, int c)
	{
		switch (Banmen[a][b])
		{
		case -1:Banmen[a][b] = 0;
			//ここにえんしゅつのやつ
			BanX = a;
			BanY = b;
			stonePos = c;
			NewGO<Animation>(0);
			break;
		case 0:Banmen[a][b] = 1;
			break;
		default:break;
		}
	}

	void SetMapW(int a, int b, int c)
	{
		switch (Banmen[a][b])
		{
		case 1:Banmen[a][b] = 0;
			//ここにえんしゅつのやつ
			BanX = a;
			BanY = b;
			stonePos = c;
			NewGO<Animation>(0);
			break;
		case 0:Banmen[a][b] = -1;
			break;
		default:break;
		}
	}
};