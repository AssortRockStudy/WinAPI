#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CPaletteMgr.h"

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

void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	CPaletteMgr* palette = CPaletteMgr::GetInst();

	palette->SelectPen(CPaletteMgr::PenColor::PBLACK);
	palette->SelectBrush(CPaletteMgr::BrushColor::BBLACK);
	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}
