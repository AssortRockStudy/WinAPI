#include "pch.h"

#include "CCamera.h"

#include "CEngine.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CAssetMgr.h"
#include "CTexture.h"

CCamera::CCamera():
    m_Veil(nullptr),
    m_Alpha(0.f),
    m_AccTime(0.f),
    m_CamEffectType(CAM_EFFECT::NONE)
{
    Vec2 vResol = CEngine::GetInst()->GetResolution();
    m_Veil = CAssetMgr::GetInst()->CreateTexture(L"VeilTex", vResol.x, vResol.y);
}

CCamera::~CCamera() {}

void CCamera::tick() {

    float m_Speed = 200.f;

    if (KEY_PRESSED(LEFT)) {
        m_vLookAt.x -= m_Speed * DT;
    }

    if (KEY_PRESSED(RIGHT)) {
        m_vLookAt.x += m_Speed * DT;
    }

    if (KEY_PRESSED(UP)) {
        m_vLookAt.y -= m_Speed * DT;
    }

    if (KEY_PRESSED(DOWN)) {
        m_vLookAt.y += m_Speed * DT;
    }

    Vec2 vResolution = CEngine::GetInst()->GetResolution();
    Vec2 vCenter = vResolution / 2.f;

    m_vDiff = m_vLookAt - vCenter;

    if (m_CamEffectType == CAM_EFFECT::NONE)
        return;

    if (m_CamEffectType == CAM_EFFECT::FADE_IN) {

        m_AccTime += DT;

        if (m_DestTime <= m_AccTime) {
            m_CamEffectType = CAM_EFFECT::NONE;
            m_Alpha = 0;
        }
        else {
            float fRatio = m_AccTime / m_DestTime;
            float alpha = 1.f - fRatio;
            m_Alpha = (UINT)(alpha * 255);
        }
    }

    if (m_CamEffectType == CAM_EFFECT::FADE_OUT) {

        m_AccTime += DT;

        if (m_DestTime <= m_AccTime) {
            m_CamEffectType = CAM_EFFECT::NONE;
            m_Alpha = 255;
        }
        else {
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
    blend.SourceConstantAlpha = m_Alpha;
    blend.AlphaFormat = 0;

    AlphaBlend(_dc
        , 0, 0, m_Veil->GetWidth(), m_Veil->GetHeight()
        , m_Veil->GetDC()
        , 0, 0
        , m_Veil->GetWidth(), m_Veil->GetHeight()
        , blend);
}
