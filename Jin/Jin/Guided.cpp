#include "pch.h"
#include "Guided.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Monster.h"

Guided::Guided()
	: m_Target(nullptr)
{
}

Guided::~Guided()
{
}

void Guided::tick(float _DT)
{
	if (nullptr == m_Target)
	{
		FindTarget();
	}
	else
	{
		Vec2 vPos = GetPos();
		// 1
		Vec2 vDir = m_Target->GetPos() - GetPos();
		vDir.Normalize();

		vPos.x += vDir.x * GetSpeed() * _DT;
		vPos.y += vDir.y * GetSpeed() * _DT;

		SetPos(vPos);

	}
}

void Guided::FindTarget()
{
	vector<Monster*> vecMon;
	Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();
	pCurLevel->GetObjects<Monster>(vecMon);

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


