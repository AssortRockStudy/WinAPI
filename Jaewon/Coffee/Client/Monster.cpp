#include "pch.h"
#include "Monster.h"
#include "Collider.h"


void Monster::tick(float _dt)
{
	Super::tick(_dt);
	Vec2 vPos = getRenderPos();
	setPos(vPos);
}

void Monster::render(HDC _dc)
{
	Vec2 vPos = getRenderPos();
	Vec2 vScale = getScale();

	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}

Monster::Monster():collider(nullptr)
{
	collider = addComponent<Collider>();
}

Monster::~Monster()
{
}
