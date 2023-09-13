#include "CMissile3.h"

void CMissile3::tick(float _DT)
{
	Vec2 pos = GetPos();										// 유도탄의 위치
	Vec2 enemyPos = m_TargetMonster->GetPos();					// 적의 위치

	SetDir(atan2f(enemyPos.y - pos.y, enemyPos.x - pos.x));

	pos.x += GetSpeed() * cosf(GetDir() + PI / 2.5f) * _DT;
	pos.y += GetSpeed() * sinf(GetDir() + PI / 2.5f) * _DT;

	SetPos(pos);
}

CMissile3::CMissile3()
{

}

CMissile3::~CMissile3()
{

}