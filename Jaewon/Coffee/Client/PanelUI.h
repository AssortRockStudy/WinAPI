#pragma once
#include "UI.h"
class PanelUI :
    public UI
{
    GENERATED_OBJECT(UI);
private:
    Vec2 LbtnDownPos;
public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void LBtnDown(Vec2 _vMousePos) override;

public:
    PanelUI();
    ~PanelUI();
};

