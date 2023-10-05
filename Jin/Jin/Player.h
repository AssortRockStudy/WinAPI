#pragma once
#include "Obj.h"
class Collider;


class Player : 
    public Obj
{
    GENERATED_OBJECT(Obj);
    private:
        float                m_Speed;
        HBITMAP     m_Image;
        HDC                m_ImageDC;
        BITMAP         m_BitmapInfo;
        Collider*        m_Collider;

    public:
        virtual void tick(float _DT) override;
        virtual void render(HDC _dc) override;

    public:
        Player();
        ~Player();
};

