#pragma once
#include "UI.h"
class PanelUI :
    public UI
{
    GENERATED_OBJECT(UI);
private:

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    PanelUI();
    ~PanelUI();
};

