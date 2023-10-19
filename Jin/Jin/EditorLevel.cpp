#include "pch.h"
#include "EditorLevel.h"

#include "resource.h"

#include "LevelMgr.h"
#include "KeyMgr.h"

#include "Engine.h"
#include "Camera.h"

#include "Tile.h"
#include "BtnUI.h"
#include "PanelUI.h"

//void TestFunc();
INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);



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


	PanelUI* pPanelUI = new PanelUI;
	pPanelUI->SetScale(Vec2(500.f, 400.f));
	pPanelUI->SetPos(Vec2(800.f, 200.f));

	BtnUI* pBtnUI = new BtnUI;
	pBtnUI->SetScale(Vec2(200.f, 80.f));
	pBtnUI->SetPos(Vec2(10.f, 10.f));
	pBtnUI->SetDelegate(this, (DelegateFunc)& EditorLevel::OpenTileCreateWindow);

	pPanelUI->AddChildUI(pBtnUI);
	AddObject(LAYER::UILAYER, pPanelUI);


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

	if (KEY_TAP(KEY::LBTN))
	{
		Vec2 vMousePos = KeyMgr::GetInst()->GetMousePos();
		vMousePos = Camera::GetInst()->GerRealPos(vMousePos);

		int col = vMousePos.x / TILE_SIZE;
		int row = vMousePos.y / TILE_SIZE;
		int idx = GetTileCol() * row + col;

		if (!(GetTileCol() <= col) && !(GetTileCol() <= row)
			 && !(vMousePos.x < 0.f) && !(vMousePos.y < 0.f) )
		{
			const vector<Obj*>& vecTiles = GetLayer(LAYER::TILE)->GetObjects();
			Tile* pTargetTile = dynamic_cast<Tile*>(vecTiles[idx]);
			pTargetTile->AddImgIdx();
		}

	}

	if (KEY_TAP(ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}


}

void EditorLevel::OpenTileCreateWindow()
{
	DialogBox(nullptr, MAKEINTRESOURCE(IDD_JIN_DIALOG), Engine::GetInst()->GetMainWind(), CreateTileProc);

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

//void TestFunc()
//{
//	DialogBox(nullptr, MAKEINTRESOURCE(ID_CREATE_TILE), Engine::GetInst()->GetMainWind(), CreateTileProc);
//}
