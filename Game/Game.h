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
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。 カーソル
	CAnimationClip m_animClip[1];							//アニメーションクリップ。
	CAnimation m_animation;
	CVector3 m_pos = CVector3::Zero;
	int cursorX = 0;
	int	cursorY = 0;
	int Flag = 1;//操作可能かどうかのフラグ。0の時はBoardの更新処理中
	int TurnB = 10; 
 	int turnW = 10; //残りのターン数
	int turn = 1;	//どちらのターンか　1が青-1が白
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

