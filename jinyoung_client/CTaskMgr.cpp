#include "pch.h"
#include "CTaskMgr.h"


#include "CLevelMgr.h"
#include "CLevel.h"
#include "CObj.h"

CTaskMgr::CTaskMgr()
{

}

CTaskMgr::~CTaskMgr()
{

}

void CTaskMgr::tick()
{
	for (size_t i = 0; i < m_vecTask.size(); ++i)
	{
		switch (m_vecTask[i].Type)
		{
		case CREATE_OBJECT:
		{
			LAYER layertype = (LAYER)m_vecTask[i].Param_1;
			CObj* Object = (CObj*)m_vecTask[i].Param_2;

			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
			pCurLevel->AddObject(layertype, Object);
		}
		break;
		case DELETE_OBJECT:

			break;
		case LEVEL_CHANGE:

			break;
		}
	}

	m_vecTask.clear();
}