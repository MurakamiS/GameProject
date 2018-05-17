#include "stdafx.h"
#include "Fade.h"
#include "Game.h"
#include "TurnSprite.h"
#include "Player.h"

TurnSprite::TurnSprite()
{
}

TurnSprite::~TurnSprite()
{
}
bool TurnSprite::Start()
{
	/*m_texture.CreateFromDDSTextureFromFile(L"sprite/title.dds");
	m_sprite.Init(m_texture, 1280, 720);
	m_fade = FindGO<Fade>("fade");
	m_fade->StartFadeIn();*/ 
	return true;
}
void TurnSprite::Update()
{
	
}

void TurnSprite::PostRender(CRenderContext& rc)
{
	m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());
}

