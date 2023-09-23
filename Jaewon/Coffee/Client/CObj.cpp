#include "pch.h"
#include "CObj.h"
#include "Component.h"
#include "TaskMgr.h"

void CObj::setDead()
{
	mDead = true;

	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		mVecComponent[i]->mDead = true;
	}
}

void CObj::tick(float _dt)
{
	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		mVecComponent[i]->tick(_dt);
	}
}

void CObj::finalTick(float _dt)
{
	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		mVecComponent[i]->finalTick(_dt);
	}
}

void CObj::render(HDC _dc)
{
	for (size_t i = 0; i < mVecComponent.size(); ++i)
		mVecComponent[i]->render(_dc);
}

void CObj::Destroy()
{
	FTask task;
	task.Type = DELETE_OBJECT;
	task.Param1 = (INT_PTR)this;

	TaskMgr::GetInst()->addTask(task);
}

CObj::CObj():mLayerIdx(-1)
{
}

CObj::~CObj()
{
	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		if (nullptr != mVecComponent[i])
			delete mVecComponent[i];
	}
}
