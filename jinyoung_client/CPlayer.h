#pragma once
#include "CObj.h"

class CCollider;
class CTexture;
class CAnimator;

class CPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);


private:
    //HBITMAP hLoadBit;
    //HBITMAP m_Image;
    //HDC m_ImageDC;
    //BITMAP      m_BitmapInfo;
    CCollider* m_Collider;
    CTexture* m_pTexture;
    CAnimator* m_Animator;

public:
    float m_Speed;
    virtual void tick(float _DT) override;
    //더이상 오버라이드하지않고,애님에 이관한다.
    //void render(HDC _dc) override;
    virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

public:
    CPlayer();
    ~CPlayer();
};

