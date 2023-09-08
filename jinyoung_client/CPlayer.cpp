#include "pch.h"
#include "CPlayer.h"

#include "CTimeManager.h"
#include "CPal.h"
#include "CKeyman.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CProjectile.h"



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
	if (KEY_PRESSED(W))
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KEY_PRESSED(D))
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

	if (KEY_TAP(SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		for (int i = 0; i < 3; ++i)
		{
			CProjectile* pProjectile = new CProjectile;

			Vec2 ProjectilePos = GetPos();
			ProjectilePos.y -= GetScale().y / 2.f;

			pProjectile->SetSpeed(1000.f);
			pProjectile->SetDir(PI / 4.f + (PI / 4.f) * (float)i);
			pProjectile->SetPos(ProjectilePos);
			pProjectile->SetScale(Vec2(25.f, 25.f));

			pCurLevel->AddObject(pProjectile);
		}
	}
	SetPos(vPos);
}


void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	SelectObject(_dc, CPal::GetInst()->getHPen(BLACK));
	SelectObject(_dc, CPal::GetInst()->getHBrush(BLACK));


	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

}