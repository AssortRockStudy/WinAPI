#include "pch.h"
#include "CProjectile.h"


CProjectile::CProjectile()
	: m_Speed(0.f)
	, m_theta(PI / 2.f)
{
}

CProjectile::~CProjectile()
{
}

void CProjectile::tick(float _DT)
{
	Vec2 vPos = GetPos();

	vPos.x += m_Speed * cosf(m_theta) * _DT;
	vPos.y -= m_Speed * sinf(m_theta) * _DT;

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
