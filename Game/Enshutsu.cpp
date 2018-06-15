#include "stdafx.h"
#include "Enshutsu.h"
#include "Game.h"
#include "Stone.h"
#include "Player.h"
#include "Board.h"

bool Enshutsu::Start()
{
	
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	rot.SetRotation(CVector3::AxisZ, 90);
	m_skinModelData.Load(L"modelData/whitekari.cmo");
	m_board = FindGO<Board>("board");
	m_player = FindGO<Player>("Player");
	prefab::CSoundSource* ss;
	ss = NewGO<prefab::CSoundSource>(0);
	ss->Init("sound/koma.wav");	
	ss->Play(false);
	if (m_board->Koushin == 0 && m_player->turn == 1) {
		
		
		
		/////////////////////////////////
		/////////‚±‚±‚©‚ç
		////////////////////////////////
		// 
		//  «‚±‚ê‚Å‚Å‚«‚é‚ÆŽv‚Á‚½
		if (m_player->cursorX != 0 || m_player->cursorX != 7 || m_player->cursorY != 0 && m_player->cursorX != 7) {
			effect->SetScale(scale);
			CVector3 emitPos1{ 100.0f,10.0f,20.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos2{ -100.0f,10.0f,20.0f };
			emitPos2 += m_player->m_position;
			effect->SetPosition(emitPos2);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos3{ -10.0f,10.0f,100.0f };
			emitPos3 += m_player->m_position;
			effect->SetPosition(emitPos3);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos4{ -10.0f,10.0f,-100.0f };
			emitPos4 += m_player->m_position;
			effect->SetPosition(emitPos4);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");
		}
	}
		
	

	if (m_board->Koushin == 0 && m_player->turn == -1) {
		if (a == 0 || a == 7 || b == 0 || b == 7) {
			effect->SetScale(scale);
			CVector3 emitPos1{ 100.0f,10.0f,20.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos2{ -100.0f,10.0f,20.0f };
			emitPos2 += m_player->m_position;
			effect->SetPosition(emitPos2);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos3{ -10.0f,10.0f,100.0f };
			emitPos3 += m_player->m_position;
			effect->SetPosition(emitPos3);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos4{ -10.0f,10.0f,-100.0f };
			emitPos4+= m_player->m_position;
			effect->SetPosition(emitPos4);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");
		}
	}
	return true;
}
void Enshutsu :: Update()
{	
	
	DeleteGO(this);
}
void Enshutsu::PostRender(CRenderContext& rc) {

}