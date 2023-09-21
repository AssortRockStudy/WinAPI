#pragma once
#include "CEntity.h"

class CObj;

class Component :
    public CEntity
{
private:
    CObj* const owner;

public:
    CObj* getOwner() { return owner; }

public:
    virtual void tick(float _dt) {}
    virtual void finalTick(float _dt) = 0;

public:
    Component(CObj* _owner);
    ~Component();
    
};

