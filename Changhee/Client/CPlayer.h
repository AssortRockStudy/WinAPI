#pragma once
#include "CObj.h"

class CCollider;

class CPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    float           m_fSpeed;

    HBITMAP         m_hImage;
    HDC             m_hImageDC;
    BITMAP          m_BitmapInfo;

    CCollider*      m_pCollider;


public:
    virtual void Overlap(CCollider* _pOwnCol, CObj* _pOtherObj, CCollider* _pOtherCol) override;

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CPlayer();
    ~CPlayer();

};

