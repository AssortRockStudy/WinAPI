#pragma once
#include "CObj.h"
class Monster;

class CProjectile : public CObj
{
private:
	Monster* mTarget;
	
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
	void setTarget(Monster* _target) { mTarget = _target; }
	void setDir(Vec2 _Dir){
		mDir = _Dir;
		mDir.Normalize();
	}

public:
	float getSpeed() { return mSpeed; }
	float getAngle() { return mAngle; };
	
public:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;
	void update3(float _dt);

public:
	CProjectile();
	~CProjectile();
};

