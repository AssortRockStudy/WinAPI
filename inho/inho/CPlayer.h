#pragma once
#include "CObj.h"

class CPlayer :
    public CObj
{
private:
    float       m_Speed;

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CPlayer();
    ~CPlayer();
};

