#include "pch.h"
#include "BtnUI.h"

#include "CEngine.h"
#include "resource.h"

void BtnUI::tick(float _DT){
	Super::tick(_DT);
}

void BtnUI::render(HDC _dc){
	Vec2 vPos = getFinalPos();
	Vec2 vScale = getScale();
	if (nullptr != mCur)
	{

	}
	else
		Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);

	Super::render(_dc);
}

void BtnUI::onHovered(Vec2 _vMousePos)
{
	mCur = mHover;
}

void BtnUI::onUnHovered(Vec2 _vMousePos)
{
	mCur = mNormal;
}

void BtnUI::mouseOn(Vec2 _vMousePos)
{
}

void BtnUI::LBtnDown(Vec2 _vMousePos)
{
	mCur = mPressed;
}

void BtnUI::LBtnUp(Vec2 _vMousePos)
{
	mCur = mNormal;
}

INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

void BtnUI::LBtnClicked(Vec2 _vMousePos)
{
	DialogBox(nullptr, MAKEINTRESOURCE(IDD_CREATE_TILE), CEngine::GetInst()->getMainWin(), CreateTileProc);
}

BtnUI::BtnUI():mNormal(nullptr), mHover(nullptr), mPressed(nullptr), mCur(nullptr)
{
}

BtnUI::~BtnUI()
{
}
