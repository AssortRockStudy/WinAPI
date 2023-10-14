#pragma once
#include "Obj.h"
class UI :
    public Obj
{
    GENERATED_OBJECT(Obj);

private:
    UI* m_ParentUI;
    vector<UI*> m_vecChildUI;

public:
    void AddChildUI(UI* _ChildUI)
    {
        m_vecChildUI.push_back(_ChildUI);
        _ChildUI->m_ParentUI = this;
    }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    UI();
    ~UI();

};

