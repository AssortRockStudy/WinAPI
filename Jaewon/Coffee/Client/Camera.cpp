#include "pch.h"
#include "Camera.h"

#include "CEngine.h"
#include "KeyMgr.h"
#include "CTimeMgr.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::tick()
{
	float dt = CTimeMgr::GetInst()->getDeltaTime();
	// ����Ű�� ī�޶� �ٶ󺸰� �ִ� ��ġ�� ����
	if (KeyMgr::GetInst()->getKeyState(LEFT) == PRESSED)
	{
		mLookAt.x -= 200.f * dt;
	}

	if (KeyMgr::GetInst()->getKeyState(RIGHT) == PRESSED)
	{
		mLookAt.x += 200.f * dt;
	}

	if (KeyMgr::GetInst()->getKeyState(UP) == PRESSED)
	{
		mLookAt.y -= 200.f * dt;
	}

	if (KeyMgr::GetInst()->getKeyState(DOWN) == PRESSED)
	{
		mLookAt.y += 200.f * dt;
	}


	Vec2 vResolution = CEngine::GetInst()->getMainResol();
	Vec2 vCenter = vResolution / 2.f;

	mDiff = mLookAt - vCenter;
}