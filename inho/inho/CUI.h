#pragma once
#include "CObj.h"
class CUI :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    CUI* m_ParentUI;
    vector<CUI*> m_vecChildUI;

public:
    void AddChildUI(CUI* _ChildUI) {
        m_vecChildUI.push_back(_ChildUI);
        _ChildUI->m_ParentUI = this;
    }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CUI();
    ~CUI();
};

