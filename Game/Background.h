#pragma once
#include "Fade.h"
#include "tkEngine/graphics/effect/tkEffect.h"
#include "Title.h"
#include "Board.h"
#include "Game.h"
class Background : public IGameObject

{
public:
	Background();
	~Background();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	CSkinModelData m_skinModelData;	//スキンモデルデータ。
	CSkinModel m_skinModel;			//スキンモデル。
	CVector3 m_position = CVector3::Zero;	//座標。
};