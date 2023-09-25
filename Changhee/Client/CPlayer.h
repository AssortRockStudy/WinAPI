#pragma once
#include "CObj.h"

class CTexture;
class CCollider;
class CAnimator;

class CPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    float                           m_fSpeed;
    CTexture*                       m_pAtlas;


    CCollider*                      m_pCollider;
    CAnimator*                      m_pAnimator;

public:
    virtual void tick(float _DT) override;

public:
    virtual void Overlap(CCollider* _pOwnCol, CObj* _pOtherObj, CCollider* _pOtherCol) override;


public:
    CPlayer();
    ~CPlayer();

};

