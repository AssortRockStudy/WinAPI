#pragma once
#include "CObj.h"

class CPlayer :
    public CObj
{


private:

public:
    float m_Speed;
    virtual void tick(float _DT) override;
    void render(HDC _dc) override;

public:
    CPlayer();
    ~CPlayer();
};
