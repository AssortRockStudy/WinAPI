#include "pch.h"
#include "MyEditLevel.h"

#include "MyEngine.h"
#include "MyCameraMgr.h"

void MyEditLevel::init()
{
}

void MyEditLevel::enter()
{
	// 카메라 설정
	Vec2 vLookAt = MyEngine::GetInst()->GetMainResolution();
	vLookAt /= 2.f;
	MyCameraMgr::GetInst()->SetLookAt(vLookAt);

	CreateTile(5, 5);
}

void MyEditLevel::exit()
{
	DeleteAllObjects();
}

void MyEditLevel::tick()
{
	MyLevel::tick();
}
