#pragma once
#include "CComponent.h"
class CMovement :
    public CComponent
{

private:

    Vec2 m_Force;
    Vec2 m_Accel;
    Vec2 m_Velocity;
    float m_Mass;
    float m_InitSpeed;
    float m_MaxSpeed;
    float m_FrictionScale;
    bool m_UseGravity;

    Vec2 m_GravityDir;
    bool m_Ground;

public:
    void AddForce(Vec2 _vForce) {
        m_Force += _vForce;
    }

    Vec2 GetForce() {
        return m_Force;
    }

    void SetVelocity(Vec2 _vVelocity) {
        m_Velocity = _vVelocity;
    }

    Vec2 GetVelocity() {
        return m_Velocity;
    }

    void SetMass(float _Mass) {
        m_Mass = _Mass;
    }

    float GetMass() {
        return m_Mass;
    }

    void SetInitSpeed(float _Speed) {
        m_InitSpeed = _Speed;
    }

    void SetMaxSpeed(float _Speed) {
        m_MaxSpeed = _Speed;
    }

    float GetInitSpeed() {
        return m_InitSpeed;
    }

    float GetMaxSpeed() {
        return m_MaxSpeed;
    }

    void SetFrictionScale(float _F) {
        m_FrictionScale = _F;
    }

    float GetFrictionScale() {
        return m_FrictionScale;
    }

    void UseGravity(bool _Use) {
        m_UseGravity = _Use;
    }

    bool IsUseGravity() {
        return m_UseGravity;
    }

    void SetGravityDir(Vec2 _vGravityDir) {
        m_GravityDir = _vGravityDir;
    }

    Vec2 GetGravityDir() {
        return m_GravityDir;
    }

    bool IsGround() {
        return m_Ground;
    }

public:
    virtual void finaltick(float _DT) override;

public:
    CMovement(CObj* _Owner);
    ~CMovement();
};

