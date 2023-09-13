#include "pch.h"
#include "CProjectile.h"
#include "CObj.h"

void CProjectile::tick(float _DT)
{
	Vec2 pos = GetPos(); // private라서 부모 멤버에 접근이 안되네요...

	// 삼각함수를 여기서 써먹네요
	pos.x += m_Speed * cosf(m_theta) * _DT;
	pos.y -= m_Speed * sinf(m_theta) * _DT; // 위로 올라가야 해서 빼주는 것

	SetPos(pos); // 다시 넣어줌
}

void CProjectile::render(HDC _dc)
{
	Vec2 pos = GetPos();
	Vec2 sca = GetScale();

	Ellipse(_dc,
		int(pos.x - sca.x) / 2,
		int(pos.y - sca.y) / 2,
		int(pos.x + sca.x) / 2,
		int(pos.y + sca.y) / 2); // Ellipse -> 원 그리는 함수. 인자는 Rectangle이랑 똑같음
}


CProjectile::CProjectile()
	:m_theta(PI / 2.f) // 2분의 PI = 90도
	,m_Speed(.0f)
{

}

CProjectile::~CProjectile()
{

}

