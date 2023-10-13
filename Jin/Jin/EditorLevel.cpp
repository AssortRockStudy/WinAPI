#include "pch.h"
#include "EditorLevel.h"

#include "resource.h"

#include "LevelMgr.h"
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

	//CreateTile(10, 10);

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

INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDOK)
		{
			int y, x;

			y = GetDlgItemInt(hDlg,IDC_EDIT2, nullptr, true);
			x = GetDlgItemInt(hDlg, IDC_EDIT1, nullptr, true);
			Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();
			EditorLevel* pEditorLevel = dynamic_cast<EditorLevel*>(pCurLevel);

			if (nullptr != pEditorLevel)
			{
				pEditorLevel->CreateTile(y, x);
			}
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
