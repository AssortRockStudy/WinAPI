#include "pch.h"
#include "define.h"
#include "Monster.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "DrawMgr.h"

Monster::Monster()
	: m_Info{}
{
}

Monster::~Monster()
{
}


void Monster::tick(float _DT)
{
	Super::tick(_DT);
}

void Monster::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc
		, int(vRenderPos.x - vScale.x / 2)
		, int(vRenderPos.y - vScale.y / 2)
		, int(vRenderPos.x + vScale.x / 2)
		, int(vRenderPos.y + vScale.y / 2));
}


