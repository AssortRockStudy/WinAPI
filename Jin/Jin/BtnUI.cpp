#include "pch.h"
#include "BtnUI.h"
#include "Engine.h"
#include "resource.h"
#include "KeyMgr.h"

BtnUI::BtnUI()
	: m_NormalImg(nullptr)
	, m_HoverImg(nullptr)
	, m_PressedImg(nullptr)
	, m_CurImg(nullptr)
	, m_CallBackFunc(nullptr)
	, m_Inst(nullptr)
	, m_Delegate(nullptr)
{
}

BtnUI::~BtnUI()
{
}

void BtnUI::tick(float _DT)
{
	Super::tick(_DT);
}

void BtnUI::render(HDC _dc)
{

	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();
	
	if (nullptr != m_CurImg)
	{

	}
	else
	{
		Rectangle(_dc
			, (int)(vPos.x)
			, (int)(vPos.y)
			, (int)(vPos.x + vScale.x)
			, (int)(vPos.y + vScale.y));
	}
	Super::render(_dc);
}

void BtnUI::OnHovered(Vec2 _vMousePos)
{
	m_CurImg = m_HoverImg;
}

void BtnUI::OnUnHovered(Vec2 _vMousePos)
{
	m_CurImg = m_NormalImg;
}

void BtnUI::MouseOn(Vec2 _vMousePos)
{
}

void BtnUI::LBtnDown(Vec2 _vMousePos)
{
	m_CurImg = m_PressedImg;
}

void BtnUI::LBtnUp(Vec2 _vMousePos)
{
	m_CurImg = m_NormalImg;
}

void BtnUI::LBtnClicked(Vec2 _vMousePos)
{
	if (nullptr != m_CallBackFunc)
	{
		m_CallBackFunc();
	}

	if (nullptr != m_Inst && nullptr != m_Delegate)
	{
		(m_Inst->*m_Delegate)();
	}
}
