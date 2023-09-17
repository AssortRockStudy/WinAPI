#pragma once
#include "CObj.h"


class CMonster :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    FMonInfo    m_Info;


public:
    void SetMonsterInfo(const FMonInfo& _Info) { m_Info = _Info; }
    virtual void render(HDC _dc) override;

public:
    virtual void tick(float _DT) override;

public:
    CMonster();
    ~CMonster();
};

