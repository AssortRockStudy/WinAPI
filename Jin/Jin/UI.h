#pragma once
#include "Obj.h"

class UI :
    public Obj
{
    GENERATED_OBJECT(Obj);

private:
    UI* m_ParentUI;
    vector<UI*> m_vecChildUI;
    Vec2 m_vFinalPos;

    bool m_bMouseOn;
    bool m_bMouseOn_Prev;
    bool m_bMouseLBtnDown;

public:
    void AddChildUI(UI* _ChildUI)
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

    Vec2 GetFinalPos()
    { 
        return m_vFinalPos; 
    }

public:
    UI();
    ~UI();

    friend class UIMgr;
};

