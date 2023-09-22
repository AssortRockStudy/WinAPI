#include "pch.h"
#include "Monster.h"
#include "Collider.h"


void Monster::begin()
{
	collider->setScale(getScale() - 10.f);
}

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
	Super::render(_dc);
}

Monster::Monster():collider(nullptr)
{
	collider = addComponent<Collider>(L"MonsterCollider");
}

Monster::~Monster()
{
}
