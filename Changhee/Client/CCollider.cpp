#include "pch.h"
#include "CCollider.h"

#include "CObj.h"

CCollider::CCollider(CObj* _pOwner)
	: CComponent(_pOwner)
{
}

CCollider::~CCollider()
{
}


void CCollider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();

	m_vFinalPos = vOwnerPos + m_vOffsetPos;
}