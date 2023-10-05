#pragma once
#include "Projectile.h"

class Monster;

class Guided :
    public Projectile
{
private:
    Monster*  m_Target;
    float            m_fMass;
    Vec2          m_vAccel;
    Vec2         m_vVelocity;


public:
    virtual void FindTarget();
    virtual void tick(float _DT) override;

    Guided();
    ~Guided();

};

