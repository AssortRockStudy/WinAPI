#pragma once
#include "CProjectile.h"
#include "CMonster.h"
class CAccGuidedProjectile :
    public CProjectile
{
private:
	CMonster* target;

public:
	virtual void tick(float _dt) override;


public:
	CAccGuidedProjectile() {};
	~CAccGuidedProjectile() {};

};

