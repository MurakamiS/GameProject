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

	bool IsFade() const	//�t�F�[�h���Ȃ�true��Ԃ��B
	{
		return m_state != enState_Idle;
	}
	float GetCurrentAlpha() const
	{
		return m_currentAlpha;
	}
	//�����o�ϐ�
private:
	enum Enstate
	{
		enState_FadeIn,		//�t�F�[�h�C����
		enState_FadeOut,	//�t�F�[�h�A�E�g��
		enState_Idle,		//�ǂ����ł��Ȃ�
	};
	CShaderResourceView m_texture;
	CSprite m_sprite;
	Enstate m_state = enState_Idle;	//���݂̃t�F�[�h�̏�ԁB
	float m_currentAlpha = 1.0f;
};

