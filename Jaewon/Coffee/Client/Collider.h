#pragma once
#include "Component.h"
class Collider :
    public Component
{
private:
    Vec2 offsetPos;
    Vec2 offsetScale;
    Vec2 finalPos;

public:
    Vec2 getPos() { return finalPos; }

public:
    virtual void finalTick(float _dt) override;
    
public:
    Collider(CObj* _owner);
    ~Collider();
};

