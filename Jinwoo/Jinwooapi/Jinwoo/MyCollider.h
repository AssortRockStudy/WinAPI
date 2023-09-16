#pragma once
#include "MyComponent.h"

class MyCollider :
    public MyComponent
{
private:
    Vec2 m_OffsetPos;
    Vec2 m_OffsetScale;

    Vec2 m_finalPos;

public:
    Vec2 GetColliderPos() { return m_finalPos; }
    Vec2 GetOffsetPos() { return m_OffsetPos; }
    Vec2 GetOffsetScale() { return m_OffsetScale; }
    Vec2 GetFinalPos() { return m_finalPos; }

    void SetOffsetPos(Vec2 _OffsetPos) { m_OffsetPos = _OffsetPos; }
    void SetOffsetScale(Vec2 _OffsetScale) { m_OffsetScale = _OffsetScale; }

    virtual void finaltick(float _DT) override;

    virtual void render(HDC _dc) override;

public:
    MyCollider(MyObject* _Object);
    ~MyCollider();
};

