#include "pch.h"
#include "EditorLevel.h"

#include "resource.h"

#include "KeyMgr.h"

#include "Engine.h"
#include "Camera.h"

void EditorLevel::init()
{
}

void EditorLevel::enter()
{
	Vec2 vLookAt = Engine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	Camera::GetInst()->SetLookAt(vLookAt);

	CreateTile(10, 10);

	HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDR_EDITORMENU));

	SetMenu(Engine::GetInst()->GetMainWind(), hMenu);

	POINT ptResSol = Engine::GetInst()->GetResolution();
	Engine::GetInst()->ChangeWindowSize(ptResSol, true);


}

void EditorLevel::exit()
{
	DeleteAllObjects();

	HMENU hMenu = GetMenu(Engine::GetInst()->GetMainWind());
	SetMenu(Engine::GetInst()->GetMainWind(), nullptr);
	DestroyMenu(hMenu);

	POINT ptResSol = Engine::GetInst()->GetResolution();
	Engine::GetInst()->ChangeWindowSize(ptResSol, false);

}

void EditorLevel::tick()
{
	Level::tick();

	if (KEY_TAP(ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}


}
