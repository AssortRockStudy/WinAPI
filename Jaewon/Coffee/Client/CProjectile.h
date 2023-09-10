#pragma once
#include "CObj.h"
class CProjectile : public CObj
{
private:
	float mSpeed;
	float mTheta;

public:
	void setDir(float _theta) { mTheta = _theta; }
	void setSpeed(float _speed) { mSpeed = _speed; }
	

public:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;

public:
	CProjectile();
	~CProjectile();
};

