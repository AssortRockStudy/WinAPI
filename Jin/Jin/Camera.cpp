#include "pch.h"
#include "Camera.h"
#include "Engine.h"
#include "KeyMgr.h"
#include "TimeMgr.h"


Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::tick()
{
	if (KEY_PRESSED(KEY::LEFT))
	{
		m_vLookAt.x -= 200.f * DT;
	}

	if (KEY_PRESSED(KEY::RIGHT))
	{
		m_vLookAt.x += 200.f * DT;
	}

	if (KEY_PRESSED(KEY::UP))
	{
		m_vLookAt.y -= 200.f * DT;
	}

	if (KEY_PRESSED(KEY::DOWN))
	{
		m_vLookAt.y += 200.f * DT;
	}

	Vec2 vResolution = Engine::GetInst()->GetResolution();
	Vec2 vCenter = vResolution / 2.f;

	m_vDiff = m_vLookAt - vCenter;
}