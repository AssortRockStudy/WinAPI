#include "pch.h"
#include "Collider.h"
#include "Obj.h"
#include "Engine.h"
#include "Camera.h"

#include "LevelMgr.h"
#include "Level.h"
#include "Layer.h"


Collider::Collider(Obj* _Owner)
	: Component(_Owner)
{
}

Collider::~Collider()
{
}

void Collider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();
	m_vFinalPos = vOwnerPos + m_vOffsetPos;
	int iLayerIdx = GetOwner()->GetLayerIdx();

	assert(!(iLayerIdx < 0));
	Layer* pCurLayer = LevelMgr::GetInst()->GetCurLevel()->GetLayer(iLayerIdx);
	pCurLayer->RegisterCollider(this);

}

void Collider::render(HDC _dc)
{
	if (!DEBUG_RENDER)
		return;

	SELECT_PEN(_dc, GREEN_PEN);
	SELECT_BRUSH(_dc, (HBRUSH)GetStockObject(HOLLOW_BRUSH));

	Vec2 vRenderPos = Camera::GetInst()->GetRenderPos(m_vFinalPos);

	// render
	Rectangle(_dc, int(vRenderPos.x - m_vScale.x / 2.f)
		, int(vRenderPos.y - m_vScale.y / 2.f)
		, int(vRenderPos.x + m_vScale.x / 2.f)
		, int(vRenderPos.y + m_vScale.y / 2.f));
}

