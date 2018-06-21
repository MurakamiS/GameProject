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
	CVector3 transPos(CInt2 s)
	{
		CVector3 P;
		P = { s.X*-110.0f, 50.0f, s.Y*110.0f };
		return P;
	}
	void setRotA(int p, CQuaternion* CQ);
	void setRotB(int p,CQuaternion* cq);
private:
	Board * m_board = nullptr;
	Player* m_player = nullptr;
	CVector3 m_whitePos;
	CVector3 m_bluePos;
	CQuaternion m_whiteRot = CQuaternion::Identity;
	CQuaternion m_blueRot = CQuaternion::Identity;
	//V‚µ‚­‚Â‚­‚Á‚½CInt2‚ğ‚Â‚©‚Á‚Ä‚È‚ñ‚Æ‚©‚·‚é‚¼
	CInt2 WBan;
	CInt2 BBan;
	int m_BanX;//
	int m_BanY;
	int m_WBanX, m_WBanY;
	int m_BBanX, m_BBanY;
	int turn;
	int sPos;
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
	//‚±‚ê‚ªˆê’è‚Ì”’l‚É’B‚·‚é‚Æ‚¨‚í‚è
	int count = 0;
};

