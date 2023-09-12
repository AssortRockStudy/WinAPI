#include "pch.h"
#include "HomingBullet.h"

#include "MyTimeMgr.h"
#include "MyLevelMgr.h"

#include "MyLevel.h"
#include "MyMonster.h"

HomingBullet::HomingBullet() : m_TargetMonster(nullptr)
{
}

HomingBullet::~HomingBullet()
{
}

void HomingBullet::tick(float _DT)
{
	if (nullptr == m_TargetMonster)
	{
		FindTarget();
	}
	else
	{
		Fire01();
	}
}

void HomingBullet::FindTarget()
{
	// 현재 레벨에 있는 오브젝트 중에서 MyMonster 클래스로 생성된 객체들을 찾는다
	vector<MyMonster*> vMonster;

	// 레벨 매니저에서 현재 레벨을 받아오고
	MyLevel* CurLevel = MyLevelMgr::GetInst()->GetCurLevel();

	// 받아온 현재 레벨에 존재하는 몬스터 객체를 찾는다
	CurLevel->GetObjects(vMonster);

	// 몬스터가 한마리만 있다면
	if (1 == vMonster.size())
	{
		m_TargetMonster = vMonster[0];
	}
	else if (0 == vMonster.size())
	{
		return;
	}
	else
	{
		// 두 마리 이상일 경우 플레이어 위치에서 가까운 몬스터를 타겟으로 한다
		float fMax = 2000.f;

		for (size_t i = 0; i < vMonster.size(); ++i)
		{
			float fDistance = GetPos().Distance(vMonster[i]->GetPos());

			if (fMax > fDistance)
			{
				fMax = fDistance;
				
				m_TargetMonster = vMonster[i];
			}
		}
	}
}

void HomingBullet::Fire01()
{
	Vec2 vPos = GetPos();
	Vec2 vMonsPos = m_TargetMonster->GetPos();
	Vec2 vDir = vMonsPos - vPos;

	vDir.Normalize();

	vPos.x += vDir.x * GetSpeed() * DT;
	vPos.y += vDir.y * GetSpeed() * DT;

	SetPos(vPos);
}