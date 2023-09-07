#include "pch.h"
#include "CMonster.h"

#include "CKeyMgr.h"


CMonster::CMonster()
	: m_fSpeed(100.f)
{
}

CMonster::~CMonster()
{
}



void CMonster::tick(float _DT)
{
	Vec2 vPos = GetPos();

	if (KEY_PRESSED(KEY::W))
	{
		vPos.y += m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::S))
	{
		vPos.y -= m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::A))
	{
		vPos.x += m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::D))
	{
		vPos.x -= m_fSpeed * _DT;
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

