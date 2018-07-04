#pragma once
class Player;
class Board;
class Fade;
class Title;
class TurnSprite;

class Animation :public IGameObject
{
	
public:
	Animation();
	~Animation();
	bool Start();
	void Update();
private:
	Board * m_board = nullptr;
	Player* m_player = nullptr;
	Fade* m_fade = nullptr;
	Title* m_title = nullptr;
	TurnSprite* m_turnsp = nullptr;
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
	
	prefab::CSkinModelRender* m_SkinModelRender1 = nullptr;
	prefab::CSkinModelRender* m_SkinModelRender2 = nullptr;
	prefab::CSkinModelRender* m_SkinModelRender3 = nullptr;
	CAnimationClip m_animClips[enAnimationClip_Num];
	CQuaternion rot = CQuaternion::Identity;
	//Ç±ÇÍÇ™àÍíËÇÃêîílÇ…íBÇ∑ÇÈÇ∆Ç®ÇÌÇË
	int count = 0;
	int m_flame = 30;

};


