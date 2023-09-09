#pragma once
#include "CProjectile.h"


class CObj;

class CProjectile2 :
    public CProjectile
{
private:
    CObj*   m_pTarget;

    Vec2    m_vVelocity;
    Vec2    m_vAccel;

    float   m_fMass;

    float   m_fForce;


public:
    virtual void tick(float _DT) override;
    void Targeting();


public:
    CProjectile2();
    ~CProjectile2();

};

