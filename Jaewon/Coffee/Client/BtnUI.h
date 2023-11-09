#pragma once
#include "UI.h"

class Texture;

typedef void(*BtnCallBack)(void);
typedef void(CEntity::* DelegateFunc)(void);

class BtnUI :
    public UI
{
    GENERATED_OBJECT(UI);
private:
    Texture* mNormal;
    Texture* mHover;
    Texture* mPressed;
    Texture* mCur;

    BtnCallBack callBackFunc;
    CEntity* mInst;
    DelegateFunc mDelegate;
    Vec2 LbtnDownPos;

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    void setNormalImg(Texture* _NormalImg) { mNormal = _NormalImg; }
    void setPressedImg(Texture* _PressedImg) { mPressed = _PressedImg; }
    void setHoverImg(Texture* _HoverImg) { mHover = _HoverImg; }
    void setCallBack(BtnCallBack _CallBack) { callBackFunc = _CallBack; }
    void setDeletage(CEntity* _Inst, DelegateFunc _Func) { mInst = _Inst; mDelegate = _Func; }

    virtual void onHovered(Vec2 _vMousePos) override;
    virtual void onUnHovered(Vec2 _vMousePos) override;
    virtual void mouseOn(Vec2 _vMousePos) override;

    virtual void LBtnDown(Vec2 _vMousePos) override;
    virtual void LBtnUp(Vec2 _vMousePos) override;
    virtual void LBtnClicked(Vec2 _vMousePos) override;

public:
    BtnUI();
    ~BtnUI();
};

