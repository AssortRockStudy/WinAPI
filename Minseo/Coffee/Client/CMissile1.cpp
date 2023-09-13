#include "CMissile1.h"

void CMissile1::tick(float _DT)
{
	Vec2 pos = GetPos();										// 유도탄의 위치
	Vec2 enemyPos = m_TargetMonster->GetPos();					// 적의 위치
	if ((enemyPos.y != pos.y) || (enemyPos.x != pos.x))
	{
		float thetaPI = atan2f((enemyPos.y - pos.y), (enemyPos.x - pos.x)); // 아크탄젠트로 세타 구하고, 호도법으로 변환

		pos.x += GetSpeed() * cosf(thetaPI) * _DT;
		pos.y += GetSpeed() * sinf(thetaPI) * _DT;
	}
	SetPos(pos);
}

//void CMissile1::render(HDC _dc)
//{
//}
