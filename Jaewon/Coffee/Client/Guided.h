#pragma once
#include "CProjectile.h"

class Monster;

class Guided :
    public CProjectile
{
    GENERATED_OBJECT(CProjectile);
private:
    Monster* mTarget;

    float       mMass;
    Vec2        mAccel;
    Vec2        mVelocity;
    Vec2        mForce;

    Vec2        mDir;

    float       mRotateSpeed;


public:
    void SetDir(Vec2 _vDir)
    {
        mDir = _vDir;
        mDir.Normalize();
    }

private:
    virtual void FindTarget();

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;
    virtual void beginOverLap(Collider* myCol, CObj* _othObj, Collider* _othCol) override;

private:
    void Update_1(float _dt);
    void Update_2(float _dt);
    void Update_3(float _dt);

public:
    Guided();
    ~Guided();
};

