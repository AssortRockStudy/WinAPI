#include "pch.h"
#include "MyCollider.h"

#include "MyObject.h"

MyCollider::MyCollider(MyObject* _Object) : MyComponent(_Object)
{
}

MyCollider::~MyCollider()
{
}


void MyCollider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();

	m_finalPos = vOwnerPos + m_OffsetPos;
}