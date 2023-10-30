#include "pch.h"
#include "NormalMonIdle.h"

NormalMonIdle::NormalMonIdle()
{
}

NormalMonIdle::~NormalMonIdle()
{
}

void NormalMonIdle::finaltick(float _DT)
{
	if (nullptr == m_pTarget)
		return;

	float* pDetectRange = (float*)GetOwnerSM()->GetDataFromBlackboard(L"Detect Range");
	float DetectRange = *pDetectRange;

	Vec2 vPlayerPos = m_pTarget->GetPos();

	Monster* pMonster = dynamic_cast<Monster*>(GetOwnerSM()->GetOwner());
	if (nullptr == pMonster)
		return;

	Vec2 vMonsterPos = pMonster->GetPos();
	float fDist = vPlayerPos.Distance(vMonsterPos);

	if (fDist < DetectRange)
	{
		GetOwnerSM()->ChangeState((UINT)ENORMAL_MON_STATE::NORMAL_MON_TRACE);
	}
}

void NormalMonIdle::Enter()
{
	m_pTarget = dynamic_cast<Player*>(LevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Player"));
}

void NormalMonIdle::Exit()
{
}



