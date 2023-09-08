#include "pch.h"
#include "CLevel.h"
#include "CObj.h"
#include "CTimeMgr.h"

// 레벨에 들어있는 오브젝트들의 tick을 다 실행
void CLevel::tick()
{
	float delta = CTimeMgr::GetInst()->getDeltaTime();

	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->tick(delta);
	}
}

// 레벨에 들어있는 오브젝트들의 render을 다 실행
void CLevel::render(HDC _dc)
{
	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->render(_dc);
	}
}

CLevel::CLevel()
{
}

// vector에 들어 있는 오브젝트들을 다 delete해주어야 됨
CLevel::~CLevel()
{
	for (int i = 0; i < mVecObjects.size(); ++i)
		delete mVecObjects[i];
}
