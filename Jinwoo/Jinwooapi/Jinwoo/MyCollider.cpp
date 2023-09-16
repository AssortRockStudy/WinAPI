#include "pch.h"
#include "MyCollider.h"

#include "MyEngine.h"
#include "MyCameraMgr.h"

#include "MyObject.h"

MyCollider::MyCollider(MyObject* _Object) : MyComponent(_Object)
{
}

MyCollider::~MyCollider()
{
}


void MyCollider::finaltick(float _DT)
{
	Vec2 vOwnerPos = GetOwner()->GetPos();

	m_finalPos = vOwnerPos + m_OffsetPos;
}

void MyCollider::render(HDC _dc)
{
	if (!DEBUG_RENDER)
	{
		return;
	}

	SELECT_PEN(_dc, PEN_TYPE::GREEN_PEN);
	SELECT_BRUSH(_dc, (HBRUSH)GetStockObject(HOLLOW_BRUSH));

	Vec2 vRenderPos = MyCameraMgr::GetInst()->GetRenderPos(m_finalPos);

	Rectangle(_dc,
		int(vRenderPos.x - m_OffsetScale.x / 2.f),
		int(vRenderPos.y - m_OffsetScale.y / 2.f),
		int(vRenderPos.x + m_OffsetScale.x / 2.f),
		int(vRenderPos.y + m_OffsetScale.y / 2.f));
}