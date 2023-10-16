#pragma once
#include "MyUI.h"
class MyPanelUI :
    public MyUI
{
    GENERATED_OBJECT(MyUI);

private:

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    MyPanelUI();
    ~MyPanelUI();
};

