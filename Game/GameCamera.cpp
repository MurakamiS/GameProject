#include "stdafx.h"
#include "GameCamera.h"


GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}
bool GameCamera::Start()
{

	MainCamera().SetTarget({ -375.0f, 0.0f, 400.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(5000.0f);
	MainCamera().SetPosition({ -375.0f, 1000.0f, 600.0f });
	MainCamera().Update();
	return true;
}
void GameCamera::Update()
{
	MainCamera().Update();

}