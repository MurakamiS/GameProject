#include "stdafx.h"
#include "Enshutsu.h"
#include "Game.h"
#include "Stone.h"

bool Enshutsu::Start()
{
	return true;
}
void Enshutsu :: Update()
{
	if (Pad(0).IsTrigger(enButtonStart)) {
		m_game = FindGO<Game>("Game");
		//m_game->m_position;
		//�G�t�F�N�g���쐬�B
		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//�G�t�F�N�g���Đ��B

		CVector3 emitPos = m_game->m_position;
		effect->SetPosition(emitPos);
		effect->Play(L"effect/test.efk");
	}
}