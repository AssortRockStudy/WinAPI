#include "pch.h"
#include "CProjectile.h"

void CProjectile::tick(float _dt)
{
	Vec2 vPos = getPos();

	vPos.x += mSpeed * cosf(mTheta) * _dt;
	vPos.y += mSpeed * sinf(mTheta) * _dt;

	setPos(vPos);
}

void CProjectile::render(HDC _dc)
{
	Vec2 vPos = getPos();
	Vec2 vScale = getScale();
	POINT vertices[3] = { {int(vPos.x), int(vPos.y - vScale.y / 2)},
						  {int(vPos.x - vScale.x/2), int(vPos.y + vScale.y/2)},
		                  {int(vPos.x + vScale.x / 2), int(vPos.y + vScale.y / 2)}};

	Polygon(_dc, vertices, 3);
}

CProjectile::CProjectile():mSpeed(0.f), mTheta(M_PI / 2.f)
{
}

CProjectile::~CProjectile()
{
}
