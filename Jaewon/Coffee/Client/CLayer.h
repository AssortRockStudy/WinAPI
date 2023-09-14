#pragma once
#include "CEntity.h"
// 오브젝트를 관리하는 역할
// 이전에 레벨에서 하던 역할을 하며
// 레벨은 이제 레이어를 관리하는 쪽으로 구조 변경을 진행

class CObj;

class CLayer : public CEntity
{
private:
	vector<CObj*> mVecObjects;

public:
	void tick();
	void render(HDC _dc);

public:
	void AddObj(CObj* _obj) {
		mVecObjects.push_back(_obj);
	}

public:
	CLayer();
	~CLayer();

	friend class CLevel;

};

