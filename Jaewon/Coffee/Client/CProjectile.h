#pragma once
#include "CObj.h"
class CProjectile : public CObj
{
private:
	float mSpeed;
	float mTheta;
	float mAccel;

public:
	void setDir(float _theta) { mTheta = _theta; }
	void setSpeed(float _speed) { mSpeed = _speed; }
	void setAccel(float _accel) { mAccel = _accel; }
	

public:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;

public:
	CProjectile();
	~CProjectile();
};

