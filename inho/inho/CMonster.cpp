#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"
#include "CPaletteMgr.h"

CMonster::CMonster()
	: m_Speed(500.f)
{
}

CMonster::~CMonster()
{
}

void CMonster::tick(float _DT)
{
	Vec2 vPos = GetPos();


	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		vPos.x += m_Speed * _DT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		vPos.x -= m_Speed * _DT;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		vPos.y += m_Speed * _DT;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		vPos.y -= m_Speed * _DT;
	}

	SetPos(vPos);
}

void CMonster::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	CPaletteMgr* palette = CPaletteMgr::GetInst();

	palette->SelectPen(CPaletteMgr::PenColor::PRED);
	palette->SelectBrush(CPaletteMgr::BrushColor::BRED);
	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}
