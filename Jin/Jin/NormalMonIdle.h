#pragma once
#include "State.h"
class NormalMonIdle :
    public State
{

private:
    Player* m_pTarget;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(NormalMonIdle);
    NormalMonIdle();
    ~NormalMonIdle();




};

