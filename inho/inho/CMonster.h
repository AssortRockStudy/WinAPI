﻿#pragma once
#include "CObj.h"

class CMonster : public CObj {

    GENERATED_OBJECT(CObj);

  private:
    FMonInfo m_Info;

  public:
    void SetMonsterInfo(const FMonInfo& _Info) { m_Info = _Info; }

  public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

  public:
    CMonster();
    ~CMonster();
};