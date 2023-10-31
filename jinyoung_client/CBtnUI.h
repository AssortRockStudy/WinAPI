#pragma once
#include "CUI.h"

class CTexture;

class CBtnUI :
    public CUI
{
    GENERATED_OBJECT(CUI);
private:
    CTexture* m_NormalImg;
    CTexture* m_HoverImg;
    CTexture* m_PressedImg;
    CTexture* m_CurImg;

    // 콜백 (전역함수 포인터)    
    // 델리게이트(맴버함수 포인터, 객체)

public:
    void SetNormalImg(CTexture* _NormalImg) { m_NormalImg = _NormalImg; }
    void SetPressedImg(CTexture* _PressedImg) { m_PressedImg = _PressedImg; }
    void SetHoverImg(CTexture* _HoverImg) { m_HoverImg = _HoverImg; }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    virtual void OnHovered(Vec2 _vMousePos) override;
    virtual void OnUnHovered(Vec2 _vMousePos) override;
    virtual void MouseOn(Vec2 _vMousePos) override;

    virtual void LBtnDown(Vec2 _vMousePos) override;
    virtual void LBtnUp(Vec2 _vMousePos) override;
    virtual void LBtnClicked(Vec2 _vMousePos) override;

public:
    CBtnUI();
    ~CBtnUI();
};

