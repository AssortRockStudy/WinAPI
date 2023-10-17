#pragma once
#include "CObj.h"
class Platform :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class Collider* mCollider;


public:
    virtual void tick(float _DT) override;
    virtual void overLap(Collider* mycol, CObj* _othObj, Collider* _othCol) override;


public:
    Platform();
    ~Platform();
};

