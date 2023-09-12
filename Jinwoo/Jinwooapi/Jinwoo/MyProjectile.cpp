#include "pch.h"
#include "MyProjectile.h"

MyProjectile::MyProjectile() : m_Speed(300.f), m_Angle(PI / 2.f)
{

}

MyProjectile::~MyProjectile()
{

}

void MyProjectile::tick(float _DT)
{
	Vec2 vPos = GetPos();

	vPos.x += m_Speed * cosf(m_Angle) * _DT;
	vPos.y -= m_Speed * sinf(m_Angle) * _DT;

	SetPos(vPos);
}

void MyProjectile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}
