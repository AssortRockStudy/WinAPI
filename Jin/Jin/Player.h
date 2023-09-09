#pragma once
#include "Obj.h"
class Player : 
    public Obj
{
    private:
        float       m_Speed;
        HBITMAP     m_Image;
        HDC         m_ImageDC;
        BITMAP      m_BitmapInfo;

    public:
        virtual void tick(float _DT) override;
        virtual void render(HDC _dc) override;

    public:
        Player();
        ~Player();
};

