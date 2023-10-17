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
    Vec2            m_vFinalPos;

    bool            m_bMouseOn;
    bool            m_bMouseOn_Prev;

    bool            m_bMouseLBtnDown;

public:
    void AddChildUI(MyUI* _ChildUI)
    {
        m_vecChildUI.push_back(_ChildUI);
        _ChildUI->m_ParentUI = this;
    }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void OnHovered(Vec2 _vMousePos) {}
    virtual void MouseOn(Vec2 _vMousePos) {}
    virtual void OnUnHovered(Vec2 _vMousePos) {}

    virtual void LBtnDown(Vec2 _vMousePos) {}
    virtual void LBtnUp(Vec2 _vMousePos) {}
    virtual void LBtnClicked(Vec2 _vMousePos) {}

public:
    Vec2 GetFinalPos() { return m_vFinalPos; }

public:
    MyUI();
    ~MyUI();

    friend class MyUIMgr;
};

