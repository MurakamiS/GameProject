#pragma once
#include "Fade.h"
#include "tkEngine/graphics/effect/tkEffect.h"
#include "Title.h"
#include "Board.h"
class Board;
class Stone;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	void OnDestroy();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。 
	int TurnB = 10; 
 	int turnW = 10; //残りのターン数
	int turn = 1;	//どちらのターンか　1が青-1が白
	int win; //どちらが勝ったかを判定　1が青の勝ち　-1が白の勝ち 0が引き分け
	CVector3 m_position = CVector3::Zero;
private:
	Fade * m_fade = nullptr;
	Board* m_board = nullptr;
	Stone* m_stone = nullptr;
	enum EnState
	{
		enState_FadeIn,		//フェードイン中
		enState_InGame,		//インゲーム中
	};
	bool m_DeleteFlag = false;	//このクラスのデリートを開始しているかどうか
};

