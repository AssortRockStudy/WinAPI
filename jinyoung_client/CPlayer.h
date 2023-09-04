#pragma once
#include "CObj.h"

class CPlayer :
    public CObj
{
private:

public:
    virtual void tick() override;

public:
    CPlayer();
    ~CPlayer();
};

