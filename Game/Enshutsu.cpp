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
	//���u�����Ƃ��ɔ�������G�t�F�N�g
	//�������鉼�̃G�t�F�N�g�����������ăG���^�[�������Ă���̉��ŃG�t�F�N�g�����������̂ŃX�y�[�X�L�[����������Đ������悤�ɂ��Ă���B
	//�X�y�[�X�L�[���������炷����2,4,6,8�̈ړ��L�[�������B��������ƃG�t�F�N�g�̊m�F���ł���B
	//�Ԉ���Ă��Ȃ���΃G�t�F�N�g��visual studio�ւ̎�荞�ݕ��𒲂ׁA��荞�񂾂�if�������B
	//if (Pad(0).IsTrigger(enButtonSelect)) {
		//�G�t�F�N�g���쐬�B
	count++;
	//if
		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/test.efk");
		effect->SetScale(scale);
		m_player = FindGO<Player>("Player");
		CVector3 emitPos = m_player->m_position;
		effect->SetPosition(emitPos);
		DeleteGO(this);
	//}
}