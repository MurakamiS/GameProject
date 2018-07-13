#pragma once
#include "Fade.h"

#include "Title.h"
#include "Board.h"

#include "tkEngine/graphics/font/tkFont.h"

class Board;
class Stone;
class Player;
//class victory;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	void PostRender(CRenderContext& rc);
	void OnDestroy();
	void ResetTimer()
	{
		m_timer = 3.0f;
	}
	//prefab::CEffect* m_effect = nullptr;					//エフェクト

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。 
	int TurnB = 10; 
 	int turnW = 10; //残りのターン数
	int turn = 1;	//どちらのターンか　1が青-1が白
	int win; //どちらが勝ったかを判定　1が青の勝ち　-1が白の勝ち 0が引き分け
	
	CVector3 m_position = CVector3::Zero;
	int count0flag = 0;
private:
	Fade * m_fade = nullptr;
	Board* m_board = nullptr;
	Stone* m_stone = nullptr;
	Player* m_player = nullptr;
	

	Animation* m_animation = nullptr;
	
	CFont m_fontTest;
	float m_timer = 3.0f;								//!<タイマー
	//std::unique_ptr<DirectX::SpriteFont> m_timerFont;	//!<タイマー用のフォント。
	enum EnState
	{
		enState_FadeIn,		//フェードイン中
		enState_InGame,		//インゲーム中
	};
	bool m_DeleteFlag = false;	//このクラスのデリートを開始しているかどうか
	int count = 0;
	int count2 = 0;
};

