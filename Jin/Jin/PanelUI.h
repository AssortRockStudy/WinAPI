#pragma once
#include "UI.h"
class PanelUI :
    public UI
{
    GENERATED_OBJECT(UI);
private:
    Vec2 m_vLBtnDownPos;
public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void LBtnDown(Vec2 _MousePos) override;
public:
    PanelUI();
    ~PanelUI();
};

