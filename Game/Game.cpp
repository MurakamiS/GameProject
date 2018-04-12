#include "stdafx.h"
#include "Game.h"
#include "Stone.h"


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
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/bluekari.cmo");
	m_skinModelRender->SetScale({ 1.0f, 1.0f, 1.0f });
	m_skinModelRender->SetPosition({ 0.0f,50.0f,0.0f });
	//�J������ݒ�B��ŏ���
	MainCamera().SetTarget({ -375.0f, 0.0f, 400.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(5000.0f);
	MainCamera().SetPosition({ -375.0f, 1000.0f, 600.0f });
	MainCamera().Update();

//�Q�[���v���C�ɕK�v�ȃN���X�̃C���X�^���X�𐶐��B
	NewGO<Board>(0, "board");
	m_board = FindGO<Board>("board");
	//�t�F�[�h�C���̏����B
	m_fade = FindGO<Fade>("fade");
	m_fade->StartFadeIn();
	return true;
}
void Game::Update()
{
	//����
	if (Flag == 1) {
		if (Pad(0).IsTrigger(enButtonRight))
		{
			cursorX++;
			if (cursorX > 7)cursorX = 7;
		}
		if (Pad(0).IsTrigger(enButtonLeft))
		{
			cursorX--;
			if (cursorX < 0)cursorX = 0;
		}
		if (Pad(0).IsTrigger(enButtonDown))
		{
			cursorY++;
			if (cursorY > 7)cursorY = 7;
		}
		if (Pad(0).IsTrigger(enButtonUp))
		{
			cursorY--;
			if (cursorY < 0)cursorY = 0;
		}
	}
	if (Pad(0).IsTrigger(enButtonSelect))
	{
		m_fade->StartFadeOut();
		m_DeleteFlag = true;
		DeleteGO(m_board);
	}

	//�΂�z�u���ĔՖʂ̍X�V���s�� �����}�X�ɕ���������̂��C���\�� �u���Ȃ����͒u���Ȃ��Ƃ����̂������H
	if (Pad(0).IsTrigger(enButtonStart))
	{
		if (m_board->Banmen[cursorX][cursorY] != -2 && m_board->Banmen[cursorX][cursorY] != 2) {
			Flag = 0;//�����s�\�ɂ���
			m_board->Banmen[cursorX][cursorY] = turn * 2;
			NewGO<Stone>(0, nullptr);
			m_board->Haichi = 1;
		}
	}

	m_skinModelRender->SetPosition({ cursorX*-110.0f,50.0f,cursorY*110.0f });
	m_position = { cursorX*-110.0f,50.0f,cursorY*110.0f };
	if (m_DeleteFlag && !m_fade->IsFade())
	{

		NewGO<Title>(0, nullptr);
		DeleteGO(this);
	}

}
void Game::Render(CRenderContext& rc)
{
}