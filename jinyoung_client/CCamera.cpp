#include "pch.h"
#include "CCamera.h"

#include "CEngine.h"
#include "CKeyman.h"
#include "CTimeManager.h"

CCamera::CCamera()
{
}

CCamera::~CCamera()
{
}

void CCamera::tick()
{
	// ����Ű�� ī�޶� �ٶ󺸰� �ִ� ��ġ�� ����
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



	// ȭ�� �ػ��� �߽���ġ�� �˾Ƴ���.
	Vec2 vResolution = CEngine::GetInst()->GetResolution();
	Vec2 vCenter = vResolution / 2.f;

	// �ػ� �߽ɰ�, ī�޶� ���� �����ִ� ��ǥ�� ���̰��� ���Ѵ�.
	m_vDiff = m_vLookAt - vCenter;
}