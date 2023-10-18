#include "pch.h"
#include "EditorLevel.h"
#include "CEngine.h"
#include "Camera.h"
#include "KeyMgr.h"
#include "resource.h"
#include "LevelMgr.h"
#include "Tile.h"
#include "BtnUI.h"

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

	BtnUI* pBtnUI = new BtnUI;
	pBtnUI->setScale(Vec2(200.f, 80.f));
	pBtnUI->setPos(Vec2(1390.f, 10.f));
	addObject(LAYER::UI, pBtnUI);
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

	if ((KeyMgr::GetInst()->getKeyState(KEY::LBTN) == TAP))
	{
		Vec2 vMousePos = KeyMgr::GetInst()->getMousePos();
		vMousePos = Camera::GetInst()->getRealPos(vMousePos);

		int col = vMousePos.x / TILE_SIZE;
		int row = vMousePos.y / TILE_SIZE;
		int idx = getTileCol() * row + col;

		if (!(getTileCol() <= col) && !(getTileRow() <= row)
			&& !(vMousePos.x < 0.f) && !(vMousePos.y < 0.f))
		{
			const vector<CObj*>& vecTiles = GetLayer(TILE)->getObjects();
			Tile* targetTile = dynamic_cast<Tile*>(vecTiles[idx]);
			targetTile->addImgIdx();
		}
	}
}


INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			// IDC_COL, IDC_ROW 에디트 컨트롤에 입력한 숫자를 알아내서
			// EditorLevel 의 타일을 해당 수치에 맞게 생성시킨다.
			int Col = GetDlgItemInt(hDlg, IDC_COL, nullptr, true);
			int Row = GetDlgItemInt(hDlg, IDC_ROW, nullptr, true);

			CLevel* pCurLevel = LevelMgr::GetInst()->getCurLevel();
			EditorLevel* pEditorLevel = dynamic_cast<EditorLevel*>(pCurLevel);

			if (nullptr != pEditorLevel)
				pEditorLevel->createTile(Row, Col);

			// 다이얼로그 윈도우 종료
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			// 다이얼로그 윈도우 종료
			EndDialog(hDlg, LOWORD(wParam));
		}
		break;
	}
	return (INT_PTR)FALSE;
}