#include "pch.h"
#include "CLayer.h"
#include "CTimeMgr.h"
#include "CObj.h"

void CLayer::begin()
{
	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->begin();
	}
}

void CLayer::tick()
{
	float delta = CTimeMgr::GetInst()->getDeltaTime();
	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->tick(delta);
	}
}

void CLayer::finalTick()
{
	float delta = CTimeMgr::GetInst()->getDeltaTime();
	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->finalTick(delta);
	}
}

void CLayer::render(HDC _dc)
{
	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->render(_dc);
	}
}

CLayer::CLayer()
{
}

CLayer::~CLayer()
{
	for (int i = 0; i < mVecObjects.size(); ++i)
		delete mVecObjects[i];
}
