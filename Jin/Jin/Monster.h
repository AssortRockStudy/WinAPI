#pragma once
#include "Obj.h"
class Collider;
class Texture;

class Monster : public Obj
{
    GENERATED_OBJECT(Obj);

private:
    FMonInfo m_Info;
    Collider* m_Collider;
    Texture* m_Texture;
    StateMachine* m_AI;

public:
    void SetMonsterInfo(const FMonInfo& _Info)
    {
        m_Info = _Info;
    }
    virtual void begin() override;
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override; 

    virtual void BeginOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol) override;



public:
    CLONE(Monster);
    Monster();
    Monster(const Monster& _Origin);
    ~Monster();


};

