#pragma once
#include "CObj.h"

class CPlayer : public CObj {
    GENERATED_OBJECT(CObj);

  private:
    float m_Speed;

    HBITMAP m_Image;
    HDC     m_ImageDC;
    BITMAP  m_BitmapInfo;

    class CCollider* m_Collider;

  public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;
    virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

  public:
    CPlayer();
    ~CPlayer();
};
