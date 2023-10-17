#include "pch.h"
#include "MyCameraMgr.h"

#include "MyEngine.h"
#include "MyTimeMgr.h"
#include "MyKeyMgr.h"

MyCameraMgr::MyCameraMgr()
{

}

MyCameraMgr::~MyCameraMgr()
{

}

void MyCameraMgr::tick()
{
	if (KEY_PRESSED(LEFT))
	{
		m_LookAt.x -= 400.f * DT;
	}

	if (KEY_PRESSED(RIGHT))
	{
		m_LookAt.x += 400.f * DT;
	}

	if (KEY_PRESSED(UP))
	{
		m_LookAt.y -= 400.f * DT;
	}
	
	if (KEY_PRESSED(DOWN))
	{
		m_LookAt.y += 400.f * DT;
	}

	Vec2 vResolution = MyEngine::GetInst()->GetMainResolution();
	Vec2 vCenter = vResolution / 2.f;

	m_CameraMove = m_LookAt - vCenter;
}
