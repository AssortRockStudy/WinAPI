#include "pch.h"
#include "MyProjectile.h"

#include "MyCollider.h"


MyProjectile::MyProjectile() : m_Speed(300.f), m_Angle(PI / 2.f), m_Collider(nullptr)
{
	m_Collider = AddComponent<MyCollider>(L"Collider");
}

MyProjectile::~MyProjectile()
{

}

void MyProjectile::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	MyObject::render(_dc);
}
