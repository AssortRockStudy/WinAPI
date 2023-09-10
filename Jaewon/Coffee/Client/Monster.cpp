#include "pch.h"
#include "Monster.h"

void Monster::tick(float _dt)
{
}

void Monster::render(HDC _dc)
{
	Vec2 vPos = getPos();
	Vec2 vScale = getScale();

	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
