#include "CMissile2.h"

void CMissile2::tick(float _DT)
{
	Vec2 pos = GetPos();										// 유도탄의 위치
	Vec2 enemyPos = m_TargetMonster->GetPos();					// 적의 위치
	float thetaPI = atan2f((enemyPos.y - pos.y), (enemyPos.x - pos.x)); // 아크탄젠트로 세타 구하고, 호도법으로 변환
	

	if (enemyPos.y < pos.y) { m_SpeedY -= 80.f; }
	else					{ m_SpeedY += 100.f; }
	if (enemyPos.x < pos.x) { m_SpeedX -= 80.f; }
	else					{ m_SpeedX += 100.f; }

	pos.x += GetSpeed() * cosf(thetaPI) * _DT + m_SpeedX * _DT;
	pos.y += GetSpeed() * sinf(thetaPI) * _DT + m_SpeedY * _DT;

	SetPos(pos);
}
