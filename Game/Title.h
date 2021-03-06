#pragma once
class Fade;

class Title:public IGameObject
{
public:
	Title();
	~Title();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& rc);
	//メンバ変数

private:

	bool m_WaitFadeOut = false;   
	CShaderResourceView m_texture;
	CSprite m_sprite;
	Fade* m_fade = nullptr;
	
};



