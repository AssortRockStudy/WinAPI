#include "pch.h"
#include "NormalMonTrace.h"




NormalMonTrace::NormalMonTrace()
{
}

NormalMonTrace::~NormalMonTrace()
{
}

void NormalMonTrace::finaltick(float _DT)
{
	Vec2 vPlayerPos = m_pTarget->GetPos();

	Monster* pMonster = dynamic_cast<Monster*>(GetOwnerSM()->GetOwner());
	if (nullptr == pMonster)
		return;
	Vec2 vMonsterPos = pMonster->GetPos();

	float* pDetectRange = (float*)GetOwnerSM()->GetDataFromBlackboard(L"Detect Range");
	float DetectRange = *pDetectRange;

	float fDist = vPlayerPos.Distance(vMonsterPos);

	if (DetectRange < fDist)
	{
		GetOwnerSM()->ChangeState((UINT)ENORMAL_MON_STATE::NORMAL_MON_IDLE);
		return;
	}

	Vec2 vDir = vPlayerPos - vMonsterPos;
	vDir.Normalize();

	float* pSpeed = (float*)GetOwnerSM()->GetDataFromBlackboard(L"Speed");
	float fSpeed = *pSpeed;

	vMonsterPos += vDir * fSpeed * _DT;
	pMonster->SetPos(vMonsterPos);
}

void NormalMonTrace::Enter()
{
	m_pTarget = dynamic_cast<Player*>(LevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Player"));
}

void NormalMonTrace::Exit()
{
}