#pragma once
#include "CProjectile.h"
#include "CMonster.h"


class  CAngularGuidedProjectile 
	:	public CProjectile
{
private:
	CMonster* target;

public:
	virtual void tick(float _dt) override;


public:
	CAngularGuidedProjectile() {};
	~CAngularGuidedProjectile() {};
};

