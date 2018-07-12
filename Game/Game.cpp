#include "stdafx.h"
#include "Game.h"
#include "Stone.h"

#include "TurnSprite.h";
#include "Background.h"
#include "Player.h"
#include "Animation.h"

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

	//�^�C�}�[�p�̃t�H���g���������B
	//m_timerFont = std::make_unique<DirectX::SpriteFont>(
	//	GraphicsEngine().GetD3DDevice(),
	//	L"font/hato_pop.spritefont"
	//	);

	

//�Q�[���v���C�ɕK�v�ȃN���X�̃C���X�^���X�𐶐��B
	NewGO<Board>(0, "board");
	
	NewGO<Background>(0, "Back");
//	NewGO<Count>(0, "count");
	m_board = FindGO<Board>("board");
	//�v���C���[�N���X�C���X�^���X���
	//�t�F�[�h�C���̏����Bk
	m_fade = FindGO<Fade>("fade");
	m_player=FindGO<Player>("Player");
	m_fade->StartFadeIn();
	
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

	m_timer = max(0.0f, m_timer - GameTime().GetFrameDeltaTime()); {
		if (m_timer == 0) {
			if (m_player->turn == -1) {
				m_player->turn = 1;
			}
			else if (m_player->turn == 1) {
				m_player->turn = -1;
			}
			NewGO<TurnSprite>(0, "turnsp");
			ResetTimer();
			}
		}
	}

void Game::Render(CRenderContext& rc)
{
}
void Game::PostRender(CRenderContext& rc)
{
	wchar_t text[256];
	int sec = (int)m_timer;
	swprintf_s(text, L"%02d", sec);
	m_fontTest.Begin(rc);

	//������`��B
	m_fontTest.Draw(
		text,
		{ -300.0f, 300.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f },//RGB
		0.0f,
		3.0f,
		{ 0.0f, 1.0f }
	);
	m_fontTest.End(rc);
}