#pragma once
#include "Obj.h"
class Collider;

class Monster : public Obj
{
    GENERATED_OBJECT(Obj);

private:
    FMonInfo m_Info;
    Collider* m_Collider;

public:
    void SetMonsterInfo(const FMonInfo& _Info)
    {
        m_Info = _Info;
    }
    virtual void begin() override;
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    Monster();
    ~Monster();


};

