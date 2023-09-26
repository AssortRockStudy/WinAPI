#pragma once
#include "CComponent.h"

class CMovement :
    public CComponent
{
private:
    Vec2    m_vForce;
    Vec2    m_vVelocity;
    Vec2    m_vAccel;
    float   m_fMass;
    float   m_fFrictionScale;

    float   m_fInitSpeed;
    float   m_fMaxSpeed;

    Vec2    m_vGravityDir;
    bool    m_bUseGravity;
    bool    m_bGround;

public:
    Vec2 GetForce() { return m_vForce; }
    Vec2 GetVelocity() { return m_vVelocity; }
    float GetMass() { return m_fMass; }
    float GetInitSpeed() { return m_fInitSpeed; }
    float GetMaxSpeed() { return m_fMaxSpeed; }
    float GetFrictionScale() { return m_fFrictionScale; }
    Vec2 GetGravityDir() { return m_vGravityDir; }
    bool IsUseGravity() { return m_bUseGravity; }
    bool IsGround() { return m_bGround; }

public:
    void AddForce(Vec2 _vForce) { m_vForce += _vForce; }
    void SetVelocity(Vec2 _vVelocity) { m_vVelocity = _vVelocity; }
    void SetMass(float _fMass) { m_fMass = _fMass; }
    void SetInitSpeed(float _fSpeed) { m_fInitSpeed = _fSpeed; }
    void SetMaxSpeed(float _fSpeed) { m_fMaxSpeed = _fSpeed; }
    void SetFrictionScale(float _F) { m_fFrictionScale = _F; }
    void UseGravity(bool _bUse) { m_bUseGravity = _bUse; }
    void SetGravityDir(Vec2 _vGravityDir) { m_vGravityDir = _vGravityDir; }
    



public:
    virtual void finaltick(float _DT) override;

public:
    CMovement(CObj* _Owner);
    ~CMovement();
};
