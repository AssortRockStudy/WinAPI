#include "pch.h"
#include "Camera.h"
#include "Engine.h"
#include "KeyMgr.h"
#include "TimeMgr.h"

#include "AssetMgr.h"
#include "Texture.h"

Camera::Camera()
	: m_Veil(nullptr)
	, m_Alpha(0.f)
	, m_AccTime(0.f)
	, m_CamEffectType(CAM_EFFECT::NONE)
{
	Vec2 vResol = Engine::GetInst()->GetResolution();
	m_Veil = AssetMgr::GetInst()->CreateTexture(L"VeilTex", vResol.x, vResol.y);
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

void Camera::render(HDC _dc)
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
