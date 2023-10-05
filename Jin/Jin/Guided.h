#pragma once
#include "Projectile.h"

class Monster;

class Guided :
    public Projectile
{
private:
    Monster*  m_Target;

public:
    virtual void FindTarget();
    virtual void tick(float _DT) override;

    Guided();
    ~Guided();

};

