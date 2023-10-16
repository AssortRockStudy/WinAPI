#pragma once
#include "MyUI.h"
class MyBtnUI :
    public MyUI
{
    GENERATED_OBJECT(MyUI);

private:

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    MyBtnUI();
    ~MyBtnUI();
};

