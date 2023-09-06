#include "pch.h"
#include "Player.h"

#include "TimeMgr.h"

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
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		vPos.x -= m_Speed * _DT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		vPos.x += m_Speed * _DT;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		vPos.y -= m_Speed * _DT;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		vPos.y += m_Speed * _DT;
	}

	SetPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
	HPEN hPrevPen = (HPEN)SelectObject(_dc, hBlackPen);

	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_dc, hBlackBrush);
	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));



	//// 되돌리고 사용했던 펜, 브러쉬를 삭제한다.
	//SelectObject(_dc, hPrevPen);
	//DeleteObject(hRedPen);

	//SelectObject(_dc, hPrevBrush);
	//DeleteObject(hBlueBrush);
}
