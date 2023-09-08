#include "pch.h"
#include "CLevel.h"
#include "CObj.h"
#include "CTimeMgr.h"

// ������ ����ִ� ������Ʈ���� tick�� �� ����
void CLevel::tick()
{
	float delta = CTimeMgr::GetInst()->getDeltaTime();

	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->tick(delta);
	}
}

// ������ ����ִ� ������Ʈ���� render�� �� ����
void CLevel::render(HDC _dc)
{
	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->render(_dc);
	}
}

CLevel::CLevel()
{
}

// vector�� ��� �ִ� ������Ʈ���� �� delete���־�� ��
CLevel::~CLevel()
{
	for (int i = 0; i < mVecObjects.size(); ++i)
		delete mVecObjects[i];
}
