#include "pch.h"
#include "Player.h"

#include "TimeMgr.h"
#include "DrawMgr.h"

Player::Player()
	: m_Speed(500.f)
{
}

Player::~Player()
{
}

void Player::tick(float _DT)
{
	Vec2 vPos = GetPos();

	// 키입력이 발생하면 움직인다.
	if (GetAsyncKeyState('A') & 0x8001)
	{
		vPos.x -= m_Speed * _DT;
	}

	if (GetAsyncKeyState('D') & 0x8001)
	{
		vPos.x += m_Speed * _DT;
	}

	if (GetAsyncKeyState('W') & 0x8001)
	{
		vPos.y -= m_Speed * _DT;
	}

	if (GetAsyncKeyState('S') & 0x8001)
	{
		vPos.y += m_Speed * _DT;
	}

	SetPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	//HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
	//SelectObject(_dc,);

	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	//SelectObject(_dc, hBlackBrush);

	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	//DeleteObject(hBlackPen);
	//DeleteObject(hBlackBrush);


}
