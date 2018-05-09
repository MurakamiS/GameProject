#pragma once
class Fade;
class TurnSprite:public IGameObject
{
public:
	TurnSprite();
	~TurnSprite();
	bool Start(); 
	void Update(); 
	void PostRender(CRenderContext& rc);
private:

	bool m_WaitFadeOut = false;
	CShaderResourceView m_texture;
	CSprite m_sprite;
	Fade* m_fade = nullptr;


};

