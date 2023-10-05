#include "pch.h"
#include "define.h"
#include "Monster.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "DrawMgr.h"


Monster::Monster()
	: m_Info{}
	, m_Collider(nullptr)
{
	m_Collider = AddComponent<Collider>(L"MonsterCollider");
}

Monster::~Monster()
{
}


void Monster::begin()
{
	m_Collider->SetScale(GetScale() - 10.f);
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

	Super::render(_dc);
}


