#include "pch.h"
#include "CLevel.h"

#include "CTimeMgr.h"
#include "CObj.h"

//CMonster* CLevel::GetCurruntMonster(Vec2 playerPos)
//{
//	float m1pos, m2pos;
//
//	m1pos = sqrt((m_Monster1->GetPos().y - playerPos.y) * (m_Monster1->GetPos().y - playerPos.y) + 
//		(m_Monster1->GetPos().x - playerPos.x) * (m_Monster1->GetPos().x - playerPos.x));
//	m2pos = sqrt((m_Monster2->GetPos().y - playerPos.y) * (m_Monster2->GetPos().y - playerPos.y) + 
//		(m_Monster2->GetPos().x - playerPos.x) * (m_Monster2->GetPos().x - playerPos.x));
//
//	if (m1pos > m2pos)
//		return m_Monster2;
//	else 
//		return m_Monster1;
//}

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i]; // 모든 인자를 지워줌
	}

	// 이후 CEngine 에서 자동으로 객체 소멸
}

void CLevel::tick()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(DT); // 모든 인자의 tick() 수행
	}
}

void CLevel::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc); // 모든 인자를 그림
	}
}
