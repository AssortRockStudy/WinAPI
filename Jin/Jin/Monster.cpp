#include "pch.h"
#include "Monster.h"

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

void Monster::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();


	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(_dc, hRedPen);

	HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(_dc, hRedBrush);

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));


	DeleteObject(hRedPen);
	DeleteObject(hRedBrush);

}

