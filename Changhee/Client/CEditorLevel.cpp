#include "pch.h"
#include "CEditorLevel.h"

#include "resource.h"

#include "CEngine.h"

#include "CCamera.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

void CEditorLevel::init()
{
}

void CEditorLevel::enter()
{
	HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDC_EDITOR_MENU));

	SetMenu(CEngine::GetInst()->GetMainWind(), hMenu);

	POINT ptResolution = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResolution, true);

	// 카메라 설정
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	// 타일 생성
	CreateTile(10, 10);
}

void CEditorLevel::exit()
{
	DeleteAllObjects();

	HMENU hMenu = GetMenu(CEngine::GetInst()->GetMainWind());

	SetMenu(CEngine::GetInst()->GetMainWind(), nullptr);
	DestroyMenu(hMenu);

	POINT ptResolution = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResolution, false);


}

void CEditorLevel::tick()
{
	CLevel::tick();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}
}


// ==============================
// CreateTile Dialog 프로시저 함수
// ==============================

INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			int Row = GetDlgItemInt(hDlg, IDC_ROW, nullptr, true);
			int Col = GetDlgItemInt(hDlg, IDC_COL, nullptr, true);

			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
			CEditorLevel* pEditorLevel = dynamic_cast<CEditorLevel*>(pCurLevel);

			if (nullptr != pEditorLevel)
			{
				pEditorLevel->CreateTile(Row, Col);
			}

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}