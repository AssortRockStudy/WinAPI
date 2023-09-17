#include "pch.h"

#include "CCamera.h"

#include "CEngine.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

CCamera::CCamera() {}

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
}
