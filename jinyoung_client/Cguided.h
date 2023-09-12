#pragma once
#include "CProjectile.h"

class CMonster;

class CGuided :
    public CProjectile
{
private:
    CMonster* m_Target;
    float       m_fMass;
    Vec2        m_vVelocity;

    Vec2        m_vAccel;
    Vec2        m_vForce;
    Vec2        m_vDir;

    float       m_fRotateSpeed;


public:
    virtual void FindTarget();
    void update1();
    void update2();
    void update3();
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Normalize();
    }



public:
    virtual void tick(float _DT) override;

public:
    CGuided();
    ~CGuided();
};

