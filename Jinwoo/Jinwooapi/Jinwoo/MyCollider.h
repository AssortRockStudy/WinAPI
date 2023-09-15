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
    virtual void finaltick(float _DT) override;

public:
    MyCollider(MyObject* _Object);
    ~MyCollider();
};

