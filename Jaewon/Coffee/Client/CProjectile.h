#pragma once
#include "CObj.h"

class Collider;

class CProjectile : public CObj
{
private:
	
	float   mSpeed;
	float   mAngle;
	Collider* mCollider;

public:
	void setAngle(float _theta) { mAngle = _theta; }
	void setSpeed(float _Speed) { mSpeed = _Speed; }

public:
	float getSpeed() { return mSpeed; }
	float getAngle() { return mAngle; };
	Collider* getCollider() { return mCollider; }

public:
	virtual void render(HDC _dc) override;

public:
	CProjectile();
	~CProjectile();
};

