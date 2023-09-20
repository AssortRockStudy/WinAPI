#include "pch.h"

#include "CCollider.h"

#include "CCamera.h"
#include "CEngine.h"
#include "CObj.h"
#include "CPaletteMgr.h"

#include "CLayer.h"
#include "CLevel.h"
#include "CLevelMgr.h"

CCollider::CCollider(CObj* _Owner) : CComponent(_Owner) {}

CCollider::~CCollider() {}

void CCollider::finaltick(float _DT) {
    Vec2 vOwnerPos = GetOwner()->GetPos();

    m_vFinalPos = vOwnerPos + m_vOffsetPos;

    int iLayerIdx = GetOwner()->GetLayerIdx();

    assert(!(iLayerIdx < 0));
    CLayer* pCurLayer = CLevelMgr::GetInst()->GetCurLevel()->GetLayer(iLayerIdx);

    pCurLayer->RegisterCollider(this);
}

void CCollider::render(HDC _dc) {
    if (!DEBUG_RENDER)
        return;

    CPaletteMgr::GetInst()->SelectPen(CPaletteMgr::PenColor::PGREEN);
    CPaletteMgr::GetInst()->SelectBrush(CPaletteMgr::BrushColor::BHOLLOW);

    Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);

    // render
    Rectangle(_dc, int(vRenderPos.x - m_vScale.x / 2.f),
              int(vRenderPos.y - m_vScale.y / 2.f),
              int(vRenderPos.x + m_vScale.x / 2.f),
              int(vRenderPos.y + m_vScale.y / 2.f));
}