#pragma once
class Player;
class Board;
class Animation:public IGameObject
{
public:
	Animation();
	~Animation();
	bool Start();
	void Update();
private:
	Board * m_board = nullptr;
	Player* m_player = nullptr;
	CVector3 m_whitePos;
	CVector3 m_bluePos;
	CQuaternion m_whiteRot = CQuaternion::Identity;
	CQuaternion m_blueRot = CQuaternion::Identity;
	enum EnAnimationClip
	{
		enAnimationClip_idle,
		enAnimationClip_Attack,
		enAnimationClip_Walk,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	prefab::CSkinModelRender* m_SkinModelRenderW = nullptr;
	prefab::CSkinModelRender* m_SkinModelRenderB = nullptr;
	CAnimationClip m_animClips[enAnimationClip_Num];
	//Ç±ÇÍÇ™àÍíËÇÃêîílÇ…íBÇ∑ÇÈÇ∆Ç®ÇÌÇË
	int count = 0;
};

