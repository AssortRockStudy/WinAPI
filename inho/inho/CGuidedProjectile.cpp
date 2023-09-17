#include "pch.h"

#include "CGuidedProjectile.h"
#include "CLevelMgr.h"
#include "CLevel.h"
#include "CMonster.h"


CGuidedProjectile::CGuidedProjectile() :target(nullptr) {}

CGuidedProjectile::~CGuidedProjectile() {}

void CGuidedProjectile::tick(float _dt)
{

	if (nullptr == target) {
		FindTarget();
	}

	else {
		
		Vec2 vPos = GetPos();
		Vec2 vDir = target->GetPos() - vPos;
		vDir.Normalize();

		vPos.x += vDir.x * GetSpeed() * _dt;
		vPos.y += vDir.y * GetSpeed() * _dt;

		SetPos(vPos);
	}
}


void CGuidedProjectile::FindTarget() {
	vector<CMonster*> vecMon;
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	pCurLevel->GetObjects<CMonster>(vecMon);

	if (vecMon.empty()) {
		return;
	}
	else if (vecMon.size() == 1) {
		target = vecMon.front();
	}
	else {
		float fMax = 2000.f;
		
		for (size_t i = 0; i < vecMon.size(); ++i) {
			float fDistance = GetPos().Distance(vecMon[i]->GetPos());
			if (fMax > fDistance) {
				fMax = fDistance;

				target = vecMon[i];
			}
		}
	}
}