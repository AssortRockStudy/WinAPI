#pragma once
#include "CObj.h"
class Monster;

class CProjectile : public CObj
{
private:
	
	float   mSpeed;
	float   mAngle;

	float mMass;
	Vec2 mAccel;
	Vec2 mVelocity;
	Vec2 mForce;
	Vec2 mDir;
	float mRotateSpeed;

public:
	void setAngle(float _theta) { mAngle = _theta; }
	void setSpeed(float _Speed) { mSpeed = _Speed; }

public:
	float getSpeed() { return mSpeed; }
	float getAngle() { return mAngle; };
	
public:
	virtual void render(HDC _dc) override;

public:
	CProjectile();
	~CProjectile();
};

