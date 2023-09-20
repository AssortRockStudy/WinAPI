#include "pch.h"
#include "CProjectile.h"
#include "Monster.h"
#include "CLevel.h"
#include "LevelMgr.h"


void CProjectile::render(HDC _dc)
{
	Vec2 vPos = getPos();
	Vec2 vScale = getScale();
	//POINT vertices[3] = { {int(vPos.x), int(vPos.y - vScale.y / 2)},
	//					  {int(vPos.x - vScale.x/2), int(vPos.y + vScale.y/2)},
	//	                  {int(vPos.x + vScale.x / 2), int(vPos.y + vScale.y / 2)}};
	//
	//Polygon(_dc, vertices, 3);
	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}



CProjectile::CProjectile() : mSpeed(0.f), mAngle(M_PI / 2.f)
{
}

CProjectile::~CProjectile()
{
}
