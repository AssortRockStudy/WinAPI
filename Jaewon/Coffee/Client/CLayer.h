#pragma once
#include "CEntity.h"
// 오브젝트를 관리하는 역할
// 이전에 레벨에서 하던 역할을 하며
// 레벨은 이제 레이어를 관리하는 쪽으로 구조 변경을 진행

class CObj;

class CLayer : public CEntity
{
	// 레벨에서 갖고 있던 멤버 변수 및 함수 가져옴
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

	// 앞으로 레벨에서 레이어에 접근할 일이 많기 때문에 friend 키워드 사용
	friend class CLevel;

};

