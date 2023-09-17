#pragma once
#include "CComponent.h"
class CCollider :
    public CComponent
{

private:
    Vec2 m_vOffsetPos;
    Vec2 m_vScale;
    Vec2 m_vFinalPos;

public:
    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    void SetOffsetPos(Vec2 _vOffset) { m_vOffsetPos = _vOffset; }
    void SetScale(Vec2 _vScale) { m_vScale = _vScale; }    
    Vec2 GetPos() { return m_vFinalPos; }
    Vec2 GetOffsetPos() { return m_vOffsetPos; }
    Vec2 GetScale() { return m_vScale; }

public:
    CCollider(class CObj* _Owner);
    ~CCollider();
};

