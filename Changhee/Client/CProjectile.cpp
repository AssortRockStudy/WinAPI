#include "pch.h"
#include "CProjectile.h"


CProjectile::CProjectile()
	: m_fSpeed(0.f)
	, m_fTheta(0.f)
{
}

CProjectile::~CProjectile()
{
}



void CProjectile::tick(float _DT)
{
	Vec2 vPos = GetPos();

	vPos.x += m_fSpeed * cosf(m_fTheta) * _DT;
	vPos.y -= m_fSpeed * sinf(m_fTheta) * _DT;

	SetPos(vPos);
}

void CProjectile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

}

