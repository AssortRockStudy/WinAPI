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
    Vec2          m_vVelocity;
    Vec2          m_vForce;
    Vec2          m_vDir;
    float           m_fRotateSpeed;


public:
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
    }
    virtual void FindTarget();
    virtual void tick(float _DT) override;

    Guided();
    ~Guided();

private :
    void Update_1();
    void Update_2();
    void Update_3();

};

