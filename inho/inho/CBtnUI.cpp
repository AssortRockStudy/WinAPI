﻿#include "pch.h"
#include "CBtnUI.h"

#include "CEngine.h"
#include "Resource.h"

CBtnUI::CBtnUI():
	m_NormalImg(nullptr),
	m_HoverImg(nullptr),
	m_PressedImg(nullptr),
	m_CurImg(nullptr)
{
}

CBtnUI::~CBtnUI()
{
}

void CBtnUI::tick(float _DT)
{

	Super::tick(_DT);
}

void CBtnUI::render(HDC _dc)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();
	if (nullptr != m_CurImg) {

	}
	else {
		Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);
	}

	Super::render(_dc);
}

void CBtnUI::OnHovered(Vec2 _vMousePos)
{
	m_CurImg = m_HoverImg;
}

void CBtnUI::OnUnHovered(Vec2 _vMousePos)
{
	m_CurImg = m_NormalImg;
}

void CBtnUI::MouseOn(Vec2 _vMousePos)
{
}

void CBtnUI::LBtnDown(Vec2 _vMousePos)
{
	m_CurImg = m_PressedImg;
}

void CBtnUI::LBtnUp(Vec2 _vMousePos)
{
}

INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

void CBtnUI::LBtnClicked(Vec2 _vMousePos)
{
	DialogBox(nullptr, MAKEINTRESOURCE(IDD_CREATE_TILE), CEngine::GetInst()->GetMainWind(), CreateTileProc);
}


