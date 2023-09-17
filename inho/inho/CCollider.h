#pragma once
#include "CComponent.h"
class CCollider :
    public CComponent
{

private:
    Vec2 m_vOffsetPos;
    Vec2 m_vOffsetScale;
    Vec2 m_vFinalPos;

public:
    virtual void finaltick(float _DT) override;
    
    Vec2 GetPos() { return m_vFinalPos; }

public:
    CCollider(class CObj* _Owner);
    ~CCollider();
};

