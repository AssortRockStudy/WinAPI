#pragma once
#include "CObj.h"
class CProjectile :
    public CObj
{
private:
    float   m_fSpeed;
    float   m_fTheta;

public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CProjectile();
    ~CProjectile();

};

