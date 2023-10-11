#pragma once
#include "Obj.h"
class Platform :
    public Obj
{
    GENERATED_OBJECT(Obj);
private:
    class Collider* m_Collider;

public:
    virtual void tick(float _DT) override;
    virtual void Overlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol) override;

public:
    Platform();
    ~Platform();

};

