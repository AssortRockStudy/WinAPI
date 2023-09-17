#include "pch.h"
#include "CMonster.h"


CMonster::CMonster()
	: m_Info{}
{
}

CMonster::~CMonster()
{
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
}
