#include "pch.h"
#include "Monster.h"

void Monster::tick(float _dt)
{
	Super::tick(_dt);
	Vec2 vPos = getRenderPos();
	if (vPos.x < 20.f) {
		mSpeed = mSpeed * -1.f;
	}
	if (vPos.x > 800.f) {
		mSpeed = mSpeed * -1.f;
	}
	vPos.x += mSpeed;
	setPos(vPos);
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

Monster::Monster():mSpeed(0.2f)
{
}

Monster::~Monster()
{
}
