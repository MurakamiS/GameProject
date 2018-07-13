#pragma once
class Player;
class Fade;
class Board;
class Game;
class Count;
class victory:public IGameObject
{
public:
	victory();
	~victory();
	bool Start();
	void Update();
	void PostRender(CRenderContext& rc);
	
private:
	CQuaternion m_blueRot = CQuaternion::Identity;
	enum EnAnimationClip
	{
		enAnimationClip_vict,
		enAnimationClip_Num,
	};
	CVector3 m_bluePos;
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;
	prefab::CSkinModelRender* m_SkinModelRenderW = nullptr;
	prefab::CSkinModelRender* m_SkinModelRenderB = nullptr;
	
	CVector3 position = { 1000.0f, 0.0f, 400.0f };

	CAnimationClip m_animClips[enAnimationClip_Num];
	CSkinModel m_blueman;
	CAnimation m_animation;
	Player* m_player = nullptr;
	
	enum state
	{
		enState_play,
		enState_unplay,
	};
	state m_animplay = enState_unplay;

	void StartPlay() {
		m_animplay = enState_play;
	}

	void StartUnPlay() {
		m_animplay = enState_unplay;
	}

	bool IsPlay() {
		return m_animplay == enState_play;
	}
	int time = 0;
	float m_currentAlpha = 1.0f;
	float m_currentAlpha1 = 1.0f;
	float m_currentAlpha2 = 1.0f;
	bool m_WaitFadeOut = false;
	CShaderResourceView m_texture;
	CSprite m_sprite;
	CShaderResourceView m_Wwin;
	CSprite m_wwin;
	Fade* m_fade = nullptr;
	Board* m_board = nullptr;
	Game* m_game = nullptr;
	Count* m_count = nullptr;
	int count = 0;
	CFont m_fontTest;
	float m_timer = 0.0f;
	int win = 0;
	CShaderResourceView m_texture1;
	CSprite m_sprite1;
	int flag = 0;
};


