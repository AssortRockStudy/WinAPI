#pragma once
#include "CObj.h"
class UI :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    UI* parentUI;
    vector<UI*> vecChildUI;
    Vec2 finalPos;
    bool mMouseOn;
    bool mouseOnPrev;
    bool mouseLBtnDown;

public:
    void AddChildUI(UI* _ChildUI)
    {
        vecChildUI.push_back(_ChildUI);
        _ChildUI->parentUI = this;
    }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void onHovered(Vec2 _vMousePos) {}
    virtual void mouseOn(Vec2 _vMousePos) {}
    virtual void onUnHovered(Vec2 _vMousePos) {}

    virtual void LBtnDown(Vec2 _vMousePos) {}
    virtual void LBtnUp(Vec2 _vMousePos) {}
    virtual void LBtnClicked(Vec2 _vMousePos) {}

    Vec2 getFinalPos() { return finalPos; }
    bool isLBtnDown() { return mouseLBtnDown; }

public:
    UI();
    ~UI();

    friend class UIMgr;
};

