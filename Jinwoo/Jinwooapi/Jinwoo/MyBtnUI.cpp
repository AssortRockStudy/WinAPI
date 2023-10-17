#include "pch.h"
#include "MyBtnUI.h"

#include "MyEngine.h"

#include "resource.h"

MyBtnUI::MyBtnUI() : m_NormalImg(nullptr), m_HoverImg(nullptr), m_PressedImg(nullptr), m_CurImg(nullptr)
{

}

MyBtnUI::~MyBtnUI()
{
}

void MyBtnUI::tick(float _DT)
{

	Super::tick(_DT);
}

void MyBtnUI::render(HDC _dc)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();

	if (nullptr != m_CurImg)
	{

	}
	else
	{
		Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);
	}

	Super::render(_dc);
}

void MyBtnUI::OnHovered(Vec2 _vMousePos)
{
	m_CurImg = m_HoverImg;
}

void MyBtnUI::MouseOn(Vec2 _vMousePos)
{

}

void MyBtnUI::OnUnHovered(Vec2 _vMousePos)
{
	m_CurImg = m_NormalImg;
}

void MyBtnUI::LBtnDown(Vec2 _vMousePos)
{
	m_CurImg = m_PressedImg;
}

void MyBtnUI::LBtnUp(Vec2 _vMousePos)
{
	m_CurImg = m_NormalImg;
}

INT_PTR CALLBACK CreateTileProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

void MyBtnUI::LBtnClicked(Vec2 _vMousePos)
{
	DialogBox(nullptr, MAKEINTRESOURCE(IDD_CREATETILE), MyEngine::GetInst()->GetMainhWnd(), CreateTileProc);
}
