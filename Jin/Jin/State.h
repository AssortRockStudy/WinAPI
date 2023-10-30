#pragma once
#include "Entity.h"

#include "StateMachine.h"

#include "Obj.h"
#include "Animator.h"

#include "LevelMgr.h"
#include "Level.h"

#include "Monster.h"
#include "Player.h"

class State :
    public Entity
{
private:
    StateMachine* m_pSM;
    UINT m_StateID;

public:
    StateMachine* GetOwnerSM()
    {
        return m_pSM;
    }
    UINT GetStateID()
    {
        return m_StateID;
    }

public:
    virtual void finaltick(float _DT) = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;

public:
    virtual State* Clone() = 0;

public:
    State();
    ~State();

    friend class StateMachine;

};

