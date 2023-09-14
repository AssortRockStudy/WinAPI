#pragma once
#include "CObj.h"

class CCollider;

class CPlayer :
    public CObj
{


private:
    //HBITMAP hLoadBit;
    HBITMAP m_Image;
    HDC m_ImageDC;
    BITMAP      m_BitmapInfo;
    CCollider* m_Collider;

public:
    float m_Speed;
    virtual void tick(float _DT) override;
    void render(HDC _dc) override;

public:
    CPlayer();
    ~CPlayer();
};

