#include "stdafx.h"
#include "Stone.h"
#include "Game.h"


Stone::Stone()
{
}


Stone::~Stone()
{
}
bool Stone::Start()
{
	m_game = FindGO<Game>("Game");
	m_position = m_game->m_position;
	switch (m_game->turn)
	{
	case -1:
		m_skinModelData.Load(L"modelData/whitekari.cmo");
		m_game->turn = 1;
		break;
	case 1:
		m_skinModelData.Load(L"modelData/bluekari.cmo");
		m_game->turn = -1;
		break;
	default:
		break;
	}
	m_skinModel.Init(m_skinModelData);
	return true;
}
void Stone::Update()
{
	m_skinModel.Update(m_position, CQuaternion::Identity, CVector3::One);
}
void Stone::Render(CRenderContext& rc)
{
	m_skinModel.Draw(rc, MainCamera().GetViewMatrix(), MainCamera().GetProjectionMatrix());
}