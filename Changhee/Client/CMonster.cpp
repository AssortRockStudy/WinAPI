#include "pch.h"
#include "CMonster.h"

#include "CKeyMgr.h"


CMonster::CMonster()
	: m_fSpeed(300.f)
{
}

CMonster::~CMonster()
{
}



void CMonster::tick(float _DT)
{
	Vec2 vPos = GetPos();

	if (KEY_PRESSED(KEY::UP))
	{
		vPos.y -= m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::DOWN))
	{
		vPos.y += m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::LEFT))
	{
		vPos.x -= m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::RIGHT))
	{
		vPos.x += m_fSpeed * _DT;
	}

	SetPos(vPos);
}

void CMonster::render(HDC _dc)
{
	CPalette RedBrush(_dc, BRUSH_TYPE::RED);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc 
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}

