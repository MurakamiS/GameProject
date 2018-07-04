#pragma once
class Fade;
class VictTet:public IGameObject

{
public:
	VictTet();
	~VictTet();

	bool Start()override;
	void Update()override;
	void PostRender(CRenderContext& rc)override;

	enum Enstate
	{
		enState_max,
		enState_min,
		enState_idle,
	};
	Enstate m_state = enState_max;
private:
	bool m_WaitFadeOut = false;
	CShaderResourceView m_texture;
	CSprite m_sprite;
	Fade* m_fade = nullptr;
	float m_currentAlpha = 1.0f;

};

