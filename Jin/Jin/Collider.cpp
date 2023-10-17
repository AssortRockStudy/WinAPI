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
	, m_iCollisionCnt(0)
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

	//SELECT_PEN(_dc, GREEN_PEN);
	SELECT_BRUSH(_dc, (HBRUSH)GetStockObject(HOLLOW_BRUSH));

	Vec2 vRenderPos = Camera::GetInst()->GetRenderPos(m_vFinalPos);

	if (0 < m_iCollisionCnt)
	{
		SELECT_PEN(_dc, RED_PEN);
		Rectangle(_dc, int(vRenderPos.x - m_vScale.x / 2.f)
			, int(vRenderPos.y - m_vScale.y / 2.f)
			, int(vRenderPos.x + m_vScale.x / 2.f)
			, int(vRenderPos.y + m_vScale.y / 2.f));
	}
	else
	{
		SELECT_PEN(_dc, GREEN_PEN);
		Rectangle(_dc, int(vRenderPos.x - m_vScale.x / 2.f)
			, int(vRenderPos.y - m_vScale.y / 2.f)
			, int(vRenderPos.x + m_vScale.x / 2.f)
			, int(vRenderPos.y + m_vScale.y / 2.f));
	}
}

void Collider::BeginOverlap(Collider* _OtherCol)
{
	++m_iCollisionCnt;
	GetOwner()->BeginOverlap(this, _OtherCol->GetOwner(), _OtherCol);
}

void Collider::Overlap(Collider* _OtherCol)
{
	GetOwner()->Overlap(this, _OtherCol->GetOwner(), _OtherCol);
}

void Collider::EndOverlap(Collider* _OtherCol)
{
	--m_iCollisionCnt;
	GetOwner()->EndOverlap(this, _OtherCol->GetOwner(), _OtherCol);
}
