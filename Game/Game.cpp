#include "stdafx.h"
#include "Game.h"
#include "Stone.h"
#include "TurnSprite.h"
#include "Enshutsu.h"


Game::Game()
{
}


Game::~Game()
{
}
void Game::OnDestroy()
{
	DeleteGO(m_skinModelRender);
}
bool Game::Start()
{
	//�J�[�\���̃��f�������[�h
	//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/bluekari.cmo");
	//m_skinModelRender->SetScale({ 1.0f, 1.0f, 1.0f });
	//m_skinModelRender->SetPosition({ 0.0f,50.0f,0.0f });


	

//�Q�[���v���C�ɕK�v�ȃN���X�̃C���X�^���X�𐶐��B
	NewGO<Board>(0, "board");
	m_board = FindGO<Board>("board");
	//�v���C���[�N���X�C���X�^���X���
	//�t�F�[�h�C���̏����B
	m_fade = FindGO<Fade>("fade");
	m_fade->StartFadeIn();
	m_enshutsu = NewGO<Enshutsu>(0, "enshutsu");
	return true;
}
void Game::Update()
{
	//if (m_DeleteFlag && !m_fade->IsFade())
	//{

	//	NewGO<Title>(0, nullptr);
	//	DeleteGO(this);
	//}

	/*if (m_board->turnA==0&&m_board->turnB==0)//���݂����^�[���g���؂������̏����B���l�����������Ȃ���������̒��g��ϐ��ɂ���
	{
	if(m_board->ScoreA>m_board->ScoreB)
	{
	win=1;
	}
	else if(m_board->ScoreA<m_board->ScoreB)
	{
	win=-1;
	}
	else if(m_board->ScoreA==m_board->ScoreB)
	{
	win=0;
	}
	*/

}
void Game::Render(CRenderContext& rc)
{
}