#include "pch.h"
#include "CLevel.h"

#include "CTimeMgr.h"

#include "CObj.h"

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i];
	}

}

void CLevel::tick()
{
	float DT = CTimeMgr::GetInst()->GetDeltaTime();

	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(DT);
	}
}

void CLevel::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc);
	}
}

