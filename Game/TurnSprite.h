#pragma once


class Player;
class Game;
class TurnSprite:public IGameObject
{
public:
	TurnSprite();
	~TurnSprite();
	bool Start() override;
	void Update() override; 
	void PostRender(CRenderContext& rc) override;
	
private:

	enum Enstate
	{
		enState_FadeIn,		//�t�F�[�h�C����
		enState_FadeOut,	//�t�F�[�h�A�E�g��
		enState_Idle,		//�ǂ����ł��Ȃ�
	};
	Enstate m_state = enState_Idle;	//���݂̃t�F�[�h�̏�ԁB

	int time = 0;
	float m_currentAlpha1 = 1.0f;
	float m_currentAlpha2 = 1.0f;
	bool m_WaitFadeOut = false;
	CShaderResourceView m_texture1;
	CSprite m_sprite1;
	CShaderResourceView m_texture2;
	CSprite m_sprite2;
	
	Player* m_player;
	Game* m_game;
};

