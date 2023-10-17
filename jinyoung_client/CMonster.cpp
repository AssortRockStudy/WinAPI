#include "pch.h"
#include "CMonster.h"

#include "CCollider.h"
#include "CProjectile.h"


CMonster::CMonster()
	: m_Info{}
	, m_Collider(nullptr)
{
	m_Collider = AddComponent<CCollider>(L"MonsterCollider");
	m_Info.HP = 5.f;
}

CMonster::~CMonster()
{
}

void CMonster::begin()
{
	m_Collider->SetScale(GetScale() - 10.f);
}


void CMonster::tick(float _DT)
{
	Super::tick(_DT);
}


void CMonster::render(HDC _dc)
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
void CMonster::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	if (dynamic_cast<CProjectile*>(_OtherObj))
	{
		m_Info.HP -= 1.f;

		if (m_Info.HP <= 0.f)
		{
			Destroy();
		}
	}
}
