#include "pch.h"
#include "CAccGuidedProjectile.h"
#include "CLevelMgr.h"
#include "CLevel.h"

void CAccGuidedProjectile::tick(float _dt)
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

	float acc = 1 / powf(GetPos().Distance(targetPos), 2)*10000.f;
	if (acc >= 10.f) {
		acc = 10.f;
	}

	if (curPos.x > targetPos.x) {
		curPos.x -= m_Speed * acc * _dt;
	}
	else {
		curPos.x += m_Speed * acc * _dt;
	}
	if (curPos.y > targetPos.y) {
		
		curPos.y -= m_Speed * acc * _dt;
	}
	else {
		curPos.y += m_Speed * acc * _dt;
	}

	

	SetPos(curPos);

}
