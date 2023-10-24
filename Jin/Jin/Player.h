#pragma once
#include "Obj.h"

class Player : 
    public Obj
{
    GENERATED_OBJECT(Obj);
    private:
        class Collider*        m_Collider;
        class Animator* m_Animator;
        class Movement* m_Movement;

    public:
        virtual void tick(float _DT) override;
        virtual void BeginOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol);
        virtual void EndOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol);


    public:
        CLONE(Player);
        Player();
        Player(const Player& _Origin);
        ~Player();
};

