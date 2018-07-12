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
	turn = m_player->turn;
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
	//���m�̈ʒu�Ƃ��������邽�߂ɍ��W�̏��������Ƃ����Ă��Ȃ��Ƃ����Ȃ�
	m_bluePos = m_player->m_skinModelRender->GetPosition();
	//�X�L�����f�������_���[���쐬
	m_SkinModelRenderB = NewGO<prefab::CSkinModelRender>(0, "solB");
	m_SkinModelRenderW = NewGO<prefab::CSkinModelRender>(0, "solW");
	m_SkinModelRenderB->Init(L"modelData/blueman.cmo",m_animClips,enAnimationClip_Num);
	m_SkinModelRenderW->Init(L"modelData/whiteman.cmo", m_animClips, enAnimationClip_Num);
	m_SkinModelRenderB->PlayAnimation(enAnimationClip_idle);
	m_SkinModelRenderW->PlayAnimation(enAnimationClip_idle);
	// BanX*-110.0f,50.0f,BanY*110.0f�ł��Ԃ�Ȃ�Ƃ��Ȃ� 
	//�ǂ����̃^�[�����ɂ�΂ꂽ��turn�ɓ����Ă�̂ł���ɂ���ĕ���@���������Ȃ���1��-1��
	BBan = m_board->GetMapB(turn);
	WBan = m_board->GetMapW(turn);
	/*m_board->GetBanX();
	m_board->GetBanY();*/
	m_whitePos = transPos(WBan);
	m_bluePos = transPos(BBan);
	m_SkinModelRenderB->SetPosition(m_bluePos);
	m_SkinModelRenderW->SetPosition(m_whitePos);
	//������Rotation�̒���
	sPos = m_board->GetstonePos();
	switch (turn)
	{
	case 1:
		setRotA(sPos, &m_whiteRot);
		setRotB(sPos, &m_blueRot);
		break;
	case -1:
		setRotA(sPos, &m_blueRot);
		setRotB(sPos, &m_whiteRot);
		break;
	default:
		break;
	}

	m_SkinModelRenderB->SetRotation(m_blueRot);
	m_SkinModelRenderW->SetRotation(m_whiteRot);
	return true;
}
void Animation::Update()
{
	
	count++;
	if (count > 60)
	{
		
	}
}
void Animation::setRotA(int p,CQuaternion* CQ)//�u�����ق� p�͔z�u�����΂���݂Ăǂ̕����̃}�X�������������@0123�ŏ㉺���E�̏���
{
	switch (p)
	{
	case 0:
		CQ->SetRotationDeg(CVector3::AxisY, 180.0f);
		break;
	case 1:
		break;
	case 2:
		CQ->SetRotationDeg(CVector3::AxisY, 90.0f);
		break;
	case 3:
		CQ->SetRotationDeg(CVector3::AxisY, 270.0f);
		break;
	default:
		break;
	}
}
void Animation::setRotB(int p,CQuaternion* cq)//�����ꂽ�ق�
{
	switch (p)
	{
	case 0:
		break;
	case 1:
		cq->SetRotationDeg(CVector3::AxisY, 180.0f);
		break;
	case 2:
		cq->SetRotationDeg(CVector3::AxisY, 270.0f);
		break;
	case 3:
		cq->SetRotationDeg(CVector3::AxisY, 90.0f);
		break;
	default:
		break;
	}
}