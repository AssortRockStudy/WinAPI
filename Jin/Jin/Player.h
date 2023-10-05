#pragma once
#include "Obj.h"
class Collider;
class Texture;
class Animator;


class Player : 
    public Obj
{
    GENERATED_OBJECT(Obj);
    private:
        float                m_Speed;
        Collider*        m_Collider;
        Texture*         m_pTexture;
        Animator* m_Animator;

    public:
        virtual void tick(float _DT) override;
        virtual void render(HDC _dc) override;
        virtual void Overlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol);


    public:
        Player();
        ~Player();
};

