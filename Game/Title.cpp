#include "stdafx.h"
#include "Title.h"
#include "Fade.h"
#include "Game.h"
#include "GameCamera.h"
#include "Player.h"
#include "Animation.h"


Title::Title()
{
}


Title::~Title()
{
}

bool Title::Start()
{

	m_texture.CreateFromDDSTextureFromFile(L"sprite/title.dds");
	m_sprite.Init(m_texture, 1280, 720);
	m_fade = FindGO<Fade>("fade");
	
	m_fade->StartFadeIn();
	return true;
}
void Title::Update()
{
	if (m_WaitFadeOut) {
		if (!m_fade->IsFade()) {
			NewGO<Game>(0, "Game");
			NewGO<Player>(0, "Player");
			NewGO<Animation>(0, "Animation");
			DeleteGO(this);

		}
	}
		else {
			if (Pad(0).IsTrigger(enButtonB)) {
				m_WaitFadeOut = true;
				m_fade->StartFadeOut();
				NewGO<GameCamera>(0, "gamecamera");
			
				
			}
		}
	}

void Title::PostRender(CRenderContext& rc)
{
	m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());
}


