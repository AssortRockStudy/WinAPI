#include "pch.h"
#include "CollisionMgr.h"

#include "LevelMgr.h"
#include "CLevel.h"
#include "CObj.h"
#include "Collider.h"

void CollisionMgr::tick()
{
	CLevel* curLevel = LevelMgr::GetInst()->getCurLevel();

	// 절반만 확인
	for (UINT row = 0; row < 32; ++row) {
		for (UINT col = row; col < 32; ++col) {
			if(!(mLayerChk[row] & (1 << col)))
				continue;
			const vector<Collider*>& vecLeft = curLevel->GetLayer((LAYER)row)->getColliders();
			const vector<Collider*>& vecRighr = curLevel->GetLayer((LAYER)col)->getColliders();
		}
	}
}

void CollisionMgr::checkCollision(LAYER l, LAYER r)
{
	int row = 0;
	int col = 0;

	if (l < r) {
		row = l;
		col = r;
	}
	else {
		col = l;
		row = r;
	}
	mLayerChk[row] |= (1 << col);
}

void CollisionMgr::unCheckCollision(LAYER l, LAYER r)
{
	int row = 0;
	int col = 0;

	if (l < r) {
		row = l;
		col = r;
	}
	else {
		col = l;
		row = r;
	}
	mLayerChk[row] &= ~(1 << col);
}

CollisionMgr::CollisionMgr() :mLayerChk{} {}
CollisionMgr::~CollisionMgr(){}
