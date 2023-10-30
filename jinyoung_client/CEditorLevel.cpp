#include "pch.h"
#include "CEditorLevel.h"

#include "CLevelMgr.h"

#include "CKeyman.h"

#include "CEngine.h"
#include "CCamera.h"

#include "Resource.h"

void CEditorLevel::init()
{
}


void CEditorLevel::enter()
{
	// 메뉴바 생성
// 리소스 아이디로 메뉴를 골라서 생성
	//HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDC_CLIENT));
	HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDC_JINYOUNGCLIENT));

	// 메인 윈도우에 생성시킨 메뉴를 붙이기
	SetMenu(CEngine::GetInst()->GetMainWind(), hMenu);

	// 메뉴가 추가되었기 때문에 윈도우 크기를 재조정
	POINT ptResSol = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResSol, true);

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

	// 메뉴바 제거
// 현재 윈도우에 붙어있는 메뉴의 핸들(아이디) 를 알아낸다.
	HMENU hMenu = GetMenu(CEngine::GetInst()->GetMainWind());

	// 메인 윈도우에 부착되어있는 메뉴를 떼어낸다.
	SetMenu(CEngine::GetInst()->GetMainWind(), nullptr);

	// 메뉴를 메모리 해제시킨다.
	DestroyMenu(hMenu);

	// 메뉴가 윈도우에서 떨어졌으니, 윈도우 크기를 다시 설정해준다.
	POINT ptResSol = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResSol, false);
}

void CEditorLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 StartLevel 로 변환
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
			// IDC_COL, IDC_ROW 에디트 컨트롤에 입력한 숫자를 알아내서
			// EditorLevel 의 타일을 해당 수치에 맞게 생성시킨다.
			int Col = GetDlgItemInt(hDlg, IDC_COL, nullptr, true);
			int Row = GetDlgItemInt(hDlg, IDC_ROW, nullptr, true);

			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
			CEditorLevel* pEditorLevel = dynamic_cast<CEditorLevel*>(pCurLevel);

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