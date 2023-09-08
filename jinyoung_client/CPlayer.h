#pragma once
#include "CObj.h"

class CPlayer :
    public CObj
{


private:
    //HBITMAP hLoadBit;
    HBITMAP m_Image;
    HDC m_Image_dc;
    int m_BitmapInfo;
public:
    float m_Speed;
    virtual void tick(float _DT) override;
    void render(HDC _dc) override;

public:
    CPlayer();
    ~CPlayer();
};

