#pragma once
#include "Level.h"
class StartLevel :
    public Level
{
public:
    virtual void init() override;
    virtual void enter() override;
    virtual void exit() override;

    virtual void tick() override;
};

