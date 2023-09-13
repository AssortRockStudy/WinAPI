#pragma once
#include "CMonster.h"
#include "CProjectile.h"
class CMissile3 :
    public CProjectile
{
private:
    CMonster* m_TargetMonster;

public:
    virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;

public:
    virtual void SetTarget(CMonster* monster) { m_TargetMonster = monster; }

};

