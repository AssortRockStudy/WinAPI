#pragma once
#include "CProjectile.h"

class CMonster;

class CGuided :
    public CProjectile
{
private:
    CMonster* m_Target;
    float       m_fMass;
    Vec2        m_vAccel;
    Vec2        m_vVelocity;

public:
    virtual void FindTarget();

public:
    virtual void tick(float _DT) override;

public:
    CGuided();
    ~CGuided();
};

