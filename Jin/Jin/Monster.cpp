#include "pch.h"
#include "define.h"
#include "Monster.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "DrawMgr.h"
#include "Projectile.h"


Monster::Monster()
	: m_Info{}
	, m_Collider(nullptr)
{
	m_Collider = AddComponent<Collider>(L"MonsterCollider");
	m_Info.HP = 5.f;
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

void Monster::BeginOverlap(Collider* _OwnCol, Obj* _OtherObj, Collider* _OtherCol)
{
	if (dynamic_cast<Projectile*>(_OtherObj))
	{
		m_Info.HP -= 1.f;
		if (m_Info.HP <= 0.f)
		{
			Destroy();
		}
	}
}


