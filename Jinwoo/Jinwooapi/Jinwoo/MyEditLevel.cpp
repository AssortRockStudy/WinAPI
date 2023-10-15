#include "pch.h"
#include "MyEditLevel.h"

#include "MyEngine.h"
#include "MyCameraMgr.h"
#include "MyLevelMgr.h"
#include "MyKeyMgr.h"

#include "resource.h"

void MyEditLevel::init()
{
}

void MyEditLevel::enter()
{
	// 메뉴바 생성
	// 리소스 아이디로 메뉴를 선택하여 생성
	HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDC_EDITORMENU));

	// 메인 윈도우에 생성시킨 메뉴 붙이기
	SetMenu(MyEngine::GetInst()->GetMainhWnd(), hMenu);

	// 추가된 메뉴바만큼 윈도우 크기 재조정
	POINT ptResSol = MyEngine::GetInst()->GetMainResolution();
	MyEngine::GetInst()->ChangeWindowSize(ptResSol, true);

	// 카메라 설정
	Vec2 vLookAt = MyEngine::GetInst()->GetMainResolution();
	vLookAt /= 2.f;
	MyCameraMgr::GetInst()->SetLookAt(vLookAt);

	CreateTile(5, 5);
}

void MyEditLevel::exit()
{
	DeleteAllObjects();

	// 메뉴바 제거
	// 현재 윈도우에 붙어있는 메뉴의 핸들을 알아냄
	HMENU hMenu = GetMenu(MyEngine::GetInst()->GetMainhWnd());

	// 메인 윈도우에 부착되어있는 메뉴를 떼어냄
	SetMenu(MyEngine::GetInst()->GetMainhWnd(), nullptr);

	// 메뉴를 메모리 해제시킴
	DestroyMenu(hMenu);

	// 메뉴가 사라졌으니 윈도우 크기 재조정
	POINT ptResSol = MyEngine::GetInst()->GetMainResolution();
	MyEngine::GetInst()->ChangeWindowSize(ptResSol, false);
}

void MyEditLevel::tick()
{
	MyLevel::tick();

	if (KEY_TAP(ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}
}





// CreateTile Dialog 프로시저 함수
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
			// IDC_COL, IDC_ROW 에디트 컨트롤에 입력한 숫자를 알아내서
			// EditorLevel의 타일을 해당 수치에 맞게 생성시킨다
			int Col = GetDlgItemInt(hDlg, IDC_COL, nullptr, true);
			int Row = GetDlgItemInt(hDlg, IDC_ROW, nullptr, true);

			MyLevel* pCurLevel = MyLevelMgr::GetInst()->GetCurLevel();
			MyEditLevel* pEditorLevel = dynamic_cast<MyEditLevel*>(pCurLevel);

			if (nullptr != pEditorLevel)
			{
				pEditorLevel->CreateTile(Row, Col);
			}

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