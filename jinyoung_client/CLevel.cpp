#include "pch.h"
#include "CLevel.h"

#include "CTimeManager.h"
#include "CObj.h"
#include "CLayer.h"

class CEntity;
class CLayer;


CLevel::CLevel()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new CLayer;
	}
}

CLevel::~CLevel()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}

void CLevel::tick()
{
	//float DT = CTimeManager::GetInst()->GetDeltaTime();

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->finaltick(DT);
	}
}

void CLevel::render(HDC _dc)
{
	//for (size_t i = 0; i < m_vecObjects.size(); ++i)
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}


void CLevel::AddObject(LAYER _LayerType, CObj* _Object)
{
	m_Layer[_LayerType]->AddObject(_Object);
}