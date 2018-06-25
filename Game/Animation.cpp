#include "stdafx.h"
#include "Animation.h"
#include "Player.h"
#include "Board.h"
#include "GameCamera.h"
#include "Fade.h"
#include  "Title.h"
Animation::Animation()
{
}
Animation::~Animation()
{
}
bool Animation::Start()
{
	m_player = FindGO<Player>("Player");
	m_board = FindGO<Board>("board");
	MainCamera().SetTarget({ 1000.0f, 0.0f, 400.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(5000.0f);
	MainCamera().SetPosition({ 900.0f, 100.0f, 250.0f });

	//アニメーションクリップのロード
	m_animClips[enAnimationClip_idle].Load(L"animation/solidle.tka");
	/*m_animClips[enAnimationClip_Walk].Load(L"animation/solwalk.tka");
	m_animClips[enAnimationClip_Run].Load(L"animation/solrun.tka");
	m_animClips[enAnimationClip_Attack].Load(L"animation/solattack.tka");*/
	m_animClips[enAnimationClip_battle].Load(L"animation/battle.tka");
	m_animClips[enAnimationClip_diffence].Load(L"animation/diffence.tka");
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	//m_animClips[enAnimationClip_Walk].SetLoopFlag(true);
	//m_animClips[enAnimationClip_Run].SetLoopFlag(true);
	//このへんでどのアニメーションを再生するか呼び出し元から持ってくる いまはいい
	/*m_whitePos = m_player->m_skinModelRender->GetPosition();
	m_bluePos = m_player->m_skinModelRender->GetPosition();*/
	m_animClips[enAnimationClip_battle].SetLoopFlag(true);
	m_animClips[enAnimationClip_diffence].SetLoopFlag(true);

	//if () {
	/*m_SkinModelRenderW = NewGO<prefab::CSkinModelRender>(0, "solW");
	m_SkinModelRenderW->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderW->PlayAnimation(enAnimationClip_idle);
	rot.SetRotation(CVector3::AxisY, 3.0f);
	m_SkinModelRenderW->SetRotation(rot);
	m_SkinModelRenderW->SetPosition(m_pos3);

	m_SkinModelRenderB = NewGO<prefab::CSkinModelRender>(0, "solB");
	m_SkinModelRenderB->Init(L"modelData/blueman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderB->PlayAnimation(enAnimationClip_diffence);
	m_animClips[enAnimationClip_diffence].SetLoopFlag(false);
	m_SkinModelRenderB->SetPosition(m_pos2);

	m_SkinModelRenderW = NewGO<prefab::CSkinModelRender>(0, "solW1");
	m_SkinModelRenderW->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderW->PlayAnimation(enAnimationClip_battle);
	m_animClips[enAnimationClip_battle].SetLoopFlag(false);
	m_SkinModelRenderW->SetPosition(m_pos1);*/
	//	}

	//if () {
	m_SkinModelRenderB = NewGO<prefab::CSkinModelRender>(0, "solB");
	m_SkinModelRenderB->Init(L"modelData/blueman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderB->PlayAnimation(enAnimationClip_idle);
	rot.SetRotation(CVector3::AxisY, 3.0f);
	m_SkinModelRenderB->SetRotation(rot);
	m_SkinModelRenderB->SetPosition(m_pos3);

	m_SkinModelRenderW = NewGO<prefab::CSkinModelRender>(0, "solW");
	m_SkinModelRenderW->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderW->PlayAnimation(enAnimationClip_diffence);
	m_animClips[enAnimationClip_diffence].SetLoopFlag(false);
	m_SkinModelRenderW->SetPosition(m_pos2);

	m_SkinModelRenderB1 = NewGO<prefab::CSkinModelRender>(0, "solB");
	m_SkinModelRenderB1->Init(L"modelData/blueman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderB1->PlayAnimation(enAnimationClip_battle);
	m_animClips[enAnimationClip_battle].SetLoopFlag(false);
	m_SkinModelRenderB1->SetPosition(m_pos1);
	//}
	m_title = FindGO<Title>("title");
	m_fade = FindGO<Fade>("fade");
	m_board = FindGO<Board>("board");

	return true;
}

void Animation::Update()
{
	m_flame--;
	m_pos1.y = m_flame * 50.0f;
	if (m_pos1.y <= 0.0f) {
		m_pos1.y = 0.0f;
	}
	//m_SkinModelRenderW->SetPosition(m_pos1);
	m_SkinModelRenderB1->SetPosition(m_pos1);
	if (m_flame == -50) {
		//NewGO<Fade>(0, "fade");
		//m_fade->StartFadeIn();
		DeleteGO(m_SkinModelRenderB);
		DeleteGO(m_SkinModelRenderB1);
		DeleteGO(m_SkinModelRenderW);
		NewGO<GameCamera>(0, "gamecamera");
		m_board->Animflag = 0;
		DeleteGO(this);
	}
	count++;
}
