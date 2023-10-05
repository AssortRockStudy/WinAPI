#include "pch.h"
#include "Collider.h"
#include "Obj.h"

Collider::Collider(Obj* _Owner)
	: Component(_Owner)
{
}

Collider::~Collider()
{
}

void Collider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();
	m_vFinalPos = vOwnerPos + m_vOffsetPos;
}

