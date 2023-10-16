#include "pch.h"
#include "EditorLevel.h"
#include "CEngine.h"
#include "Camera.h"
#include "KeyMgr.h"
#include "resource.h"
#include "LevelMgr.h"

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


INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			// IDC_COL, IDC_ROW ����Ʈ ��Ʈ�ѿ� �Է��� ���ڸ� �˾Ƴ���
			// EditorLevel �� Ÿ���� �ش� ��ġ�� �°� ������Ų��.
			int Col = GetDlgItemInt(hDlg, IDC_COL, nullptr, true);
			int Row = GetDlgItemInt(hDlg, IDC_ROW, nullptr, true);

			CLevel* pCurLevel = LevelMgr::GetInst()->getCurLevel();
			EditorLevel* pEditorLevel = dynamic_cast<EditorLevel*>(pCurLevel);

			if (nullptr != pEditorLevel)
				pEditorLevel->createTile(Row, Col);

			// ���̾�α� ������ ����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			// ���̾�α� ������ ����
			EndDialog(hDlg, LOWORD(wParam));
		}
		break;
	}
	return (INT_PTR)FALSE;
}