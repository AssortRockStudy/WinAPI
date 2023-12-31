﻿#include "pch.h"
#include "CProjectile.h"
#include "CLevelMgr.h"

#include "CPlayer.h"
#include "CMonster.h"

#include "CCollider.h"

CProjectile::CProjectile()
	: m_Speed(0.f)
	, m_Angle(PI / 2.f)
	, m_mass(5.f)
	, m_Collider(nullptr)
{
	m_Collider = AddComponent<CCollider>(L"Collider");
} 

CProjectile::~CProjectile()
{
}


//void CProjectile::tick(float _DT)
//{
//	Vec2 vPos = GetPos();
//	
//	
//	//addforce(100000.f, _DT);
//
//	vPos.x += m_Speed * cosf(m_Angle) * _DT;
//	vPos.y -= m_Speed * sinf(m_Angle) * _DT;
//
//	SetPos(vPos);
//}


void CProjectile::addforce(float _force , float _DT)
{

	float a = _force / m_mass;

	Vec2 vPos = GetPos();

	CMonster* cm = CLevelMgr::GetInst()->GetCurLevel()->getMonster();

	float targetth = atan2((-1) * (cm->GetPos().y - vPos.y), (cm->GetPos().x - vPos.x));

	int x = m_Speed * cosf(m_Angle) + (cosf(targetth)* a *_DT);

	//y의 증가량이 -이기때문
	int y = m_Speed * sinf(m_Angle) + (sinf(targetth)* a * _DT);

	m_Speed = sqrtf(pow(x,2) + pow(y,2));
	m_Angle = atan2(y, x);

}

void CProjectile::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
	CObj::render(_dc);
}
