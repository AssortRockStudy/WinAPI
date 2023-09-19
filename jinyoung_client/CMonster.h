#pragma once
#include "CObj.h"


class CCollider;

class CMonster :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    FMonInfo    m_Info;

    CCollider* m_Collider;

public:
    virtual void begin() override;
    void SetMonsterInfo(const FMonInfo& _Info) { m_Info = _Info; }
    virtual void render(HDC _dc) override;

public:
    virtual void tick(float _DT) override;

public:
    CMonster();
    ~CMonster();
};

