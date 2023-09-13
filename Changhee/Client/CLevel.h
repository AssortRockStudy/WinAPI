#pragma once

#include "CEntity.h"
#include "CLayer.h"


class CObj;
class CLayer;

class CLevel : 
	public CEntity
{
private:
	CLayer* m_arrLayer[(UINT)LAYER::END];

public:
	void tick();
	void render(HDC _dc);


public:
	void AddObject(LAYER _eLayer, CObj* _Object);

	template<typename T>
	void GetObjects(vector<T*>& _Out);


	const vector<CObj*>& GetObjects(LAYER _eLayer) { return m_arrLayer[(UINT)_eLayer]->m_vecObjects; }

public:
	CLevel();
	~CLevel();

	friend class CLevelMgr;
	friend class CTaskMgr;
};


template<typename T>
void CLevel::GetObjects(vector<T*>& _Out)
{
	for (UINT j = 0; j < (UINT)LAYER::END; ++j)
	{
		for (size_t i = 0; i < m_arrLayer[j]->m_vecObjects.size(); ++i)
		{
			T* pObj = dynamic_cast<T*>(m_arrLayer[j]->m_vecObjects[i]);

			if (pObj != nullptr)
			{
				_Out.push_back(pObj);
			}
		}
	}
}