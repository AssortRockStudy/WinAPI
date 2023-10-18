#pragma once
#include "CObj.h"
class UI :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    UI* parentUI;
    vector<UI*> vecChildUI;

public:
    void AddChildUI(UI* _ChildUI)
    {
        vecChildUI.push_back(_ChildUI);
        _ChildUI->parentUI = this;
    }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;
public:
    UI();
    ~UI();
};

