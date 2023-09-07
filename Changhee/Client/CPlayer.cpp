#include "pch.h"
#include "CPlayer.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"

#include "CLevel.h"

#include "CProjectile.h"

CPlayer::CPlayer()
	: m_fSpeed(100.f)
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
		vPos.y -= m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::S))
	{
		vPos.y += m_fSpeed * _DT;
	}
	
	if (KEY_PRESSED(KEY::A))
	{
		vPos.x -= m_fSpeed * _DT;
	}
	
	if (KEY_PRESSED(KEY::D))
	{
		vPos.x += m_fSpeed * _DT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CProjectile* pProjectile = new CProjectile;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		pCurLevel->AddObject(pProjectile);
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


