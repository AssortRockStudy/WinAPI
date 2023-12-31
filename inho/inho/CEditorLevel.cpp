﻿#include "pch.h"
#include "CEditorLevel.h"

#include "CEngine.h"
#include "CCamera.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

#include "resource.h"

#include "CTile.h"
#include "CBtnUI.h"

void CEditorLevel::init()
{
}

void CEditorLevel::enter()
{
	HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDR_EDITOR_MENU));

	SetMenu(CEngine::GetInst()->GetMainWind(), hMenu);

	POINT ptResSol = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResSol, true);


	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CreateTile(10, 10);

	CBtnUI* pBtnUI = new CBtnUI;
	pBtnUI->SetScale(Vec2(200.f, 80.f));
	pBtnUI->SetPos(Vec2(1390.f, 10.f));
	AddObject(LAYER::UI, pBtnUI);

}

void CEditorLevel::exit()
{
	DeleteAllObjects();

	HMENU hMenu = GetMenu(CEngine::GetInst()->GetMainWind());

	SetMenu(CEngine::GetInst()->GetMainWind(), nullptr);

	DestroyMenu(hMenu);

	POINT ptResSol = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResSol, false);
}

void CEditorLevel::tick()
{
	CLevel::tick();

	if (KEY_TAP(KEY::ENTER)) {
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}

	if (KEY_TAP(KEY::LBTN)) {
		Vec2 vMousePos = CKeyMgr::GetInst()->GetMousePos();
		vMousePos = CCamera::GetInst()->GetRealPos(vMousePos);

		int col = vMousePos.x / TILE_SIZE;
		int row = vMousePos.y / TILE_SIZE;
		int idx = GetTileCol() * row + col;

		if (!(GetTileCol() <= col) && !(GetTileRow() <= row) && !(vMousePos.x < 0.f) && !(vMousePos.y < 0.f)) {

			const vector<CObj*>& vecTiles = GetLayer(LAYER::TILE)->GetObjects();
			CTile* pTargetTile = dynamic_cast<CTile*>(vecTiles[idx]);
			pTargetTile->AddImgIdx();
		}
	}
}

INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK) {

			int Col = GetDlgItemInt(hDlg, IDC_COL, nullptr, true);
			int Row = GetDlgItemInt(hDlg, IDC_ROW, nullptr, true);

			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
			CEditorLevel* pEditorLevel = dynamic_cast<CEditorLevel*>(pCurLevel);

			if (nullptr != pEditorLevel) {
				pEditorLevel->CreateTile(Row, Col);
			}

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}