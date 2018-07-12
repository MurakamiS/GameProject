#pragma once
class Player;
class GameCamera;
class Board;
class TurnSprite;
class Fade;
class Animation2 :public IGameObject
{

public:
	Animation2();
	~Animation2();
	bool Start();
	void Update();
private:
	Player* m_player = nullptr;
	Board* m_board = nullptr;
	TurnSprite* m_turnsp = nullptr;
	Fade* m_fade = nullptr;
	//GameCamera* m_gamecamera = nullptr;
	CVector3 m_pos1 = { 1000.0f, 1500.0f, 350.0f };
	CVector3 m_pos2 = { 1000.0f, 0.0f, 380.0f };
	CVector3 m_pos3 = { 1000.0f, 0.0f, 480.0f };
	CQuaternion m_whiteRot = CQuaternion::Identity;
	CQuaternion m_blueRot = CQuaternion::Identity;
	enum EnAnimationClip
	{
		enAnimationClip_battle,
		enAnimationClip_diffence,
		enAnimationClip_idle,
		enAnimationClip_Num,
	};

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

	prefab::CSkinModelRender* m_SkinModelRender1 = nullptr;
	prefab::CSkinModelRender* m_SkinModelRender2 = nullptr;
	prefab::CSkinModelRender* m_SkinModelRender3 = nullptr;
	CAnimationClip m_animClips[enAnimationClip_Num];
	CQuaternion rot = CQuaternion::Identity;
	//Ç±ÇÍÇ™àÍíËÇÃêîílÇ…íBÇ∑ÇÈÇ∆Ç®ÇÌÇË
	int count = 0;
	int m_flame = 30;

};
