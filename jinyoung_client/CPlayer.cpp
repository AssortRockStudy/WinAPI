#include "pch.h"
#include "CPlayer.h"

#include "CTimeManager.h"
#include "CPal.h"




CPlayer::CPlayer()
	: m_Speed(500.f)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::tick(float _DT)
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


void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	SelectObject(_dc, CPal::GetInst()->getHPen(BLACK));
	SelectObject(_dc, CPal::GetInst()->getHBrush(GREEN));


	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

}