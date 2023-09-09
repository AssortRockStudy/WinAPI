#include "pch.h"
#include "CProjectile2.h"

#include "CLevelMgr.h"
#include "CLevel.h"

CProjectile2::CProjectile2()
	: m_pTarget(nullptr)
	, m_fForce(100.f)
	, m_vVelocity{0.f,0.f}
	, m_fMass(50.f)
	, m_vAccel{0.f,0.f}
{
}

CProjectile2::~CProjectile2()
{
}



void CProjectile2::tick(float _DT)
{
	Targeting();

	Vec2 vPos = GetPos();
	Vec2 vMonPos = m_pTarget->GetPos();

	Vec2 vDiff = vMonPos - vPos;
	if (vDiff.Length() != 0.f)
	{
		vDiff.Normalize();

		m_vAccel = vDiff * m_fMass / m_fForce;
	}

	m_vVelocity = m_vVelocity + m_vAccel;

	vPos = vPos + m_vVelocity * _DT;

	SetPos(vPos);

}

void CProjectile2::Targeting()
{
	Vec2 vPos = GetPos();

	// 가장 가까운 몬스터 찾기
	vector<CObj*> vecMonster = CLevelMgr::GetInst()->GetCurLevel()->GetMonster();

	float min_dis = 9999999.f;

	for (int i = 0; i < vecMonster.size(); ++i)
	{
		Vec2 vMonPos = vecMonster[i]->GetPos();

		Vec2 diff = vPos - vMonPos;

		float dis = diff.Length();

		if (dis < min_dis)
		{
			min_dis = dis;
			m_pTarget = vecMonster[i];
		}
	}

}

