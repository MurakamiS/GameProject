#include "stdafx.h"
#include "Background.h"

Background::Background()
{
}

Background::~Background()
{
}
bool Background::Start()
{
	
	m_skinModelData.Load(L"modelData/background.cmo");
	m_skinModel.Init(m_skinModelData);					

	return true;
}
void Background::Update()
{
	m_skinModel.Update(CVector3::Zero, CQuaternion::Identity, CVector3::One);

}
void Background::Render(CRenderContext& rc)
{
	m_skinModel.Draw(rc, MainCamera().GetViewMatrix(), MainCamera().GetProjectionMatrix());
	
}