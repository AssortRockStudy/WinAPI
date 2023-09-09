#pragma once
#include "CObj.h"
class CMonster :
    public CObj
{
private:
    float       m_fSpeed;

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CMonster();
    ~CMonster();

};

