﻿#pragma once
#include "CObj.h"

class CCollider;
class CTexture;

class CPlayer : public CObj {
    GENERATED_OBJECT(CObj);

  private:
    float m_Speed;

    CCollider* m_Collider;
    CTexture* m_pTexture;

  public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;
    virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

  public:
    CPlayer();
    ~CPlayer();
};
