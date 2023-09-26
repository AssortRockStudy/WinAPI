#pragma once
#include "CObj.h"

class CTexture;
class CCollider;
class CAnimator;
class CMovement;

class CPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    float                           m_fSpeed;

    CCollider*                      m_pCollider;
    CAnimator*                      m_pAnimator;
    CMovement*                      m_pMovement;

public:
    virtual void tick(float _DT) override;

public:
    virtual void Overlap(CCollider* _pOwnCol, CObj* _pOtherObj, CCollider* _pOtherCol) override;


public:
    CPlayer();
    ~CPlayer();

};

