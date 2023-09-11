#include "pch.h"
#include "CProjectile.h"
#include "Monster.h"
#include "CLevel.h"
#include "LevelMgr.h"

void CProjectile::tick(float _dt)
{
	Vec2 vPos = getPos();

	CLevel* mLevel = LevelMgr::GetInst()->getCurLevel();
	Vec2 closeMon = mLevel->findCloseMon(vPos);

	float distX = closeMon.x - vPos.x;
	float distY = closeMon.y - vPos.y;
	float distXY = std::sqrtf(std::pow(closeMon.x - vPos.x, 2) + std::pow(closeMon.y - vPos.y, 2));

	vPos.x += mSpeed * (distX / distXY) * _dt * mAccel;
	vPos.y += mSpeed * (distY / distXY) * _dt * mAccel;

	mAccel += 0.001;
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

CProjectile::CProjectile():mSpeed(0.f), mTheta(M_PI / 2.f), mAccel(0.001f)
{
}

CProjectile::~CProjectile()
{
}
