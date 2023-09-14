#pragma once
#include "CComponent.h"
class CCollider :
    public CComponent
{
private:
    Vec2    m_vOffsetPos;       // Owner로부터 떨어진 자리
    Vec2    m_vOffsetScale;     // Owner에 대한 추가 배율

    Vec2    m_vFinalPos;        // 충돌체의 최종 위치


public:
    virtual void finaltick(float _DT) override;

    Vec2 GetPos() { return m_vFinalPos; }

public:
    CCollider(CObj* _pOwner);
    ~CCollider();
};

