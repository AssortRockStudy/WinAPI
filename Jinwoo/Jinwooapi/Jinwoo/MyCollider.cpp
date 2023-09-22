#include "pch.h"
#include "MyCollider.h"

#include "MyEngine.h"
#include "MyCameraMgr.h"

#include "MyLevelMgr.h"
#include "MyLevel.h"
#include "MyLayer.h"
#include "MyObject.h"

MyCollider::MyCollider(MyObject* _Object) : MyComponent(_Object), m_CollisionCount(0)
{
}

MyCollider::~MyCollider()
{
}


void MyCollider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();

	m_finalPos = vOwnerPos + m_OffsetPos;

	int LayerIdx = GetOwner()->GetLayerIdx();

	// Collider를 보유하고 있는 오브젝트가 Level 소속이 아니였는데 finaltick이 호출된 경우
	assert(!(LayerIdx < 0));

	// 해당 LayerIdx에 맞는 레이어를 가져와 pCurLayer에 저장
	MyLayer* pCurLayer = MyLevelMgr::GetInst()->GetCurLevel()->GetLayer(LayerIdx);

	// 현재 속해있는 레이어에 충돌체를 등록해야함
	pCurLayer->RegisterCollider(this);
}

void MyCollider::render(HDC _dc)
{
	if (!DEBUG_RENDER)
	{
		return;
	}

	SELECT_BRUSH(_dc, (HBRUSH)GetStockObject(HOLLOW_BRUSH));

	Vec2 vRenderPos = MyCameraMgr::GetInst()->GetRenderPos(m_finalPos);

	if (0 < m_CollisionCount)
	{
		SELECT_PEN(_dc, PEN_TYPE::RED_PEN);

		Rectangle(_dc,
			int(vRenderPos.x - m_OffsetScale.x / 2.f),
			int(vRenderPos.y - m_OffsetScale.y / 2.f),
			int(vRenderPos.x + m_OffsetScale.x / 2.f),
			int(vRenderPos.y + m_OffsetScale.y / 2.f));
	}
	else
	{
		SELECT_PEN(_dc, PEN_TYPE::GREEN_PEN);

		Rectangle(_dc,
			int(vRenderPos.x - m_OffsetScale.x / 2.f),
			int(vRenderPos.y - m_OffsetScale.y / 2.f),
			int(vRenderPos.x + m_OffsetScale.x / 2.f),
			int(vRenderPos.y + m_OffsetScale.y / 2.f));
	}
}

void MyCollider::BeginOverlap(MyCollider* _OtherCol)
{
	++m_CollisionCount;

	GetOwner()->BeginOverlap(this, _OtherCol->GetOwner(), _OtherCol);
}

void MyCollider::Overlap(MyCollider* _OtherCol)
{
	GetOwner()->Overlap(this, _OtherCol->GetOwner(), _OtherCol);
}

void MyCollider::EndOverlap(MyCollider* _OtherCol)
{
	--m_CollisionCount;

	GetOwner()->EndOverlap(this, _OtherCol->GetOwner(), _OtherCol);
}
