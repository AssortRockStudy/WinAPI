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
		// 1. ����� ���ؼ� �̵��Ѵ�.
		// ����ź���� ���͸� ���ϴ� ������ ���Ѵ�.
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
	// ���� ������ �ִ� ������Ʈ�� �߿��� CMonster �κ��� �Ļ��� ��ü����� �޾ƿ´�.
	vector<CMonster*> vecMon;
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	pCurLevel->GetObjects<CMonster>(vecMon);

	// ���� ��� ��, ����ź�� �� ����� ���͸� Ÿ������ �����Ѵ�.
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