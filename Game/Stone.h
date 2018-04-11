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
	int Color;	//���̐΂̐F�@1����-1����
	CVector3 m_position = CVector3::Zero;
	CSkinModelData m_skinModelData;	//�X�L�����f���f�[�^�B
	CSkinModel m_skinModel;			//�X�L�����f���B
private:
	Game* m_game=nullptr;
};

