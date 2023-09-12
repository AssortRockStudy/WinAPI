#include "pch.h"
#include "CGuided.h"

#include "CLevelMgr.h"
#include "CLevel.h"

#include "CMonster.h"
#include "CTimeManager.h"

CGuided::CGuided()
	: m_Target(nullptr)
	, m_fMass(1.f)
{
	m_vVelocity = Vec2(0, -300);

}

CGuided::~CGuided()
{
}

void CGuided::tick(float _DT)
{
	if (nullptr == m_Target)
	{
		FindTarget();
	}
	else
	{
		// 1. 대상을 향해서 이동한다.
		//update1();

		// 2.
		update2();


		// 3.
		//update3();
	}
}


void CGuided::update2()
{
	// 힘에 의한 움직임
	// 1. 타겟을 향하는 방향으로 100의 크기의 힘을 설정
	float Force = 1000.f;
	Vec2 vForce = m_Target->GetPos() - GetPos();
	vForce.Normalize() *= Force;

	// 가속도 구하기
	// F = M * A
	// A = F / M
	m_vAccel = vForce / m_fMass;

	// 가속도에 의해서 시간당 속도가 변화함
	m_vVelocity += m_vAccel * DT;

	// 거리 = 속도 * 시간
	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;

	SetPos(vPos);
}





void CGuided::update1()
{
	// 유도탄에서 몬스터를 향하는 방향을 구한다.
	Vec2 vPos = GetPos();


	Vec2 vDir = m_Target->GetPos() - GetPos();
	vDir.Normalize();

	vPos.x += vDir.x * GetSpeed() * DT;
	vPos.y += vDir.y * GetSpeed() * DT;

	SetPos(vPos);
}

void CGuided::update3()
{
	m_vDir.Normalize();
	float fSpeed = GetSpeed();

	m_vVelocity = m_vDir * fSpeed;

	Vec2 vPos = GetPos();
	vPos += m_vVelocity * DT;
	SetPos(vPos);
}



void CGuided::FindTarget()
{
	// 현재 레벨에 있는 오브젝트들 중에서 CMonster 로부터 파생된 객체목록을 받아온다.
	vector<CMonster*> vecMon;
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	pCurLevel->GetObjects<CMonster>(vecMon);

	// 몬스터 목록 중, 유도탄과 더 가까운 몬스터를 타겟으로 지정한다.
	if (vecMon.size() == 1)
	{
		m_Target = vecMon[0];
	}
	else if (vecMon.empty())
	{
		return;
	}
	else
	{
		float fMax = 2000.f;

		for (size_t i = 0; i < vecMon.size(); ++i)
		{
			float fDistance = GetPos().Distance(vecMon[i]->GetPos());

			if (fMax > fDistance)
			{
				fMax = fDistance;

				m_Target = vecMon[i];
			}
		}
	}
}
