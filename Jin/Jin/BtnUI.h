#pragma once
#include "UI.h"
class Texture;

class BtnUI :
    public UI
{
    GENERATED_OBJECT(UI);
private:
    Texture* m_NormalImg;
    Texture* m_HoverImg;
    Texture* m_PressedImg;
    Texture* m_CurImg;
public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void OnHovered(Vec2 _vMousePos) override;
    virtual void OnUnHovered(Vec2 _vMousePos) override;
    virtual void MouseOn(Vec2 _vMousePos) override;

    virtual void LBtnDown(Vec2 _vMousePos) override;
    virtual void LBtnUp(Vec2 _vMousePos) override;
    virtual void LBtnClicked(Vec2 _vMousePos) override;



    void SetNormalImg(Texture* _NormalImg) { m_NormalImg = _NormalImg; }
    void SetPressedImg(Texture* _PressedImg) { m_PressedImg = _PressedImg; }
    void SetHoverImg(Texture* _HoverImg) { m_HoverImg = _HoverImg; }

public:
    BtnUI();
    ~BtnUI();
};

