#include "pch.h"
#include "CLevel.h"

#include "CTimeMgr.h"
#include "CLayer.h"
#include "CObj.h"



CLevel::CLevel()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_arrLayer[i] = new CLayer;
	}
}

CLevel::~CLevel()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		if(m_arrLayer != nullptr)
			delete m_arrLayer[i];
	}

}

void CLevel::tick()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_arrLayer[i]->tick(DT);
	}


}

void CLevel::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_arrLayer[i]->render(_dc);
	}

}

void CLevel::AddObject(LAYER _eLayer, CObj* _Object)
{
	m_arrLayer[(UINT)_eLayer]->AddObject(_Object);
}

