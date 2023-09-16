#include "pch.h"
#include "CCollider.h"

#include "CObj.h"

#include "CCamera.h"
#include "CEngine.h"

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
