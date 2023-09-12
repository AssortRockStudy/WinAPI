#include "pch.h"
#include "CPosGuidedProjectile.h"
#include "CLevelMgr.h"
#include "CLevel.h"

void CPosGuidedProjectile::tick(float _dt)
{
	auto monsters = CLevelMgr::GetInst()->GetCurLevel()->GetMonsters();
	if (monsters.empty()) {
		return;
	}
	
	target = monsters[0];
	float targetDistance = 0;
	for (int i = 1; i < monsters.size(); ++i) {
		float monsterD = GetPos().Distance(monsters[i]->GetPos());
		targetDistance = GetPos().Distance(target->GetPos());
		if (monsterD < targetDistance) {
			target = monsters[i];

		}
	}
	auto curPos = GetPos();
	auto targetPos = target->GetPos();

	
	curPos.x += m_Speed * cosf(atan2f((curPos.y - targetPos.y), (targetPos.x - curPos.x)))* _dt;
	curPos.y -= m_Speed * sinf(atan2f((curPos.y - targetPos.y), (targetPos.x - curPos.x))) * _dt;

	SetPos(curPos);

}
