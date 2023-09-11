#pragma once
#include "CProjectile.h"
class Cguided :
    public CProjectile
{
private:
    CObj* m_Taget;

public:
    virtual void tick(float _DT) override;
    virtual void FindTarget();

    Cguided();
    ~Cguided();
    


};

