#include "pch.h"
#include "MyTaskMgr.h"

#include "MyLevelMgr.h"
#include "MyLevel.h"
#include "MyObject.h"

MyTaskMgr::MyTaskMgr()
{

}

MyTaskMgr::~MyTaskMgr()
{

}

void MyTaskMgr::tick()
{
	for (size_t i = 0; i < m_vecTask.size(); ++i)
	{
		switch (m_vecTask[i].Type)
		{
		case TASK_TYPE::CREATE_OBJECT:
		{
			LAYER LayerType = (LAYER)m_vecTask[i].Param1;
			MyObject* Object = (MyObject*)m_vecTask[i].Param2;

			MyLevel* pCurLevel = MyLevelMgr::GetInst()->GetCurLevel();
			pCurLevel->AddObject(LayerType, Object);
		}
		break;

		case TASK_TYPE::DELETE_OBJECT:
		{
		}
		break;

		case TASK_TYPE::LEVEL_CHANGE:
		{
		}
		break;
		}
	}

	m_vecTask.clear();
}