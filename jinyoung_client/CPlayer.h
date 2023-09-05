#pragma once
#include "CObj.h"

class CPlayer :
    public CObj
{



private:

public:
    virtual void tick() override;
    void render(HDC _dc) override;

public:
    CPlayer();
    ~CPlayer();
};

