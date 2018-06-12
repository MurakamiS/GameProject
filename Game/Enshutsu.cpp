#include "stdafx.h"
#include "Enshutsu.h"
#include "Game.h"
#include "Stone.h"
#include "Player.h"
#include "Board.h"
bool Enshutsu::Start()
{
	m_board = FindGO<Board>("board");
	m_player = FindGO<Player>("Player");
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	
	prefab::CSoundSource* ss;
	ss = NewGO<prefab::CSoundSource>(0);
	ss->Init("sound/koma.wav");

	CVector3 emitPos{ 50.0f,0.0f,50.0f };
	emitPos += m_player->m_position;
	effect->SetPosition(emitPos);
	CQuaternion rot{ 0.0f,90.0f,0.0f,1.0f };
	effect->SetRotation(rot);

	//effect->SetScale(scale);
	
	if (m_board->Koushin == 0 &&m_player->turn == 1){
		ss->Play(false);
		effect->Play(L"effect/whitezangeki.efk");
	}
	
	if (m_board->Koushin == 0 &&m_player->turn == -1) {
		ss->Play(false);
		effect->Play(L"effect/whitezangeki.efk");
	}
	return true;
}

void Enshutsu :: Update()
{	
	//prefab::CEffect* effect;
	//	if(effect->IsPlay())
	
	
		//エフェクトを再生。
	
		
		

}