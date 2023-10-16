#pragma once
#include "MyObject.h"
class MyUI :
    public MyObject
{
    GENERATED_OBJECT(MyObject);

private:
    // nullptr일 경우 자신이 제일 부모임을 의미
    MyUI*           m_ParentUI;
    vector<MyUI*>   m_vecChildUI;

public:
    void AddChildUI(MyUI* _ChildUI)
    {
        m_vecChildUI.push_back(_ChildUI);
        _ChildUI->m_ParentUI = this;
    }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    MyUI();
    ~MyUI();
};

