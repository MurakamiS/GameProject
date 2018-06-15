#include "stdafx.h"
#include "Animation.h"
#include "Player.h"
#include "Board.h"

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
	//�A�j���[�V�����N���b�v�̃��[�h
	m_animClips[enAnimationClip_idle].Load(L"animation/solidle.tka");
	m_animClips[enAnimationClip_Walk].Load(L"animation/solwalk.tka");
	m_animClips[enAnimationClip_Run].Load(L"animation/solrun.tka");
	m_animClips[enAnimationClip_Attack].Load(L"animation/solattack.tka");
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animClips[enAnimationClip_Run].SetLoopFlag(true);
	//���̂ւ�łǂ̃A�j���[�V�������Đ����邩�Ăяo�������玝���Ă��� ���܂͂���
	m_whitePos = m_player->m_skinModelRender->GetPosition();
	m_bluePos = m_player->m_skinModelRender->GetPosition();
	//�X�L�����f�������_���[���쐬
	m_SkinModelRenderB = NewGO<prefab::CSkinModelRender>(0, "solB");
	m_SkinModelRenderW = NewGO<prefab::CSkinModelRender>(0, "solW");
	m_SkinModelRenderB->Init(L"modelData/blueman.cmo",m_animClips,enAnimationClip_Num);
	m_SkinModelRenderW->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderB->PlayAnimation(enAnimationClip_idle);
	m_SkinModelRenderW->PlayAnimation(enAnimationClip_idle);
	m_whitePos.x -= 110.0f;
	m_SkinModelRenderB->SetPosition(m_bluePos);
	m_SkinModelRenderW->SetPosition(m_whitePos);
	return true;
}
void Animation::Update()
{
	
	count++;
}