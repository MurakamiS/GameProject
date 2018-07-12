#include "stdafx.h"
#include "VictTet.h"

VictTet::VictTet()
{
}


VictTet::~VictTet()
{
}

bool VictTet::Start() 
{
	m_texture.CreateFromDDSTextureFromFile(L"sprite/button.dds");
	m_sprite.Init(m_texture, 1280, 720);
	
	return true;
}

void VictTet::Update()
{
	if (m_state == enState_max|| m_state == enState_idle){
		m_currentAlpha -= 1.0f * GameTime().GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f) {
			m_currentAlpha = 0.0f;
			if(m_state == enState_max)
			m_state = enState_min;
		}
	}

	if (m_state == enState_min) {
		m_currentAlpha += 1.0f * GameTime().GetFrameDeltaTime();
		if (m_currentAlpha >= 1.0f) {
			m_currentAlpha = 1.0f;
			m_state = enState_max;
		}
	}
	
	if (Pad(0).IsTrigger(enButtonStart)) {
		m_currentAlpha = 0.5f;
		m_state = enState_idle;
		
	}
	
	if (m_currentAlpha == 0.0f&&m_state == enState_idle){
		DeleteGO(this);
	}
}
void VictTet::PostRender(CRenderContext& rc)
{
	m_sprite.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
	m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());
}