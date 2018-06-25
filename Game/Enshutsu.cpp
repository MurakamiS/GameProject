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
	ss->Init("sound/zangeki.wav");	
	ss->Play(false);
	/*prefab::CSoundSource* sss;
	sss = NewGO<prefab::CSoundSource>(0);
	sss->Init("sound/koma.wav");
	sss->Play(false);*/
	if (m_board->Koushin == 0 && m_player->turn == 1) 
	{
		if (m_player->cursorX!=0&& m_player->cursorX !=7&& m_player->cursorY !=0&& m_player->cursorY !=7 ) {
			effect->SetScale(scale);
			CVector3 emitPos1{ 110.0f,1.0f,25.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos2{ -110.0f,1.0f,25.0f };
			emitPos2 += m_player->m_position;
			effect->SetPosition(emitPos2);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos3{ 0.0f,1.0f,110.0f };
			emitPos3 += m_player->m_position;
			effect->SetPosition(emitPos3);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos4{ 0.0f,1.0f,-90.0f };
			emitPos4 += m_player->m_position;
			effect->SetPosition(emitPos4);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");
		
		}
		if (m_player->cursorX == 0) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos3{ -110.0f,1.0f,0.0f };
			emitPos3 += m_player->m_position;
			effect->SetPosition(emitPos3);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");
			if (m_player->cursorY != 0 && m_player->cursorY != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos1{ 0.0f,1.0f,110.0f };
				emitPos1 += m_player->m_position;
				effect->SetPosition(emitPos1);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ 0.0f,1.0f,-110.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");
			}
		}
		if (m_player->cursorX == 7) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos1{ 110.0f,1.0f,0.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			if (m_player->cursorY != 0 && m_player->cursorY != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ 0.0f,1.0f,110.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos3{ 0.0f,1.0f,-110.0f };
				emitPos3 += m_player->m_position;
				effect->SetPosition(emitPos3);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");
			}
		}
		if (m_player->cursorY == 0) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos1{ 0.0f,1.0f,110.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			if (m_player->cursorX != 0 && m_player->cursorX != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ -110.0f,1.0f,0.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos3{ 110.0f,1.0f,0.0f };
				emitPos3 += m_player->m_position;
				effect->SetPosition(emitPos3);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");
			}
		}
		if (m_player->cursorY == 7) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos1{ 0.0f,1.0f,-110.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/a.efk");

			if (m_player->cursorX != 0 && m_player->cursorX != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ -110.0f,1.0f,0.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos3{ 110.0f,1.0f,0.0f };
				emitPos3 += m_player->m_position;
				effect->SetPosition(emitPos3);
				effect->SetRotation(rot);
				effect->Play(L"effect/a.efk");
			}
		}

	}
		
	if (m_board->Koushin == 0 && m_player->turn == -1) {
		if (m_player->cursorX != 0 && m_player->cursorX != 7 && m_player->cursorY != 0 && m_player->cursorY != 7) {
			effect->SetScale(scale);
			CVector3 emitPos1{ 110.0f,1.0f,30.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos2{ -110.0f,1.0f,30.0f };
			emitPos2 += m_player->m_position;
			effect->SetPosition(emitPos2);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos3{ 0.0f,1.0f,110.0f };
			emitPos3 += m_player->m_position;
			effect->SetPosition(emitPos3);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");

			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos4{ 0.0f,1.0f,-90.0f };
			emitPos4+= m_player->m_position;
			effect->SetPosition(emitPos4);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");
		}
		if (m_player->cursorX == 0) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos3{ -110.0f,1.0f,0.0f };
			emitPos3 += m_player->m_position;
			effect->SetPosition(emitPos3);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");
			if (m_player->cursorY != 0 && m_player->cursorY != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos1{ 0.0f,1.0f,110.0f };
				emitPos1 += m_player->m_position;
				effect->SetPosition(emitPos1);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ 0.0f,1.0f,-110.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");
			}
		}
		if (m_player->cursorX == 7) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos1{ 110.0f,1.0f,0.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");

			if (m_player->cursorY != 0 && m_player->cursorY != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ 0.0f,1.0f,110.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos3{ 0.0f,1.0f,-11.0f };
				emitPos3 += m_player->m_position;
				effect->SetPosition(emitPos3);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");
			}
		}
		if (m_player->cursorY == 0) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos1{ 0.0f,1.0f,110.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");

			if (m_player->cursorX != 0 && m_player->cursorX != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ -110.0f,1.0f,0.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos3{ 110.0f,1.0f,0.0f };
				emitPos3 += m_player->m_position;
				effect->SetPosition(emitPos3);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");
			}
		}
		if (m_player->cursorY == 7) {
			effect = NewGO<prefab::CEffect>(0);
			effect->SetScale(scale);
			CVector3 emitPos1{ 0.0f,1.0f,-110.0f };
			emitPos1 += m_player->m_position;
			effect->SetPosition(emitPos1);
			effect->SetRotation(rot);
			effect->Play(L"effect/Wbatsu.efk");

			if (m_player->cursorX != 0 && m_player->cursorX != 7) {
				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos2{ -110.0f,1.0f,0.0f };
				emitPos2 += m_player->m_position;
				effect->SetPosition(emitPos2);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");

				effect = NewGO<prefab::CEffect>(0);
				effect->SetScale(scale);
				CVector3 emitPos3{ 110.0f,1.0f,0.0f };
				emitPos3 += m_player->m_position;
				effect->SetPosition(emitPos3);
				effect->SetRotation(rot);
				effect->Play(L"effect/Wbatsu.efk");
			}
		}

	}

	
	return true;
}
void Enshutsu :: Update()
{	
	a++;
	if (a == 5) {
		prefab::CSoundSource* ss;
		ss = NewGO<prefab::CSoundSource>(0);
		ss->Init("sound/zangeki.wav");
		ss->Play(false);
		DeleteGO(this);
	}

}
void Enshutsu::PostRender(CRenderContext& rc) {

}