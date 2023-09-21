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
		assert(!(_idx < 0 || LAYER::END <= _idx));
		return m_Layer[_idx];
	}

private:
	void addObject(LAYER _type, CObj* _obj);

public:
	CLevel();
	~CLevel();

	friend class LevelMgr;
	friend class TaskMgr;
};

template<typename T>
inline void CLevel::getObjects(vector<T*>& _Out)
{
	for (UINT j = 0; j < LAYER::END; ++j)
	{
		for (size_t i = 0; i < m_Layer[j]->mVecObjects.size(); ++i)
		{
			T* pObj = dynamic_cast<T*>(m_Layer[j]->mVecObjects[i]);

			if (nullptr != pObj)
			{
				_Out.push_back(pObj);
			}
		}
	}
}
