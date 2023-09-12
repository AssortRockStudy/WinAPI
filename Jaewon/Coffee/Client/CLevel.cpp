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

Vec2 CLevel::findCloseMon(Vec2 mPos)
{
	Vec2 closest = {mPos.x, mPos.y - 99999.f};
	for (int i = 0; i < mVecObjects.size(); ++i) {
		if (mVecObjects[i]->getType() == MONSTER) {
			Vec2 monPos = mVecObjects[i]->getPos();
			if (std::pow(closest.x - mPos.x, 2) + std::pow(closest.y - mPos.y, 2) >
				std::pow(monPos.x - mPos.x, 2) + std::pow(monPos.y - mPos.y, 2)) {
				closest = monPos;
			}
		}
	}
	return closest;
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
