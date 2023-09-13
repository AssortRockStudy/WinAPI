#pragma once
#include "CObj.h"


class CMonster :
    public CObj
{
private:
    FMonInfo    m_Info;


public:
    void SetMonsterInfo(const FMonInfo& _Info) { m_Info = _Info; }

public:
    virtual void tick(float _DT) override;

public:
    CMonster();
    ~CMonster();
};