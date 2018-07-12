#include "stdafx.h"
#include "Animation2.h"
#include "Player.h"
#include "GameCamera.h";
#include "Board.h";
#include "TurnSprite.h"
Animation2::Animation2()
{
}
Animation2::~Animation2()
{
}
bool Animation2::Start()
{
	m_player = FindGO<Player>("Player");
	MainCamera().SetTarget({ 1000.0f, 0.0f, 400.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(5000.0f);
	MainCamera().SetPosition({ 900.0f, 100.0f, 250.0f });

	//アニメーションクリップのロード
	m_animClips[enAnimationClip_idle].Load(L"animation/solidle.tka");
	m_animClips[enAnimationClip_battle].Load(L"animation/battle.tka");
	m_animClips[enAnimationClip_diffence].Load(L"animation/diffence.tka");
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);

	//このへんでどのアニメーションを再生するか呼び出し元から持ってくる いまはいい

	m_animClips[enAnimationClip_battle].SetLoopFlag(true);
	m_animClips[enAnimationClip_diffence].SetLoopFlag(true);

	if (m_player->turn == -1) {
		m_SkinModelRender1 = NewGO<prefab::CSkinModelRender>(0, "solB1");
		m_SkinModelRender1->Init(L"modelData/blueman.cmo", m_animClips, enAnimationClip_Num);
	}
	if (m_player->turn == 1) {
		m_SkinModelRender1 = NewGO<prefab::CSkinModelRender>(0, "solW1");
		m_SkinModelRender1->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	}
	m_SkinModelRender1->PlayAnimation(enAnimationClip_idle);
	rot.SetRotation(CVector3::AxisY, 3.0f);
	m_SkinModelRender1->SetRotation(rot);
	m_SkinModelRender1->SetPosition(m_pos3);

	if (m_player->turn == -1) {
		m_SkinModelRender2 = NewGO<prefab::CSkinModelRender>(0, "solW2");
		m_SkinModelRender2->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	}
	if (m_player->turn == 1) {
		m_SkinModelRender2 = NewGO<prefab::CSkinModelRender>(0, "solB2");
		m_SkinModelRender2->Init(L"modelData/blueman.cmo", m_animClips, enAnimationClip_Num);
	}

	m_SkinModelRender2->PlayAnimation(enAnimationClip_diffence);
	m_animClips[enAnimationClip_diffence].SetLoopFlag(false);
	m_SkinModelRender2->SetPosition(m_pos2);

	if (m_player->turn == -1) {
		m_SkinModelRender3 = NewGO<prefab::CSkinModelRender>(0, "solB3");
		m_SkinModelRender3->Init(L"modelData/blueman.cmo", m_animClips, enAnimationClip_Num);
	}

	if (m_player->turn == 1) {
		m_SkinModelRender3 = NewGO<prefab::CSkinModelRender>(0, "solW3");
		m_SkinModelRender3->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	}
	m_SkinModelRender3->PlayAnimation(enAnimationClip_battle);
	m_animClips[enAnimationClip_battle].SetLoopFlag(false);
	m_SkinModelRender3->SetPosition(m_pos1);

	m_turnsp = FindGO<TurnSprite>("turnsp");
	m_board = FindGO<Board>("board");
	m_board->Animflag = 1;
	return true;
}

void Animation2::Update()
{

	m_flame--;
	m_pos1.y = m_flame * 50.0f;
	if (m_pos1.y <= 0.0f) {
		m_pos1.y = 0.0f;
	}

	m_SkinModelRender3->SetPosition(m_pos1);
	if (m_flame == -50) {

		DeleteGO(m_SkinModelRender1);
		DeleteGO(m_SkinModelRender2);
		DeleteGO(m_SkinModelRender3);
		NewGO<GameCamera>(0, "gamecamera");
		m_board->Animflag = 0;
		m_turnsp->time = 0;
		DeleteGO(this);
	}
	count++;
}
