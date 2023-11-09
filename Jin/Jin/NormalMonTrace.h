#pragma once
#include "State.h"

class Player;

class NormalMonTrace :
    public State
{
private:
    Player* m_pTarget;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(NormalMonTrace);
    NormalMonTrace();
    ~NormalMonTrace();
};

