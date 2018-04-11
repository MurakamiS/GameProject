#pragma once
class Game;
class Stone : public IGameObject
{
public:
	Stone();
	~Stone();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	int Color;	//この石の色　1が青-1が白
	CVector3 m_position = CVector3::Zero;
	CSkinModelData m_skinModelData;	//スキンモデルデータ。
	CSkinModel m_skinModel;			//スキンモデル。
private:
	Game* m_game=nullptr;
};

