#include "pch.h"
#include "CMonster.h"

#include "CCollider.h"

CMonster::CMonster()
	: m_Info{}
	, m_pCollider(nullptr)
{
	m_pCollider = AddComponent<CCollider>(L"MonsterCollider");
}

CMonster::~CMonster()
{
}

void CMonster::Overlap(CCollider* _pOwnCol, CObj* _pOtherObj, CCollider* _pOtherCol)
{
	wstring test = _pOwnCol->GetName();
}

void CMonster::begin()
{
	m_pCollider->SetScale(GetScale() - 10.f);
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
