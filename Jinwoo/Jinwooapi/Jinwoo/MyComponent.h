#pragma once
#include "MyEntity.h"

class MyObject;

class MyComponent :
    public MyEntity
{
private:
    // const를 뒤에 붙여서 포인터 변수인 m_pOwner를 수정하지 않게 함
    MyObject* const m_pOwner;

public:
    MyObject* GetOwner() { return m_pOwner; }

    virtual void tick(float _DT) {}
    virtual void finaltick(float _DT) = 0;

public:
    // 생성자를 따로 하나 구현하여 기본생성자가 자동으로 생기는 것을 방지
    MyComponent(MyObject* _Object);
    ~MyComponent();
};

