#pragma once
#include "MyUI.h"

class MyTexture;

class MyBtnUI :
    public MyUI
{
    GENERATED_OBJECT(MyUI);

private:
    MyTexture* m_NormalImg;     // 일반적인 상태일 때
    MyTexture* m_HoverImg;      // 마우스가 버튼에 올라갔을 때
    MyTexture* m_PressedImg;    // 버튼을 눌렀을 때
    MyTexture* m_CurImg;        // 현재 어떤 Img를 사용하는가

public:
    void SetNormalImg(MyTexture* _NormalImg) { m_NormalImg = _NormalImg; }
    void SetHoverImg(MyTexture* _HoverImg) { m_HoverImg = _HoverImg; }
    void SetPressedImg(MyTexture* _PressedImg) { m_PressedImg = _PressedImg; }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    virtual void OnHovered(Vec2 _vMousePos) override;
    virtual void MouseOn(Vec2 _vMousePos) override;
    virtual void OnUnHovered(Vec2 _vMousePos) override;

    virtual void LBtnDown(Vec2 _vMousePos) override;
    virtual void LBtnUp(Vec2 _vMousePos) override;
    virtual void LBtnClicked(Vec2 _vMousePos) override;
public:
    MyBtnUI();
    ~MyBtnUI();
};

