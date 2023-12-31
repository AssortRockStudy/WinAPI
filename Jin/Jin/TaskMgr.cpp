#include "pch.h"
#include "TaskMgr.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Obj.h"

TaskMgr::TaskMgr()
{

}

TaskMgr::~TaskMgr()
{

}

void TaskMgr::tick()
{
	for (size_t i = 0; i < m_vecTask.size(); ++i)
	{
		switch (m_vecTask[i].Type)
		{
		case CREATE_OBJECT:
		{
			LAYER layertype = (LAYER)m_vecTask[i].Param_1;
			Obj* Object = (Obj*)m_vecTask[i].Param_2;

			Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();
			pCurLevel->AddObject(layertype, Object);
			Object->begin();
		}
		break;
		case DELETE_OBJECT:
		{
			Obj* pDeadObj = (Obj*)m_vecTask[i].Param_1;
			pDeadObj->SetDead();
		}
		break;
		case LEVEL_CHANGE:
		{
			LEVEL_TYPE type = (LEVEL_TYPE)m_vecTask[i].Param_1;
			LevelMgr::GetInst()->ChangeLevel(type);
		}
		break;
		}
	}

	m_vecTask.clear();
}
