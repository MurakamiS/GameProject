#include "stdafx.h"
#include "Fade.h"
#include "Game.h"
#include "TurnSprite.h"


TurnSprite::TurnSprite()
{
}

TurnSprite::~TurnSprite()
{
}
bool TurnSprite::Start()
{
	m_texture.CreateFromDDSTextureFromFile(L"sprite/title.dds");
	m_sprite.Init(m_texture, 1280, 720);
	m_fade = FindGO<Fade>("fade");
	m_fade->StartFadeIn(); 
	return true;
}
void TurnSprite::Update()
{
	if (m_WaitFadeOut) {
		if (!m_fade->IsFade()) {
			NewGO<Game>(0, "Game");
			DeleteGO(this);
		}
	}
	else {
		if (Pad(0).IsTrigger(enButtonSelect)) {
		m_WaitFadeOut = true;
		m_fade->StartFadeOut();
		//NewGO<Game>(0, "Game");
		}
    }
}

void TurnSprite::PostRender(CRenderContext& rc)
{
	m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());
}

