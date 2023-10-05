#pragma once
#include "Obj.h"

class Monster : public Obj
{
private:
    FMonInfo m_Info;

public:
    void SetMonsterInfo(const FMonInfo& _Info)
    {
        m_Info = _Info;
    }
    virtual void tick(float _DT) override;

public:
    Monster();
    ~Monster();


};

