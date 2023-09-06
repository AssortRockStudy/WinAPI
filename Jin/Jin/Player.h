#pragma once
#include "Obj.h"
class Player : 
    public Obj
{
    private:
        float       m_Speed;

    public:
        virtual void tick(float _DT) override;
        virtual void render(HDC _dc) override;

    public:
        Player();
        ~Player();
};

