#include "pch.h"
#include "Monster.h"
#include "DrawMgr.h"

Monster::Monster()
	: m_Speed(500.f)
{
}

Monster::~Monster()
{
}


void Monster::tick(float _DT)
{
	Vec2 vPos = GetPos();

	// 키입력이 발생하면 움직인다.
	if (GetAsyncKeyState('A') & 0x8001)
	{
		vPos.x += m_Speed * _DT;
	}

	if (GetAsyncKeyState('D') & 0x8001)
	{
		vPos.x -= m_Speed * _DT;
	}

	if (GetAsyncKeyState('W') & 0x8001)
	{
		vPos.y += m_Speed * _DT;
	}

	if (GetAsyncKeyState('S') & 0x8001)
	{
		vPos.y -= m_Speed * _DT;
	}

	SetPos(vPos);
}

void Monster::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();


	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(_dc, hRedPen);

	//HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	//SelectObject(_dc, hRedBrush);

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	DeleteObject(SelectObject(_dc, oldPen));
}

