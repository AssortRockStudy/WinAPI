#pragma once
#include "Entity.h"
#include "Layer.h"

class Obj;

class Level : public Entity
{
private:
	Layer* m_Layer[LAYER::END];

public:
	void tick();
	void render(HDC _dc);

	template<typename T>
	void GetObjects(vector<T*>& _Out);
	const vector<Obj*>& GetObjects(LAYER _LayerType)
	{
		return m_Layer[_LayerType]->m_vecObjects;
	}

private:
	void AddObject(LAYER _LayerType, Obj* _Object);

public:
	Level();
	~Level();

	friend class LevelMgr;
	friend class TaskMgr;
};

template<typename T>
inline void Level::GetObjects(vector<T*>& _Out)
{
	for (UINT j = 0; j < LAYER::END; ++j)
	{
		for (size_t i = 0; i < m_Layer[j]->m_vecObjects.size(); ++i)
		{
			T* pObj = dynamic_cast<T*>(m_Layer[j]->m_vecObjects[i]);

			if (nullptr != pObj)
			{
				_Out.push_back(pObj);
			}
		}
	}
}
