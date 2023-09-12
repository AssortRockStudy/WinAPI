#pragma once
#include "CProjectile.h"


class CObj;

class CProjectile1 :
    public CProjectile
{
private:
    Vec2    m_vDir;
    CObj*   m_pTarget;
    float   m_fSpeed;



public:
    virtual void tick(float _DT) override;
    void Targeting();


public:
    CProjectile1();
    ~CProjectile1();

};

