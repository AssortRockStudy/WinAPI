#include "pch.h"
#include "CLayer.h"
#include "CTimeMgr.h"
#include "CObj.h"
#include "GCMgr.h"

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
	vector<CObj*>::iterator it = mVecObjects.begin();

	for (; it != mVecObjects.end();) {
		if ((*it)->isDead()) {
			GCMgr::GetInst()->addEntity(*it);
			it = mVecObjects.erase(it);
		}
		else {
			(*it)->render(_dc);
			++it;
		}

	}
}

void CLayer::deleteAllObjects()
{
	for (int i = 0; i < mVecObjects.size(); ++i)
		delete mVecObjects[i];
	mVecObjects.clear();
}

CLayer::CLayer()
{
}

CLayer::~CLayer()
{
	deleteAllObjects();
}
