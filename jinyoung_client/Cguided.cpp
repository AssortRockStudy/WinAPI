#include "pch.h"
#include "CGuided.h"

#include "CLevelMgr.h"
#include "CLevel.h"

#include "CMonster.h"


CGuided::CGuided()
	: m_Target(nullptr)
{
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
		Vec2 vPos = GetPos();
		// 1. 대상을 향해서 이동한다.
		// 유도탄에서 몬스터를 향하는 방향을 구한다.
		Vec2 vDir = m_Target->GetPos() - GetPos();
		vDir.Normalize();

		vPos.x += vDir.x * GetSpeed() * _DT;
		vPos.y += vDir.y * GetSpeed() * _DT;

		SetPos(vPos);

		// 2.


		// 3.
	}
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