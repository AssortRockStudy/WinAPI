#include "pch.h"
#include "Projectile.h"


Projectile::Projectile()
	: m_Speed(0.f)
	, m_Angle(PI/2.f)
{
}

Projectile::~Projectile()
{
}


//void Projectile::tick(float _DT)
//{
//	Vec2 vPos = GetPos();
//
//	vPos.x += m_Speed * cosf(m_Angle) * _DT;
//	vPos.y += m_Speed * sinf(m_Angle) * _DT;
//
//	SetPos(vPos);
//}

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
