#pragma once
#include "MyObject.h"

class MyCollider;

class MyPlatform :
    public MyObject
{
    GENERATED_OBJECT(MyObject);

private:
    MyCollider* m_Collider;

public:
    virtual void tick(float _DT) override;
    virtual void Overlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol) override;

public:
    MyPlatform();
    ~MyPlatform();
};

