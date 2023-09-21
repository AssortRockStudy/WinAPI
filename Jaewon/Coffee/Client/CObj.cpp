#include "pch.h"
#include "CObj.h"
#include "Component.h"

void CObj::tick(float _dt)
{
	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		mVecComponent[i]->tick(_dt);
	}
}

void CObj::finalTick(float _dt)
{
	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		mVecComponent[i]->tick(_dt);
	}
}

void CObj::render(HDC _dc)
{
	Vec2 renderPos = getRenderPos();
	Rectangle(_dc
		, int(renderPos.x - mScale.x / 2)
		, int(renderPos.y - mScale.y / 2)
		, int(renderPos.x + mScale.x / 2)
		, int(renderPos.y + mScale.y / 2));
}

CObj::CObj():mLayerIdx(-1)
{
}

CObj::~CObj()
{
	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		if (nullptr != mVecComponent[i])
			delete mVecComponent[i];
	}
}
