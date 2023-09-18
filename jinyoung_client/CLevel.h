﻿#pragma once
#include <typeinfo>

#include "CEntity.h"

#include "CLayer.h"
class CObj;
class CPlayer;
class CMonster;


//
//오브젝트를 vector에 넣는이유
// 
//


class CLevel
	: public CEntity
{
private:
	CLayer* m_Layer[LAYER::END];
	vector<CObj*> m_vecObjects;
	CPlayer* pcp;
	CMonster* pcm;

public:
	void begin();
	void AddObject(LAYER _LayerType, CObj* _Object);
	void tick();
	void render(HDC _dc);
	/*void AddObject(CObj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}*/

	__inline void setPlayer(CPlayer* _pcp) { pcp = _pcp; }
	__inline CPlayer* getPlayer() { return pcp; }

	__inline void setMonster(CMonster* _pcm) { pcm = _pcm; }
	__inline CMonster* getMonster()
	{
		//if (nullptr==pcp) {
		//	vector<CObj*>::iterator it;
		//	for (it = m_vecObjects.begin(); m_vecObjects.end() != it; ++it)
		//	{
		//		if ("CMonster" == typeid((*(*it))).name())
		//		{
		//			break;
		//		}
		//	}
		//	pcm= (CMonster*)(*it);
		//}
		return pcm;
	}


	// 레벨이 소유하고 있는 모든 레이어를 순회하면서 T 타입에 해당하는 객체를 찾아서 결과(_Out) 벡터에 담아준다.
	template<typename T>
	void GetObjects(vector<T*>& _Out);


	// 레벨이 소유하고 있는 특정 레이어의 오브젝트 목록을 반환한다.
	const vector<CObj*>& GetObjects(LAYER _LayerType) { return m_Layer[_LayerType]->m_vecObjects; }
	CLayer* GetLayer(int LayerIdx)
	{
		assert(!(LayerIdx < 0 && LAYER::END <= LayerIdx));
		return m_Layer[LayerIdx];
	}




public:
	CLevel();
	~CLevel();

	friend class CLevelMgr;
	friend class CTaskMgr;

};


//template<typename T>
//inline void CLevel::GetObjects(vector<T*>& _Out)
//{
//	for (size_t i = 0; i < m_vecObjects.size(); ++i)
//	{
//		T* pObj = dynamic_cast<T*>(m_vecObjects[i]);
//
//		if (nullptr != pObj)
//		{
//			_Out.push_back(pObj);
//		}
//	}
//}

// 레벨이 소유하고 있는 특정 레이어의 오브젝트 목록을 반환한다.
template<typename T>
inline void CLevel::GetObjects(vector<T*>& _Out)
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