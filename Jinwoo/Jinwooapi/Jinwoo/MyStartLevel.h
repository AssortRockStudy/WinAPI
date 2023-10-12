#pragma once
#include "MyLevel.h"
class MyStartLevel :
    public MyLevel
{
public:
    virtual void init() override;
    virtual void enter() override;
    virtual void exit() override;

    virtual void tick() override;
};

