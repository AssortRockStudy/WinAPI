#include "pch.h"
#include "Projectile.h"

#include "Collider.h"


Projectile::Projectile()
	: m_Speed(0.f)
	, m_Angle(PI/2.f)
	, m_Collider(nullptr)
{
	m_Collider = AddComponent<Collider>(L"Collider");
}

Projectile::~Projectile()
{
}

void Projectile::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();


	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	Obj::render(_dc);

}
