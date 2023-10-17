#pragma once
#include "Component.h"
class Movement :
    public Component
{
private:
    Vec2    force;
    Vec2    accel;
    Vec2    velocity;
    float   mass;
    float   initSpeed;
    float   maxSpeed;
    float   friction;
    bool    gravityOn;
    Vec2    gravity;
    bool    onGround;

public:
    void addForce(Vec2 _vForce){
        force += _vForce;
    }

    Vec2 getForce(){
        return force;
    }

    void setVelocity(Vec2 _vVelocity){
        velocity = _vVelocity;
    }

    void AddVelocity(Vec2 _vAdd){
        velocity += _vAdd;
    }

    Vec2 getVelocity(){
        return velocity;
    }

    void setMass(float _Mass){
        mass = _Mass;
    }

    float getMass(){
        return mass;
    }

    void setInitSpeed(float _Speed){
        initSpeed = _Speed;
    }

    void setMaxSpeed(float _Speed){
        maxSpeed = _Speed;
    }

    float getInitSpeed(){
        return initSpeed;
    }

    float getMaxSpeed(){
        return maxSpeed;
    }

    void setFriction(float _F){
        friction = _F;
    }

    float setFriction(){
        return friction;
    }

    void useGravity(bool _Use){
        gravityOn = _Use;
    }

    bool isUseGravity(){
        return gravityOn;
    }

    void setGravity(Vec2 _vGravity){
        gravity = _vGravity;
    }

    Vec2 getGravity(){
        return Vec2(gravity).Normalize();;
    }

    bool isGround(){
        return onGround;
    }

    void setGround(bool _Ground){
        if (_Ground)
            velocity.y = 0.f;
        onGround = _Ground;
    }



public:
    virtual void finalTick(float _DT) override;

public:
    Movement(CObj* _Owner);
    ~Movement();
};

