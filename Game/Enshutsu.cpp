#include "stdafx.h"
#include "Enshutsu.h"
#include "Game.h"
#include "Stone.h"
#include "Player.h"

bool Enshutsu::Start()
{
	return true;
}
void Enshutsu :: Update()
{	


	//if
		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//エフェクトを再生。
		effect->Play(L"effect/test.efk");
		effect->SetScale(scale);
		m_player = FindGO<Player>("Player");
		CVector3 emitPos = m_player->m_position;
		effect->SetPosition(emitPos);
		DeleteGO(this);
	//}
}