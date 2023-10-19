#pragma once
#include "UI.h"
class Texture;

typedef void(*BtnCallBack)(void);
typedef void(Entity::* DelegateFunc)(void);

class BtnUI :
    public UI
{
    GENERATED_OBJECT(UI);
private:
    Texture* m_NormalImg;
    Texture* m_HoverImg;
    Texture* m_PressedImg;
    Texture* m_CurImg;

    BtnCallBack m_CallBackFunc;
    Entity* m_Inst;
    DelegateFunc m_Delegate;

    Vec2 m_vLbtnDownPos;


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

    void SetCallBack(BtnCallBack _CallBack)
    {
        m_CallBackFunc = _CallBack;
    }

    void SetDelegate(Entity* _Inst, DelegateFunc _Func)
    {
        m_Inst = _Inst;
        m_Delegate = _Func;
    }


public:
    BtnUI();
    ~BtnUI();
};

