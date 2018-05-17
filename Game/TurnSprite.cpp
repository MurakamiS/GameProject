#include "stdafx.h"
#include "Game.h"
#include "TurnSprite.h"
#include "Player.h"
#include "GameCamera.h"

TurnSprite::TurnSprite()
{
}

TurnSprite::~TurnSprite()
{
}
bool TurnSprite::Start()
{
	
	
		
		m_player = FindGO<Player>("Player");
	
		return true;
}
void TurnSprite::Update()
{
	time++;
	if (m_player->SousaFlag == 1 && m_player->turn == 1) {
		
		m_texture1.CreateFromDDSTextureFromFile(L"sprite/1Pturn.dds");
		m_sprite1.Init(m_texture1, 1280, 720);
		if (time >= 30) {
			m_currentAlpha1 -= 2.0f * GameTime().GetFrameDeltaTime();
			if (m_currentAlpha1 <= 0.0f) {
				m_currentAlpha1 = 0.0f;
				m_state = enState_Idle;
				time = 0;
				m_currentAlpha2 = 1.0f;
			}
		}
	}

	if (m_player->SousaFlag == 1 && m_player->turn == -1) {

		m_texture2.CreateFromDDSTextureFromFile(L"sprite/2Pturn.dds");
		m_sprite2.Init(m_texture2, 1280, 720);
		if (time >= 30) {
			m_currentAlpha2 -= 2.0f * GameTime().GetFrameDeltaTime();
			if (m_currentAlpha2 <= 0.0f) {
				m_currentAlpha2 = 0.0f;
				m_state = enState_Idle;
				time = 0;
				m_currentAlpha1 = 1.0f;
			}
		}
	}
}

void TurnSprite::PostRender(CRenderContext& rc)
{
	if (m_player->SousaFlag == 1 && m_player->turn == 1) {
		m_sprite1.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha1 });
		m_sprite1.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());

	}
	if (m_player->SousaFlag == 1 && m_player->turn == -1) {
		m_sprite2.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha2 });
		m_sprite2.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());
	}
}
