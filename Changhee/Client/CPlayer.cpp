#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"

CPlayer::CPlayer()
	: m_Speed(100.f)
{
}

CPlayer::~CPlayer()
{
}



void CPlayer::tick(float _DT)
{
	Vec2 vPos = GetPos();
	
	if (KEY_PRESSED(KEY::W))
	{
		vPos.y -= m_Speed * _DT;
	}

	if (KEY_PRESSED(KEY::S))
	{
		vPos.y += m_Speed * _DT;
	}
	
	if (KEY_PRESSED(KEY::A))
	{
		vPos.x -= m_Speed * _DT;
	}
	
	if (KEY_PRESSED(KEY::D))
	{
		vPos.x += m_Speed * _DT;
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	CPalette BlackBrush(_dc, BRUSH_TYPE::BLACK);
	CPalette BluePen(_dc, PEN_TYPE::BLUE);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}


