#include "pch.h"
#include "CollisionMgr.h"

#include "LevelMgr.h"
#include "CLevel.h"
#include "CObj.h"
#include "Collider.h"

void CollisionMgr::collisionBtwLayer(LAYER l, LAYER r)
{
	CLevel* curLevel = LevelMgr::GetInst()->getCurLevel();
	if (nullptr == curLevel)
		return;

	const vector<Collider*>& vecLeft = curLevel->GetLayer(l)->getColliders();
	const vector<Collider*>& vecRight = curLevel->GetLayer(r)->getColliders();

	if (l != r) {
		for (size_t i = 0; i < vecLeft.size(); ++i) {
			for (size_t j = 0; j < vecRight.size(); ++j) {

				COLLIDER_ID ID(vecLeft[i]->getID(), vecRight[j]->getID());
				map<COLLIDER_ID, bool>::iterator iter = mapID.find(ID);

				if (iter == mapID.end()){
					mapID.insert(make_pair(ID, false));
					iter = mapID.find(ID);
				}


				// 현재 충돌 중이다.
				// 1. 이전에 충돌한 적이 없다.
				// 2. 이전에도 충돌 중이었다.
				if (isCollision(vecLeft[i], vecRight[j])){
					if (false == iter->second)	{
						// dead인지 확인
						if (!vecLeft[i]->isDead() && !vecRight[j]->isDead()) {
							vecLeft[i]->beginOverLap(vecRight[j]);
							vecRight[j]->beginOverLap(vecLeft[i]);
						}
					}

					else{
						if (vecLeft[i]->isDead() || vecRight[j]->isDead()) {
							vecLeft[i]->endOverLap(vecRight[j]);
							vecRight[j]->endOverLap(vecLeft[i]);
						}
						else {
							vecLeft[i]->overLap(vecRight[j]);
							vecRight[j]->overLap(vecLeft[i]);
						}
					}
					iter->second = true;
				}
				// 현재 충돌하지 않고 있다.
				// 이전에는 충돌하고 있었다.
				// 충돌 아예 안했으면 처리 X
				else{
					if (iter->second){
						vecLeft[i]->endOverLap(vecRight[j]);
						vecRight[j]->endOverLap(vecLeft[i]);
					}
					iter->second = false;
				}
			}
		}
	}
	else {

	}
}

bool CollisionMgr::isCollision(Collider* l, Collider* r)
{
	if (fabs(l->getScale().x / 2.f + r->getScale().x / 2.f) >= fabs(l->getPos().x - r->getPos().x)
		&& fabs(l->getScale().y / 2.f + r->getScale().y / 2.f) >= fabs(l->getPos().y - r->getPos().y))
		return true;
	return false;
}

void CollisionMgr::tick()
{
	
	for (UINT row = 0; row < 32; ++row) {
		for (UINT col = row; col < 32; ++col) {
			if(!(mLayerChk[row] & (1 << col)))
				continue;
			collisionBtwLayer((LAYER)row, (LAYER)col);
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
