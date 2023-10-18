#pragma once
#include "UI.h"
class BtnUI :
    public UI
{
    GENERATED_OBJECT(UI);
private:

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void OnHovered(Vec2 _vMousePos) override;
    virtual void OnUnHovered(Vec2 _vMousePos) override;
    virtual void MouseOn(Vec2 _vMousePos) override;

public:
    BtnUI();
    ~BtnUI();
};

