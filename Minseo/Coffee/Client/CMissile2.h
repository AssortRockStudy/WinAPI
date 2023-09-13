#pragma once
#include "CMonster.h"
#include "CProjectile.h"
class CMissile2 :
    public CProjectile
{
private:
    float m_SpeedX = 0.f;
    float m_SpeedY = 0.f;
    CMonster* m_TargetMonster;

public:
    virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;

public:
    virtual void SetTarget(CMonster* monster) { m_TargetMonster = monster; }

};

