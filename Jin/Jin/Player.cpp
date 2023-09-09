#include "pch.h"
#include "define.h"
#include "Player.h"

#include "KeyMgr.h"
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
	if (KEY_PRESSED(A))
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KeyMgr::GetInst()->GetKeyState(D) == PRESSED)
	{
		vPos.x += m_Speed * _DT;
	}

	if (KEY_PRESSED(W))
	{
		vPos.y -= m_Speed * _DT;
	}

	if (KEY_PRESSED(S))
	{
		vPos.y += m_Speed * _DT;
	}

	SetPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HPEN oldPen = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->pens[BLACK]));
	HPEN oldBrush = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->brushes[BLACK]));


	 Rectangle(_dc
		 , int(vPos.x - vScale.x / 2)
		 , int(vPos.y - vScale.y / 2)
		 , int(vPos.x + vScale.x / 2)
		 , int(vPos.y + vScale.y / 2));


}
