#include "pch.h"
#include "Collider.h"
#include "CObj.h"
#include "CEngine.h"
#include "Camera.h"
#include "LevelMgr.h"
#include "CLevel.h"
#include "CLayer.h"

void Collider::finalTick(float _dt)
{
	Vec2 ownerPos = getOwner()->getRenderPos();
	finalPos = ownerPos + offsetPos;

	int lIdx = getOwner()->getLayerIdx();

	assert(!(lIdx < 0));
	CLayer* curLayer = LevelMgr::GetInst()->getCurLevel()->GetLayer(lIdx);
	curLayer->registerCollider(this);
}

void Collider::render(HDC _dc)
{
	if (!DEBUG_RENDER)
		return;

	SELECT_PEN(_dc, GREEN_PEN);
	SELECT_BRUSH(_dc, (HBRUSH)GetStockObject(HOLLOW_BRUSH));

	Vec2 renderPos = Camera::GetInst()->GetRenderPos(finalPos);
	Rectangle(_dc, int(renderPos.x - scale.x / 2.f)
		, int(renderPos.y - scale.y / 2.f)
		, int(renderPos.x + scale.x / 2.f)
		, int(renderPos.y + scale.y / 2.f));
}

Collider::Collider(CObj* _owner):Component(_owner){}
Collider::~Collider(){}
