#pragma once
class Fade : public IGameObject
{
public:
	Fade();
	~Fade();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& rc) override;
	void StartFadeIn()
	{
		m_state = enState_FadeIn;
	}
	void StartFadeOut()
	{
		m_state = enState_FadeOut;
	}

	bool IsFade() const	//フェード中ならtrueを返す。
	{
		return m_state != enState_Idle;
	}
	float GetCurrentAlpha() const
	{
		return m_currentAlpha;
	}
	//メンバ変数
private:
	enum Enstate
	{
		enState_FadeIn,		//フェードイン中
		enState_FadeOut,	//フェードアウト中
		enState_Idle,		//どっちでもない
	};
	CShaderResourceView m_texture;
	CSprite m_sprite;
	Enstate m_state = enState_Idle;	//現在のフェードの状態。
	float m_currentAlpha = 1.0f;
};

