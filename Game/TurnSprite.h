#pragma once


class Player;
class Board;
class TurnSprite:public IGameObject
{
public:
	TurnSprite();
	~TurnSprite();
	bool Start() override;
	void Update() override; 
	void PostRender(CRenderContext& rc) override;
	int time = 0;
private:

	enum Enstate
	{
		enState_FadeIn,		//フェードイン中
		enState_FadeOut,	//フェードアウト中
		enState_Idle,		//どっちでもない
	};
	Enstate m_state = enState_Idle;	//現在のフェードの状態。


	int x = 0;
	Board* m_board = nullptr;
	float m_currentAlpha1 = 1.0f;
	float m_currentAlpha2 = 1.0f;
	bool m_WaitFadeOut = false;
	CShaderResourceView m_texture1;
	CSprite m_sprite1;
	CShaderResourceView m_texture2;
	CSprite m_sprite2;
	Player* m_player;

};

