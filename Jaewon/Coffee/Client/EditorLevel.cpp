#include "pch.h"
#include "EditorLevel.h"
#include "CEngine.h"
#include "Camera.h"
#include "KeyMgr.h"
#include "resource.h"

void EditorLevel::init()
{
}

void EditorLevel::enter()
{
	HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDC_EDITOR_MENU));
	SetMenu(CEngine::GetInst()->getMainWin(), hMenu);
	POINT ptResSol = CEngine::GetInst()->getMainResol();
	CEngine::GetInst()->changeWindowSize(ptResSol, true);

	Vec2 vLookAt = CEngine::GetInst()->getMainResol();
	vLookAt /= 2.f;
	Camera::GetInst()->SetLookAt(vLookAt);
	createTile(10, 10);
}

void EditorLevel::exit()
{
	deleteAllObjects();
	HMENU hMenu = GetMenu(CEngine::GetInst()->getMainWin());
	SetMenu(CEngine::GetInst()->getMainWin(), nullptr);
	DestroyMenu(hMenu);
	POINT ptResSol = CEngine::GetInst()->getMainResol();
	CEngine::GetInst()->changeWindowSize(ptResSol, false);
}

void EditorLevel::tick()
{
	CLevel::tick();

	if (KeyMgr::GetInst()->getKeyState(ENTER) == TAP)
		changeLevel(LEVEL_TYPE::PLAY_LEVEL);
}
