#pragma once
#include "CObj.h"
class CMonster :
    public CObj
{
private:
    float m_Speed;
    float m_Time;
public:
    virtual void tick(float _DT) override;

    CMonster();
    ~CMonster();
};

