#pragma once
#include "Obj.h"

class Monster : public Obj
{
private:
    float       m_Speed;

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    Monster();
    ~Monster();


};

