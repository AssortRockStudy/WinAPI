#include "pch.h"
#include "TaskMgr.h"
#include "CLayer.h"
#include "CLevel.h"
#include "LevelMgr.h"
#include "CObj.h"


void TaskMgr::tick()
{
	for (size_t i = 0; i < mVecTask.size(); ++i) {
		switch (mVecTask[i].Type)
		{
		case CREATE_OBJECT: {
			LAYER layerType = (LAYER)mVecTask[i].Param1;
			CObj* obj = (CObj*)mVecTask[i].Param2;
			CLevel* curLevel = LevelMgr::GetInst()->getCurLevel();
			curLevel->addObject(layerType, obj);
			obj->begin();
		}
			break;
		case DELETE_OBJECT:
			break;
		case LEVEL_CHANGE:
			break;
		default:
			break;
		}
	}
	mVecTask.clear();
}

TaskMgr::TaskMgr(){}
TaskMgr::~TaskMgr(){}