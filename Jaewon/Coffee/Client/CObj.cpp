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
		mVecComponent[i]->finalTick(_dt);
	}
}

void CObj::render(HDC _dc)
{
	for (size_t i = 0; i < mVecComponent.size(); ++i)
		mVecComponent[i]->render(_dc);
}

CObj::CObj()
{
}

CObj::~CObj()
{
	for (size_t i = 0; i < mVecComponent.size(); ++i) {
		if (nullptr != mVecComponent[i])
			delete mVecComponent[i];
	}
}
