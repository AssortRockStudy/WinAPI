#include "pch.h"
#include "CProjectile.h"
#include "Monster.h"
#include "CLevel.h"
#include "LevelMgr.h"
#include "Collider.h"


void CProjectile::render(HDC _dc)
{
	Vec2 vPos = getRenderPos();
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
	CObj::render(_dc);
}



CProjectile::CProjectile() : mSpeed(0.f), mAngle(M_PI / 2.f), mCollider(nullptr)
{
	mCollider = addComponent<Collider>(L"Collider");
}

CProjectile::~CProjectile()
{
}
