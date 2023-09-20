#pragma once
#include "CEntity.h"
#include "CLayer.h"

class CObj;

class CLevel
	: public CEntity
{
private:
	CLayer* m_Layer[LAYER::END];

public:
	void tick();
	void render(HDC _dc);
	
	template<typename T>
	void getObjects(vector<T*>& _Out);
	const vector<CObj*>& getObjects(LAYER _type) { return m_Layer[_type]->mVecObjects; }

	CLayer* GetLayer(int _idx){
		assert(!(_idx < 0 && LAYER::END <= _idx));
		return m_Layer[_idx];
	}

public:
	void addObject(LAYER _type, CObj* _obj);

public:
	CLevel();
	~CLevel();
};

