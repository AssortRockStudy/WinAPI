#include "pch.h"
#include "CLevel.h"
#include "CObj.h"


// ������ ����ִ� ������Ʈ���� tick�� �� ����
void CLevel::tick()
{
	for (int i = 0; i < mVecObjects.size(); ++i) {
		mVecObjects[i]->tick();
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
