#include "pch.h"
#include "CProjectile.h"

#include "CCollider.h"


CProjectile::CProjectile()
	: m_Speed(0.f)
	, m_Angle(PI / 2.f)
	, m_Collider(nullptr)
{
	m_Collider = AddComponent<CCollider>(L"Collider");
}

CProjectile::~CProjectile()
{
}

void CProjectile::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	CObj::render(_dc);
}