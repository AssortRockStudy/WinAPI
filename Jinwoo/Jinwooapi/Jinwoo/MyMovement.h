#pragma once
#include "MyComponent.h"


class MyMovement :
    public MyComponent
{
private:
    // 누적된 힘
    Vec2    m_Force;

    // 현재 가속도
    Vec2    m_Accel;

    // 속도
    Vec2    m_Velocity;

    // 질량
    float   m_Mass;

    // 초기 속력
    float   m_InitSpeed;

    // 최대 속력
    float   m_MaxSpeed;

    // 마찰력
    float   m_FrictionScale;

    // 중력 기능 on & off
    bool    m_UseGravity;

    // 중력 방향 및 배율
    Vec2    m_GravityForce;

    // 현재 오브젝트가 땅 위에 있는가
    bool    m_Ground;
    
public:
    void AddForce(Vec2 _Force)
    {
        m_Force += _Force;
    }

    Vec2 GetForce()
    {
        return m_Force;
    }

    void SetVelocity(Vec2 _Velocity)
    {
        m_Velocity = _Velocity;
    }

    Vec2 GetVelocity()
    {
        return m_Velocity;
    }

    void AddVelocity(Vec2 _vAdd)
    {
        m_Velocity += _vAdd;
    }

    void SetMass(float _Mass)
    {
        m_Mass = _Mass;
    }

    float GetMass()
    {
        return m_Mass;
    }

    void SetInitSpeed(float _Speed)
    {
        m_InitSpeed = _Speed;
    }

    void SetMaxSpeed(float _Speed)
    {
        m_MaxSpeed = _Speed;
    }

    float GetInitSpeed()
    {
        return m_InitSpeed;
    }

    float GetMaxSpeed()
    {
        return m_MaxSpeed;
    }

    void SetFrictionScale(float _F)
    {
        m_FrictionScale = _F;
    }

    float GetFrictionScale()
    {
        return m_FrictionScale;
    }

    void UseGravity(bool _Use)
    {
        m_UseGravity = _Use;
    }

    bool IsUseGravity()
    {
        return m_UseGravity;
    }

    void SetGravity(Vec2 _Gravity)
    {
        m_GravityForce = _Gravity;
    }

    Vec2 GetGravityDir()
    {
        return Vec2(m_GravityForce).Normalize();
    }

    bool IsGround()
    {
        return m_Ground;
    }

    void SetGround(bool _Ground)
    {
        if (_Ground)
        {
            m_Velocity.y = 0.f;
        }

        m_Ground = _Ground;
    }

public:
    virtual void finaltick(float _DT) override;

public:
    MyMovement(MyObject* _Object);
    ~MyMovement();
};

