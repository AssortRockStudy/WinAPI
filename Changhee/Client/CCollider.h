#pragma once
#include "CComponent.h"
class CCollider :
    public CComponent
{
private:
    Vec2    m_vOffsetPos;       // Owner로부터 떨어진 자리
    Vec2    m_vScale;           // Collider 크기
    Vec2    m_vFinalPos;        // 충돌체의 최종 위치

    int     m_iCollisionCount;

public:
    Vec2 GetOffsetPos() { return m_vOffsetPos; }
    Vec2 GetScale() { return m_vScale; }
    Vec2 GetPos() { return m_vFinalPos; }

    void SetOffsetPos(Vec2 _vOffsetPos) { m_vOffsetPos = _vOffsetPos; }
    void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

public:
    void BeginOverlap(CCollider* _pOtherCol);
    void Overlap(CCollider* _pOtherCol);
    void EndOverlap(CCollider* _pOtherCol);

public:
    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CCollider(CObj* _pOwner);
    ~CCollider();
};

