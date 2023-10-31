#include "pch.h"
#include "CCamera.h"

#include "CEngine.h"
#include "CKeyman.h"
#include "CTimeManager.h"

#include "CAssetMgr.h"
#include "CTexture.h"

CCamera::CCamera()
	: m_Veil(nullptr)
	, m_Alpha(0.f)
	, m_AccTime(0.f)
	, m_CamEffectType(CAM_EFFECT::NONE)
{
	Vec2 vResol = CEngine::GetInst()->GetResolution();
	m_Veil = CAssetMgr::GetInst()->CreateTexture(L"VeilTex", vResol.x, vResol.y);
}

CCamera::~CCamera()
{
}

void CCamera::tick()
{
	// 방향키로 카메라가 바라보고 있는 위치를 변경
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



	// 화면 해상도의 중심위치를 알아낸다.
	Vec2 vResolution = CEngine::GetInst()->GetResolution();
	Vec2 vCenter = vResolution / 2.f;

	// 해상도 중심과, 카메라가 현재 보고있는 좌표의 차이값을 구한다.
	m_vDiff = m_vLookAt - vCenter;


	// 카메라 효과가 켜져있다면
	if (m_CamEffectType == CAM_EFFECT::NONE)
		return;

	if (m_CamEffectType == CAM_EFFECT::FADE_IN)
	{
		m_AccTime += DT;

		if (m_DestTime <= m_AccTime)
		{
			m_CamEffectType = CAM_EFFECT::NONE;
			m_Alpha = 0;
		}
		else
		{
			float fRatio = m_AccTime / m_DestTime;
			float alpha = 1.f - fRatio;
			m_Alpha = (UINT)(alpha * 255);
		}
	}

	if (m_CamEffectType == CAM_EFFECT::FADE_OUT)
	{
		m_AccTime += DT;

		if (m_DestTime <= m_AccTime)
		{
			m_CamEffectType = CAM_EFFECT::NONE;
			m_Alpha = 255;
		}
		else
		{
			float fRatio = m_AccTime / m_DestTime;
			float alpha = fRatio;
			m_Alpha = (UINT)(alpha * 255);
		}
	}
}

void CCamera::render(HDC _dc)
{
	if (0 == m_Alpha)
		return;

	BLENDFUNCTION blend = {};
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = m_Alpha; // 0 ~ 255
	blend.AlphaFormat = 0; // 0

	AlphaBlend(_dc
		, 0, 0, m_Veil->GetWidth(), m_Veil->GetHeight()
		, m_Veil->GetDC()
		, 0, 0
		, m_Veil->GetWidth(), m_Veil->GetHeight()
		, blend);
}