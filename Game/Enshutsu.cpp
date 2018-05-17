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
	//駒を置いたときに発生するエフェクト
	//発生する仮のエフェクトが小さすぎてエンターを押しても駒の下でエフェクトが発生されるのでスペースキーを押したら再生されるようにしている。
	//スペースキーを押したらすぐに2,4,6,8の移動キーを押す。そうするとエフェクトの確認ができる。
	//間違っていなければエフェクトをvisual studioへの取り込み方を調べ、取り込んだらifを消す。
	//if (Pad(0).IsTrigger(enButtonSelect)) {
		//エフェクトを作成。
	count++;
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