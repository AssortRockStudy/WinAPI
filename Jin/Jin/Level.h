#pragma once
#include "Entity.h"
#include "Layer.h"

class Obj;

class Level : public Entity
{
private:
	Layer* m_Layer[LAYER::END];

	UINT	m_TileRow;
	UINT	m_TileCol;

public:
	virtual void init() = 0;
	virtual void enter() = 0;
	virtual void exit() = 0;

	virtual void begin();
	virtual void tick();
	virtual void render(HDC _dc);

	template<typename T>
	void GetObjects(vector<T*>& _Out);
	const vector<Obj*>& GetObjects(LAYER _LayerType)
	{
		return m_Layer[_LayerType]->m_vecObjects;
	}

	Layer* GetLayer(int LayerIdx)
	{
		assert(!(LayerIdx < 0 || LAYER::END <= LayerIdx));
		return m_Layer[LayerIdx];
	}

protected:
	void AddObject(LAYER _LayerType, Obj* _Object);
	void DeleteAllObjects();
	void CreateTile(UINT _Row, UINT _Col);

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
