#include "pch.h"
#include "CProjectile.h"
#include "Monster.h"
#include "CLevel.h"
#include "LevelMgr.h"


void CProjectile::tick(float _dt)
{
	

	if (mTarget == nullptr) {
		Vec2 vPos = getPos();
		CLevel* mLevel = LevelMgr::GetInst()->getCurLevel();
		mTarget = mLevel->findCloseMon(vPos);
	}
	else {
		update3(_dt);
		/*
		Vec2 closeMon = mTarget->getPos();
		
		float distX = closeMon.x - vPos.x;
		float distY = closeMon.y - vPos.y;
		float distXY = std::sqrtf(std::pow(closeMon.x - vPos.x, 2) + std::pow(closeMon.y - vPos.y, 2));

		vPos.x += mSpeed * (distX / distXY) * _dt * mAccel;
		vPos.y += mSpeed * (distY / distXY) * _dt * mAccel;

		mAccel += 0.001;
		
		setPos(vPos);
		*/
	}
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

void CProjectile::update3(float _dt) {
	mDir.Normalize();
	
	Vec2 destination = mTarget->getPos() - getPos();
	destination.Normalize();

	// 방향벡터와 목적지의 내적을 이용해서 각도 구하기
	float fDot = mDir.x * destination.x + mDir.y * destination.y;
	float fAngle = acosf(fDot);

	if (fAngle > M_PI / 90.f) {
		// 내적의 음/양 값에 따라서 -값을 준다
		if (GetRotateClock(mDir, destination))
			mDir - Rotate(mDir, mRotateSpeed * _dt);
		else
			mDir - Rotate(mDir, -mRotateSpeed * _dt);
	}
	float fSpeed = getSpeed();
	mVelocity = mDir * fSpeed;

	Vec2 vPos = getPos();
	vPos += mVelocity * _dt;
	setPos(vPos);


}

CProjectile::CProjectile() : mSpeed(0.f), mAngle(M_PI / 2.f), mTarget(nullptr), mMass(1.f), mRotateSpeed(M_PI)
{
}

CProjectile::~CProjectile()
{
}
