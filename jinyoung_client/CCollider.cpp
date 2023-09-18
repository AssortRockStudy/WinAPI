#include "pch.h"
#include "CCollider.h"

#include "CObj.h"
#include "CEngine.h"
#include "CCamera.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CLayer.h"

CCollider::CCollider(CObj* _Owner)
	: CComponent(_Owner)
{

}

CCollider::~CCollider()
{

}

void CCollider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();

	m_vFinalPos = vOwnerPos + m_vOffsetPos;
	// ���� �����ִ� ���̾ �浹ü(����) �� ���
	int iLayerIdx = GetOwner()->GetLayerIdx();

	// Collider �� �����ϰ� �ִ� ������Ʈ�� ���� �Ҽ��� �ƴѵ� Finaltick �� ȣ��� ���
	assert(!(iLayerIdx < 0));
	CLayer* pCurLayer = CLevelMgr::GetInst()->GetCurLevel()->GetLayer(iLayerIdx);
	pCurLayer->RegisterCollider(this);
}

void CCollider::render(HDC _dc)
{
	if (!DEBUG_RENDER)
		return;

	SELECT_PEN(_dc, GREEN_PEN);
	SELECT_BRUSH(_dc, (HBRUSH)GetStockObject(HOLLOW_BRUSH));

	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);

	// render
	Rectangle(_dc, int(vRenderPos.x - m_vScale.x / 2.f)
		, int(vRenderPos.y - m_vScale.y / 2.f)
		, int(vRenderPos.x + m_vScale.x / 2.f)
		, int(vRenderPos.y + m_vScale.y / 2.f));
}