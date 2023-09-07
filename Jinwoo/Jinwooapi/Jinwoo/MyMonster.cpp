#include "pch.h"
#include "MyMonster.h"

#include "MyKeyMgr.h"
#include "MyTimeMgr.h"

MyMonster::MyMonster() : m_Speed(300.f)
{
}

MyMonster::~MyMonster()
{
}

void MyMonster::tick(float _DT)
{
	Vec2 vPos = GetPos();

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

void MyMonster::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	// 새로운 펜 객체를 생성
	//						선의 스타일 / 두께 / 색상
	HPEN hCurPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	// 그리기에 사용할 개체를 현재 DC(device context)에 적용
	//								현재 dc / 사용할 개체
	HPEN hPrevPen = (HPEN)SelectObject(_dc, hCurPen);

	// 새로운 브러쉬 생성
	// 펜으로 그린 것의 내부를 채운다
	HBRUSH hCurBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_dc, hCurBrush);

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	// 되돌리고 사용했던 펜과 브러쉬를 삭제한다
	SelectObject(_dc, hPrevPen);
	DeleteObject(hCurPen);

	SelectObject(_dc, hPrevBrush);
	DeleteObject(hCurBrush);
}
