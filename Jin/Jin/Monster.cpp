#include "pch.h"
#include "define.h"
#include "Monster.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
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
	if (KEY_PRESSED(A))
	{
		vPos.x += m_Speed * _DT;
	}

	if (KEY_PRESSED(D))
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KEY_PRESSED(W))
	{
		vPos.y += m_Speed * _DT;
	}

	if (KEY_PRESSED(S))
	{
		vPos.y -= m_Speed * _DT;
	}

	SetPos(vPos);
}

void Monster::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HPEN oldPen = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->pens[RED]));
	HPEN oldBrush = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->brushes[RED]));

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

}

