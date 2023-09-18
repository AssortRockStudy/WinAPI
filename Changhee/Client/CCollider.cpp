#include "pch.h"
#include "CCollider.h"

#include "CObj.h"
#include "CCamera.h"
#include "CEngine.h"

#include "CLevel.h"
#include "CLevelMgr.h"
#include "CLayer.h"

CCollider::CCollider(CObj* _pOwner)
	: CComponent(_pOwner)
{
}

CCollider::~CCollider()
{
}

void CCollider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();

	m_vFinalPos = vOwnerPos + m_vOffsetPos;

	// 현재 속해있는 레이어에 충돌체(본인) 를 등록

	int iLayerIdx = GetOwner()->GetLayerIdx();
	assert(!(iLayerIdx < 0));

	CLayer* pCurLayer = CLevelMgr::GetInst()->GetCurLevel()->GetLayer(iLayerIdx);

	pCurLayer->RegisterCollider(this);

}

void CCollider::render(HDC _dc)
{
	if (!DEBUG_RENDER)
		return;

	SELECT_PEN(_dc, PEN_TYPE::GREEN);


	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);

	// render
	Rectangle(_dc, int(vRenderPos.x - m_vScale.x / 2.f)
		, int(vRenderPos.y - m_vScale.y / 2.f)
		, int(vRenderPos.x + m_vScale.x / 2.f)
		, int(vRenderPos.y + m_vScale.y / 2.f));

}


void CCollider::Overlap(CCollider* _pOtherCol)
{
	GetOwner()->Overlap(this, _pOtherCol->GetOwner(), _pOtherCol);
}