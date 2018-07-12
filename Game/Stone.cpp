#include "stdafx.h"
#include "Stone.h"
#include "Game.h"
#include"Player.h"


Stone::Stone()
{
}


Stone::~Stone()
{
}
bool Stone::Start()
{
	m_game = FindGO<Game>("Game");
	m_player = FindGO<Player>("Player");
	m_position = m_player->m_position;
	switch (m_player->turn)
	{
	case 1:
		m_skinModelData.Load(L"modelData/whitekari.cmo");
		//break;
	case -1:
		m_skinModelData.Load(L"modelData/bluekari.cmo");
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