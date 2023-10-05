#pragma once
#include "Obj.h"

class Monster : public Obj
{
    GENERATED_OBJECT(Obj);

private:
    FMonInfo m_Info;

public:
    void SetMonsterInfo(const FMonInfo& _Info)
    {
        m_Info = _Info;
    }
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    Monster();
    ~Monster();


};

