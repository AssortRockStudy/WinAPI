#pragma once
#include "CUI.h"

class CBtnUI :
    public CUI
{
    GENERATED_OBJECT(CUI);
private:

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void OnHovered(Vec2 _vMousePos) override;
    virtual void OnUnHovered(Vec2 _vMousePos) override;
    virtual void MouseOn(Vec2 _vMousePos) override;

public:
    CBtnUI();
    ~CBtnUI();
};

