#include "stdafx.h"
#include "victory.h"
#include "Player.h"
#include "GameCamera.h"
#include "Fade.h"
#include "VictTet.h"
#include "Board.h"
#include "Game.h"
#include "Count.h"
victory::victory()
{
}

victory::~victory()
{
}

bool victory::Start()
{
	m_player = FindGO<Player>("Player");
	MainCamera().SetTarget({ 1000.0f, 0.0f, 400.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(5000.0f);
	MainCamera().SetPosition({ 1000.0f, 70.0f, 550.0f });

	m_animClips[enAnimationClip_vict].Load(L"animation/victory.tka");
	m_animClips[enAnimationClip_vict].SetLoopFlag(true);
	m_game=FindGO<Game>("Game");
	m_count= FindGO<Count>("count");
	
	if  (m_count->win == 1) {
		m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0, "solB");
		m_SkinModelRender->Init(L"modelData/blueman.cmo", m_animClips, enAnimationClip_Num);
		m_texture.CreateFromDDSTextureFromFile(L"sprite/1Pvic.dds");
	}

	if  (m_count->win == -1) {
		m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0, "solW");
		m_SkinModelRender->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
		m_texture.CreateFromDDSTextureFromFile(L"sprite/2Pvic.dds");
	}
	if  (m_count->win == 0) {
		m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0, "solW");
		m_SkinModelRender->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
		m_texture.CreateFromDDSTextureFromFile(L"sprite/2Pvic.dds");
	}

	m_sprite.Init(m_texture, 1280, 720);
	m_SkinModelRender->SetPosition(position);
	m_SkinModelRender->PlayAnimation(enAnimationClip_vict);
	m_animClips[enAnimationClip_vict].SetLoopFlag(false);
	StartPlay();
		m_fade = FindGO<Fade>("fade");
		m_fade->FadeState();
		m_board = FindGO<Board>("board");
		m_board->Animflag = 1;
	return true;
}

void victory::Update() {
	time++;
	if (time >= 60) {
		m_currentAlpha -= 2.0f * GameTime().GetFrameDeltaTime();
		if (m_currentAlpha <= 0.0f) {
			m_currentAlpha = 0.0f;
			time = 0;
		}
	}

	if (Pad(0).IsTrigger(enButtonStart) && Pad(1).IsTrigger(enButtonStart) && m_fade->IsFade2()) {
		m_fade->StartFadeOut();
		flag = 1;
	}

	if (m_SkinModelRender->IsPlayingAnimation() == false && IsPlay()&&flag==0) {
		NewGO<VictTet>(0, "VictTet");
		StartUnPlay();
	}

	if (!m_fade->IsFade()) {
		m_fade->StartFadeIn();
		DeleteGO(m_SkinModelRender);
		NewGO<GameCamera>(0, "GameCamera");
		DeleteGO(this);
	}
}
void victory::PostRender(CRenderContext& rc)
{
		m_sprite.SetMulColor({ 1.0f, 1.0f, 1.0f, m_currentAlpha });
		m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());
}