#pragma once
#include "CComponent.h"
class CCollider :
    public CComponent
{
private:
    Vec2    m_vOffsetPos;       // Owner�κ��� ������ �ڸ�
    Vec2    m_vOffsetScale;     // Owner�� ���� �߰� ����

    Vec2    m_vFinalPos;        // �浹ü�� ���� ��ġ


public:
    virtual void finaltick(float _DT) override;

    Vec2 GetPos() { return m_vFinalPos; }

public:
    CCollider(CObj* _pOwner);
    ~CCollider();
};

