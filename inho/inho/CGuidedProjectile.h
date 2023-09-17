#pragma once
#include "CProjectile.h"

class CMonster;

class CGuidedProjectile :
    public CProjectile
{
private:
	CMonster* target;

	float m_fMass;
	Vec2 m_Accel;
	Vec2 m_vVelocity;

public:
	virtual void FindTarget();

public:
	virtual void tick(float _dt) override;
	

public:
	CGuidedProjectile();;
	~CGuidedProjectile();;
};

